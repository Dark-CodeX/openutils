#ifndef __cplusplus

#pragma once

/**
 * This header file is written to manage string data safely under C programming language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "sstring.h" under "sstring" directory
 * sstring: version 1.5.6
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
typedef struct __string__ sstring;

#define sstring_version "1.5.6"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * This struct is made to store single-pointer char and its initialized value.
 * Do not use this directly, instead use `sstring` struct.
 */
typedef struct __str__
{
    /* Do not modify it directly (segfault), most probably and use 'str.destructor(&str);' at the end */
    char *src;
    /* Do not change this value. */
    int init;
    /** Stores the length of sstring without using `strlen` function. NOTE: Do not change this value.*/
    size_t len;
} __str__;

/**
 * This struct is made to store double-pointer char and its length.
 * NOTE: Use `free_split` function to free this struct.
 */
typedef struct split_t
{
    /* contains the splitted strings */
    char **data;
    /* length of double-pointer `data` */
    size_t len;
} split_t;

/**
 * This struct is made to store current position and character in a `sstring`.
 */
typedef struct __iterator__ iter_sstring;
struct __iterator__
{
    /** Initial or current position. */
    signed long long int cur;
    /** Final position. */
    signed long long int max;
    /** For BOTTOM_TO_TOP. */
    short is_max_smaller;
    /**
     * Increases or decreases `iter_sstring` by `move_by`.
     * @param is pointer to struct iter_sstring
     * @param move_by factor to move `is->cur`
     */
    void (*advance)(iter_sstring *is, signed long long int move_by);

    /**
     * Tells whether to continue the loop or not.
     * @param is pointer to struct iter_sstring
     * @returns true if loop can be continued, otherwise false
     */
    int (*c_loop)(iter_sstring *is);
};

/**
 * This enum is used to store the type of token.
 */
enum parse_token
{
    WORD,
    INTEGER,
    ESC_SEQ,
    SPECIAL_CHAR,
    WHITESPACE,
    NULL_END
} parse_token;

/**
 * This struct stores double-pointer char, its length and type of token.
 * NOTE: Use `free_parse` function to avoid memory leaks.
 */
typedef struct __parse__ parse_t;
struct __parse__
{
    /* contains the parsed strings */
    char **src;
    /* length of double-pointer `src` */
    size_t length;
    /** contains the type of token */
    enum parse_token *type;
} __parse__;

struct __string__
{
    /* Do not use this. */
    void *str;

    /** Sets `src` to `a`.
     * @param a pointer to struct sstring
     * @param src string to assign
     */
    void (*set)(sstring *a, const char *src);

    /** Sets `c` to `a`.
     * @param a pointer to struct sstring
     * @param c character to assign
     */
    void (*set_char)(sstring *a, const char c);

    /** Sets `src` to `a` upto `N`.
     * @param a pointer to struct sstring
     * @param src string to assign
     * @param N sets upto a number
     */
    void (*set_upto)(sstring *a, const char *src, size_t N);

    /** Sets random data to `a`. NOTE: length should be greater than 0, (not equal to 0). Well, no error and result if assigned 0.
     * NOTE: use srand function before calling this function.
     * @code {.c}
     * srand((unsigned int)(time(NULL) * getpid() * getpid() + getpid()));
     * @endcode
     * OR you can use `srand` function with the memory reference of any pointer.
     * @param a pointer to struct sstring
     * @param len size of random string
     */
    void (*set_random)(sstring *a, const size_t len);

    /** @brief Sets `src` array to `a`. NOTE: `from`, `till` belongs to [0, sizeof(`src`)].
     * Set `char_between` to 0 if you want nothing to append in-between.
     * NOTE: `src[till]` is not included in resultant string.
     * @param a pointer to struct sstring
     * @param src string array to assign
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start assigning `src[from]`
     * @param till assign till `src[till]`
     * @param len length of `src` array
     */
    void (*set_array)(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);

    /** Returns `a` as `char *`.
     * @param a pointer to struct sstring
     * @returns return `a` as `char *`
     */
    char *(*get)(sstring *a);

    /** Appends `src` to `a` at the end.
     * @param a pointer to struct sstring
     * @param src string to append
     */
    void (*append)(sstring *a, const char *src);

    /** Appends `c` to `a` at the end.
     * @param a pointer to struct sstring
     * @param c character to append
     */
    void (*append_char)(sstring *a, const char c);

    /** Appends `src` to `a` at the end upto `N`.
     * @param a pointer to struct sstring
     * @param src string to append
     * @param N append upto a number
     */
    void (*append_upto)(sstring *a, const char *src, size_t N);

    /** Appends `src` to `a` at the starting.
     * @param a pointer to struct sstring
     * @param src string to append
     */
    void (*append_start)(sstring *a, const char *src);

    /** Appends `c` to `a` at the starting.
     * @param a pointer to struct sstring
     * @param c character to append
     */
    void (*append_start_char)(sstring *a, const char c);

    /** Appends `src` to `a` at the starting upto `N`.
     * @param a pointer to struct sstring
     * @param src string to append
     * @param N append upto a number
     */
    void (*append_start_upto)(sstring *a, const char *src, size_t N);

    /** @brief Appends `src` array to `a` at the end. NOTE: `from`, `till` belongs to [0, sizeof(`src`)].
     * Set `char_between` to 0 if you want nothing to append in-between.
     * NOTE: `src[till]` is not included in resultant string.
     * @param a pointer to struct sstring
     * @param src string array to append
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start appending `src[from]`
     * @param till append till `src[till]`
     * @param len length of `src` array
     */
    void (*append_array)(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);

    /** @brief Appends `src` array to `a` at the starting. NOTE: `from`, `till` belongs to [0, sizeof(`src`)].
     * Set `char_between` to 0 if you want nothing to append in-between.
     * NOTE: `src[till]` is not included in resultant string.
     * @param a pointer to struct sstring
     * @param src string array to append
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start appending `src[from]`
     * @param till append till `src[till]`
     * @param len length of `src` array
     */
    void (*append_start_array)(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);

    /** Checks whether `a` is empty or not.
     * @param a pointer to struct sstring
     * @returns return true if empty, otherwise return false
     */
    int (*empty)(sstring *a);

    /** Linear time complexity, O(n), where n is the length of the char array.
     * Replaces `old` to `new`.
     * @param a pointer to struct sstring
     * @param old old character (character to be replaced)
     * @param new_ new character (character to be replaced with)
     */
    void (*replace_char)(sstring *a, const char old, const char new_);

    /**
     * Sets `what` at `where` in `a`.
     * Only sets if `where` is less than size of `a`.
     * @param a pointer to struct sstring
     * @param what character to set
     * @param where sets `what` at a fixed position
     */
    void (*char_set)(sstring *a, const char what, size_t where);

    /**
     * Returns character from `a` at `where`.
     * Only returns if `where` is less than size of `a`.
     * @param a pointer to struct sstring
     * @param where get an element from where in `a`
     * @returns character from `a` at `where`.
     */
    char (*char_get)(sstring *a, size_t where);

    /**
     * Returns length of `a` using `strlen` function, does not include the count of NUL(0).
     * @param a pointer to struct sstring
     * @returns length of `a`
     */
    size_t (*length)(sstring *a);

    /**
     * Compares `a` against `T1`.
     * @param a pointer to struct sstring
     * @param T1 string to compare with
     * @returns return true if true, otherwise return false
     */
    int (*compare)(sstring *a, const char *T1);

    /**
     * Compares `a` against `T1` upto `N`.
     * @param a pointer to struct sstring
     * @param T1 string to compare with
     * @param N compare upto a number
     * @returns return true if true, otherwise return false
     */
    int (*compare_upto)(sstring *a, const char *T1, size_t N);

    /**
     * Prints `a`.
     * @param a pointer to struct sstring
     * @param add_next_line set 0 if append next line, otherwise set 1
     * @param __format__ arguments for ...
     */
    void (*print)(sstring *a, int add_next_line, const char *__format__, ...);

    /**
     * Replaces `old` in `a` with `new_`.
     * @param a pointer to struct sstring
     * @param old what to replace
     * @param new_ replace with
     */
    void (*replace)(sstring *a, const char *old, const char *new_);

    /**
     * Frees `a`'s content.
     * Do not forget to use this function at the end.
     * @param a pointer to struct sstring
     * @returns true if freed successfully, otherwise return false
     */
    int (*destructor)(sstring *a);

    /**
     * Returns `a` as `const char *`.
     * @param a pointer to struct sstring
     * @returns return `a` as `const char *`
     */
    const char *(*c_str)(sstring *a);

    /**
     * Saves `a` at `location`.
     * @param a pointer to struct sstring
     * @param location where to save
     * @returns true if saved successfully, otherwise return false
     */
    int (*save)(sstring *a, const char *location);

    /**
     * Appends `a` at `location`.
     * @param a pointer to struct sstring
     * @param location where to append
     * @returns true if appended successfully, otherwise return false
     */
    int (*append_file)(sstring *a, const char *location);

    /**
     * Opens file at `location` and then sets `a` the contents of the file.
     * @param a pointer to struct sstring
     * @param location file to open
     * @returns true if opened successfully, otherwise return false
     */
    int (*open)(sstring *a, const char *location);

    /**
     * Clears `a` using `calloc` function defined in <stdlib.h> header.
     * @param a pointer to struct sstring
     * @returns true if cleared successfully, otherwise return false
     */
    int (*clear)(sstring *a);

    /**
     * Converts `a` to upper case.
     * @param a pointer to struct sstring
     */
    void (*to_upper)(sstring *a);

    /**
     * Converts `a` to lower case.
     * @param a pointer to struct sstring
     */
    void (*to_lower)(sstring *a);

    /**
     * Converts upper case letters to lower case and vice-versa of `a`.
     * @param a pointer to struct sstring
     */
    void (*swap_case)(sstring *a);

    /**
     * Returns whether `a` is initialized or not using `init_sstr` function.
     * @param a pointer to struct sstring
     * @returns true if initialized, otherwise return nothing because this method have to be initialized using `init_sstr` function. Use `_is_initialized` function to get a result i.e, true or false.
     */
    int (*is_initialized)(sstring *a);

    /**
     * Converts `a` (as string) to base 2 (as binary).
     * @param a pointer to struct sstring
     */
    void (*to_binary)(sstring *a);

    /**
     * Converts `a` from base 2 (as binary) to string. Not executed if `a` is not in binary form i.e, [1, 0].
     * @param a pointer to struct sstring
     * @returns true if converted successfully, otherwise returns false.
     */
    int (*from_binary)(sstring *a);

    /**
     * Calculates the entropy using `Shannon's entropy` formula, which was introduced in his 1948 paper "A Mathematical Theory of Communication". For more information https://en.wikipedia.org/wiki/Entropy_(information_theory)
     * @param a pointer to struct sstring
     * @returns entropy of `a`.
     */
    long double (*entropy)(sstring *a);

    /**
     * Returns true if contains `str`, otherwise returns false.
     * @param a pointer to struct sstring
     * @param str string to be tested
     * @returns true if contains, otherwise return false
     */
    int (*contains)(sstring *a, const char *str);

    /**
     * If character was found returns its index (first occurrence only) in `a`, otherwise returns `nerr`.
     * @param a pointer to struct sstring
     * @param c character to be tested
     * @returns If character was found returns its index (first occurrence only) in `a`, otherwise returns `nerr`.
     */
    size_t (*contains_char)(sstring *a, const char c);

