/**
 * This header file is written to return any object_t from a function in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/returns.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "object_t.hh" under "returns" directory
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

#ifndef RETURNS_OBJECT
#define RETURNS_OBJECT

#define returns_version "1.5.0"

#include <cstdlib>
#include <cstring>
#include <cstdio>

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

	class object_t
	{
	private:
		void *value;
		std::size_t pointer_size;

		template <typename T>
		inline T &type_cast_val(void *ptr) const;

	public:
		object_t();
		template <typename T>
		object_t(T &&val);

		object_t(const object_t &c);
		object_t(object_t &&c) noexcept;

		template <typename T>
		object_t &set_value(T &&val);

		object_t &clear();
		bool is_null() const;

		template <typename T>
		inline T &get_value() const;

		template <typename T>
		object_t &change_value(T &&val);

		object_t &operator=(const object_t &c);
		object_t &operator=(object_t &&c) noexcept;

		~object_t();
	};

	template <typename T>
	inline T &object_t::type_cast_val(void *ptr) const
	{
		return *(static_cast<T *>(ptr));
	}

	object_t::object_t()
	{
		this->pointer_size = 0;
		this->value = nullptr;
	}

	template <typename T>
	object_t::object_t(T &&val)
	{
		this->pointer_size = sizeof(T);
		this->value = std::malloc(this->pointer_size);
		exit_heap_fail(this->value);
		if (!std::memmove(this->value, &val, this->pointer_size))
		{
			std::fprintf(stderr, "err: invalid pointer size of destination.\n");
			std::exit(EXIT_FAILURE);
		}
	}

	object_t::object_t(const object_t &c)
	{
		if (c.value)
		{
			this->pointer_size = c.pointer_size;
			this->value = std::malloc(this->pointer_size);
			exit_heap_fail(this->value);
			if (!std::memmove(this->value, c.value, this->pointer_size))
			{
				std::fprintf(stderr, "err: invalid pointer size of destination.\n");
				std::exit(EXIT_FAILURE);
			}
		}
		else
		{
			this->pointer_size = 0;
			this->value = nullptr;
		}
	}

	object_t::object_t(object_t &&c) noexcept
	{
		this->value = c.value;
		this->pointer_size = c.pointer_size;

		c.value = nullptr;
		c.pointer_size = 0;
	}

	template <typename T>
	object_t &object_t::set_value(T &&val)
	{
		if (this->value)
			std::free(this->value);
		this->pointer_size = sizeof(T);
		this->value = std::malloc(this->pointer_size);
		exit_heap_fail(this->value);
		if (!std::memmove(this->value, &val, this->pointer_size))
		{
			std::fprintf(stderr, "err: invalid pointer size of destination.\n");
			std::exit(EXIT_FAILURE);
		}
		return *this;
	}

	object_t &object_t::clear()
	{
		if (this->value)
			std::free(this->value);
		this->pointer_size = 0;
		return *this;
	}

	bool object_t::is_null() const
	{
		return !(this->value);
	}

	template <typename T>
	inline T &object_t::get_value() const
	{
		if (this->value)
			return this->type_cast_val<T>(this->value);
		std::fprintf(stderr, "err: invalid pointer access\n");
		std::exit(EXIT_FAILURE);
	}

	template <typename T>
	object_t &object_t::change_value(T &&val)
	{
		if (this->value)
			std::free(this->value);
		this->pointer_size = sizeof(T);
		this->value = std::malloc(this->pointer_size);
		exit_heap_fail(this->value);
		if (!std::memmove(this->value, &val, this->pointer_size))
		{
			std::fprintf(stderr, "err: invalid pointer size of destination.\n");
			std::exit(EXIT_FAILURE);
		}
		return *this;
	}

	object_t &object_t::operator=(const object_t &c)
	{
		if (this->value)
			std::free(this->value);
		this->pointer_size = c.pointer_size;

		this->value = std::malloc(this->pointer_size);
		exit_heap_fail(this->value);
		if (!std::memmove(this->value, c.value, this->pointer_size))
		{
			std::fprintf(stderr, "err: invalid pointer size of destination.\n");
			std::exit(EXIT_FAILURE);
		}
		return *this;
	}

	object_t &object_t::operator=(object_t &&c) noexcept
	{
		if (this != &c)
		{
			std::free(this->value);
			this->pointer_size = c.pointer_size;
			this->value = c.value;

			c.value = nullptr;
			c.pointer_size = 0;
		}
		return *this;
	}

	object_t::~object_t()
	{
		if (this->value)
			std::free(this->value);
		this->pointer_size = 0;
	}
}

#endif