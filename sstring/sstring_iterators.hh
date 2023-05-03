#ifndef SSTRING_ITERATORS_DEFINED
#define SSTRING_ITERATORS_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    const T *sstring_t_view<T>::cbegin() const
    {
        if (this->src)
            return this->src;
        return nullptr;
    }

    template <typename T>
    const T *sstring_t_view<T>::cend() const
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::begin()
    {
        if (this->src)
            return this->src;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::end()
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    const T *sstring_t_view<T>::crbegin() const
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    const T *sstring_t_view<T>::crend() const
    {
        if (this->src)
            return this->src;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::rbegin()
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::rend()
    {
        if (this->src)
            return this->src;
        return nullptr;
    }
}

#endif