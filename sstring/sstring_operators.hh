/**
  * @file sstring_operators.hh
  * @brief This file contains definition of operator functions. Do NOT directly include this file.
  * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
  * @version 3.0.0
  * @author Tushar Chaurasia (Dark-CodeX)
*/

#ifndef SSTRING_OPERATORS_DEFINED
#define SSTRING_OPERATORS_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    const T &sstring_t_view<T>::operator[](std::size_t n) const
    {
        if (this->len >= n && this->src)
            return this->src[n];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    T &sstring_t_view<T>::operator[](std::size_t n)
    {
        if (this->len >= n && this->src)
            return this->src[n];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::operator+(const T c) const
    {
        sstring_t_view x = sstring_t_view(this->src);
        x.append_char(c);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::operator+(const T *str) const
    {
        sstring_t_view x = sstring_t_view(this->src);
        x.append(str);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::operator+(const sstring_t_view<T> &str) const
    {
        sstring_t_view x = sstring_t_view(this->src);
        x.append(str.src);
        return x;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const T c)
    {
        return this->append_char(c);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const T *str)
    {
        return this->append(str);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const sstring_t_view<T> &str)
    {
        return this->append(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const std::initializer_list<T> &list)
    {
        for (const auto &i : list)
            this->append_char(i);
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const std::initializer_list<sstring_t_view<T>> &list)
    {
        for (const auto &i : list)
            this->append(i.src);
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(const T c)
    {
        return this->set_char(c);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(const T *str)
    {
        return this->set(str);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(const sstring_t_view<T> &str)
    {
        if (this != &str)
            return this->set(str.src);
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(sstring_t_view<T> &&__s) noexcept
    {
        if (this != &__s)
        {
            if (this->src)
                std::free(this->src);
            this->len = __s.len;
            this->src = __s.src;
            __s.src = nullptr;
            __s.len = 0;
        }
        return *this;
    }

    template <typename T>
    bool sstring_t_view<T>::operator==(const T *str) const
    {
        return this->compare(str);
    }

    template <typename T>
    bool sstring_t_view<T>::operator==(const sstring_t_view<T> &str) const
    {
        return this->compare(str.src);
    }

    template <typename T>
    bool sstring_t_view<T>::operator<(const T *str) const
    {
        if (this->lexicographical_comparison(str) < 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator<(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) < 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>(const T *str) const
    {
        if (this->lexicographical_comparison(str) > 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) > 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator<=(const T *str) const
    {
        if (this->lexicographical_comparison(str) <= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator<=(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) <= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>=(const T *str) const
    {
        if (this->lexicographical_comparison(str) >= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>=(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) >= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator!=(const T *str) const
    {
        return !(this->compare(str));
    }

    template <typename T>
    bool sstring_t_view<T>::operator!=(const sstring_t_view<T> &str) const
    {
        return !(this->compare(str.src));
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &out, const sstring_t_view<T> &obj)
    {
        out << obj.c_str();
        return out;
    }

    template <typename T>
    std::wostream &operator<<(std::wostream &out, const sstring_t_view<T> &obj)
    {
        out << obj.c_str();
        return out;
    }
};

#endif