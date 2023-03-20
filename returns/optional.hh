/**
 * This header file is written to return optional values from a function in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/returns.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "optional.hh" under "returns" directory
 * returns version: 1.2.3
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

#ifndef RETURNS_OPTIONAL
#define RETURNS_OPTIONAL

#ifndef returns_version
#define returns_version "1.2.3"
#endif

#include <cstdlib>
#include <cstdio>

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
		optional_t(optional_t &&opt);

		bool is_null() const;
		const T &get() const;
		T &get();

		void operator=(const optional_t &opt);
		optional_t &operator=(optional_t &&opt);
		bool operator==(optnull_t) const;
		bool operator!=(optnull_t) const;
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
		this->value = new T(val);
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
	optional_t<T>::optional_t(optional_t &&opt)
	{
		this->value = opt.value;
		opt.value = nullptr;
	}

	template <typename T>
	bool optional_t<T>::is_null() const
	{
		return !(this->value);
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
	void optional_t<T>::operator=(const optional_t &opt)
	{
		if (opt.value)
		{
			if (this->value)
				delete this->value;
			this->value = new T(*opt.value);
			exit_heap_fail(this->value);
		}
	}

	template <typename T>
	optional_t<T> &optional_t<T>::operator=(optional_t &&opt)
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
};

#endif
#endif