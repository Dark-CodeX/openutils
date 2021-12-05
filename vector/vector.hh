#ifdef __cplusplus

#pragma once

/**
 * This header file is written to create vectors in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/vector.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "vector.hh" under "vector" directory
 * vector version: 1.4.4
 * MIT License
 *
 * Copyright (c) 2021 Tushar Chaurasia
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <initializer_list>
#include <bits/functional_hash.h>
#include <bits/move.h>
#include <cstdlib>

#define vector_t_version "1.4.4"

template <typename T>
class vector_t
{
private:
    void resize();
    std::size_t len, cap;
    T *data;

public:
    vector_t();
    vector_t(T &&default_data, std::size_t capacity = 10);
    vector_t(const vector_t &vec);
    vector_t(vector_t &&other) noexcept;
    vector_t(std::initializer_list<T> __list);
    vector_t(const std::size_t capacity);
    const std::size_t length() const;
    const std::size_t capacity() const;
    void add(T &&data);
    bool insert(T &&data, const std::size_t nth);
    void remove();
    bool remove(const std::size_t nth);
    bool empty() const;
    const std::size_t hash() const;
    bool compare(const vector_t &vec) const;
    bool compare_hash(const vector_t &vec) const;
    void erase();
    void erase(T &&default_data, std::size_t capacity = 10);
    T &get(const std::size_t nth) const;
    bool set(T &&data, const std::size_t nth);
    void reverse();
    const std::size_t find(T &&data) const;
    bool swap(const std::size_t x1, const std::size_t x2);

    void operator=(const vector_t &data);
    T &operator[](const std::size_t nth) const;
    bool operator==(const vector_t &vec) const;
    bool operator!=(const vector_t &vec) const;
    vector_t &operator=(const vector_t &&__s) noexcept;
    void operator+=(const vector_t &data);
    void operator+=(T &&data);
    void operator+=(std::initializer_list<T> __list);
    const std::size_t nerr = (std::size_t)-1;

    bool unsafe_set(std::size_t where, T &&data);
    bool unsafe_remove(std::size_t where);
    std::size_t unsafe_resize(std::size_t new_size);
    T &unsafe_get(std::size_t where) const;
    void unsafe_delete(std::size_t where, bool delete_array = false);
    void unsafe_free(std::size_t where);
    ~vector_t();
};

template <typename T>
vector_t<T>::vector_t()
{
    this->cap = 10;
    this->data = new T[this->cap];
}

template <typename T>
vector_t<T>::vector_t(T &&default_data, std::size_t capacity)
{
    this->cap = capacity;
    this->data = new T[this->cap];
    for (std::size_t i = 0; i < this->cap; i++)
    {
        this->data[i] = default_data;
        this->len++;
    }
}

template <typename T>
vector_t<T>::vector_t(const vector_t &vec)
{
    this->len = vec.len;
    this->cap = vec.cap;
    this->data = new T[this->cap];
    for (std::size_t i = 0; i < vec.len; i++)
        this->data[i] = vec.data[i];
}

template <typename T>
vector_t<T>::vector_t(vector_t &&other) noexcept : len(0), cap(0), data(nullptr)
{
    data = other.data;
    len = other.len;
    cap = other.cap;
    other.data = nullptr;
    other.len = 0;
    other.cap = 10;
}

template <typename T>
vector_t<T>::vector_t(std::initializer_list<T> __list)
{
    this->len = 0;
    this->cap = __list.size();
    this->data = new T[this->cap];
    for (auto i = __list.begin(); i != __list.end(); i++, this->len++)
        this->data[this->len] = *i;
}

template <typename T>
vector_t<T>::vector_t(const std::size_t capacity)
{
    this->cap = capacity;
    this->data = new T[this->cap];
}

template <typename T>
void vector_t<T>::resize()
{
    T *temp = new T[this->cap * 3];
    for (std::size_t i = 0; i < this->cap; i++)
        temp[i] = this->data[i];
    delete[] this->data;
    this->cap *= 3;
    this->data = temp;
}

template <typename T>
const std::size_t vector_t<T>::length() const { return this->len; }

template <typename T>
const std::size_t vector_t<T>::capacity() const { return this->cap; }

template <typename T>
void vector_t<T>::add(T &&data)
{
    if (this->len == this->cap)
        this->resize();
    this->data[this->len++] = data;
}

template <typename T>
bool vector_t<T>::insert(T &&data, const std::size_t nth)
{
    if (nth <= this->len)
    {
        if (this->len == this->cap)
            this->resize();
        static T __t[1] = {};
        for (std::size_t i = this->len; i >= nth; i--)
        {
            this->data[i + 1] = this->data[i];
            this->data[i] = __t[0];
            if (i == 0)
                break;
        }
        this->data[nth] = data;
        this->len++;
        return true;
    }
    return false;
}

template <typename T>
void vector_t<T>::remove()
{
    static T __t[1] = {};
    this->data[this->len--] = __t[0];
}

template <typename T>
bool vector_t<T>::remove(const std::size_t nth)
{
    if (nth < this->len)
    {
        static T __t[1] = {};
        this->data[nth] = __t[0];
        for (std::size_t i = nth; i < this->len - 1; i++)
        {
            this->data[i] = this->data[i + 1];
            this->data[i + 1] = __t[0];
        }
        this->len--;
        return true;
    }
    return false;
}

template <typename T>
bool vector_t<T>::empty() const
{
    return (this->len == 0);
}

template <typename T>
inline void hash_combine(std::size_t &seed, const T &v)
{
    seed ^= std::hash<T>()(v) + static_cast<std::size_t>(0xc70f6907UL) + (seed << 7) + (seed >> 3);
}

template <typename T>
const std::size_t vector_t<T>::hash() const
{
    std::size_t h = 0;
    for (std::size_t i = 0; i < this->len; i++)
        hash_combine(h, this->data[i]);
    return h;
}

template <typename T>
bool vector_t<T>::compare(const vector_t &vec) const
{
    if (this->len != vec.len)
        return false;
    for (std::size_t i = 0; i < this->len; i++)
        if (this->data[i] != vec.data[i])
            return false;
    return true;
}

template <typename T>
bool vector_t<T>::compare_hash(const vector_t &vec) const
{
    return (this->hash() == vec.hash());
}

template <typename T>
void vector_t<T>::erase()
{
    delete[] this->data;
    this->cap = 10;
    this->len = 0;
    this->data = new T[this->cap];
}

template <typename T>
void vector_t<T>::erase(T &&default_data, std::size_t capacity)
{
    delete[] this->data;
    this->cap = capacity;
    this->len = 0;
    this->data = new T[this->cap];

    for (std::size_t i = 0; i < this->cap; i++)
    {
        this->data[i] = default_data;
        this->len++;
    }
}

template <typename T>
T &vector_t<T>::get(const std::size_t nth) const
{
    if (nth < this->len)
        return this->data[nth];
    static T __t[1] = {};
    return (T &)__t[0];
}

template <typename T>
bool vector_t<T>::set(T &&data, const std::size_t nth)
{
    if (nth < this->len)
    {
        this->data[nth] = data;
        return true;
    }
    return false;
}

template <typename T>
void vector_t<T>::reverse()
{
    T c;
    for (std::size_t i = 0; i < this->len / 2; i++)
    {
        c = this->data[i];
        this->data[i] = this->data[this->len - i - 1];
        this->data[this->len - i - 1] = c;
    }
}

template <typename T>
const std::size_t vector_t<T>::find(T &&data) const
{
    for (std::size_t i = 0; i < this->len; i++)
        if (this->data[i] == data)
            return i;
    return (std::size_t)-1;
}

template <typename T>
bool vector_t<T>::swap(const std::size_t x1, const std::size_t x2)
{
    if (x1 < this->len && x2 < this->len)
    {
        T x = T((T &&) this->data[x1]);
        this->data[x1] = this->data[x2];
        this->data[x2] = x;
        return true;
    }
    return false;
}

template <typename T>
void vector_t<T>::operator=(const vector_t &data)
{
    delete[] this->data;
    this->len = data.len;
    this->cap = data.cap;
    this->data = new T[data.cap];
    for (std::size_t i = 0; i < data.len; i++)
        this->data[i] = data.data[i];
}

template <typename T>
T &vector_t<T>::operator[](const std::size_t nth) const
{
    if (nth < this->len)
        return this->data[nth];
    static T __t[1] = {};
    return (T &)__t[0];
}

template <typename T>
bool vector_t<T>::operator==(const vector_t &vec) const
{
    return this->compare(vec);
}

template <typename T>
bool vector_t<T>::operator!=(const vector_t &vec) const
{
    return !(*this == vec);
}

template <typename T>
vector_t<T> &vector_t<T>::operator=(const vector_t &&__s) noexcept
{
    if (this != &__s)
    {
        delete[] this->data;
        this->len = __s.len;
        this->cap = __s.cap;
        this->data = new T[this->cap];
        for (std::size_t i = 0; i < __s.len; i++)
            this->data[i] = __s.data[i];
    }
    return *this;
}

template <typename T>
void vector_t<T>::operator+=(const vector_t &data)
{
    for (std::size_t i = 0; i < data.len; i++)
        this->add(std::move(data.data[i]));
}

template <typename T>
void vector_t<T>::operator+=(T &&data)
{
    this->add(std::move(data));
}

template <typename T>
void vector_t<T>::operator+=(std::initializer_list<T> __list)
{
    for (auto &i : __list)
        this->add(std::move((T &&) i));
}

template <typename T>
bool vector_t<T>::unsafe_set(std::size_t where, T &&data)
{
    if (where >= this->cap)
        return false;
    this->data[where] = data;
    return true;
}

template <typename T>
bool vector_t<T>::unsafe_remove(std::size_t where)
{
    if (where >= this->cap)
        return false;
    static T __t[1] = {};
    this->data[where] = __t[0];
    return true;
}

template <typename T>
std::size_t vector_t<T>::unsafe_resize(std::size_t new_size)
{
    if (new_size <= this->cap)
        return (std::size_t)-1;
    T *temp = new T[new_size];
    for (std::size_t i = 0; i < this->cap; i++)
        temp[i] = this->data[i];
    delete[] this->data;
    this->data = temp;
    this->cap = new_size;
    return this->cap;
}

template <typename T>
T &vector_t<T>::unsafe_get(std::size_t where) const
{
    if (where >= this->cap)
    {
        static T __t[1] = {};
        return (T &)__t[0];
    }
    return this->data[where];
}

template <typename T>
void vector_t<T>::unsafe_delete(std::size_t where, bool delete_array)
{
    if (where >= this->cap)
        return;
    if (delete_array == true)
        delete[] this->data[where];
    else
        delete this->data[where];
}

template <typename T>
void vector_t<T>::unsafe_free(std::size_t where)
{
    if (where >= this->cap)
        return;
    std::free(this->data[where]);
}

template <typename T>
vector_t<T>::~vector_t()
{
    this->len = 0;
    this->cap = 0;
    delete[] this->data;
}

namespace std
{
    template <typename T>
    struct hash<vector_t<T>>
    {
        std::size_t operator()(const vector_t<T> &vec) const
        {
            return vec.hash();
        }
    };
};
#endif