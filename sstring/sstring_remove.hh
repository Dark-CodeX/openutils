/**
 * @file sstring_remove.hh
 * @brief This file contains definition of sstring removing functions. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef SSTRING_REMOVE_DEFINED
#define SSTRING_REMOVE_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove(const T *sub)
    {
        if (sub && sub[0] != 0 && this->src)
        {
            vector_t<std::size_t> indexes;
            std::size_t occur = this->find(sub);
            if (occur == this->nerr())
                return *this;
            indexes.add(occur);
            while (true)
            {
                occur = this->find_next(occur + 1, sub);
                if (occur == this->nerr())
                    break;
                indexes.add(occur);
            }

            std::size_t sub_len = this->sstr_strlen(sub);
            // now we have all indexes where sub has occurred

            std::size_t buff_len = this->len - (sub_len * indexes.length());
            T *buff = static_cast<T *>(std::calloc(buff_len + 1, sizeof(T)));
            exit_heap_fail(buff);

            std::size_t track = 0;
            for (std::size_t i = 0, k = 0; i < indexes.length(); i++)
            {
                for (; k < indexes[i]; track++, k++)
                {
                    buff[track] = this->src[k];
                }
                k += sub_len;
            }
            this->fast_strncat(buff, this->src + indexes[indexes.length() - 1] + sub_len, track);

            std::free(this->src);
            this->src = buff;
            this->len = track;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove(const sstring_t_view<T> &sub)
    {
        return this->remove(sub.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_char(const T c)
    {
        if (c != 0 && this->src)
        {
            std::size_t z = this->count_char(c);
            T *buff = static_cast<T *>(std::calloc(this->len - z + 1, sizeof(T)));
            exit_heap_fail(buff);

            std::size_t buff_len = 0;
            for (std::size_t i = 0; this->src[i] != 0; i++)
            {
                if (this->src[i] != c)
                    buff[buff_len++] = this->src[i];
            }

            std::free(this->src);
            this->src = buff;
            this->len = buff_len;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_extra_char(const T c)
    {
        if (c != 0 && this->src)
        {
            T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(buff);

            std::size_t p = 0, i = 0;
            while (this->src[p] != 0)
            {
                if (!(this->src[p] == c && this->src[p + 1] == c))
                    buff[i++] = this->src[p];
                p++;
            }
            std::free(this->src);
            this->src = buff;
            this->len = i;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_range(std::size_t from, std::size_t till)
    {
        if (!this->src)
            return *this;
        if (till > this->len || from > this->len || from > till || till == from)
            return *this;
        T *buff = static_cast<T *>(std::calloc(this->len - (till - from) + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::size_t k = 0;
        for (std::size_t i = 0; i < this->len; i++)
        {
            if (i == from)
                i = till + 1;
            buff[k++] = this->src[i];
        }

        std::free(this->src);
        this->src = buff;
        this->len = k;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::intersect(std::size_t from, std::size_t till)
    {
        if (!this->src)
            return *this;
        if (till > this->len || from > this->len || from > till || till == from)
            return *this;
        T *buff = static_cast<T *>(std::calloc(till - from + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::size_t k = 0;
        for (std::size_t i = from; i <= till; i++)
            buff[k++] = this->src[i];

        std::free(this->src);
        this->src = buff;
        this->len = k;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_first_char()
    {
        if (!this->src)
            return *this;
        if (this->src[0] == 0)
            return *this;

        T *buff = static_cast<T *>(std::calloc(this->len, sizeof(T)));
        exit_heap_fail(buff);

        std::size_t z = 0;
        for (std::size_t i = 1; i < this->len; i++)
            buff[z++] = this->src[i];

        std::free(this->src);
        this->src = buff;
        this->len = z;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_last_char()
    {
        if (!this->src)
            return *this;
        this->src[this->len - 1] = 0;
        this->len--;
        return *this;
    }
}

#endif