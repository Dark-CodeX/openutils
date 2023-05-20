/**
 * @file sstring_class.hh
 * @brief This file contains class declaration of `sstring_t_view`. Do NOT directly include this file.
 * @license This file is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007. You may obtain a copy of this license at https://www.gnu.org/licenses/gpl-3.0.en.html.
 * @version 3.0.0
 * @author Tushar Chaurasia (Dark-CodeX)
 */

#ifndef OPENUTILS_SSTRING_CLASS_DEFINED
#define OPENUTILS_SSTRING_CLASS_DEFINED

#include <cstring>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include <ostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <openutils/heap-pair/heap-pair.hh>
#include <openutils/vector/vector.hh>

namespace openutils
{
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

    public:
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
         * @brief Prints `this->src` to `stdout`, and flushes `stdout`.
         * @return number of characters printed to `stdout`
         */
        std::size_t print() const;

        /**
         * @brief Prints `this->src` and a new line to `stdout`, and flushes `stdout`.
         * @return number of characters printed to `stdout`
         */
        std::size_t println() const;

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

    /**
     * @brief This function converts <char_type> to <another_char_type>, where `char_type` could be `char`, `unsigned char`, `wchar_t`, `char8_t`, `char16_t` and `char32_t`.
     * @brief NOTE: Data may loss.
     * @tparam TO Convert to [final]
     * @tparam FROM Convert from [initial]
     * @param frm c-style string to convert
     * @return sstring_t_view<TO> copy of converted sstring
     */
    template <typename TO, typename FROM>
    sstring_t_view<TO> static convert_sstring(const FROM *frm);

    /**
     * @brief This function converts <char_type> to <another_char_type>, where `char_type` could be `char`, `unsigned char`, `wchar_t`, `char8_t`, `char16_t` and `char32_t`.
     * @brief NOTE: Data may loss.
     * @tparam TO Convert to [final]
     * @tparam FROM Convert from [initial]
     * @param frm sstring to convert
     * @return sstring_t_view<TO> copy of converted sstring
     */
    template <typename TO, typename FROM>
    sstring_t_view<TO> static convert_sstring(const sstring_t_view<FROM> &frm);

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
}

#endif