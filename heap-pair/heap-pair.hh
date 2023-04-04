/**
 * This header file contains `heap_pair` class.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/heap-pair.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "heap-pair.hh" under "heap-pair" directory
 * heap-pair: version 1.0.0
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

#ifndef HEAP_PAIR_DEFINED
#define HEAP_PAIR_DEFINED

#include <cstdio>
#include <cstdlib>

#define heap_pair_version "1.0.0"

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

	template <typename FIRST, typename SECOND>
	class heap_pair
	{
	private:
		FIRST *t1;
		SECOND *t2;

	public:
		heap_pair();
		heap_pair(const FIRST &T1, const SECOND &T2);
		heap_pair(FIRST &&T1, SECOND &&T2);
		heap_pair(const heap_pair &pair);
		heap_pair(heap_pair &&pair) noexcept;
		const FIRST &first() const;
		const SECOND &second() const;
		heap_pair &operator=(const heap_pair &pair);
		heap_pair &operator=(heap_pair &&pair) noexcept;
		~heap_pair();

		static heap_pair make_heap_pair(const FIRST &T1, const SECOND &T2);
		static heap_pair make_heap_pair(FIRST &&T1, SECOND &&T2);
	};

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND>::heap_pair()
	{
		this->t1 = nullptr;
		this->t2 = nullptr;
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND>::heap_pair(const FIRST &T1, const SECOND &T2)
	{
		this->t1 = new FIRST(T1);
		exit_heap_fail(this->t1);
		this->t2 = new SECOND(T2);
		exit_heap_fail(this->t2);
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND>::heap_pair(FIRST &&T1, SECOND &&T2)
	{
		this->t1 = new FIRST(T1);
		exit_heap_fail(this->t1);
		this->t2 = new SECOND(T2);
		exit_heap_fail(this->t2);
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND>::heap_pair(const heap_pair &pair)
	{
		if (pair.t1 && pair.t2)
		{
			this->t1 = new FIRST(*pair.t1);
			exit_heap_fail(this->t1);
			this->t2 = new SECOND(*pair.t2);
			exit_heap_fail(this->t2);
		}
		else
		{
			this->t1 = nullptr;
			this->t2 = nullptr;
		}
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND>::heap_pair(heap_pair &&pair) noexcept
	{
		this->t1 = pair.t1;
		this->t2 = pair.t2;

		pair.t1 = nullptr;
		pair.t2 = nullptr;
	}

	template <typename FIRST, typename SECOND>
	const FIRST &heap_pair<FIRST, SECOND>::first() const
	{
		if (!this->t1)
		{
			std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
			std::exit(EXIT_FAILURE);
		}
		return *this->t1;
	}

	template <typename FIRST, typename SECOND>
	const SECOND &heap_pair<FIRST, SECOND>::second() const
	{
		if (!this->t2)
		{
			std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
			std::exit(EXIT_FAILURE);
		}
		return *this->t2;
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND> &heap_pair<FIRST, SECOND>::operator=(const heap_pair &pair)
	{
		if (this != &pair)
		{
			if (pair.t1 && pair.t2)
			{
				if (this->t1 && this->t2)
				{
					delete this->t1;
					delete this->t2;
				}
				this->t1 = new FIRST(*pair.t1);
				exit_heap_fail(this->t1);
				this->t2 = new SECOND(*pair.t2);
				exit_heap_fail(this->t2);
			}
		}
		return *this;
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND> &heap_pair<FIRST, SECOND>::operator=(heap_pair &&pair) noexcept
	{
		if (this != &pair)
		{
			if (pair.t1 && pair.t2)
			{
				if (this->t1 && this->t2)
				{
					delete this->t1;
					delete this->t2;
				}
				this->t1 = pair.t1;
				this->t2 = pair.t2;

				pair.t1 = nullptr;
				pair.t2 = nullptr;
			}
		}
		return *this;
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND>::~heap_pair()
	{
		if (this->t1 && this->t2)
		{
			delete this->t1;
			delete this->t2;
		}
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND> heap_pair<FIRST, SECOND>::make_heap_pair(const FIRST &T1, const SECOND &T2)
	{
		return heap_pair<FIRST, SECOND>(T1, T2);
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND> heap_pair<FIRST, SECOND>::make_heap_pair(FIRST &&T1, SECOND &&T2)
	{
		return heap_pair<FIRST, SECOND>(T1, T2);
	}
}

#endif
