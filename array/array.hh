/**
 * This header file is written to manage array under C++ programming language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/array.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "array.hh" under "array" directory
 * array: version 1.0.0
 * MIT License
 *
 * Copyright (c) 2023 Tushar Chaurasia
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

#ifndef ARRAY_T_DEFINED
#define ARRAY_T_DEFINED

#include <cstdlib>
#include <cstdio>
#include <initializer_list>
#include <algorithm>

#define array_version "1.0.0"

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

	template <typename T, std::size_t cap>
	class array_t
	{
	private:
		T *arr;
		std::size_t len;

	public:
		array_t();
		array_t(const array_t &a);
		array_t(array_t &&a) noexcept;
		array_t(std::initializer_list<T> list);
		void add(const T &src);
		void add(T &&src);
		void remove();
		bool remove(const std::size_t &nth);
		const std::size_t &length() const;
		const std::size_t &capacity() const;

		void reverse();
		void erase();
		bool empty() const;
		const T &get(const std::size_t &nth) const;
		T &get(const std::size_t &nth);
		void set(const T &src, const std::size_t &nth);
		void set(T &&src, const std::size_t &nth);
		std::size_t hash() const;
		bool compare(array_t &&a) const;
		bool compare(const array_t &a) const;
		bool compare_hash(array_t &&a) const;
		bool compare_hash(const array_t &a) const;

		const T *&raw_data() const;
		T *&raw_data();
		template <typename comp>
		void sort(comp c)
		{
			std::sort(this->arr, this->arr + this->len, c);
		}
		void operator=(const array_t &a);
		array_t &operator=(array_t &&a) noexcept;
		bool operator==(const array_t &a) const;
		bool operator==(array_t &&a) const;
		bool operator!=(const array_t &a) const;
		bool operator!=(array_t &&a) const;
		void operator+=(const array_t &data);
		void operator+=(array_t &&data);
		void operator+=(T &&data);
		void operator+=(const T &data);
		void operator+=(std::initializer_list<T> __list);
		const std::size_t nerr = (std::size_t)-1;
		const T &operator[](const std::size_t &nth) const;
		T &operator[](const std::size_t &nth);
		~array_t();
	};

	template <typename T, std::size_t cap>
	array_t<T, cap>::array_t()
	{
		this->arr = new T[cap]();
		exit_heap_fail(this->arr);
		this->len = 0;
	}

	template <typename T, std::size_t cap>
	array_t<T, cap>::array_t(const array_t &a)
	{
		this->arr = new T[a.capacity()]();
		exit_heap_fail(this->arr);
		for (this->len = 0; this->len < a.len; this->len++)
		{
			arr[this->len] = a.arr[this->len];
		}
	}

	template <typename T, std::size_t cap>
	array_t<T, cap>::array_t(array_t &&a) noexcept
	{
		this->arr = a.arr;
		this->len = a.len;

		a.arr = nullptr;
		a.len = 0;
	}

	template <typename T, std::size_t cap>
	array_t<T, cap>::array_t(std::initializer_list<T> list)
	{
		if (cap < list.size())
		{
			std::fprintf(stderr, "err: length exceeds capacity\n");
			std::exit(EXIT_FAILURE);
		}
		for (auto &&i : list)
			this->add(i);
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::add(const T &src)
	{
		this->arr[this->len++] = src;
		if (cap <= this->len)
		{
			std::fprintf(stderr, "err: length exceeds capacity\n");
			std::exit(EXIT_FAILURE);
		}
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::add(T &&src)
	{
		this->arr[this->len++] = src;
		if (cap < this->len)
		{
			std::fprintf(stderr, "err: length exceeds capacity\n");
			std::exit(EXIT_FAILURE);
		}
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::remove()
	{
		this->len--;
	}

	template <typename T, std::size_t cap>
	bool array_t<T, cap>::remove(const std::size_t &nth)
	{
		if (nth < this->len)
		{
			static T __t[1] = {};
			this->arr[nth] = __t[0];
			for (std::size_t i = nth; i < this->len - 1; i++)
			{
				this->arr[i] = this->arr[i + 1];
				this->arr[i + 1] = __t[0];
			}
			this->len--;
			return true;
		}
		return false;
	}

	template <typename T, std::size_t cap>
	const std::size_t &array_t<T, cap>::length() const
	{
		return this->len;
	}

	template <typename T, std::size_t cap>
	const std::size_t &array_t<T, cap>::capacity() const
	{
		return cap;
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::reverse()
	{
		T c;
		for (std::size_t i = 0; i < this->len / 2; i++)
		{
			c = this->arr[i];
			this->arr[i] = this->arr[this->len - i - 1];
			this->arr[this->len - i - 1] = c;
		}
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::erase()
	{
		delete[] this->arr;
		this->arr = new T[this->capacity()]();
		this->len = 0;
	}

	template <typename T, std::size_t cap>
	bool array_t<T, cap>::empty() const {
		return this->len == 0;
	}

	template <typename T, std::size_t cap>
	const T &array_t<T, cap>::get(const std::size_t &nth) const {}
	template <typename T, std::size_t cap>
	T &array_t<T, cap>::get(const std::size_t &nth) {}
	template <typename T, std::size_t cap>
	void array_t<T, cap>::set(const T &src, const std::size_t &nth) {}
	template <typename T, std::size_t cap>
	void array_t<T, cap>::set(T &&src, const std::size_t &nth) {}
	template <typename T, std::size_t cap>
	std::size_t array_t<T, cap>::hash() const {}
	template <typename T, std::size_t cap>
	bool array_t<T, cap>::compare(array_t &&a) const {}
	template <typename T, std::size_t cap>
	bool array_t<T, cap>::compare(const array_t &a) const {}
	template <typename T, std::size_t cap>
	bool array_t<T, cap>::compare_hash(array_t &&a) const {}
	template <typename T, std::size_t cap>
	bool array_t<T, cap>::compare_hash(const array_t &a) const {}

	template <typename T, std::size_t cap>
	const T *&array_t<T, cap>::raw_data() const
	{
		return this->arr;
	}

	template <typename T, std::size_t cap>
	T *&array_t<T, cap>::raw_data()
	{
		return this->arr;
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::operator=(const array_t &a)
	{
		delete[] this->arr;
		this->len = 0;
		this->arr = new T[a.capacity()];
		for (std::size_t i = 0; i < a.len; i++)
			this->add(a[i]);
	}

	template <typename T, std::size_t cap>
	array_t<T, cap> &array_t<T, cap>::operator=(array_t &&a) noexcept
	{
		if (this != &a)
		{
			delete[] this->arr;
			this->len = 0;
			this->arr = a.arr;
			this->len = a.len;

			a.arr = nullptr;
			a.len = 0;
		}
		return *this;
	}

	template <typename T, std::size_t cap>
	bool array_t<T, cap>::operator==(const array_t &a) const
	{
		if (a.len != this->len)
			return false;
		for (std::size_t i = 0; i < a.len; i++)
			if (this->arr[i] != a.arr[i])
				return false;
	}

	template <typename T, std::size_t cap>
	bool array_t<T, cap>::operator==(array_t &&a) const
	{
		if (a.len != this->len)
			return false;
		for (std::size_t i = 0; i < a.len; i++)
			if (this->arr[i] != a.arr[i])
				return false;
	}

	template <typename T, std::size_t cap>
	bool array_t<T, cap>::operator!=(const array_t &a) const
	{
		return !(*this == a);
	}

	template <typename T, std::size_t cap>
	bool array_t<T, cap>::operator!=(array_t &&a) const
	{
		return !(*this == a);
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::operator+=(const array_t &data)
	{
		for (std::size_t i = 0; i < data.len; i++)
			this->add(data.arr[i]);
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::operator+=(array_t &&data)
	{
		for (std::size_t i = 0; i < data.len; i++)
			this->add(data.arr[i]);
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::operator+=(T &&data)
	{
		this->add(data);
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::operator+=(const T &data)
	{
		this->add(data);
	}

	template <typename T, std::size_t cap>
	void array_t<T, cap>::operator+=(std::initializer_list<T> __list)
	{
		for (auto &&i : __list)
			this->add(i);
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
	array_t<T, cap>::~array_t()
	{
		delete[] this->arr;
		this->len = 0;
	}
};

#endif
#endif