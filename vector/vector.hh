/**
 * This header file is written to create vectors in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/vector.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "vector.hh" under "vector" directory
 * vector version: 2.0.0
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

#ifndef VECTOR_DEFINED
#define VECTOR_DEFINED

#include <utility>
#include <initializer_list>
#include <functional>
#include <cstdio>

#define vector_t_version "2.0.0"

namespace openutils
{
#ifndef EXIT_HEAP_FAIL
#define EXIT_HEAP_FAIL
    static inline void exit_heap_fail(const void *ptr)
    {
        if (!ptr)
        {
            std::fprintf(stderr, "err: can't allocate heap memory.\n");
            std::exit(EXIT_FAILURE);
        }
    }
#endif

    template <typename T>
    class vector_t
    {
      private:
        inline void init(std::size_t max);
        inline void resize();
        static inline void hash_combine(std::size_t &seed, const T &v);
        T *vec_data;
        std::size_t len, cap;

      public:
        vector_t();
        vector_t(T *ptr, std::size_t max_len, bool is_ptr_heap_allocated = false);
        vector_t(T *ptr_begin, T *ptr_end);
        vector_t(const vector_t &vec);
        vector_t(vector_t &&other) noexcept;
        vector_t(std::initializer_list<T> __list);
        vector_t(std::size_t max_capacity);
        const std::size_t &length() const;
        const std::size_t &capacity() const;
        vector_t &add(const T &data);
        vector_t &add(T &&data);
        vector_t &remove();
        vector_t &remove(std::size_t nth);
        bool is_empty() const;
        bool is_null() const;
        vector_t &insert(const T &data, std::size_t nth);
        vector_t &insert(T &&data, std::size_t nth);
        std::size_t hash() const;
        bool compare(const vector_t &vec) const;
        bool compare_hash(const vector_t &vec) const;
        vector_t &erase();
        const T &get(std::size_t nth) const;
        T &get(std::size_t nth);
        vector_t &get_ref();
        vector_t *get_ptr();
        vector_t &set(const T &data, std::size_t nth);
        vector_t &set(T &&data, std::size_t nth);
        vector_t &reverse();
        std::size_t find(const T &data) const;
        std::size_t rfind(const T &data) const;
        vector_t &swap(std::size_t x1, std::size_t x2);
        vector_t &swap(vector_t &vec) noexcept;
        const T *raw_data() const;
        T *&raw_data();
        const T *cbegin() const;
        const T *cend() const;
        T *begin();
        T *end();
        const T *crbegin() const;
        const T *crend() const;
        T *rbegin();
        T *rend();
        vector_t &shrink_to_fit();
        template <typename comp>
        vector_t &sort(comp c);
        const T &operator[](std::size_t nth) const;
        T &operator[](std::size_t nth);
        vector_t &operator=(const vector_t &data);
        vector_t &operator=(vector_t &&__s) noexcept;
        bool operator!=(const vector_t &vec) const;
        bool operator==(const vector_t &vec) const;
        vector_t &operator+=(T &&data);
        vector_t &operator+=(const T &data);
        vector_t &operator+=(std::initializer_list<T> __list);
        constexpr inline std::size_t nerr() const noexcept;
        ~vector_t();
    };

    template <typename T>
    inline void vector_t<T>::init(std::size_t max)
    {
        this->vec_data = new T[max]();
        exit_heap_fail(this->vec_data);
        this->cap = max;
        this->len = 0;
    }

    template <typename T>
    inline void vector_t<T>::resize()
    {
        this->cap *= 2;
        T *temp = new T[this->cap]();
        exit_heap_fail(temp);
        for (std::size_t i = 0; i < this->len; i++)
            temp[i] = std::move(this->vec_data[i]);
        delete[] this->vec_data;
        this->vec_data = temp;
    }

    template <typename T>
    inline void vector_t<T>::hash_combine(std::size_t &seed, const T &v)
    {
        seed ^= std::hash<T>()(v) + static_cast<std::size_t>(0xc70f6907UL) + (seed << 7) + (seed >> 3);
    }

    template <typename T>
    vector_t<T>::vector_t()
    {
        this->len = 0;
        this->cap = 0;
        this->vec_data = nullptr;
    }

    template <typename T>
    vector_t<T>::vector_t(T *ptr, std::size_t max_len, bool is_ptr_heap_allocated)
    {
        if (ptr && max_len != 0)
        {
            if (is_ptr_heap_allocated)
            {
                this->vec_data = ptr;
                this->cap = max_len;
                this->len = max_len;
            }
            else
            {
                this->init(max_len);
                for (std::size_t i = 0; i < max_len; i++)
                    this->add(ptr[i]);
            }
        }
        else
        {
            this->len = 0;
            this->cap = 0;
            this->vec_data = nullptr;
        }
    }

    template <typename T>
    vector_t<T>::vector_t(T *ptr_begin, T *ptr_end)
    {
        if (ptr_begin && ptr_end)
        {
            this->init(10);
            for (const T *i = ptr_begin; i != ptr_end; i++)
                this->add(*i);
        }
        else
        {
            this->len = 0;
            this->cap = 0;
            this->vec_data = nullptr;
        }
    }

    template <typename T>
    vector_t<T>::vector_t(const vector_t &vec)
    {
        if (vec.vec_data)
        {
            this->init(vec.cap);
            for (std::size_t i = 0; i < vec.len; i++)
                this->add(vec.vec_data[i]);
        }
        else
        {
            this->len = 0;
            this->cap = 0;
            this->vec_data = nullptr;
        }
    }

    template <typename T>
    vector_t<T>::vector_t(vector_t &&other) noexcept
    {
        this->vec_data = other.vec_data;
        this->len = other.len;
        this->cap = other.cap;

        other.vec_data = nullptr;
        other.len = 0;
        other.cap = 0;
    }

    template <typename T>
    vector_t<T>::vector_t(std::initializer_list<T> __list)
    {
        this->init(__list.size());
        for (auto i = __list.begin(); i != __list.end(); i++)
            this->add(*i);
    }

    template <typename T>
    vector_t<T>::vector_t(std::size_t max_capacity)
    {
        this->init(max_capacity);
    }

    template <typename T>
    const std::size_t &vector_t<T>::length() const
    {
        return this->len;
    }

    template <typename T>
    const std::size_t &vector_t<T>::capacity() const
    {
        return this->cap;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::add(const T &data)
    {
        if (!this->vec_data)
            this->init(10);
        if (this->len == this->cap)
            this->resize();
        this->vec_data[this->len++] = data;
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::add(T &&data)
    {
        if (!this->vec_data)
            this->init(10);
        if (this->len == this->cap)
            this->resize();
        this->vec_data[this->len++] = std::move(data);
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::remove()
    {
        if (!this->vec_data || this->len == 0)
            return *this;
        this->vec_data[--this->len].~T();
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::remove(std::size_t nth)
    {
        if (!this->vec_data || this->len == 0 || this->len <= nth)
            return *this;
        this->vec_data[nth].~T();
        for (std::size_t i = nth; i < this->len - 1; i++)
        {
            this->vec_data[i] = std::move(this->vec_data[i + 1]);
        }
        this->len--;
        return *this;
    }

    template <typename T>
    bool vector_t<T>::is_empty() const
    {
        return (this->len == 0);
    }

    template <typename T>
    bool vector_t<T>::is_null() const
    {
        return (this->vec_data == nullptr);
    }

    template <typename T>
    vector_t<T> &vector_t<T>::insert(const T &data, std::size_t nth)
    {
        if (!this->vec_data)
            return *this;
        if (nth == this->len || this->len == 0)
            return this->add(data);
        if (this->len == this->cap)
            this->resize();

        for (std::size_t i = this->len; i > nth; i--)
        {
            this->vec_data[i] = std::move(this->vec_data[i - 1]);
        }
        this->vec_data[nth] = data;
        this->len++;
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::insert(T &&data, std::size_t nth)
    {
        if (!this->vec_data)
            return *this;
        if (nth == this->len || this->len == 0)
            return this->add(data);
        if (this->len == this->cap)
            this->resize();

        for (std::size_t i = this->len; i > nth; i--)
        {
            this->vec_data[i] = std::move(this->vec_data[i - 1]);
        }
        this->vec_data[nth] = std::move(data);
        this->len++;
        return *this;
    }

    template <typename T>
    std::size_t vector_t<T>::hash() const
    {
        if (!this->vec_data || this->len == 0)
            return 0;
        std::size_t h = 0;
        for (std::size_t i = 0; i < this->len; i++)
            this->hash_combine(h, this->vec_data[i]);
        return h;
    }

    template <typename T>
    bool vector_t<T>::compare(const vector_t &vec) const
    {
        if (!this->vec_data || !vec.vec_data)
            return false;
        if (this->len != vec.len)
            return false;
        for (std::size_t i = 0; i < this->len; i++)
            if (this->vec_data[i] != vec.vec_data[i])
                return false;
        return true;
    }

    template <typename T>
    bool vector_t<T>::compare_hash(const vector_t &vec) const
    {
        return this->hash() == vec.hash();
    }

    template <typename T>
    vector_t<T> &vector_t<T>::erase()
    {
        if (this->vec_data)
            delete[] this->vec_data;
        this->vec_data = nullptr;
        this->len = 0;
        this->cap = 0;
        return *this;
    }

    template <typename T>
    const T &vector_t<T>::get(std::size_t nth) const
    {
        if (nth < this->len && this->vec_data)
            return this->vec_data[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T>
    T &vector_t<T>::get(std::size_t nth)
    {
        if (nth < this->len && this->vec_data)
            return this->vec_data[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T>
    vector_t<T> &vector_t<T>::get_ref()
    {
        return *this;
    }

    template <typename T>
    vector_t<T> *vector_t<T>::get_ptr()
    {
        return this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::set(const T &data, std::size_t nth)
    {
        if (nth < this->len && this->vec_data)
            this->vec_data[nth] = data;
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::set(T &&data, std::size_t nth)
    {
        if (nth < this->len && this->vec_data)
            this->vec_data[nth] = std::move(data);
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::reverse()
    {
        if (!this->vec_data || this->len == 0 || this->len == 1)
            return *this;
        for (std::size_t i = 0; i < this->len / 2; i++)
        {
            T c = std::move(this->vec_data[i]);
            this->vec_data[i] = std::move(this->vec_data[this->len - i - 1]);
            this->vec_data[this->len - i - 1] = std::move(c);
        }
        return *this;
    }

    template <typename T>
    std::size_t vector_t<T>::find(const T &data) const
    {
        if (this->vec_data)
        {
            for (std::size_t i = 0; i < this->len; i++)
            {
                if (this->vec_data[i] == data)
                    return i;
            }
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t vector_t<T>::rfind(const T &data) const
    {
        if (this->vec_data)
        {
            for (std::size_t i = this->len; i != this->nerr(); i--)
            {
                if (this->vec_data[i] == data)
                    return i;
            }
        }
        return this->nerr();
    }

    template <typename T>
    vector_t<T> &vector_t<T>::swap(std::size_t x1, std::size_t x2)
    {
        if (x1 < this->len && x2 < this->len && this->vec_data)
        {
            T temp = std::move(this->vec_data[x1]);
            this->vec_data[x1] = std::move(this->vec_data[x2]);
            this->vec_data[x2] = std::move(temp);
        }
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::swap(vector_t &vec) noexcept
    {
        T *temp = this->vec_data;
        this->vec_data = vec.vec_data;
        vec.vec_data = temp;
        std::swap(this->len, vec.len);
        std::swap(this->cap, vec.cap);
        return *this;
    }

    template <typename T>
    const T *vector_t<T>::raw_data() const
    {
        return this->vec_data;
    }

    template <typename T>
    T *&vector_t<T>::raw_data()
    {
        return this->vec_data;
    }

    template <typename T>
    const T *vector_t<T>::cbegin() const
    {
        if (this->vec_data)
            return this->vec_data;
        return nullptr;
    }

    template <typename T>
    const T *vector_t<T>::cend() const
    {
        if (this->vec_data)
            return this->vec_data + this->len;
        return nullptr;
    }

    template <typename T>
    T *vector_t<T>::begin()
    {
        if (this->vec_data)
            return this->vec_data;
        return nullptr;
    }

    template <typename T>
    T *vector_t<T>::end()
    {
        if (this->vec_data)
            return this->vec_data + this->len;
        return nullptr;
    }

    template <typename T>
    const T *vector_t<T>::crbegin() const
    {
        if (this->vec_data)
            return this->vec_data + this->len;
        return nullptr;
    }

    template <typename T>
    const T *vector_t<T>::crend() const
    {
        if (this->vec_data)
            return this->vec_data;
        return nullptr;
    }

    template <typename T>
    T *vector_t<T>::rbegin()
    {
        if (this->vec_data)
            return this->vec_data + this->len;
        return nullptr;
    }

    template <typename T>
    T *vector_t<T>::rend()
    {
        if (this->vec_data)
            return this->vec_data;
        return nullptr;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::shrink_to_fit()
    {
        if (!this->vec_data)
            return *this;
        T *temp = new T[this->len]();
        exit_heap_fail(temp);
        for (std::size_t i = 0; i < this->len; i++)
            temp[i] = std::move(this->vec_data[i]);
        this->cap = this->len;
        delete[] this->vec_data;
        this->vec_data = temp;
    }

    template <typename T>
    template <typename comp>
    vector_t<T> &vector_t<T>::sort(comp c)
    {
        std::sort(this->vec_data, this->vec_data + this->len, c);
        return *this;
    }

    template <typename T>
    const T &vector_t<T>::operator[](std::size_t nth) const
    {
        if (nth < this->len && this->vec_data)
            return this->vec_data[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T>
    T &vector_t<T>::operator[](std::size_t nth)
    {
        if (nth < this->len && this->vec_data)
            return this->vec_data[nth];
        std::fprintf(stderr, "err: out-of-range\n");
        std::exit(EXIT_FAILURE);
    }

    template <typename T>
    vector_t<T> &vector_t<T>::operator=(const vector_t &data)
    {
        if (this != &data)
        {
            if (this->vec_data)
                delete[] this->vec_data;
            this->len = data.len;
            this->cap = data.cap;
            this->init(this->cap);
            for (std::size_t i = 0; i < data.len; i++)
                this->vec_data[i] = data.vec_data[i];
        }
        return *this;
    }

    template <typename T>
    vector_t<T> &vector_t<T>::operator=(vector_t &&__s) noexcept
    {
        if (this != &__s)
        {
            if (this->vec_data)
                delete[] this->vec_data;
            this->vec_data = __s.vec_data;
            this->cap = __s.cap;
            this->len = __s.len;

            __s.vec_data = nullptr;
            __s.len = 0;
            __s.cap = 0;
        }
        return *this;
    }

    template <typename T>
    bool vector_t<T>::operator==(const vector_t &vec) const
    {
        return this->compare(vec);
    }

    template <typename T>
    bool vector_t<T>::operator!=(const vector_t &vec) const
    {
        return !this->compare(vec);
    }

    template <typename T>
    vector_t<T> &vector_t<T>::operator+=(T &&data)
    {
        return this->add(data);
    }

    template <typename T>
    vector_t<T> &vector_t<T>::operator+=(const T &data)
    {
        return this->add(data);
    }

    template <typename T>
    vector_t<T> &vector_t<T>::operator+=(std::initializer_list<T> __list)
    {
        for (auto i = __list.begin(); i != __list.end(); i++)
            this->add(*i);
        return *this;
    }

    template <typename T>
    constexpr inline std::size_t vector_t<T>::nerr() const noexcept
    {
        return static_cast<std::size_t>(-1);
    }

    template <typename T>
    vector_t<T>::~vector_t()
    {
        if (this->vec_data)
            delete[] this->vec_data;
        this->vec_data = nullptr;
        this->len = 0;
        this->cap = 0;
    }
}

namespace std
{
    template <typename T>
    struct hash<openutils::vector_t<T>>
    {
        std::size_t operator()(const openutils::vector_t<T> &vec) const
        {
            return vec.hash();
        }
    };
};

#endif