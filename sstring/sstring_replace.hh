/**
 * @file sstring_replace.hh
 * @brief This file contains definition of replace functions. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef OPENUTILS_SSTRING_REPLACE_DEFINED
#define OPENUTILS_SSTRING_REPLACE_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace(const T *old, const T *new_)
    {
        if (old && new_ && this->src)
        {
            vector_t<std::size_t> indexes;
            std::size_t occur = this->find(old);
            if (occur == this->nerr())
                return *this;
            indexes.add(occur);
            while (true)
            {
                occur = this->find_next(occur + 1, old);
                if (occur == this->nerr())
                    break;
                indexes.add(occur);
            }

            std::size_t old_len = this->sstr_strlen(old), new_len = this->sstr_strlen(new_);

            // now we have got every points (indexes) where `old` is present

            std::size_t buff_len = this->len + (new_len * indexes.length()) - (old_len * indexes.length());
            T *buff = static_cast<T *>(std::calloc(buff_len + 1, sizeof(T)));
            exit_heap_fail(buff);

            std::size_t track = 0;
            for (std::size_t i = 0, k = 0; i < indexes.length(); i++)
            {
                for (; k < indexes[i]; track++, k++)
                {
                    buff[track] = this->src[k];
                }
                k += old_len;
                this->fast_strncat(buff, new_, track);
            }
            this->fast_strncat(buff, this->src + indexes[indexes.length() - 1] + old_len, track);

            std::free(this->src);
            this->src = buff;
            this->len = track;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace(const sstring_t_view<T> &old, const sstring_t_view<T> &new_)
    {
        return this->replace(old.src, new_.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace_line(std::size_t line_no, const T *new_)
    {
        if (!new_ || !this->src || this->len == 0)
            return *this;
        vector_t<sstring_t_view<T>> vec_split = this->split(convert_sstring<T, char>("\n"));
        if (line_no >= vec_split.length())
            return *this;
        std::size_t nlen = this->sstr_strlen(new_);
        sstring_t_view<T> buff;
        std::size_t track = 0;

        for (std::size_t i = 0; i < vec_split.length(); i++)
        {
            if (i == line_no)
            {
                for (std::size_t j = 0; j < nlen; j++)
                    buff += new_[j];
            }
            else
            {
                for (std::size_t j = 0; j < vec_split[i].len; j++)
                    buff += vec_split[i].src[j];
            }
            if (i != vec_split.length() - 1)
                buff += 10;
        }

        std::free(this->src);
        this->src = buff.src;
        this->len = buff.len;
        buff.src = nullptr;
        buff.len = 0;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace_line(std::size_t line_no, const sstring_t_view<T> &new_)
    {
        return this->replace_line(line_no, new_.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace_char(const T old, const T new_)
    {
        if (old != 0 && new_ != 0 && this->src)
            for (std::size_t i = 0; this->src[i] != 0; i++)
                if (this->src[i] == old)
                    this->src[i] = new_;
        return *this;
    }
}

#endif