    /**
     * Assigns `a` as a set. (From Set Theory)
     * @param a pointer to struct sstring
     */
    void (*to_set)(sstring *a);

    /**
     * Copies `a` to `dest`. If copied successfully then, returns true otherwise false.
     * @param a pointer to struct sstring
     * @param dest pointer to struct sstring
     * @returns If copied successfully then, returns true otherwise false.
     */
    int (*copy)(sstring *a, sstring *dest);

    /**
     * Converts `a` (as string) to base 16 (as hexadecimal).
     * @param a pointer to struct sstring
     */
    void (*to_hexadecimal)(sstring *a);

    /**
     * Converts `a` from base 16 (as hexadecimal) to string. Not executed if `a` is not in hexadecimal form.
     * @param a pointer to struct sstring
     * @returns true if converted successfully, otherwise returns false.
     */
    int (*from_hexadecimal)(sstring *a);

    /**
     * Returns index of first occurrence of sub-string `sub` in `a`. Returns `nerr` if `sub` was not found in `a`.
     * @param a pointer to struct sstring
     * @param sub sub-string to find in `a`
     * @returns index of first occurrence of sub-string `sub` in `a`
     */
    size_t (*find)(sstring *a, const char *sub);

    /**
     * Get input from user and then sets that input to `a`.
     * @param a pointer to struct sstring
     * @param get_line set false to break input after SPACE, otherwise set true to break after EOL
     * @param buff_size memory to allocate for buffer size, data may not be written after `buff_size`, be careful while assigning this value.
     * @returns true if got input and assigned that to `a`, otherwise returns false
     */
    int (*in)(sstring *a, int get_line, size_t buff_size);

    /**
     * Returns content of `line` from `a`. If `line` does not exists it returns NULL.
     * NOTE: free the returned value when not in use, or before exiting the program.
     * @code {.c}
     * char *line = a.getline(&a, 7);
     * free(line);
     * @endcode
     * @param a pointer to struct sstring
     * @param line line number to be returned
     * @returns content of `line` from `a`. If `line`does not exists it returns NULL
     */
    char *(*getline)(sstring *a, size_t line);

    /**
     * Reverse a string means "ABCD" -> "DCBA".
     * Time complexity: O(N / 2), where N is the length of the `a`.
     * @param a pointer to struct sstring
     */
    void (*reverse)(sstring *a);

    /**
     * Removes all occurrence of sub-string `sub` from `a`.
     * @param a pointer to struct sstring
     * @param sub sub-string to remove
     * @returns total number of characters removed
     */
    size_t (*remove)(sstring *a, const char *sub);

    /**
     * Removes all occurrence of character `c` from `a`.
     * @param a pointer to struct sstring
     * @param c character to remove
     * @returns total number of characters removed
     */
    size_t (*remove_char)(sstring *a, char c);

    /**
     * Removes all extra occurrence of character `c` from `a`. Eg.: "Hello__1" -> "Hello_1", here `c` was underscore('_').
     * Mainly used to remove extra whitespaces from a string.
     * @param a pointer to struct sstring
     * @param c character to remove
     * @returns total number of characters removed
     */
    size_t (*remove_extra_char)(sstring *a, char c);

    /**
     * Removes characters between `from` and `till`.
     * @param a pointer to struct sstring
     * @param from where to start removing characters
     * @param till when to stop removing characters
     * @returns total number of characters removed
     */
    size_t (*remove_range)(sstring *a, size_t from, size_t till);

    /**
     * Assings characters to `a` between `from` and `till`.
     * @param a pointer to struct sstring
     * @param from where to start assigning characters
     * @param till when to stop assigning characters
     * @returns true if assigned, otherwise false
     */
    int (*intersect)(sstring *a, size_t from, size_t till);

    /**
     * Calculates hamming distance (From Information Theory) between two strings. NOTE: string's length should be same.
     * @param a pointer to struct sstring
     * @param src second string to compare with
     * @returns returns `nerr` if length does not match, otherwise number of characters didn't matched.
     */
    size_t (*distance)(sstring *a, const char *src);

    /**
     * Returns `Levenshtein Distance` (From Information Theory) against `src`.
     * @param a pointer to struct sstring
     * @param src string to be matched
     * @returns edit distance
     */
    size_t (*edit_distance)(sstring *a, const char *src);

    /**
     * Returns percentage matched against `src` using `Levenshtein Distance` algorithm (From Information Theory).
     * @param a pointer to struct sstring
     * @param src string to be matched
     * @returns percentage matched, NOTE: returned value belongs to [0, 100]
     */
    long double (*percentage_matched)(sstring *a, const char *src);

    /**
     * Counts the number of occurrence of `what` in `a`.
     * @param a pointer to struct sstring
     * @param what string to find in `a`
     * @returns number of occurrence of `what`
     */
    size_t (*count)(sstring *a, const char *what);

    /**
     * Counts the number of occurrence of `what` in `a`.
     * @param a pointer to struct sstring
     * @param what character to find in `a`
     * @returns number of occurrence of `what`
     */
    size_t (*count_char)(sstring *a, const char what);

    /**
     * Encodes `a` to 4 characters long string which can be compared to other `soundex` returned value.
     * This function is used to compare two names by their pronunciation.
     * NOTE: free the returned value when not in use, or before exiting the program.
     * @code {.c}
     * char *sdx = a.soundex(&a);
     * free(sdx);
     * @endcode
     * @param a pointer to struct sstring
     * @returns string generated by this function
     */
    char *(*soundex)(sstring *a);

    /**
     * Returns the word which was most occurred in `a`. NOTE: By `word`, I mean text separated by whitespace.
     * @code {.c}
     * char *most = a.most_used(&a);
     * free(most);
     * @endcode
     * @param a pointer to struct sstring
     * @param dl string to separate
     * @returns most used / occurred word in `a`
     */
    char *(*most_used)(sstring *a, const char *dl);

    /**
     * Returns the character which was most occurred in `a`.
     * @param a pointer to struct sstring
     * @returns most used / occurred character in `a`
     */
    char (*most_used_char)(sstring *a);

    /**
     * Splits `a` when `dl` is found. NOTE: `dl` is not included in the splitted string.
     * NOTE: use `free_split` to avoid memory leak.
     * @code {.c}
     * split sp = a.split(&a, "-");
     * free_split(&sp);
     * @endcode
     * @param a pointer to struct sstring
     * @param dl delimiter string
     * @returns splitted string as `split` struct with its length.
     */
    split_t (*split)(sstring *a, const char *dl);

    /**
     * Sort each character using merge sort algorithm. NOTE: character are sorted in ascending order using ASCII comparison.
     * @param a pointer to struct sstring
     */
    void (*sort)(sstring *a);

    /**
     * Opens file at `location` for binary I/O.
     * @param a pointer to struct sstring
     * @param location file to be opened
     * @returns size of the file in bytes
     */
    size_t (*open_binary)(sstring *a, const char *location);

    /**
     * Saves the content of `a` to the file at `location`.
     * @param a pointer to struct sstring
     * @param location file to be saved
     * @param len length of the data (returned value of `open_binary` function)
     * @returns true if saved, otherwise false
     */
    int (*save_binary)(sstring *a, const char *location, size_t len);

    /**
     * Appends the content of `a` to the file at `location`.
     * @param a pointer to struct sstring
     * @param location file to be appended
     * @param len length of the data (returned value of `open_binary` function)
     * @returns true if appended, otherwise false
     */
    int (*append_binary)(sstring *a, const char *location, size_t len);

    /**
     * Appends the content of `data` to `a`.
     * @param a pointer to struct sstring
     * @param data data to add to `a`
     * @param len length of the `a` (returned value of `open_binary` function)
     * @returns size of data written in bytes, if returned value is 0 then no data is written
     */
    size_t (*add_binary)(sstring *a, const char *data, size_t len);

    /**
     * Prints `a` till `len`.
     * @param a pointer to struct sstring
     * @param len length of the data (returned value of `open_binary` function)
     * @returns true if appended, otherwise false
     */
    int (*print_binary)(sstring *a, size_t len);

    /**
     * Encrypts `a` using positional modulus for `key`.
     * @param a pointer to struct sstring
     * @returns true if encrypted, otherwise false
     */
    int (*encrypt)(sstring *a, const char *key);

    /**
     * Decrypts `a` using positional modulus for `key`.
     * @param a pointer to struct sstring
     * @returns true if decrypted, otherwise false
     */
    int (*decrypt)(sstring *a, const char *key);

    /**
     * Returns first index of `sstring`, i.e, 0.
     * @returns 0
     */
    size_t (*begin)(void);

    /**
     * Returns an iterator which traverse through `a`.
     * @param a pointer to struct sstring
     * @returns an initialized `iter_sstring`
     */
    iter_sstring (*iterator)(sstring *a);

    /**
     * Returns an iterator which traverse through `a` in reverse order.
     * @param a pointer to struct sstring
     * @returns an initialized `iter_sstring`
     */
    iter_sstring (*reverse_iterator)(sstring *a);

    /**
     * Returns last index of `a`, without using `strlen` function. Should be used in any loop.
     * @param a pointer to struct sstring
     * @returns last index of `a`, without using `strlen` function
     */
    size_t (*end)(sstring *a);

    /**
     * Converts `a` to morse code. NOTE: `a` should only contain (A-Z), (a-z), (0-9) and WHITESPACE.
     * @param a pointer to struct sstring
     * @returns true if converted, otherwise false
     */
    int (*to_morse_code)(sstring *a);

    /**
     * Converts morse code to simple readable `sstring`.
     * @param a pointer to struct sstring
     * @returns true if converted, otherwise false
     */
    int (*from_morse_code)(sstring *a);

    /**
     * Checks whether all characters of `a` is digit or not.
     * @param a pointer to struct sstring
     * @returns true if all character were digit, otherwise false
     */
    int (*is_digit)(sstring *a);

    /**
     * Checks whether `a` is decimal or not.
     * @param a pointer to struct sstring
     * @returns true if all character were decimal, otherwise false
     */
    int (*is_decimal)(sstring *a);

    /**
     * Checks whether all characters of `a` is ascii or not.
     * @param a pointer to struct sstring
     * @returns true if all character were ascii, otherwise false
     */
    int (*is_ascii)(sstring *a);

    /**
     * Checks whether all characters of `a` is alphabetic or not.
     * @param a pointer to struct sstring
     * @returns true if all character were alphabetic, otherwise false
     */
    int (*is_alphabetic)(sstring *a);

    /**
     * Formats `a` according to escape sequences.
     * @param a pointer to struct sstring
     * @returns true if all formatted, otherwise false
     */
    int (*format_escape_sequence)(sstring *a);

    /**
     * Inserts `src` into `a` at `index`.
     * @param a pointer to struct sstring
     * @param src string to insert
     * @param index where to insert `src`
     * @returns true if inserted `src` into `a`, otherwise false
     */
    int (*insert)(sstring *a, const char *src, size_t index);

    /**
     * Checks whether `a` starts with `src`.
     * @param a pointer to struct sstring
     * @param src string to check
     * @returns true if starts with `src`, otherwise false
     */
    int (*starts_with)(sstring *a, const char *src);

    /**
     * Checks whether `a` ends with `src`.
     * @param a pointer to struct sstring
     * @param src string to check
     * @returns true if ends with `src`, otherwise false
     */
    int (*ends_with)(sstring *a, const char *src);

