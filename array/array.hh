/**
 * @file array.hh
 * @brief This file contains declaration as well as definition of array_t class.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 2.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef ARRAY_DEFINED
#define ARRAY_DEFINED

#include <utility>
#include <initializer_list>
#include <functional>
#include <cstdio>

#define array_version "2.0.0"

namespace openutils
{
    /**
     * @brief NOTE: stores data on stack memory
     */
    template <typename T, std::size_t cap>
    class array_t
    {
    private:
        T arr[cap];
        std::size_t len;
        static inline void hash_combine(std::size_t &seed, const T &v);

    public:
        array_t();
        array_t(const array_t &ar);
        array_t(array_t &&ar) noexcept;
        array_t(const std::initializer_list<T> &__list);
        array_t(std::initializer_list<T> &&__list);
        const std::size_t &length() const;
        std::size_t capacity() const;
        array_t &add(const T &data);
        array_t &add(T &&data);
        array_t &remove();
        array_t &remove(const std::size_t &nth);
        bool is_empty() const;
        std::size_t hash() const;
        bool compare(const array_t &vec) const;
        bool compare_hash(const array_t &vec) const;
        const T &get(const std::size_t &nth) const;
        T &get(const std::size_t &nth);
        array_t &get_ref();
        array_t *get_ptr();
        array_t &set(const T &data, const std::size_t &nth);
        array_t &set(T &&data, const std::size_t &nth);
        array_t &reverse();
        std::size_t find(const T &data) const;
        std::size_t rfind(const T &data) const;
        array_t &swap(const std::size_t &x1, const std::size_t &x2);
        array_t &swap(array_t &vec) noexcept;
        const T *raw_data() const;
        T *raw_data();
        const T *cbegin() const;
        const T *cend() const;
        T *begin();
        T *end();
        const T *crbegin() const;
        const T *crend() const;
        T *rbegin();
        T *rend();
        template <typename comp>
        array_t &sort(comp c);
        const T &operator[](const std::size_t &nth) const;
        T &operator[](const std::size_t &nth);
        array_t &operator=(const array_t &data);
        array_t &operator=(array_t &&__s) noexcept;
        bool operator==(const array_t &vec) const;
        bool operator!=(const array_t &vec) const;
        constexpr inline std::size_t nerr() const noexcept;
        ~array_t();
    };

    template <typename T, std::size_t cap>
    inline void array_t<T, cap>::hash_combine(std::size_t &seed, const T &v)
    {
        seed ^= std::hash<T>()(v) + static_cast<std::size_t>(0xc70f6907UL) + (seed << 7) + (seed >> 3);
    }

    template <typename T, std::size_t cap>
    array_t<T, cap>::array_t()
    {
        this->len = 0;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap>::array_t(const array_t &ar)
    {
        this->len = 0;
        for (std::size_t i = 0; i < ar.len; i++)
            this->arr[this->len++] = ar.arr[i];
    }

    template <typename T, std::size_t cap>
    array_t<T, cap>::array_t(array_t &&ar) noexcept
    {
        this->len = ar.len;
        std::move(ar.arr, ar.arr + ar.len, this->arr);

        ar.len = 0;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap>::array_t(const std::initializer_list<T> &__list)
    {
        if (cap < __list.size())
        {
            std::fprintf(stderr, "err: length exceeds capacity\n");
            std::exit(EXIT_FAILURE);
        }
        this->len = 0;
        for (const auto &i : __list)
            this->add(i);
    }

    template <typename T, std::size_t cap>
    array_t<T, cap>::array_t(std::initializer_list<T> &&__list)
    {
        if (cap < __list.size())
        {
            std::fprintf(stderr, "err: length exceeds capacity\n");
            std::exit(EXIT_FAILURE);
        }
        this->len = 0;
        for (auto &&i : __list)
            this->add(std::move(i));
    }

    template <typename T, std::size_t cap>
    const std::size_t &array_t<T, cap>::length() const
    {
        return this->len;
    }

    template <typename T, std::size_t cap>
    std::size_t array_t<T, cap>::capacity() const
    {
        return cap;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::add(const T &data)
    {
        if (cap == this->len)
        {
            std::fprintf(stderr, "err: length exceeds capacity\n");
            std::exit(EXIT_FAILURE);
        }
        this->arr[this->len++] = data;
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::add(T &&data)
    {
        if (cap == this->len)
        {
            std::fprintf(stderr, "err: length exceeds capacity\n");
            std::exit(EXIT_FAILURE);
        }
        this->arr[this->len++] = std::move(data);
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::remove()
    {
        if (this->len != 0)
            this->arr[--this->len].~T();
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::remove(const std::size_t &nth)
    {
        if (this->len == 0 || this->len <= nth)
            return *this;
        this->arr[nth].~T();
        for (std::size_t i = nth; i < this->len - 1; i++)
        {
            this->arr[i] = std::move(this->arr[i + 1]);
        }
        this->len--;
        return *this;
    }

    template <typename T, std::size_t cap>
    bool array_t<T, cap>::is_empty() const
    {
        return this->len == 0;
    }

    template <typename T, std::size_t cap>
    std::size_t array_t<T, cap>::hash() const
    {
        if (this->len == 0)
            return 0;
        std::size_t h = 0;
        for (std::size_t i = 0; i < this->len; i++)
            this->hash_combine(h, this->arr[i]);
        return h;
    }

    template <typename T, std::size_t cap>
    bool array_t<T, cap>::compare(const array_t &vec) const
    {
        if (this->len != vec.len)
            return false;
        for (std::size_t i = 0; i < this->len; i++)
            if (this->arr[i] != vec.arr[i])
                return false;
        return true;
    }

    template <typename T, std::size_t cap>
    bool array_t<T, cap>::compare_hash(const array_t &vec) const
    {
        return this->hash() == vec.hash();
    }

    template <typename T, std::size_t cap>
    const T &array_t<T, cap>::get(const std::size_t &nth) const
    {
        if (nth < this->len)
            return this->arr[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T, std::size_t cap>
    T &array_t<T, cap>::get(const std::size_t &nth)
    {
        if (nth < this->len)
            return this->arr[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::get_ref()
    {
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> *array_t<T, cap>::get_ptr()
    {
        return this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::set(const T &data, const std::size_t &nth)
    {
        if (nth < this->len)
            this->arr[nth] = data;
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::set(T &&data, const std::size_t &nth)
    {
        if (nth < this->len)
            this->arr[nth] = std::move(data);
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::reverse()
    {
        if (this->len == 0 || this->len == 1)
            return *this;
        for (std::size_t i = 0; i < this->len / 2; i++)
        {
            T c = std::move(this->arr[i]);
            this->arr[i] = std::move(this->arr[this->len - i - 1]);
            this->arr[this->len - i - 1] = std::move(c);
        }
        return *this;
    }

    template <typename T, std::size_t cap>
    std::size_t array_t<T, cap>::find(const T &data) const
    {
        for (std::size_t i = 0; i < this->len; i++)
        {
            if (this->arr[i] == data)
                return i;
        }
        return this->nerr();
    }

    template <typename T, std::size_t cap>
    std::size_t array_t<T, cap>::rfind(const T &data) const
    {
        for (std::size_t i = this->len; i != this->nerr(); i--)
        {
            if (this->arr[i] == data)
                return i;
        }
        return this->nerr();
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::swap(const std::size_t &x1, const std::size_t &x2)
    {
        if (x1 < this->len && x2 < this->len)
        {
            T temp = std::move(this->arr[x1]);
            this->arr[x1] = std::move(this->arr[x2]);
            this->arr[x2] = std::move(temp);
        }
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::swap(array_t &vec) noexcept
    {
        std::swap(this->arr, vec.arr);
        std::swap(this->len, vec.len);
        return *this;
    }

    template <typename T, std::size_t cap>
    const T *array_t<T, cap>::raw_data() const
    {
        return this->arr;
    }

    template <typename T, std::size_t cap>
    T *array_t<T, cap>::raw_data()
    {
        return this->arr;
    }

    template <typename T, std::size_t cap>
    const T *array_t<T, cap>::cbegin() const
    {
        if (this->arr)
            return this->arr;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    const T *array_t<T, cap>::cend() const
    {
        if (this->arr)
            return this->arr + this->len;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    T *array_t<T, cap>::begin()
    {
        if (this->arr)
            return this->arr;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    T *array_t<T, cap>::end()
    {
        if (this->arr)
            return this->arr + this->len;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    const T *array_t<T, cap>::crbegin() const
    {
        if (this->arr)
            return this->arr + this->len;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    const T *array_t<T, cap>::crend() const
    {
        if (this->arr)
            return this->arr;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    T *array_t<T, cap>::rbegin()
    {
        if (this->arr)
            return this->arr + this->len;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    T *array_t<T, cap>::rend()
    {
        if (this->arr)
            return this->arr;
        return nullptr;
    }

    template <typename T, std::size_t cap>
    template <typename comp>
    array_t<T, cap> &array_t<T, cap>::sort(comp c)
    {
        std::sort(this->arr, this->arr + this->len, c);
        return *this;
    }

    template <typename T, std::size_t cap>
    const T &array_t<T, cap>::operator[](const std::size_t &nth) const
    {
        if (nth < this->len)
            return this->arr[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T, std::size_t cap>
    T &array_t<T, cap>::operator[](const std::size_t &nth)
    {
        if (nth < this->len)
            return this->arr[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::operator=(const array_t &data)
    {
        if (this != &data)
        {
            this->len = 0;
            for (std::size_t i = 0; i < data.len; i++)
                this->arr[this->len++] = data.arr[i];
        }

        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::operator=(array_t &&__s) noexcept
    {
        if (this != &__s)
        {
            this->len = __s.len;
            std::move(__s.arr, __s.arr + __s.len, this->arr);

            __s.len = 0;
        }
        return *this;
    }

    template <typename T, std::size_t cap>
    bool array_t<T, cap>::operator==(const array_t &vec) const
    {
        return this->compare(vec);
    }

    template <typename T, std::size_t cap>
    bool array_t<T, cap>::operator!=(const array_t &vec) const
    {
        return !this->compare(vec);
    }

    template <typename T, std::size_t cap>
    constexpr inline std::size_t array_t<T, cap>::nerr() const noexcept
    {
        return static_cast<std::size_t>(-1);
    }

    template <typename T, std::size_t cap>
    array_t<T, cap>::~array_t() = default;
};

#endif