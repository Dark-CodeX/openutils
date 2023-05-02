/**
 * This header file is written to manage string data safely under C++ programming language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/sstring.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "sstring.hh" under "sstring" directory
 * sstring: version 2.7.7
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

#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <openutils/heap-pair/heap-pair.hh>
#include <openutils/vector/vector.hh>
#include <ostream>

#define sstring_version "2.7.7"

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

    /**
     * @brief This function converts <char_type> to <another_char_type>, where `char_type` could be `char`, `unsigned char`, `wchar_t`, `char8_t`, `char16_t` and `char32_t`.
     * @brief NOTE: Information may lose.
     * @tparam TO returning `char_type`
     * @tparam FROM converting `char_type`
     */
    template <typename TO, typename FROM>
    class convert_sstring
    {
      private:
        TO *src;
        std::size_t len;

      public:
        convert_sstring();
        convert_sstring(const FROM *str);
        convert_sstring(FROM c);
        convert_sstring(const convert_sstring &cs);
        convert_sstring(convert_sstring &&cs) noexcept;

        const std::size_t &length() const;
        const TO *get() const;
        convert_sstring &set(const FROM *str);
        convert_sstring &set(FROM c);

        convert_sstring &operator=(const convert_sstring &cs);
        convert_sstring &operator=(convert_sstring &&cs) noexcept;

        ~convert_sstring();
    };

#ifndef LEXER_TOKEN_DEFINED
#define LEXER_TOKEN_DEFINED
    enum lexer_token
    {
        WORD,
        INTEGER,
        ESC_SEQ,
        SPECIAL_CHAR,
        WHITESPACE,
        NULL_END
    };