    /**
     * Parse `a` into tokens and returns a `parse_t` struct. NOTE: Use `free_parse` function to avoid memory leaks.
     * @param a pointer to struct sstring
     * @returns `parse_t` struct with length, token and token type
     */
    parse_t (*parse)(sstring *a);

    /**
     * Converts `toks` to `sstring`, and then assigns it to `a`.
     * @param a pointer to struct sstring
     * @param toks pointer to struct parse_t
     * @returns true if converted, otherwise false
     */
    int (*from_parse_t)(sstring *a, parse_t *toks);

    /**
     * Assigns `__format__` to `a` with formatting.
     * @param a pointer to struct sstring
     * @param buffer_length length of `__format__` along with variable length `...`
     * @param __format__ string containing the format instructions
     * @param ... variables
     * @returns true if task completed, otherwise false
     */
    int (*set_formatted)(sstring *a, size_t buffer_length, const char *__format__, ...);

    /**
     * Appends `__format__` to `a` with formatting.
     * @param a pointer to struct sstring
     * @param buffer_length length of `__format__` along with variable length `...`
     * @param __format__ string containing the formatting instructions
     * @param ... variables
     * @returns true if task completed, otherwise false
     */
    int (*append_formatted)(sstring *a, size_t buffer_length, const char *__format__, ...);

    /**
     * Resizes `a` with new size `new_len`.
     * @param a pointer to struct sstring
     * @param new_len new length of `a`
     * @returns true if resized, otherwise false
     */
    int (*resize)(sstring *a, size_t new_len);

    /**
     * Returns hash of `a`.
     * @param a pointer to struct sstring
     * @returns hash of `a`
     */
    size_t (*hash)(sstring *a);

    /**
     * Value returned when an error is occurred.
     */
    size_t nerr;
} __string__;

#include "prototype_err.h"

/**
 * Linear time complexity = O(n), where n is the length of `src`. NOTE: `dest` must have enough space for `src`.
 * @param dest string where `src` is going to append
 * @param src string to be appended
 * @param size where to append `src`, pass your variable like &size);
 */
void fast_strncat(char *dest, const char *src, size_t *size)
{
    if (dest && src)
        while ((dest[*size] = *src++))
            *size += 1;
}

void _set(sstring *a, const char *src)
{
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        free((*(__str__ *)a->str).src);
        size_t len = strlen(src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        strcpy((*(__str__ *)a->str).src, src);
        (*(__str__ *)a->str).len = len;
    }
}

void _set_char(sstring *a, const char c)
{
    if (a && a->str && c != '\0' && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * 2, sizeof(char));
        strncpy((*(__str__ *)a->str).src, &c, 1);
        (*(__str__ *)a->str).len = 1;
    }
}

void _set_upto(sstring *a, const char *src, size_t N)
{
    size_t l = 0;
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src && N <= (l = strlen(src)))
    {
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
        strncpy((*(__str__ *)a->str).src, src, N);
        (*(__str__ *)a->str).len = N;
    }
}

void _set_random(sstring *a, const size_t len)
{
    if (a && a->str && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src && len > 0)
    {
        char *buff = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        // random ascii character betweem 32 and 126, inclusive
        for (size_t i = 0; i < len; i++)
            buff[i] = (rand() % (126 - 32 + 1)) + 32;
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)buff);
        free(buff);
        (*(__str__ *)a->str).len = len;
    }
}

void _set_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len)
{
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        int valid = true;
        if (till > len || from > len)
        {
            valid = false;
            return;
        }
        size_t cnt_t = 0;
        if (valid == true)
        {
            for (size_t i = from; i < till; i++)
            {
                if (src[i] == NULL)
                {
                    valid = false;
                    break;
                }
                else
                    cnt_t += strlen(src[i]);
            }
        }
        if (valid == true)
        {
            if (char_between != '\0')
                cnt_t += len + 1;
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + 1, sizeof(char)), bw[3] = "\0\0";
            size_t track = 0;
            for (size_t i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], &track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, &track);
            }
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
            strcpy((*(__str__ *)a->str).src, (const char *)buff);
            (*(__str__ *)a->str).len = track;
            free(buff);
        }
    }
}

char *_get(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
        return (*(__str__ *)a->str).src;
    return (char *)NULL;
}

void _append(sstring *a, const char *src)
{
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        size_t len = 0, l = strlen(src);
        if ((len = (*(__str__ *)a->str).len) == 0) // string is empty
        {
            free((*(__str__ *)a->str).src); // used calloc in `init_str` function
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (l + 1), sizeof(char));
            strcpy((*(__str__ *)a->str).src, src); // copy `src` to `a`.
            (*(__str__ *)a->str).len = l;
        }
        else
        {
            (*(__str__ *)a->str).src = (char *)realloc((*(__str__ *)a->str).src, sizeof(char) * (l + len + 1));
            fast_strncat((*(__str__ *)a->str).src, src, &len);
            (*(__str__ *)a->str).len = len;
        }
    }
}

void _append_char(sstring *a, const char c)
{
    if (a && a->str && c != '\0' && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        size_t len = 0;
        if ((len = (*(__str__ *)a->str).len) == 0) // string is empty
        {
            free((*(__str__ *)a->str).src); // used calloc in `init_str` function
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * 2, sizeof(char));
            strncpy((*(__str__ *)a->str).src, &c, 1); // copy `c` to `a`.
            (*(__str__ *)a->str).len = 1;
        }
        else
        {
            (*(__str__ *)a->str).src = (char *)realloc((*(__str__ *)a->str).src, (sizeof(char) * 2) + (len + 1));
            char __dat[3] = "\0\0";
            __dat[0] = c;
            fast_strncat((*(__str__ *)a->str).src, (const char *)__dat, &len);
            (*(__str__ *)a->str).len = len;
        }
    }
}

void _append_upto(sstring *a, const char *src, size_t N)
{
    size_t l = 0;
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src && N <= (l = strlen(src)) && N != 0)
    {
        size_t len = 0;
        if ((len = (*(__str__ *)a->str).len) == 0) // string is empty
        {
            free((*(__str__ *)a->str).src); // used calloc in `init_str` function
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
            strncpy((*(__str__ *)a->str).src, src, N); // copy `src` to `a`.
            (*(__str__ *)a->str).len = N;
        }
        else
        {
            (*(__str__ *)a->str).src = (char *)realloc((*(__str__ *)a->str).src, sizeof(char) * (N + len + 1));
            char *buff = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
            strncpy(buff, src, N);
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &len);
            free(buff);
            (*(__str__ *)a->str).len = len;
        }
    }
}

void _append_start(sstring *a, const char *src)
{
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        size_t len = 0, l = strlen(src);
        if ((len = (*(__str__ *)a->str).len) == 0) // string is empty
        {
            free((*(__str__ *)a->str).src); // used calloc in `init_str` function
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (l + 1), sizeof(char));
            strcpy((*(__str__ *)a->str).src, src); // copy `src` to `a`.
            (*(__str__ *)a->str).len = l;
        }
        else
        {
            char *buff = (char *)calloc(sizeof(char) * (l + len + 1), sizeof(char));
            size_t track = 0;
            fast_strncat(buff, src, &track);
            fast_strncat(buff, (const char *)(*(__str__ *)a->str).src, &track);
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * track) + 1, sizeof(char));
            track = 0;
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &track);
            free(buff);
            (*(__str__ *)a->str).len = track;
        }
    }
}

void _append_start_char(sstring *a, const char c)
{
    if (a && a->str && c != '\0' && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        size_t len = 0;
        if ((len = (*(__str__ *)a->str).len) == 0) // string is empty
        {
            free((*(__str__ *)a->str).src); // used calloc in `init_str` function
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * 2, sizeof(char));
            strncpy((*(__str__ *)a->str).src, &c, 1); // copy `c` to `a`.
            (*(__str__ *)a->str).len = len + 1;
        }
        else
        {
            char ___c[3] = "\0\0";
            ___c[0] = c;
            size_t track = 0;
            char *buff = (char *)calloc((sizeof(char) * 2) + (len + 1), sizeof(char));
            fast_strncat(buff, (const char *)___c, &track);
            fast_strncat(buff, (const char *)(*(__str__ *)a->str).src, &track);
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * track) + 1, sizeof(char));
            track = 0;
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &track);
            free(buff);
            (*(__str__ *)a->str).len = track;
        }
    }
}

void _append_start_upto(sstring *a, const char *src, size_t N)
{
    size_t l = 0;
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src && N <= (l = strlen(src)) && N != 0)
    {
        size_t len = 0;
        if ((len = (*(__str__ *)a->str).len) == 0) // string is empty
        {
            free((*(__str__ *)a->str).src); // used calloc in `init_str` function
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
            strncpy((*(__str__ *)a->str).src, src, N); // copy `src` to `a`.
            (*(__str__ *)a->str).len = N;
        }
        else
        {
            char *buff = (char *)calloc((sizeof(char) * (len + N + 1)), sizeof(char));
            strncpy(buff, src, N);
            size_t track = N;
            fast_strncat(buff, (const char *)(*(__str__ *)a->str).src, &track);
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * track) + 1, sizeof(char));
            track = 0;
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &track);
            free(buff);
            (*(__str__ *)a->str).len = track;
        }
    }
}

void _append_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len)
{
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        int valid = true;
        if (till > len || from > len)
        {
            valid = false;
            return;
        }
        size_t cnt_t = 0;
        if (valid == true)
        {
            for (size_t i = from; i < till; i++)
            {
                if (src[i] == NULL)
                {
                    valid = false;
                    break;
                }
                else
                    cnt_t += strlen(src[i]);
            }
        }
        if (valid == true)
        {
            if (char_between != '\0')
                cnt_t += len + 1;
            size_t slen = (*(__str__ *)a->str).len, track = 0;
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + slen + 1, sizeof(char)), bw[3] = "\0\0";
            fast_strncat(buff, (const char *)(*(__str__ *)a->str).src, &track);

            if (slen > 0 && (bw[0] = char_between) != '\0')
                fast_strncat(buff, (const char *)bw, &track);
            for (size_t i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], &track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, &track);
            }
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
            track = 0;
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &track);
            free(buff);
            (*(__str__ *)a->str).len = track;
        }
    }
}

void _append_start_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len)
{
    if (a && a->str && src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        int valid = true;
        if (till > len || from > len)
        {
            valid = false;
            return;
        }
        size_t cnt_t = 0;
        if (valid == true)
        {
            for (size_t i = from; i < till; i++)
            {
                if (src[i] == NULL)
                {
                    valid = false;
                    break;
                }
                else
                    cnt_t += strlen(src[i]);
            }
        }
        if (valid == true)
        {
            if (char_between != '\0')
                cnt_t += len + 1;
            size_t slen = (*(__str__ *)a->str).len, track = 0;
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + slen + 1, sizeof(char)), bw[3] = "\0\0";
            for (size_t i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], &track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, &track);
            }
            if (cnt_t > 2 && (bw[0] = char_between) != '\0')
                fast_strncat(buff, (const char *)bw, &track);
            fast_strncat(buff, (const char *)(*(__str__ *)a->str).src, &track);
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
            track = 0;
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &track);
            free(buff);
            (*(__str__ *)a->str).len = track;
        }
    }
}

int _empty(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
        if ((*(__str__ *)a->str).len == 0)
            return true;
    return false;
}

void _replace_char(sstring *a, const char old, const char new_)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; ++i)
            if ((*(__str__ *)a->str).src[i] == old)
                (*(__str__ *)a->str).src[i] = new_;
    }
}

