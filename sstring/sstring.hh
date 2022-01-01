/**
 * This header file is written to manage string data safely under C++ programming language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "sstring.h" under "sstring" directory
 * sstring: version 1.5.7
 * MIT License
 *
 * Copyright (c) 2021 Tushar Chaurasia
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

#pragma once

#include <ostream>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include "binary.h"
#include "morse_code.h"

#define sstring_version "1.5.7"

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

            std::size_t len = std::strlen(str);

            for (std::size_t i = 0; i < len; i++)
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

            std::size_t len = std::strlen((const char *)str);

            for (std::size_t i = 0; i < len; i++)
            {
                hash_val = (hash_val + (str[i] - 97 + 1) * power_of_p) % m;
                power_of_p = (power_of_p * p) % m;
            }
            return (hash_val % m + m) % m;
        }
    };
};

namespace openutils
{
    /** sstring class for storing 1D array chars */
    class sstring;
    /** parse_t class for storing 2D array of tokens */
    class parse_t;
    /** split_t class for storing 2D array of splitted strings */
    class split_t;

    /**
     * Linear time complexity = O(n), where n is the length of `src`. NOTE: `dest` must have enough space for `src`.
     * @param dest string where `src` is going to append
     * @param src string to be appended
     * @param size where to append `src`
     */
    void fast_strncat(char *dest, const char *src, std::size_t &size);

    /**
     * Converts escape sequences to their representable strings (as const).
     * @param c escape sequence of the character
     * @returns representable string of escape sequences, if `c` is not an escape sequence then NUL is returned
     */
    const char *char_to_esc_seq(char c);

    /**
     * Converts strings to their respective escape sequences, if possible.
     * To get escape sequence as (char) use `char c = *esc_seq_to_char_ptr("\\n");`
     * @param c string
     * @returns escape sequence of `c`, otherwise returns `c`
     */
    const char *esc_seq_to_char_ptr(const char *c);
    int strcmp_void(const void *a1, const void *a2);
    int compare_chars(const void *c1, const void *c2);

    class sstring
    {
    private:
        char *src;
        std::size_t len;

    public:
        sstring(const char *src = nullptr, std::size_t alloc_size = 1UL);
        sstring(const sstring &other);
        sstring(sstring &&other) noexcept;
        sstring(std::initializer_list<char> list);
        sstring(std::initializer_list<sstring> list);
        sstring(std::initializer_list<const char *> list);
        sstring(const char c);
        void set(const char *src);
        void set_char(const char c);
        void set_upto(const char *src, std::size_t N);
        void set_random(const std::size_t len);
        bool set_array(const char **src, char char_between, std::size_t from, std::size_t till, std::size_t len);
        char *get() const;
        void append(const char *src);
        void append_char(const char c);
        void append_upto(const char *src, std::size_t N);
        void append_start(const char *src);
        void append_start_char(const char c);
        void append_start_upto(const char *src, std::size_t N);
        bool append_array(const char **src, char char_between, std::size_t from, std::size_t till, std::size_t len);
        bool append_start_array(const char **src, char char_between, std::size_t from, std::size_t till, std::size_t len);
        bool empty() const;
        void replace_char(const char old, const char new_);
        void char_set(const char what, std::size_t where);
        char char_get(std::size_t where) const;
        std::size_t length() const;
        bool compare(const char *T1) const;
        bool compare_upto(const char *T1, std::size_t N) const;
        void print(bool add_next_line, const char *__format__, ...) const;
        void replace(const char *old, const char *new_);
        const char *c_str() const;
        bool save(const char *location) const;
        bool append_file(const char *location) const;
        bool open(const char *location);
        void clear();
        void to_upper();
        void to_lower();
        void swap_case();
        void to_binary();
        bool from_binary();
        long double entropy() const;
        bool contains(const char *str) const;
        std::size_t contains_char(const char c) const;
        void to_set();
        bool copy(sstring &dest);
        void to_hexadecimal();
        bool from_hexadecimal();
        std::size_t find(const char *sub) const;
        bool in(bool get_line, std::size_t buff_size);
        sstring getline(std::size_t line) const;
        void reverse();
        std::size_t remove(const char *sub);
        std::size_t remove_char(char c);
        std::size_t remove_extra_char(char c);
        std::size_t remove_range(std::size_t from, std::size_t till);
        bool intersect(std::size_t from, std::size_t till);
        std::size_t distance(const char *src) const;
        std::size_t edit_distance(const char *src) const;
        long double percentage_matched(const char *src) const;
        std::size_t count(const char *what) const;
        std::size_t count_char(const char what) const;
        sstring soundex() const;
        sstring most_used(const char *dl) const;
        char most_used_char() const;
        split_t split(const char *str);
        void sort();
        std::size_t open_binary(const char *location);
        bool save_binary(const char *location, std::size_t len) const;
        bool append_binary(const char *location, std::size_t len) const;
        std::size_t add_binary(const char *data, std::size_t len);
        bool print_binary(std::size_t len) const;
        bool encrypt(const char *key);
        bool decrypt(const char *key);
        std::size_t begin() const;
        std::size_t end() const;
        bool to_morse_code();
        bool from_morse_code();
        bool is_digit() const;
        bool is_decimal() const;
        bool is_ascii() const;
        bool is_alphabetic() const;
        void format_escape_sequence();
        bool insert(const char *src, std::size_t index);
        bool starts_with(const char *src) const;
        bool ends_with(const char *src) const;
        parse_t parse();
        bool from_parse_t(parse_t toks);
        bool set_formatted(std::size_t buffer_length, const char *__format__, ...);
        bool append_formatted(std::size_t buffer_length, const char *__format__, ...);
        bool resize(std::size_t new_len);
        std::size_t hash() const;
        char operator[](std::size_t n) const;
        sstring operator+(const sstring &str);
        sstring operator+(const char str);
        sstring operator+(const char *str);
        void operator+=(const sstring &str);
        void operator+=(const char str);
        void operator+=(const char *str);
        void operator+=(std::initializer_list<char> list);
        void operator+=(std::initializer_list<sstring> list);
        void operator=(const sstring &str);
        void operator=(const char *str);
        void operator=(const char c);
        bool operator==(const sstring &str) const;
        bool operator==(const char *str) const;
        bool operator!=(const sstring &str) const;
        bool operator!=(const char *str) const;
        sstring &operator=(const sstring &&__s) noexcept;
        const std::size_t nerr = (std::size_t)-1;
        friend std::ostream &operator<<(std::ostream &out, const sstring &obj);
        ~sstring();
    };

    sstring to_sstring(char str);
    sstring to_sstring(const char *str);
    sstring to_sstring(void *ptr);
    sstring to_sstring(signed short int x);
    sstring to_sstring(unsigned short int x);
    sstring to_sstring(signed int x);
    sstring to_sstring(unsigned int x);
    sstring to_sstring(signed long int x);
    sstring to_sstring(unsigned long int x);
    sstring to_sstring(signed long long int x);
    sstring to_sstring(unsigned long long int x);
    sstring to_sstring(float x);
    sstring to_sstring(double x);
    sstring to_sstring(long double x);
    sstring get_random(std::size_t len);
    sstring open_file(const sstring &location);
    sstring end_line();

    enum parse_token
    {
        WORD,
        INTEGER,
        ESC_SEQ,
        SPECIAL_CHAR,
        WHITESPACE,
        NULL_END
    } parse_token;

    class parse_t
    {
    private:
        char **src;
        enum parse_token *type;
        std::size_t len, cap;

    public:
        parse_t(std::size_t len = 1LL);
        bool add(const char *src, enum parse_token type);
        sstring get(const std::size_t n) const;
        enum parse_token get_type(const std::size_t n) const;
        sstring operator[](const std::size_t n) const;
        std::size_t length() const;
        parse_t(parse_t &&other) noexcept;
        parse_t &operator=(const parse_t &&__pt) noexcept;
        ~parse_t();
    };

    class split_t
    {
    private:
        char **src;
        std::size_t len, cap;

    public:
        split_t(std::size_t len = 1LL);
        bool add(const char *src);
        sstring get(const std::size_t n) const;
        sstring operator[](const std::size_t n) const;
        std::size_t length() const;
        split_t(split_t &&other) noexcept;
        split_t &operator=(const split_t &&__st) noexcept;
        ~split_t();
    };

    // definitions

    void fast_strncat(char *dest, const char *src, std::size_t &size)
    {
        if (dest && src)
            while ((dest[size] = *src++))
                size += 1;
    }

    sstring::sstring(const char *src, std::size_t alloc_size)
    {
        if (src)
        {
            this->src = (char *)std::calloc(sizeof(char) * (std::strlen(src) + 1), sizeof(char));
            std::size_t l = 0;
            fast_strncat(this->src, src, l);
            this->len = l;
        }
        else
        {
            this->src = (char *)std::calloc(sizeof(char) * (alloc_size + 1), sizeof(char));
            this->len = 0;
        }
    }

    sstring::sstring(const sstring &other)
    {
        this->set(other.c_str());
    }

    sstring::sstring(sstring &&other) noexcept : src(nullptr), len(0)
    {
        src = other.src;
        len = other.len;
        other.src = nullptr;
        other.len = 0;
    }

    sstring::sstring(std::initializer_list<char> list)
    {
        std::size_t len = sizeof(char) * list.size(), currlen = 0;
        this->src = (char *)std::calloc(len + 1, sizeof(char));
        for (std::initializer_list<char>::const_iterator i = list.begin(); i != list.end() && *i != '\0'; i++)
            this->src[currlen++] = *i;
        this->len = currlen;
    }

    sstring::sstring(std::initializer_list<sstring> list)
    {
        this->src = (char *)std::calloc(sizeof(char) * 1, sizeof(char));
        this->len = 0;
        for (std::initializer_list<sstring>::const_iterator i = list.begin(); i != list.end(); i++)
            this->append(i->c_str());
    }

    sstring::sstring(std::initializer_list<const char *> list)
    {
        this->src = (char *)std::calloc(sizeof(char) * 1, sizeof(char));
        this->len = 0;
        for (std::initializer_list<const char *>::const_iterator i = list.begin(); i != list.end(); i++)
            this->append(*i);
    }

    sstring::sstring(const char c)
    {
        this->src = (char *)std::calloc(sizeof(char) * 1, sizeof(char));
        this->len = 0;
        this->set_char(c);
    }

    void sstring::set(const char *src)
    {
        if (src)
        {
            std::free(this->src);
            std::size_t len = std::strlen(src);
            this->src = (char *)std::calloc(sizeof(char) * (len + 1), sizeof(char));
            std::strcpy(this->src, src);
            this->len = len;
        }
    }

    void sstring::set_char(const char c)
    {
        if (c != '\0')
        {
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * 2, sizeof(char));
            std::strncpy(this->src, &c, 1);
            this->len = 1;
        }
    }

    void sstring::set_upto(const char *src, std::size_t N)
    {
        std::size_t l = 0;
        if (src && N <= (l = std::strlen(src)))
        {
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (N + 1), sizeof(char));
            std::strncpy(this->src, src, N);
            this->len = N;
        }
    }

    void sstring::set_random(const std::size_t len)
    {
        if (len > 0)
        {
            char *buff = (char *)std::calloc(sizeof(char) * (len + 1), sizeof(char));
            // random ascii character betweem 32 and 126, inclusive
            for (std::size_t i = 0; i < len; i++)
                buff[i] = (rand() % (126 - 32 + 1)) + 32;
            std::free(this->src);
            this->src = (char *)std::calloc((sizeof(char) * len) + 1, sizeof(char));
            std::strcpy(this->src, (const char *)buff);
            std::free(buff);
            this->len = len;
        }
    }

    bool sstring::set_array(const char **src, char char_between, std::size_t from, std::size_t till, std::size_t len)
    {
        if (src)
        {
            if (till > len || from > len)
                return false;
            std::size_t cnt_t = 0;
            for (std::size_t i = from; i < till; i++)
            {
                if (src[i] == nullptr)
                    return false;
                else
                    cnt_t += std::strlen(src[i]);
            }
            if (char_between != '\0')
                cnt_t += len + 1;
            char *buff = (char *)std::calloc((sizeof(char) * cnt_t) + 1, sizeof(char)), bw[3] = "\0\0";
            std::size_t track = 0;
            for (std::size_t i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, track);
            }
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (track + 1), sizeof(char));
            std::strcpy(this->src, (const char *)buff);
            this->len = track;
            std::free(buff);
            return true;
        }
        return false;
    }

    char *sstring::get() const
    {
        return this->src;
    }

    void sstring::append(const char *src)
    {
        if (src)
        {
            std::size_t len = 0, l = std::strlen(src);
            if ((len = this->len) == 0) // string is empty
            {
                std::free(this->src);
                this->src = (char *)std::calloc(sizeof(char) * (l + 1), sizeof(char));
                std::strcpy(this->src, src);
                this->len = l;
            }
            else
            {
                this->src = (char *)std::realloc(this->src, sizeof(char) * (l + len + 1));
                fast_strncat(this->src, src, len);
                this->len = len;
            }
        }
    }

    void sstring::append_char(const char c)
    {
        if (c != '\0')
        {
            std::size_t len = 0;
            if ((len = this->len) == 0)
            {
                std::free(this->src);
                this->src = (char *)std::calloc(sizeof(char) * 2, sizeof(char));
                std::strncpy(this->src, &c, 1);
                this->len = 1;
            }
            else
            {
                this->src = (char *)std::realloc(this->src, (sizeof(char) * 2) + (len + 1));
                char __dat[3] = "\0\0";
                __dat[0] = c;
                fast_strncat(this->src, (const char *)__dat, len);
                this->len = len;
            }
        }
    }

    void sstring::append_upto(const char *src, std::size_t N)
    {
        std::size_t l = 0;
        if (src && N <= (l = strlen(src)) && N != 0)
        {
            std::size_t len = 0;
            if ((len = this->len) == 0) // string is empty
            {
                std::free(this->src); // used calloc in `init_str` function
                this->src = (char *)std::calloc(sizeof(char) * (N + 1), sizeof(char));
                std::strncpy(this->src, src, N); // copy `src` to `a`.
                this->len = N;
            }
            else
            {
                this->src = (char *)std::realloc(this->src, sizeof(char) * (N + len + 1));
                char *buff = (char *)std::calloc(sizeof(char) * (N + 1), sizeof(char));
                std::strncpy(buff, src, N);
                fast_strncat(this->src, (const char *)buff, len);
                std::free(buff);
                this->len = len;
            }
        }
    }

    void sstring::append_start(const char *src)
    {
        if (src)
        {
            std::size_t len = 0, l = std::strlen(src);
            if ((len = this->len) == 0) // string is empty
            {
                std::free(this->src); // used calloc in `init_str` function
                this->src = (char *)std::calloc(sizeof(char) * (l + 1), sizeof(char));
                std::strcpy(this->src, src); // copy `src` to `a`.
                this->len = l;
            }
            else
            {
                char *buff = (char *)std::calloc(sizeof(char) * (l + len + 1), sizeof(char));
                std::size_t track = 0;
                fast_strncat(buff, src, track);
                fast_strncat(buff, (const char *)this->src, track);
                std::free(this->src);
                this->src = (char *)std::calloc((sizeof(char) * track) + 1, sizeof(char));
                track = 0;
                fast_strncat(this->src, (const char *)buff, track);
                std::free(buff);
                this->len = track;
            }
        }
    }

    void sstring::append_start_char(const char c)
    {
        if (c != '\0')
        {
            std::size_t len = 0;
            if ((len = this->len) == 0) // string is empty
            {
                std::free(this->src); // used calloc in `init_str` function
                this->src = (char *)std::calloc(sizeof(char) * 2, sizeof(char));
                std::strncpy(this->src, &c, 1); // copy `c` to `a`.
                this->len = len + 1;
            }
            else
            {
                char ___c[3] = "\0\0";
                ___c[0] = c;
                std::size_t track = 0;
                char *buff = (char *)std::calloc((sizeof(char) * 2) + (len + 1), sizeof(char));
                fast_strncat(buff, (const char *)___c, track);
                fast_strncat(buff, (const char *)this->src, track);
                std::free(this->src);
                this->src = (char *)std::calloc((sizeof(char) * track) + 1, sizeof(char));
                track = 0;
                fast_strncat(this->src, (const char *)buff, track);
                std::free(buff);
                this->len = track;
            }
        }
    }

    void sstring::append_start_upto(const char *src, std::size_t N)
    {
        std::size_t l = 0;
        if (src && N <= (l = std::strlen(src)) && N != 0)
        {
            std::size_t len = 0;
            if ((len = this->len) == 0) // string is empty
            {
                std::free(this->src); // used calloc in `init_str` function
                this->src = (char *)std::calloc(sizeof(char) * (N + 1), sizeof(char));
                std::strncpy(this->src, src, N); // copy `src` to `a`.
                this->len = N;
            }
            else
            {
                char *buff = (char *)std::calloc((sizeof(char) * (len + N + 1)), sizeof(char));
                std::strncpy(buff, src, N);
                std::size_t track = N;
                fast_strncat(buff, (const char *)this->src, track);
                std::free(this->src);
                this->src = (char *)std::calloc((sizeof(char) * track) + 1, sizeof(char));
                track = 0;
                fast_strncat(this->src, (const char *)buff, track);
                std::free(buff);
                this->len = track;
            }
        }
    }

    bool sstring::append_array(const char **src, char char_between, std::size_t from, std::size_t till, std::size_t len)
    {
        if (src)
        {
            if (till > len || from > len)
                return false;
            std::size_t cnt_t = 0;
            for (std::size_t i = from; i < till; i++)
            {
                if (src[i] == nullptr)
                    return false;
                else
                    cnt_t += std::strlen(src[i]);
            }
            if (char_between != '\0')
                cnt_t += len + 1;
            std::size_t slen = this->len, track = 0;
            char *buff = (char *)std::calloc((sizeof(char) * (cnt_t + slen + 1)), sizeof(char)), bw[3] = "\0\0";
            fast_strncat(buff, (const char *)this->src, track);

            if (slen > 0 && (bw[0] = char_between) != '\0')
                fast_strncat(buff, (const char *)bw, track);
            for (std::size_t i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, track);
            }
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (track + 1), sizeof(char));
            track = 0;
            fast_strncat(this->src, (const char *)buff, track);
            std::free(buff);
            this->len = track;
            return true;
        }
        return false;
    }

    bool sstring::append_start_array(const char **src, char char_between, std::size_t from, std::size_t till, std::size_t len)
    {
        if (src)
        {
            if (till > len || from > len)
                return false;
            std::size_t cnt_t = 0;
            for (std::size_t i = from; i < till; i++)
            {
                if (src[i] == nullptr)
                    return false;
                else
                    cnt_t += std::strlen(src[i]);
            }
            if (char_between != '\0')
                cnt_t += len + 1;
            std::size_t slen = this->len, track = 0;
            char *buff = (char *)std::calloc((sizeof(char) * (cnt_t + slen + 1)), sizeof(char)), bw[3] = "\0\0";
            for (std::size_t i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, track);
            }
            if (cnt_t > 2 && (bw[0] = char_between) != '\0')
                fast_strncat(buff, (const char *)bw, track);
            fast_strncat(buff, (const char *)this->src, track);
            std::free(this->src);
            this->src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
            track = 0;
            fast_strncat(this->src, (const char *)buff, track);
            std::free(buff);
            this->len = track;
        }
        return false;
    }

    bool sstring::empty() const
    {
        return (this->len == 0);
    }

    void sstring::replace_char(const char old, const char new_)
    {
        if (old != '\0' && new_ != '\0')
            for (std::size_t i = 0; this->src[i] != '\0'; i++)
                if (this->src[i] == old)
                    this->src[i] = new_;
    }

    void sstring::char_set(const char what, std::size_t where)
    {

        if (this->len >= where && what != '\0')
            this->src[where] = what;
    }

    char sstring::char_get(std::size_t where) const
    {

        if (this->len >= where)
            return this->src[where];
        return (char)'\0';
    }

    std::size_t sstring::length() const
    {
        return std::strlen((const char *)this->src);
    }

    bool sstring::compare(const char *T1) const
    {
        if (T1)
            if (std::strcmp((const char *)this->src, T1) == 0)
                return true;
        return false;
    }

    bool sstring::compare_upto(const char *T1, std::size_t N) const
    {
        if (T1 && strlen(T1) >= N)
            if (std::strncmp((const char *)this->src, T1, N) == 0)
                return true;
        return false;
    }

    void sstring::print(bool add_next_line, const char *__format__, ...) const
    {
        if (__format__)
        {
            std::va_list ar;
            va_start(ar, __format__);
            std::printf("%s", this->src);
            std::vprintf(__format__, ar);
            va_end(ar);
            if (add_next_line == true)
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
        }
    }

    void sstring::replace(const char *old, const char *new_)
    {
        if (old && new_)
        {
            std::size_t i, count_old = 0, len_o = std::strlen(old), len_n = std::strlen(new_);
            const char *temp = (const char *)this->src;
            for (i = 0; temp[i] != '\0'; ++i)
            {
                if (std::strstr((const char *)&temp[i], old) == &temp[i])
                {
                    count_old++;
                    i += len_o - 1;
                }
            }
            char *buff = (char *)std::calloc(sizeof(char) * (i + count_old * (len_n - len_o) + 1), sizeof(char));
            i = 0;
            while (*temp)
            {
                if (std::strstr(temp, old) == temp)
                {
                    std::size_t x = 0;
                    fast_strncat(&buff[i], new_, x);
                    i += len_n;
                    temp += len_o;
                }
                else
                    buff[i++] = *temp++;
            }
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (i + 1), sizeof(char));
            this->len = i;
            i = 0;
            fast_strncat(this->src, (const char *)buff, i);
            std::free(buff);
        }
    }

    const char *sstring::c_str() const
    {
        return (const char *)this->src;
    }

    bool sstring::save(const char *location) const
    {
        if (location)
        {
            std::FILE *f = std::fopen(location, "wb");
            if (f != nullptr)
            {
                std::fwrite((const char *)this->src, this->len, sizeof(char), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    bool sstring::append_file(const char *location) const
    {
        if (location)
        {
            std::FILE *f = std::fopen(location, "ab");
            if (f != nullptr)
            {
                std::fwrite((const char *)this->src, this->len, sizeof(char), f);
                std::fclose(f);
                return true;
            }
        }
        return false;
    }

    bool sstring::open(const char *location)
    {
        if (location)
        {
            std::FILE *f = std::fopen(location, "rb");
            if (f != nullptr)
            {
                std::fseek(f, 0, SEEK_END);
                std::size_t len = std::ftell(f);
                std::fseek(f, 0, SEEK_SET);
                std::free(this->src);
                this->src = (char *)std::calloc(len + 1, sizeof(char));
                std::fread(this->src, len, sizeof(char), f);
                std::fclose(f);
                this->len = len;
                return true;
            }
        }
        return false;
    }

    void sstring::clear()
    {
        std::free(this->src);
        this->src = (char *)std::calloc(1 * sizeof(char), sizeof(char));
        this->len = 0;
    }

    void sstring::to_upper()
    {
        for (std::size_t i = 0; this->src[i] != '\0'; ++i)
        {
            if (this->src[i] <= 122 && this->src[i] >= 97)
                this->src[i] -= 32;
        }
    }

    void sstring::to_lower()
    {
        for (std::size_t i = 0; this->src[i] != '\0'; ++i)
        {
            if (this->src[i] <= 90 && this->src[i] >= 65)
                this->src[i] += 32;
        }
    }

    void sstring::swap_case()
    {
        for (std::size_t i = 0; this->src[i] != '\0'; ++i)
        {
            if (this->src[i] <= 90 && this->src[i] >= 65)
                this->src[i] += 32;
            else if (this->src[i] <= 122 && this->src[i] >= 97)
                this->src[i] -= 32;
        }
    }

    void sstring::to_binary()
    {
        std::size_t len = this->len, size = 0;
        char *buff = (char *)std::calloc(((2 * (len * 8)) + 1) * sizeof(char), sizeof(char));
        for (std::size_t i = 0; i < len; ++i)
        {
            fast_strncat(buff, binary_data[(std::size_t)this->src[i]], size);
            if (i < len - 1)
                fast_strncat(buff, " ", size);
        }
        std::free(this->src);
        this->src = (char *)std::calloc(sizeof(char) * (size + 1), sizeof(char));
        size = 0;
        fast_strncat(this->src, (const char *)buff, size);
        this->len = size;
        std::free(buff);
    }

    bool sstring::from_binary()
    {
        std::size_t len = this->len;
        // test 1 for checking binary input format
        for (std::size_t i = 0; i < len; i++)
        {
            switch (this->src[i])
            {
            case '1':
            case '0':
            case ' ':
                break;

            default:
                return false;
            }
        }
        // test 2 for checking binary input format
        std::size_t cnt = 0;
        for (std::size_t i = 0; i < len; i++)
            if (this->src[i] == ' ')
                cnt++;
        if ((len - cnt) % 8 != 0 && ((len - cnt) / 8) != (cnt + 1))
            return false;
        char *buff = (char *)std::calloc((len / 8) + 1, sizeof(char));
        char bin[9] = "\0", store[2] = "\0";
        char c = '\0';
        std::size_t z = 0;
        for (std::size_t i = 0, j = 0; i < len; ++i, ++j)
        {
            if (this->src[i] == ' ')
            {
                c = std::strtol(bin, (char **)nullptr, 2);
                store[0] = c;
                fast_strncat(buff, (const char *)store, z);
                j = 0;
            }
            if (i == len - 1)
            {
                bin[j] = this->src[i]; // append last character
                c = std::strtol(bin, (char **)nullptr, 2);
                store[0] = c;
                fast_strncat(buff, store, z);
            }
            bin[j] = this->src[i];
        }
        std::free(this->src);
        this->src = (char *)std::calloc(sizeof(char) * (z + 1), sizeof(char));
        z = 0;
        fast_strncat(this->src, (const char *)buff, z);
        this->len = z;
        std::free(buff);
        return true;
    }

    long double sstring::entropy() const
    {
        std::size_t len = this->len;
        std::size_t cnt = 0, map_append = 0, o = 0;
        bool check = false;
        char *map_char = (char *)std::calloc((sizeof(char) * (len + 1)), sizeof(char));
        std::size_t *map_cnt = (std::size_t *)std::calloc((sizeof(std::size_t) * (len + 1)), sizeof(std::size_t));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; map_char[o] != '\0'; o++)
            {
                if (map_char[o] == this->src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                map_char[map_append] = this->src[cnt];
                map_cnt[map_append] = 1;
                map_append++;
            }
            else
                map_cnt[o] += 1;
        }
        long double result = 0.0f;
        long double freq = 0.0f;
        for (std::size_t i = 0; map_char[i] != '\0'; i++)
        {
            freq = (long double)map_cnt[i] / len;
            result -= freq * (log10l(freq) / log10l(2.0f));
        }
        std::free(map_char);
        std::free(map_cnt);
        return result;
    }

    bool sstring::contains(const char *str) const
    {
        if (str)
            if (std::strstr((const char *)this->src, str) != nullptr)
                return true;
        return false;
    }

    std::size_t sstring::contains_char(const char c) const
    {
        if (c != '\0')
        {
            for (std::size_t i = 0; this->src[i] != '\0'; i++)
                if (this->src[i] == c)
                    return (std::size_t)i;
        }
        return (std::size_t)-1;
    }

    void sstring::to_set()
    {
        std::size_t len = this->len;
        std::size_t cnt = 0, map_append = 0, o = 0;
        bool check = false;
        char *set_char = (char *)std::calloc((sizeof(char) * (len + 1)), sizeof(char));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; set_char[o] != '\0'; o++)
            {
                if (set_char[o] == this->src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                set_char[map_append] = this->src[cnt];
                map_append++;
            }
        }
        std::free(this->src);
        std::size_t set_len = std::strlen((const char *)set_char);
        this->src = (char *)std::calloc(sizeof(char) * (set_len + 1), sizeof(char));
        std::strcpy(this->src, (const char *)set_char);
        this->len = set_len;
        std::free(set_char);
    }

    bool sstring::copy(sstring &dest)
    {
        if (dest.src)
        {
            std::free(dest.src);
            dest.src = (char *)std::calloc(sizeof(char) * (this->len + 1), sizeof(char));
            std::strcpy(dest.src, (const char *)this->src);
            dest.len = this->len;
            return true;
        }
        return false;
    }

    void sstring::to_hexadecimal()
    {
        char *buff = (char *)std::calloc((sizeof(char) * this->len * 2) + 1, sizeof(char));
        std::size_t i = 0, j = 0;
        while (this->src[i] != '\0')
        {
            std::sprintf((char *)buff + j, "%02X", this->src[i]);
            i++, j += 2;
        }
        std::free(this->src);
        this->src = (char *)std::calloc(sizeof(char) * (j + 1), sizeof(char));
        j = 0;
        fast_strncat(this->src, (const char *)buff, j);
        this->len = j;
        std::free(buff);
    }

    bool sstring::from_hexadecimal()
    {
        std::size_t len = this->len;
        // test 1 for checking hexadecimal input format
        for (std::size_t i = 0; i < len; i++)
        {
            switch (this->src[i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                break;

            default:
                return false;
            }
        }
        // test 2 for checking hexadecimal input format
        if (len % 2 != 0)
            return false;
        char *buff = (char *)std::calloc((len) / 2 + 1, sizeof(char));
        char bin[3] = "\0", store[2] = "\0";
        char c = '\0';
        std::size_t z = 0;
        for (std::size_t i = 0, j = 0; i < len; ++i)
        {
            if (i == len - 1)
            {
                bin[j] = this->src[i];
                c = std::strtol(bin, (char **)nullptr, 16);
                store[0] = c;
                fast_strncat(buff, (const char *)store, z);
            }
            if (j == 2)
            {
                j = 0;
                c = std::strtol(bin, (char **)nullptr, 16);
                store[0] = c;
                fast_strncat(buff, (const char *)store, z);
            }
            bin[j] = this->src[i];
            j++;
        }
        std::free(this->src);
        this->src = (char *)std::calloc(sizeof(char) * (z + 1), sizeof(char));
        z = 0;
        fast_strncat(this->src, (const char *)buff, z);
        this->len = z;
        std::free(buff);
        return true;
    }

    std::size_t sstring::find(const char *sub) const
    {
        if (sub)
        {
            char *buff = (char *)std::strstr((const char *)this->src, sub);
            if (buff)
                return (std::size_t)this->len - std::strlen((const char *)buff);
        }
        return (std::size_t)-1;
    }

    bool sstring::in(bool get_line, std::size_t buff_size)
    {
        char *buff = (char *)std::calloc((sizeof(char) * buff_size + 1), sizeof(char));
        std::size_t len_ = 0;
        if (get_line == false)
        {
            char _____format_____[128] = "%%";
            std::sprintf(_____format_____ + 1, "%lu", buff_size);
            std::strcat(_____format_____, "s");
            std::scanf(_____format_____, buff);
            len_ = std::strlen((const char *)buff);
        }
        else
        {
            std::fgets(buff, buff_size, stdin);
            len_ = std::strlen((const char *)buff);
            if (buff[len_ - 1] == '\n')
            {
                buff[len_ - 1] = '\0';
                len_--;
            }
        }
        std::free(this->src);
        this->src = (char *)std::calloc((sizeof(char) * len_) + 1, sizeof(char));
        std::strcpy(this->src, (const char *)buff);
        std::free(buff);
        this->len = len_;
        return true;
    }

    sstring sstring::getline(std::size_t line) const
    {
        std::size_t len = this->len, cnt = 0;
        char *temp = (char *)std::calloc((sizeof(char) * len) + 1, sizeof(char)), *tok;
        std::strcpy(temp, this->src);
        tok = std::strtok(temp, "\n");
        while (tok)
        {
            if (cnt++ == line)
                break;
            tok = std::strtok(nullptr, "\n");
        }
        if (cnt == 0 || tok == nullptr)
        {
            std::free(temp);
            return sstring(nullptr);
        }
        sstring res = sstring((const char *)tok);
        std::free(temp);
        return res;
    }

    void sstring::reverse()
    {
        std::size_t len = this->len, l = len / 2;
        char c = '\0';
        for (std::size_t i = 0; i < l; i++)
        {
            c = this->src[i];
            this->src[i] = this->src[len - i - 1];
            this->src[len - i - 1] = c;
        }
    }

    std::size_t sstring::remove(const char *sub)
    {
        if (sub && sub[0] != '\0')
        {
            char *buff = (char *)std::calloc((sizeof(char) * this->len) + 1, sizeof(char));
            std::strcpy(buff, (const char *)this->src);
            std::size_t len_s = std::strlen(sub), cnt = 0;
            {
                char *temp = buff;
                std::size_t size = 0;
                while ((temp = std::strstr(temp, sub)))
                {
                    size = (size == 0) ? (temp - buff) + strlen(temp + len_s) + 1 : size - len_s;
                    std::memmove(temp, temp + len_s, size - (temp - buff));
                    cnt += len_s;
                }
                std::free(temp);
            }
            std::free(this->src);
            std::size_t len_buff = std::strlen((const char *)buff);
            this->src = (char *)std::calloc((sizeof(char) * len_buff) + 1, sizeof(char));
            std::strcpy(this->src, (const char *)buff);
            std::free(buff);
            this->len = len_buff;
            return cnt;
        }
        return 0;
    }

    std::size_t sstring::remove_char(char c)
    {
        if (c != '\0')
        {
            char *buff = (char *)std::calloc((sizeof(char) * this->len) + 1, sizeof(char));
            std::size_t cnt = 0;
            for (std::size_t i = 0, k = 0; this->src[i] != '\0'; i++)
            {
                if (this->src[i] != c)
                {
                    buff[k] = this->src[i];
                    k++;
                }
                else
                    cnt++;
            }
            std::free(this->src);
            std::size_t buff_len = std::strlen((const char *)buff);
            this->src = (char *)std::calloc((sizeof(char) * buff_len) + 1, sizeof(char));
            std::strcpy(this->src, (const char *)buff);
            std::free(buff);
            this->len = buff_len;
            return cnt;
        }
        return 0;
    }

    std::size_t sstring::remove_extra_char(char c)
    {
        if (c != '\0')
        {
            char *buff = (char *)std::calloc((sizeof(char) * this->len) + 1, sizeof(char));
            std::size_t p = 0, i = 0, cnt = 0;
            while (this->src[p] != '\0')
            {
                if (!(this->src[p] == c && this->src[p + 1] == c))
                {
                    buff[i] = this->src[p];
                    i++;
                }
                else
                    cnt++;
                p++;
            }
            buff[i] = '\0';
            std::free(this->src);
            std::size_t buff_len = std::strlen((const char *)buff);
            this->src = (char *)std::calloc((sizeof(char) * buff_len) + 1, sizeof(char));
            std::strcpy(this->src, (const char *)buff);
            std::free(buff);
            this->len = buff_len;
            return cnt;
        }
        return 0;
    }

    std::size_t sstring::remove_range(std::size_t from, std::size_t till)
    {
        std::size_t len = this->len, cnt = 0;
        if (till > len || from > len || from > till)
            return cnt;
        char *buff = (char *)std::calloc(sizeof(char) * (len - (till - from) + 1), sizeof(char));
        for (std::size_t i = 0, k = 0; i < len; i++)
        {
            if (i == from)
            {
                i += till - from;
                cnt += (till - from);
            }
            if (i < from || i > from)
            {
                buff[k] = this->src[i];
                k++;
            }
        }
        std::free(this->src);
        std::size_t buff_len = std::strlen((const char *)buff);
        this->src = (char *)std::calloc((sizeof(char) * buff_len) + 1, sizeof(char));
        std::strcpy(this->src, (const char *)buff);
        std::free(buff);
        this->len = buff_len;
        return cnt;
    }

    bool sstring::intersect(std::size_t from, std::size_t till)
    {
        std::size_t len = this->len;
        if (till > len || from > len || from > till)
            return false;
        char *buff = (char *)std::calloc(sizeof(char) * ((till - from) + 1), sizeof(char));
        for (std::size_t i = from, k = 0; i < till; i++)
        {
            buff[k] = this->src[i];
            k++;
        }
        std::free(this->src);
        std::size_t buff_len = std::strlen((const char *)buff);
        this->src = (char *)std::calloc((sizeof(char) * buff_len) + 1, sizeof(char));
        std::strcpy(this->src, (const char *)buff);
        std::free(buff);
        this->len = buff_len;
        return true;
    }

    std::size_t sstring::distance(const char *src) const
    {
        if (src)
        {
            if (std::strlen(src) == this->len)
            {
                std::size_t cnt = 0;
                for (std::size_t i = 0; this->src[i] != '\0'; i++)
                    if (this->src[i] != src[i])
                        cnt++;
                return (std::size_t)cnt;
            }
        }
        return (std::size_t)-1;
    }

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX2(x, y) ((x > y) ? x : y)
    std::size_t sstring::edit_distance(const char *src) const
    {
        if (src)
        {
            std::size_t len1 = this->len, len2 = std::strlen(src), x, y, last, old;
            std::size_t *cols = (std::size_t *)std::calloc(sizeof(std::size_t) * (len1 + 1), sizeof(std::size_t));
            for (y = 1; y <= len1; y++)
                cols[y] = y;
            for (x = 1; x <= len2; x++)
            {
                cols[0] = x;
                for (y = 1, last = x - 1; y <= len1; y++)
                {
                    old = cols[y];
                    cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + (this->src[y - 1] == src[x - 1] ? 0 : 1));
                    last = old;
                }
            }
            std::size_t r = cols[len1];
            std::free(cols);
            return r;
        }
        return (std::size_t)-1;
    }

    long double sstring::percentage_matched(const char *src) const
    {
        if (src)
        {
            std::size_t len1 = this->len, len2 = std::strlen(src), x, y, last, old;
            std::size_t *cols = (std::size_t *)std::calloc(sizeof(std::size_t) * (len1 + 1), sizeof(std::size_t));
            for (y = 1; y <= len1; y++)
                cols[y] = y;
            for (x = 1; x <= len2; x++)
            {
                cols[0] = x;
                for (y = 1, last = x - 1; y <= len1; y++)
                {
                    old = cols[y];
                    cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + (this->src[y - 1] == src[x - 1] ? 0 : 1));
                    last = old;
                }
            }
            std::size_t max = MAX2(len1, len2);
            std::size_t r = cols[len1];
            std::free(cols);
            return (max - r) * 100.0L / max;
        }
        return 0.0L;
    }

    std::size_t sstring::count(const char *what) const
    {
        if (what)
        {
            std::size_t cnt = 0, len = std::strlen(what);
            const char *sub = (const char *)this->src;
            while ((sub = std::strstr(sub, what)))
            {
                cnt++;
                sub += len;
            }
            return cnt;
        }
        return 0;
    }

    std::size_t sstring::count_char(const char what) const
    {
        if (what != '\0')
        {
            std::size_t cnt = 0;
            for (std::size_t i = 0; this->src[i] != '\0'; i++)
                if (this->src[i] == what)
                    cnt++;
            return cnt;
        }
        return 0;
    }

    sstring sstring::soundex() const
    {
        std::size_t s = 1, len = this->len;
        const char *map = "01230120022455012623010202"; // not stored in heap memory, do not free it
        char c;
        sstring res = sstring(nullptr, 5);
        res.src[0] = std::toupper(this->src[0]);
        for (std::size_t i = 1; i < len; ++i)
        {
            c = std::toupper(this->src[i]) - 65;
            if (c >= 0 && c <= 25) // from ASCII table
            {
                if (map[(std::size_t)c] != '\0')
                {
                    if (map[(std::size_t)c] != res[s - 1])
                    {
                        res.src[s] = map[(std::size_t)c];
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
                res.src[s] = '0';
                s++;
            }
        }
        res.len = std::strlen((const char *)res.src); // not big deal just 4 character (if nothing goes wrong)
        return res;
    }

    int strcmp_void(const void *a1, const void *a2)
    {
        return std::strcmp((const char *)a1, (const char *)a2);
    }

    sstring sstring::most_used(const char *dl) const
    {
        if (!dl || dl[0] == '\0')
            return sstring(nullptr);
        std::size_t len = this->len, cnt = 0, l = 0;
        cnt = this->count(dl);
        if (cnt == 0)
            return sstring(nullptr);
        char *temp = (char *)std::calloc((sizeof(char) * len) + 1, sizeof(char));
        std::strcpy(temp, this->src);
        char **buff = (char **)std::calloc((sizeof(char *) * cnt) + sizeof(char *), sizeof(char *)), *tok = strtok(temp, dl);
        while (tok != nullptr)
        {
            buff[l] = tok;
            tok = std::strtok(nullptr, dl);
            l++;
        }
        std::qsort(buff, l, sizeof(buff[0]), strcmp_void);
        char *res = nullptr;
        std::size_t m = 0, curr = 0;
        for (std::size_t i = 0; i < l; i++)
        {
            if (!std::strcmp(buff[i], buff[i - curr]))
                curr += 1;
            else
                curr = 1;
            if (curr > m)
            {
                res = buff[i];
                m = curr;
            }
        }
        sstring x = res;
        std::free(temp);
        std::free(buff);
        return x;
    }

    char sstring::most_used_char() const
    {
        std::size_t len = this->len;
        std::size_t cnt = 0, map_append = 0, o = 0;
        bool check = false;
        char *map_char = (char *)std::calloc((sizeof(char) * (len + 1)), sizeof(char));
        std::size_t *map_cnt = (std::size_t *)std::calloc((sizeof(std::size_t) * (len + 1)), sizeof(std::size_t));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; map_char[o] != '\0'; o++)
            {
                if (map_char[o] == this->src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                map_char[map_append] = this->src[cnt];
                map_cnt[map_append] = 1;
                map_append++;
            }
            else
                map_cnt[o] += 1;
        }
        std::size_t n = map_cnt[0], q = 0;
        for (std::size_t i = 1; map_char[i] != '\0'; i++)
        {
            if (n < map_cnt[i])
            {
                n = map_cnt[i];
                q = i;
            }
        }
        char c = map_char[q];
        std::free(map_char);
        std::free(map_cnt);
        return c;
    }

    split_t sstring::split(const char *str)
    {
        if (str && str[0] != '\0')
        {
            std::size_t len = this->len, cnt = 0;
            char *temp = (char *)std::calloc((sizeof(char) * len) + 1, sizeof(char)), *tok;
            std::strcpy(temp, this->src);
            tok = std::strtok(temp, str);
            while (tok)
            {
                cnt++;
                tok = std::strtok(nullptr, str);
                if (!tok)
                    break;
            }
            std::free(temp);
            if (cnt == 0)
                return split_t(0);
            temp = (char *)std::calloc((sizeof(char) * len) + 1, sizeof(char));
            std::strcpy(temp, this->src);
            tok = std::strtok(temp, str);
            split_t x(cnt + 1);
            while (tok)
            {
                x.add((const char *)tok);
                tok = std::strtok(nullptr, str);
                if (!tok)
                    break;
            }
            std::free(temp);
            return x;
        }
        return split_t(0);
    }

    int compare_chars(const void *c1, const void *c2)
    {
        return (*(char *)c1 - *(char *)c2);
    }

    void sstring::sort()
    {
        std::qsort(this->src, this->len, sizeof(char), compare_chars);
    }

    std::size_t sstring::open_binary(const char *location)
    {
        if (location)
        {
            std::FILE *f = std::fopen(location, "rb");
            if (f != nullptr)
            {
                std::fseek(f, 0, SEEK_END);
                std::size_t len = std::ftell(f);
                std::fseek(f, 0, SEEK_SET);
                unsigned char *_temp_ = (unsigned char *)std::calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
                std::free(this->src);
                this->src = (char *)std::calloc(len + 1, sizeof(char));
                std::fread(_temp_, len, sizeof(unsigned char), f);
                std::memcpy(this->src, (const void *)_temp_, len);
                std::fclose(f);
                std::free(_temp_);
                return len;
            }
        }
        return 0;
    }

    bool sstring::save_binary(const char *location, std::size_t len) const
    {
        if (location)
        {
            unsigned char *_temp_ = (unsigned char *)std::calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
            std::memcpy(_temp_, (const void *)this->src, len);
            std::FILE *f = std::fopen(location, "wb");
            if (f != nullptr)
            {
                std::fwrite((unsigned char *)_temp_, len, sizeof(unsigned char), f);
                std::fclose(f);
                std::free(_temp_);
                return true;
            }
            std::free(_temp_);
        }
        return false;
    }

    bool sstring::append_binary(const char *location, std::size_t len) const
    {
        if (location)
        {
            unsigned char *_temp_ = (unsigned char *)std::calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
            std::memcpy(_temp_, (const void *)this->src, len);
            std::FILE *f = std::fopen(location, "ab");
            if (f != nullptr)
            {
                std::fwrite((unsigned char *)_temp_, len, sizeof(unsigned char), f);
                std::fclose(f);
                std::free(_temp_);
                return true;
            }
            std::free(_temp_);
        }
        return false;
    }

    std::size_t sstring::add_binary(const char *data, std::size_t len)
    {
        if (data)
        {
            std::size_t size = len;
            this->src = (char *)std::realloc(this->src, (sizeof(char) * (len + std::strlen(data) + 1)));
            fast_strncat(this->src, data, size);
            return size - len; // total data written
        }
        return 0;
    }

    bool sstring::print_binary(std::size_t len) const
    {
        std::size_t x = 0;
        while (x != len)
            std::printf("%c", this->src[x++]);
        return true;
    }

    bool sstring::encrypt(const char *key)
    {
        if (key)
        {
            std::size_t len = this->len, val = std::hash<const char *>()(key) % 128;
            short add = true;
            char *buff = (char *)std::calloc(sizeof(char) * (len + 1), sizeof(char));
            for (std::size_t i = 0; this->src[i] != '\0'; i++)
            {
                if (add == true && this->src[i] + val > '\0')
                {
                    buff[i] = this->src[i] + val;
                    add = false;
                }
                else if (add == false && this->src[i] - val > '\0')
                {
                    buff[i] = this->src[i] - val;
                    add = true;
                }
                else
                {
                    std::free(buff);
                    return false;
                }
            }
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (len + 1), sizeof(char));
            len = 0;
            fast_strncat(this->src, (const char *)buff, len);
            this->len = len;
            std::free(buff);
            return true;
        }
        return false;
    }

    bool sstring::decrypt(const char *key)
    {
        if (key)
        {
            std::size_t len = this->len, val = std::hash<const char *>()(key) % 128;
            short add_invr = true;
            char *buff = (char *)std::calloc(sizeof(char) * (len + 1), sizeof(char));
            for (std::size_t i = 0; this->src[i] != '\0'; i++)
            {
                if (add_invr == true && this->src[i] + val > '\0')
                {
                    buff[i] = this->src[i] - val;
                    add_invr = false;
                }
                else if (add_invr == false && this->src[i] - val > '\0')
                {
                    buff[i] = this->src[i] + val;
                    add_invr = true;
                }
                else
                {
                    std::free(buff);
                    return false;
                }
            }
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (len + 1), sizeof(char));
            len = 0;
            fast_strncat(this->src, (const char *)buff, len);
            this->len = len;
            std::free(buff);
            return true;
        }
        return false;
    }

    std::size_t sstring::begin() const
    {
        return 0ULL;
    }

    std::size_t sstring::end() const
    {
        return this->len;
    }

    bool sstring::to_morse_code()
    {
        for (std::size_t i = 0; i < this->len; i++)
            if (!std::isdigit(this->src[i]) && !std::isalpha(this->src[i]) && this->src[i] != ' ')
                return false;
        char *buff = (char *)std::calloc((sizeof(char) * this->len * 8) + 1, sizeof(char));
        std::size_t track = 0;
        for (std::size_t i = 0; i < this->len; i++)
        {
            if (std::isdigit(this->src[i]))
                fast_strncat(buff, morse_code[(std::size_t)this->src[i] - 48].code, track);
            else if (this->src[i] == ' ')
                fast_strncat(buff, morse_code[(std::size_t)36].code, track);
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
        this->src = (char *)std::calloc(sizeof(char) * (track + 1), sizeof(char));
        track = 0;
        fast_strncat(this->src, (const char *)buff, track);
        std::free(buff);
        this->len = track;
        return true;
    }

    bool sstring::from_morse_code()
    {
        for (std::size_t i = 0; i < this->len; i++)
        {
            switch (this->src[i])
            {
            case '-':
            case '.':
            case ' ':
                break;
            default:
                return false;
            }
        }
        char *buff = (char *)std::calloc(sizeof(char) * (this->len + 1), sizeof(char)), *temp = (char *)std::calloc(sizeof(char) * 8, sizeof(char));
        std::size_t track = 0, x = 0;
        char arr[3] = "\0\0";
        for (std::size_t i = 0, k = 0; i < this->len; i++, k++)
        {
            if (i == this->len - 1)
            {
                x = 0;
                temp[k] = this->src[i];
                while ((std::strcmp(temp, morse_code[x].code)) != 0)
                    x++;
                arr[0] = morse_code[x].character;
                fast_strncat(buff, (const char *)arr, track);
            }
            if (this->src[i] == ' ')
            {
                i++, x = 0;
                while ((std::strcmp(temp, morse_code[x].code)) != 0)
                    x++;
                arr[0] = morse_code[x].character;
                fast_strncat(buff, (const char *)arr, track);
                memset(temp, 0, 8);
                k = 0;
            }
            temp[k] = this->src[i];
        }
        std::free(this->src);
        this->src = (char *)std::calloc(sizeof(char) * (track + 1), sizeof(char));
        track = 0;
        fast_strncat(this->src, (const char *)buff, track);
        std::free(buff);
        std::free(temp);
        this->len = track;
        return true;
    }

    bool sstring::is_digit() const
    {
        if (this->src[0] != '\0')
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (!std::isdigit(this->src[i]))
                    return false;
            return true;
        }
        return false;
    }

    bool sstring::is_decimal() const
    {
        if (this->src[0] != '\0')
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

    bool sstring::is_ascii() const
    {
        if (this->src[0] != '\0')
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
        if (this->src[0] != '\0')
        {
            for (std::size_t i = 0; i < this->len; i++)
                if (!std::isalpha(this->src[i]))
                    return false;
            return true;
        }
        return false;
    }

    void sstring::format_escape_sequence()
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
    }

    bool sstring::insert(const char *src, std::size_t index)
    {
        if (src && index <= this->len)
        {
            std::size_t len = std::strlen(src);
            this->src = (char *)std::realloc(this->src, sizeof(char) * (this->len + len + 1));
            for (std::size_t i = this->len; i >= index; i--)
            {
                this->src[i + len] = this->src[i];
                this->src[i] = '\0';
                if (i == 0)
                    break;
            }
            std::memcpy(this->src + index, src, len);
            this->len += len;
            return true;
        }
        return false;
    }

    bool sstring::starts_with(const char *src) const
    {
        if (src)
        {
            if (std::strlen(src) > this->len)
                return false;
            for (std::size_t i = 0; src[i] != '\0' && this->src[i] != '\0'; i++)
                if (this->src[i] != src[i])
                    return false;
            return true;
        }
        return false;
    }

    bool sstring::ends_with(const char *src) const
    {
        if (src)
        {
            std::size_t len = std::strlen(src);
            if (len > this->len)
                return false;
            for (std::size_t i = this->len - len, z = 0; src[z] != '\0' && this->src[i] != '\0'; i++, z++)
                if (this->src[i] != src[z])
                    return false;
            return true;
        }
        return false;
    }

    const char *char_to_esc_seq(char c)
    {
        if (c == '\\')
            return (const char *)"\\\\";
        else if (c == '\a')
            return (const char *)"\\a";
        else if (c == '\b')
            return (const char *)"\\b";
        else if (c == '\f')
            return (const char *)"\\f";
        else if (c == '\n')
            return (const char *)"\\n";
        else if (c == '\r')
            return (const char *)"\\r";
        else if (c == '\t')
            return (const char *)"\\t";
        else if (c == '\v')
            return (const char *)"\\v";
        else if (c == '\"')
            return (const char *)"\\\"";
        else if (c == '\'')
            return (const char *)"\\\'";
        else if (c == '\?')
            return (const char *)"\\\?";
        else if (c == '\0')
            return (const char *)"\\0";
        else
            return (const char *)"\0";
    }

    const char *esc_seq_to_char_ptr(const char *c)
    {
        if (std::strcmp(c, "\\\\") == 0)
            return (const char *)"\\";
        else if (std::strcmp(c, "\\a") == 0)
            return (const char *)"\a";
        else if (std::strcmp(c, "\\b") == 0)
            return (const char *)"\b";
        else if (std::strcmp(c, "\\f") == 0)
            return (const char *)"\f";
        else if (std::strcmp(c, "\\n") == 0)
            return (const char *)"\n";
        else if (std::strcmp(c, "\\r") == 0)
            return (const char *)"\r";
        else if (std::strcmp(c, "\\t") == 0)
            return (const char *)"\t";
        else if (std::strcmp(c, "\\v") == 0)
            return (const char *)"\v";
        else if (std::strcmp(c, "\\\"") == 0)
            return (const char *)"\"";
        else if (std::strcmp(c, "\\\'") == 0)
            return (const char *)"\'";
        else if (std::strcmp(c, "\\\?") == 0)
            return (const char *)"\?";
        else if (std::strcmp(c, "\\0") == 0)
            return (const char *)"\0";
        else
            return c;
    }

    parse_t sstring::parse()
    {
        std::size_t len = 0;
        for (std::size_t i = 0; i < this->len;)
        {
            if ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
            {
                while ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
                    i++;
                len++;
            }
            else if (this->src[i] == 32)
                i++, len++;
            else if (std::isdigit(this->src[i]))
            {
                while (std::isdigit(this->src[i]))
                    i++;
                len++;
            }
            else if (this->src[i] == '\\' || this->src[i] == '\a' || this->src[i] == '\b' || this->src[i] == '\f' || this->src[i] == '\n' || this->src[i] == '\r' || this->src[i] == '\t' || this->src[i] == '\v' || this->src[i] == '\"' || this->src[i] == '\'' || this->src[i] == '\?')
            {
                while (this->src[i] == '\\' || this->src[i] == '\a' || this->src[i] == '\b' || this->src[i] == '\f' || this->src[i] == '\n' || this->src[i] == '\r' || this->src[i] == '\t' || this->src[i] == '\v' || this->src[i] == '\"' || this->src[i] == '\'' || this->src[i] == '\?')
                    i++, len++;
            }
            else if ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
            {
                while ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
                    i++, len++;
            }
            else
                return parse_t(0);
        }
        len++;
        parse_t pt(len);
        sstring toks(nullptr);
        for (std::size_t i = 0; i < this->len;)
        {
            if ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
            {
                toks.clear();
                while ((this->src[i] >= 97 && this->src[i] <= 122) || (this->src[i] >= 65 && this->src[i] <= 90))
                    toks.append_char(this->src[i++]);
                pt.add(toks.c_str(), WORD);
            }
            else if (this->src[i] == 32)
            {
                toks.clear();
                toks.append_char(this->src[i++]);
                pt.add(toks.c_str(), WHITESPACE);
            }
            else if (std::isdigit(this->src[i]))
            {
                toks.clear();
                while (std::isdigit(this->src[i]))
                    toks.append_char(this->src[i++]);
                pt.add(toks.c_str(), INTEGER);
            }
            else if (this->src[i] == '\\' || this->src[i] == '\a' || this->src[i] == '\b' || this->src[i] == '\f' || this->src[i] == '\n' || this->src[i] == '\r' || this->src[i] == '\t' || this->src[i] == '\v' || this->src[i] == '\"' || this->src[i] == '\'' || this->src[i] == '\?')
            {
                toks.clear();
                while (this->src[i] == '\\' || this->src[i] == '\a' || this->src[i] == '\b' || this->src[i] == '\f' || this->src[i] == '\n' || this->src[i] == '\r' || this->src[i] == '\t' || this->src[i] == '\v' || this->src[i] == '\"' || this->src[i] == '\'' || this->src[i] == '\?')
                {
                    toks.clear();
                    toks.set(char_to_esc_seq(this->src[i++]));
                    pt.add(toks.c_str(), ESC_SEQ);
                }
            }
            else if ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
            {
                toks.clear();
                while ((this->src[i] == 33) || (this->src[i] >= 35 && this->src[i] <= 38) || (this->src[i] >= 40 && this->src[i] <= 47) || (this->src[i] >= 58 && this->src[i] <= 62) || (this->src[i] == 64) || (this->src[i] == 91) || (this->src[i] >= 93 && this->src[i] <= 96) || (this->src[i] >= 123 && this->src[i] <= 126))
                {
                    toks.clear();
                    toks.set_char(this->src[i++]);
                    pt.add(toks.c_str(), SPECIAL_CHAR);
                }
            }
            else
                return parse_t(0);
        }
        pt.add(char_to_esc_seq('\0'), NULL_END);
        return pt;
    }

    bool sstring::from_parse_t(parse_t toks)
    {
        if (toks.length() != 0)
        {
            std::size_t len = 0;
            for (std::size_t i = 0; i < toks.length(); i++)
                len += std::strlen(toks[i].c_str());
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (len + 1), sizeof(char));
            len = 0;
            for (std::size_t i = 0; i < toks.length(); i++)
                fast_strncat(this->src, esc_seq_to_char_ptr(toks[i].c_str()), len);
            this->len = len;
            return true;
        }
        return false;
    }

    bool sstring::set_formatted(std::size_t buffer_length, const char *__format__, ...)
    {
        if (__format__ == nullptr)
            return false;
        std::size_t buff_l = std::strlen(__format__);
        if (buffer_length >= buff_l)
        {
            char *buff = (char *)std::calloc(sizeof(char) * (buffer_length + 1), sizeof(char));
            std::va_list ar;
            va_start(ar, __format__);
            std::vsnprintf(buff, buffer_length, __format__, ar);
            va_end(ar);
            std::free(this->src);
            this->src = (char *)std::calloc(sizeof(char) * (std::strlen((const char *)buff) + 1), sizeof(char));
            std::size_t len = 0;
            fast_strncat(this->src, (const char *)buff, len);
            this->len = len;
            std::free(buff);
            return true;
        }
        return false;
    }

    bool sstring::append_formatted(std::size_t buffer_length, const char *__format__, ...)
    {
        if (__format__ == nullptr)
            return false;
        std::size_t buff_l = strlen(__format__);
        if (buffer_length >= buff_l)
        {
            char *buff = (char *)std::calloc(sizeof(char) * (buffer_length + 1), sizeof(char));
            std::va_list ar;
            va_start(ar, __format__);
            std::vsnprintf(buff, buffer_length, __format__, ar);
            va_end(ar);
            this->src = (char *)std::realloc(this->src, sizeof(char) * (std::strlen((const char *)buff) + this->len + 1));
            std::size_t len = this->len;
            fast_strncat(this->src, (const char *)buff, len);
            this->len = len;
            std::free(buff);
            return true;
        }
        return false;
    }

    bool sstring::resize(std::size_t new_len)
    {
        if (new_len > 0)
        {
            this->src = (char *)realloc(this->src, new_len);
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
        if (this->len >= n)
            return this->src[n];
        return (char)'\0';
    }

    sstring sstring::operator+(const sstring &str)
    {
        sstring x = sstring(this->src);
        x.append(str.c_str());
        return x;
    }

    sstring sstring::operator+(const char str)
    {
        sstring x = sstring(this->src);
        x.append_char(str);
        return x;
    }

    sstring sstring::operator+(const char *str)
    {
        sstring x = sstring(this->src);
        x.append(str);
        return x;
    }

    void sstring::operator+=(const sstring &str)
    {
        this->append(str.c_str());
    }

    void sstring::operator+=(const char str)
    {
        this->append_char(str);
    }

    void sstring::operator+=(const char *str)
    {
        this->append(str);
    }

    void sstring::operator+=(std::initializer_list<char> list)
    {
        for (auto &i : list)
            this->append_char(i);
    }

    void sstring::operator+=(std::initializer_list<sstring> list)
    {
        for (auto &i : list)
            this->append(i.c_str());
    }

    void sstring::operator=(const sstring &str)
    {
        this->set(str.c_str());
    }

    void sstring::operator=(const char *str)
    {
        this->set(str);
    }

    void sstring::operator=(const char c)
    {
        this->set_char(c);
    }

    bool sstring::operator==(const sstring &str) const
    {
        return this->compare(str.c_str());
    }

    bool sstring::operator==(const char *str) const
    {
        return this->compare(str);
    }

    bool sstring::operator!=(const sstring &str) const
    {
        return !(this->compare(str.c_str()));
    }

    bool sstring::operator!=(const char *str) const
    {
        return !(this->compare(str));
    }

    sstring &sstring::operator=(const sstring &&__s) noexcept
    {
        if (this != &__s)
        {
            free(this->src);
            this->len = __s.len;
            this->src = (char *)std::calloc(sizeof(char *) * this->len, sizeof(char *));
            std::size_t pos = 0;
            fast_strncat(this->src, __s.src, pos);
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const sstring &obj)
    {
        out << obj.src;
        return out;
    }

    sstring::~sstring()
    {
        free(this->src);
        this->len = 0;
    }

    sstring to_sstring(char str)
    {
        sstring x(nullptr);
        x.set_char(str);
        return x;
    }

    sstring to_sstring(const char *str)
    {
        return sstring(str);
    }

    sstring to_sstring(void *ptr)
    {
        char s[64];
        std::snprintf(s, 64, "%p", ptr);
        return sstring((const char *)s);
    }

    sstring to_sstring(signed short int x)
    {
        char s[64];
        std::snprintf(s, 64, "%hi", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(unsigned short int x)
    {
        char s[64];
        std::snprintf(s, 64, "%hu", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(signed int x)
    {
        char s[64];
        std::snprintf(s, 64, "%d", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(unsigned int x)
    {
        char s[64];
        std::snprintf(s, 64, "%i", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(signed long int x)
    {
        char s[64];
        std::snprintf(s, 64, "%ld", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(unsigned long int x)
    {
        char s[64];
        std::snprintf(s, 64, "%lu", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(signed long long int x)
    {
        char s[64];
        std::snprintf(s, 64, "%lld", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(unsigned long long int x)
    {
        char s[64];
        std::snprintf(s, 64, "%llu", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(float x)
    {
        char s[64];
        std::snprintf(s, 64, "%f", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(double x)
    {
        char s[512];
        std::snprintf(s, 512, "%lf", x);
        return sstring((const char *)s);
    }

    sstring to_sstring(long double x)
    {
        char s[5120];
        std::snprintf(s, 5120, "%Lf", x);
        return sstring((const char *)s);
    }

    sstring get_random(std::size_t len)
    {
        sstring x;
        x.set_random(len);
        return x;
    }

    sstring open_file(const sstring &location)
    {
        sstring x;
        x.open(location.c_str());
        return x;
    }

    sstring end_line()
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

    parse_t::parse_t(std::size_t len)
    {
        this->src = (char **)std::calloc(sizeof(char *) * len, sizeof(char *));
        this->type = (enum parse_token *)std::calloc(sizeof(enum parse_token) * len, sizeof(enum parse_token));
        this->len = 0;
        this->cap = len;
    }

    bool parse_t::add(const char *src, enum parse_token type)
    {
        if (src)
        {
            if (this->len > this->cap)
                return false;
            this->src[this->len] = (char *)std::calloc(sizeof(char) * (std::strlen(src) + 1), sizeof(char));
            std::size_t l = 0;
            fast_strncat(this->src[this->len], src, l);
            this->type[this->len++] = type;
            return true;
        }
        return false;
    }

    sstring parse_t::get(std::size_t n) const
    {
        if (n < this->len)
            return sstring(this->src[n]);
        return sstring(nullptr);
    }

    enum parse_token parse_t::get_type(std::size_t n) const
    {
        if (n < this->len)
            return this->type[n];
        return NULL_END;
    }

    sstring parse_t::operator[](std::size_t n) const
    {
        if (n < this->len)
            return sstring(this->src[n]);
        return sstring(nullptr);
    }

    std::size_t parse_t::length() const
    {
        return this->len;
    }

    parse_t::parse_t(parse_t &&other) noexcept : src(nullptr), type(nullptr), len(0), cap(10)
    {
        src = other.src;
        type = other.type;
        len = other.len;

        other.src = nullptr;
        other.type = nullptr;
        other.len = 0;
    }

    parse_t &parse_t::operator=(const parse_t &&__pt) noexcept
    {
        if (this != &__pt)
        {
            for (std::size_t i = 0; i < this->len; i++)
                free(this->src[i]);
            free(this->src);
            free(this->type);
            this->len = __pt.len;
            this->cap = __pt.cap;

            this->src = (char **)std::calloc(sizeof(char *) * this->cap, sizeof(char *));
            this->type = (enum parse_token *)std::calloc(sizeof(enum parse_token) * len, sizeof(enum parse_token));
            for (std::size_t i = 0; i < this->len; i++)
            {
                this->src[i] = (char *)std::calloc(sizeof(char) * (std::strlen(__pt.src[i]) + 1), sizeof(char));
                std::size_t pos = 0; // temp variable note string length of `__st.src[i]` is only counted once because if we use `std::strcpy` it will also transverse through the string
                fast_strncat(this->src[i], __pt.src[i], pos);
                this->type[i] = __pt.type[i];
            }
        }
        return *this;
    }

    parse_t::~parse_t()
    {
        for (std::size_t i = 0; i < this->len; i++)
            free(this->src[i]);
        free(this->src);
        free(this->type);
        this->len = 0;
        this->cap = 0;
    }

    split_t::split_t(std::size_t len)
    {
        this->src = (char **)std::calloc(sizeof(char *) * len, sizeof(char *));
        this->len = 0;
        this->cap = len;
    }

    bool split_t::add(const char *src)
    {
        if (src)
        {
            if (this->len > this->cap)
                return false;
            this->src[this->len] = (char *)std::calloc(sizeof(char) * (std::strlen(src) + 1), sizeof(char));
            std::size_t l = 0;
            fast_strncat(this->src[this->len++], src, l);
            return true;
        }
        return false;
    }

    sstring split_t::get(std::size_t n) const
    {
        if (n < this->len)
            return sstring(this->src[n]);
        return sstring(nullptr);
    }

    sstring split_t::operator[](std::size_t n) const
    {
        if (n < this->len)
            return sstring(this->src[n]);
        return sstring(nullptr);
    }

    std::size_t split_t::length() const
    {
        return this->len;
    }

    split_t::split_t(split_t &&other) noexcept : src(nullptr), len(0), cap(10)
    {
        src = other.src;
        len = other.len;
        other.src = nullptr;
        other.len = 0;
    }

    split_t &split_t::operator=(const split_t &&__st) noexcept
    {
        if (this != &__st)
        {
            for (std::size_t i = 0; i < this->len; i++)
                free(this->src[i]);
            free(this->src);
            this->len = __st.len;
            this->cap = __st.cap;

            this->src = (char **)std::calloc(sizeof(char *) * this->cap, sizeof(char *));
            for (std::size_t i = 0; i < this->len; i++)
            {
                this->src[i] = (char *)std::calloc(sizeof(char) * (std::strlen(__st.src[i]) + 1), sizeof(char));
                std::size_t pos = 0; // temp variable note string length of `__st.src[i]` is only counted once because if we use `std::strcpy` it will also transverse through the string
                fast_strncat(this->src[i], __st.src[i], pos);
            }
        }
        return *this;
    }

    split_t::~split_t()
    {
        for (std::size_t i = 0; i < this->len; i++)
            free(this->src[i]);
        free(this->src);
        this->len = 0;
        this->cap = 0;
    }
};

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
