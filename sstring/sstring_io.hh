/**
 * @file sstring_io.hh
 * @brief This file contains definition of input/output functions. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef OPENUTILS_SSTRING_IO_DEFINED
#define OPENUTILS_SSTRING_IO_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    bool sstring_t_view<T>::save(const char *location) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "wb");
            if (f != nullptr)
            {
                std::fwrite(this->src, this->len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::save(const sstring_t_view<char> &location) const
    {
        return this->save(location.c_str());
    }

    template <typename T>
    bool sstring_t_view<T>::append_file(const char *location) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "ab");
            if (f != nullptr)
            {
                std::fwrite(this->src, this->len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::append_file(const sstring_t_view<char> &location) const
    {
        return this->append_file(location.c_str());
    }

    template <typename T>
    bool sstring_t_view<T>::open(const char *location)
    {
        if (location)
        {
            std::FILE *f = std::fopen(location, "rb");
            if (f)
            {
                std::fseek(f, 0, SEEK_END);
                std::size_t file_len = std::ftell(f);
                std::fseek(f, 0, SEEK_SET);
                if (this->src)
                    std::free(this->src);
                this->src = static_cast<T *>(std::calloc(file_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                std::fread(this->src, file_len, sizeof(T), f);
                std::fclose(f);
                this->len = file_len;
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::open(const sstring_t_view<char> &location)
    {
        return this->open(location.c_str());
    }

    template <typename T>
    bool sstring_t_view<T>::save_binary(const char *location, std::size_t bin_len) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "wb");
            if (f != nullptr)
            {
                std::fwrite(this->src, bin_len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::append_binary(const char *location, std::size_t bin_len) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "ab");
            if (f != nullptr)
            {
                std::fwrite(this->src, bin_len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::add_binary(const T *data, std::size_t &bin_len)
    {
        if (data)
        {
            if (!this->src)
            {
                this->len = 0;
                this->src = static_cast<T *>(std::calloc(bin_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->fast_strncat(this->src, data, this->len);
                return *this;
            }
            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + bin_len + 1)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, data, this->len);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::in()
    {
        if (this->src)
            std::free(this->src);

        std::size_t cap = 64, len_input = 0;
        T ch;
        this->src = static_cast<T *>(std::calloc(cap, sizeof(T)));
        exit_heap_fail(this->src);

        while ((ch = std::getchar()))
        {
            if (ch == 10 || ch == 0 || ch == EOF)
                break;
            this->src[len_input++] = ch;
            if (len_input == cap)
            {
                cap += 64;
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * cap));
                exit_heap_fail(this->src);
            }
        }
        this->src[len_input] = 0;
        this->len = len_input;
        return *this;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::print() const
    {
        if (!this->src || this->len == 0)
            return 0;
        std::setvbuf(stdout, nullptr, _IOFBF, this->len);
        std::size_t i = 0;
        for (; i < this->len; i++)
            std::putc(this->src[i], stdout);
        std::fflush(stdout);
        return i;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::println() const
    {
        if (!this->src || this->len == 0)
            return 0;
        std::setvbuf(stdout, nullptr, _IOFBF, this->len + 1);
        std::size_t i = 0;
        for (; i < this->len; i++)
            std::putc(this->src[i], stdout);
        std::putc(10, stdout); // new line character
        std::fflush(stdout);
        return i;
    }
}

#endif