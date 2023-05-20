/**
 * @file sstring_memory.hh
 * @brief This file contains definition of memory management functions. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef OPENUTILS_SSTRING_MEMORY_DEFINED
#define OPENUTILS_SSTRING_MEMORY_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::clear()
    {
        if (this->src)
            std::free(this->src);
        this->src = nullptr;
        this->len = 0;
        return *this;
    }

    template <typename T>
    bool sstring_t_view<T>::resize(std::size_t new_len)
    {
        if (new_len > 0 && new_len > this->len)
        {
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * new_len));
                exit_heap_fail(this->src);
                this->init_n_zeroes(this->src, this->len, new_len);
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(new_len, sizeof(T)));
                exit_heap_fail(this->src);
            }
            return true;
        }
        return false;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::shrink_to_fit()
    {
        if (!this->src)
            return *this;
        T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
        exit_heap_fail(buff);
        std::size_t tempLen = 0;
        this->fast_strncat(buff, this->src, tempLen);
        std::free(this->src);
        this->src = buff;
        this->len = tempLen; // same though
        return *this;
    }
}

#endif