void _char_set(sstring *a, const char what, size_t where)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        if ((*(__str__ *)a->str).len >= where && what != '\0')
            (*(__str__ *)a->str).src[where] = what;
    }
}

char _char_get(sstring *a, size_t where)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        if ((*(__str__ *)a->str).len >= where)
            return (*(__str__ *)a->str).src[where];
    }
    return (char)'\0';
}

size_t _length(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
        return strlen((const char *)(*(__str__ *)a->str).src);
    return (size_t)0;
}

int _compare(sstring *a, const char *T1)
{
    if (a && a->str && T1 && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        if (strcmp((const char *)(*(__str__ *)a->str).src, T1) == 0)
            return true;
    }
    return false;
}

int _compare_upto(sstring *a, const char *T1, size_t N)
{
    if (a && a->str && T1 && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src && strlen(T1) >= N)
    {
        if (strncmp((const char *)(*(__str__ *)a->str).src, T1, N) == 0)
            return true;
    }
    return false;
}

void _print(sstring *a, int add_next_line, const char *__format__, ...)
{
    if (a && a->str && __format__ && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        va_list ar;
        va_start(ar, __format__);
        printf("%s", (*(__str__ *)a->str).src);
        vprintf(__format__, ar);
        va_end(ar);
        if (add_next_line == true)
        {
#if defined __linux__ || defined linux || defined __linux
            printf("\n");
#elif _WIN32 || defined _WIN64 || defined __CYGWIN__
            printf("\r\n");
#elif defined __unix__ || defined __unix || defined unix
            printf("\n");
#elif defined __APPLE__ || defined __MACH__
            printf("\n");
#elif defined __FreeBSD__
            printf("\n");
#elif defined __ANDROID__
            printf("\n");
#endif
        }
        fflush(stdout);
    }
}

void _replace(sstring *a, const char *old, const char *new_)
{
    if (a && a->str && old && new_ && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
    {
        size_t i, count_old = 0, len_o = strlen(old), len_n = strlen(new_);
        const char *temp = (const char *)(*(__str__ *)a->str).src;
        for (i = 0; temp[i] != '\0'; ++i)
        {
            if (strstr((const char *)&temp[i], old) == &temp[i])
            {
                count_old++;
                i += len_o - 1;
            }
        }
        char *buff = (char *)calloc(sizeof(char) * (i + count_old * (len_n - len_o) + 1), sizeof(char));
        i = 0;
        while (*temp)
        {
            if (strstr(temp, old) == temp)
            {
                size_t x = 0;
                fast_strncat(&buff[i], new_, &x);
                i += len_n;
                temp += len_o;
            }
            else
                buff[i++] = *temp++;
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (i + 1), sizeof(char));
        (*(__str__ *)a->str).len = i;
        i = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &i);
        free(buff);
    }
}

int _destructor(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).init = false;
        (*(__str__ *)a->str).len = 0;
        free(a->str);
        return true;
    }
    return false;
}

const char *_c_str(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src)
        return (const char *)(*(__str__ *)a->str).src;
    return (const char *)NULL;
}

int _save(sstring *a, const char *location)
{
    if (a && a->str && (*(__str__ *)a->str).src && location && (*(__str__ *)a->str).init == true)
    {
        FILE *f = fopen(location, "wb");
        if (f != NULL)
        {
            fwrite((const char *)(*(__str__ *)a->str).src, (*(__str__ *)a->str).len, sizeof(char), f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _append_file(sstring *a, const char *location)
{
    if (a && a->str && (*(__str__ *)a->str).src && location && (*(__str__ *)a->str).init == true)
    {
        FILE *f = fopen(location, "ab");
        if (f != NULL)
        {
            fwrite((const char *)(*(__str__ *)a->str).src, (*(__str__ *)a->str).len, sizeof(char), f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _open(sstring *a, const char *location)
{
    if (a && a->str && location && (*(__str__ *)a->str).init == true)
    {
        FILE *f = fopen(location, "rb");
        if (f != NULL)
        {
            fseek(f, 0, SEEK_END);
            size_t len = ftell(f);
            fseek(f, 0, SEEK_SET);
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc(len + 1, sizeof(char));
            fread((*(__str__ *)a->str).src, len, sizeof(char), f);
            fclose(f);
            (*(__str__ *)a->str).len = len;
            return true;
        }
    }
    return false;
}

int _clear(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        free((*(__str__ *)a->str).src);
        free(a->str);
        a->str = (__str__ *)calloc(sizeof(__str__), sizeof(__str__));
        (*(__str__ *)a->str).src = (char *)calloc(1 * sizeof(char), sizeof(char));
        (*(__str__ *)a->str).len = 0;
        (*(__str__ *)a->str).init = true;
        return true;
    }
    return false;
}

void _to_upper(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; ++i)
        {
            if ((*(__str__ *)a->str).src[i] <= 122 && (*(__str__ *)a->str).src[i] >= 97)
                (*(__str__ *)a->str).src[i] -= 32;
        }
    }
}

void _to_lower(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; ++i)
        {
            if ((*(__str__ *)a->str).src[i] <= 90 && (*(__str__ *)a->str).src[i] >= 65)
                (*(__str__ *)a->str).src[i] += 32;
        }
    }
}

void _swap_case(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; ++i)
        {
            if ((*(__str__ *)a->str).src[i] <= 90 && (*(__str__ *)a->str).src[i] >= 65)
                (*(__str__ *)a->str).src[i] += 32;
            else if ((*(__str__ *)a->str).src[i] <= 122 && (*(__str__ *)a->str).src[i] >= 97)
                (*(__str__ *)a->str).src[i] -= 32;
        }
    }
}

int _is_initialized(sstring *a)
{
    if (a && a->str)
        if ((*(__str__ *)a->str).init == true)
            return true;
    return false; // never reaches this point by the way, call this function(_is_initialized) directly to get a value i.e, true or false.
}

#include "binary.h"

void _to_binary(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len, size = 0;
        char *buff = (char *)calloc(((2 * (len * 8)) + 1) * sizeof(char), sizeof(char));
        for (size_t i = 0; i < len; ++i)
        {
            fast_strncat(buff, binary_data[(size_t)(*(__str__ *)a->str).src[i]], &size);
            if (i < len - 1)
                fast_strncat(buff, " ", &size);
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (size + 1), sizeof(char));
        size = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &size);
        (*(__str__ *)a->str).len = size;
        free(buff);
    }
}

int _from_binary(sstring *a)
{
    int valid = true;
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len;
        // test 1 for checking binary input format
        for (size_t i = 0; i < len; i++)
        {
            switch ((*(__str__ *)a->str).src[i])
            {
            case '1':
            case '0':
            case ' ':
                break;

            default:
                valid = false;
                break;
            }
            if (valid == false)
                break;
        }
        // test 2 for checking binary input format
        if (valid == true)
        {
            size_t cnt = 0;
            for (size_t i = 0; i < len; i++)
            {
                if ((*(__str__ *)a->str).src[i] == ' ')
                    cnt++;
            }
            if ((len - cnt) % 8 == 0 && ((len - cnt) / 8) == (cnt + 1))
                valid = true;
            else
                valid = false;
        }
        if (valid == true)
        {
            char *buff = (char *)calloc((len / 8) + 1, sizeof(char));
            char bin[9] = "\0", store[2] = "\0";
            char c = '\0';
            size_t z = 0;
            for (size_t i = 0, j = 0; i < len; ++i, ++j)
            {
                if ((*(__str__ *)a->str).src[i] == ' ')
                {
                    c = strtol(bin, (char **)NULL, 2);
                    store[0] = c;
                    fast_strncat(buff, (const char *)store, &z);
                    j = 0;
                }
                if (i == len - 1)
                {
                    bin[j] = (*(__str__ *)a->str).src[i]; // append last character
                    c = strtol(bin, (char **)NULL, 2);
                    store[0] = c;
                    fast_strncat(buff, store, &z);
                }
                bin[j] = (*(__str__ *)a->str).src[i];
            }
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (z + 1), sizeof(char));
            z = 0;
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &z);
            (*(__str__ *)a->str).len = z;
            free(buff);
        }
    }
    return valid;
}

long double _entropy(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len;
        size_t cnt = 0, map_append = 0, o = 0;
        int check = false;
        char *map_char = (char *)calloc((sizeof(char) * (len + 1)), sizeof(char));
        size_t *map_cnt = (size_t *)calloc((sizeof(size_t) * (len + 1)), sizeof(size_t));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; map_char[o] != '\0'; o++)
            {
                if (map_char[o] == (*(__str__ *)a->str).src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                map_char[map_append] = (*(__str__ *)a->str).src[cnt];
                map_cnt[map_append] = 1;
                map_append++;
            }
            else
                map_cnt[o] += 1;
        }
        long double result = 0.0f;
        long double freq = 0.0f;
        for (size_t i = 0; map_char[i] != '\0'; i++)
        {
            freq = (long double)map_cnt[i] / len;
            result -= freq * (log10l(freq) / log10l(2.0f));
        }
        free(map_char);
        free(map_cnt);
        return result;
    }
    return 0.0f;
}

int _contains(sstring *a, const char *str)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && str)
        if (strstr((const char *)(*(__str__ *)a->str).src, str) != NULL)
            return true;
    return false;
}

size_t _contains_char(sstring *a, const char c)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && c != '\0')
    {
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; i++)
            if ((*(__str__ *)a->str).src[i] == c)
                return (size_t)i;
    }
    return (size_t)-1;
}

void _to_set(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len;
        size_t cnt = 0, map_append = 0, o = 0;
        int check = false;
        char *set_char = (char *)calloc((sizeof(char) * (len + 1)), sizeof(char));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; set_char[o] != '\0'; o++)
            {
                if (set_char[o] == (*(__str__ *)a->str).src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                set_char[map_append] = (*(__str__ *)a->str).src[cnt];
                map_append++;
            }
        }
        free((*(__str__ *)a->str).src);
        size_t set_len = strlen((const char *)set_char);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (set_len + 1), sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)set_char);
        (*(__str__ *)a->str).len = set_len;
        free(set_char);
    }
}

int _copy(sstring *a, sstring *dest)
{
    if (a && a->str && dest && (*(__str__ *)dest->str).src && (*(__str__ *)dest->str).init == true && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        free((*(__str__ *)dest->str).src);
        (*(__str__ *)dest->str).src = (char *)calloc(sizeof(char) * ((*(__str__ *)a->str).len + 1), sizeof(char));
        strcpy((*(__str__ *)dest->str).src, (const char *)(*(__str__ *)a->str).src);
        (*(__str__ *)dest->str).len = (*(__str__ *)a->str).len;
        return true;
    }
    return false;
}

void _to_hexadecimal(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        char *buff = (char *)calloc((sizeof(char) * (*(__str__ *)a->str).len * 2) + 1, sizeof(char));
        size_t i = 0, j = 0;
        while ((*(__str__ *)a->str).src[i] != '\0')
        {
            sprintf((char *)buff + j, "%02X", (*(__str__ *)a->str).src[i]);
            i++, j += 2;
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (j + 1), sizeof(char));
        j = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &j);
        (*(__str__ *)a->str).len = j;
        free(buff);
    }
}

