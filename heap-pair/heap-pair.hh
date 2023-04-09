/**
 * This header file contains `heap_pair` class.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/heap-pair.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "heap-pair.hh" under "heap-pair" directory
 * heap-pair: version 1.0.1
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

#ifndef HEAP_PAIR_DEFINED
#define HEAP_PAIR_DEFINED

#include <cstdio>
#include <cstdlib>
#include <utility>

#define heap_pair_version "1.0.1"

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
		FIRST &first();
		SECOND &second();
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
	FIRST &heap_pair<FIRST, SECOND>::first()
	{
		if (!this->t1)
		{
			std::fprintf(stderr, "err: cannot de-reference a null-pointer\n");
			std::exit(EXIT_FAILURE);
		}
		return *this->t1;
	}

	template <typename FIRST, typename SECOND>
	SECOND &heap_pair<FIRST, SECOND>::second()
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
		heap_pair<FIRST, SECOND> x = heap_pair<FIRST, SECOND>(T1, T2);
		return return std::move(x);
	}

	template <typename FIRST, typename SECOND>
	heap_pair<FIRST, SECOND> heap_pair<FIRST, SECOND>::make_heap_pair(FIRST &&T1, SECOND &&T2)
	{
		heap_pair<FIRST, SECOND> x = heap_pair<FIRST, SECOND>(T1, T2);
		return return std::move(x);
	}
}

#endif
