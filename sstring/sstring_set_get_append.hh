/**
 * @file sstring_set_get_append.hh
 * @brief This file contains definition of set, get and append functions. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef SSTRING_SET_GET_APPEND_DEFINED
#define SSTRING_SET_GET_APPEND_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set(const T *str)
    {
        if (str)
        {
            if (this->src)
                std::free(this->src);
            this->len = 0;
            std::size_t str_len = this->sstr_strlen(str);
            this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, str, this->len);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set(const sstring_t_view<T> &str)
    {
        return this->set(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_char(const T c)
    {
        if (c != 0)
        {
            if (this->src)
                std::free(this->src);
            this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
            exit_heap_fail(this->src);
            this->src[this->len++] = c;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_upto(const T *str, std::size_t N)
    {
        if (str && (N <= this->sstr_strlen(str)))
        {
            if (this->src)
                std::free(this->src);
            this->src = static_cast<T *>(std::calloc(N + 1, sizeof(T)));
            exit_heap_fail(this->src);
            std::memmove(this->src, str, N * sizeof(T));
            this->len = N;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_upto(const sstring_t_view<T> &str, std::size_t N)
    {
        return this->set_upto(str.src, N);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_random(std::size_t rnd_len)
    {
        if (rnd_len != 0)
        {
            if (this->src)
                std::free(this->src);
            this->src = static_cast<T *>(std::calloc(rnd_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            for (std::size_t i = 0; i < rnd_len; i++)
                this->src[i] = (rand() % (126 - 32 + 1)) + 32;
            this->len = rnd_len;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_array(const vector_t<T *> &vec, const T *between)
    {
        if (this->src)
            std::free(this->src);
        this->len = 0;

        std::size_t vec_str_len = 0, bw_len = 0;

        if (between)
            bw_len = this->sstr_strlen(between);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i])
                vec_str_len += this->sstr_strlen(vec[i]);
        }

        if (between)
            vec_str_len += vec.length() * bw_len;

        this->src = static_cast<T *>(std::calloc(vec_str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i])
            {
                this->fast_strncat(this->src, vec[i], this->len);
                if (between)
                    this->fast_strncat(this->src, between, this->len);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_array(const vector_t<sstring_t_view<T>> &vec, const T *between)
    {
        if (this->src)
            std::free(this->src);
        this->len = 0;

        std::size_t vec_str_len = 0, bw_len = 0;

        if (between)
            bw_len = this->sstr_strlen(between);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i].src)
                vec_str_len += vec[i].len;
        }

        if (between)
            vec_str_len += vec.length() * bw_len;

        this->src = static_cast<T *>(std::calloc(vec_str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i].src)
            {
                this->fast_strncat(this->src, vec[i].src, this->len);
                if (between)
                    this->fast_strncat(this->src, between, this->len);
            }
        }
        return *this;
    }

    template <typename T>
    T *&sstring_t_view<T>::get()
    {
        return this->src;
    }

    template <typename T>
    const T *sstring_t_view<T>::c_str() const
    {
        return this->src;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::get_ref()
    {
        return *this;
    }

    template <typename T>
    sstring_t_view<T> *sstring_t_view<T>::get_ptr()
    {
        return this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append(const T *str)
    {
        if (str)
        {
            std::size_t str_len = this->sstr_strlen(str);
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + str_len + 1)));
                exit_heap_fail(this->src);
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
            }
            this->fast_strncat(this->src, str, this->len);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append(const sstring_t_view<T> &str)
    {
        return this->append(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_char(const T c)
    {
        if (c != 0)
        {
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + 2)));
                exit_heap_fail(this->src);
                this->init_n_zeroes(this->src, this->len, this->len + 2);
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
            }
            this->src[this->len++] = c;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_upto(const T *str, std::size_t N)
    {
        if (str && (N <= this->sstr_strlen(str)))
        {
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + N + 1)));
                exit_heap_fail(this->src);
                std::memmove(this->src + this->len, str, N * sizeof(T));
                this->len += N;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(N + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
                std::memmove(this->src, str, N * sizeof(T));
                this->len = N;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_upto(const sstring_t_view<T> &str, std::size_t N)
    {
        return this->append_upto(str.src, N);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start(const T *str)
    {
        if (str)
        {
            std::size_t str_len = this->sstr_strlen(str);
            if (this->src)
            {
                T *buff = static_cast<T *>(std::calloc(str_len + this->len + 1, sizeof(T)));
                exit_heap_fail(buff);
                this->len = 0;
                this->fast_strncat(buff, str, this->len);
                this->fast_strncat(buff, this->src, this->len);

                std::free(this->src);
                this->src = buff;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
                this->fast_strncat(this->src, str, this->len);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start(const sstring_t_view<T> &str)
    {
        return this->append_start(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_char(const T c)
    {
        if (c != 0)
        {
            if (this->src)
            {
                T *buff = static_cast<T *>(std::calloc(this->len + 2, sizeof(T)));
                exit_heap_fail(buff);
                this->len = 1;
                std::memmove(buff, &c, sizeof(T));
                this->fast_strncat(buff, this->src, this->len);

                std::free(this->src);
                this->src = buff;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
                exit_heap_fail(this->src);
                std::memmove(this->src, &c, sizeof(T));
                this->len = 1;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_upto(const T *str, std::size_t N)
    {
        if (str && (N <= this->sstr_strlen(str)))
        {
            if (this->src)
            {
                T *buff = static_cast<T *>(std::calloc(N + this->len + 1, sizeof(T)));
                exit_heap_fail(buff);
                this->len = N;
                std::memmove(buff, str, N * sizeof(T));
                this->fast_strncat(buff, this->src, this->len);

                std::free(this->src);
                this->src = buff;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(N + 1, sizeof(T)));
                exit_heap_fail(this->src);
                std::memmove(this->src, str, N * sizeof(T));
                this->len = N;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_upto(const sstring_t_view<T> &str, std::size_t N)
    {
        return this->append_start_upto(str.src, N);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_array(const vector_t<T *> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i])
                    vec_str_len += this->sstr_strlen(vec[i]);
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + vec_str_len + 1)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i])
                {
                    this->fast_strncat(this->src, vec[i], this->len);
                    if (between)
                        this->fast_strncat(this->src, between, this->len);
                }
            }
        }
        else
        {
            this->set_array(vec, between);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_array(const vector_t<sstring_t_view<T>> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i].src)
                    vec_str_len += vec[i].len;
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + vec_str_len + 1)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i].src)
                {
                    this->fast_strncat(this->src, vec[i].src, this->len);
                    if (between)
                        this->fast_strncat(this->src, between, this->len);
                }
            }
        }
        else
        {
            this->set_array(vec, between);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_array(const vector_t<T *> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i])
                    vec_str_len += this->sstr_strlen(vec[i]);
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            T *buff = static_cast<T *>(std::calloc(this->len + vec_str_len + 1, sizeof(T)));
            exit_heap_fail(buff);
            std::size_t track = 0;
            this->fast_strncat(buff, this->src, track);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                this->fast_strncat(buff, vec[i], track);
                if (between)
                    this->fast_strncat(buff, between, track);
            }

            std::free(this->src);
            this->src = buff;
            this->len = track;
        }
        else
        {
            this->set_array(vec, between);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_array(const vector_t<sstring_t_view<T>> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i].src)
                    vec_str_len += vec[i].len;
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            T *buff = static_cast<T *>(std::calloc(this->len + vec_str_len + 1, sizeof(T)));
            exit_heap_fail(buff);
            std::size_t track = 0;
            this->fast_strncat(buff, this->src, track);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                this->fast_strncat(buff, vec[i].src, track);
                if (between)
                    this->fast_strncat(buff, between, track);
            }

            std::free(this->src);
            this->src = buff;
            this->len = track;
        }
        else
        {
            this->set_array(vec, between);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::char_set(const T new_char, std::size_t nth)
    {
        if (this->len >= nth && new_char != 0 && this->src)
            this->src[nth] = new_char;
        return *this;
    }

    template <typename T>
    const T &sstring_t_view<T>::char_get(std::size_t nth) const
    {
        if (this->len >= nth && this->src)
            return this->src[nth];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    T &sstring_t_view<T>::char_get(std::size_t nth)
    {
        if (this->len >= nth && this->src)
            return this->src[nth];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    const std::size_t &sstring_t_view<T>::length() const
    {
        return this->len;
    }

    template <typename T>
    const std::size_t &sstring_t_view<T>::change_length(std::size_t new_length)
    {
        this->len = new_length;
        return this->len;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_formatted(std::size_t buffer_length, const char *__format__, ...)
    {
        if (!__format__)
            return *this;

        char *buff = static_cast<char *>(std::calloc(buffer_length + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::va_list ar;
        va_start(ar, __format__);
        std::vsnprintf(buff, buffer_length, __format__, ar);
        va_end(ar);

        if (this->src)
            std::free(this->src);

        this->src = reinterpret_cast<T *>(buff);
        this->len = 0;
        while (this->src[this->len] != 0)
            this->len++;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_formatted(std::size_t buffer_length, const char *__format__, ...)
    {
        if (!__format__)
            return *this;

        char *buff = static_cast<char *>(std::calloc(buffer_length + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::va_list ar;
        va_start(ar, __format__);
        std::vsnprintf(buff, buffer_length, __format__, ar);
        va_end(ar);

        if (!this->src)
        {
            this->src = reinterpret_cast<T *>(buff);
            this->len = 0;
            while (this->src[this->len] != 0)
                this->len++;
        }
        else
        {
            this->append(convert_sstring<T, char>(buff));
            std::free(buff);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::getline(std::size_t line) const
    {
        if (!this->src)
            return nullptr;

        vector_t<sstring_t_view<T>> vec_split = this->split(convert_sstring<T, char>("\n"));
        if (line >= vec_split.length())
            return nullptr;
        sstring_t_view<T> ret = std::move(vec_split[line]);
        vec_split.erase();
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::substr(std::size_t index, std::size_t sub_len) const
    {
        if (index >= this->len || !this->src)
            return nullptr;
        if (sub_len == this->nerr() || index + sub_len > this->len)
            sub_len = this->len - index;
        T *buff = static_cast<T *>(std::calloc(sub_len + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::memmove(buff, this->src + index, sub_len * sizeof(T));

        sstring_t_view ret;
        ret.src = buff;
        ret.len = sub_len;
        return ret;
    }
}

#endif