#endif

    /**
     * @brief sstring_t_view for using same class for every character data type. NOTE: Every data type ends at 0 or NULL
     * @tparam T char, unsigned char, wchar_t, char8_t, char16_t and char32_t
     */
    template <typename T>
    class sstring_t_view
    {
      private:
        T *src;
        std::size_t len;
        template <typename TO, typename FROM>
        friend class convert_sstring;

        /**
         * Linear time complexity = O(n), where n is the length of `src`. NOTE: `dest` must have enough space for `src`.
         * @param dest string where `src` is going to append
         * @param src string to be appended
         * @param size where to append `src`
         */
        static inline void fast_strncat(T *dest, const T *src, std::size_t &size);

        /**
         * @brief Searches and returns the first occurrence of `needle` in `haystack`.
         * @brief Time comeplexity of this function is O(m + n), where m is the length of `haystack` and n is the length of `needle`.
         * @brief This function uses the Knuth-Morris-Pratt or KMP algorithm, for more information visit: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm#
         * @param haystack string to search for the substring
         * @param haystack_len length of `haystack`
         * @param needle substring to search for within `haystack`
         * @return If `needle` is found within `haystack`, it returns a pointer to the first occurrence of `needle` in `haystack`, else if `needle` is not found, it returns nullptr
         */
        static inline T *fast_strstr(const T *haystack, std::size_t haystack_len, const T *needle) noexcept(true);

        /**
         * @brief Initialize zero of every character between `from_where` and `till_move` in `ptr`, this function is generally used after `std::realloc()` to initialize the pointer with zeroes.
         * @param ptr string to initialize zeroes
         * @param from_where starting index
         * @param till_where ending index
         */
        static inline void init_n_zeroes(T *ptr, std::size_t from_where, std::size_t till_where);

        /**
         * @brief Compares both string.
         * @param str1 string to compare
         * @param str2 string to compare
         * @return 0 if both strings were equal
         */
        static inline int sstr_strcmp(const T *str1, const T *str2);

        /**
         * @brief Compares both string till `n`.
         * @param str1 string to compare
         * @param str2 string to compare
         * @param n compare both strings till `n`
         * @return 0 if both strings were equal till `n`
         */
        static inline int sstr_strncmp(const T *str1, const T *str2, std::size_t n);

        /**
         * @brief Returns the length of `str`. NOTE: make sure `str` is null-terminated
         * @param str string
         * @return length of `str`
         */
        static inline std::size_t sstr_strlen(const T *str);

        /**
         * @brief Divide `str` into tokens separated by characters in `delim`.
         * @param str string to tokenize
         * @param delim separator
         * @param delim_length separator's length
         * @return separated string
         */
        static inline T *fast_strtok(T *str, const T *delim, std::size_t delim_length);

      public:
        /**
         * @brief Default constructor of sstring_t_view, it assigns nullptr to src and 0 to len
         */
        sstring_t_view();

        /**
         * @brief Assigns `c`.
         * @param c character to assign
         */
        sstring_t_view(const T c);

        /**
         * @brief Assigns `str`
         * @param str string
         */
        sstring_t_view(const T *str);

        /**
         * @brief Assigns character between `ptr_begin` and `ptr_end`
         * @param ptr_begin starting pointer
         * @param ptr_end ending pointer
         */
        sstring_t_view(T *ptr_begin, T *ptr_end);

        /**
         * @brief Assigns `c`, `n` times
         * @param c character to assign
         * @param n number of times `c` has to be repeated
         */
        sstring_t_view(const T c, std::size_t n);

        /**
         * @brief Assigns `str`, `n` times
         * @param str string
         * @param n number of times `str` has to be repeated
         */
        sstring_t_view(const T *str, std::size_t n);

        /**
         * @brief Copy constructor for sstring_t_view
         * @param other another sstring_t_view object
         */
        sstring_t_view(const sstring_t_view<T> &other);

        /**
         * @brief Move constructor for sstring_t_view
         * @param other another sstring_t_view object
         */
        sstring_t_view(sstring_t_view<T> &&other) noexcept;

        /**
         * @brief Assigns list of characters
         * @param list list of characters
         */
        sstring_t_view(const std::initializer_list<T> &list);

        /**
         * @brief Assigns list of `sstring_t_view`s
         * @param list list of `sstring_t_view`s
         */
        sstring_t_view(const std::initializer_list<sstring_t_view> &list);

        /**
         * @brief Assigns `str`
         * @param str string
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set(const T *str);

        /**
         * @brief Assigns `str`
         * @param str sstring_t_view to assign
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set(const sstring_t_view<T> &str);

        /**
         * @brief Assigns `c`
         * @param c character to assign
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set_char(const T c);

        /**
         * @brief Assigns `str` upto `N`
         * @param str string
         * @param N number of character that has to be assigned
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set_upto(const T *str, std::size_t N);

        /**
         * @brief Assigns `str` upto `N`
         * @param str sstring_t_view to assign
         * @param N number of character that has to be assigned
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set_upto(const sstring_t_view<T> &str, std::size_t N);

        /**
         * @brief Assigns random characters
         * @param rnd_len length of random characters
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set_random(std::size_t rnd_len);

        /**
         * @brief Assigns `vec` with `between` between each iteration
         * @param vec vector of `T *` that has to be assigned
         * @param between if `nullptr` then, nothing is added between each iteration
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set_array(const vector_t<T *> &vec, const T *between = nullptr);

        /**
         * @brief Assigns `vec` with `between` between each iteration
         * @param vec vector of sstring_t_view that has to be assigned
         * @param between if `nullptr` then, nothing is added between each iteration
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set_array(const vector_t<sstring_t_view<T>> &vec, const T *between = nullptr);

        /**
         * @brief Returns `this->src` by reference, and it can be modified [UNSAFE]
         * NOTE: In case of modification, the new string must to stored on heap memory.
         * @return reference to `this->src`
         */
        T *&get();

        /**
         * @brief Returns `this->src` as `const T *`
         * @return const T* of `this->src`
         */
        const T *c_str() const;

        /**
         * @brief Get the reference of the current object
         * @return sstring_t_view& `*this`
         */
        sstring_t_view<T> &get_ref();

        /**
         * @brief Get the pointer to the current object
         * @return sstring_t_view* `this`
         */
        sstring_t_view<T> *get_ptr();

        /**
         * @brief Appends `str`
         * @param str string
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append(const T *str);

        /**
         * @brief Appends `str`
         * @param str sstring_t_view to append
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append(const sstring_t_view<T> &str);

        /**
         * @brief Appends `c`
         * @param c character to append
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_char(const T c);

        /**
         * @brief Appends `str` upto `N`
         * @param str string
         * @param N number of character that has to be appended
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_upto(const T *str, std::size_t N);

        /**
         * @brief Appends `str` upto `N`
         * @param str sstring_t_view to append
         * @param N number of character that has to be appended
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_upto(const sstring_t_view<T> &str, std::size_t N);

        /**
         * @brief Appends `str` at index 0
         * @param str string
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_start(const T *str);

        /**
         * @brief Appends `str` at index 0
         * @param str sstring_t_view to append
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_start(const sstring_t_view<T> &str);

        /**
         * @brief Appends `c` at index 0
         * @param c character to append
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_start_char(const T c);

        /**
         * @brief Appends `str` upto `N` at index 0
         * @param str string
         * @param N number of character that has to be appended
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_start_upto(const T *str, std::size_t N);

        /**
         * @brief Appends `str` upto `N` at index 0
         * @param str sstring_t_view to append
         * @param N number of character that has to be appended
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_start_upto(const sstring_t_view<T> &str, std::size_t N);

        /**
         * @brief Appends `vec` with `between` between each iteration
         * @param vec vector of `T *` that has to be assigned
         * @param between if `nullptr` then, nothing is added between each iteration
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_array(const vector_t<T *> &vec, const T *between = nullptr);

        /**
         * @brief Appends `vec` with `between` between each iteration
         * @param vec vector of sstring_t_view that has to be assigned
         * @param between if `nullptr` then, nothing is added between each iteration
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_array(const vector_t<sstring_t_view<T>> &vec, const T *between = nullptr);

        /**
         * @brief Appends `vec` with `between` between each iteration at index 0
         * @param vec vector of `T *` that has to be assigned
         * @param between if `nullptr` then, nothing is added between each iteration
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_start_array(const vector_t<T *> &vec, const T *between = nullptr);

        /**
         * @brief Appends `vec` with `between` between each iteration at index 0
         * @param vec vector of sstring_t_view that has to be assigned
         * @param between if `nullptr` then, nothing is added between each iteration
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_start_array(const vector_t<sstring_t_view<T>> &vec, const T *between = nullptr);

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
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &replace(const T *old, const T *new_);

        /**
         * @brief Replaces `old` with `new_`
         * @param old what to replace
         * @param new_ replace with
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &replace(const sstring_t_view<T> &old, const sstring_t_view<T> &new_);

        /**
         * @brief Replaces the content at line `line_no` with `new_` only
         * @param line_no line number NOTE: line index starts from 0
         * @param new_ replace with
         * @return sstring_t_view<T>& reference to current object
         */
        sstring_t_view<T> &replace_line(std::size_t line_no, const T *new_);

        /**
         * @brief Replaces the content at line `line_no` with `new_` only
         * @param line_no line number NOTE: line index starts from 0
         * @param new_ replace with
         * @return sstring_t_view<T>& reference to current object
         */
        sstring_t_view<T> &replace_line(std::size_t line_no, const sstring_t_view<T> &new_);

        /**
         * @brief Replaces `old` with `new_`
         * @param old what to replace
         * @param new_ replace with
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &replace_char(const T old, const T new_);

        /**
         * @brief Changes character at `nth` with `new_char`
         * @param new_char new character
         * @param nth index of old character
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &char_set(const T new_char, std::size_t nth);

        /**
         * @brief Returns character at `nth` index
         * @param nth index of character
         * @return character at `nth`
         */
        const T &char_get(std::size_t nth) const;

        /**
         * @brief Returns reference of character at `nth` index
         * @param nth index of character
         * @return character reference at `nth`
         */
        T &char_get(std::size_t nth);

        /**
         * @brief Returns the index of `ch` from starting
         * @param ch character to find
         * @return std::size_t index of `ch` if found, else `this->nerr()`
         */
        std::size_t index_of(T ch) const;

        /**
         * @brief Returns the index of `ch` from ending
         * @param ch character to find
         * @return std::size_t index of `ch` if found, else `this->nerr()`
         */
        std::size_t last_index_of(T ch) const;

        /**
         * @brief Returns the length of `this->src` without using `this->strlen()`, it is done by keeping track in every function
         * @return const std::size_t& returns the length of `this->src`
         */
        const std::size_t &length() const;

        /**
         * @brief Changes `this->len` to `new_length` [UNSAFE]
         * @param new_length new length that has to be assigned
         * @return sstring_t_view& reference to current object
         */
        const std::size_t &change_length(std::size_t new_length);

        /**
         * @brief Compares `T1` to `this->src`
         * @param T1 string
         * @return true both strings are equal;
         * @return false both string are unequal
         */
        bool compare(const T *T1) const;

        /**
         * @brief Compares `T1` to `this->src`
         * @param T1 sstring_t_view to be compared
         * @return true both strings are equal;
         * @return false both string are unequal
         */
        bool compare(const sstring_t_view<T> &T1) const;

        /**
         * @brief Compares `T1` to `this->src` upto `N`
         * @param T1 string
         * @param N number to character that has to be compared
         * @return true both strings are equal upto `N`;
         * @return false both string are unequal upto `N`
         */
        bool compare_upto(const T *T1, std::size_t N) const;

        /**
         * @brief Compares `T1` to `this->src` upto `N`
         * @param T1 sstring_t_view to be compared
         * @param N number to character that has to be compared
         * @return true both strings are equal upto `N`;
         * @return false both string are unequal upto `N`
         */
        bool compare_upto(const sstring_t_view<T> &T1, std::size_t N) const;

        /**
         * @brief Tells whether `*this` object changed after a function was called
         * @param obj return value of that function
         * @return true changed;
         * @return false not changed
         */
        bool is_changed(sstring_t_view<T> &obj);

        /**
         * @brief A lexicographical comparison is the kind of comparison generally used to sort strings alphabetically.
         * @param str string to compare with
         * @return difference between ASCII characters or if starting of both the strings are same then it returns the difference between the length, otherwise 0 is returned if strings are equal
         */
        int lexicographical_comparison(const T *str) const;

        /**
         * @brief A lexicographical comparison is the kind of comparison generally used to sort strings alphabetically.
         * @param str sstring_t_view to compare with
         * @return difference between ASCII characters or if starting of both the strings are same then it returns the difference between the length, otherwise 0 is returned if strings are equal
         */
        int lexicographical_comparison(const sstring_t_view<T> &str) const;

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
        bool save(const sstring_t_view<char> &location) const;

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
        bool append_file(const sstring_t_view<char> &location) const;

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
        bool open(const sstring_t_view<char> &location);

        /**
         * @brief Clears `this->src` and assigns it's value to `nullptr`
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &clear();

        /**
         * @brief Converts all characters to upper case
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &to_upper();

        /**
         * @brief Converts all characters to lower case
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &to_lower();

        /**
         * @brief Converts upper case characters to lower case and vice-versa
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &swap_case();

        /**
         * @brief Calculates the entropy using `Shannon's entropy` formula, which was introduced in his 1948 paper "A Mathematical Theory of Communication". For more information https://en.wikipedia.org/wiki/Entropy_(information_theory)
         * @returns entropy of `this->src`
         */
        double entropy() const;

        /**
         * @brief Password entropy is a measurement of how unpredictable a password is.
         * | Entropy Value Range | Strength       |
         * | ------------------- | -------------- |
         * | 0 - 28              | Very Weak      |
         * | 29 - 35             | Weak           |
         * | 36 - 59             | Medium         |
         * | 60 - 127            | Strong         |
         * | 128 - ...           | Very Strong    |
         * @return password entropy
         */
        double password_entropy() const;

        /**
         * @brief Returns whether `str` is in `this->src` or not
         * @param str string to find
         * @return true if `str` is present;
         * @return false if `str` was NOT present
         */
        bool contains(const T *str) const;

        /**
         * @brief Returns whether `str` is in `this->src` or not
         * @param str string to find
         * @return true if `str` is present;
         * @return false if `str` was NOT present
         */
        bool contains(const sstring_t_view<T> &str) const;

        /**
         * @brief Returns whether `c` is in `this->src` or not
         * @param str character to find
         * @return true if `c` is present;
         * @return false if `c` was NOT present
         */
        std::size_t contains_char(const T c) const;

        /**
         * @brief Assigns `this->src` as a set, i.e., only unique characters will be present. (From Set Theory)
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &to_set();

        /**
         * @brief Returns the index of first occurrence of `sub`
         * @param sub string to find
         * @return std::size_t index of `sub` if found, else `this->nerr()`
         */
        std::size_t find(const T *sub) const;

        /**
         * @brief Returns the index of first occurrence of `sub`
         * @param sub string to find
         * @return std::size_t index of `sub` if found, else `this->nerr()`
         */
        std::size_t find(const sstring_t_view<T> &sub) const;

        /**
         * @brief Returns the index of last occurrence of `sub`
         * @param sub string to find
         * @return std::size_t index of `sub` if found, else `this->nerr()`
         */
        std::size_t rfind(const T *sub) const;

        /**
         * @brief Returns the index of last occurrence of `sub`
         * @param sub string to find
         * @return std::size_t index of `sub` if found, else `this->nerr()`
         */
        std::size_t rfind(const sstring_t_view<T> &sub) const;

        /**
         * @brief Returns the index of nth occurrence of `sub`
         * @param last_index where to start searching for `sub`
         * @param sub string to find
         * @return std::size_t index of `sub` if found, else `this->nerr()`
         */
        std::size_t find_next(std::size_t last_index, const T *sub) const;

        /**
         * @brief Returns the index of nth occurrence of `sub`
         * @param last_index where to start searching for `sub`
         * @param sub string to find
         * @return std::size_t index of `sub` if found, else `this->nerr()`
         */
        std::size_t find_next(std::size_t last_index, const sstring_t_view<T> &sub) const;

        /**
         * @brief Gets input from user, of any length
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &in();

        /**
         * @brief Returns content of `line` from `this->src`, if `line` does not exists it returns `nullptr`.
         * @param line line number NOTE: line index starts from 0
         * @return sstring_t_view content of `line`, `nullptr` if `line` does NOT exists
         */
        sstring_t_view getline(std::size_t line) const;

        /**
         * @brief Adds content of `prefix` and `suffix` at starting and ending respectively and returns a new sstring
         * @param prefix string to add at starting
         * @param suffix string to add at ending
         * @return sstring_t_view<T> wraped sstring
         */
        sstring_t_view<T> wrap(const T *prefix, const T *suffix) const;

        /**
         * @brief Adds content of `prefix` and `suffix` at starting and ending respectively and returns a new sstring
         * @param prefix string to add at starting
         * @param suffix string to add at ending
         * @return sstring_t_view<T> wraped sstring
         */
        sstring_t_view<T> wrap(const sstring_t_view<T> &prefix, const sstring_t_view<T> &suffix) const;

        /**
         * @brief Adds content of `str` at beginning and ending and returns a new sstring
         * @param str string to add at beginning and ending
         * @return sstring_t_view<T> wraped sstring
         */
        sstring_t_view<T> wrap(const T *str) const;

        /**
         * @brief Adds content of `str` at beginning and ending and returns a new sstring
         * @param str string to add at beginning and ending
         * @return sstring_t_view<T> wraped sstring
         */
        sstring_t_view<T> wrap(const sstring_t_view<T> &str) const;

        /**
         * @brief Centers content of current object and returns a new sstring
         * @param col_size size of column
         * @param padding text to be used as padding, if `nullptr` is given " " is used as padding
         * @return sstring_t_view<T> centered string with content of current object
         */
        sstring_t_view<T> center(std::size_t col_size, const T *padding = nullptr) const;

        /**
         * @brief Centers content of current object and returns a new sstring
         * @param col_size size of column
         * @param padding text to be used as padding, if `nullptr` is given " " is used as padding
         * @return sstring_t_view<T> centered string with content of current object
         */
        sstring_t_view<T> center(std::size_t col_size, const sstring_t_view<T> &padding = nullptr) const;

        /**
         * @brief Reverses `this->src`
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &reverse();

        /**
         * @brief Removes every occurrences of `sub`
         * @param sub string to remove
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &remove(const T *sub);

        /**
         * @brief Removes every occurrences of `sub`
         * @param sub string to remove
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &remove(const sstring_t_view<T> &sub);

        /**
         * @brief Removes every occurrences of `c`
         * @param sub character to remove
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &remove_char(const T c);

        /**
         * @brief Removes every EXTRA occurrences of `c`
         * @param sub character to remove
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &remove_extra_char(const T c);

        /**
         * @brief Removes the content between `from` and `till` inclusive
         * @param from stating index
         * @param till ending index
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &remove_range(std::size_t from, std::size_t till);

        /**
         * @brief Assigns `this->src` the content between `from` and `till` inclusive
         * @param from stating index
         * @param till ending index
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &intersect(std::size_t from, std::size_t till);

        /**
         * @brief Removes the first character from `this->src`
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &remove_first_char();

        /**
         * @brief Removes the last character from `this->src`
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &remove_last_char();

        /**
         * @brief Calculates hamming distance (From Information Theory) between two strings. NOTE: string's length should be same.
         * @param str string to compare with
         * @return returns `this->nerr()` if length does not match, otherwise number of characters didn't matched.
         */
        std::size_t distance(const T *str) const;

        /**
         * @brief Calculates hamming distance (From Information Theory) between two strings. NOTE: string's length should be same.
         * @param str string to compare with
         * @return returns `this->nerr()` if length does not match, otherwise number of characters didn't matched.
         */
        std::size_t distance(const sstring_t_view<T> &str) const;

        /**
         * @brief Returns `Levenshtein Distance` (From Information Theory) against `str`.
         * @param str string to be matched
         * @return edit distance
         */
        std::size_t edit_distance(const T *str) const;

        /**
         * @brief Returns `Levenshtein Distance` (From Information Theory) against `str`.
         * @param str string to be matched
         * @return edit distance
         */
        std::size_t edit_distance(const sstring_t_view<T> &str) const;

        /**
         * @brief Returns percentage matched against `str` using `Levenshtein Distance` algorithm (From Information Theory).
         * @param str string to be matched
         * @return percentage `this->src` matched with `str`
         */
        double percentage_matched(const T *str) const;

        /**
         * @brief Returns percentage matched against `str` using `Levenshtein Distance` algorithm (From Information Theory).
         * @param str string to be matched
         * @return percentage `this->src` matched with `str`
         */
        double percentage_matched(const sstring_t_view<T> &str) const;

        /**
         * @brief Counts the number of occurrence of `what`.
         * @param what string to count
         * @return number of occurrence of `what`
         */
        std::size_t count(const T *what) const;

        /**
         * @brief Counts the number of occurrence of `what`.
         * @param what string to count
         * @return number of occurrence of `what`
         */
        std::size_t count(const sstring_t_view<T> &what) const;

        /**
         * @brief Counts the number of occurrence of `what`.
         * @param what character to count
         * @return number of occurrence of `what`
         */
        std::size_t count_char(const T what) const;

        /**
         * @brief Encodes `this->src` to 4 characters long string which can be compared to other `soundex` returned value.
         * @return sstring_t_view generated by this function
         */
        sstring_t_view<char> soundex() const;

        /**
         * @brief Returns the most occurred string in `this->src` separated by `dl`
         * @param dl separator string
         * @return most occurred string
         */
        sstring_t_view most_used(const T *dl) const;

        /**
         * @brief Returns the most occurred string in `this->src` separated by `dl`
         * @param dl separator string
         * @return most occurred string
         */
        sstring_t_view most_used(const sstring_t_view<T> &dl) const;

        /**
         * @brief Returns the most occurred character in `this->src`
         * @return most occurred character
         */
        T most_used_char() const;

        /**
         * @brief Splits `this->src` using `str`
         * @param str separator string
         * @return vector of sstring_t_view separated by `str`
         */
        vector_t<sstring_t_view<T>> split(const T *str) const;

        /**
         * @brief Splits `this->src` using `str`
         * @param str separator string
         * @return vector of sstring_t_view separated by `str`
         */
        vector_t<sstring_t_view<T>> split(const sstring_t_view<T> &str) const;

        /**
         * @brief Sorts `this->src` using `std::sort`
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &sort();

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
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &add_binary(const T *data, std::size_t &bin_len);

        /**
         * @brief Encrypts `a` using hash of `key`
         * @param key key to encrypt
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &encrypt(const T *key);

        /**
         * @brief Encrypts `a` using hash of `key`
         * @param key key to encrypt
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &encrypt(const sstring_t_view<T> &key);

        /**
         * @brief Decrypts `a` using hash of `key`
         * @param key key to decrypt
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &decrypt(const T *key);

        /**
         * @brief Decrypts `a` using hash of `key`
         * @param key key to decrypt
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &decrypt(const sstring_t_view<T> &key);

        /**
         * @brief Encodes a string to base64.
         * @return encoded string
         */
        sstring_t_view<char> encode_base64() const;

        /**
         * @brief Decodes a base64 encoded string to it's original form.
         * @param encoded convert encoded in base64 which has to be decoded
         * @return original decoded string, if invalid base64 string is provided it will return `nullptr`
         */
        sstring_t_view<T> decode_base64(const char *encoded) const;

        /**
         * @brief Decodes a base64 encoded string to it's original form.
         * @param encoded convert encoded in base64 which has to be decoded
         * @return original decoded string, if invalid base64 string is provided it will return `nullptr`
         */
        sstring_t_view<T> decode_base64(const sstring_t_view<char> &encoded) const;

        /**
         * @brief Returns const iterator for beginning
         * @return const beginning of iterator
         */
        const T *cbegin() const;

        /**
         * @brief Returns const iterator for ending
         * @return const ending of iterator
         */
        const T *cend() const;

        /**
         * @brief Returns iterator for beginning
         * @return beginning of iterator
         */
        T *begin();

        /**
         * @brief Returns iterator for ending
         * @return ending of iterator
         */
        T *end();

        /**
         * @brief Returns const reverse iterator for beginning
         * @return const reverse beginning of iterator
         */
        const T *crbegin() const;

        /**
         * @brief Returns const reverse iterator for ending
         * @return const reverse ending of iterator
         */
        const T *crend() const;

        /**
         * @brief Returns reverse iterator for beginning
         * @return reverse beginning of iterator
         */
        T *rbegin();

        /**
         * @brief Returns reverse iterator for ending
         * @return reverse ending of iterator
         */
        T *rend();

        /**
         * @brief Swaps contents of current object to `__x`
         * @param __x reference to another sstring_t_view
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &swap(sstring_t_view<T> &__x) noexcept;

        /**
         * @brief Returns content from `index` to `index` + `sub_len`
         * @param index stating index
         * @param sub_len length of new content
         * @return content from `index` to `index` + `sub_len`
         */
        sstring_t_view substr(std::size_t index, std::size_t sub_len = static_cast<std::size_t>(-1)) const;

        /**
         * @brief Parses `this->src` as C-style argv in `main()` function
         * @param argv0 first argument of `T **argv` in `main()` function, default value is `nullptr`
         * @return arguments
         */
        vector_t<sstring_t_view<T>> to_argv(const T *argv0 = nullptr) const;

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
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &format_escape_sequence();

        /**
         * @brief Inserts `str` into `this->src` at `index`.
         * @param str string to insert
         * @param index index where `str` is going to be inserted
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &insert(const T *str, std::size_t index);

        /**
         * @brief Inserts `str` into `this->src` at `index`.
         * @param str string to insert
         * @param index index where `str` is going to be inserted
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &insert(const sstring_t_view<T> &str, std::size_t index);

        /**
         * @brief Checks if `this->src` starts with `str`
         * @param str string to be matched
         * @return true if `this->src` starts with `str`;
         * @return false if `this->src` does NOT starts with `str`;
         */
        bool starts_with(const T *str) const;

        /**
         * @brief Checks if `this->src` starts with `str`
         * @param str string to be matched
         * @return true if `this->src` starts with `str`;
         * @return false if `this->src` does NOT starts with `str`;
         */
        bool starts_with(const sstring_t_view<T> &str) const;

        /**
         * @brief Checks if `this->src` ends with `str`
         * @param str string to be matched
         * @return true if `this->src` ends with `str`;
         * @return false if `this->src` does NOT ends with `str`;
         */
        bool ends_with(const T *str) const;

        /**
         * @brief Checks if `this->src` ends with `str`
         * @param str string to be matched
         * @return true if `this->src` ends with `str`;
         * @return false if `this->src` does NOT ends with `str`;
         */
        bool ends_with(const sstring_t_view<T> &str) const;

        /**
         * @brief Tokenize `this->src`.
         * @return returns tokenized vector with it's respective token
         */
        vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> lexer() const;

        /**
         * @brief Converts tokens to concentrated string
         * @param toks tokens
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &from_lexer(const vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> &toks);

        /**
         * @brief Assigns `__format__` to `this->src` with formatting.
         * @param buffer_length length of `__format__` along with the variable length of `...`
         * @param __format__ string containing the format instructions
         * @param ... arguments
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &set_formatted(std::size_t buffer_length, const char *__format__, ...);

        /**
         * @brief Appends `__format__` to `this->src` with formatting.
         * @param buffer_length length of `__format__` along with the variable length of `...`
         * @param __format__ string containing the format instructions
         * @param ... arguments
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &append_formatted(std::size_t buffer_length, const char *__format__, ...);

        /**
         * @brief Resizes `this->src` with `new_len`, no loss of previous data happens if resized successfully
         * @param new_len new length of `this->src`
         * @return true if resized successfully;
         * @return false if resized failed
         */
        bool resize(std::size_t new_len);

        /**
         * @brief Shrinks any extra memory allocation.
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &shrink_to_fit();

        /**
         * @brief Returns hash of `this->src`
         * @return hash of `this->src`
         */
        std::size_t hash() const;

        /**
         * @brief It first calculates hash of current object then converts that into base64 encoded sstring
         * @return sstring_t_view<char> base64 encoded hash of current object
         */
        sstring_t_view<char> hash_digest() const;

        /**
         * @brief Returns character at `n` index
         * @param n index of character
         * @return character at `n`
         */
        const T &operator[](std::size_t n) const;

        /**
         * @brief Returns reference of character at `n` index
         * @param n index of character
         * @return character reference at `n`
         */
        T &operator[](std::size_t n);

        /**
         * @brief Returns the addition of `this->src` and `c`
         * @param c character to add
         * @return sstring_t_view with `this->src` and `c`
         */
        sstring_t_view operator+(const T c) const;

        /**
         * @brief Returns the addition of `this->src` and `str`
         * @param str string to add
         * @return sstring_t_view with `this->src` and `str`
         */
        sstring_t_view operator+(const T *str) const;

        /**
         * @brief Returns the addition of `this->src` and `str`
         * @param str sstring_t_view to add
         * @return sstring_t_view with `this->src` and `str`
         */
        sstring_t_view operator+(const sstring_t_view<T> &str) const;

        /**
         * @brief Appends `c`
         * @param c character to append
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator+=(const T c);

        /**
         * @brief Appends `str`
         * @param str string to append
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator+=(const T *str);

        /**
         * @brief Appends `str`
         * @param str sstring_t_view to append
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator+=(const sstring_t_view<T> &str);

        /**
         * @brief Appends list of characters
         * @param list list of characters
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator+=(const std::initializer_list<T> &list);

        /**
         * @brief Appends list of `sstring_t_view`s
         * @param list list of `sstring_t_view`s
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator+=(const std::initializer_list<sstring_t_view> &list);

        /**
         * @brief Assigns `c`
         * @param c character to assign
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator=(const T c);

        /**
         * @brief Assigns `str`
         * @param str string to assign
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator=(const T *str);

        /**
         * @brief Copy operator
         * @param str sstring_t_view to copy
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator=(const sstring_t_view<T> &str);

        /**
         * @brief Move operator
         * @param __s sstring_t_view to move
         * @return sstring_t_view& reference to current object
         */
        sstring_t_view<T> &operator=(sstring_t_view<T> &&__s) noexcept;

        /**
         * @brief Compares `str` to `this->src`
         * @param str string
         * @return true both strings are equal;
         * @return false both string are unequal
         */
        bool operator==(const T *str) const;

        /**
         * @brief Compares `str` to `this->src`
         * @param str sstring_t_view to be compared
         * @return true both strings are equal;
         * @return false both string are unequal
         */
        bool operator==(const sstring_t_view<T> &str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is less than `str`;
         * @return false if `this->src` is greater than `str`
         */
        bool operator<(const T *str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is less than `str`;
         * @return false if `this->src` is greater than `str`
         */
        bool operator<(const sstring_t_view<T> &str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is greater than `str`;
         * @return false if `this->src` is less than `str`
         */
        bool operator>(const T *str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is greater than `str`;
         * @return false if `this->src` is less than `str`
         */
        bool operator>(const sstring_t_view<T> &str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is less than or equal to `str`;
         * @return false if `this->src` is greater than or equal to `str`
         */
        bool operator<=(const T *str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is less than or equal to `str`;
         * @return false if `this->src` is greater than or equal to `str`
         */
        bool operator<=(const sstring_t_view<T> &str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is greater than or equal to `str`;
         * @return false if `this->src` is less than or equal to `str`
         */
        bool operator>=(const T *str) const;

        /**
         * @brief Does lexicographical comparison between `this->src` and `str`
         * @param str string to be compared
         * @return true if `this->src` is greater than or equal to `str`;
         * @return false if `this->src` is less than or equal to `str`
         */
        bool operator>=(const sstring_t_view<T> &str) const;

        /**
         * @brief Compares `str` to `this->src`
         * @param str string
         * @return true both strings are unequal;
         * @return false both string are equal
         */
        bool operator!=(const T *str) const;

        /**
         * @brief Compares `str` to `this->src`
         * @param str sstring_t_view to be compared
         * @return true both strings are unequal;
         * @return false both string are equal
         */
        bool operator!=(const sstring_t_view<T> &str) const;

        /**
         * @brief Return value of many in-built functions when some error occurs
         * @return (std::size_t)-1
         */
        constexpr inline std::size_t nerr() const noexcept;

        /**
         * @brief Destroy the sstring_t_view object. NOTE: Calling this function explicitly can cause double-free error
         */
        ~sstring_t_view();

        /**
         * @brief Sorts `arr`
         * @param arr array of sstring_t_view
         * @param len length of `arr`
         */
        static void sort(sstring_t_view *arr, std::size_t len);

        /**
         * @brief Sorts `arr`
         * @param arr array of `T *`
         * @param len length of `arr`
         */
        static void sort(T **arr, std::size_t len);

        /**
         * @brief Returns `c` as sstring_t_view
         * @param c character to assign
         * @return `c` as sstring_t_view
         */
        static sstring_t_view to_sstring(T c);

        /**
         * @brief Returns `boolean` as sstring_t_view
         * @param boolean bool value to assign
         * @return `boolean` as sstring_t_view
         */
        static sstring_t_view to_sstring(bool boolean);

        /**
         * @brief Returns `str` as sstring_t_view
         * @param str string to assign
         * @return `str` as sstring_t_view
         */
        static sstring_t_view to_sstring(const T *str);

        /**
         * @brief Returns `ptr` as sstring_t_view
         * @param ptr pointer value
         * @return `ptr` as sstring_t_view
         */
        static sstring_t_view to_sstring(void *ptr);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(signed short int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(unsigned short int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(signed int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(unsigned int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(signed long int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(unsigned long int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(signed long long int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(unsigned long long int x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x decimal number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(float x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x decimal number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(double x);

        /**
         * @brief Returns `x` as sstring_t_view
         * @param x decimal number to assign
         * @return `x` as sstring_t_view
         */
        static sstring_t_view to_sstring(long double x);

        /**
         * @brief Returns random sstring_t_view of length `len`
         * @param len length of random sstring_t_view
         * @return random sstring_t_view of length `len`
         */
        static sstring_t_view get_random(const std::size_t &len);

        /**
         * @brief Returns user input.
         * @return user input
         */
        static sstring_t_view get_input();

        /**
         * @brief Returns content of file at `location` in the filesystem
         * @param location location of file
         * @return content of file at `location` in the filesystem
         */
        static sstring_t_view open_file(const sstring_t_view<char> &location);

        /**
         * @brief Returns end line character with respect to operating system in use.
         * @return end line character with respect to operating system in use.
         */
        static sstring_t_view end_line();
    };

    // definitions

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM>::convert_sstring()
    {
        this->src = nullptr;
        this->len = 0;
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM>::convert_sstring(const FROM *str)
    {
        if (str)
        {
            this->len = 0;

            while (str[this->len] != 0)
                this->len++;

            this->src = static_cast<TO *>(std::calloc(this->len + 1, sizeof(TO)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < this->len; i++)
                this->src[i] = static_cast<TO>(str[i]);
        }
        else
        {
            this->src = nullptr;
            this->len = 0;
        }
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM>::convert_sstring(FROM c)
    {
        if (c != 0)
        {
            this->len = 1;
            this->src = static_cast<TO *>(std::calloc(this->len + 1, sizeof(TO)));
            exit_heap_fail(this->src);
            this->src[0] = static_cast<TO>(c);
        }
        else
        {
            this->src = nullptr;
            this->len = 0;
        }
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM>::convert_sstring(const convert_sstring &cs)
    {
        if (cs.src)
        {
            this->len = cs.len;
            this->src = static_cast<TO *>(std::calloc(this->len + 1, sizeof(TO)));
            exit_heap_fail(this->src);
            for (std::size_t i = 0; i < this->len; i++)
                this->src[i] = cs.src[i];
        }
        else
        {
            this->src = nullptr;
            this->len = 0;
        }
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM>::convert_sstring(convert_sstring &&cs) noexcept
    {
        this->len = cs.len;
        this->src = cs.src;

        cs.len = 0;
        cs.src = nullptr;
    }

    template <typename TO, typename FROM>
    const std::size_t &convert_sstring<TO, FROM>::length() const
    {
        return this->len;
    }

    template <typename TO, typename FROM>
    const TO *convert_sstring<TO, FROM>::get() const
    {
        return this->src;
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM> &convert_sstring<TO, FROM>::set(const FROM *str)
    {
        if (str)
        {
            if (this->src)
                std::free(this->src);
            this->len = 0;

            while (str[this->len] != 0)
                this->len++;

            this->src = static_cast<TO *>(std::calloc(this->len + 1, sizeof(TO)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < this->len; i++)
                this->src[i] = static_cast<TO>(str[i]);
        }
        return *this;
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM> &convert_sstring<TO, FROM>::set(FROM c)
    {
        if (c != 0)
        {
            if (this->src)
                std::free(this->src);
            this->len = 1;
            this->src = static_cast<TO *>(std::calloc(this->len + 1, sizeof(TO)));
            exit_heap_fail(this->src);
            this->src[0] = static_cast<TO>(c);
        }
        return *this;
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM> &convert_sstring<TO, FROM>::operator=(const convert_sstring &cs)
    {
        if (this != &cs)
            this->set(cs.src);
        return *this;
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM> &convert_sstring<TO, FROM>::operator=(convert_sstring &&cs) noexcept
    {
        if (this != &cs)
        {
            if (this->src)
                std::free(this->src);
            this->len = cs.len;
            this->src = cs.src;

            cs.len = 0;
            cs.src = nullptr;
        }
        return *this;
    }

    template <typename TO, typename FROM>
    convert_sstring<TO, FROM>::~convert_sstring()
    {
        if (this->src)
            std::free(this->src);
        this->len = 0;
    }

    template <typename T>
    inline void sstring_t_view<T>::fast_strncat(T *dest, const T *src, std::size_t &size)
    {
        if (dest && src)
            while ((dest[size] = *src++))
                size += 1;
    }

    template <typename T>
    inline T *sstring_t_view<T>::fast_strstr(const T *haystack, std::size_t haystack_len, const T *needle) noexcept(true)
    {
        if (!haystack || !needle || haystack_len == 0)
            return nullptr;
        std::size_t needle_len = sstring_t_view<T>::sstr_strlen(needle);
        if (needle_len == 0)
            return (T *)haystack;
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
                return (T *)(haystack + i - needle_len + 1);
            }
        }
        std::free(prefix);
        return nullptr;
    }

    template <typename T>
    inline void sstring_t_view<T>::init_n_zeroes(T *ptr, std::size_t from_where, std::size_t till_where)
    {
        if (ptr)
            for (std::size_t i = from_where; i < till_where; i++)
                ptr[i] = 0;
    }

    template <typename T>
    inline int sstring_t_view<T>::sstr_strcmp(const T *str1, const T *str2)
    {
        if (!str1 || !str2)
            return -1;
        int i = 0;
        while (str1[i] != 0 && str2[i] != 0)
        {
            if (str1[i] != str2[i])
                return (str1[i] < str2[i]) ? -1 : 1;
            i++;
        }
        return (str1[i] == 0 && str2[i] == 0) ? 0 : (str1[i] < str2[i]) ? -1
                                                                        : 1;
    }

    template <typename T>
    inline int sstring_t_view<T>::sstr_strncmp(const T *str1, const T *str2, std::size_t n)
    {
        if (!str1 || !str2)
            return -1;
        std::size_t i = 0;
        while (i < n && str1[i] != 0 && str2[i] != 0)
        {
            if (str1[i] != str2[i])
                return (str1[i] < str2[i]) ? -1 : 1;
            i++;
        }
        if (i == n)
            return 0;
        return (str1[i] < str2[i]) ? -1 : 1;
    }

    template <typename T>
    inline std::size_t sstring_t_view<T>::sstr_strlen(const T *str)
    {
        if (!str)
            return 0;
        std::size_t str_L = 0;
        while (*str != 0)
        {
            str_L++;
            str++;
        }
        return str_L;
    }

    template <typename T>
    inline T *sstring_t_view<T>::fast_strtok(T *str, const T *delim, std::size_t delim_length)
    {
        if (!delim)
            return nullptr;
        static T *token = nullptr; // maintains a static pointer variable
        if (str != nullptr)
            token = str;
        else if (token == nullptr)
            return nullptr;
        T *p = sstring_t_view<T>::fast_strstr(token, sstring_t_view<T>::sstr_strlen(token), delim);
        if (p != nullptr)
        {
            *p = 0;
            T *tmp = token;
            token = p + delim_length;
            return tmp;
        }
        else
        {
            T *tmp = token;
            token = nullptr;
            return tmp;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view()
    {
        this->len = 0;
        this->src = nullptr;
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T c)
    {
        if (c != 0)
        {
            this->len = 0;
            this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
            exit_heap_fail(this->src);
            this->src[this->len++] = c;
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T *str)
    {
        if (str)
        {
            this->len = 0;
            std::size_t str_len = this->sstr_strlen(str);
            this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, str, this->len);
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(T *ptr_begin, T *ptr_end)
    {
        if (ptr_begin && ptr_end)
        {
            this->len = static_cast<std::size_t>(ptr_end - ptr_begin);
            this->src = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            std::size_t i = 0;
            for (const T *ptr = ptr_begin; ptr != ptr_end; ptr++)
                this->src[i++] = *ptr;
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T c, std::size_t n)
    {
        if (n != 0 && c != 0)
        {
            this->len = 0;
            this->src = static_cast<T *>(std::calloc(n + 1, sizeof(T)));
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

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const T *str, std::size_t n)
    {
        if (n != 0 && str)
        {
            this->len = 0;
            std::size_t str_len = this->sstr_strlen(str) * n;
            this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            for (std::size_t i = 0; i < n; i++)
                this->fast_strncat(this->src, str, this->len);
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const sstring_t_view<T> &other)
    {
        if (other.src)
        {
            this->len = 0;
            this->src = static_cast<T *>(std::calloc(other.len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, other.src, this->len);
        }
        else
        {
            this->len = 0;
            this->src = nullptr;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(sstring_t_view<T> &&other) noexcept
    {
        this->src = other.src;
        this->len = other.len;
        other.src = nullptr;
        other.len = 0;
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const std::initializer_list<T> &list)
    {
        this->len = 0;
        std::size_t str_len = list.size();
        this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);
        for (auto i = list.begin(); i != list.end(); i++)
        {
            if (*i != 0)
                this->src[this->len++] = *i;
        }
    }

    template <typename T>
    sstring_t_view<T>::sstring_t_view(const std::initializer_list<sstring_t_view<T>> &list)
    {
        this->len = 0;
        std::size_t str_len = 0;
        for (auto i = list.begin(); i != list.end(); i++)
            str_len += (*i).len;

        this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);

        for (auto i = list.begin(); i != list.end(); i++)
        {
            if ((*i).src)
            {
                for (std::size_t j = 0; j < (*i).len; j++)
                    this->src[this->len++] = (*i).src[j];
            }
        }
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set(const T *str)
    {
        if (str)
        {
            if (this->src)
                std::free(this->src);
            this->len = 0;
            std::size_t str_len = this->sstr_strlen(str);
            this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, str, this->len);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set(const sstring_t_view<T> &str)
    {
        return this->set(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_char(const T c)
    {
        if (c != 0)
        {
            if (this->src)
                std::free(this->src);
            this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
            exit_heap_fail(this->src);
            this->src[this->len++] = c;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_upto(const T *str, std::size_t N)
    {
        if (str && (N <= this->sstr_strlen(str)))
        {
            if (this->src)
                std::free(this->src);
            this->src = static_cast<T *>(std::calloc(N + 1, sizeof(T)));
            exit_heap_fail(this->src);
            std::memmove(this->src, str, N * sizeof(T));
            this->len = N;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_upto(const sstring_t_view<T> &str, std::size_t N)
    {
        return this->set_upto(str.src, N);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_random(std::size_t rnd_len)
    {
        if (rnd_len != 0)
        {
            if (this->src)
                std::free(this->src);
            this->src = static_cast<T *>(std::calloc(rnd_len + 1, sizeof(T)));
            exit_heap_fail(this->src);
            for (std::size_t i = 0; i < rnd_len; i++)
                this->src[i] = (rand() % (126 - 32 + 1)) + 32;
            this->len = rnd_len;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_array(const vector_t<T *> &vec, const T *between)
    {
        if (this->src)
            std::free(this->src);
        this->len = 0;

        std::size_t vec_str_len = 0, bw_len = 0;

        if (between)
            bw_len = this->sstr_strlen(between);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i])
                vec_str_len += this->sstr_strlen(vec[i]);
        }

        if (between)
            vec_str_len += vec.length() * bw_len;

        this->src = static_cast<T *>(std::calloc(vec_str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i])
            {
                this->fast_strncat(this->src, vec[i], this->len);
                if (between)
                    this->fast_strncat(this->src, between, this->len);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_array(const vector_t<sstring_t_view<T>> &vec, const T *between)
    {
        if (this->src)
            std::free(this->src);
        this->len = 0;

        std::size_t vec_str_len = 0, bw_len = 0;

        if (between)
            bw_len = this->sstr_strlen(between);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i].src)
                vec_str_len += vec[i].len;
        }

        if (between)
            vec_str_len += vec.length() * bw_len;

        this->src = static_cast<T *>(std::calloc(vec_str_len + 1, sizeof(T)));
        exit_heap_fail(this->src);

        for (std::size_t i = 0; i < vec.length(); i++)
        {
            if (vec[i].src)
            {
                this->fast_strncat(this->src, vec[i].src, this->len);
                if (between)
                    this->fast_strncat(this->src, between, this->len);
            }
        }
        return *this;
    }

    template <typename T>
    T *&sstring_t_view<T>::get()
    {
        return this->src;
    }

    template <typename T>
    const T *sstring_t_view<T>::c_str() const
    {
        return this->src;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::get_ref()
    {
        return *this;
    }

    template <typename T>
    sstring_t_view<T> *sstring_t_view<T>::get_ptr()
    {
        return this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append(const T *str)
    {
        if (str)
        {
            std::size_t str_len = this->sstr_strlen(str);
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + str_len + 1)));
                exit_heap_fail(this->src);
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
            }
            this->fast_strncat(this->src, str, this->len);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append(const sstring_t_view<T> &str)
    {
        return this->append(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_char(const T c)
    {
        if (c != 0)
        {
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + 2)));
                exit_heap_fail(this->src);
                this->init_n_zeroes(this->src, this->len, this->len + 2);
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
            }
            this->src[this->len++] = c;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_upto(const T *str, std::size_t N)
    {
        if (str && (N <= this->sstr_strlen(str)))
        {
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + N + 1)));
                exit_heap_fail(this->src);
                std::memmove(this->src + this->len, str, N * sizeof(T));
                this->len += N;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(N + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
                std::memmove(this->src, str, N * sizeof(T));
                this->len = N;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_upto(const sstring_t_view<T> &str, std::size_t N)
    {
        return this->append_upto(str.src, N);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start(const T *str)
    {
        if (str)
        {
            std::size_t str_len = this->sstr_strlen(str);
            if (this->src)
            {
                T *buff = static_cast<T *>(std::calloc(str_len + this->len + 1, sizeof(T)));
                exit_heap_fail(buff);
                this->len = 0;
                this->fast_strncat(buff, str, this->len);
                this->fast_strncat(buff, this->src, this->len);

                std::free(this->src);
                this->src = buff;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(str_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->len = 0;
                this->fast_strncat(this->src, str, this->len);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start(const sstring_t_view<T> &str)
    {
        return this->append_start(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_char(const T c)
    {
        if (c != 0)
        {
            if (this->src)
            {
                T *buff = static_cast<T *>(std::calloc(this->len + 2, sizeof(T)));
                exit_heap_fail(buff);
                this->len = 1;
                std::memmove(buff, &c, sizeof(T));
                this->fast_strncat(buff, this->src, this->len);

                std::free(this->src);
                this->src = buff;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(2, sizeof(T)));
                exit_heap_fail(this->src);
                std::memmove(this->src, &c, sizeof(T));
                this->len = 1;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_upto(const T *str, std::size_t N)
    {
        if (str && (N <= this->sstr_strlen(str)))
        {
            if (this->src)
            {
                T *buff = static_cast<T *>(std::calloc(N + this->len + 1, sizeof(T)));
                exit_heap_fail(buff);
                this->len = N;
                std::memmove(buff, str, N * sizeof(T));
                this->fast_strncat(buff, this->src, this->len);

                std::free(this->src);
                this->src = buff;
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(N + 1, sizeof(T)));
                exit_heap_fail(this->src);
                std::memmove(this->src, str, N * sizeof(T));
                this->len = N;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_upto(const sstring_t_view<T> &str, std::size_t N)
    {
        return this->append_start_upto(str.src, N);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_array(const vector_t<T *> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i])
                    vec_str_len += this->sstr_strlen(vec[i]);
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + vec_str_len + 1)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i])
                {
                    this->fast_strncat(this->src, vec[i], this->len);
                    if (between)
                        this->fast_strncat(this->src, between, this->len);
                }
            }
        }
        else
        {
            this->set_array(vec, between);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_array(const vector_t<sstring_t_view<T>> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i].src)
                    vec_str_len += vec[i].len;
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + vec_str_len + 1)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i].src)
                {
                    this->fast_strncat(this->src, vec[i].src, this->len);
                    if (between)
                        this->fast_strncat(this->src, between, this->len);
                }
            }
        }
        else
        {
            this->set_array(vec, between);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_array(const vector_t<T *> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i])
                    vec_str_len += this->sstr_strlen(vec[i]);
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            T *buff = static_cast<T *>(std::calloc(this->len + vec_str_len + 1, sizeof(T)));
            exit_heap_fail(buff);
            std::size_t track = 0;
            this->fast_strncat(buff, this->src, track);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                this->fast_strncat(buff, vec[i], track);
                if (between)
                    this->fast_strncat(buff, between, track);
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

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_start_array(const vector_t<sstring_t_view<T>> &vec, const T *between)
    {
        if (this->src)
        {
            std::size_t vec_str_len = 0, bw_len = 0;

            if (between)
                bw_len = this->sstr_strlen(between);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                if (vec[i].src)
                    vec_str_len += vec[i].len;
            }

            if (between)
                vec_str_len += vec.length() * bw_len;

            T *buff = static_cast<T *>(std::calloc(this->len + vec_str_len + 1, sizeof(T)));
            exit_heap_fail(buff);
            std::size_t track = 0;
            this->fast_strncat(buff, this->src, track);

            for (std::size_t i = 0; i < vec.length(); i++)
            {
                this->fast_strncat(buff, vec[i].src, track);
                if (between)
                    this->fast_strncat(buff, between, track);
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

    template <typename T>
    bool sstring_t_view<T>::is_empty() const
    {
        return (this->len == 0);
    }

    template <typename T>
    bool sstring_t_view<T>::is_null() const
    {
        if (this->src)
            return false;
        return true;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace(const T *old, const T *new_)
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

            std::size_t old_len = this->sstr_strlen(old), new_len = this->sstr_strlen(new_);

            // now we have got every points (indexes) where `old` is present

            std::size_t buff_len = this->len + (new_len * indexes.length()) - (old_len * indexes.length());
            T *buff = static_cast<T *>(std::calloc(buff_len + 1, sizeof(T)));
            exit_heap_fail(buff);

            std::size_t track = 0;
            for (std::size_t i = 0, k = 0; i < indexes.length(); i++)
            {
                for (; k < indexes[i]; track++, k++)
                {
                    buff[track] = this->src[k];
                }
                k += old_len;
                this->fast_strncat(buff, new_, track);
            }
            this->fast_strncat(buff, this->src + indexes[indexes.length() - 1] + old_len, track);

            std::free(this->src);
            this->src = buff;
            this->len = track;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace(const sstring_t_view<T> &old, const sstring_t_view<T> &new_)
    {
        return this->replace(old.src, new_.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace_line(std::size_t line_no, const T *new_)
    {
        if (!new_ || !this->src || this->len == 0)
            return *this;
        vector_t<sstring_t_view<T>> vec_split = this->split(convert_sstring<T, char>("\n").get());
        if (line_no >= vec_split.length())
            return *this;
        std::size_t nlen = this->sstr_strlen(new_);
        sstring_t_view<T> buff;
        std::size_t track = 0;

        for (std::size_t i = 0; i < vec_split.length(); i++)
        {
            if (i == line_no)
            {
                for (std::size_t j = 0; j < nlen; j++)
                    buff += new_[j];
            }
            else
            {
                for (std::size_t j = 0; j < vec_split[i].len; j++)
                    buff += vec_split[i].src[j];
            }
            if(i != vec_split.length() - 1)
                buff += 10;
        }

        std::free(this->src);
        this->src = buff.src;
        this->len = buff.len;
        buff.src = nullptr;
        buff.len = 0;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace_line(std::size_t line_no, const sstring_t_view<T> &new_)
    {
        return this->replace_line(line_no, new_.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::replace_char(const T old, const T new_)
    {
        if (old != 0 && new_ != 0 && this->src)
            for (std::size_t i = 0; this->src[i] != 0; i++)
                if (this->src[i] == old)
                    this->src[i] = new_;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::char_set(const T new_char, std::size_t nth)
    {
        if (this->len >= nth && new_char != 0 && this->src)
            this->src[nth] = new_char;
        return *this;
    }

    template <typename T>
    const T &sstring_t_view<T>::char_get(std::size_t nth) const
    {
        if (this->len >= nth && this->src)
            return this->src[nth];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    T &sstring_t_view<T>::char_get(std::size_t nth)
    {
        if (this->len >= nth && this->src)
            return this->src[nth];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    std::size_t sstring_t_view<T>::index_of(T ch) const
    {
        if (ch != 0 && this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (this->src[i] == ch)
                    return i;
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::last_index_of(T ch) const
    {
        if (ch != 0 && this->src)
        {
            for (std::size_t i = this->len - 1; i != static_cast<std::size_t>(-1); i--)
                if (this->src[i] == ch)
                    return i;
        }
        return this->nerr();
    }

    template <typename T>
    const std::size_t &sstring_t_view<T>::length() const
    {
        return this->len;
    }

    template <typename T>
    const std::size_t &sstring_t_view<T>::change_length(std::size_t new_length)
    {
        this->len = new_length;
        return this->len;
    }

    template <typename T>
    bool sstring_t_view<T>::compare(const T *T1) const
    {
        if (T1 && this->src)
            if (this->sstr_strcmp(this->src, T1) == 0)
                return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::compare(const sstring_t_view<T> &T1) const
    {
        return this->compare(T1.src);
    }

    template <typename T>
    bool sstring_t_view<T>::compare_upto(const T *T1, std::size_t N) const
    {
        if (T1 && this->src)
            if (this->sstr_strncmp(this->src, T1, N) == 0)
                return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::compare_upto(const sstring_t_view<T> &T1, std::size_t N) const
    {
        return this->compare_upto(T1.src, N);
    }

    template <typename T>
    bool sstring_t_view<T>::is_changed(sstring_t_view<T> &obj)
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

    template <typename T>
    int sstring_t_view<T>::lexicographical_comparison(const T *str) const
    {
        if (!this->src)
            return this->len - this->sstr_strlen(str);
        std::size_t str_len = 0;
        for (std::size_t i = 0; this->src[i] && str[str_len]; i++, str_len++)
        {
            if (this->src[i] == str[i])
                continue;
            return (int)this->src[i] - (int)str[i];
        }
        return this->len - str_len;
    }

    template <typename T>
    int sstring_t_view<T>::lexicographical_comparison(const sstring_t_view<T> &str) const
    {
        return this->lexicographical_comparison(str.src);
    }

    template <typename T>
    bool sstring_t_view<T>::save(const char *location) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "wb");
            if (f != nullptr)
            {
                std::fwrite(this->src, this->len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::save(const sstring_t_view<char> &location) const
    {
        return this->save(location.c_str());
    }

    template <typename T>
    bool sstring_t_view<T>::append_file(const char *location) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "ab");
            if (f != nullptr)
            {
                std::fwrite(this->src, this->len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::append_file(const sstring_t_view<char> &location) const
    {
        return this->append_file(location.c_str());
    }

    template <typename T>
    bool sstring_t_view<T>::open(const char *location)
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
                this->src = static_cast<T *>(std::calloc(file_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                std::fread(this->src, file_len, sizeof(T), f);
                std::fclose(f);
                this->len = file_len;
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::open(const sstring_t_view<char> &location)
    {
        return this->open(location.c_str());
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::clear()
    {
        if (this->src)
            std::free(this->src);
        this->src = nullptr;
        this->len = 0;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::to_upper()
    {
        if (this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; ++i)
            {
                if (std::islower(this->src[i]))
                    this->src[i] = std::toupper(this->src[i]);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::to_lower()
    {
        if (this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; ++i)
            {
                if (std::isupper(this->src[i]))
                    this->src[i] = std::tolower(this->src[i]);
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::swap_case()
    {
        if (this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; ++i)
            {
                if (std::islower(this->src[i]))
                    this->src[i] = std::toupper(this->src[i]);
                else if (std::isupper(this->src[i]))
                    this->src[i] = std::tolower(this->src[i]);
            }
        }
        return *this;
    }

    template <typename T>
    double sstring_t_view<T>::entropy() const
    {
        if (this->src)
        {
            std::unordered_map<T, std::size_t> freq;
            for (std::size_t i = 0; i < this->len; i++)
                freq[this->src[i]] += 1;

            double result = 0;
            for (const auto &[key, value] : freq)
            {
                double f1 = static_cast<double>(value) / static_cast<double>(this->len);
                result -= f1 * (std::log(f1) / std::log(2.0));
            }
            return result;
        }
        return -1;
    }

    template <typename T>
    double sstring_t_view<T>::password_entropy() const
    {
        if (!this->src)
            return 0;
        // formula = E = L * log2(R)
        std::size_t R = 0;
        //					  0      1      2      3         4
        // 					digit, lower, upper, special, other_ascii
        bool is_added[5] = {false, false, false, false, false};

        for (std::size_t i = 0; i < this->len; i++)
        {
            if (std::isdigit(this->src[i]))
            {
                if (is_added[0] == false)
                {
                    R += 10;
                    is_added[0] = true;
                }
            }
            else if (std::islower(this->src[i]))
            {
                if (is_added[1] == false)
                {
                    R += 26;
                    is_added[1] = true;
                }
            }
            else if (std::isupper(this->src[i]))
            {
                if (is_added[2] == false)
                {
                    R += 26;
                    is_added[2] = true;
                }
            }
            else if ((this->src[i] >= 32 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 64) || (this->src[i] >= 91 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] < 127))
            {
                if (is_added[3] == false)
                {
                    R += 33;
                    is_added[3] = true;
                }
            }
            else
            {
                if (is_added[4] == false)
                {
                    R += 33;
                    is_added[4] = true;
                }
            }
        }
        return (double)this->len * std::log2(R);
    }

    template <typename T>
    bool sstring_t_view<T>::contains(const T *str) const
    {
        if (str && this->src)
            if (this->fast_strstr(this->src, this->len, str) != nullptr)
                return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::contains(const sstring_t_view<T> &str) const
    {
        return this->contains(str.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::contains_char(const T c) const
    {
        if (c != 0 && this->src)
        {
            for (std::size_t i = 0; this->src[i] != 0; i++)
                if (this->src[i] == c)
                    return i;
        }
        return this->nerr();
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::to_set()
    {
        if (this->src)
        {
            std::unordered_map<T, std::size_t> freq;
            for (std::size_t i = 0; i < this->len; i++)
                freq[this->src[i]] += 1;

            std::free(this->src);
            this->len = freq.size();
            this->src = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(this->src);

            this->len = 0;
            for (const auto &[key, value] : freq)
            {
                this->src[this->len++] = key;
            }
        }
        return *this;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find(const T *sub) const
    {
        if (sub && this->src)
        {
            T *buff = this->fast_strstr(this->src, this->len, sub);
            if (buff)
                return this->len - this->sstr_strlen(buff);
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find(const sstring_t_view<T> &sub) const
    {
        return this->find(sub.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::rfind(const T *sub) const
    {
        if (sub && this->src)
        {
            const T *last = nullptr;
            const T *cur = this->src;

            while ((cur = this->fast_strstr(cur, this->sstr_strlen(cur), sub)) != nullptr)
            {
                last = cur;
                cur++;
            }

            return last ? static_cast<std::size_t>(last - this->src) : this->nerr();
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::rfind(const sstring_t_view<T> &sub) const
    {
        return this->rfind(sub.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find_next(std::size_t last_index, const T *sub) const
    {
        if (sub && this->src)
        {
            T *buff = this->fast_strstr(this->src + last_index, this->len - last_index, sub);
            if (buff)
                return this->len - this->sstr_strlen(buff);
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::find_next(std::size_t last_index, const sstring_t_view<T> &sub) const
    {
        return this->find_next(last_index, sub.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::in()
    {
        if (this->src)
            std::free(this->src);

        std::size_t cap = 64, len_input = 0;
        T ch;
        this->src = static_cast<T *>(std::calloc(cap, sizeof(T)));
        exit_heap_fail(this->src);

        while ((ch = std::getchar()))
        {
            if (ch == 10 || ch == 0 || ch == EOF)
                break;
            this->src[len_input++] = ch;
            if (len_input == cap)
            {
                cap += 64;
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * cap));
                exit_heap_fail(this->src);
            }
        }
        this->src[len_input] = 0;
        this->len = len_input;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::getline(std::size_t line) const
    {
        if (!this->src)
            return nullptr;

        vector_t<sstring_t_view<T>> vec_split = this->split(convert_sstring<T, char>("\n").get());
        if (line >= vec_split.length())
            return nullptr;
        sstring_t_view<T> ret = std::move(vec_split[line]);
        vec_split.erase();
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const T *prefix, const T *suffix) const
    {
        if (!prefix || !suffix || !this->src)
            return nullptr;
        std::size_t plen = this->sstr_strlen(prefix), slen = this->sstr_strlen(suffix);
        T *buff = static_cast<T *>(std::calloc(this->len + plen + slen + 1, sizeof(T)));
        exit_heap_fail(buff);
        std::size_t track = 0;
        this->fast_strncat(buff, prefix, track);
        this->fast_strncat(buff, this->src, track);
        this->fast_strncat(buff, suffix, track);
        // done copying
        sstring_t_view<T> ret;
        ret.src = buff;
        ret.len = track;
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const sstring_t_view<T> &prefix, const sstring_t_view<T> &suffix) const
    {
        return this->wrap(prefix.src, suffix.src);
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const T *str) const
    {
        if (!str || !this->src)
            return nullptr;
        std::size_t pslen = this->sstr_strlen(str);
        T *buff = static_cast<T *>(std::calloc(this->len + pslen + pslen + 1, sizeof(T)));
        exit_heap_fail(buff);
        std::size_t track = 0;
        this->fast_strncat(buff, str, track);
        this->fast_strncat(buff, this->src, track);
        this->fast_strncat(buff, str, track);
        // done copying
        sstring_t_view<T> ret;
        ret.src = buff;
        ret.len = track;
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::wrap(const sstring_t_view<T> &str) const
    {
        return this->wrap(str.src);
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::center(std::size_t col_size, const T *padding) const
    {
        if (!this->src)
        {
            if (!padding)
                return sstring_t_view<T>(convert_sstring<T, char>(" ").get(), col_size);
            return sstring_t_view<T>(padding, col_size);
        }
        if (col_size == 0 || col_size <= this->len)
            return sstring_t_view<T>(this->src);
        sstring_t_view<T> ret;
        std::size_t temp_padding = (col_size - this->len) / 2;
        convert_sstring<T, char> conversion((padding == nullptr ? " " : padding));
        for (std::size_t i = 0; i < temp_padding; i++)
            ret += conversion.get();
        ret += *this;
        for (std::size_t i = 0; i < temp_padding; i++)
            ret += conversion.get();
        return ret;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::center(std::size_t col_size, const sstring_t_view<T> &padding) const
    {
        return this->center(col_size, padding.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::reverse()
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len / 2; i++)
            {
                T c = this->src[i];
                this->src[i] = this->src[this->len - i - 1];
                this->src[this->len - i - 1] = c;
            }
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove(const T *sub)
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

            std::size_t sub_len = this->sstr_strlen(sub);
            // now we have all indexes where sub has occurred

            std::size_t buff_len = this->len - (sub_len * indexes.length());
            T *buff = static_cast<T *>(std::calloc(buff_len + 1, sizeof(T)));
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
            this->fast_strncat(buff, this->src + indexes[indexes.length() - 1] + sub_len, track);

            std::free(this->src);
            this->src = buff;
            this->len = track;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove(const sstring_t_view<T> &sub)
    {
        return this->remove(sub.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_char(const T c)
    {
        if (c != 0 && this->src)
        {
            std::size_t z = this->count_char(c);
            T *buff = static_cast<T *>(std::calloc(this->len - z + 1, sizeof(T)));
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

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_extra_char(const T c)
    {
        if (c != 0 && this->src)
        {
            T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
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

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_range(std::size_t from, std::size_t till)
    {
        if (!this->src)
            return *this;
        if (till > this->len || from > this->len || from > till || till == from)
            return *this;
        T *buff = static_cast<T *>(std::calloc(this->len - (till - from) + 1, sizeof(T)));
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

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::intersect(std::size_t from, std::size_t till)
    {
        if (!this->src)
            return *this;
        if (till > this->len || from > this->len || from > till || till == from)
            return *this;
        T *buff = static_cast<T *>(std::calloc(till - from + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::size_t k = 0;
        for (std::size_t i = from; i <= till; i++)
            buff[k++] = this->src[i];

        std::free(this->src);
        this->src = buff;
        this->len = k;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_first_char()
    {
        if (!this->src)
            return *this;
        if (this->src[0] == 0)
            return *this;

        T *buff = static_cast<T *>(std::calloc(this->len, sizeof(T)));
        exit_heap_fail(buff);

        std::size_t z = 0;
        for (std::size_t i = 1; i < this->len; i++)
            buff[z++] = this->src[i];

        std::free(this->src);
        this->src = buff;
        this->len = z;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::remove_last_char()
    {
        if (!this->src)
            return *this;
        this->src[this->len - 1] = 0;
        this->len--;
        return *this;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::distance(const T *str) const
    {
        if (str && this->src)
        {
            if (this->sstr_strlen(src) == this->len)
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

    template <typename T>
    std::size_t sstring_t_view<T>::distance(const sstring_t_view<T> &str) const
    {
        return this->distance(str.src);
    }

#ifndef MIN3
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#endif

    template <typename T>
    std::size_t sstring_t_view<T>::edit_distance(const T *str) const
    {
        if (str && this->src)
        {
            std::size_t len_str = this->sstr_strlen(str), x, y, last, old;
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
                    cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + (this->src[y - 1] == str[x - 1] ? 0 : 1));
                    last = old;
                }
            }
            std::size_t r = cols[this->len];
            std::free(cols);
            return r;
        }
        return this->nerr();
    }

    template <typename T>
    std::size_t sstring_t_view<T>::edit_distance(const sstring_t_view<T> &str) const
    {
        return this->edit_distance(str.src);
    }

    template <typename T>
    double sstring_t_view<T>::percentage_matched(const T *str) const
    {
        if (str && this->src)
        {
            std::size_t len_str = this->sstr_strlen(str);
            std::size_t max = ((this->len > len_str) ? this->len : len_str);
            std::size_t edit_dis = this->edit_distance(str);
            return (max - edit_dis) * 100.0 / max;
        }
        return -1;
    }

    template <typename T>
    double sstring_t_view<T>::percentage_matched(const sstring_t_view<T> &str) const
    {
        return this->percentage_matched(str.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::count(const T *what) const
    {
        if (what && this->src)
        {
            std::size_t cnt = 0, what_len = this->sstr_strlen(what);
            const T *sub = this->src;
            while ((sub = this->fast_strstr(sub, this->sstr_strlen(sub), what)))
            {
                cnt++;
                sub += what_len;
            }
            return cnt;
        }
        return 0;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::count(const sstring_t_view<T> &what) const
    {
        return this->count(what.src);
    }

    template <typename T>
    std::size_t sstring_t_view<T>::count_char(const T what) const
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

    template <typename T>
    sstring_t_view<char> sstring_t_view<T>::soundex() const
    {
        if (this->src)
        {
            std::size_t s = 1;
            const char *map = "01230120022455012623010202"; // not stored in heap memory, do not free it
            T c;
            char res[5] = {};
            res[0] = std::toupper(this->src[0]);
            for (std::size_t i = 1; i < this->len; ++i)
            {
                c = std::toupper(this->src[i]) - 65;
                if (c >= 0 && c <= 25) // from ASCII table
                {
                    if (map[static_cast<std::size_t>(c)] != 0)
                    {
                        if (map[static_cast<std::size_t>(c)] != res[s - 1])
                        {
                            res[s] = map[static_cast<std::size_t>(c)];
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
            return sstring_t_view<char>(res);
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::most_used(const T *dl) const
    {
        if (dl && this->src)
        {
            sstring_t_view ret;
            vector_t<sstring_t_view<T>> vec = this->split(dl);
            std::unordered_map<sstring_t_view<T>, std::size_t> map;
            for (std::size_t i = 0; i < vec.length(); i++)
            {
                map[std::move(vec[i])] += 1;
            }
            vec.erase();

            std::size_t max = 0;
            for (auto &&[key, value] : map)
            {
                if (max < value)
                {
                    max = value;
                    ret = std::move(key);
                }
            }
            return ret;
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::most_used(const sstring_t_view<T> &dl) const
    {
        return this->most_used(dl.src);
    }

    template <typename T>
    T sstring_t_view<T>::most_used_char() const
    {
        if (this->src)
        {
            std::unordered_map<T, std::size_t> freq;
            for (std::size_t i = 0; i < this->len; i++)
                freq[this->src[i]] += 1;

            T _char_t_ = 0;
            std::size_t max = 0;
            for (const auto &[key, value] : freq)
            {
                if (max < value)
                {
                    max = value;
                    _char_t_ = key;
                }
            }
            return _char_t_;
        }
        return 0;
    }

    template <typename T>
    vector_t<sstring_t_view<T>> sstring_t_view<T>::split(const T *str) const
    {
        if (this->src && str)
        {
            if (str[0] == 0)
            {
                vector_t<sstring_t_view<T>> x(this->len);
                for (std::size_t i = 0; i < this->len; i++)
                    x.add(this->src[i]);
                return x;
            }
            T *temp = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
            exit_heap_fail(temp);
            std::memmove(temp, this->src, this->len * sizeof(T));
            std::size_t str_len = this->sstr_strlen(str);
            T *tok = this->fast_strtok(temp, str, str_len);
            vector_t<sstring_t_view<T>> x;
            while (tok)
            {
                x.add(tok);
                tok = this->fast_strtok(nullptr, str, str_len);
                if (!tok)
                    break;
            }
            std::free(temp);
            return x;
        }
        return vector_t<sstring_t_view<T>>();
    }

    template <typename T>
    vector_t<sstring_t_view<T>> sstring_t_view<T>::split(const sstring_t_view<T> &str) const
    {
        return this->split(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::sort()
    {
        if (this->src)
            std::sort(this->src, this->src + this->len, [](T c1, T c2)
                      { return c1 - c2; });
        return *this;
    }

    template <typename T>
    bool sstring_t_view<T>::save_binary(const char *location, std::size_t bin_len) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "wb");
            if (f != nullptr)
            {
                std::fwrite(this->src, bin_len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::append_binary(const char *location, std::size_t bin_len) const
    {
        if (location && this->src)
        {
            std::FILE *f = std::fopen(location, "ab");
            if (f != nullptr)
            {
                std::fwrite(this->src, bin_len, sizeof(T), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::add_binary(const T *data, std::size_t &bin_len)
    {
        if (data)
        {
            if (!this->src)
            {
                this->len = 0;
                this->src = static_cast<T *>(std::calloc(bin_len + 1, sizeof(T)));
                exit_heap_fail(this->src);
                this->fast_strncat(this->src, data, this->len);
                return *this;
            }
            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + bin_len + 1)));
            exit_heap_fail(this->src);
            this->fast_strncat(this->src, data, this->len);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::encrypt(const T *key)
    {
        if (key && this->src)
        {
            std::size_t val = sstring_t_view(key).hash() % 128;
            bool add = true;

            T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
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

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::encrypt(const sstring_t_view<T> &key)
    {
        return this->encrypt(key.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::decrypt(const T *key)
    {
        if (key && this->src)
        {
            std::size_t val = sstring_t_view(key).hash() % 128;
            bool add_invr = true;

            T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
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

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::decrypt(const sstring_t_view<T> &key)
    {
        return this->decrypt(key.src);
    }

    template <typename T>
    sstring_t_view<char> sstring_t_view<T>::encode_base64() const
    {
        if (this->src)
        {
            // some temps
            const T *temp_src = this->src;
            std::size_t temp_len = this->len;
            // end temps

            const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
            sstring_t_view<char> ret;
            std::size_t i = 0, j = 0;
            unsigned char char_array_3[3] = {}, char_array_4[4] = {};

            while (temp_len--)
            {
                char_array_3[i++] = *(temp_src++);
                if (i == 3)
                {
                    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                    char_array_4[3] = char_array_3[2] & 0x3f;

                    for (i = 0; i < 4; i++)
                        ret += base64_chars[char_array_4[i]];
                    i = 0;
                }
            }

            if (i)
            {
                for (j = i; j < 3; j++)
                    char_array_3[j] = 0;

                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (j = 0; j < i + 1; j++)
                    ret += base64_chars[char_array_4[j]];

                while (i++ < 3)
                    ret += '=';
            }

            return ret;
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::decode_base64(const char *encoded) const
    {
        if (this->src)
        {
            // some temps
            std::size_t temp_len = this->sstr_strlen(encoded);
            const char *encoded_string = encoded;
            // end temp

            const sstring_t_view<char> base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

            std::size_t i = 0, j = 0, in_ = 0;
            unsigned char char_array_4[4] = {}, char_array_3[3] = {};
            sstring_t_view<T> ret;

            while (temp_len-- && (encoded_string[in_] != 61) && (std::isalnum(encoded_string[in_]) || (encoded_string[in_] == 43) || (encoded_string[in_] == 47)))
            {
                char_array_4[i++] = encoded_string[in_];
                in_++;
                if (i == 4)
                {
                    for (i = 0; i < 4; i++)
                        char_array_4[i] = static_cast<unsigned char>(base64_chars.find(char_array_4[i]));

                    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
                    for (i = 0; i < 3; i++)
                        ret += static_cast<T>(char_array_3[i]);
                    i = 0;
                }
            }

            if (i)
            {
                for (j = i; j < 4; j++)
                    char_array_4[j] = 0;

                for (j = 0; j < 4; j++)
                    char_array_4[j] = static_cast<unsigned char>(base64_chars.find(char_array_4[j]));

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

                for (j = 0; j < i - 1; j++)
                    ret += static_cast<T>(char_array_3[j]);
            }

            return ret;
        }
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::decode_base64(const sstring_t_view<char> &encoded) const
    {
        return this->decode_base64(encoded.c_str());
    }

    template <typename T>
    const T *sstring_t_view<T>::cbegin() const
    {
        if (this->src)
            return this->src;
        return nullptr;
    }

    template <typename T>
    const T *sstring_t_view<T>::cend() const
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::begin()
    {
        if (this->src)
            return this->src;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::end()
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    const T *sstring_t_view<T>::crbegin() const
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    const T *sstring_t_view<T>::crend() const
    {
        if (this->src)
            return this->src;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::rbegin()
    {
        if (this->src)
            return this->src + this->len;
        return nullptr;
    }

    template <typename T>
    T *sstring_t_view<T>::rend()
    {
        if (this->src)
            return this->src;
        return nullptr;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::swap(sstring_t_view<T> &__x) noexcept
    {
        T *temp = this->src;
        this->src = __x.src;
        __x.src = temp;

        std::size_t temp_len = this->len;
        this->len = __x.len;
        __x.len = temp_len;

        return *this;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::substr(std::size_t index, std::size_t sub_len) const
    {
        if (index >= this->len || !this->src)
            return nullptr;
        if (sub_len == this->nerr() || index + sub_len > this->len)
            sub_len = this->len - index;
        T *buff = static_cast<T *>(std::calloc(sub_len + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::memmove(buff, this->src + index, sub_len * sizeof(T));

        sstring_t_view ret;
        ret.src = buff;
        ret.len = sub_len;
        return ret;
    }

    template <typename T>
    vector_t<sstring_t_view<T>> sstring_t_view<T>::to_argv(const T *argv0) const
    {
        if (!this->src)
            return vector_t<sstring_t_view<T>>();

        vector_t<sstring_t_view<T>> args;
        if (argv0)
            args.add(argv0);
        sstring_t_view<T> arg;
        bool in_quotes = false;

        for (size_t i = 0; i < this->len; i++)
        {
            T c = this->src[i];
            if (c == 34)
                in_quotes = !in_quotes;
            else if (c == 32 && !in_quotes)
            {
                if (!arg.is_empty())
                {
                    args.add(arg);
                    arg.clear();
                }
            }
            else if (c == 92)
            {
                if (in_quotes && i + 1 < this->len)
                    arg.append_char(this->src[++i]);
            }
            else
                arg.append_char(c);
        }
        if (!arg.is_empty())
            args.add(arg);

        return args;
    }

    template <typename T>
    bool sstring_t_view<T>::is_digit() const
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (!std::isdigit(this->src[i]))
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::is_decimal() const
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
                else if (!std::isdigit(this->src[i]))
                    return false;
            }
            if (point_cnt == 1)
                return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::is_ascii() const
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (this->src[i] < 0 || this->src[i] > 127)
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::is_alphabetic() const
    {
        if (this->src)
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (!std::isalpha(this->src[i]))
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::format_escape_sequence()
    {
        this->replace(convert_sstring<T, char>("\\").get(), convert_sstring<T, char>("\\\\").get());
        this->replace(convert_sstring<T, char>("\a").get(), convert_sstring<T, char>("\\a").get());
        this->replace(convert_sstring<T, char>("\b").get(), convert_sstring<T, char>("\\b").get());
        this->replace(convert_sstring<T, char>("\f").get(), convert_sstring<T, char>("\\f").get());
        this->replace(convert_sstring<T, char>("\n").get(), convert_sstring<T, char>("\\n").get());
        this->replace(convert_sstring<T, char>("\r").get(), convert_sstring<T, char>("\\r").get());
        this->replace(convert_sstring<T, char>("\t").get(), convert_sstring<T, char>("\\t").get());
        this->replace(convert_sstring<T, char>("\v").get(), convert_sstring<T, char>("\\v").get());
        this->replace(convert_sstring<T, char>("\"").get(), convert_sstring<T, char>("\\\"").get());
        this->replace(convert_sstring<T, char>("\'").get(), convert_sstring<T, char>("\\\'").get());
        this->replace(convert_sstring<T, char>("\?").get(), convert_sstring<T, char>("\\\?").get());
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::insert(const T *str, std::size_t index)
    {
        if (str && this->src && index <= this->len)
        {
            std::size_t str_len = this->sstr_strlen(str);
            this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * (this->len + str_len + 1)));
            exit_heap_fail(this->src);

            for (std::size_t i = this->len; i >= index; i--)
            {
                this->src[i + str_len] = this->src[i];
                this->src[i] = 0;
                if (i == 0)
                    break;
            }
            std::memmove(this->src + index, str, str_len * sizeof(T));
            this->len += str_len;
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::insert(const sstring_t_view<T> &str, std::size_t index)
    {
        return this->insert(str.src, index);
    }

    template <typename T>
    bool sstring_t_view<T>::starts_with(const T *str) const
    {
        if (str && this->src)
        {
            if (this->sstr_strlen(str) > this->len)
                return false;
            for (std::size_t i = 0; str[i] != 0 && this->src[i] != 0; i++)
                if (this->src[i] != str[i])
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::starts_with(const sstring_t_view<T> &str) const
    {
        return this->starts_with(str.src);
    }

    template <typename T>
    bool sstring_t_view<T>::ends_with(const T *str) const
    {
        if (str && this->src)
        {
            std::size_t str_len = this->sstr_strlen(str);
            if (str_len > this->len)
                return false;
            for (std::size_t i = this->len - str_len, z = 0; str[z] != 0 && this->src[i] != 0; i++, z++)
                if (this->src[i] != str[z])
                    return false;
            return true;
        }
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::ends_with(const sstring_t_view<T> &str) const
    {
        return this->ends_with(str.src);
    }

    template <typename T>
    vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> sstring_t_view<T>::lexer() const
    {
        vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> vec;
        sstring_t_view<T> toks;
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
            else if (std::isdigit(this->src[i]))
            {
                toks.clear();
                while (std::isdigit(this->src[i]))
                    toks.append_char(this->src[i++]);
                vec.add({toks, lexer_token::INTEGER});
            }
            else if (this->src[i] == 92 || this->src[i] == 7 || this->src[i] == 8 || this->src[i] == 12 || this->src[i] == 10 || this->src[i] == 13 || this->src[i] == 9 || this->src[i] == 11 || this->src[i] == 34 || this->src[i] == 39 || this->src[i] == 63)
            {
                toks.clear();
                while (this->src[i] == 92 || this->src[i] == 7 || this->src[i] == 8 || this->src[i] == 12 || this->src[i] == 10 || this->src[i] == 13 || this->src[i] == 9 || this->src[i] == 11 || this->src[i] == 34 || this->src[i] == 39 || this->src[i] == 63)
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
            {
                toks.clear();
                while (!(this->src[i] > 0 && this->src[i] <= 127)) // while (not ascii) -> for non ascii characters
                    toks.append_char(this->src[i++]);
                vec.add({toks, lexer_token::WORD});
            }
        }
        vec.add({sstring_t_view<T>(), lexer_token::NULL_END});
        return vec;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::from_lexer(const vector_t<heap_pair<sstring_t_view<T>, enum lexer_token>> &toks)
    {
        if (toks.length() != 0)
        {
            if (this->src)
                std::free(this->src);
            this->len = 0;

            std::size_t buff_len = 0;
            for (std::size_t i = 0; i < toks.length(); i++)
                buff_len += toks[i].first().len;

            this->src = static_cast<T *>(std::calloc(buff_len + 1, sizeof(T)));
            exit_heap_fail(this->src);

            for (std::size_t i = 0; i < toks.length(); i++)
                this->fast_strncat(this->src, toks[i].first().src, this->len);
        }
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::set_formatted(std::size_t buffer_length, const char *__format__, ...)
    {
        if (!__format__)
            return *this;

        char *buff = static_cast<char *>(std::calloc(buffer_length + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::va_list ar;
        va_start(ar, __format__);
        std::vsnprintf(buff, buffer_length, __format__, ar);
        va_end(ar);

        if (this->src)
            std::free(this->src);

        this->src = reinterpret_cast<T *>(buff);
        this->len = 0;
        while (this->src[this->len] != 0)
            this->len++;
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::append_formatted(std::size_t buffer_length, const char *__format__, ...)
    {
        if (!__format__)
            return *this;

        char *buff = static_cast<char *>(std::calloc(buffer_length + 1, sizeof(T)));
        exit_heap_fail(buff);

        std::va_list ar;
        va_start(ar, __format__);
        std::vsnprintf(buff, buffer_length, __format__, ar);
        va_end(ar);

        if (!this->src)
        {
            this->src = reinterpret_cast<T *>(buff);
            this->len = 0;
            while (this->src[this->len] != 0)
                this->len++;
        }
        else
        {
            this->append(convert_sstring<T, char>(buff).get());
            std::free(buff);
        }
        return *this;
    }

    template <typename T>
    bool sstring_t_view<T>::resize(std::size_t new_len)
    {
        if (new_len > 0 && new_len > this->len)
        {
            if (this->src)
            {
                this->src = static_cast<T *>(std::realloc(this->src, sizeof(T) * new_len));
                exit_heap_fail(this->src);
                this->init_n_zeroes(this->src, this->len, new_len);
            }
            else
            {
                this->src = static_cast<T *>(std::calloc(new_len, sizeof(T)));
                exit_heap_fail(this->src);
            }
            return true;
        }
        return false;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::shrink_to_fit()
    {
        if (!this->src)
            return *this;
        T *buff = static_cast<T *>(std::calloc(this->len + 1, sizeof(T)));
        exit_heap_fail(buff);
        std::size_t tempLen = 0;
        this->fast_strncat(buff, this->src, tempLen);
        std::free(this->src);
        this->src = buff;
        this->len = tempLen; // same though
        return *this;
    }

    template <typename T>
    std::size_t sstring_t_view<T>::hash() const
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

    template <typename T>
    sstring_t_view<char> sstring_t_view<T>::hash_digest() const
    {
        std::size_t h = this->hash();
        sstring_t_view<char> digest = this->to_sstring(h);
        digest = digest.encode_base64();
        return digest;
    }

    template <typename T>
    const T &sstring_t_view<T>::operator[](std::size_t n) const
    {
        if (this->len >= n && this->src)
            return this->src[n];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    T &sstring_t_view<T>::operator[](std::size_t n)
    {
        if (this->len >= n && this->src)
            return this->src[n];
        else
        {
            std::fprintf(stderr, "err: out-of-range\n");
            std::exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::operator+(const T c) const
    {
        sstring_t_view x = sstring_t_view(this->src);
        x.append_char(c);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::operator+(const T *str) const
    {
        sstring_t_view x = sstring_t_view(this->src);
        x.append(str);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::operator+(const sstring_t_view<T> &str) const
    {
        sstring_t_view x = sstring_t_view(this->src);
        x.append(str.src);
        return x;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const T c)
    {
        return this->append_char(c);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const T *str)
    {
        return this->append(str);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const sstring_t_view<T> &str)
    {
        return this->append(str.src);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const std::initializer_list<T> &list)
    {
        for (const auto &i : list)
            this->append_char(i);
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator+=(const std::initializer_list<sstring_t_view<T>> &list)
    {
        for (const auto &i : list)
            this->append(i.src);
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(const T c)
    {
        return this->set_char(c);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(const T *str)
    {
        return this->set(str);
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(const sstring_t_view<T> &str)
    {
        if (this != &str)
            return this->set(str.src);
        return *this;
    }

    template <typename T>
    sstring_t_view<T> &sstring_t_view<T>::operator=(sstring_t_view<T> &&__s) noexcept
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

    template <typename T>
    bool sstring_t_view<T>::operator==(const T *str) const
    {
        return this->compare(str);
    }

    template <typename T>
    bool sstring_t_view<T>::operator==(const sstring_t_view<T> &str) const
    {
        return this->compare(str.src);
    }

    template <typename T>
    bool sstring_t_view<T>::operator<(const T *str) const
    {
        if (this->lexicographical_comparison(str) < 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator<(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) < 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>(const T *str) const
    {
        if (this->lexicographical_comparison(str) > 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) > 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator<=(const T *str) const
    {
        if (this->lexicographical_comparison(str) <= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator<=(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) <= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>=(const T *str) const
    {
        if (this->lexicographical_comparison(str) >= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator>=(const sstring_t_view<T> &str) const
    {
        if (this->lexicographical_comparison(str.src) >= 0)
            return true;
        return false;
    }

    template <typename T>
    bool sstring_t_view<T>::operator!=(const T *str) const
    {
        return !(this->compare(str));
    }

    template <typename T>
    bool sstring_t_view<T>::operator!=(const sstring_t_view<T> &str) const
    {
        return !(this->compare(str.src));
    }

    template <typename T>
    constexpr inline std::size_t sstring_t_view<T>::nerr() const noexcept
    {
        return static_cast<std::size_t>(-1);
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &out, const sstring_t_view<T> &obj)
    {
        out << obj.c_str();
        return out;
    }

    template <typename T>
    std::wostream &operator<<(std::wostream &out, const sstring_t_view<T> &obj)
    {
        out << obj.c_str();
        return out;
    }

    template <typename T>
    sstring_t_view<T>::~sstring_t_view()
    {
        if (this->src)
            std::free(this->src);
        this->src = nullptr;
        this->len = 0;
    }

    template <typename T>
    void sstring_t_view<T>::sort(sstring_t_view *arr, std::size_t len)
    {
        std::sort(arr, arr + len);
    }

    template <typename T>
    void sstring_t_view<T>::sort(T **arr, std::size_t len)
    {
        std::sort(arr, arr + len, [](T *a, T *b)
                  { return sstring_t_view(a) < sstring_t_view(b); });
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(T c)
    {
        sstring_t_view x;
        x.set_char(c);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(bool boolean)
    {
        sstring_t_view x;
        if (boolean)
            x = convert_sstring<T, char>("true").get();
        else
            x = convert_sstring<T, char>("false").get();
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(const T *str)
    {
        sstring_t_view x = str;
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(void *ptr)
    {
        char s[std::numeric_limits<std::size_t>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<std::size_t>::digits10 + 1, "%p", ptr);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed short int x)
    {
        char s[std::numeric_limits<signed short int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed short int>::digits10 + 2, "%hi", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned short int x)
    {
        char s[std::numeric_limits<unsigned short int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned short int>::digits10 + 1, "%hu", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed int x)
    {
        char s[std::numeric_limits<signed int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed int>::digits10 + 2, "%d", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned int x)
    {
        char s[std::numeric_limits<unsigned int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned int>::digits10 + 1, "%i", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed long int x)
    {
        char s[std::numeric_limits<signed long int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed long int>::digits10 + 2, "%ld", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned long int x)
    {
        char s[std::numeric_limits<unsigned long int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned long int>::digits10 + 1, "%lu", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(signed long long int x)
    {
        char s[std::numeric_limits<signed long long int>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<signed long long int>::digits10 + 2, "%lld", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(unsigned long long int x)
    {
        char s[std::numeric_limits<unsigned long long int>::digits10 + 1] = {};
        std::snprintf(s, std::numeric_limits<unsigned long long int>::digits10 + 1, "%llu", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(float x)
    {
        char s[std::numeric_limits<float>::digits10 + 4] = {};
        std::snprintf(s, std::numeric_limits<float>::digits10 + 4, "%f", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(double x)
    {
        char s[std::numeric_limits<double>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<double>::digits10 + 2, "%lf", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::to_sstring(long double x)
    {
        char s[std::numeric_limits<long double>::digits10 + 2] = {};
        std::snprintf(s, std::numeric_limits<long double>::digits10 + 2, "%Lf", x);
        return sstring_t_view(convert_sstring<T, char>(s).get());
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::get_random(const std::size_t &len)
    {
        sstring_t_view x;
        x.set_random(len);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::get_input()
    {
        sstring_t_view x;
        x.in();
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::open_file(const sstring_t_view<char> &location)
    {
        sstring_t_view x;
        x.open(location);
        return x;
    }

    template <typename T>
    sstring_t_view<T> sstring_t_view<T>::end_line()
    {
#if defined __linux__ || defined linux || defined __linux
        return sstring_t_view(convert_sstring<T, char>("\n").get());
#elif _WIN32 || defined _WIN64 || defined __CYGWIN__
        return sstring_t_view(convert_sstring<T, char>("\r\n").get());
#elif defined __unix__ || defined __unix || defined unix
        return sstring_t_view(convert_sstring<T, char>("\n").get());
#elif defined __APPLE__ || defined __MACH__
        return sstring_t_view(convert_sstring<T, char>("\n").get());
#elif defined __FreeBSD__
        return sstring_t_view(convert_sstring<T, char>("\n").get());
#elif defined __ANDROID__
        return sstring_t_view(convert_sstring<T, char>("\n").get());
#else
        return sstring_t_view(convert_sstring<T, char>("\n").get());
#endif
    }

    using sstring = sstring_t_view<char>;
    using usstring = sstring_t_view<unsigned char>;
    using wsstring = sstring_t_view<wchar_t>;
#if defined(__cpp_char8_t)
    using u8sstring = sstring_t_view<char8_t>;
#endif
    using u16sstring = sstring_t_view<char16_t>;
    using u32sstring = sstring_t_view<char32_t>;
}

namespace std
{
    template <typename T>
    struct hash<openutils::sstring_t_view<T>>
    {
        std::size_t operator()(const openutils::sstring_t_view<T> &str) const
        {
            return str.hash();
        }
    };
};

#endif