int _from_hexadecimal(sstring *a)
{
    int valid = true;
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len;
        // test 1 for checking hexadecimal input format
        for (size_t i = 0; i < len; i++)
        {
            switch ((*(__str__ *)a->str).src[i])
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
                valid = false;
                break;
            }
            if (valid == false)
                break;
        }
        // test 2 for checking hexadecimal input format
        if (valid == true)
            if (len % 2 != 0)
                valid = false;
        if (valid == true)
        {
            char *buff = (char *)calloc((len) / 2 + 1, sizeof(char));
            char bin[3] = "\0", store[2] = "\0";
            char c = '\0';
            size_t z = 0;
            for (size_t i = 0, j = 0; i < len; ++i)
            {
                if (i == len - 1)
                {
                    bin[j] = (*(__str__ *)a->str).src[i];
                    c = strtol(bin, (char **)NULL, 16);
                    store[0] = c;
                    fast_strncat(buff, (const char *)store, &z);
                }
                if (j == 2)
                {
                    j = 0;
                    c = strtol(bin, (char **)NULL, 16);
                    store[0] = c;
                    fast_strncat(buff, (const char *)store, &z);
                }
                bin[j] = (*(__str__ *)a->str).src[i];
                j++;
            }
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (z + 1), sizeof(char));
            z = 0;
            fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &z);
            (*(__str__ *)a->str).len = z;
            free(buff);
        }
    }
    return valid;
}

size_t _find(sstring *a, const char *sub)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && sub)
    {
        char *buff;
#ifdef __cplusplus
        buff = (char *)strstr((const char *)(*(__str__ *)a->str).src, sub);
#else
        buff = strstr((const char *)(*(__str__ *)a->str).src, sub);
#endif
        if (buff != NULL)
            return (size_t)(*(__str__ *)a->str).len - strlen((const char *)buff); // buff is subset of a, if buff != NULL
    }
    return (size_t)-1;
}

int _in(sstring *a, int get_line, size_t buff_size)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        char *buff = (char *)calloc((sizeof(char) * buff_size + 1), sizeof(char));
        size_t len_ = 0;
        if (get_line == false)
        {
            char _____format_____[128] = "%%";
            sprintf(_____format_____ + 1, "%lu", buff_size);
            strcat(_____format_____, "s");
            scanf(_____format_____, buff);
            len_ = strlen((const char *)buff);
        }
        else
        {
            fgets(buff, buff_size, stdin);
            len_ = strlen((const char *)buff);
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * len_) + 1, sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)buff);
        free(buff);
        (*(__str__ *)a->str).len = len_;
        return true;
    }
    return false;
}

char *_getline(sstring *a, size_t line)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len, cnt = 0;
        char *temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char)), *tok;
        strcpy(temp, (*(__str__ *)a->str).src);
        tok = strtok(temp, "\n");
        while (tok)
        {
            if (cnt++ == line)
                break;
            tok = strtok(NULL, "\n");
        }
        if (cnt == 0 || tok == NULL)
        {
            free(temp);
            return (char *)NULL;
        }
        char *res = (char *)calloc((sizeof(char) * strlen((const char *)tok)) + 1, sizeof(char));
        strcpy(res, (const char *)tok);
        free(temp);
        return res;
    }
    return (char *)NULL;
}

void _reverse(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len, l = len / 2;
        char c = '\0';
        for (size_t i = 0; i < l; i++)
        {
            c = (*(__str__ *)a->str).src[i];
            (*(__str__ *)a->str).src[i] = (*(__str__ *)a->str).src[len - i - 1];
            (*(__str__ *)a->str).src[len - i - 1] = c;
        }
    }
}

size_t _remove(sstring *a, const char *sub)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && sub && sub[0] != '\0')
    {
        char *buff = (char *)calloc((sizeof(char) * (*(__str__ *)a->str).len) + 1, sizeof(char));
        strcpy(buff, (const char *)(*(__str__ *)a->str).src);
        size_t len_s = strlen(sub), cnt = 0;
        {
            char *temp = buff;
            size_t size = 0;
            while ((temp = strstr(temp, sub)))
            {
                size = (size == 0) ? (temp - buff) + strlen(temp + len_s) + 1 : size - len_s;
                memmove(temp, temp + len_s, size - (temp - buff));
                cnt += len_s;
            }
            free(temp);
        }
        free((*(__str__ *)a->str).src);
        size_t len_buff = strlen((const char *)buff);
        (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * len_buff) + 1, sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)buff);
        free(buff);
        (*(__str__ *)a->str).len = len_buff;
        return cnt;
    }
    return 0;
}

size_t _remove_char(sstring *a, const char c)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && c != '\0')
    {
        char *buff = (char *)calloc((sizeof(char) * (*(__str__ *)a->str).len) + 1, sizeof(char));
        size_t cnt = 0;
        for (size_t i = 0, k = 0; (*(__str__ *)a->str).src[i] != '\0'; i++)
        {
            if ((*(__str__ *)a->str).src[i] != c)
            {
                buff[k] = (*(__str__ *)a->str).src[i];
                k++;
            }
            else
                cnt++;
        }
        free((*(__str__ *)a->str).src);
        size_t buff_len = strlen((const char *)buff);
        (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * buff_len) + 1, sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)buff);
        free(buff);
        (*(__str__ *)a->str).len = buff_len;
        return cnt;
    }
    return 0;
}

size_t _remove_extra_char(sstring *a, const char c)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && c != '\0')
    {
        char *buff = (char *)calloc((sizeof(char) * (*(__str__ *)a->str).len) + 1, sizeof(char));
        size_t p = 0, i = 0, cnt = 0;
        while ((*(__str__ *)a->str).src[p] != '\0')
        {
            if (!((*(__str__ *)a->str).src[p] == c && (*(__str__ *)a->str).src[p + 1] == c))
            {
                buff[i] = (*(__str__ *)a->str).src[p];
                i++;
            }
            else
                cnt++;
            p++;
        }
        buff[i] = '\0';
        free((*(__str__ *)a->str).src);
        size_t buff_len = strlen((const char *)buff);
        (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * buff_len) + 1, sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)buff);
        free(buff);
        (*(__str__ *)a->str).len = buff_len;
        return cnt;
    }
    return 0;
}

size_t _remove_range(sstring *a, size_t from, size_t till)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len, cnt = 0;
        if (till > len || from > len || from > till)
            return cnt;
        char *buff = (char *)calloc(sizeof(char) * (len - (till - from) + 1), sizeof(char));
        for (size_t i = 0, k = 0; i < len; i++)
        {
            if (i == from)
            {
                i += till - from;
                cnt += (till - from);
            }
            if (i < from || i > from)
            {
                buff[k] = (*(__str__ *)a->str).src[i];
                k++;
            }
        }
        free((*(__str__ *)a->str).src);
        size_t buff_len = strlen((const char *)buff);
        (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * buff_len) + 1, sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)buff);
        free(buff);
        (*(__str__ *)a->str).len = buff_len;
        return cnt;
    }
    return 0;
}

int _intersect(sstring *a, size_t from, size_t till)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len;
        if (till > len || from > len || from > till)
            return false;
        char *buff = (char *)calloc(sizeof(char) * ((till - from) + 1), sizeof(char));
        for (size_t i = from, k = 0; i < till; i++)
        {
            buff[k] = (*(__str__ *)a->str).src[i];
            k++;
        }
        free((*(__str__ *)a->str).src);
        size_t buff_len = strlen((const char *)buff);
        (*(__str__ *)a->str).src = (char *)calloc((sizeof(char) * buff_len) + 1, sizeof(char));
        strcpy((*(__str__ *)a->str).src, (const char *)buff);
        free(buff);
        (*(__str__ *)a->str).len = buff_len;
        return true;
    }
    return false;
}

size_t _distance(sstring *a, const char *src)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && src)
    {
        if (strlen(src) == (*(__str__ *)a->str).len)
        {
            size_t cnt = 0;
            for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; i++)
                if ((*(__str__ *)a->str).src[i] != src[i])
                    cnt++;
            return (size_t)cnt;
        }
    }
    return (size_t)-1;
}

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX2(x, y) ((x > y) ? x : y)
size_t _edit_distance(sstring *a, const char *src)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && src)
    {
        size_t len1 = (*(__str__ *)a->str).len, len2 = strlen(src), x, y, last, old;
        size_t cols[len1 + 1];
        for (y = 1; y <= len1; y++)
            cols[y] = y;
        for (x = 1; x <= len2; x++)
        {
            cols[0] = x;
            for (y = 1, last = x - 1; y <= len1; y++)
            {
                old = cols[y];
                cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + ((*(__str__ *)a->str).src[y - 1] == src[x - 1] ? 0 : 1));
                last = old;
            }
        }
        return (size_t)cols[len1];
    }
    return (size_t)-1;
}

long double _percentage_matched(sstring *a, const char *src)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && src)
    {
        size_t len1 = (*(__str__ *)a->str).len, len2 = strlen(src), x, y, last, old;
        size_t cols[len1 + 1];
        for (y = 1; y <= len1; y++)
            cols[y] = y;
        for (x = 1; x <= len2; x++)
        {
            cols[0] = x;
            for (y = 1, last = x - 1; y <= len1; y++)
            {
                old = cols[y];
                cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + ((*(__str__ *)a->str).src[y - 1] == src[x - 1] ? 0 : 1));
                last = old;
            }
        }
        size_t max = MAX2(len1, len2);
        return (max - cols[len1]) * 100.0f / max;
    }
    return (long double)0.0f;
}

size_t _count(sstring *a, const char *what)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && what)
    {
        size_t cnt = 0, len = strlen(what);
        const char *sub = (const char *)(*(__str__ *)a->str).src;
        while ((sub = strstr(sub, what)))
        {
            cnt++;
            sub += len;
        }
        return cnt;
    }
    return 0;
}

size_t _count_char(sstring *a, const char what)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && what != '\0')
    {
        size_t cnt = 0;
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; i++)
            if ((*(__str__ *)a->str).src[i] == what)
                cnt++;
        return cnt;
    }
    return 0;
}

char *_soundex(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t s = 1, len = (*(__str__ *)a->str).len;
        const char *map = "01230120022455012623010202"; // not stored in heap memory, do not free it
        char c, *res = (char *)calloc(sizeof(char) * 5, sizeof(char));
        res[0] = toupper((*(__str__ *)a->str).src[0]);
        for (size_t i = 1; i < len; ++i)
        {
            c = toupper((*(__str__ *)a->str).src[i]) - 65;
            if (c >= 0 && c <= 25) // from ASCII table
            {
                if (map[(size_t)c] != '\0')
                {
                    if (map[(size_t)c] != res[s - 1])
                    {
                        res[s] = map[(size_t)c];
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
        return res;
    }
    return (char *)(NULL);
}

int strcmp_void(const void *a1, const void *a2)
{
    return strcmp((const char *)a1, (const char *)a2);
}

char *_most_used(sstring *a, const char *dl)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && dl)
    {
        size_t len = (*(__str__ *)a->str).len, cnt = 0, l = 0;
        cnt = a->count(a, dl);
        if (cnt == 0)
            return (char *)NULL;
        char *temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        strcpy(temp, (*(__str__ *)a->str).src);
        char **buff = (char **)calloc((sizeof(char *) * cnt) + sizeof(char *), sizeof(char *)), *tok = strtok(temp, dl);
        while (tok != NULL)
        {
            buff[l] = tok;
            tok = strtok(NULL, dl);
            l++;
        }
        qsort(buff, l, sizeof(buff[0]), strcmp_void);
        char *res = NULL;
        size_t m = 0, curr = 0;
        for (size_t i = 0; i < l; i++)
        {
            if (!strcmp(buff[i], buff[i - curr]))
                curr += 1;
            else
                curr = 1;
            if (curr > m)
            {
                res = buff[i];
                m = curr;
            }
        }
        char *x = (char *)calloc((sizeof(char) * strlen((const char *)res)) + 1, sizeof(char));
        strcpy(x, res);
        free(temp);
        free(buff);
        return x;
    }
    return (char *)NULL;
}

char _most_used_char(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = (*(__str__ *)a->str).len;
        size_t cnt = 0, map_append = 0, o = 0;
        int check = false;
        char *map_char = (char *)calloc((sizeof(char) * (len + 1)), sizeof(char));
        size_t *map_cnt = (size_t *)calloc((sizeof(size_t) * (len + 1)), sizeof(size_t));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; map_char[o] != '\0'; o++)
            {
                if (map_char[o] == (*(__str__ *)a->str).src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                map_char[map_append] = (*(__str__ *)a->str).src[cnt];
                map_cnt[map_append] = 1;
                map_append++;
            }
            else
                map_cnt[o] += 1;
        }
        size_t n = map_cnt[0], q = 0;
        for (size_t i = 1; map_char[i] != '\0'; i++)
        {
            if (n < map_cnt[i])
            {
                n = map_cnt[i];
                q = i;
            }
        }
        char c = map_char[q];
        free(map_char);
        free(map_cnt);
        return c;
    }
    return '\0';
}

