/**
 * This header file is written to manage string data safely under C++ programming language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/sstring.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "sstring.hh" under "sstring" directory
 * sstring: version 2.0.2
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

#ifndef SSTRING_DEFINED
#define SSTRING_DEFINED

#include "binary.h"
#include "morse_code.h"
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <numeric>
#include <openutils/heap-pair/heap-pair.hh>
#include <openutils/vector/vector.hh>
#include <openutils/map/map.hh>
#include <ostream>

#define sstring_version "2.0.2"

namespace std
{
	template <>
	struct hash<const char *>
	{
		std::size_t operator()(const char *const &str) const
		{
			std::size_t p = 53;
			std::size_t m = 1e9 + 9;
			long long power_of_p = 1;
			long long hash_val = 0;

			for (std::size_t i = 0; str[i] != 0; i++)
			{
				hash_val = (hash_val + (str[i] - 97 + 1) * power_of_p) % m;
				power_of_p = (power_of_p * p) % m;
			}
			return (hash_val % m + m) % m;
		}
	};

	template <>
	struct hash<const unsigned char *>
	{
		std::size_t operator()(const unsigned char *const &str) const
		{
			std::size_t p = 53;
			std::size_t m = 1e9 + 9;
			long long power_of_p = 1;
			long long hash_val = 0;

			for (std::size_t i = 0; str[i] != 0; i++)
			{
				hash_val = (hash_val + (str[i] - 97 + 1) * power_of_p) % m;
				power_of_p = (power_of_p * p) % m;
			}
			return (hash_val % m + m) % m;
		}
	};
} // namespace std

namespace openutils
{
	/**
	 * Linear time complexity = O(n), where n is the length of `src`. NOTE: `dest` must have enough space for `src`.
	 * @param dest string where `src` is going to append
	 * @param src string to be appended
	 * @param size where to append `src`
	 */
	void fast_strncat(char *dest, const char *src, std::size_t &size)
	{
		if (dest && src)
			while ((dest[size] = *src++))
				size += 1;
	}

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

	/**
	 * @brief Searches and returns the first occurrence of `needle` in `haystack`.
	 * @brief Time comeplexity of this function is O(m + n), where m is the length of `haystack` and n is the length of `needle`.
	 * @brief This function uses the Knuth–Morris–Pratt or KMP algorithm, for more information visit: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm#
	 * @param haystack string to search for the substring
	 * @param haystack_len length of `haystack`
	 * @param needle substring to search for within `haystack`
	 * @return If `needle` is found within `haystack`, it returns a pointer to the first occurrence of `needle` in `haystack`, else if `needle` is not found, it returns nullptr
	 */
	char *fast_strstr(const char *haystack, std::size_t haystack_len, const char *needle)
	{
		if (!haystack || !needle || haystack_len == 0)
			return nullptr;
		std::size_t needle_len = std::strlen(needle);
		if (needle_len == 0)
			return (char *)haystack;
		int *prefix = static_cast<int *>(std::malloc(needle_len * sizeof(int)));
		if (!prefix)
		{
			std::fprintf(stderr, "err: can't allocate heap memory.\n");
			std::exit(EXIT_FAILURE);
		}
		prefix[0] = 0;
		int k = 0;
		for (std::size_t q = 1; q < needle_len; ++q)
		{
			while (k > 0 && needle[k] != needle[q])
				k = prefix[k - 1];
			if (needle[k] == needle[q])
				k += 1;
			prefix[q] = k;
		}
		int q = 0;
		for (std::size_t i = 0; i < haystack_len; ++i)
		{
			while (q > 0 && needle[q] != haystack[i])
				q = prefix[q - 1];
			if (needle[q] == haystack[i])
				q += 1;
			if (q == (int)needle_len)
			{
				std::free(prefix);
				return (char *)(haystack + i - needle_len + 1);
			}
		}
		std::free(prefix);
		return nullptr;
	}

	enum lexer_token
	{
		WORD,
		INTEGER,
		ESC_SEQ,
		SPECIAL_CHAR,
		WHITESPACE,
		NULL_END
	} lexer_token;

	class sstring
	{
	private:
		char *src;
		std::size_t len;

	public:
		/**
		 * @brief Default constructor of sstring, it assigns nullptr to src and 0 to len
		 */
		sstring();

		/**
		 * @brief Assigns `c`.
		 * @param c char to assign
		 */
		sstring(const char c);

		/**
		 * @brief Assigns `str`
		 * @param str C-style null-terminated string
		 */
		sstring(const char *str);

		/**
		 * @brief Assigns `c`, `n` times
		 * @param c char to assign
		 * @param n number of times `c` has to be repeated
		 */
		sstring(const char c, std::size_t n);

		/**
		 * @brief Assigns `str`, `n` times
		 * @param str C-style null-terminated string
		 * @param n number of times `str` has to be repeated
		 */
		sstring(const char *str, std::size_t n);

		/**
		 * @brief Copy constructor for sstring
		 * @param other another sstring object
		 */
		sstring(const sstring &other);

		/**
		 * @brief Move constructor for sstring
		 * @param other another sstring object
		 */
		sstring(sstring &&other) noexcept;

		/**
		 * @brief Assigns list of `char`s
		 * @param list list of `char`s
		 */
		sstring(std::initializer_list<char> list);

		/**
		 * @brief Assigns list of `sstring`s
		 * @param list list of `sstring`s
		 */
		sstring(std::initializer_list<sstring> list);

		/**
		 * @brief Assigns `str`
		 * @param str C-style null-terminated string
		 * @return sstring& reference to current object
		 */
		sstring &set(const char *str);

		/**
		 * @brief Assigns `str`
		 * @param str sstring to assign
		 * @return sstring& reference to current object
		 */
		sstring &set(const sstring &str);

		/**
		 * @brief Assigns `c`
		 * @param c char to assign
		 * @return sstring& reference to current object
		 */
		sstring &set_char(const char c);

		/**
		 * @brief Assigns `str` upto `N`
		 * @param str C-style null-terminated string
		 * @param N number of char that has to be assigned
		 * @return sstring& reference to current object
		 */
		sstring &set_upto(const char *str, std::size_t N);

		/**
		 * @brief Assigns `str` upto `N`
		 * @param str sstring to assign
		 * @param N number of char that has to be assigned
		 * @return sstring& reference to current object
		 */
		sstring &set_upto(const sstring &str, std::size_t N);

		/**
		 * @brief Assigns random characters
		 * @param rnd_len length of random characters
		 * @return sstring& reference to current object
		 */
		sstring &set_random(const std::size_t rnd_len);

		/**
		 * @brief Assigns `vec` with `between` between each iteration
		 * @param vec vector of `char *` that has to be assigned
		 * @param between if `nullptr` then, nothing is added between each iteration
		 * @return sstring& reference to current object
		 */
		sstring &set_array(const vector_t<char *> &vec, const char *between = nullptr);

		/**
		 * @brief Assigns `vec` with `between` between each iteration
		 * @param vec vector of sstring that has to be assigned
		 * @param between if `nullptr` then, nothing is added between each iteration
		 * @return sstring& reference to current object
		 */
		sstring &set_array(const vector_t<sstring> &vec, const char *between = nullptr);

		/**
		 * @brief Returns `this->src` by reference, and it can be modified [UNSAFE]
		 * @return char*& reference to `this->src`
		 */
		char *&get();

		/**
		 * @brief Returns `this->src` as `const char *`
		 * @return const char* of `this->src`
		 */
		const char *c_str() const;

		/**
		 * @brief Get the reference of the current object
		 * @return sstring& `*this`
		 */
		sstring &get_ref();

		/**
		 * @brief Appends `str`
		 * @param str C-style null-terminated string
		 * @return sstring& reference to current object
		 */
		sstring &append(const char *str);

		/**
		 * @brief Appends `str`
		 * @param str sstring to append
		 * @return sstring& reference to current object
		 */
		sstring &append(const sstring &str);

		/**
		 * @brief Appends `c`
		 * @param c char to append
		 * @return sstring& reference to current object
		 */
		sstring &append_char(const char c);

		/**
		 * @brief Appends `str` upto `N`
		 * @param str C-style null-terminated string
		 * @param N number of char that has to be appended
		 * @return sstring& reference to current object
		 */
		sstring &append_upto(const char *str, std::size_t N);

		/**
		 * @brief Appends `str` upto `N`
		 * @param str sstring to append
		 * @param N number of char that has to be appended
		 * @return sstring& reference to current object
		 */
		sstring &append_upto(const sstring &str, std::size_t N);

		/**
		 * @brief Appends `str` at index 0
		 * @param str C-style null-terminated string
		 * @return sstring& reference to current object
		 */
		sstring &append_start(const char *str);

		/**
		 * @brief Appends `str` at index 0
		 * @param str sstring to append
		 * @return sstring& reference to current object
		 */
		sstring &append_start(const sstring &str);

		/**
		 * @brief Appends `c` at index 0
		 * @param c char to append
		 * @return sstring& reference to current object
		 */
		sstring &append_start_char(const char c);

		/**
		 * @brief Appends `str` upto `N` at index 0
		 * @param str C-style null-terminated string
		 * @param N number of char that has to be appended
		 * @return sstring& reference to current object
		 */
		sstring &append_start_upto(const char *str, std::size_t N);

		/**
		 * @brief Appends `str` upto `N` at index 0
		 * @param str sstring to append
		 * @param N number of char that has to be appended
		 * @return sstring& reference to current object
		 */
		sstring &append_start_upto(const sstring &str, std::size_t N);

		/**
		 * @brief Appends `vec` with `between` between each iteration
		 * @param vec vector of `char *` that has to be assigned
		 * @param between if `nullptr` then, nothing is added between each iteration
		 * @return sstring& reference to current object
		 */
		sstring &append_array(const vector_t<char *> &vec, const char *between = nullptr);

		/**
		 * @brief Appends `vec` with `between` between each iteration
		 * @param vec vector of sstring that has to be assigned
		 * @param between if `nullptr` then, nothing is added between each iteration
		 * @return sstring& reference to current object
		 */
		sstring &append_array(const vector_t<sstring> &vec, const char *between = nullptr);

		/**
		 * @brief Appends `vec` with `between` between each iteration at index 0
		 * @param vec vector of `char *` that has to be assigned
		 * @param between if `nullptr` then, nothing is added between each iteration
		 * @return sstring& reference to current object
		 */
		sstring &append_start_array(const vector_t<char *> &vec, const char *between = nullptr);

		/**
		 * @brief Appends `vec` with `between` between each iteration at index 0
		 * @param vec vector of sstring that has to be assigned
		 * @param between if `nullptr` then, nothing is added between each iteration
		 * @return sstring& reference to current object
		 */
		sstring &append_start_array(const vector_t<sstring> &vec, const char *between = nullptr);

		/**
		 * @brief Tells whether `this->len` is 0 or not
		 * @return true `this->len` is 0;
		 * @return false `this->len` is NOT 0
		 */
		bool is_empty() const;

		/**
		 * @brief Tells whether `this->src` is `nullptr` or not
		 * @return true `this->src` is `nullptr`;
		 * @return false `this->src` is NOT `nullptr`
		 */
		bool is_null() const;

		/**
		 * @brief Replaces `old` with `new_`
		 * @param old what to replace
		 * @param new_ replace with
		 * @return sstring& reference to current object
		 */
		sstring &replace(const char *old, const char *new_);

		/**
		 * @brief Replaces `old` with `new_`
		 * @param old what to replace
		 * @param new_ replace with
		 * @return sstring& reference to current object
		 */
		sstring &replace(const sstring &old, const sstring &new_);

		/**
		 * @brief Replaces `old` with `new_`
		 * @param old what to replace
		 * @param new_ replace with
		 * @return sstring& reference to current object
		 */
		sstring &replace_char(const char old, const char new_);

		/**
		 * @brief Changes character at `nth` with `new_char`
		 * @param new_char new character
		 * @param nth index of old character
		 * @return sstring& reference to current object
		 */
		sstring &char_set(const char new_char, std::size_t nth);

		/**
		 * @brief Returns character at `nth` index
		 * @param nth index of character
		 * @return char at `nth`
		 */
		char char_get(std::size_t nth) const;

		/**
		 * @brief Returns reference of character at `nth` index
		 * @param nth index of character
		 * @return char& at `nth`
		 */
		char &char_get(std::size_t nth);

		/**
		 * @brief Returns the index of `ch` from starting
		 * @param ch character to find
		 * @return std::size_t index of `ch` if found, else `this->nerr()`
		 */
		std::size_t index_of(char ch) const;

		/**
		 * @brief Returns the index of `ch` from ending
		 * @param ch character to find
		 * @return std::size_t index of `ch` if found, else `this->nerr()`
		 */
		std::size_t last_index_of(char ch) const;

		/**
		 * @brief Returns the length of `this->src` without using `std::strlen`, it is done by keeping track in every function
		 * @return const std::size_t& returns the length of `this->src`
		 */
		const std::size_t &length() const;

		/**
		 * @brief Changes `this->len` to `new_length` [UNSAFE]
		 * @param new_length new length that has to be assigned
		 * @return sstring& reference to current object
		 */
		std::size_t &change_length(std::size_t new_length);

		/**
		 * @brief Compares `T1` to `this->src`
		 * @param T1 C-style null-terminated string
		 * @return true both strings are equal;
		 * @return false both string are unequal
		 */
		bool compare(const char *T1) const;

		/**
		 * @brief Compares `T1` to `this->src`
		 * @param T1 sstring to be compared
		 * @return true both strings are equal;
		 * @return false both string are unequal
		 */
		bool compare(const sstring &T1) const;

		/**
		 * @brief Compares `T1` to `this->src` upto `N`
		 * @param T1 C-style null-terminated string
		 * @param N number to character that has to be compared
		 * @return true both strings are equal upto `N`;
		 * @return false both string are unequal upto `N`
		 */
		bool compare_upto(const char *T1, std::size_t N) const;

		/**
		 * @brief Compares `T1` to `this->src` upto `N`
		 * @param T1 sstring to be compared
		 * @param N number to character that has to be compared
		 * @return true both strings are equal upto `N`;
		 * @return false both string are unequal upto `N`
		 */
		bool compare_upto(const sstring &T1, std::size_t N) const;

		/**
		 * @brief Tells whether `*this` object changed after a function was called
		 * @param obj return value of that function
		 * @return true changed;
		 * @return false not changed
		 */
		bool is_changed(sstring &obj);

		/**
		 * @brief A lexicographical comparison is the kind of comparison generally used to sort strings alphabetically.
		 * @param str string to compare with
		 * @return difference between ASCII characters or if starting of both the strings are same then it returns the difference between the length, otherwise 0 is returned if strings are equal
		 */
		int lexicographical_comparison(const char *str) const;

		/**
		 * @brief A lexicographical comparison is the kind of comparison generally used to sort strings alphabetically.
		 * @param str sstring to compare with
		 * @return difference between ASCII characters or if starting of both the strings are same then it returns the difference between the length, otherwise 0 is returned if strings are equal
		 */
		int lexicographical_comparison(const sstring &str) const;

		/**
		 * @brief Prints `this->src` to `stdout` and then flush the buffer
		 * @param add_next_line if true add `\n` at the end, otherwise no change
		 * @param __format__ string containing the format instructions
		 * @param ... arguments
		 * @return std::size_t number of characters printed on `stdout`
		 */
		std::size_t print(bool add_next_line, const char *__format__, ...) const;

		/**
		 * @brief Saves `this->src` at `location` in the filesystem
		 * @param location location of file
		 * @return true file saved successfully
		 * @return false file was NOT saved
		 */
		bool save(const char *location) const;

		/**
		 * @brief Saves `this->src` at `location` in the filesystem
		 * @param location location of file
		 * @return true file saved successfully
		 * @return false file was NOT saved
		 */
		bool save(const sstring &location) const;

		/**
		 * @brief Appends `this->src` at `location` in the filesystem
		 * @param location location of file
		 * @return true file appended successfully
		 * @return false file was NOT appended
		 */
		bool append_file(const char *location) const;

		/**
		 * @brief Appends `this->src` at `location` in the filesystem
		 * @param location location of file
		 * @return true file appended successfully
		 * @return false file was NOT appended
		 */
		bool append_file(const sstring &location) const;

		/**
		 * @brief Opens `location` from the filesystem and assigns it's data to `this->src` and it's length to `this->len`
		 * @param location location of file
		 * @return true if file opened successfully
		 * @return false if file was NOT opened
		 */
		bool open(const char *location);

		/**
		 * @brief Opens `location` from the filesystem and assigns it's data to `this->src` and it's length to `this->len`
		 * @param location location of file
		 * @return true if file opened successfully
		 * @return false if file was NOT opened
		 */
		bool open(const sstring &location);

		/**
		 * @brief Clears `this->src` and assigns it's value to `nullptr`
		 * @return sstring& reference to current object
		 */
		sstring &clear();

		/**
		 * Converts all characters to upper case
		 * @return sstring& reference to current object
		 */
		sstring &to_upper();

		/**
		 * Converts all characters to lower case
		 * @return sstring& reference to current object
		 */
		sstring &to_lower();

		/**
		 * Converts upper case characters to lower case and vice-versa
		 * @return sstring& reference to current object
		 */
		sstring &swap_case();

		/**
		 * @brief Converts `this->src` to binary representation
		 * @return sstring& reference to current object
		 */
		sstring &to_binary();

		/**
		 * @brief Converts binary representation to it's readable form
		 * @return sstring& reference to current object
		 */
		sstring &from_binary();

		/**
		 * Calculates the entropy using `Shannon's entropy` formula, which was introduced in his 1948 paper "A Mathematical Theory of Communication". For more information https://en.wikipedia.org/wiki/Entropy_(information_theory)
		 * @returns entropy of `this->src`
		 */
		double entropy() const;

		/**
		 * @brief Returns whether `str` is in `this->src` or not
		 * @param str string to find
		 * @return true if `str` is present;
		 * @return false if `str` was NOT present
		 */
		bool contains(const char *str) const;

		/**
		 * @brief Returns whether `str` is in `this->src` or not
		 * @param str string to find
		 * @return true if `str` is present;
		 * @return false if `str` was NOT present
		 */
		bool contains(const sstring &str) const;

		/**
		 * @brief Returns whether `c` is in `this->src` or not
		 * @param str character to find
		 * @return true if `c` is present;
		 * @return false if `c` was NOT present
		 */
		std::size_t contains_char(const char c) const;

		/**
		 * @brief Assigns `this->src` as a set, i.e., only unique characters will be present. (From Set Theory)
		 * @return sstring& reference to current object
		 */
		sstring &to_set();

		/**
		 * @brief Converts `this->src` (as string) to base 16 (as hexadecimal)
		 * @return sstring& reference to current object
		 */
		sstring &to_hexadecimal();

		/**
		 * @brief Converts `this->src` from base 16 (as hexadecimal) to string
		 * @return sstring& reference to current object
		 */
		sstring &from_hexadecimal();

		/**
		 * @brief Returns the index of first occurrence of `sub`
		 * @param sub string to find
		 * @return std::size_t index of `sub` if found, else `this->nerr()`
		 */
		std::size_t find(const char *sub) const;

		/**
		 * @brief Returns the index of first occurrence of `sub`
		 * @param sub string to find
		 * @return std::size_t index of `sub` if found, else `this->nerr()`
		 */
		std::size_t find(const sstring &sub) const;

		/**
		 * @brief Returns the index of nth occurrence of `sub`
		 * @param last_index where to start searching for `sub`
		 * @param sub string to find
		 * @return std::size_t index of `sub` if found, else `this->nerr()`
		 */
		std::size_t find_next(std::size_t last_index, const char *sub) const;

		/**
		 * @brief Returns the index of nth occurrence of `sub`
		 * @param last_index where to start searching for `sub`
		 * @param sub string to find
		 * @return std::size_t index of `sub` if found, else `this->nerr()`
		 */
		std::size_t find_next(std::size_t last_index, const sstring &sub) const;

		/**
		 * @brief Gets input from user, of any length
		 * @return sstring& reference to current object
		 */
		sstring &in();

		/**
		 * @brief Returns content of `line` from `this->src`, if `line` does not exists it returns `nullptr`.
		 * @param line line number
		 * @return sstring content of `line`, `nullptr` if `line` does NOT exists
		 */
		sstring getline(const std::size_t line) const;

		/**
		 * @brief Reverses `this->src`
		 * @return sstring& reference to current object
		 */
		sstring &reverse();

		/**
		 * @brief Removes every occurrences of `sub`
		 * @param sub string to remove
		 * @return sstring& reference to current object
		 */
		sstring &remove(const char *sub);

		/**
		 * @brief Removes every occurrences of `sub`
		 * @param sub string to remove
		 * @return sstring& reference to current object
		 */
		sstring &remove(const sstring &sub);

		/**
		 * @brief Removes every occurrences of `c`
		 * @param sub character to remove
		 * @return sstring& reference to current object
		 */
		sstring &remove_char(const char c);

		/**
		 * @brief Removes every EXTRA occurrences of `c`
		 * @param sub character to remove
		 * @return sstring& reference to current object
		 */
		sstring &remove_extra_char(const char c);

		/**
		 * @brief Removes the content between `from` and `till` inclusive
		 * @param from stating index
		 * @param till ending index
		 * @return sstring& reference to current object
		 */
		sstring &remove_range(std::size_t from, std::size_t till);

		/**
		 * @brief Assigns `this->src` the content between `from` and `till` inclusive
		 * @param from stating index
		 * @param till ending index
		 * @return sstring& reference to current object
		 */
		sstring &intersect(std::size_t from, std::size_t till);

		/**
		 * @brief Removes the first character from `this->src`
		 * @return sstring& reference to current object
		 */
		sstring &remove_first_char();

		/**
		 * @brief Removes the last character from `this->src`
		 * @return sstring& reference to current object
		 */
		sstring &remove_last_char();

		/**
		 * @brief Calculates hamming distance (From Information Theory) between two strings. NOTE: string's length should be same.
		 * @param str string to compare with
		 * @return returns `this->nerr()` if length does not match, otherwise number of characters didn't matched.
		 */
		std::size_t distance(const char *str) const;

		/**
		 * @brief Calculates hamming distance (From Information Theory) between two strings. NOTE: string's length should be same.
		 * @param str string to compare with
		 * @return returns `this->nerr()` if length does not match, otherwise number of characters didn't matched.
		 */
		std::size_t distance(const sstring &str) const;

		/**
		 * @brief Returns `Levenshtein Distance` (From Information Theory) against `str`.
		 * @param str string to be matched
		 * @return edit distance
		 */
		std::size_t edit_distance(const char *str) const;

		/**
		 * @brief Returns `Levenshtein Distance` (From Information Theory) against `str`.
		 * @param str string to be matched
		 * @return edit distance
		 */
		std::size_t edit_distance(const sstring &str) const;

		/**
		 * @brief Returns percentage matched against `str` using `Levenshtein Distance` algorithm (From Information Theory).
		 * @param str string to be matched
		 * @return percentage `this->src` matched with `str`
		 */
		double percentage_matched(const char *str) const;

		/**
		 * @brief Returns percentage matched against `str` using `Levenshtein Distance` algorithm (From Information Theory).
		 * @param str string to be matched
		 * @return percentage `this->src` matched with `str`
		 */
		double percentage_matched(const sstring &str) const;

		/**
		 * @brief Counts the number of occurrence of `what`.
		 * @param what string to count
		 * @return number of occurrence of `what`
		 */
		std::size_t count(const char *what) const;

		/**
		 * @brief Counts the number of occurrence of `what`.
		 * @param what string to count
		 * @return number of occurrence of `what`
		 */
		std::size_t count(const sstring &what) const;

		/**
		 * @brief Counts the number of occurrence of `what`.
		 * @param what character to count
		 * @return number of occurrence of `what`
		 */
		std::size_t count_char(const char what) const;

		/**
		 * @brief Encodes `this->src` to 4 characters long string which can be compared to other `soundex` returned value.
		 * @return sstring generated by this function
		 */
		sstring soundex() const;

		/**
		 * @brief Returns the most occurred string in `this->src` separated by `dl`
		 * @param dl separator string
		 * @return most occurred string
		 */
		sstring most_used(const char *dl) const;

		/**
		 * @brief Returns the most occurred string in `this->src` separated by `dl`
		 * @param dl separator string
		 * @return most occurred string
		 */
		sstring most_used(const sstring &dl) const;

		/**
		 * @brief Returns the most occurred character in `this->src`
		 * @return most occurred character
		 */
		char most_used_char() const;

		/**
		 * @brief Splits `this->src` using `str`
		 * @param str separator string
		 * @return vector of sstring separated by `str`
		 */
		vector_t<sstring> split(const char *str) const;

		/**
		 * @brief Splits `this->src` using `str`
		 * @param str separator string
		 * @return vector of sstring separated by `str`
		 */
		vector_t<sstring> split(const sstring &str) const;

		/**
		 * @brief Sorts `this->src` using `std::sort`
		 * @return sstring& reference to current object
		 */
		sstring &sort();

		/**
		 * @brief Saves the content of `this->src` to the file at `location`.
		 * @param location file to be saved
		 * @param bin_len length of the data
		 * @return true if saved
		 * @return false if was NOT saved
		 */
		bool save_binary(const char *location, std::size_t bin_len) const;

		/**
		 * @brief Appends the content of `this->src` to the file at `location`.
		 * @param location file to be appended
		 * @param bin_len length of the data
		 * @return true if appended
		 * @return false if was NOT appended
		 */
		bool append_binary(const char *location, std::size_t bin_len) const;

		/**
		 * @brief Appends the content of `data` to `this->src`
		 * @param data data to append
		 * @param bin_len length of `data`
		 * @return sstring& reference to current object
		 */
		sstring &add_binary(const char *data, std::size_t &bin_len);

		/**
		 * @brief Prints `this->len` till `len`
		 * @param bin_len length of the data
		 * @return number of character printed on `stdout`
		 */
		std::size_t print_binary(std::size_t bin_len) const;

		/**
		 * @brief Encrypts `a` using hash of `key`
		 * @param key key to encrypt
		 * @return sstring& reference to current object
		 */
		sstring &encrypt(const char *key);

		/**
		 * @brief Encrypts `a` using hash of `key`
		 * @param key key to encrypt
		 * @return sstring& reference to current object
		 */
		sstring &encrypt(const sstring &key);

		/**
		 * @brief Decrypts `a` using hash of `key`
		 * @param key key to decrypt
		 * @return sstring& reference to current object
		 */
		sstring &decrypt(const char *key);

		/**
		 * @brief Decrypts `a` using hash of `key`
		 * @param key key to decrypt
		 * @return sstring& reference to current object
		 */
		sstring &decrypt(const sstring &key);

		/**
		 * @brief Returns const iterator for beginning
		 * @return const beginning of iterator
		 */
		const char *cbegin() const;

		/**
		 * @brief Returns const iterator for ending
		 * @return const ending of iterator
		 */
		const char *cend() const;

		/**
		 * @brief Returns iterator for beginning
		 * @return beginning of iterator
		 */
		char *begin();

		/**
		 * @brief Returns iterator for ending
		 * @return ending of iterator
		 */
		char *end();

		/**
		 * @brief Returns const reverse iterator for beginning
		 * @return const reverse beginning of iterator
		 */
		const char *crbegin() const;

		/**
		 * @brief Returns const reverse iterator for ending
		 * @return const reverse ending of iterator
		 */
		const char *crend() const;

		/**
		 * @brief Returns reverse iterator for beginning
		 * @return reverse beginning of iterator
		 */
		char *rbegin();

		/**
		 * @brief Returns reverse iterator for ending
		 * @return reverse ending of iterator
		 */
		char *rend();

		/**
		 * @brief Swaps contents of current object to `__x`
		 * @param __x reference to another sstring
		 * @return sstring& reference to current object
		 */
		sstring &swap(sstring &__x) noexcept;

		/**
		 * @brief Returns content from `index` to `index` + `sub_len`
		 * @param index stating index
		 * @param sub_len length of new content
		 * @return content from `index` to `index` + `sub_len`
		 */
		sstring substr(std::size_t index, std::size_t sub_len = (std::size_t)-1) const;

		/**
		 * @brief Parses `this->src` as C-style argv in `main()` function
		 * @return arguments
		 */
		vector_t<sstring> to_argv() const;

		/**
		 * @brief Converts normal text to morse code
		 * @return sstring& reference to current object
		 */
		sstring &to_morse_code();

		/**
		 * @brief Converts morse code to normal text
		 * @return sstring& reference to current object
		 */
		sstring &from_morse_code();

		/**
		 * @brief Checks if `this->src` is only digits or not
		 * @return true if all characters are digits;
		 * @return false if NOT all characters are digits
		 */
		bool is_digit() const;

		/**
		 * @brief Checks whether `this->src` is decimal or not.
		 * @return true if `this->src` was a perfect decimal number;
		 * @return false if `this->src` was NOT a perfect decimal number
		 */
		bool is_decimal() const;

		/**
		 * @brief Checks whether all characters of `this->src` is ASCII or not.
		 * @return true if all characters were ASCII;
		 * @return false if NOT all characters were ASCII
		 */
		bool is_ascii() const;

		/**
		 * @brief Checks whether all characters of `this->src` is alphabetic or not.
		 * @return true if all characters were alphabetic;
		 * @return false if NOT all characters were alphabetic
		 */
		bool is_alphabetic() const;

		/**
		 * @brief Formats `a` according to escape sequences.
		 * @return sstring& reference to current object
		 */
		sstring &format_escape_sequence();

		/**
		 * @brief Inserts `str` into `this->src` at `index`.
		 * @param str string to insert
		 * @param index index where `str` is going to be inserted
		 * @return sstring& reference to current object
		 */
		sstring &insert(const char *str, std::size_t index);

		/**
		 * @brief Inserts `str` into `this->src` at `index`.
		 * @param str string to insert
		 * @param index index where `str` is going to be inserted
		 * @return sstring& reference to current object
		 */
		sstring &insert(const sstring &str, std::size_t index);

		/**
		 * @brief Checks if `this->src` starts with `str`
		 * @param str string to be matched
		 * @return true if `this->src` starts with `str`;
		 * @return false if `this->src` does NOT starts with `str`;
		 */
		bool starts_with(const char *str) const;

		/**
		 * @brief Checks if `this->src` starts with `str`
		 * @param str string to be matched
		 * @return true if `this->src` starts with `str`;
		 * @return false if `this->src` does NOT starts with `str`;
		 */
		bool starts_with(const sstring &str) const;

		/**
		 * @brief Checks if `this->src` ends with `str`
		 * @param str string to be matched
		 * @return true if `this->src` ends with `str`;
		 * @return false if `this->src` does NOT ends with `str`;
		 */
		bool ends_with(const char *str) const;

		/**
		 * @brief Checks if `this->src` ends with `str`
		 * @param str string to be matched
		 * @return true if `this->src` ends with `str`;
		 * @return false if `this->src` does NOT ends with `str`;
		 */
		bool ends_with(const sstring &str) const;

		/**
		 * @brief Tokenize `this->src`.
		 * @return returns tokenized vector with it's respective token
		 */
		vector_t<heap_pair<sstring, enum lexer_token>> lexer() const;

		/**
		 * @brief Converts tokens to concentrated string
		 * @param toks tokens
		 * @return sstring& reference to current object
		 */
		sstring &from_lexer(const vector_t<heap_pair<sstring, enum lexer_token>> &toks);

		/**
		 * @brief Assigns `__format__` to `this->src` with formatting.
		 * @param buffer_length length of `__format__` along with the variable length of `...`
		 * @param __format__ string containing the format instructions
		 * @param ... arguments
		 * @return sstring& reference to current object
		 */
		sstring &set_formatted(std::size_t buffer_length, const char *__format__, ...);

		/**
		 * @brief Appends `__format__` to `this->src` with formatting.
		 * @param buffer_length length of `__format__` along with the variable length of `...`
		 * @param __format__ string containing the format instructions
		 * @param ... arguments
		 * @return sstring& reference to current object
		 */
		sstring &append_formatted(std::size_t buffer_length, const char *__format__, ...);

		/**
		 * @brief Resizes `this->src` with `new_len`, no loss of previous data happens if resized successfully
		 * @param new_len new length of `this->src`
		 * @return true if resized successfully;
		 * @return false if resized failed
		 */
		bool resize(std::size_t new_len);

		/**
		 * @brief Returns hash of `this->src`
		 * @return hash of `this->src`
		 */
		std::size_t hash() const;

		/**
		 * @brief Returns character at `n` index
		 * @param n index of character
		 * @return char at `n`
		 */
		char operator[](std::size_t n) const;

		/**
		 * @brief Returns reference of character at `n` index
		 * @param n index of character
		 * @return char& at `n`
		 */
		char &operator[](std::size_t n);

		/**
		 * @brief Returns the addition of `this->src` and `c`
		 * @param c character to add
		 * @return sstring with `this->src` and `c`
		 */
		sstring operator+(const char c) const;

		/**
		 * @brief Returns the addition of `this->src` and `str`
		 * @param str string to add
		 * @return sstring with `this->src` and `str`
		 */
		sstring operator+(const char *str) const;

		/**
		 * @brief Returns the addition of `this->src` and `str`
		 * @param str sstring to add
		 * @return sstring with `this->src` and `str`
		 */
		sstring operator+(const sstring &str) const;

		/**
		 * @brief Appends `c`
		 * @param c character to append
		 * @return sstring& reference to current object
		 */
		sstring &operator+=(const char c);

		/**
		 * @brief Appends `str`
		 * @param str string to append
		 * @return sstring& reference to current object
		 */
		sstring &operator+=(const char *str);

		/**
		 * @brief Appends `str`
		 * @param str sstring to append
		 * @return sstring& reference to current object
		 */
		sstring &operator+=(const sstring &str);

		/**
		 * @brief Appends list of `char`s
		 * @param list list of `char`s
		 * @return sstring& reference to current object
		 */
		sstring &operator+=(std::initializer_list<char> list);

		/**
		 * @brief Appends list of `sstring`s
		 * @param list list of `sstring`s
		 * @return sstring& reference to current object
		 */
		sstring &operator+=(std::initializer_list<sstring> list);

		/**
		 * @brief Assigns `c`
		 * @param c character to assign
		 * @return sstring& reference to current object
		 */
		sstring &operator=(const char c);

		/**
		 * @brief Assigns `str`
		 * @param str string to assign
		 * @return sstring& reference to current object
		 */
		sstring &operator=(const char *str);

		/**
		 * @brief Copy operator
		 * @param str sstring to copy
		 * @return sstring& reference to current object
		 */
		sstring &operator=(const sstring &str);

		/**
		 * @brief Move operator
		 * @param __s sstring to move
		 * @return sstring& reference to current object
		 */
		sstring &operator=(sstring &&__s) noexcept;

		/**
		 * @brief Compares `str` to `this->src`
		 * @param str C-style null-terminated string
		 * @return true both strings are equal;
		 * @return false both string are unequal
		 */
		bool operator==(const char *str) const;

		/**
		 * @brief Compares `str` to `this->src`
		 * @param str sstring to be compared
		 * @return true both strings are equal;
		 * @return false both string are unequal
		 */
		bool operator==(const sstring &str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is less than `str`;
		 * @return false if `this->src` is greater than `str`
		 */
		bool operator<(const char *str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is less than `str`;
		 * @return false if `this->src` is greater than `str`
		 */
		bool operator<(const sstring &str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is greater than `str`;
		 * @return false if `this->src` is less than `str`
		 */
		bool operator>(const char *str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is greater than `str`;
		 * @return false if `this->src` is less than `str`
		 */
		bool operator>(const sstring &str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is less than or equal to `str`;
		 * @return false if `this->src` is greater than or equal to `str`
		 */
		bool operator<=(const char *str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is less than or equal to `str`;
		 * @return false if `this->src` is greater than or equal to `str`
		 */
		bool operator<=(const sstring &str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is greater than or equal to `str`;
		 * @return false if `this->src` is less than or equal to `str`
		 */
		bool operator>=(const char *str) const;

		/**
		 * @brief Does lexicographical comparison between `this->src` and `str`
		 * @param str string to be compared
		 * @return true if `this->src` is greater than or equal to `str`;
		 * @return false if `this->src` is less than or equal to `str`
		 */
		bool operator>=(const sstring &str) const;

		/**
		 * @brief Compares `str` to `this->src`
		 * @param str C-style null-terminated string
		 * @return true both strings are unequal;
		 * @return false both string are equal
		 */
		bool operator!=(const char *str) const;

		/**
		 * @brief Compares `str` to `this->src`
		 * @param str sstring to be compared
		 * @return true both strings are unequal;
		 * @return false both string are equal
		 */
		bool operator!=(const sstring &str) const;

		/**
		 * @brief Return value of many in-built functions when some error occurs
		 * @return (std::size_t)-1
		 */
		constexpr inline std::size_t nerr() const noexcept;

		/**
		 * @brief Prints `obj` by `std::cout`
		 * @param out reference of `std::ostream`
		 * @param obj sstring to print
		 * @return `this->src`
		 */
		friend std::ostream &operator<<(std::ostream &out, const sstring &obj);

		/**
		 * @brief Destroy the sstring object. NOTE: Calling this function explicitly can cause double-free error
		 */
		~sstring();

		/**
		 * @brief Sorts `arr`
		 * @param arr array of sstring
		 * @param len length of `arr`
		 */
		static void sort(sstring *arr, const std::size_t len);

		/**
		 * @brief Sorts `arr`
		 * @param arr array of `char *`
		 * @param len length of `arr`
		 */
		static void sort(char **arr, const std::size_t len);

		/**
		 * @brief Returns `c` as sstring
		 * @param c character to assign
		 * @return `c` as sstring
		 */
		static sstring to_sstring(char c);

		/**
		 * @brief Returns `boolean` as sstring
		 * @param boolean bool value to assign
		 * @return `boolean` as sstring
		 */
		static sstring to_sstring(bool boolean);

		/**
		 * @brief Returns `str` as sstring
		 * @param str string to assign
		 * @return `str` as sstring
		 */
		static sstring to_sstring(const char *str);

		/**
		 * @brief Returns `ptr` as sstring
		 * @param ptr pointer value
		 * @return `ptr` as sstring
		 */
		static sstring to_sstring(void *ptr);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(signed short int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(unsigned short int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(signed int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(unsigned int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(signed long int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(unsigned long int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(signed long long int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(unsigned long long int x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x decimal number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(float x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x decimal number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(double x);

		/**
		 * @brief Returns `x` as sstring
		 * @param x decimal number to assign
		 * @return `x` as sstring
		 */
		static sstring to_sstring(long double x);

		/**
		 * @brief Returns random sstring of length `len`
		 * @param len length of random sstring
		 * @return random sstring of length `len`
		 */
		static sstring get_random(const std::size_t &len);

		/**
		 * @brief Returns user input.
		 * @return user input
		 */
		static sstring get_input();

		/**
		 * @brief Returns content of file at `location` in the filesystem
		 * @param location location of file
		 * @return content of file at `location` in the filesystem
		 */
		static sstring open_file(const sstring &location);

		/**
		 * @brief Returns end line character with respect to operating system in use.
		 * @return end line character with respect to operating system in use.
		 */
		static sstring end_line();
	};

	// definitions

	sstring::sstring()
	{
		this->len = 0;
		this->src = nullptr;
	}

	sstring::sstring(const char c)
	{
		if (c != 0)
		{
			this->len = 0;
			this->src = static_cast<char *>(std::calloc(2, sizeof(char)));
			exit_heap_fail(this->src);
			this->src[this->len++] = c;
		}
		else
		{
			this->len = 0;
			this->src = nullptr;
		}
	}

	sstring::sstring(const char *str)
	{
		if (str)
		{
			this->len = 0;
			std::size_t str_len = std::strlen(str);
			this->src = static_cast<char *>(std::calloc(str_len + 1, sizeof(char)));
			exit_heap_fail(this->src);
			fast_strncat(this->src, str, this->len);
		}
		else
		{
			this->len = 0;
			this->src = nullptr;
		}
	}

	sstring::sstring(const char c, std::size_t n)
	{
		if (n != 0 && c != 0)
		{
			this->len = 0;
			this->src = static_cast<char *>(std::calloc(n + 1, sizeof(char)));
			exit_heap_fail(this->src);
			for (std::size_t i = 0; i < n; i++)
				this->src[i] = c;
			this->len = n;
		}
		else
		{
			this->len = 0;
			this->src = nullptr;
		}
	}

	sstring::sstring(const char *str, std::size_t n)
	{
		if (n != 0 && str)
		{
			this->len = 0;
			std::size_t str_len = std::strlen(str) * n;
			this->src = static_cast<char *>(std::calloc(str_len + 1, sizeof(char)));
			exit_heap_fail(this->src);
			for (std::size_t i = 0; i < n; i++)
				fast_strncat(this->src, str, this->len);
		}
		else
		{
			this->len = 0;
			this->src = nullptr;
		}
	}

	sstring::sstring(const sstring &other)
	{
		if (other.src)
		{
			this->len = 0;
			this->src = static_cast<char *>(std::calloc(other.len + 1, sizeof(char)));
			exit_heap_fail(this->src);
			fast_strncat(this->src, other.src, this->len);
		}
		else
		{
			this->len = 0;
			this->src = nullptr;
		}
	}

	sstring::sstring(sstring &&other) noexcept
	{
		this->src = other.src;
		this->len = other.len;
		other.src = nullptr;
		other.len = 0;
	}

	sstring::sstring(std::initializer_list<char> list)
	{
		this->len = 0;
		std::size_t str_len = list.size();
		this->src = static_cast<char *>(std::calloc(str_len + 1, sizeof(char)));
		exit_heap_fail(this->src);
		for (std::initializer_list<char>::const_iterator i = list.begin(); i != list.end(); i++)
		{
			if (*i != 0)
				this->src[this->len++] = *i;
		}
	}

	sstring::sstring(std::initializer_list<sstring> list)
	{
		this->len = 0;
		std::size_t str_len = 0;
		for (std::initializer_list<sstring>::const_iterator i = list.begin(); i != list.end(); i++)
			str_len += (*i).len;

		this->src = static_cast<char *>(std::calloc(str_len + 1, sizeof(char)));
		exit_heap_fail(this->src);

		for (std::initializer_list<sstring>::const_iterator i = list.begin(); i != list.end(); i++)
		{
			if ((*i).src)
			{
				for (std::size_t j = 0; j < (*i).len; j++)
					this->src[this->len++] = (*i).src[j];
			}
		}
	}

	sstring &sstring::set(const char *str)
	{
		if (str)
		{
			if (this->src)
				std::free(this->src);
			this->len = 0;
			std::size_t str_len = std::strlen(str);
			this->src = static_cast<char *>(std::calloc(str_len + 1, sizeof(char)));
			exit_heap_fail(this->src);
			fast_strncat(this->src, str, this->len);
		}
		return *this;
	}

	sstring &sstring::set(const sstring &str)
	{
		return this->set(str.src);
	}

	sstring &sstring::set_char(const char c)
	{
		if (c != 0)
		{
			if (this->src)
				std::free(this->src);
			this->src = static_cast<char *>(std::calloc(2, sizeof(char)));
			exit_heap_fail(this->src);
			this->src[this->len++] = c;
		}
		return *this;
	}

	sstring &sstring::set_upto(const char *str, std::size_t N)
	{
		if (str && (N <= std::strlen(str)))
		{
			if (this->src)
				std::free(this->src);
			this->src = static_cast<char *>(std::calloc(N + 1, sizeof(char)));
			exit_heap_fail(this->src);
			std::strncpy(this->src, str, N);
			this->len = N;
		}
		return *this;
	}

	sstring &sstring::set_upto(const sstring &str, std::size_t N)
	{
		return this->set_upto(str.src, N);
	}

	sstring &sstring::set_random(const std::size_t rnd_len)
	{
		if (rnd_len != 0)
		{
			if (this->src)
				std::free(this->src);
			this->src = static_cast<char *>(std::calloc(rnd_len + 1, sizeof(char)));
			exit_heap_fail(this->src);
			for (std::size_t i = 0; i < rnd_len; i++)
				this->src[i] = (rand() % (126 - 32 + 1)) + 32;
			this->len = rnd_len;
		}
		return *this;
	}

	sstring &sstring::set_array(const vector_t<char *> &vec, const char *between)
	{
		if (this->src)
			std::free(this->src);
		this->len = 0;

		std::size_t vec_str_len = 0, bw_len = 0;

		if (between)
			bw_len = std::strlen(between);

		for (std::size_t i = 0; i < vec.length(); i++)
		{
			if (vec[i])
				vec_str_len += std::strlen(vec[i]);
		}

		if (between)
			vec_str_len += vec.length() * bw_len;

		this->src = static_cast<char *>(std::calloc(vec_str_len + 1, sizeof(char)));
		exit_heap_fail(this->src);

		for (std::size_t i = 0; i < vec.length(); i++)
		{
			if (vec[i])
			{
				fast_strncat(this->src, vec[i], this->len);
				if (between)
					fast_strncat(this->src, between, this->len);
			}
		}
		return *this;
	}

	sstring &sstring::set_array(const vector_t<sstring> &vec, const char *between)
	{
		if (this->src)
			std::free(this->src);
		this->len = 0;

		std::size_t vec_str_len = 0, bw_len = 0;

		if (between)
			bw_len = std::strlen(between);

		for (std::size_t i = 0; i < vec.length(); i++)
		{
			if (vec[i].src)
				vec_str_len += vec[i].len;
		}

		if (between)
			vec_str_len += vec.length() * bw_len;

		this->src = static_cast<char *>(std::calloc(vec_str_len + 1, sizeof(char)));
		exit_heap_fail(this->src);

		for (std::size_t i = 0; i < vec.length(); i++)
		{
			if (vec[i].src)
			{
				fast_strncat(this->src, vec[i].src, this->len);
				if (between)
					fast_strncat(this->src, between, this->len);
			}
		}
		return *this;
	}

	char *&sstring::get()
	{
		return this->src;
	}

	const char *sstring::c_str() const
	{
		return this->src;
	}

	sstring &sstring::get_ref()
	{
		return *this;
	}

	sstring &sstring::append(const char *str)
	{
		if (str)
		{
			std::size_t str_len = std::strlen(str);
			if (this->src)
			{
				this->src = static_cast<char *>(std::realloc(this->src, this->len + str_len + 1));
				exit_heap_fail(this->src);
			}
			else
			{
				this->src = static_cast<char *>(std::calloc(str_len + 1, sizeof(char)));
				exit_heap_fail(this->src);
				this->len = 0;
			}
			fast_strncat(this->src, str, this->len);
		}
		return *this;
	}

	sstring &sstring::append(const sstring &str)
	{
		return this->append(str.src);
	}

	sstring &sstring::append_char(const char c)
	{
		if (c != 0)
		{
			if (this->src)
			{
				this->src = static_cast<char *>(std::realloc(this->src, this->len + 2));
				exit_heap_fail(this->src);
			}
			else
			{
				this->src = static_cast<char *>(std::calloc(2, sizeof(char)));
				exit_heap_fail(this->src);
				this->len = 0;
			}
			this->src[this->len++] = c;
		}
		return *this;
	}

	sstring &sstring::append_upto(const char *str, std::size_t N)
	{
		if (str && (N <= std::strlen(str)))
		{
			if (this->src)
			{
				this->src = static_cast<char *>(std::realloc(this->src, this->len + N + 1));
				exit_heap_fail(this->src);
				std::strncpy(this->src + this->len, str, N);
				this->len += N;
			}
			else
			{
				this->src = static_cast<char *>(std::calloc(N + 1, sizeof(char)));
				exit_heap_fail(this->src);
				this->len = 0;
				std::strncpy(this->src, str, N);
				this->len = N;
			}
		}
		return *this;
	}

	sstring &sstring::append_upto(const sstring &str, std::size_t N)
	{
		return this->append_upto(str.src, N);
	}

	sstring &sstring::append_start(const char *str)
	{
		if (str)
		{
			std::size_t str_len = std::strlen(str);
			if (this->src)
			{
				char *buff = static_cast<char *>(std::calloc(str_len + this->len + 1, sizeof(char)));
				exit_heap_fail(buff);
				this->len = 0;
				fast_strncat(buff, str, this->len);
				fast_strncat(buff, this->src, this->len);

				std::free(this->src);
				this->src = buff;
			}
			else
			{
				this->src = static_cast<char *>(std::calloc(str_len + 1, sizeof(char)));
				exit_heap_fail(this->src);
				this->len = 0;
				fast_strncat(this->src, str, this->len);
			}
		}
		return *this;
	}

	sstring &sstring::append_start(const sstring &str)
	{
		return this->append_start(str.src);
	}

	sstring &sstring::append_start_char(const char c)
	{
		if (c != 0)
		{
			if (this->src)
			{
				char *buff = static_cast<char *>(std::calloc(this->len + 2, sizeof(char)));
				exit_heap_fail(buff);
				this->len = 1;
				std::strncpy(buff, &c, 1);
				fast_strncat(buff, this->src, this->len);

				std::free(this->src);
				this->src = buff;
			}
			else
			{
				this->src = static_cast<char *>(std::calloc(2, sizeof(char)));
				exit_heap_fail(this->src);
				std::strncpy(this->src, &c, 1);
				this->len = 1;
			}
		}
		return *this;
	}

	sstring &sstring::append_start_upto(const char *str, std::size_t N)
	{
		if (str && (N <= std::strlen(str)))
		{
			if (this->src)
			{
				char *buff = static_cast<char *>(std::calloc(N + this->len + 1, sizeof(char)));
				exit_heap_fail(buff);
				this->len = N;
				std::strncpy(buff, str, N);
				fast_strncat(buff, this->src, this->len);

				std::free(this->src);
				this->src = buff;
			}
			else
			{
				this->src = static_cast<char *>(std::calloc(N + 1, sizeof(char)));
				exit_heap_fail(this->src);
				std::strncpy(this->src, str, N);
				this->len = N;
			}
		}
		return *this;
	}

	sstring &sstring::append_start_upto(const sstring &str, std::size_t N)
	{
		return this->append_start_upto(str.src, N);
	}

	sstring &sstring::append_array(const vector_t<char *> &vec, const char *between)
	{
		if (this->src)
		{
			std::size_t vec_str_len = 0, bw_len = 0;

			if (between)
				bw_len = std::strlen(between);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				if (vec[i])
					vec_str_len += std::strlen(vec[i]);
			}

			if (between)
				vec_str_len += vec.length() * bw_len;

			this->src = static_cast<char *>(std::realloc(this->src, this->len + vec_str_len + 1));
			exit_heap_fail(this->src);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				if (vec[i])
				{
					fast_strncat(this->src, vec[i], this->len);
					if (between)
						fast_strncat(this->src, between, this->len);
				}
			}
		}
		else
		{
			this->set_array(vec, between);
		}
		return *this;
	}

	sstring &sstring::append_array(const vector_t<sstring> &vec, const char *between)
	{
		if (this->src)
		{
			std::size_t vec_str_len = 0, bw_len = 0;

			if (between)
				bw_len = std::strlen(between);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				if (vec[i].src)
					vec_str_len += vec[i].len;
			}

			if (between)
				vec_str_len += vec.length() * bw_len;

			this->src = static_cast<char *>(std::realloc(this->src, this->len + vec_str_len + 1));
			exit_heap_fail(this->src);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				if (vec[i].src)
				{
					fast_strncat(this->src, vec[i].src, this->len);
					if (between)
						fast_strncat(this->src, between, this->len);
				}
			}
		}
		else
		{
			this->set_array(vec, between);
		}
		return *this;
	}

	sstring &sstring::append_start_array(const vector_t<char *> &vec, const char *between)
	{
		if (this->src)
		{
			std::size_t vec_str_len = 0, bw_len = 0;

			if (between)
				bw_len = std::strlen(between);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				if (vec[i])
					vec_str_len += std::strlen(vec[i]);
			}

			if (between)
				vec_str_len += vec.length() * bw_len;

			char *buff = static_cast<char *>(std::calloc(this->len + vec_str_len + 1, sizeof(char)));
			exit_heap_fail(buff);
			std::size_t track = 0;
			fast_strncat(buff, this->src, track);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				fast_strncat(buff, vec[i], track);
				if (between)
					fast_strncat(buff, between, track);
			}

			std::free(this->src);
			this->src = buff;
			this->len = track;
		}
		else
		{
			this->set_array(vec, between);
		}
		return *this;
	}

	sstring &sstring::append_start_array(const vector_t<sstring> &vec, const char *between)
	{
		if (this->src)
		{
			std::size_t vec_str_len = 0, bw_len = 0;

			if (between)
				bw_len = std::strlen(between);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				if (vec[i].src)
					vec_str_len += vec[i].len;
			}

			if (between)
				vec_str_len += vec.length() * bw_len;

			char *buff = static_cast<char *>(std::calloc(this->len + vec_str_len + 1, sizeof(char)));
			exit_heap_fail(buff);
			std::size_t track = 0;
			fast_strncat(buff, this->src, track);

			for (std::size_t i = 0; i < vec.length(); i++)
			{
				fast_strncat(buff, vec[i].src, track);
				if (between)
					fast_strncat(buff, between, track);
			}

			std::free(this->src);
			this->src = buff;
			this->len = track;
		}
		else
		{
			this->set_array(vec, between);
		}
		return *this;
	}

	bool sstring::is_empty() const
	{
		return (this->len == 0);
	}

	bool sstring::is_null() const
	{
		if (this->src)
			return false;
		return true;
	}

	sstring &sstring::replace(const char *old, const char *new_)
	{
		if (old && new_ && this->src)
		{
			vector_t<std::size_t> indexes;
			std::size_t occur = this->find(old);
			if (occur == this->nerr())
				return *this;
			indexes.add(occur);
			while (true)
			{
				occur = this->find_next(occur + 1, old);
				if (occur == this->nerr())
					break;
				indexes.add(occur);
			}

			std::size_t old_len = std::strlen(old), new_len = std::strlen(new_);

			// now we have got every points (indexes) where `old` is present

			std::size_t buff_len = this->len + (new_len * indexes.length()) - (old_len * indexes.length());
			char *buff = static_cast<char *>(std::calloc(buff_len + 1, sizeof(char)));
			exit_heap_fail(buff);

			std::size_t track = 0;
			for (std::size_t i = 0, k = 0; i < indexes.length(); i++)
			{
				for (; k < indexes[i]; track++, k++)
				{
					buff[track] = this->src[k];
				}
				k += old_len;
				fast_strncat(buff, new_, track);
			}
			fast_strncat(buff, this->src + indexes[indexes.length() - 1] + old_len, track);

			std::free(this->src);
			this->src = buff;
			this->len = track;
		}
		return *this;
	}

	sstring &sstring::replace(const sstring &old, const sstring &new_)
	{
		return this->replace(old.src, new_.src);
	}

	sstring &sstring::replace_char(const char old, const char new_)
	{
		if (old != 0 && new_ != 0 && this->src)
			for (std::size_t i = 0; this->src[i] != 0; i++)
				if (this->src[i] == old)
					this->src[i] = new_;
		return *this;
	}

	sstring &sstring::char_set(const char new_char, std::size_t nth)
	{
		if (this->len >= nth && new_char != 0 && this->src)
			this->src[nth] = new_char;
		return *this;
	}

	char sstring::char_get(std::size_t nth) const
	{
		if (this->len >= nth && this->src)
			return this->src[nth];
		else
		{
			std::fprintf(stderr, "err: out-of-range\n");
			std::exit(EXIT_FAILURE);
		}
	}

	char &sstring::char_get(std::size_t nth)
	{
		if (this->len >= nth && this->src)
			return this->src[nth];
		else
		{
			std::fprintf(stderr, "err: out-of-range\n");
			std::exit(EXIT_FAILURE);
		}
	}

	std::size_t sstring::index_of(char ch) const
	{
		if (ch != 0 && this->src)
		{
			for (std::size_t i = 0; i < this->len; i++)
				if (this->src[i] == ch)
					return i;
		}
		return this->nerr();
	}

	std::size_t sstring::last_index_of(char ch) const
	{
		if (ch != 0 && this->src)
		{
			for (std::size_t i = this->len - 1; i != (std::size_t)-1; i--)
				if (this->src[i] == ch)
					return i;
		}
		return this->nerr();
	}

	const std::size_t &sstring::length() const
	{
		return this->len;
	}

	std::size_t &sstring::change_length(std::size_t new_length)
	{
		this->len = new_length;
		return this->len;
	}

	bool sstring::compare(const char *T1) const
	{
		if (T1 && this->src)
			if (std::strcmp(this->src, T1) == 0)
				return true;
		return false;
	}

	bool sstring::compare(const sstring &T1) const
	{
		return this->compare(T1.src);
	}

	bool sstring::compare_upto(const char *T1, std::size_t N) const
	{
		if (T1 && this->src)
			if (std::strncmp(this->src, T1, N) == 0)
				return true;
		return false;
	}

	bool sstring::compare_upto(const sstring &T1, std::size_t N) const
	{
		return this->compare_upto(T1.src, N);
	}

	bool sstring::is_changed(sstring &obj)
	{
		// CASE 1: nullptr
		if (this->src == nullptr && obj.src == nullptr)
			return true;
		else if (this->src == nullptr && obj.src != nullptr)
			return false;
		else if (this->src != nullptr && obj.src == nullptr)
			return false;
		else
		{
			// now both src are not nullptr
			// CASE 2: length compare
			if (this->len != obj.len)
				return false;
			else
			{
				// now both src have equal length
				// CASE 3: text compare
				return this->compare(obj.src);
			}
		}
	}

	int sstring::lexicographical_comparison(const char *str) const
	{
		if (!this->src)
			return this->len - std::strlen(str);
		std::size_t str_len = 0;
		for (std::size_t i = 0; this->src[i] && str[str_len]; i++, str_len++)
		{
			if (this->src[i] == str[i])
				continue;
			return (int)this->src[i] - (int)str[i];
		}
		return this->len - str_len;
	}

	int sstring::lexicographical_comparison(const sstring &str) const
	{
		return this->lexicographical_comparison(str.src);
	}

	std::size_t sstring::print(bool add_next_line, const char *__format__, ...) const
	{
		if (!this->src)
			return 0;
		std::size_t LEN = 0;
		if (__format__)
		{
			std::va_list ar;
			va_start(ar, __format__);
			LEN += std::printf("%s", this->src);
			LEN += std::vprintf(__format__, ar);
			va_end(ar);
		}
		else
			LEN += printf("%s", this->src);
		if (add_next_line)
		{
#if defined __linux__ || defined linux || defined __linux
			std::printf("\n");
#elif _WIN32 || defined _WIN64 || defined __CYGWIN__
			std::printf("\r\n");
#elif defined __unix__ || defined __unix || defined unix
			std::printf("\n");
#elif defined __APPLE__ || defined __MACH__
			std::printf("\n");
#elif defined __FreeBSD__
			std::printf("\n");
#elif defined __ANDROID__
			std::printf("\n");
#endif
		}
		fflush(stdout);
		return LEN;
	}

	bool sstring::save(const char *location) const
	{
		if (location && this->src)
		{
			std::FILE *f = std::fopen(location, "wb");
			if (f != nullptr)
			{
				std::fwrite(this->src, this->len, sizeof(char), f);
				std::fclose(f);
				return true;
			}
		}
		return false;
	}

	bool sstring::save(const sstring &location) const
	{
		return this->save(location.src);
	}

	bool sstring::append_file(const char *location) const
	{
		if (location && this->src)
		{
			std::FILE *f = std::fopen(location, "ab");
			if (f != nullptr)
			{
				std::fwrite(this->src, this->len, sizeof(char), f);
				std::fclose(f);
				return true;
			}
		}
		return false;
	}

	bool sstring::append_file(const sstring &location) const
	{
		return this->append_file(location.src);
	}

	bool sstring::open(const char *location)
	{
		if (location)
		{
			std::FILE *f = std::fopen(location, "rb");
			if (f)
			{
				std::fseek(f, 0, SEEK_END);
				std::size_t file_len = std::ftell(f);
				std::fseek(f, 0, SEEK_SET);
				if (this->src)
					std::free(this->src);
				this->src = static_cast<char *>(std::calloc(file_len + 1, sizeof(char)));
				exit_heap_fail(this->src);
				std::fread(this->src, file_len, sizeof(char), f);
				std::fclose(f);
				this->len = file_len;
				return true;
			}
		}
		return false;
	}

	bool sstring::open(const sstring &location)
	{
		return this->open(location.src);
	}

	sstring &sstring::clear()
	{
		if (this->src)
			std::free(this->src);
		this->src = nullptr;
		this->len = 0;
		return *this;
	}

	sstring &sstring::to_upper()
	{
		if (this->src)
		{
			for (std::size_t i = 0; this->src[i] != 0; ++i)
			{
				if (this->src[i] <= 122 && this->src[i] >= 97)
					this->src[i] -= 32;
			}
		}
		return *this;
	}

	sstring &sstring::to_lower()
	{
		if (this->src)
		{
			for (std::size_t i = 0; this->src[i] != 0; ++i)
			{
				if (this->src[i] <= 90 && this->src[i] >= 65)
					this->src[i] += 32;
			}
		}
		return *this;
	}

	sstring &sstring::swap_case()
	{
		if (this->src)
		{
			for (std::size_t i = 0; this->src[i] != 0; ++i)
			{
				if (this->src[i] <= 90 && this->src[i] >= 65)
					this->src[i] += 32;
				else if (this->src[i] <= 122 && this->src[i] >= 97)
					this->src[i] -= 32;
			}
		}
		return *this;
	}

	sstring &sstring::to_binary()
	{
		if (this->src)
		{
			std::size_t size = 0;
			char *buff = static_cast<char *>(std::calloc((9 * this->len) + 1, sizeof(char)));
			exit_heap_fail(buff);

			for (std::size_t i = 0; i < this->len; ++i)
			{
				fast_strncat(buff, binary_data[(std::size_t)this->src[i]], size);
				if (i < this->len - 1)
					fast_strncat(buff, " ", size);
			}
			std::free(this->src);
			this->src = buff;
			this->len = size;
		}
		return *this;
	}

	sstring &sstring::from_binary()
	{
		if (this->src)
		{
			char *buff = static_cast<char *>(std::calloc((this->len / 9) + 1, sizeof(char)));
			exit_heap_fail(buff);

			char bin[9] = {}, store[2] = {};
			std::size_t z = 0;
			for (std::size_t i = 0, j = 0; i < this->len; ++i, ++j)
			{
				if (this->src[i] == ' ')
				{
					store[0] = std::strtol(bin, nullptr, 2);
					fast_strncat(buff, store, z);
					j = 0;
				}
				if (i == this->len - 1)
				{
					bin[j] = this->src[i]; // append last character
					store[0] = std::strtol(bin, nullptr, 2);
					fast_strncat(buff, store, z);
				}
				bin[j] = this->src[i];
			}

			std::free(this->src);
			this->src = buff;
			this->len = z;
		}
		return *this;
	}

	double sstring::entropy() const
	{
		if (this->src)
		{
			const std::size_t MAX = 1 << CHAR_BIT;
			std::size_t frequencies[MAX] = {};
			for (const char *p = this->src; *p != 0; p++)
			{
				frequencies[*p - CHAR_MIN] += 1;
			}

			double result = 0;
			for (std::size_t i = 0; i < MAX; i++)
			{
				if (frequencies[i] != 0)
				{
					double freq = (double)frequencies[i] / (double)this->len;
					result -= freq * (log(freq) / log(2.0));
				}
			}
			return result;
		}
		return -1;
	}

	bool sstring::contains(const char *str) const
	{
		if (str && this->src)
			if (fast_strstr(this->src, this->len, str) != nullptr)
				return true;
		return false;
	}

	bool sstring::contains(const sstring &str) const
	{
		return this->contains(str.src);
	}

	std::size_t sstring::contains_char(const char c) const
	{
		if (c != 0 && this->src)
		{
			for (std::size_t i = 0; this->src[i] != 0; i++)
				if (this->src[i] == c)
					return i;
		}
		return this->nerr();
	}

	sstring &sstring::to_set()
	{
		if (this->src)
		{
			const std::size_t MAX = 1 << CHAR_BIT;
			std::size_t frequencies[MAX] = {};

			for (const char *p = this->src; *p != 0; p++)
			{
				frequencies[*p - CHAR_MIN] += 1;
			}

			char *buff = static_cast<char *>(calloc(MAX, sizeof(char)));
			exit_heap_fail(buff);
			std::size_t z = 0;
			for (size_t i = 0; i < MAX; i++)
			{
				if (frequencies[i] != 0)
					buff[z++] = i + CHAR_MIN;
			}
			std::free(this->src);
			this->src = buff;
			this->len = z;
		}
		return *this;
	}

	sstring &sstring::to_hexadecimal()
	{
		if (this->src)
		{
			char *buff = static_cast<char *>(std::calloc((this->len * 2) + 1, sizeof(char)));
			exit_heap_fail(buff);

			std::size_t i = 0, j = 0;
			while (this->src[i] != 0)
			{
				std::sprintf(buff + j, "%02X", this->src[i]);
				i++, j += 2;
			}
			std::free(this->src);
			this->src = buff;
			this->len = j;
		}
		return *this;
	}

	sstring &sstring::from_hexadecimal()
	{
		if (this->src)
		{
			char *buff = static_cast<char *>(std::calloc((this->len / 2) + 1, sizeof(char)));
			exit_heap_fail(buff);

			char hex[3] = {}, store[2] = {};
			std::size_t z = 0;
			for (std::size_t i = 0, j = 0; i < len; ++i)
			{
				if (i == len - 1)
				{
					hex[j] = this->src[i];
					store[0] = std::strtol(hex, nullptr, 16);
					fast_strncat(buff, store, z);
				}
				if (j == 2)
				{
					j = 0;
					store[0] = std::strtol(hex, nullptr, 16);
					fast_strncat(buff, store, z);
				}
				hex[j] = this->src[i];
				j++;
			}

			std::free(this->src);
			this->src = buff;
			this->len = z;
		}
		return *this;
	}

	std::size_t sstring::find(const char *sub) const
	{
		if (sub && this->src)
		{
			char *buff = fast_strstr(this->src, this->len, sub);
			if (buff)
				return this->len - std::strlen(buff);
		}
		return this->nerr();
	}

	std::size_t sstring::find(const sstring &sub) const
	{
		return this->find(sub.src);
	}

	std::size_t sstring::find_next(std::size_t last_index, const char *sub) const
	{
		if (sub && this->src)
		{
			char *buff = fast_strstr(this->src + last_index, this->len - last_index, sub);
			if (buff)
				return this->len - std::strlen(buff);
		}
		return this->nerr();
	}

	std::size_t sstring::find_next(std::size_t last_index, const sstring &sub) const
	{
		return this->find_next(last_index, sub.src);
	}

	sstring &sstring::in()
	{
		if (this->src)
			std::free(this->src);

		std::size_t cap = 64, len_input = 0;
		char ch;
		this->src = static_cast<char *>(std::calloc(cap, sizeof(char)));
		exit_heap_fail(this->src);

		while ((ch = std::getchar()))
		{
			if (ch == 10 || ch == 0 || ch == EOF)
				break;
			this->src[len_input++] = ch;
			if (len_input == cap)
			{
				cap += 64;
				this->src = static_cast<char *>(std::realloc(this->src, cap));
				exit_heap_fail(this->src);
			}
		}
		this->src[len_input] = 0;
		this->len = len_input;
		return *this;
	}

	sstring sstring::getline(const std::size_t line) const
	{
		if (!this->src)
			return sstring();

		std::size_t cnt = 0;
		char *temp = static_cast<char *>(std::calloc(len + 1, sizeof(char)));
		exit_heap_fail(temp);

		std::strncpy(temp, this->src, this->len);
		char *tok = std::strtok(temp, "\n");
		while (tok)
		{
			if (cnt++ == line)
				break;
			tok = std::strtok(nullptr, "\n");
		}
		if (cnt == 0 || tok == nullptr)
		{
			std::free(temp);
			return sstring();
		}
		sstring res = sstring(tok);
		std::free(temp);
		return std::move(res);
	}

	sstring &sstring::reverse()
	{
		if (this->src)
		{
			for (std::size_t i = 0; i < this->len / 2; i++)
			{
				char c = this->src[i];
				this->src[i] = this->src[this->len - i - 1];
				this->src[this->len - i - 1] = c;
			}
		}
		return *this;
	}

	sstring &sstring::remove(const char *sub)
	{
		if (sub && sub[0] != 0 && this->src)
		{
			vector_t<std::size_t> indexes;
			std::size_t occur = this->find(sub);
			if (occur == this->nerr())
				return *this;
			indexes.add(occur);
			while (true)
			{
				occur = this->find_next(occur + 1, sub);
				if (occur == this->nerr())
					break;
				indexes.add(occur);
			}

			std::size_t sub_len = std::strlen(sub);
			// now we have all indexes where sub has occurred

			std::size_t buff_len = this->len - (sub_len * indexes.length());
			char *buff = static_cast<char *>(std::calloc(buff_len + 1, sizeof(char)));
			exit_heap_fail(buff);

			std::size_t track = 0;
			for (std::size_t i = 0, k = 0; i < indexes.length(); i++)
			{
				for (; k < indexes[i]; track++, k++)
				{
					buff[track] = this->src[k];
				}
				k += sub_len;
			}
			fast_strncat(buff, this->src + indexes[indexes.length() - 1] + sub_len, track);

			std::free(this->src);
			this->src = buff;
			this->len = track;
		}
		return *this;
	}

	sstring &sstring::remove(const sstring &sub)
	{
		return this->remove(sub.src);
	}

	sstring &sstring::remove_char(const char c)
	{
		if (c != 0 && this->src)
		{
			std::size_t z = this->count_char(c);
			char *buff = static_cast<char *>(std::calloc(this->len - z + 1, sizeof(char)));
			exit_heap_fail(buff);

			std::size_t buff_len = 0;
			for (std::size_t i = 0; this->src[i] != 0; i++)
			{
				if (this->src[i] != c)
					buff[buff_len++] = this->src[i];
			}

			std::free(this->src);
			this->src = buff;
			this->len = buff_len;
		}
		return *this;
	}

	sstring &sstring::remove_extra_char(const char c)
	{
		if (c != 0 && this->src)
		{
			char *buff = static_cast<char *>(std::calloc(this->len + 1, sizeof(char)));
			exit_heap_fail(buff);

			std::size_t p = 0, i = 0;
			while (this->src[p] != 0)
			{
				if (!(this->src[p] == c && this->src[p + 1] == c))
					buff[i++] = this->src[p];
				p++;
			}
			std::free(this->src);
			this->src = buff;
			this->len = i;
		}
		return *this;
	}

	sstring &sstring::remove_range(std::size_t from, std::size_t till)
	{
		if (!this->src)
			return *this;
		if (till > this->len || from > this->len || from > till || till == from)
			return *this;
		char *buff = static_cast<char *>(std::calloc(this->len - (till - from) + 1, sizeof(char)));
		exit_heap_fail(buff);

		std::size_t k = 0;
		for (std::size_t i = 0; i < this->len; i++)
		{
			if (i == from)
				i = till + 1;
			buff[k++] = this->src[i];
		}

		std::free(this->src);
		this->src = buff;
		this->len = k;
		return *this;
	}

	sstring &sstring::intersect(std::size_t from, std::size_t till)
	{
		if (!this->src)
			return *this;
		if (till > this->len || from > this->len || from > till || till == from)
			return *this;
		char *buff = static_cast<char *>(std::calloc(till - from + 1, sizeof(char)));
		exit_heap_fail(buff);

		std::size_t k = 0;
		for (std::size_t i = from; i <= till; i++)
			buff[k++] = this->src[i];

		std::free(this->src);
		this->src = buff;
		this->len = k;
		return *this;
	}

	sstring &sstring::remove_first_char()
	{
		if (!this->src)
			return *this;
		if (this->src[0] == 0)
			return *this;

		char *buff = static_cast<char *>(std::calloc(this->len, sizeof(char)));
		exit_heap_fail(buff);

		std::size_t z = 0;
		for (std::size_t i = 1; i < this->len; i++)
			buff[z++] = this->src[i];

		std::free(this->src);
		this->src = buff;
		this->len = z;
		return *this;
	}

	sstring &sstring::remove_last_char()
	{
		if (!this->src)
			return *this;
		this->src[this->len - 1] = 0;
		this->len--;
		return *this;
	}

	std::size_t sstring::distance(const char *str) const
	{
		if (str && this->src)
		{
			if (std::strlen(src) == this->len)
			{
				std::size_t cnt = 0;
				for (std::size_t i = 0; this->src[i] != 0; i++)
					if (this->src[i] != str[i])
						cnt++;
				return cnt;
			}
		}
		return this->nerr();
	}

	std::size_t sstring::distance(const sstring &str) const
	{
		return this->distance(str.src);
	}

	std::size_t sstring::edit_distance(const char *str) const
	{
		if (str && this->src)
		{
			std::size_t len_str = std::strlen(src), x, y, last, old;
			std::size_t *cols = static_cast<std::size_t *>(std::calloc(this->len + 1, sizeof(std::size_t)));
			exit_heap_fail(cols);
			for (y = 1; y <= this->len; y++)
				cols[y] = y;
			for (x = 1; x <= len_str; x++)
			{
				cols[0] = x;
				for (y = 1, last = x - 1; y <= this->len; y++)
				{
					old = cols[y];
					cols[y] = ((cols[y] + 1) < (cols[y - 1] + 1) ? ((cols[y] + 1) < (last + (this->src[y - 1] == src[x - 1] ? 0 : 1)) ? (cols[y] + 1) : (last + (this->src[y - 1] == src[x - 1] ? 0 : 1))) : ((cols[y - 1] + 1) < (last + (this->src[y - 1] == src[x - 1] ? 0 : 1)) ? (cols[y - 1] + 1) : (last + (this->src[y - 1] == src[x - 1] ? 0 : 1))));
					last = old;
				}
			}
			std::size_t r = cols[this->len];
			std::free(cols);
			return r;
		}
		return this->nerr();
	}

	std::size_t sstring::edit_distance(const sstring &str) const
	{
		return this->edit_distance(str.src);
	}

	double sstring::percentage_matched(const char *str) const
	{
		if (str && this->src)
		{
			std::size_t len_str = std::strlen(src), x, y, last, old;
			std::size_t *cols = static_cast<std::size_t *>(std::calloc(this->len + 1, sizeof(std::size_t)));
			exit_heap_fail(cols);
			for (y = 1; y <= this->len; y++)
				cols[y] = y;
			for (x = 1; x <= len_str; x++)
			{
				cols[0] = x;
				for (y = 1, last = x - 1; y <= this->len; y++)
				{
					old = cols[y];
					cols[y] = ((cols[y] + 1) < (cols[y - 1] + 1) ? ((cols[y] + 1) < (last + (this->src[y - 1] == src[x - 1] ? 0 : 1)) ? (cols[y] + 1) : (last + (this->src[y - 1] == src[x - 1] ? 0 : 1))) : ((cols[y - 1] + 1) < (last + (this->src[y - 1] == src[x - 1] ? 0 : 1)) ? (cols[y - 1] + 1) : (last + (this->src[y - 1] == src[x - 1] ? 0 : 1))));
					last = old;
				}
			}
			std::size_t max = ((this->len > len_str) ? this->len : len_str);
			std::size_t r = cols[this->len];
			std::free(cols);
			return (max - r) * 100.0L / max;
		}
		return -1;
	}

	double sstring::percentage_matched(const sstring &str) const
	{
		return this->percentage_matched(str.src);
	}

	std::size_t sstring::count(const char *what) const
	{
		if (what && this->src)
		{
			std::size_t cnt = 0, len = std::strlen(what);
			const char *sub = this->src;
			while ((sub = fast_strstr(sub, std::strlen(sub), what)))
			{
				cnt++;
				sub += len;
			}
			return cnt;
		}
		return 0;
	}

	std::size_t sstring::count(const sstring &what) const
	{
		return this->count(what.src);
	}

	std::size_t sstring::count_char(const char what) const
	{
		if (what != 0 && this->src)
		{
			std::size_t cnt = 0;
			for (std::size_t i = 0; this->src[i] != 0; i++)
				if (this->src[i] == what)
					cnt++;
			return cnt;
		}
		return 0;
	}

	sstring sstring::soundex() const
	{
		if (this->src)
		{
			std::size_t s = 1;
			const char *map = "01230120022455012623010202"; // not stored in heap memory, do not free it
			char c;
			char res[5] = {};
			res[0] = std::toupper(this->src[0]);
			for (std::size_t i = 1; i < this->len; ++i)
			{
				c = std::toupper(this->src[i]) - 65;
				if (c >= 0 && c <= 25) // from ASCII table
				{
					if (map[(std::size_t)c] != 0)
					{
						if (map[(std::size_t)c] != res[s - 1])
						{
							res[s] = map[(std::size_t)c];
							s++;
						}
						if (s > 3)
							break;
					}
				}
			}
			if (s <= 3)
			{
				while (s <= 3)
				{
					res[s] = '0';
					s++;
				}
			}
			return sstring(res);
		}
		return sstring();
	}

	sstring sstring::most_used(const char *dl) const
	{
		if (dl && this->src && dl[0] != 0)
		{
			vector_t<sstring> vec = this->split(dl);
			map_t<sstring, std::size_t> map;
			for (std::size_t i = 0; i < vec.length(); i++)
			{
				if (map.add(vec[i], 1) == false)
				{
					map[vec[i]] += 1;
				}
			}

			map.sort_values([](node_t<sstring, std::size_t> x, node_t<sstring, std::size_t> y)
							{ return x.value > y.value; });

			sstring ret;
			for (map_t<sstring, std::size_t>::iter i = map.iterator(); i.c_loop(); i.next())
			{
				ret.set(i->key.c_str());
				break;
			}
			return std::move(ret);
		}
		return sstring();
	}

	sstring sstring::most_used(const sstring &dl) const
	{
		return this->most_used(dl.src);
	}

	char sstring::most_used_char() const
	{
		if (this->src)
		{
			const std::size_t MAX = 1 << CHAR_BIT;
			std::size_t frequencies[MAX] = {};

			for (const char *p = this->src; *p != 0; p++)
			{
				frequencies[*p - CHAR_MIN] += 1;
			}

			std::size_t nth = 0;
			for (std::size_t i = 1, max = frequencies[0]; i < MAX; i++)
			{
				if (frequencies[i] > max)
				{
					max = frequencies[i];
					nth = i;
				}
			}
			return (char)(nth + CHAR_MIN);
		}
		return 0;
	}

	vector_t<sstring> sstring::split(const char *str) const
	{
		if (this->src && str && str[0] != 0)
		{
			if (!this->contains(str))
				return vector_t<sstring>(1);

			char *temp = static_cast<char *>(std::calloc(this->len + 1, sizeof(char)));
			exit_heap_fail(temp);
			std::strncpy(temp, this->src, this->len);
			char *tok = std::strtok(temp, str);
			vector_t<sstring> x;
			while (tok)
			{
				x.add(tok);
				tok = std::strtok(nullptr, str);
				if (!tok)
					break;
			}
			std::free(temp);
			return std::move(x);
		}
		return vector_t<sstring>(1);
	}

	vector_t<sstring> sstring::split(const sstring &str) const
	{
		return this->split(str.src);
	}

	sstring &sstring::sort()
	{
		if (this->src)
			std::sort(this->src, this->src + this->len, [](char c1, char c2)
					  { return c1 - c2; });
		return *this;
	}

	bool sstring::save_binary(const char *location, std::size_t bin_len) const
	{
		if (location && this->src)
		{
			std::FILE *f = std::fopen(location, "wb");
			if (f != nullptr)
			{
				std::fwrite(this->src, bin_len, sizeof(char), f);
				std::fclose(f);
				return true;
			}
		}
		return false;
	}

	bool sstring::append_binary(const char *location, std::size_t bin_len) const
	{
		if (location && this->src)
		{
			std::FILE *f = std::fopen(location, "ab");
			if (f != nullptr)
			{
				std::fwrite(this->src, bin_len, sizeof(char), f);
				std::fclose(f);
				return true;
			}
		}
		return false;
	}

	sstring &sstring::add_binary(const char *data, std::size_t &bin_len)
	{
		if (data)
		{
			if (!this->src)
			{
				this->len = 0;
				this->src = static_cast<char *>(std::calloc(bin_len + 1, sizeof(char)));
				exit_heap_fail(this->src);
				fast_strncat(this->src, data, this->len);
				return *this;
			}
			this->src = static_cast<char *>(std::realloc(this->src, this->len + bin_len + 1));
			exit_heap_fail(this->src);
			fast_strncat(this->src, data, this->len);
		}
		return *this;
	}

	std::size_t sstring::print_binary(std::size_t bin_len) const
	{
		if (!this->src)
			return 0;
		std::size_t x = 0;
		while (x != bin_len)
			std::printf("%c", this->src[x++]);
		return x;
	}

	sstring &sstring::encrypt(const char *key)
	{
		if (key && this->src)
		{
			std::size_t val = std::hash<const char *>()(key) % 128;
			bool add = true;

			char *buff = static_cast<char *>(std::calloc(this->len + 1, sizeof(char)));
			exit_heap_fail(buff);

			for (std::size_t i = 0; this->src[i] != 0; i++)
			{
				if (add == true && this->src[i] + val > 0)
				{
					buff[i] = this->src[i] + val;
					add = false;
				}
				else if (add == false && this->src[i] - val > 0)
				{
					buff[i] = this->src[i] - val;
					add = true;
				}
				else
				{
					std::free(buff);
					return *this;
				}
			}

			std::free(this->src);
			this->src = buff; // now this->len does not changes
		}
		return *this;
	}

	sstring &sstring::encrypt(const sstring &key)
	{
		return this->encrypt(key.src);
	}

	sstring &sstring::decrypt(const char *key)
	{
		if (key && this->src)
		{
			std::size_t val = std::hash<const char *>()(key) % 128;
			bool add_invr = true;

			char *buff = static_cast<char *>(std::calloc(this->len + 1, sizeof(char)));
			exit_heap_fail(buff);

			for (std::size_t i = 0; this->src[i] != 0; i++)
			{
				if (add_invr == true && this->src[i] + val > 0)
				{
					buff[i] = this->src[i] - val;
					add_invr = false;
				}
				else if (add_invr == false && this->src[i] - val > 0)
				{
					buff[i] = this->src[i] + val;
					add_invr = true;
				}
				else
				{
					std::free(buff);
					return *this;
				}
			}

			std::free(this->src);
			this->src = buff; // now this->len does not changes
		}
		return *this;
	}

	sstring &sstring::decrypt(const sstring &key)
	{
		return this->decrypt(key.src);
	}

	const char *sstring::cbegin() const
	{
		if (this->src)
			return this->src;
		return nullptr;
	}

	const char *sstring::cend() const
	{
		if (this->src)
			return this->src + this->len;
		return nullptr;
	}

	char *sstring::begin()
	{
		if (this->src)
			return this->src;
		return nullptr;
	}

	char *sstring::end()
	{
		if (this->src)
			return this->src + this->len;
		return nullptr;
	}

	const char *sstring::crbegin() const
	{
		if (this->src)
			return this->src + this->len;
		return nullptr;
	}

	const char *sstring::crend() const
	{
		if (this->src)
			return this->src;
		return nullptr;
	}

	char *sstring::rbegin()
	{
		if (this->src)
			return this->src + this->len;
		return nullptr;
	}

	char *sstring::rend()
	{
		if (this->src)
			return this->src;
		return nullptr;
	}

	sstring &sstring::swap(sstring &__x) noexcept
	{
		char *temp = this->src;
		this->src = __x.src;
		__x.src = temp;

		std::size_t temp_len = this->len;
		this->len = __x.len;
		__x.len = temp_len;

		return *this;
	}

	sstring sstring::substr(std::size_t index, std::size_t sub_len) const
	{
		if (index >= this->len || !this->src)
			return sstring();
		if (sub_len == this->nerr() || index + sub_len > this->len)
			sub_len = this->len - index;
		char *buff = static_cast<char *>(std::calloc(sub_len + 1, sizeof(char)));
		exit_heap_fail(buff);

		strncpy(buff, this->src + index, sub_len);

		sstring ret;
		ret.src = buff;
		ret.len = sub_len;
		return std::move(ret);
	}

	vector_t<sstring> sstring::to_argv() const
	{
		if (!this->src)
			return vector_t<sstring>(1);

		vector_t<sstring> spt = this->split(" ");
		vector_t<sstring> args;
		for (std::size_t i = 0; i < spt.length();)
		{
			if (spt[i][0] == '"')
			{
				sstring temp;
				for (; spt[i][spt[i].len - 1] != '"' && i < spt.length(); i++)
					temp.append(spt[i] + " ");
				temp.append(spt[i++]).remove_first_char().remove_last_char();
				args.add(temp);
			}
			else
				args.add(spt[i++]);
		}
		return std::move(args);
	}

	sstring &sstring::to_morse_code()
	{
		if (!this->src)
			return *this;
		for (std::size_t i = 0; i < this->len; i++)
			if (!std::isdigit((unsigned char)this->src[i]) && !std::isalpha((unsigned char)this->src[i]) && this->src[i] != ' ')
				return *this;

		char *buff = static_cast<char *>(std::calloc((this->len * 8) + 1, sizeof(char)));
		exit_heap_fail(buff);
		std::size_t track = 0;

		for (std::size_t i = 0; i < this->len; i++)
		{
			if (std::isdigit((unsigned char)this->src[i]))
				fast_strncat(buff, morse_code[(std::size_t)this->src[i] - 48].code, track);
			else if (this->src[i] == ' ')
				fast_strncat(buff, morse_code[36].code, track);
			else
			{
				if (this->src[i] >= 65 && this->src[i] <= 90)
					fast_strncat(buff, morse_code[(std::size_t)this->src[i] - 55].code, track);
				else
					fast_strncat(buff, morse_code[(std::size_t)this->src[i] - 87].code, track);
			}
			if (i < this->len - 1)
				fast_strncat(buff, " ", track);
		}

		std::free(this->src);
		this->src = buff;
		this->len = track;
		return *this;
	}

	sstring &sstring::from_morse_code()
	{
		if (!this->src)
			return *this;
		for (std::size_t i = 0; i < this->len; i++)
		{
			switch (this->src[i])
			{
			case '-':
			case '.':
			case ' ':
				break;
			default:
				return *this;
			}
		}

		char *buff = static_cast<char *>(std::calloc(this->len + 1, sizeof(char)));
		exit_heap_fail(buff);
		char temp[9] = {}, arr[2] = {};

		std::size_t track = 0, x = 0;
		for (std::size_t i = 0, k = 0; i < this->len; i++, k++)
		{
			if (i == this->len - 1)
			{
				x = 0;
				temp[k] = this->src[i];
				while ((std::strcmp(temp, morse_code[x].code)) != 0)
					x++;
				arr[0] = morse_code[x].character;
				fast_strncat(buff, arr, track);
			}
			if (this->src[i] == ' ')
			{
				i++, x = 0;
				while ((std::strcmp(temp, morse_code[x].code)) != 0)
					x++;
				arr[0] = morse_code[x].character;
				fast_strncat(buff, arr, track);
				memset(temp, 0, 8);
				k = 0;
			}
			temp[k] = this->src[i];
		}
		std::free(this->src);
		this->src = buff;
		this->len = track;
		return *this;
	}

	bool sstring::is_digit() const
	{
		if (this->src)
		{
			for (std::size_t i = 0; i < this->len; i++)
				if (!std::isdigit((unsigned int)this->src[i]))
					return false;
			return true;
		}
		return false;
	}

	bool sstring::is_decimal() const
	{
		if (this->src)
		{
			std::size_t point_cnt = 0;
			for (std::size_t i = 0; i < this->len; i++)
			{
				if (this->src[i] == 46)
				{
					point_cnt++;
					if (point_cnt > 1)
						return false;
				}
				else if (!std::isdigit((unsigned int)this->src[i]))
					return false;
			}
			if (point_cnt == 1)
				return true;
		}
		return false;
	}

	bool sstring::is_ascii() const
	{
		if (this->src)
		{
			for (std::size_t i = 0; i < this->len; i++)
				if (this->src[i] <= 0 || this->src[i] >= 127)
					return false;
			return true;
		}
		return false;
	}

	bool sstring::is_alphabetic() const
	{
		if (this->src)
		{
			for (std::size_t i = 0; i < this->len; i++)
				if (!std::isalpha((unsigned int)this->src[i]))
					return false;
			return true;
		}
		return false;
	}

	sstring &sstring::format_escape_sequence()
	{
		this->replace("\\", "\\\\");
		this->replace("\a", "\\a");
		this->replace("\b", "\\b");
		this->replace("\f", "\\f");
		this->replace("\n", "\\n");
		this->replace("\r", "\\r");
		this->replace("\t", "\\t");
		this->replace("\v", "\\v");
		this->replace("\"", "\\\"");
		this->replace("\'", "\\\'");
		this->replace("\?", "\\\?");
		return *this;
	}

	sstring &sstring::insert(const char *str, std::size_t index)
	{
		if (str && this->src && index <= this->len)
		{
			std::size_t str_len = std::strlen(str);
			this->src = static_cast<char *>(std::realloc(this->src, this->len + str_len + 1));
			exit_heap_fail(this->src);

			for (std::size_t i = this->len; i >= index; i--)
			{
				this->src[i + str_len] = this->src[i];
				this->src[i] = 0;
				if (i == 0)
					break;
			}
			std::memcpy(this->src + index, str, str_len);
			this->len += str_len;
		}
		return *this;
	}

	sstring &sstring::insert(const sstring &str, std::size_t index)
	{
		return this->insert(str.src, index);
	}

	bool sstring::starts_with(const char *str) const
	{
		if (str && this->src)
		{
			if (std::strlen(str) > this->len)
				return false;
			for (std::size_t i = 0; str[i] != 0 && this->src[i] != 0; i++)
				if (this->src[i] != str[i])
					return false;
			return true;
		}
		return false;
	}

	bool sstring::starts_with(const sstring &str) const
	{
		return this->starts_with(str.src);
	}

	bool sstring::ends_with(const char *str) const
	{
		if (str && this->src)
		{
			std::size_t str_len = std::strlen(str);
			if (str_len > this->len)
				return false;
			for (std::size_t i = this->len - str_len, z = 0; str[z] != 0 && this->src[i] != 0; i++, z++)
				if (this->src[i] != str[z])
					return false;
			return true;
		}
		return false;
	}

	bool sstring::ends_with(const sstring &str) const
	{
		return this->ends_with(str.src);
	}

	vector_t<heap_pair<sstring, enum lexer_token>> sstring::lexer() const
	{
		vector_t<heap_pair<sstring, enum lexer_token>> vec;
		sstring toks;
		for (std::size_t i = 0; i < this->len;)
		{
			if ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
			{
				toks.clear();
				while ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
					toks.append_char(this->src[i++]);
				vec.add({toks, lexer_token::WORD});
			}
			else if (this->src[i] == 32)
			{
				toks.clear();
				toks.append_char(this->src[i++]);
				vec.add({toks, lexer_token::WHITESPACE});
			}
			else if (std::isdigit((unsigned char)this->src[i]))
			{
				toks.clear();
				while (std::isdigit((unsigned char)this->src[i]))
					toks.append_char(this->src[i++]);
				vec.add({toks, lexer_token::INTEGER});
			}
			else if (this->src[i] == '\\' || this->src[i] == '\a' || this->src[i] == '\b' || this->src[i] == '\f' || this->src[i] == '\n' || this->src[i] == '\r' || this->src[i] == '\t' || this->src[i] == '\v' || this->src[i] == '\"' || this->src[i] == '\'' || this->src[i] == '\?')
			{
				toks.clear();
				while (this->src[i] == '\\' || this->src[i] == '\a' || this->src[i] == '\b' || this->src[i] == '\f' || this->src[i] == '\n' || this->src[i] == '\r' || this->src[i] == '\t' || this->src[i] == '\v' || this->src[i] == '\"' || this->src[i] == '\'' || this->src[i] == '\?')
				{
					toks.clear();
					toks.set_char(this->src[i++]);
					vec.add({toks, lexer_token::ESC_SEQ});
				}
			}
			else if ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
			{
				toks.clear();
				while ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
				{
					toks.clear();
					toks.set_char(this->src[i++]);
					vec.add({toks, lexer_token::SPECIAL_CHAR});
				}
			}
			else
				return vector_t<heap_pair<sstring, enum lexer_token>>(1);
		}
		vec.add({sstring("\0"), lexer_token::NULL_END});
		return std::move(vec);
	}

	sstring &sstring::from_lexer(const vector_t<heap_pair<sstring, enum lexer_token>> &toks)
	{
		if (toks.length() != 0)
		{
			if (this->src)
				std::free(this->src);
			this->len = 0;

			std::size_t buff_len = 0;
			for (std::size_t i = 0; i < toks.length(); i++)
				buff_len += toks[i].first().len;

			this->src = static_cast<char *>(std::calloc(buff_len + 1, sizeof(char)));
			exit_heap_fail(this->src);

			for (std::size_t i = 0; i < toks.length(); i++)
				fast_strncat(this->src, toks[i].first().src, this->len);
		}
		return *this;
	}

	sstring &sstring::set_formatted(std::size_t buffer_length, const char *__format__, ...)
	{
		if (!__format__)
			return *this;

		char *buff = static_cast<char *>(std::calloc(buffer_length + 1, sizeof(char)));
		exit_heap_fail(buff);

		std::va_list ar;
		va_start(ar, __format__);
		std::vsnprintf(buff, buffer_length, __format__, ar);
		va_end(ar);

		if (this->src)
			std::free(this->src);

		this->src = buff;
		this->len = std::strlen(buff);
		return *this;
	}

	sstring &sstring::append_formatted(std::size_t buffer_length, const char *__format__, ...)
	{
		if (!__format__)
			return *this;

		char *buff = static_cast<char *>(std::calloc(buffer_length + 1, sizeof(char)));
		exit_heap_fail(buff);

		std::va_list ar;
		va_start(ar, __format__);
		std::vsnprintf(buff, buffer_length, __format__, ar);
		va_end(ar);

		if (!this->src)
		{
			this->src = buff;
			this->len = std::strlen(buff);
		}
		else
			this->append(buff);
		return *this;
	}

	bool sstring::resize(std::size_t new_len)
	{
		if (new_len > 0)
		{
			if (this->src)
				this->src = static_cast<char *>(realloc(this->src, new_len));
			else
				this->src = static_cast<char *>(std::calloc(new_len, sizeof(char)));
			exit_heap_fail(this->src);
			return true;
		}
		return false;
	}

	std::size_t sstring::hash() const
	{
		std::size_t p = 53;
		std::size_t m = 1e9 + 9;
		long long power_of_p = 1;
		long long hash_val = 0;

		for (std::size_t i = 0; i < this->len; i++)
		{
			hash_val = (hash_val + (this->src[i] - 97 + 1) * power_of_p) % m;
			power_of_p = (power_of_p * p) % m;
		}
		return (hash_val % m + m) % m;
	}

	char sstring::operator[](std::size_t n) const
	{
		if (this->len >= n && this->src)
			return this->src[n];
		else
		{
			std::fprintf(stderr, "err: out-of-range\n");
			std::exit(EXIT_FAILURE);
		}
	}

	char &sstring::operator[](std::size_t n)
	{
		if (this->len >= n && this->src)
			return this->src[n];
		else
		{
			std::fprintf(stderr, "err: out-of-range\n");
			std::exit(EXIT_FAILURE);
		}
	}

	sstring sstring::operator+(const char c) const
	{
		sstring x = sstring(this->src);
		x.append_char(c);
		return std::move(x);
	}

	sstring sstring::operator+(const char *str) const
	{
		sstring x = sstring(this->src);
		x.append(str);
		return std::move(x);
	}

	sstring sstring::operator+(const sstring &str) const
	{
		sstring x = sstring(this->src);
		x.append(str.src);
		return std::move(x);
	}

	sstring &sstring::operator+=(const char c)
	{
		return this->append_char(c);
	}

	sstring &sstring::operator+=(const char *str)
	{
		return this->append(str);
	}

	sstring &sstring::operator+=(const sstring &str)
	{
		return this->append(str.src);
	}

	sstring &sstring::operator+=(std::initializer_list<char> list)
	{
		for (auto &i : list)
			this->append_char(i);
		return *this;
	}

	sstring &sstring::operator+=(std::initializer_list<sstring> list)
	{
		for (auto &i : list)
			this->append(i.src);
		return *this;
	}

	sstring &sstring::operator=(const char c)
	{
		return this->set_char(c);
	}

	sstring &sstring::operator=(const char *str)
	{
		return this->set(str);
	}

	sstring &sstring::operator=(const sstring &str)
	{
		if (this != &str)
			return this->set(str.src);
		return *this;
	}

	sstring &sstring::operator=(sstring &&__s) noexcept
	{
		if (this != &__s)
		{
			if (this->src)
				std::free(this->src);
			this->len = __s.len;
			this->src = __s.src;
			__s.src = nullptr;
			__s.len = 0;
		}
		return *this;
	}

	bool sstring::operator==(const char *str) const
	{
		return this->compare(str);
	}

	bool sstring::operator==(const sstring &str) const
	{
		return this->compare(str.src);
	}

	bool sstring::operator<(const char *str) const
	{
		if (this->lexicographical_comparison(str) < 0)
			return true;
		return false;
	}

	bool sstring::operator<(const sstring &str) const
	{
		if (this->lexicographical_comparison(str.src) < 0)
			return true;
		return false;
	}

	bool sstring::operator>(const char *str) const
	{
		if (this->lexicographical_comparison(str) > 0)
			return true;
		return false;
	}

	bool sstring::operator>(const sstring &str) const
	{
		if (this->lexicographical_comparison(str.src) > 0)
			return true;
		return false;
	}

	bool sstring::operator<=(const char *str) const
	{
		if (this->lexicographical_comparison(str) <= 0)
			return true;
		return false;
	}

	bool sstring::operator<=(const sstring &str) const
	{
		if (this->lexicographical_comparison(str.src) <= 0)
			return true;
		return false;
	}

	bool sstring::operator>=(const char *str) const
	{
		if (this->lexicographical_comparison(str) >= 0)
			return true;
		return false;
	}

	bool sstring::operator>=(const sstring &str) const
	{
		if (this->lexicographical_comparison(str.src) >= 0)
			return true;
		return false;
	}

	bool sstring::operator!=(const char *str) const
	{
		return !(this->compare(str));
	}

	bool sstring::operator!=(const sstring &str) const
	{
		return !(this->compare(str.src));
	}

	constexpr inline std::size_t sstring::nerr() const noexcept
	{
		return (std::size_t)-1;
	}

	std::ostream &operator<<(std::ostream &out, const sstring &obj)
	{
		out << obj.src;
		return out;
	}

	sstring::~sstring()
	{
		if (this->src)
			std::free(this->src);
		this->src = nullptr;
		this->len = 0;
	}

	void sstring::sort(sstring *arr, const std::size_t len)
	{
		std::sort(arr, arr + len);
	}

	void sstring::sort(char **arr, const std::size_t len)
	{
		std::sort(arr, arr + len, [](char *a, char *b)
				  { return sstring(a) < sstring(b); });
	}

	sstring sstring::to_sstring(char c)
	{
		sstring x;
		x.set_char(c);
		return std::move(x);
	}

	sstring sstring::to_sstring(bool boolean)
	{
		sstring x;
		if (boolean)
			x = "true";
		else
			x = "false";
		return std::move(x);
	}

	sstring sstring::to_sstring(const char *str)
	{
		sstring x = str;
		return std::move(x);
	}

	sstring sstring::to_sstring(void *ptr)
	{
		char s[std::numeric_limits<std::size_t>::digits + 1] = {};
		std::snprintf(s, std::numeric_limits<std::size_t>::digits + 1, "%p", ptr);
		return sstring(s);
	}

	sstring sstring::to_sstring(signed short int x)
	{
		char s[std::numeric_limits<signed short int>::digits + 2] = {};
		std::snprintf(s, std::numeric_limits<signed short int>::digits + 2, "%hi", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(unsigned short int x)
	{
		char s[std::numeric_limits<unsigned short int>::digits + 1] = {};
		std::snprintf(s, std::numeric_limits<unsigned short int>::digits + 1, "%hu", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(signed int x)
	{
		char s[std::numeric_limits<signed int>::digits + 2] = {};
		std::snprintf(s, std::numeric_limits<signed int>::digits + 2, "%d", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(unsigned int x)
	{
		char s[std::numeric_limits<unsigned int>::digits + 1] = {};
		std::snprintf(s, std::numeric_limits<unsigned int>::digits + 1, "%i", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(signed long int x)
	{
		char s[std::numeric_limits<signed long int>::digits + 2] = {};
		std::snprintf(s, std::numeric_limits<signed long int>::digits + 2, "%ld", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(unsigned long int x)
	{
		char s[std::numeric_limits<unsigned long int>::digits + 1] = {};
		std::snprintf(s, std::numeric_limits<unsigned long int>::digits + 1, "%lu", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(signed long long int x)
	{
		char s[std::numeric_limits<signed long long int>::digits + 2] = {};
		std::snprintf(s, std::numeric_limits<signed long long int>::digits + 2, "%lld", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(unsigned long long int x)
	{
		char s[std::numeric_limits<unsigned long long int>::digits + 1] = {};
		std::snprintf(s, std::numeric_limits<unsigned long long int>::digits + 1, "%llu", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(float x)
	{
		char s[std::numeric_limits<float>::digits + 2] = {};
		std::snprintf(s, std::numeric_limits<float>::digits + 2, "%f", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(double x)
	{
		char s[std::numeric_limits<double>::digits + 2];
		std::snprintf(s, std::numeric_limits<double>::digits + 2, "%lf", x);
		return sstring(s);
	}

	sstring sstring::to_sstring(long double x)
	{
		char s[std::numeric_limits<long double>::digits + 2];
		std::snprintf(s, std::numeric_limits<long double>::digits + 2, "%Lf", x);
		return sstring(s);
	}

	sstring sstring::get_random(const std::size_t &len)
	{
		sstring x;
		x.set_random(len);
		return std::move(x);
	}

	sstring sstring::get_input()
	{
		sstring x;
		x.in();
		return std::move(x);
	}

	sstring sstring::open_file(const sstring &location)
	{
		sstring x;
		x.open(location.c_str());
		return std::move(x);
	}

	sstring sstring::end_line()
	{
#if defined __linux__ || defined linux || defined __linux
		return sstring("\n");
#elif _WIN32 || defined _WIN64 || defined __CYGWIN__
		return sstring("\r\n");
#elif defined __unix__ || defined __unix || defined unix
		return sstring("\n");
#elif defined __APPLE__ || defined __MACH__
		return sstring("\n");
#elif defined __FreeBSD__
		return sstring("\n");
#elif defined __ANDROID__
		return sstring("\n");
#else
		return sstring("\n");
#endif
	}
}

namespace std
{
	template <>
	struct hash<openutils::sstring>
	{
		std::size_t operator()(const openutils::sstring &str) const
		{
			return str.hash();
		}
	};
};

#endif
