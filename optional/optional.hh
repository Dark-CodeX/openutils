/**
 * @file optional.hh
 * @brief This file contains declaration as well as definition of optional_t class.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 1.6.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef OPENUTILS_OPTIONAL_DEFINED
#define OPENUTILS_OPTIONAL_DEFINED

#define OPENUTILS_optional_version "1.6.0"

#include <cstdlib>
#include <cstdio>
#include <functional>

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
    class optional_t
    {
    private:
        T *value;

    public:
        optional_t();
        optional_t(optnull_t);
        optional_t(const T &val);
        optional_t(T &&val);
        optional_t(const optional_t &opt);
        optional_t(optional_t &&opt) noexcept;

        bool is_null() const;
        const T &get() const;
        T &get();
        optional_t &swap(optional_t &opt) noexcept;
        std::size_t hash() const;

        optional_t &operator=(const optional_t &opt);
        optional_t &operator=(optional_t &&opt) noexcept;
        bool operator==(optnull_t) const;
        bool operator!=(optnull_t) const;
        bool operator==(const optional_t &opt) const;
        bool operator!=(const optional_t &opt) const;
        operator const void *() const;
        ~optional_t();
    };

    template <typename T>
    optional_t<T>::optional_t()
    {
        this->value = nullptr;
    }

    template <typename T>
    optional_t<T>::optional_t(optnull_t)
    {
        this->value = nullptr;
    }

    template <typename T>
    optional_t<T>::optional_t(const T &val)
    {
        this->value = new T(val);
        exit_heap_fail(this->value);
    }

    template <typename T>
    optional_t<T>::optional_t(T &&val)
    {
        this->value = new T(std::move(val));
        exit_heap_fail(this->value);
    }

    template <typename T>
    optional_t<T>::optional_t(const optional_t &opt)
    {
        if (opt.value)
        {
            this->value = new T(*opt.value);
            exit_heap_fail(this->value);
        }
        else
            this->value = nullptr;
    }

    template <typename T>
    optional_t<T>::optional_t(optional_t &&opt) noexcept
    {
        this->value = opt.value;
        opt.value = nullptr;
    }

    template <typename T>
    bool optional_t<T>::is_null() const
    {
        return this->value == nullptr;
    }

    template <typename T>
    const T &optional_t<T>::get() const
    {
        if (!this->value)
        {
            std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
            std::exit(EXIT_FAILURE);
        }
        return *this->value;
    }

    template <typename T>
    T &optional_t<T>::get()
    {
        if (!this->value)
        {
            std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
            std::exit(EXIT_FAILURE);
        }
        return *this->value;
    }

    template <typename T>
    optional_t<T> &optional_t<T>::swap(optional_t<T> &opt) noexcept
    {
        T *temp = this->value;
        this->value = opt.value;
        opt.value = temp;
        return *this;
    }

    template <typename T>
    std::size_t optional_t<T>::hash() const
    {
        if (this->value)
            return std::hash<T>()(*this->value);
        return 0;
    }

    template <typename T>
    optional_t<T> &optional_t<T>::operator=(const optional_t &opt)
    {
        if (*this != &opt)
        {
            if (opt.value)
            {
                if (this->value)
                    delete this->value;
                this->value = new T(*opt.value);
                exit_heap_fail(this->value);
            }
        }
        return *this;
    }

    template <typename T>
    optional_t<T> &optional_t<T>::operator=(optional_t &&opt) noexcept
    {
        if (*this != &opt)
        {
            if (opt.value)
            {
                if (this->value)
                    delete this->value;
                this->value = opt.value;
                opt.value = nullptr;
            }
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
    bool optional_t<T>::operator==(const optional_t &opt) const
    {
        if (this->value && opt.value)
        {
            return *this->value == *opt.value;
        }
        return false;
    }

    template <typename T>
    bool optional_t<T>::operator!=(const optional_t &opt) const
    {
        if (this->value && opt.value)
        {
            return *this->value != *opt.value;
        }
        return true;
    }

    template <typename T>
    optional_t<T>::operator const void *() const
    {
        return this->value;
    }

    template <typename T>
    optional_t<T>::~optional_t()
    {
        if (this->value)
            delete this->value;
    }
}

namespace std
{
    template <typename T>
    struct hash<openutils::optional_t<T>>
    {
        std::size_t operator()(const openutils::optional_t<T> &opt) const
        {
            return opt.hash();
        }
    };
};

#endif