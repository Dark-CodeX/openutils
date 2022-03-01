/**
 * This header file is written to return optional values from a function in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/returns.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "optional.hh" under "returns" directory
 * returns version: 1.0.0
 * MIT License
 *
 * Copyright (c) 2022 Tushar Chaurasia
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
namespace openutils
{
    struct optnull_t
    {
        enum ctor
        {
            ctr
        };
        explicit constexpr optnull_t(ctor) {}
    };

    inline constexpr optnull_t optnull{optnull_t::ctor::ctr};

    template <typename T>
    class optional_t
    {
    private:
        bool has_value;
        T *value;

    public:
        optional_t(optnull_t);
        optional_t(const T &val);
        optional_t(T &&val);
        optional_t(const optional_t &opt);
        optional_t(optional_t &&opt);

        bool is_null() const;
        T &get() const;

        void operator=(const optional_t &opt);
        optional_t &operator=(optional_t &&opt);
        bool operator==(optnull_t) const;
        bool operator!=(optnull_t) const;
        operator const void *() const;
        ~optional_t();
    };

    template <typename T>
    optional_t<T>::optional_t(optnull_t)
    {
        this->has_value = false;
        this->value = nullptr;
    }

    template <typename T>
    optional_t<T>::optional_t(const T &val)
    {
        this->value = new T[1];
        *this->value = val;
        this->has_value = true;
    }

    template <typename T>
    optional_t<T>::optional_t(T &&val)
    {
        this->value = new T[1];
        *this->value = val;
        this->has_value = true;
    }

    template <typename T>
    optional_t<T>::optional_t(const optional_t &opt)
    {
        this->has_value = opt.has_value;
        if (opt.has_value == true)
        {
            this->value = new T[1];
            *this->value = *opt.value;
        }
        else
            this->value = nullptr;
    }

    template <typename T>
    optional_t<T>::optional_t(optional_t &&opt)
    {
        this->has_value = opt.has_value;
        if (opt.has_value == true)
        {
            this->value = new T[1];
            *this->value = *opt.value;
        }
        else
            this->value = nullptr;

        opt.has_value = false;
        opt.value = nullptr;
    }

    template <typename T>
    bool optional_t<T>::is_null() const
    {
        return !(this->value && this->has_value);
    }
    template <typename T>
    T &optional_t<T>::get() const
    {
        return *this->value;
    }

    template <typename T>
    void optional_t<T>::operator=(const optional_t &opt)
    {
        if (this->has_value == true)
            delete[] this->value;
        this->has_value = opt.has_value;
        if (opt.has_value == true)
        {
            this->value = new T[1];
            *this->value = *opt.value;
        }
        else
            this->value = nullptr;
    }

    template <typename T>
    optional_t<T> &optional_t<T>::operator=(optional_t &&opt)
    {
        if (*this != &opt)
        {
            if (this->has_value == true)
                delete[] this->value;
            this->has_value = opt.has_value;
            if (opt.has_value == true)
            {
                this->value = new T[1];
                *this->value = *opt.value;
            }
            else
                this->value = nullptr;
        }
        return *this;
    }

    template <typename T>
    bool optional_t<T>::operator==(optnull_t) const
    {
        return this->is_null();
    }

    template <typename T>
    bool optional_t<T>::operator!=(optnull_t) const
    {
        return !this->is_null();
    }

    template <typename T>
    optional_t<T>::operator const void *() const
    {
        return this->value;
    }

    template <typename T>
    optional_t<T>::~optional_t()
    {
        if (this->has_value == true)
            delete[] this->value;
    }
};

#endif