split_t _split(sstring *a, const char *dl)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && dl && dl[0] != '\0')
    {
        split_t x;
        x.data = (char **)NULL;
        x.len = 0;
        size_t len = (*(__str__ *)a->str).len, cnt = 0;
        char *temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char)), *tok;
        strcpy(temp, (*(__str__ *)a->str).src);
        tok = strtok(temp, dl);
        while (tok)
        {
            cnt++;
            tok = strtok(NULL, dl);
            if (!tok)
                break;
        }
        free(temp);
        if (cnt == 0)
            return x;
        temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        strcpy(temp, (*(__str__ *)a->str).src);
        x.data = (char **)calloc((sizeof(char *) * (cnt + 1)), sizeof(char *));
        tok = strtok(temp, dl);
        while (tok)
        {
            x.data[x.len] = (char *)calloc((sizeof(char) * strlen((const char *)tok)) + 1, sizeof(char));
            strcpy(x.data[x.len], (const char *)tok);
            x.len++;
            tok = strtok(NULL, dl);
            if (!tok)
                break;
        }
        free(temp);
        return x;
    }
    split_t x;
    x.data = (char **)NULL;
    x.len = 0;
    return x;
}

int compare_chars(const void *c1, const void *c2)
{
    return (*(char *)c1 - *(char *)c2);
}

void _sort(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src[0] != '\0')
        qsort((*(__str__ *)a->str).src, (*(__str__ *)a->str).len, sizeof(char), compare_chars);
}

size_t _open_binary(sstring *a, const char *location)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && location)
    {
        FILE *f = fopen(location, "rb");
        if (f != NULL)
        {
            fseek(f, 0, SEEK_END);
            size_t len = ftell(f);
            fseek(f, 0, SEEK_SET);
            unsigned char *_temp_ = (unsigned char *)calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
            free((*(__str__ *)a->str).src);
            (*(__str__ *)a->str).src = (char *)calloc(len + 1, sizeof(char));
            fread(_temp_, len, sizeof(unsigned char), f);
            memcpy((*(__str__ *)a->str).src, (const void *)_temp_, len);
            fclose(f);
            free(_temp_);
            return len;
        }
    }
    return 0;
}

int _save_binary(sstring *a, const char *location, size_t len)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && location)
    {
        unsigned char *_temp_ = (unsigned char *)calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
        memcpy(_temp_, (const void *)(*(__str__ *)a->str).src, len);
        FILE *f = fopen(location, "wb");
        if (f != NULL)
        {
            fwrite((unsigned char *)_temp_, len, sizeof(unsigned char), f);
            fclose(f);
            free(_temp_);
            return true;
        }
        free(_temp_);
    }
    return false;
}

int _append_binary(sstring *a, const char *location, size_t len)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && location)
    {
        unsigned char *_temp_ = (unsigned char *)calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
        memcpy(_temp_, (const void *)(*(__str__ *)a->str).src, len);
        FILE *f = fopen(location, "ab");
        if (f != NULL)
        {
            fwrite((unsigned char *)_temp_, len, sizeof(unsigned char), f);
            fclose(f);
            free(_temp_);
            return true;
        }
        free(_temp_);
    }
    return false;
}

size_t _add_binary(sstring *a, const char *data, size_t len)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && data)
    {
        size_t size = len;
        (*(__str__ *)a->str).src = (char *)realloc((*(__str__ *)a->str).src, (sizeof(char) * (len + strlen(data) + 1)));
        fast_strncat((*(__str__ *)a->str).src, data, &size);
        return size - len; // total data written
    }
    return 0;
}

int _print_binary(sstring *a, size_t len)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t x = 0;
        while (x != len)
            printf("%c", (*(__str__ *)a->str).src[x++]);
        return true;
    }
    return false;
}

int _encrypt(sstring *a, const char *key)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && key)
    {
        sstring __temp__ = new_sstring(0, key);
        size_t val = __temp__.hash(&__temp__) % 128;
        __temp__.destructor(&__temp__);
        size_t len = (*(__str__ *)a->str).len;
        short add = true;
        char *buff = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; i++)
        {
            if (add == true && (*(__str__ *)a->str).src[i] + val > '\0')
            {
                buff[i] = (*(__str__ *)a->str).src[i] + val;
                add = false;
            }
            else if (add == false && (*(__str__ *)a->str).src[i] - val > '\0')
            {
                buff[i] = (*(__str__ *)a->str).src[i] - val;
                add = true;
            }
            else
            {
                free(buff);
                return false;
            }
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        len = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &len);
        (*(__str__ *)a->str).len = len;
        free(buff);
        return true;
    }
    return false;
}

int _decrypt(sstring *a, const char *key)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && key)
    {
        sstring __temp__ = new_sstring(0, key);
        size_t val = __temp__.hash(&__temp__) % 128;
        __temp__.destructor(&__temp__);
        size_t len = (*(__str__ *)a->str).len;
        short add_inrv = true;
        char *buff = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        for (size_t i = 0; (*(__str__ *)a->str).src[i] != '\0'; i++)
        {
            if (add_inrv == true && (*(__str__ *)a->str).src[i] - val > '\0')
            {
                buff[i] = (*(__str__ *)a->str).src[i] - val;
                add_inrv = false;
            }
            else if (add_inrv == false && (*(__str__ *)a->str).src[i] + val > '\0')
            {
                buff[i] = (*(__str__ *)a->str).src[i] + val;
                add_inrv = true;
            }
            else
            {
                free(buff);
                return false;
            }
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        len = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &len);
        (*(__str__ *)a->str).len = len;
        free(buff);
        return true;
    }
    return false;
}

size_t _begin(void)
{
    return 0ULL;
}

void __advance__iter_sstring(iter_sstring *is, signed long long int move_by)
{
    if (is)
        is->cur += move_by;
}

int __c_loop__iter_sstring(iter_sstring *is)
{
    if (is)
    {
        if (is->is_max_smaller == true)
        {
            if (is->max < is->cur)
                return true;
            else
                return false;
        }
        else if (is->is_max_smaller == false)
        {
            if (is->max > is->cur)
                return true;
            else
                return false;
        }
    }
    return false;
}

iter_sstring _iterator(sstring *a)
{
    return (iter_sstring){.cur = 0, .max = (*(__str__ *)a->str).len, .is_max_smaller = false, .advance = __advance__iter_sstring, .c_loop = __c_loop__iter_sstring};
}

iter_sstring __reverse_iterator(sstring *a)
{
    return (iter_sstring){.cur = (*(__str__ *)a->str).len, .max = -1, .is_max_smaller = true, .advance = __advance__iter_sstring, .c_loop = __c_loop__iter_sstring};
}

size_t _end_sstring(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
        return (*(__str__ *)a->str).len;
    return 0;
}

#include "morse_code.h"
int _to_morse_code(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
            if (!isdigit((*(__str__ *)a->str).src[i]) && !isalpha((*(__str__ *)a->str).src[i]) && (*(__str__ *)a->str).src[i] != ' ')
                return false;
        char *buff = (char *)calloc((sizeof(char) * (*(__str__ *)a->str).len * 8) + 1, sizeof(char));
        size_t track = 0;
        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
        {
            if (isdigit((*(__str__ *)a->str).src[i]))
                fast_strncat(buff, morse_code[(size_t)(*(__str__ *)a->str).src[i] - 48].code, &track);
            else if ((*(__str__ *)a->str).src[i] == ' ')
                fast_strncat(buff, morse_code[(size_t)36].code, &track);
            else
            {
                if ((*(__str__ *)a->str).src[i] >= 65 && (*(__str__ *)a->str).src[i] <= 90)
                    fast_strncat(buff, morse_code[(size_t)(*(__str__ *)a->str).src[i] - 55].code, &track);
                else
                    fast_strncat(buff, morse_code[(size_t)(*(__str__ *)a->str).src[i] - 87].code, &track);
            }
            if (i < (*(__str__ *)a->str).len - 1)
                fast_strncat(buff, " ", &track);
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
        track = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &track);
        free(buff);
        (*(__str__ *)a->str).len = track;
        return true;
    }
    return false;
}

int _from_morse_code(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
        {
            switch ((*(__str__ *)a->str).src[i])
            {
            case '-':
            case '.':
            case ' ':
                break;
            default:
                return false;
            }
        }
        char *buff = (char *)calloc(sizeof(char) * ((*(__str__ *)a->str).len + 1), sizeof(char)), *temp = (char *)calloc(sizeof(char) * 8, sizeof(char));
        size_t track = 0, x = 0;
        char arr[3] = "\0\0";
        for (size_t i = 0, k = 0; i < (*(__str__ *)a->str).len; i++, k++)
        {
            if (i == (*(__str__ *)a->str).len - 1)
            {
                x = 0;
                temp[k] = (*(__str__ *)a->str).src[i];
                while ((strcmp(temp, morse_code[x].code)) != 0)
                    x++;
                arr[0] = morse_code[x].character;
                fast_strncat(buff, (const char *)arr, &track);
            }
            if ((*(__str__ *)a->str).src[i] == ' ')
            {
                i++, x = 0;
                while ((strcmp(temp, morse_code[x].code)) != 0)
                    x++;
                arr[0] = morse_code[x].character;
                fast_strncat(buff, (const char *)arr, &track);
                memset(temp, 0, 8);
                k = 0;
            }
            temp[k] = (*(__str__ *)a->str).src[i];
        }
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
        track = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &track);
        free(buff);
        free(temp);
        (*(__str__ *)a->str).len = track;
        return true;
    }
    return false;
}

int _is_digit(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src[0] != '\0')
    {
        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
            if (!isdigit((*(__str__ *)a->str).src[i]))
                return false;
        return true;
    }
    return false;
}

int _is_decimal(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src[0] != '\0')
    {
        size_t point_cnt = 0;
        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
        {
            if ((*(__str__ *)a->str).src[i] == 46)
            {
                point_cnt++;
                if (point_cnt > 1)
                    return false;
            }
            else if (!isdigit((*(__str__ *)a->str).src[i]))
                return false;
        }
        if (point_cnt == 1)
            return true;
    }
    return false;
}

