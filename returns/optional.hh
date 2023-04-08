/**
 * This header file is written to return optional values from a function in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/returns.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "optional.hh" under "returns" directory
 * returns version: 1.5.0
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

#ifndef RETURNS_OPTIONAL
#define RETURNS_OPTIONAL

#define returns_version "1.5.0"

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

		optional_t &operator=(const optional_t &opt);
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
	optional_t<T> &optional_t<T>::operator=(const optional_t &opt)
	{
		if (opt.value)
		{
			if (this->value)
				delete this->value;
			this->value = new T(*opt.value);
			exit_heap_fail(this->value);
		}
		return *this;
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