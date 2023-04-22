/**
 * This header file is written to manage array under C++ programming language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/array.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "array.hh" under "array" directory
 * array: version 2.0.0
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, Tushar Chaurasia
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef __cplusplus

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
        array_t(std::initializer_list<T> __list);
        const std::size_t &length() const;
        std::size_t capacity() const;
        array_t &add(const T &data);
        array_t &add(T &&data);
        array_t &remove();
        array_t &remove(std::size_t nth);
        bool is_empty() const;
        std::size_t hash() const;
        bool compare(const array_t &vec) const;
        bool compare_hash(const array_t &vec) const;
        const T &get(std::size_t nth) const;
        T &get(std::size_t nth);
        array_t &get_ref();
        array_t *get_ptr();
        array_t &set(const T &data, std::size_t nth);
        array_t &set(T &&data, std::size_t nth);
        array_t &reverse();
        std::size_t find(const T &data) const;
        std::size_t rfind(const T &data) const;
        array_t &swap(std::size_t x1, std::size_t x2);
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
        const T &operator[](std::size_t nth) const;
        T &operator[](std::size_t nth);
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
    array_t<T, cap>::array_t(std::initializer_list<T> __list)
    {
        if (cap < __list.size())
        {
            std::fprintf(stderr, "err: length exceeds capacity\n");
            std::exit(EXIT_FAILURE);
        }
        this->len = 0;
        for (auto &i : __list)
            this->add(i);
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
    array_t<T, cap> &array_t<T, cap>::remove(std::size_t nth)
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
    const T &array_t<T, cap>::get(std::size_t nth) const
    {
        if (nth < this->len)
            return this->arr[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T, std::size_t cap>
    T &array_t<T, cap>::get(std::size_t nth)
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
    array_t<T, cap> &array_t<T, cap>::set(const T &data, std::size_t nth)
    {
        if (nth < this->len)
            this->arr[nth] = data;
        return *this;
    }

    template <typename T, std::size_t cap>
    array_t<T, cap> &array_t<T, cap>::set(T &&data, std::size_t nth)
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
    array_t<T, cap> &array_t<T, cap>::swap(std::size_t x1, std::size_t x2)
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
    const T &array_t<T, cap>::operator[](std::size_t nth) const
    {
        if (nth < this->len)
            return this->arr[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T, std::size_t cap>
    T &array_t<T, cap>::operator[](std::size_t nth)
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
#endif