#ifndef SSTRING_FIND_DEFINED
#define SSTRING_FIND_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    std::size_t sstring_t_view<T>::index_of(T ch) const
    {
        if (ch != 0 && this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (this->src[i] == ch)
                    return i;
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::last_index_of(T ch) const
    {
        if (ch != 0 && this->src)
        {
            for (std::size_t i = this->len - 1; i != static_cast<std::size_t>(-1); i--)
                if (this->src[i] == ch)
                    return i;
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find(const T *sub) const
    {
        if (sub && this->src)
        {
            T *buff = this->fast_strstr(this->src, this->len, sub);
            if (buff)
                return this->len - this->sstr_strlen(buff);
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find(const sstring_t_view<T> &sub) const
    {
        return this->find(sub.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::rfind(const T *sub) const
    {
        if (sub && this->src)
        {
            const T *last = nullptr;
            const T *cur = this->src;

            while ((cur = this->fast_strstr(cur, this->sstr_strlen(cur), sub)) != nullptr)
            {
                last = cur;
                cur++;
            }

            return last ? static_cast<std::size_t>(last - this->src) : this->nerr();
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::rfind(const sstring_t_view<T> &sub) const
    {
        return this->rfind(sub.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find_next(std::size_t last_index, const T *sub) const
    {
        if (sub && this->src)
        {
            T *buff = this->fast_strstr(this->src + last_index, this->len - last_index, sub);
            if (buff)
                return this->len - this->sstr_strlen(buff);
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find_next(std::size_t last_index, const sstring_t_view<T> &sub) const
    {
        return this->find_next(last_index, sub.src);
    }
}

#endif