int _is_ascii(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src[0] != '\0')
    {
        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
            if ((*(__str__ *)a->str).src[i] <= 0 || (*(__str__ *)a->str).src[i] >= 127)
                return false;
        return true;
    }
    return false;
}

int _is_alphabetic(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).src[0] != '\0')
    {
        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
            if (!isalpha((*(__str__ *)a->str).src[i]))
                return false;
        return true;
    }
    return false;
}

int _format_escape_sequence(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        _replace(a, "\\", "\\\\");
        _replace(a, "\a", "\\a");
        _replace(a, "\b", "\\b");
        _replace(a, "\f", "\\f");
        _replace(a, "\n", "\\n");
        _replace(a, "\r", "\\r");
        _replace(a, "\t", "\\t");
        _replace(a, "\v", "\\v");
        _replace(a, "\"", "\\\"");
        _replace(a, "\'", "\\\'");
        _replace(a, "\?", "\\\?");
        return true;
    }
    return false;
}

/**
 * Converts escape sequences to their representable strings (as const).
 * @param c escape sequence of the character
 * @returns representable string of escape sequences, if `c` is not an escape sequence then NUL is returned
 */
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

/**
 * Converts strings to their respective escape sequences, if possible.
 * To get escape sequence as (char) use `char c = *esc_seq_to_char_ptr("\\n");`
 * @param c string
 * @returns escape sequence of `c`, otherwise returns `c`
 */
const char *esc_seq_to_char_ptr(const char *c)
{
    if (strcmp(c, "\\\\") == 0)
        return (const char *)"\\";
    else if (strcmp(c, "\\a") == 0)
        return (const char *)"\a";
    else if (strcmp(c, "\\b") == 0)
        return (const char *)"\b";
    else if (strcmp(c, "\\f") == 0)
        return (const char *)"\f";
    else if (strcmp(c, "\\n") == 0)
        return (const char *)"\n";
    else if (strcmp(c, "\\r") == 0)
        return (const char *)"\r";
    else if (strcmp(c, "\\t") == 0)
        return (const char *)"\t";
    else if (strcmp(c, "\\v") == 0)
        return (const char *)"\v";
    else if (strcmp(c, "\\\"") == 0)
        return (const char *)"\"";
    else if (strcmp(c, "\\\'") == 0)
        return (const char *)"\'";
    else if (strcmp(c, "\\\?") == 0)
        return (const char *)"\?";
    else if (strcmp(c, "\\0") == 0)
        return (const char *)"\0";
    else
        return c;
}

int _insert(sstring *a, const char *src, size_t index)
{
    if (a && a->str && (*(__str__ *)a->str).src && src && (*(__str__ *)a->str).init == true && index <= (*(__str__ *)a->str).len)
    {
        size_t len = strlen(src);
        (*(__str__ *)a->str).src = (char *)realloc((*(__str__ *)a->str).src, sizeof(char) * ((*(__str__ *)a->str).len + len + 1));
        for (size_t i = (*(__str__ *)a->str).len; i >= index; i--)
        {
            (*(__str__ *)a->str).src[i + len] = (*(__str__ *)a->str).src[i];
            (*(__str__ *)a->str).src[i] = '\0';
            if (i == 0)
                break;
        }
        memcpy((*(__str__ *)a->str).src + index, src, len);
        (*(__str__ *)a->str).len += len;
        return true;
    }
    return false;
}

int _starts_with(sstring *a, const char *src)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && src)
    {
        if (strlen(src) > (*(__str__ *)a->str).len)
            return false;
        for (size_t i = 0; src[i] != '\0' && (*(__str__ *)a->str).src[i] != '\0'; i++)
            if ((*(__str__ *)a->str).src[i] != src[i])
                return false;
        return true;
    }
    return false;
}

int _ends_with(sstring *a, const char *src)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && src)
    {
        size_t len = strlen(src);
        if (len > (*(__str__ *)a->str).len)
            return false;
        for (size_t i = (*(__str__ *)a->str).len - len, z = 0; src[z] != '\0' && (*(__str__ *)a->str).src[i] != '\0'; i++, z++)
            if ((*(__str__ *)a->str).src[i] != src[z])
                return false;
        return true;
    }
    return false;
}

parse_t _parse(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        size_t len = 0;
        for (size_t i = 0; i < (*(__str__ *)a->str).len;)
        {
            if (((*(__str__ *)a->str).src[i] >= 97 && (*(__str__ *)a->str).src[i] <= 122) || ((*(__str__ *)a->str).src[i] >= 65 && (*(__str__ *)a->str).src[i] <= 90))
            {
                while (((*(__str__ *)a->str).src[i] >= 97 && (*(__str__ *)a->str).src[i] <= 122) || ((*(__str__ *)a->str).src[i] >= 65 && (*(__str__ *)a->str).src[i] <= 90))
                    i++;
                len++;
            }
            else if ((*(__str__ *)a->str).src[i] == 32)
                i++, len++;
            else if (isdigit((*(__str__ *)a->str).src[i]))
            {
                while (isdigit((*(__str__ *)a->str).src[i]))
                    i++;
                len++;
            }
            else if ((*(__str__ *)a->str).src[i] == '\\' || (*(__str__ *)a->str).src[i] == '\a' || (*(__str__ *)a->str).src[i] == '\b' || (*(__str__ *)a->str).src[i] == '\f' || (*(__str__ *)a->str).src[i] == '\n' || (*(__str__ *)a->str).src[i] == '\r' || (*(__str__ *)a->str).src[i] == '\t' || (*(__str__ *)a->str).src[i] == '\v' || (*(__str__ *)a->str).src[i] == '\"' || (*(__str__ *)a->str).src[i] == '\'' || (*(__str__ *)a->str).src[i] == '\?')
            {
                while ((*(__str__ *)a->str).src[i] == '\\' || (*(__str__ *)a->str).src[i] == '\a' || (*(__str__ *)a->str).src[i] == '\b' || (*(__str__ *)a->str).src[i] == '\f' || (*(__str__ *)a->str).src[i] == '\n' || (*(__str__ *)a->str).src[i] == '\r' || (*(__str__ *)a->str).src[i] == '\t' || (*(__str__ *)a->str).src[i] == '\v' || (*(__str__ *)a->str).src[i] == '\"' || (*(__str__ *)a->str).src[i] == '\'' || (*(__str__ *)a->str).src[i] == '\?')
                    i++, len++;
            }
            else if (((*(__str__ *)a->str).src[i] == 33) || ((*(__str__ *)a->str).src[i] >= 35 && (*(__str__ *)a->str).src[i] <= 38) || ((*(__str__ *)a->str).src[i] >= 40 && (*(__str__ *)a->str).src[i] <= 47) || ((*(__str__ *)a->str).src[i] >= 58 && (*(__str__ *)a->str).src[i] <= 62) || ((*(__str__ *)a->str).src[i] == 64) || ((*(__str__ *)a->str).src[i] == 91) || ((*(__str__ *)a->str).src[i] >= 93 && (*(__str__ *)a->str).src[i] <= 96) || ((*(__str__ *)a->str).src[i] >= 123 && (*(__str__ *)a->str).src[i] <= 126))
            {
                while (((*(__str__ *)a->str).src[i] == 33) || ((*(__str__ *)a->str).src[i] >= 35 && (*(__str__ *)a->str).src[i] <= 38) || ((*(__str__ *)a->str).src[i] >= 40 && (*(__str__ *)a->str).src[i] <= 47) || ((*(__str__ *)a->str).src[i] >= 58 && (*(__str__ *)a->str).src[i] <= 62) || ((*(__str__ *)a->str).src[i] == 64) || ((*(__str__ *)a->str).src[i] == 91) || ((*(__str__ *)a->str).src[i] >= 93 && (*(__str__ *)a->str).src[i] <= 96) || ((*(__str__ *)a->str).src[i] >= 123 && (*(__str__ *)a->str).src[i] <= 126))
                    i++, len++;
            }
            else
                return (parse_t){.src = (char **)NULL, .length = 0, .type = (enum parse_token *)NULL};
        }
        len++;
        parse_t pt;
        pt.src = (char **)calloc(sizeof(char *) * (len), sizeof(char *));
        pt.type = (enum parse_token *)calloc(sizeof(enum parse_token) * (len), sizeof(enum parse_token));
        sstring toks = new_sstring(1, NULL);
        size_t sigma = 0, track = 0;
        for (size_t i = 0; i < (*(__str__ *)a->str).len;)
        {
            if (((*(__str__ *)a->str).src[i] >= 97 && (*(__str__ *)a->str).src[i] <= 122) || ((*(__str__ *)a->str).src[i] >= 65 && (*(__str__ *)a->str).src[i] <= 90))
            {
                _clear(&toks);
                while (((*(__str__ *)a->str).src[i] >= 97 && (*(__str__ *)a->str).src[i] <= 122) || ((*(__str__ *)a->str).src[i] >= 65 && (*(__str__ *)a->str).src[i] <= 90))
                    _append_char(&toks, (*(__str__ *)a->str).src[i++]);
                pt.src[sigma] = (char *)calloc(sizeof(char) * (_end_sstring(&toks) + 1), sizeof(char));
                track = 0;
                fast_strncat(pt.src[sigma], _c_str(&toks), &track);
                pt.type[sigma++] = WORD;
            }
            else if ((*(__str__ *)a->str).src[i] == 32)
            {
                _clear(&toks);
                _append_char(&toks, (*(__str__ *)a->str).src[i++]);
                pt.src[sigma] = (char *)calloc(sizeof(char) * (_end_sstring(&toks) + 1), sizeof(char));
                track = 0;
                fast_strncat(pt.src[sigma], _c_str(&toks), &track);
                pt.type[sigma++] = WHITESPACE;
            }
            else if (isdigit((*(__str__ *)a->str).src[i]))
            {
                _clear(&toks);
                while (isdigit((*(__str__ *)a->str).src[i]))
                    _append_char(&toks, (*(__str__ *)a->str).src[i++]);
                pt.src[sigma] = (char *)calloc(sizeof(char) * (_end_sstring(&toks) + 1), sizeof(char));
                track = 0;
                fast_strncat(pt.src[sigma], _c_str(&toks), &track);
                pt.type[sigma++] = INTEGER;
            }
            else if ((*(__str__ *)a->str).src[i] == '\\' || (*(__str__ *)a->str).src[i] == '\a' || (*(__str__ *)a->str).src[i] == '\b' || (*(__str__ *)a->str).src[i] == '\f' || (*(__str__ *)a->str).src[i] == '\n' || (*(__str__ *)a->str).src[i] == '\r' || (*(__str__ *)a->str).src[i] == '\t' || (*(__str__ *)a->str).src[i] == '\v' || (*(__str__ *)a->str).src[i] == '\"' || (*(__str__ *)a->str).src[i] == '\'' || (*(__str__ *)a->str).src[i] == '\?')
            {
                _clear(&toks);
                while ((*(__str__ *)a->str).src[i] == '\\' || (*(__str__ *)a->str).src[i] == '\a' || (*(__str__ *)a->str).src[i] == '\b' || (*(__str__ *)a->str).src[i] == '\f' || (*(__str__ *)a->str).src[i] == '\n' || (*(__str__ *)a->str).src[i] == '\r' || (*(__str__ *)a->str).src[i] == '\t' || (*(__str__ *)a->str).src[i] == '\v' || (*(__str__ *)a->str).src[i] == '\"' || (*(__str__ *)a->str).src[i] == '\'' || (*(__str__ *)a->str).src[i] == '\?')
                {
                    _clear(&toks);
                    _set(&toks, char_to_esc_seq((*(__str__ *)a->str).src[i++]));
                    pt.src[sigma] = (char *)calloc(sizeof(char) * (_end_sstring(&toks) + 1), sizeof(char));
                    track = 0;
                    fast_strncat(pt.src[sigma], _c_str(&toks), &track);
                    pt.type[sigma++] = ESC_SEQ;
                }
            }
            else if (((*(__str__ *)a->str).src[i] == 33) || ((*(__str__ *)a->str).src[i] >= 35 && (*(__str__ *)a->str).src[i] <= 38) || ((*(__str__ *)a->str).src[i] >= 40 && (*(__str__ *)a->str).src[i] <= 47) || ((*(__str__ *)a->str).src[i] >= 58 && (*(__str__ *)a->str).src[i] <= 62) || ((*(__str__ *)a->str).src[i] == 64) || ((*(__str__ *)a->str).src[i] == 91) || ((*(__str__ *)a->str).src[i] >= 93 && (*(__str__ *)a->str).src[i] <= 96) || ((*(__str__ *)a->str).src[i] >= 123 && (*(__str__ *)a->str).src[i] <= 126))
            {
                _clear(&toks);
                while (((*(__str__ *)a->str).src[i] == 33) || ((*(__str__ *)a->str).src[i] >= 35 && (*(__str__ *)a->str).src[i] <= 38) || ((*(__str__ *)a->str).src[i] >= 40 && (*(__str__ *)a->str).src[i] <= 47) || ((*(__str__ *)a->str).src[i] >= 58 && (*(__str__ *)a->str).src[i] <= 62) || ((*(__str__ *)a->str).src[i] == 64) || ((*(__str__ *)a->str).src[i] == 91) || ((*(__str__ *)a->str).src[i] >= 93 && (*(__str__ *)a->str).src[i] <= 96) || ((*(__str__ *)a->str).src[i] >= 123 && (*(__str__ *)a->str).src[i] <= 126))
                {
                    _clear(&toks);
                    _set_char(&toks, (*(__str__ *)a->str).src[i++]);
                    pt.src[sigma] = (char *)calloc(sizeof(char) * (_end_sstring(&toks) + 1), sizeof(char));
                    track = 0;
                    fast_strncat(pt.src[sigma], _c_str(&toks), &track);
                    pt.type[sigma++] = SPECIAL_CHAR;
                }
            }
            else
                return (parse_t){.src = (char **)NULL, .length = 0, .type = (enum parse_token *)NULL};
        }
        // append \0 as the end of file or string
        pt.src[sigma] = (char *)calloc(sizeof(char) * 4, sizeof(char));
        track = 0;
        fast_strncat(pt.src[sigma], char_to_esc_seq('\0'), &track);
        pt.type[sigma++] = NULL_END;
        _destructor(&toks);
        pt.length = sigma;
        return pt;
    }
    return (parse_t){.src = (char **)NULL, .length = 0, .type = (enum parse_token *)NULL};
}

