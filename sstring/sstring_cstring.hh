/**
 * @file sstring_cstring.hh
 * @brief This file contains definition of most used `string.h` functions, but better optimized and fast. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef SSTRING_CSTRING_DEFINED
#define SSTRING_CSTRING_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
#ifndef EXIT_HEAP_FAIL
#define EXIT_HEAP_FAIL
    static inline void exit_heap_fail(const void *ptr)
    {
        if (!ptr)
        {
            std::fprintf(stderr, "err: can't allocate heap memory.\n");
            std::exit(EXIT_FAILURE);
        }
    }
#endif

    template <typename T>
    inline void sstring_t_view<T>::fast_strncat(T *dest, const T *src, std::size_t &size)
    {
        if (dest && src)
            while ((dest[size] = *src++))
                size += 1;
    }

    template <typename T>
    inline T *sstring_t_view<T>::fast_strstr(const T *haystack, std::size_t haystack_len, const T *needle) noexcept(true)
    {
        if (!haystack || !needle || haystack_len == 0)
            return nullptr;
        std::size_t needle_len = sstring_t_view<T>::sstr_strlen(needle);
        if (needle_len == 0)
            return const_cast<T *>(haystack);
        int *prefix = static_cast<int *>(std::malloc(needle_len * sizeof(int)));
        exit_heap_fail(prefix);
        prefix[0] = 0;
        int k = 0;
        for (std::size_t q = 1; q < needle_len; ++q)
        {
            while (k > 0 && needle[k] != needle[q])
                k = prefix[k - 1];
            if (needle[k] == needle[q])
                k += 1;
            prefix[q] = k;
        }
        int q = 0;
        for (std::size_t i = 0; i < haystack_len; ++i)
        {
            while (q > 0 && needle[q] != haystack[i])
                q = prefix[q - 1];
            if (needle[q] == haystack[i])
                q += 1;
            if (q == (int)needle_len)
            {
                std::free(prefix);
                return const_cast<T *>(haystack + i - needle_len + 1);
            }
        }
        std::free(prefix);
        return nullptr;
    }

    template <typename T>
    inline void sstring_t_view<T>::init_n_zeroes(T *ptr, std::size_t from_where, std::size_t till_where)
    {
        if (ptr)
            for (std::size_t i = from_where; i < till_where; i++)
                ptr[i] = 0;
    }

    template <typename T>
    inline int sstring_t_view<T>::sstr_strcmp(const T *str1, const T *str2)
    {
        if (!str1 || !str2)
            return -1;
        int i = 0;
        while (str1[i] != 0 && str2[i] != 0)
        {
            if (str1[i] != str2[i])
                return (str1[i] < str2[i]) ? -1 : 1;
            i++;
        }
        return (str1[i] == 0 && str2[i] == 0) ? 0 : (str1[i] < str2[i]) ? -1
                                                                        : 1;
    }

    template <typename T>
    inline int sstring_t_view<T>::sstr_strncmp(const T *str1, const T *str2, std::size_t n)
    {
        if (!str1 || !str2)
            return -1;
        std::size_t i = 0;
        while (i < n && str1[i] != 0 && str2[i] != 0)
        {
            if (str1[i] != str2[i])
                return (str1[i] < str2[i]) ? -1 : 1;
            i++;
        }
        if (i == n)
            return 0;
        return (str1[i] < str2[i]) ? -1 : 1;
    }

    template <typename T>
    inline std::size_t sstring_t_view<T>::sstr_strlen(const T *str)
    {
        if (!str)
            return 0;
        std::size_t str_L = 0;
        while (*str != 0)
        {
            str_L++;
            str++;
        }
        return str_L;
    }

    template <typename T>
    inline T *sstring_t_view<T>::fast_strtok(T *str, const T *delim, std::size_t delim_length)
    {
        if (!delim)
            return nullptr;
        static T *token = nullptr; // maintains a static pointer variable
        if (str != nullptr)
            token = str;
        else if (token == nullptr)
            return nullptr;
        T *p = sstring_t_view<T>::fast_strstr(token, sstring_t_view<T>::sstr_strlen(token), delim);
        if (p != nullptr)
        {
            *p = 0;
            T *tmp = token;
            token = p + delim_length;
            return tmp;
        }
        else
        {
            T *tmp = token;
            token = nullptr;
            return tmp;
        }
    }
}

#endif