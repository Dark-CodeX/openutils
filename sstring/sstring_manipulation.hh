#ifndef SSTRING_MANIPULATION_DEFINED
#define SSTRING_MANIPULATION_DEFINED

#include "./sstring_class.hh"

namespace openutils
{
    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::to_upper()
    {
        if (this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; ++i)
            {
                if (std::islower(this->src[i]))
                    this->src[i] = std::toupper(this->src[i]);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::to_lower()
    {
        if (this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; ++i)
            {
                if (std::isupper(this->src[i]))
                    this->src[i] = std::tolower(this->src[i]);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::swap_case()
    {
        if (this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; ++i)
            {
                if (std::islower(this->src[i]))
                    this->src[i] = std::toupper(this->src[i]);
                else if (std::isupper(this->src[i]))
                    this->src[i] = std::tolower(this->src[i]);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::to_set()
    {
        if (this->src)
        {
            std::unordered_map<T, std::size_t> freq;
            for (std::size_t i = 0; i < this->len; i++)
                freq[this->src[i]] += 1;

            std::free(this->src);
            this->len = freq.size();
            this->src = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(this->src);

            this->len = 0;
            for (const auto &[key, value] : freq)
            {
                this->src[this->len++] = key;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::reverse()
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len / 2; i++)
            {
                T c = this->src[i];
                this->src[i] = this->src[this->len - i - 1];
                this->src[this->len - i - 1] = c;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::sort()
    {
        if (this->src)
            std::sort(this->src, this->src + this->len, [](T c1, T c2)
                      { return c1 - c2; });
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::swap(sstring_t_view<T> &__x) noexcept
    {
        T *temp = this->src;
        this->src = __x.src;
        __x.src = temp;

        std::size_t temp_len = this->len;
        this->len = __x.len;
        __x.len = temp_len;

        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::insert(const T *str, std::size_t index)
    {
        if (str && this->src && index <= this->len)
        {
            std::size_t str_len = this->sstr_strlen(str);
            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + str_len + 1)));
            exit_heap_fail(this->src);

            for (std::size_t i = this->len; i >= index; i--)
            {
                this->src[i + str_len] = this->src[i];
                this->src[i] = 0;
                if (i == 0)
                    break;
            }
            std::memmove(this->src + index, str, str_len * sizeof(T));
            this->len += str_len;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::insert(const sstring_t_view<T> &str, std::size_t index)
    {
        return this->insert(str.src, index);
    }
}

#endif