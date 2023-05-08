/**
 * @file sstring_boolean.hh
 * @brief This file contains definition of bool returning functions. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef SSTRING_BOOLEAN_DEFINED
#define SSTRING_BOOLEAN_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    bool sstring_t_view<T>::is_empty() const
    {
        return (this->len == 0);
    }

    template <typename T>
    bool sstring_t_view<T>::is_null() const
    {
        if (this->src)
            return false;
        return true;
    }

    template <typename T>
    bool sstring_t_view<T>::compare(const T *T1) const
    {
        if (T1 && this->src)
            if (this->sstr_strcmp(this->src, T1) == 0)
                return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::compare(const sstring_t_view<T> &T1) const
    {
        return this->compare(T1.src);
    }

    template <typename T>
    bool sstring_t_view<T>::compare_upto(const T *T1, std::size_t N) const
    {
        if (T1 && this->src)
            if (this->sstr_strncmp(this->src, T1, N) == 0)
                return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::compare_upto(const sstring_t_view<T> &T1, std::size_t N) const
    {
        return this->compare_upto(T1.src, N);
    }

    template <typename T>
    bool sstring_t_view<T>::is_changed(sstring_t_view<T> &obj)
    {
        // CASE 1: nullptr
        if (this->src == nullptr && obj.src == nullptr)
            return true;
        else if (this->src == nullptr && obj.src != nullptr)
            return false;
        else if (this->src != nullptr && obj.src == nullptr)
            return false;
        else
        {
            // now both src are not nullptr
            // CASE 2: length compare
            if (this->len != obj.len)
                return false;
            else
            {
                // now both src have equal length
                // CASE 3: text compare
                return this->compare(obj.src);
            }
        }
    }

    template <typename T>
    bool sstring_t_view<T>::contains(const T *str) const
    {
        if (str && this->src)
            if (this->fast_strstr(this->src, this->len, str) != nullptr)
                return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::contains(const sstring_t_view<T> &str) const
    {
        return this->contains(str.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::contains_char(const T c) const
    {
        if (c != 0 && this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; i++)
                if (this->src[i] == c)
                    return i;
        }
        return this->nerr();
    }

    template <typename T>
    bool sstring_t_view<T>::is_digit() const
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (!std::isdigit(this->src[i]))
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::is_decimal() const
    {
        if (this->src)
        {
            std::size_t point_cnt = 0;
            for (std::size_t i = 0; i < this->len; i++)
            {
                if (this->src[i] == 46)
                {
                    point_cnt++;
                    if (point_cnt > 1)
                        return false;
                }
                else if (!std::isdigit(this->src[i]))
                    return false;
            }
            if (point_cnt == 1)
                return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::is_ascii() const
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (this->src[i] < 0 || this->src[i] > 127)
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::is_alphabetic() const
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (!std::isalpha(this->src[i]))
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::starts_with(const T *str) const
    {
        if (str && this->src)
        {
            if (this->sstr_strlen(str) > this->len)
                return false;
            for (std::size_t i = 0; str[i] != 0 && this->src[i] != 0; i++)
                if (this->src[i] != str[i])
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::starts_with(const sstring_t_view<T> &str) const
    {
        return this->starts_with(str.src);
    }

    template <typename T>
    bool sstring_t_view<T>::ends_with(const T *str) const
    {
        if (str && this->src)
        {
            std::size_t str_len = this->sstr_strlen(str);
            if (str_len > this->len)
                return false;
            for (std::size_t i = this->len - str_len, z = 0; str[z] != 0 && this->src[i] != 0; i++, z++)
                if (this->src[i] != str[z])
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::ends_with(const sstring_t_view<T> &str) const
    {
        return this->ends_with(str.src);
    }
}

#endif