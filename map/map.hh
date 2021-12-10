/**
 * This header file is written to create maps in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/map.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "map.hh" under "map" directory
 * map version: 1.0.5
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

#ifdef __cplusplus

#pragma once

#ifdef _WIN32 || defined _WIN64 || defined __CYGWIN__
#include <utility>
#include <functional>
#else
#include <bits/functional_hash.h>
#include <bits/move.h>
#include <bits/stl_pair.h>
#endif

#include <initializer_list>

template <typename KEY, typename VALUE>
struct node_t
{
    KEY key;
    VALUE value;
    node_t *next;
    node_t() : next(nullptr) {}
    node_t(KEY &&key, VALUE &&value) : key(std::move(key)), value(std::move(value)), next(nullptr) {}
};

template <typename KEY, typename VALUE>
class iter_map_t;

template <typename KEY, typename VALUE>
class map_t
{
private:
    std::size_t cap, len;
    float load_factor = 0.75f;
    std::size_t get_hash(const KEY &key, std::size_t c) const;
    bool equal(const KEY &key1, const KEY &key2) const;
    void rehash();
    node_t<KEY, VALUE> **table;
    friend class iter_map_t<KEY, VALUE>;

public:
    map_t(std::size_t capacity = 16, float load_factor = 0.75f);
    map_t(const map_t &other);
    map_t(map_t &&other) noexcept;
    map_t(std::initializer_list<std::pair<KEY, VALUE>> list);
    map_t(float load_factor);
    bool add(KEY &&key, VALUE &&value);
    bool add(const KEY &key, const VALUE &value);
    bool remove(KEY &&key);
    bool remove(const KEY &key);
    bool contains(KEY &&key) const;
    bool contains(const KEY &key) const;
    const VALUE &get(KEY &&key) const;
    const VALUE &get(const KEY &key) const;
    const node_t<KEY, VALUE> *get_node(KEY &&key) const;
    const node_t<KEY, VALUE> *get_node(const KEY &key) const;
    void erase();
    bool empty() const;
    const std::size_t length() const;
    const std::size_t capacity() const;
    const long double error_rate(const std::size_t expected_size) const;
    typedef iter_map_t<KEY, VALUE> iter;
    iter iterator() const;
    const std::size_t hash() const;

    void operator=(const map_t &other);
    map_t &operator=(map_t &&other);
    VALUE &operator[](KEY &&key) const;
    VALUE &operator[](const KEY &key) const;
    bool operator==(const map_t &other) const;
    bool operator!=(const map_t &other) const;
    bool operator+=(std::pair<KEY, VALUE> pair);
    void operator+=(std::initializer_list<std::pair<KEY, VALUE>> list);
    void operator+=(const map_t &other);
    bool operator-=(KEY &&key);
    bool operator-=(const KEY &key);
    ~map_t();
};

template <typename KEY, typename VALUE>
map_t<KEY, VALUE>::map_t(std::size_t capacity, float load_factor)
{
    this->cap = capacity;
    this->table = new node_t<KEY, VALUE> *[this->cap];
    for (std::size_t i = 0; i < this->cap; i++)
        this->table[i] = nullptr;
    this->len = 0;
    this->load_factor = load_factor;
}

template <typename KEY, typename VALUE>
map_t<KEY, VALUE>::map_t(const map_t &other)
{
    this->cap = other.cap;
    this->table = new node_t<KEY, VALUE> *[this->cap];
    for (std::size_t i = 0; i < this->cap; i++)
        this->table[i] = nullptr;
    this->len = 0;
    this->load_factor = other.load_factor;
    for (std::size_t i = 0; i < this->cap; i++)
    {
        node_t<KEY, VALUE> *curr = other.table[i];
        while (curr != nullptr)
        {
            this->add(std::move(curr->key), std::move(curr->value));
            curr = curr->next;
        }
    }
}

template <typename KEY, typename VALUE>
map_t<KEY, VALUE>::map_t(map_t &&other) noexcept : cap(0), len(0), load_factor(0), table(nullptr)
{
    this->cap = other.cap;
    this->table = other.table;
    this->len = other.len;
    this->load_factor = other.load_factor;

    other.cap = 0;
    other.table = nullptr;
    other.len = 0;
    other.load_factor = 0;
}

template <typename KEY, typename VALUE>
map_t<KEY, VALUE>::map_t(std::initializer_list<std::pair<KEY, VALUE>> list)
{
    this->cap = list.size();
    this->table = new node_t<KEY, VALUE> *[this->cap];
    for (std::size_t i = 0; i < this->cap; i++)
        this->table[i] = nullptr;
    this->len = 0;
    this->load_factor = 0.75f;
    for (auto &pair : list)
        this->add(std::move((KEY &&) pair.first), std::move((VALUE &&) pair.second));
}

template <typename KEY, typename VALUE>
map_t<KEY, VALUE>::map_t(float load_factor)
{
    this->cap = 16;
    this->table = new node_t<KEY, VALUE> *[this->cap];
    for (std::size_t i = 0; i < this->cap; i++)
        this->table[i] = nullptr;
    this->len = 0;
    this->load_factor = load_factor;
}

template <typename KEY, typename VALUE>
std::size_t map_t<KEY, VALUE>::get_hash(const KEY &key, std::size_t c) const
{
    return std::hash<KEY>()(key) % c;
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::equal(const KEY &key1, const KEY &key2) const
{
    return key1 == key2;
}

template <typename KEY, typename VALUE>
void map_t<KEY, VALUE>::rehash()
{
    std::size_t new_cap = this->cap * 2;
    node_t<KEY, VALUE> **new_table = new node_t<KEY, VALUE> *[new_cap];
    for (std::size_t i = 0; i < new_cap; i++)
        new_table[i] = nullptr;
    for (std::size_t i = 0; i < this->cap; i++)
    {
        node_t<KEY, VALUE> *cur = this->table[i];
        while (cur != nullptr)
        {
            std::size_t hash = this->get_hash(cur->key, new_cap);
            node_t<KEY, VALUE> *next = cur->next;
            cur->next = new_table[hash];
            new_table[hash] = cur;
            cur = next;
        }
    }
    delete[] this->table;
    this->table = new_table;
    this->cap = new_cap;
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::add(KEY &&key, VALUE &&value)
{
    std::size_t hash = this->get_hash(key, this->cap);
    node_t<KEY, VALUE> *cur = this->table[hash];
    while (cur != nullptr)
    {
        if (this->equal(cur->key, key))
            return false;
        cur = cur->next;
    }
    node_t<KEY, VALUE> *new_node = new node_t<KEY, VALUE>(std::move(key), std::move(value));
    new_node->next = this->table[hash];
    this->table[hash] = new_node;
    this->len++;
    if (this->len >= this->cap * this->load_factor)
        this->rehash();
    return true;
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::add(const KEY &key, const VALUE &value)
{
    return this->add((KEY &&) key, (VALUE &&) value);
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::remove(KEY &&key)
{
    std::size_t hash = this->get_hash(key, this->cap);
    node_t<KEY, VALUE> *cur = this->table[hash];
    node_t<KEY, VALUE> *prev = nullptr;
    while (cur != nullptr)
    {
        if (this->equal(cur->key, key))
        {
            if (prev == nullptr)
                this->table[hash] = cur->next;
            else
                prev->next = cur->next;
            delete cur;
            this->len--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::remove(const KEY &key)
{
    return this->remove((KEY &&) key);
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::contains(KEY &&key) const
{
    std::size_t hash = this->get_hash(key, this->cap);
    node_t<KEY, VALUE> *cur = this->table[hash];
    while (cur != nullptr)
    {
        if (this->equal(cur->key, key))
            return true;
        cur = cur->next;
    }
    return false;
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::contains(const KEY &key) const
{
    return this->contains((KEY &&) key);
}

template <typename KEY, typename VALUE>
const VALUE &map_t<KEY, VALUE>::get(KEY &&key) const
{
    std::size_t hash = this->get_hash(key, this->cap);
    node_t<KEY, VALUE> *cur = this->table[hash];
    while (cur != nullptr)
    {
        if (this->equal(cur->key, key))
            return cur->value;
        cur = cur->next;
    }
    static VALUE __t[1] = {};
    return (VALUE &)__t[0];
}

template <typename KEY, typename VALUE>
const VALUE &map_t<KEY, VALUE>::get(const KEY &key) const
{
    return this->get((KEY &&) key);
}

template <typename KEY, typename VALUE>
const node_t<KEY, VALUE> *map_t<KEY, VALUE>::get_node(KEY &&key) const
{
    std::size_t hash = this->get_hash(key, this->cap);
    node_t<KEY, VALUE> *cur = this->table[hash];
    while (cur != nullptr)
    {
        if (this->equal(cur->key, key))
            return cur;
        cur = cur->next;
    }
    return nullptr;
}

template <typename KEY, typename VALUE>
const node_t<KEY, VALUE> *map_t<KEY, VALUE>::get_node(const KEY &key) const
{
    return this->get_node((KEY &&) key);
}

template <typename KEY, typename VALUE>
void map_t<KEY, VALUE>::erase()
{
    for (std::size_t i = 0; i < this->cap; i++)
    {
        node_t<KEY, VALUE> *cur = this->table[i];
        while (cur != nullptr)
        {
            node_t<KEY, VALUE> *next = cur->next;
            delete cur;
            cur = next;
        }
        this->table[i] = nullptr;
    }
    this->len = 0;
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::empty() const
{
    return this->len == 0;
}

template <typename KEY, typename VALUE>
const std::size_t map_t<KEY, VALUE>::length() const
{
    return this->len;
}

template <typename KEY, typename VALUE>
const std::size_t map_t<KEY, VALUE>::capacity() const
{
    return this->cap;
}

template <typename KEY, typename VALUE>
const long double map_t<KEY, VALUE>::error_rate(const std::size_t expected_size) const
{
    return (expected_size - this->len) * 100.0L / this->len;
}

template <typename KEY, typename VALUE>
typename map_t<KEY, VALUE>::iter map_t<KEY, VALUE>::iterator() const
{
    return map_t<KEY, VALUE>::iter(this);
}

template <typename KEY, typename VALUE>
inline void hash_combine(std::size_t &seed, const KEY &k, const VALUE &v)
{
    seed ^= std::hash<KEY>()(k) + std::hash<VALUE>()(v) + static_cast<std::size_t>(0xc70f6907UL) + (seed << 7) + (seed >> 3);
}

template <typename KEY, typename VALUE>
const std::size_t map_t<KEY, VALUE>::hash() const
{
    std::size_t h = 0;
    for (map_t<KEY, VALUE>::iter i = this->iterator(); i.c_loop(); i.next())
        hash_combine(h, i->key, i->value);
    return h;
}

template <typename KEY, typename VALUE>
void map_t<KEY, VALUE>::operator=(const map_t &other)
{
    this->erase();
    for (std::size_t i = 0; i < other.cap; i++)
    {
        node_t<KEY, VALUE> *cur = other.table[i];
        while (cur != nullptr)
        {
            this->add(std::move(cur->key), std::move(cur->value));
            cur = cur->next;
        }
    }
}

template <typename KEY, typename VALUE>
map_t<KEY, VALUE> &map_t<KEY, VALUE>::operator=(map_t &&other)
{
    if (this != &other)
    {
        this->erase();
        this->table = other.table;
        this->len = other.len;
        this->cap = other.cap;

        other.table = nullptr;
        other.len = 0;
        other.cap = 0;
    }
    return *this;
}

template <typename KEY, typename VALUE>
VALUE &map_t<KEY, VALUE>::operator[](KEY &&key) const
{
    std::size_t hash = this->get_hash(key, this->cap);
    node_t<KEY, VALUE> *cur = this->table[hash];
    while (cur != nullptr)
    {
        if (this->equal(cur->key, key))
            return cur->value;
        cur = cur->next;
    }
    static VALUE __t[1] = {};
    return (VALUE &)__t[0];
}

template <typename KEY, typename VALUE>
VALUE &map_t<KEY, VALUE>::operator[](const KEY &key) const
{
    std::size_t hash = this->get_hash(key, this->cap);
    node_t<KEY, VALUE> *cur = this->table[hash];
    while (cur != nullptr)
    {
        if (this->equal(cur->key, key))
            return cur->value;
        cur = cur->next;
    }
    static VALUE __t[1] = {};
    return (VALUE &)__t[0];
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::operator==(const map_t &other) const
{
    if (this->len != other.len)
        return false;
    for (std::size_t i = 0; i < this->cap; i++)
    {
        node_t<KEY, VALUE> *cur = this->table[i];
        while (cur != nullptr)
        {
            if (!other.contains(cur->key))
                return false;
            if (this->get(cur->key) != other.get(cur->key))
                return false;
            if (this->get(cur->value) != other.get(cur->value))
                return false;
            cur = cur->next;
        }
    }
    return true;
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::operator!=(const map_t &other) const
{
    return !(*this == other);
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::operator+=(std::pair<KEY, VALUE> pair)
{
    return this->add(std::move((KEY &&) pair.first), std::move((VALUE &&) pair.second));
}

template <typename KEY, typename VALUE>
void map_t<KEY, VALUE>::operator+=(std::initializer_list<std::pair<KEY, VALUE>> list)
{
    for (auto &pair : list)
        this->add(std::move((KEY &&) pair.first), std::move((VALUE &&) pair.second));
}

template <typename KEY, typename VALUE>
void map_t<KEY, VALUE>::operator+=(const map_t &other)
{
    for (std::size_t i = 0; i < other.cap; i++)
    {
        node_t<KEY, VALUE> *cur = other.table[i];
        while (cur != nullptr)
        {
            this->add(std::move(cur->key), std::move(cur->value));
            cur = cur->next;
        }
    }
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::operator-=(KEY &&key)
{
    return this->remove(std::move(key));
}

template <typename KEY, typename VALUE>
bool map_t<KEY, VALUE>::operator-=(const KEY &key)
{
    return this->remove((KEY &&) key);
}

template <typename KEY, typename VALUE>
map_t<KEY, VALUE>::~map_t()
{
    for (std::size_t i = 0; i < this->cap; i++)
    {
        node_t<KEY, VALUE> *cur = this->table[i];
        while (cur != nullptr)
        {
            node_t<KEY, VALUE> *next = cur->next;
            delete cur;
            cur = next;
        }
    }
    delete[] this->table;
    this->len = 0;
    this->cap = 0;
}

template <typename KEY, typename VALUE>
class iter_map_t
{
private:
    map_t<KEY, VALUE> *m;
    node_t<KEY, VALUE> *cur;
    std::size_t i;

public:
    iter_map_t(const map_t<KEY, VALUE> *m);
    bool c_loop() const;
    const node_t<KEY, VALUE> *&operator->() const;
    void next();
};

template <typename KEY, typename VALUE>
iter_map_t<KEY, VALUE>::iter_map_t(const map_t<KEY, VALUE> *m)
{
    this->m = (map_t<KEY, VALUE> *)m;
    this->i = 0;
    while (this->i < this->m->cap && this->m->table[this->i] == nullptr)
        this->i++;
    this->cur = this->m->table[this->i];
}

template <typename KEY, typename VALUE>
bool iter_map_t<KEY, VALUE>::c_loop() const
{
    return this->cur != nullptr;
}

template <typename KEY, typename VALUE>
const node_t<KEY, VALUE> *&iter_map_t<KEY, VALUE>::operator->() const
{
    return (const node_t<KEY, VALUE> *&)this->cur;
}

template <typename KEY, typename VALUE>
void iter_map_t<KEY, VALUE>::next()
{
    this->cur = this->cur->next;
    if (this->cur == nullptr)
    {
        this->i++;
        while (this->i < this->m->cap && this->m->table[this->i] == nullptr)
            this->i++;
        if (this->i < this->m->cap)
            this->cur = this->m->table[this->i];
    }
}

namespace std
{
    template <typename KEY, typename VALUE>
    struct hash<map_t<KEY, VALUE>>
    {
        std::size_t operator()(const map_t<KEY, VALUE> &m) const
        {
            return m.hash();
        }
    };
};

#endif