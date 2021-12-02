#ifdef __cplusplus

#pragma once

#include <initializer_list>
#include <functional>

template <typename T>
class vector_t
{
private:
    void resize();
    std::size_t len = 0, cap = 10;
    T *data;
    T __t[1] = {};

public:
    vector_t();
    vector_t(T &&default_data, std::size_t capacity = 10);
    vector_t(const vector_t &vec);
    vector_t(vector_t &&other) noexcept;
    vector_t(std::initializer_list<T> __list);
    const std::size_t length() const;
    const std::size_t capacity() const;
    void add(T &&data);
    bool insert(T &&data, const std::size_t nth);
    void remove();
    bool remove(const std::size_t nth);
    bool empty();
    void erase();
    T &get(const std::size_t nth);
    bool set(T &&data, const std::size_t nth);
    void reverse();
    const std::size_t find(T &&data) const;
    bool swap(const std::size_t x1, const std::size_t x2);
    const T *cdata() const;

    void operator=(const vector_t &data);
    T &operator[](const std::size_t nth);
    bool operator==(const vector_t &vec);
    bool operator!=(const vector_t &vec);
    vector_t &operator=(const vector_t &&__s) noexcept;
    void operator+=(T &&data);
    const std::size_t nerr = (std::size_t)-1;

    bool unsafe_set(std::size_t where, T &&data);
    bool unsafe_remove(std::size_t where);
    std::size_t unsafe_resize(std::size_t new_size);
    T &unsafe_get(std::size_t where);

    ~vector_t();
};

template <typename T>
vector_t<T>::vector_t()
{
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
    this->__t[0] = default_data;
}

template <typename T>
vector_t<T>::vector_t(const vector_t &vec)
{
    delete[] this->data;
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
    if (__list.size() < this->cap)
        this->data = new T[this->cap];
    else
        this->data = new T[this->cap + __list.size()];
    for (auto i = __list.begin(); i != __list.end(); i++, this->len++)
        this->data[this->len] = *i;
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
        for (std::size_t i = this->len; i >= nth; i--)
        {
            this->data[i + 1] = this->data[i];
            this->data[i] = this->__t[0];
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
    this->data[this->len--] = this->__t[0];
}

template <typename T>
bool vector_t<T>::remove(const std::size_t nth)
{
    if (nth < this->len)
    {
        this->data[nth] = this->__t[0];
        for (std::size_t i = nth; i < this->len - 1; i++)
        {
            this->data[i] = this->data[i + 1];
            this->data[i + 1] = this->__t[0];
        }
        this->len--;
        return true;
    }
    return false;
}

template <typename T>
bool vector_t<T>::empty()
{
    return (this->len == 0);
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
T &vector_t<T>::get(const std::size_t nth)
{
    if (nth < this->len)
        return this->data[nth];
    return this->__t[0];
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
const T *vector_t<T>::cdata() const
{
    return this->data;
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
T &vector_t<T>::operator[](const std::size_t nth)
{
    if (nth < this->len)
        return this->data[nth];
    return this->__t[0];
}

template <typename T>
bool vector_t<T>::operator==(const vector_t &vec)
{
    if (this->len != vec.len)
        return false;
    for (std::size_t i = 0; i < this->len; i++)
        if (this->data[i] != vec.data[i])
            return false;
    return true;
}

template <typename T>
bool vector_t<T>::operator!=(const vector_t &vec)
{
    if (this->len != vec.len)
        return true;
    for (std::size_t i = 0; i < this->len; i++)
        if (this->data[i] != vec.data[i])
            return true;
    return false;
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
void vector_t<T>::operator+=(T &&data)
{
    this->add(data);
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
    this->data[where] = this->__t[0];
    return true;
}

template <typename T>
std::size_t vector_t<T>::unsafe_resize(std::size_t new_size)
{
    if(new_size <= this->cap)
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
T &vector_t<T>::unsafe_get(std::size_t where)
{
    if (where >= this->cap)
        return this->__t[0];
    return this->data[where];
}

template <typename T>
vector_t<T>::~vector_t()
{
    this->len = 0;
    this->cap = 0;
    delete[] this->data;
}

template <typename T>
inline void hash_combine(std::size_t &seed, const T &v)
{
    seed ^= std::hash<T>()(v) + static_cast<std::size_t>(0xc70f6907UL) + (seed << 7) + (seed >> 3);
}

namespace std
{
    template <typename T>
    struct hash<vector_t<T>>
    {
        std::size_t operator()(const vector_t<T> &vec) const
        {
            std::size_t h = 0;
            for (std::size_t i = 0; i < vec.length(); i++)
                hash_combine(h, vec.cdata()[i]);
            return h;
        }
    };
};

#endif