int _from_parse_t(sstring *a, parse_t *toks)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && toks && toks->src && toks->type && toks->length > 0)
    {
        size_t len = 0;
        for (size_t i = 0; i < toks->length; i++)
            len += strlen((const char *)toks->src[i]);
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        len = 0;
        for (size_t i = 0; i < toks->length; i++)
            fast_strncat((*(__str__ *)a->str).src, esc_seq_to_char_ptr((const char *)toks->src[i]), &len);
        (*(__str__ *)a->str).len = len;
        return true;
    }
    return false;
}

int _set_formatted(sstring *a, size_t buffer_length, const char *__format__, ...)
{
    if (__format__ == NULL)
        return false;
    size_t buff_l = strlen(__format__);
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && buffer_length >= buff_l)
    {
        char *buff = (char *)calloc(sizeof(char) * (buffer_length + 1), sizeof(char));
        va_list ar;
        va_start(ar, __format__);
        vsnprintf(buff, buffer_length, __format__, ar);
        va_end(ar);
        free((*(__str__ *)a->str).src);
        (*(__str__ *)a->str).src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
        size_t len = 0;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &len);
        (*(__str__ *)a->str).len = len;
        free(buff);
        return true;
    }
    return false;
}

int _append_formatted(sstring *a, size_t buffer_length, const char *__format__, ...)
{
    if (__format__ == NULL)
        return false;
    size_t buff_l = strlen(__format__);
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && buffer_length >= buff_l)
    {
        char *buff = (char *)calloc(sizeof(char) * (buffer_length + 1), sizeof(char));
        va_list ar;
        va_start(ar, __format__);
        vsnprintf(buff, buffer_length, __format__, ar);
        va_end(ar);
        (*(__str__ *)a->str).src = (char *)realloc((*(__str__ *)a->str).src, sizeof(char) * (strlen((const char *)buff) + (*(__str__ *)a->str).len + 1));
        size_t len = (*(__str__ *)a->str).len;
        fast_strncat((*(__str__ *)a->str).src, (const char *)buff, &len);
        (*(__str__ *)a->str).len = len;
        free(buff);
        return true;
    }
    return false;
}

int _resize(sstring *a, size_t new_len)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && new_len > 0)
    {
        (*(__str__ *)a->str).src = (char *)realloc((*(__str__ *)a->str).src, new_len);
        return true;
    }
    return false;
}

size_t _hash(sstring *a)
{
    if (a && a->str && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true && (*(__str__ *)a->str).len != 0)
    {
        size_t p = 53;
        size_t m = 1e9 + 9;
        long long power_of_p = 1;
        long long hash_val = 0;

        for (size_t i = 0; i < (*(__str__ *)a->str).len; i++)
        {
            hash_val = (hash_val + ((*(__str__ *)a->str).src[i] - 97 + 1) * power_of_p) % m;
            power_of_p = (power_of_p * p) % m;
        }
        return (hash_val % m + m) % m;
    }
    return (size_t)-1;
}

/**
 * Frees `a` carefully. Always use this function when there is not use of `a` or before your program exits.
 * @param a pointer to struct split_t
 * @returns true if freed, otherwise false
 */
int free_split(split_t *a)
{
    if (a)
    {
        for (size_t i = 0; i < a->len; i++)
            if (a->data[i] != NULL)
                free(a->data[i]);
        free(a->data);
        a->len = 0;
        return true;
    }
    return false;
}

/**
 * Frees `a` carefully. Always use this function when there is not use of `a` or before your program exits.
 * @param a pointer to struct parse_t
 * @returns true if freed, otherwise false
 */
int free_parse(parse_t *a)
{
    if (a)
    {
        for (size_t i = 0; i < a->length; i++)
            if (a->src[i] != NULL)
                free(a->src[i]);
        free(a->src);
        free(a->type);
        a->length = 0;
        return true;
    }
    return false;
}

/**
 * Shortcut for initializing a `sstring` struct.
 * @param alloc_size amount of memory block to allocate `a`.
 * @param src data to assign by default, if `src` is NULL then nothing is assigned
 * @returns an initialized `sstring`
 */
sstring new_sstring(size_t alloc_size, const char *src)
{
    sstring x;
    init_sstr(&x, alloc_size);
    if (src)
        x.set(&x, src);
    return x;
}

/**
 * Shortcut for initializing a `sstring` struct.
 * @param x sstring name or variable name
 */
#define SSTRING(x) \
    sstring x;     \
    init_sstr(&x, 1);

/**
 * Always use this function after any `sstring` declaration.
 * This function initializes `a`.
 * By the way use `SSTRING(x)` macro for shortcut.
 * @param a pointer to struct sstring
 * @param alloc_size amount of memory block to allocate `a`.
 */
int init_sstr(sstring *a, size_t alloc_size)
{
    if (a)
    {
        a->set = _set;
        a->set_char = _set_char;
        a->set_upto = _set_upto;
        a->set_random = _set_random;
        a->set_array = _set_array;
        a->get = _get;
        a->append = _append;
        a->append_char = _append_char;
        a->append_upto = _append_upto;
        a->append_start = _append_start;
        a->append_start_char = _append_start_char;
        a->append_start_upto = _append_start_upto;
        a->append_array = _append_array;
        a->append_start_array = _append_start_array;
        a->empty = _empty;
        a->replace_char = _replace_char;
        a->char_set = _char_set;
        a->char_get = _char_get;
        a->length = _length;
        a->compare = _compare;
        a->compare_upto = _compare_upto;
        a->print = _print;
        a->replace = _replace;
        a->destructor = _destructor;
        a->c_str = _c_str;
        a->save = _save;
        a->append_file = _append_file;
        a->open = _open;
        a->clear = _clear;
        a->to_upper = _to_upper;
        a->to_lower = _to_lower;
        a->swap_case = _swap_case;
        a->is_initialized = _is_initialized;
        a->to_binary = _to_binary;
        a->from_binary = _from_binary;
        a->entropy = _entropy;
        a->contains = _contains;
        a->contains_char = _contains_char;
        a->to_set = _to_set;
        a->copy = _copy;
        a->to_hexadecimal = _to_hexadecimal;
        a->from_hexadecimal = _from_hexadecimal;
        a->find = _find;
        a->in = _in;
        a->getline = _getline;
        a->reverse = _reverse;
        a->remove = _remove;
        a->remove_char = _remove_char;
        a->remove_extra_char = _remove_extra_char;
        a->remove_range = _remove_range;
        a->intersect = _intersect;
        a->distance = _distance;
        a->edit_distance = _edit_distance;
        a->percentage_matched = _percentage_matched;
        a->count = _count;
        a->count_char = _count_char;
        a->soundex = _soundex;
        a->most_used = _most_used;
        a->most_used_char = _most_used_char;
        a->split = _split;
        a->sort = _sort;
        a->open_binary = _open_binary;
        a->save_binary = _save_binary;
        a->append_binary = _append_binary;
        a->add_binary = _add_binary;
        a->print_binary = _print_binary;
        a->encrypt = _encrypt;
        a->decrypt = _decrypt;
        a->begin = _begin;
        a->iterator = _iterator;
        a->reverse_iterator = __reverse_iterator;
        a->end = _end_sstring;
        a->to_morse_code = _to_morse_code;
        a->from_morse_code = _from_morse_code;
        a->is_digit = _is_digit;
        a->is_decimal = _is_decimal;
        a->is_ascii = _is_ascii;
        a->is_alphabetic = _is_alphabetic;
        a->format_escape_sequence = _format_escape_sequence;
        a->insert = _insert;
        a->starts_with = _starts_with;
        a->ends_with = _ends_with;
        a->parse = _parse;
        a->from_parse_t = _from_parse_t;
        a->set_formatted = _set_formatted;
        a->append_formatted = _append_formatted;
        a->resize = _resize;
        a->hash = _hash;
        a->nerr = (size_t)-1;

        a->str = (__str__ *)calloc(sizeof(__str__), sizeof(__str__));
        (*(__str__ *)a->str).src = (char *)calloc((alloc_size * sizeof(char)) + sizeof(char), sizeof(char));
        (*(__str__ *)a->str).len = 0ULL;
        (*(__str__ *)a->str).init = true; // initialized properly
        return true;
    }
    return false;
}

#endif