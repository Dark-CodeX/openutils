/**
 * @file sstring_ctor.hh
 * @brief This file contains definition of constructors and deconstructor of sstring_t_view. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef SSTRING_CTOR_DEFINED
#define SSTRING_CTOR_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T>::sstring_t_view()
    {
        this->len = 0;
        this->src = nullptr;
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T c)
    {
        this->len = 0;
        this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
        exit_heap_fail(this->src);
        this->src[this->len++] = c;
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T *str)
    {
        if (str)
        {
            this->len = 0;
            std::size_t str_len = this->sstr_strlen(str);
            this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, str, this->len);
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(T *ptr_begin, T *ptr_end)
    {
        if (ptr_begin && ptr_end)
        {
            this->len = static_cast<std::size_t>(ptr_end - ptr_begin);
            this->src = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            std::size_t i = 0;
            for (const T *ptr = ptr_begin; ptr != ptr_end; ptr++)
                this->src[i++] = *ptr;
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T c, std::size_t n)
    {
        if (n != 0)
        {
            this->len = 0;
            this->src = static_cast<T *>(std::calloc(n + 1, sizeof(T)));
            exit_heap_fail(this->src);
            for (std::size_t i = 0; i < n; i++)
                this->src[i] = c;
            this->len = n;
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T *str, std::size_t n)
    {
        if (n != 0 && str)
        {
            this->len = 0;
            std::size_t str_len = this->sstr_strlen(str) * n;
            this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            for (std::size_t i = 0; i < n; i++)
                this->fast_strncat(this->src, str, this->len);
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const sstring_t_view<T> &other)
    {
        if (other.src)
        {
            this->len = 0;
            this->src = static_cast<T *>(std::calloc(other.len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, other.src, this->len);
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(sstring_t_view<T> &&other) noexcept
    {
        this->src = other.src;
        this->len = other.len;
        other.src = nullptr;
        other.len = 0;
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const std::initializer_list<T> &list)
    {
        this->len = 0;
        std::size_t str_len = list.size();
        this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);
        for (auto i = list.begin(); i != list.end(); i++)
        {
            if (*i != 0)
                this->src[this->len++] = *i;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const std::initializer_list<sstring_t_view<T>> &list)
    {
        this->len = 0;
        std::size_t str_len = 0;
        for (auto i = list.begin(); i != list.end(); i++)
            str_len += (*i).len;

        this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);

        for (auto i = list.begin(); i != list.end(); i++)
        {
            if ((*i).src)
            {
                for (std::size_t j = 0; j < (*i).len; j++)
                    this->src[this->len++] = (*i).src[j];
            }
        }
    }

    template <typename T>
    constexpr inline std::size_t sstring_t_view<T>::nerr() const noexcept
    {
        return static_cast<std::size_t>(-1);
    }

    template <typename T>
    sstring_t_view<T>::~sstring_t_view()
    {
        if (this->src)
            std::free(this->src);
        this->src = nullptr;
        this->len = 0;
    }
}

#endif