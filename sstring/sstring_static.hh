/**
  * @file sstring_static.hh
  * @brief This file contains definition of static functions of sstring_t_view class. Do NOT directly include this file.
  * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
  * @version 3.0.0
  * @author Tushar Chaurasia (Dark-CodeX)
*/

#ifndef SSTRING_STATIC_DEFINED
#define SSTRING_STATIC_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    void sstring_t_view<T>::sort(sstring_t_view *arr, std::size_t len)
    {
        std::sort(arr, arr + len);
    }

    template <typename T>
    void sstring_t_view<T>::sort(T **arr, std::size_t len)
    {
        std::sort(arr, arr + len, [](T *a, T *b)
                  { return sstring_t_view(a) < sstring_t_view(b); });
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(T c)
    {
        sstring_t_view x;
        x.set_char(c);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(bool boolean)
    {
        sstring_t_view x;
        if (boolean)
            x = convert_sstring<T, char>("true");
        else
            x = convert_sstring<T, char>("false");
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(const T *str)
    {
        sstring_t_view x = str;
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(void *ptr)
    {
        char s[std::numeric_limits<std::size_t>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<std::size_t>::digits10 + 1, "%p", ptr);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed short int x)
    {
        char s[std::numeric_limits<signed short int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed short int>::digits10 + 2, "%hi", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned short int x)
    {
        char s[std::numeric_limits<unsigned short int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned short int>::digits10 + 1, "%hu", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed int x)
    {
        char s[std::numeric_limits<signed int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed int>::digits10 + 2, "%d", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned int x)
    {
        char s[std::numeric_limits<unsigned int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned int>::digits10 + 1, "%i", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed long int x)
    {
        char s[std::numeric_limits<signed long int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed long int>::digits10 + 2, "%ld", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned long int x)
    {
        char s[std::numeric_limits<unsigned long int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned long int>::digits10 + 1, "%lu", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed long long int x)
    {
        char s[std::numeric_limits<signed long long int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed long long int>::digits10 + 2, "%lld", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned long long int x)
    {
        char s[std::numeric_limits<unsigned long long int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned long long int>::digits10 + 1, "%llu", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(float x)
    {
        char s[std::numeric_limits<float>::digits10 + 4] = {};
        std::snprintf(s, std::numeric_limits<float>::digits10 + 4, "%f", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(double x)
    {
        char s[std::numeric_limits<double>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<double>::digits10 + 2, "%lf", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(long double x)
    {
        char s[std::numeric_limits<long double>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<long double>::digits10 + 2, "%Lf", x);
        return sstring_t_view(convert_sstring<T, char>(s));
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::get_random(const std::size_t &len)
    {
        sstring_t_view x;
        x.set_random(len);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::get_input()
    {
        sstring_t_view x;
        x.in();
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::open_file(const sstring_t_view<char> &location)
    {
        sstring_t_view x;
        x.open(location);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::end_line()
    {
#if defined __linux__ || defined linux || defined __linux
        return sstring_t_view(convert_sstring<T, char>("\n"));
#elif _WIN32 || defined _WIN64 || defined __CYGWIN__
        return sstring_t_view(convert_sstring<T, char>("\r\n"));
#elif defined __unix__ || defined __unix || defined unix
        return sstring_t_view(convert_sstring<T, char>("\n"));
#elif defined __APPLE__ || defined __MACH__
        return sstring_t_view(convert_sstring<T, char>("\n"));
#elif defined __FreeBSD__
        return sstring_t_view(convert_sstring<T, char>("\n"));
#elif defined __ANDROID__
        return sstring_t_view(convert_sstring<T, char>("\n"));
#else
        return sstring_t_view(convert_sstring<T, char>("\n"));
#endif
    }
}

#endif