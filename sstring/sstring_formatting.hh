/**
  * @file sstring_formatting.hh
  * @brief This file contains definition of formatting functions. Do NOT directly include this file.
  * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
  * @version 3.0.0
  * @author Tushar Chaurasia (Dark-CodeX)
*/

#ifndef SSTRING_FORMATTING_DEFINED
#define SSTRING_FORMATTING_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const T *prefix, const T *suffix) const
    {
        if (!prefix || !suffix || !this->src)
            return nullptr;
        std::size_t plen = this->sstr_strlen(prefix), slen = this->sstr_strlen(suffix);
        T *buff = static_cast<T *>(std::calloc(this->len + plen + slen + 1, sizeof(T)));
        exit_heap_fail(buff);
        std::size_t track = 0;
        this->fast_strncat(buff, prefix, track);
        this->fast_strncat(buff, this->src, track);
        this->fast_strncat(buff, suffix, track);
        // done copying
        sstring_t_view<T> ret;
        ret.src = buff;
        ret.len = track;
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const sstring_t_view<T> &prefix, const sstring_t_view<T> &suffix) const
    {
        return this->wrap(prefix.src, suffix.src);
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const T *str) const
    {
        if (!str || !this->src)
            return nullptr;
        std::size_t pslen = this->sstr_strlen(str);
        T *buff = static_cast<T *>(std::calloc(this->len + pslen + pslen + 1, sizeof(T)));
        exit_heap_fail(buff);
        std::size_t track = 0;
        this->fast_strncat(buff, str, track);
        this->fast_strncat(buff, this->src, track);
        this->fast_strncat(buff, str, track);
        // done copying
        sstring_t_view<T> ret;
        ret.src = buff;
        ret.len = track;
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const sstring_t_view<T> &str) const
    {
        return this->wrap(str.src);
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::center(std::size_t col_size, const T *padding) const
    {
        if (!this->src)
        {
            if (!padding)
                return sstring_t_view<T>(convert_sstring<T, char>(" ").c_str(), col_size);
            return sstring_t_view<T>(padding, col_size);
        }
        if (col_size == 0 || col_size <= this->len)
            return sstring_t_view<T>(this->src);
        sstring_t_view<T> ret;
        std::size_t temp_padding = (col_size - this->len) / 2;
        if (padding)
        {
            for (std::size_t i = 0; i < temp_padding; i++)
                ret += padding;
            ret += *this;
            for (std::size_t i = 0; i < temp_padding; i++)
                ret += padding;
        }
        else
        {
            sstring_t_view<T> conversion = convert_sstring<T, char>(" ");
            for (std::size_t i = 0; i < temp_padding; i++)
                ret += conversion;
            ret += *this;
            for (std::size_t i = 0; i < temp_padding; i++)
                ret += conversion;
        }
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::center(std::size_t col_size, const sstring_t_view<T> &padding) const
    {
        return this->center(col_size, padding.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::format_escape_sequence()
    {
        this->replace(convert_sstring<T, char>("\\"), convert_sstring<T, char>("\\\\"));
        this->replace(convert_sstring<T, char>("\a"), convert_sstring<T, char>("\\a"));
        this->replace(convert_sstring<T, char>("\b"), convert_sstring<T, char>("\\b"));
        this->replace(convert_sstring<T, char>("\f"), convert_sstring<T, char>("\\f"));
        this->replace(convert_sstring<T, char>("\n"), convert_sstring<T, char>("\\n"));
        this->replace(convert_sstring<T, char>("\r"), convert_sstring<T, char>("\\r"));
        this->replace(convert_sstring<T, char>("\t"), convert_sstring<T, char>("\\t"));
        this->replace(convert_sstring<T, char>("\v"), convert_sstring<T, char>("\\v"));
        this->replace(convert_sstring<T, char>("\""), convert_sstring<T, char>("\\\""));
        this->replace(convert_sstring<T, char>("\'"), convert_sstring<T, char>("\\\'"));
        this->replace(convert_sstring<T, char>("\?"), convert_sstring<T, char>("\\\?"));
        return *this;
    }
}

#endif