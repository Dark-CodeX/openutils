/**
 * This header file is written to manage string data safely under C programming language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/sstring.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "sstring.h" under "sstring" directory
 * sstring: version 1.6.9
 * MIT License
 *
 * Copyright (c) 2022 Tushar Chaurasia
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

#ifndef __cplusplus

#pragma once

typedef struct __string__ sstring;

#define sstring_version "1.6.9"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

/**
 * This struct is made to store single-pointer char and its initialized value.
 * Do not use this directly, instead use `sstring` struct.
 */
typedef struct __str__
{
	/* Do not modify it directly (segfault), most probably and use 'str.destructor(&str);' at the end */
	char *src;
	/* Do not change this value. */
	bool init;
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
	bool is_max_smaller;
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
	bool (*c_loop)(iter_sstring *is);
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
	__str__ str;

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
	bool (*empty)(sstring *a);

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
	 * Returns the index of `ch` from the ending of `a`.
	 * @param a pointer to struct sstring
	 * @param ch character to find
	 * @returns the index of `ch` if found, otherwise `nerr`
	 */
	size_t (*last_index_of)(sstring *a, char ch);

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
	bool (*compare)(sstring *a, const char *T1);

	/**
	 * Compares `a` against `T1` upto `N`.
	 * @param a pointer to struct sstring
	 * @param T1 string to compare with
	 * @param N compare upto a number
	 * @returns return true if true, otherwise return false
	 */
	bool (*compare_upto)(sstring *a, const char *T1, size_t N);

	/**
	 * A lexicographical comparison is the kind of comparison generally used to sort strings alphabetically.
	 * @param a pointer to struct sstring
	 * @param str string to compare with
	 * @return difference between ASCII characters or if starting of both the strings are same then it returns the difference between the length, otherwise 0 is returned if strings are equal
	 */
	int (*lexicographical_comparison)(sstring *a, const char *str);

	/**
	 * Prints `a`.
	 * @param a pointer to struct sstring
	 * @param add_next_line set 0 if append next line, otherwise set 1
	 * @param __format__ arguments for ...
	 */
	void (*print)(sstring *a, bool add_next_line, const char *__format__, ...);

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
	bool (*destructor)(sstring *a);

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
	bool (*save)(sstring *a, const char *location);

	/**
	 * Appends `a` at `location`.
	 * @param a pointer to struct sstring
	 * @param location where to append
	 * @returns true if appended successfully, otherwise return false
	 */
	bool (*append_file)(sstring *a, const char *location);

	/**
	 * Opens file at `location` and then sets `a` the contents of the file.
	 * @param a pointer to struct sstring
	 * @param location file to open
	 * @returns true if opened successfully, otherwise return false
	 */
	bool (*open)(sstring *a, const char *location);

	/**
	 * Clears `a` using `calloc` function defined in <stdlib.h> header.
	 * @param a pointer to struct sstring
	 * @returns true if cleared successfully, otherwise return false
	 */
	bool (*clear)(sstring *a);

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
	bool (*is_initialized)(sstring *a);

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
	bool (*from_binary)(sstring *a);

	/**
	 * Calculates the entropy using `Shannon's entropy` formula, which was introduced in his 1948 paper "A Mathematical Theory of Communication". For more information https://en.wikipedia.org/wiki/Entropy_(information_theory)
	 * @param a pointer to struct sstring
	 * @returns entropy of `a`.
	 */
	double (*entropy)(sstring *a);

	/**
	 * Returns true if contains `str`, otherwise returns false.
	 * @param a pointer to struct sstring
	 * @param str string to be tested
	 * @returns true if contains, otherwise return false
	 */
	bool (*contains)(sstring *a, const char *str);

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
	bool (*copy)(sstring *a, sstring *dest);

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
	bool (*from_hexadecimal)(sstring *a);

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
	 */
	void (*in)(sstring *a);

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
	bool (*intersect)(sstring *a, size_t from, size_t till);

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
	double (*percentage_matched)(sstring *a, const char *src);

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
	bool (*save_binary)(sstring *a, const char *location, size_t len);

	/**
	 * Appends the content of `a` to the file at `location`.
	 * @param a pointer to struct sstring
	 * @param location file to be appended
	 * @param len length of the data (returned value of `open_binary` function)
	 * @returns true if appended, otherwise false
	 */
	bool (*append_binary)(sstring *a, const char *location, size_t len);

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
	bool (*print_binary)(sstring *a, size_t len);

	/**
	 * Encrypts `a` using positional modulus for `key`.
	 * @param a pointer to struct sstring
	 * @returns true if encrypted, otherwise false
	 */
	bool (*encrypt)(sstring *a, const char *key);

	/**
	 * Decrypts `a` using positional modulus for `key`.
	 * @param a pointer to struct sstring
	 * @returns true if decrypted, otherwise false
	 */
	bool (*decrypt)(sstring *a, const char *key);

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
	bool (*to_morse_code)(sstring *a);

	/**
	 * Converts morse code to simple readable `sstring`.
	 * @param a pointer to struct sstring
	 * @returns true if converted, otherwise false
	 */
	bool (*from_morse_code)(sstring *a);

	/**
	 * Checks whether all characters of `a` is digit or not.
	 * @param a pointer to struct sstring
	 * @returns true if all character were digit, otherwise false
	 */
	bool (*is_digit)(sstring *a);

	/**
	 * Checks whether `a` is decimal or not.
	 * @param a pointer to struct sstring
	 * @returns true if all character were decimal, otherwise false
	 */
	bool (*is_decimal)(sstring *a);

	/**
	 * Checks whether all characters of `a` is ascii or not.
	 * @param a pointer to struct sstring
	 * @returns true if all character were ascii, otherwise false
	 */
	bool (*is_ascii)(sstring *a);

	/**
	 * Checks whether all characters of `a` is alphabetic or not.
	 * @param a pointer to struct sstring
	 * @returns true if all character were alphabetic, otherwise false
	 */
	bool (*is_alphabetic)(sstring *a);

	/**
	 * Formats `a` according to escape sequences.
	 * @param a pointer to struct sstring
	 * @returns true if all formatted, otherwise false
	 */
	bool (*format_escape_sequence)(sstring *a);

	/**
	 * Inserts `src` into `a` at `index`.
	 * @param a pointer to struct sstring
	 * @param src string to insert
	 * @param index where to insert `src`
	 * @returns true if inserted `src` into `a`, otherwise false
	 */
	bool (*insert)(sstring *a, const char *src, size_t index);

	/**
	 * Checks whether `a` starts with `src`.
	 * @param a pointer to struct sstring
	 * @param src string to check
	 * @returns true if starts with `src`, otherwise false
	 */
	bool (*starts_with)(sstring *a, const char *src);

	/**
	 * Checks whether `a` ends with `src`.
	 * @param a pointer to struct sstring
	 * @param src string to check
	 * @returns true if ends with `src`, otherwise false
	 */
	bool (*ends_with)(sstring *a, const char *src);

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
	bool (*from_parse_t)(sstring *a, parse_t *toks);

	/**
	 * Assigns `__format__` to `a` with formatting.
	 * @param a pointer to struct sstring
	 * @param buffer_length length of `__format__` along with variable length `...`
	 * @param __format__ string containing the format instructions
	 * @param ... variables
	 * @returns true if task completed, otherwise false
	 */
	bool (*set_formatted)(sstring *a, size_t buffer_length, const char *__format__, ...);

	/**
	 * Appends `__format__` to `a` with formatting.
	 * @param a pointer to struct sstring
	 * @param buffer_length length of `__format__` along with variable length `...`
	 * @param __format__ string containing the formatting instructions
	 * @param ... variables
	 * @returns true if task completed, otherwise false
	 */
	bool (*append_formatted)(sstring *a, size_t buffer_length, const char *__format__, ...);

	/**
	 * Resizes `a` with new size `new_len`.
	 * @param a pointer to struct sstring
	 * @param new_len new length of `a`
	 * @returns true if resized, otherwise false
	 */
	bool (*resize)(sstring *a, size_t new_len);

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
	if (dest && src && size)
		while ((dest[*size] = *src++))
			*size += 1;
}

void _sstring_set(sstring *a, const char *src)
{
	if (a && src && a->str.init == true && a->str.src)
	{
		free(a->str.src);
		size_t len = strlen(src);
		a->str.src = calloc(len + 1, sizeof(char));
		strcpy(a->str.src, src);
		a->str.len = len;
	}
}

void _sstring_set_char(sstring *a, const char c)
{
	if (a && c != '\0' && a->str.init == true && a->str.src)
	{
		free(a->str.src);
		a->str.src = calloc(2, sizeof(char));
		strncpy(a->str.src, &c, 1);
		a->str.len = 1;
	}
}

void _sstring_set_upto(sstring *a, const char *src, size_t N)
{
	size_t l = 0;
	if (a && src && a->str.init == true && a->str.src && N <= (l = strlen(src)))
	{
		free(a->str.src);
		a->str.src = calloc(N + 1, sizeof(char));
		strncpy(a->str.src, src, N);
		a->str.len = N;
	}
}

void _sstring_set_random(sstring *a, const size_t len)
{
	if (a && a->str.init == true && a->str.src && len > 0)
	{
		char *buff = calloc(len + 1, sizeof(char));
		// random ascii character betweem 32 and 126, inclusive
		for (size_t i = 0; i < len; i++)
			buff[i] = (rand() % (126 - 32 + 1)) + 32;
		free(a->str.src);
		a->str.src = calloc(len + 1, sizeof(char));
		strcpy(a->str.src, (const char *)buff);
		free(buff);
		a->str.len = len;
	}
}

void _sstring_set_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len)
{
	if (a && src && a->str.init == true && a->str.src)
	{
		bool valid = true;
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
			char *buff = calloc(cnt_t + 1, sizeof(char)), bw[3] = "\0\0";
			size_t track = 0;
			for (size_t i = from; i < till; i++)
			{
				fast_strncat(buff, src[i], &track);
				if (i < till - 1 && (bw[0] = char_between) != '\0')
					fast_strncat(buff, (const char *)bw, &track);
			}
			free(a->str.src);
			a->str.src = calloc(track + 1, sizeof(char));
			strcpy(a->str.src, (const char *)buff);
			a->str.len = track;
			free(buff);
		}
	}
}

char *_sstring_get(sstring *a)
{
	if (a && a->str.init == true && a->str.src)
		return a->str.src;
	return (char *)NULL;
}

void _sstring_append(sstring *a, const char *src)
{
	if (a && src && a->str.init == true && a->str.src)
	{
		size_t len = 0, l = strlen(src);
		if ((len = a->str.len) == 0) // string is empty
		{
			free(a->str.src); // used calloc in `init_str` function
			a->str.src = calloc(l + 1, sizeof(char));
			strcpy(a->str.src, src); // copy `src` to `a`.
			a->str.len = l;
		}
		else
		{
			a->str.src = realloc(a->str.src, sizeof(char) * (l + len + 1));
			fast_strncat(a->str.src, src, &len);
			a->str.len = len;
		}
	}
}

void _sstring_append_char(sstring *a, const char c)
{
	if (a && c != '\0' && a->str.init == true && a->str.src)
	{
		size_t len = 0;
		if ((len = a->str.len) == 0) // string is empty
		{
			free(a->str.src); // used calloc in `init_str` function
			a->str.src = calloc(2, sizeof(char));
			strncpy(a->str.src, &c, 1); // copy `c` to `a`.
			a->str.len = 1;
		}
		else
		{
			a->str.src = realloc(a->str.src, (sizeof(char) * 2) + (len + 1));
			char __dat[3] = "\0\0";
			__dat[0] = c;
			fast_strncat(a->str.src, (const char *)__dat, &len);
			a->str.len = len;
		}
	}
}

void _sstring_append_upto(sstring *a, const char *src, size_t N)
{
	size_t l = 0;
	if (a && src && a->str.init == true && a->str.src && N <= (l = strlen(src)) && N != 0)
	{
		size_t len = 0;
		if ((len = a->str.len) == 0) // string is empty
		{
			free(a->str.src); // used calloc in `init_str` function
			a->str.src = calloc(N + 1, sizeof(char));
			strncpy(a->str.src, src, N); // copy `src` to `a`.
			a->str.len = N;
		}
		else
		{
			a->str.src = realloc(a->str.src, sizeof(char) * (N + len + 1));
			char *buff = calloc(N + 1, sizeof(char));
			strncpy(buff, src, N);
			fast_strncat(a->str.src, (const char *)buff, &len);
			free(buff);
			a->str.len = len;
		}
	}
}

void _sstring_append_start(sstring *a, const char *src)
{
	if (a && src && a->str.init == true && a->str.src)
	{
		size_t len = 0, l = strlen(src);
		if ((len = a->str.len) == 0) // string is empty
		{
			free(a->str.src); // used calloc in `init_str` function
			a->str.src = calloc(l + 1, sizeof(char));
			strcpy(a->str.src, src); // copy `src` to `a`.
			a->str.len = l;
		}
		else
		{
			char *buff = calloc(l + len + 1, sizeof(char));
			size_t track = 0;
			fast_strncat(buff, src, &track);
			fast_strncat(buff, (const char *)a->str.src, &track);
			free(a->str.src);
			a->str.src = calloc(track + 1, sizeof(char));
			track = 0;
			fast_strncat(a->str.src, (const char *)buff, &track);
			free(buff);
			a->str.len = track;
		}
	}
}

void _sstring_append_start_char(sstring *a, const char c)
{
	if (a && c != '\0' && a->str.init == true && a->str.src)
	{
		size_t len = 0;
		if ((len = a->str.len) == 0) // string is empty
		{
			free(a->str.src); // used calloc in `init_str` function
			a->str.src = calloc(2, sizeof(char));
			strncpy(a->str.src, &c, 1); // copy `c` to `a`.
			a->str.len = len + 1;
		}
		else
		{
			char ___c[3] = "\0\0";
			___c[0] = c;
			size_t track = 0;
			char *buff = calloc(2 + len + 1, sizeof(char));
			fast_strncat(buff, (const char *)___c, &track);
			fast_strncat(buff, (const char *)a->str.src, &track);
			free(a->str.src);
			a->str.src = calloc(track + 1, sizeof(char));
			track = 0;
			fast_strncat(a->str.src, (const char *)buff, &track);
			free(buff);
			a->str.len = track;
		}
	}
}

void _sstring_append_start_upto(sstring *a, const char *src, size_t N)
{
	size_t l = 0;
	if (a && src && a->str.init == true && a->str.src && N <= (l = strlen(src)) && N != 0)
	{
		size_t len = 0;
		if ((len = a->str.len) == 0) // string is empty
		{
			free(a->str.src); // used calloc in `init_str` function
			a->str.src = calloc(N + 1, sizeof(char));
			strncpy(a->str.src, src, N); // copy `src` to `a`.
			a->str.len = N;
		}
		else
		{
			char *buff = calloc(len + N + 1, sizeof(char));
			strncpy(buff, src, N);
			size_t track = N;
			fast_strncat(buff, (const char *)a->str.src, &track);
			free(a->str.src);
			a->str.src = calloc(track + 1, sizeof(char));
			track = 0;
			fast_strncat(a->str.src, (const char *)buff, &track);
			free(buff);
			a->str.len = track;
		}
	}
}

void _sstring_append_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len)
{
	if (a && src && a->str.init == true && a->str.src)
	{
		bool valid = true;
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
			size_t slen = a->str.len, track = 0;
			char *buff = calloc(cnt_t + slen + 1, sizeof(char)), bw[3] = "\0\0";
			fast_strncat(buff, (const char *)a->str.src, &track);

			if (slen > 0 && (bw[0] = char_between) != '\0')
				fast_strncat(buff, (const char *)bw, &track);
			for (size_t i = from; i < till; i++)
			{
				fast_strncat(buff, src[i], &track);
				if (i < till - 1 && (bw[0] = char_between) != '\0')
					fast_strncat(buff, (const char *)bw, &track);
			}
			free(a->str.src);
			a->str.src = calloc(track + 1, sizeof(char));
			track = 0;
			fast_strncat(a->str.src, (const char *)buff, &track);
			free(buff);
			a->str.len = track;
		}
	}
}

void _sstring_append_start_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len)
{
	if (a && src && a->str.init == true && a->str.src)
	{
		bool valid = true;
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
			size_t slen = a->str.len, track = 0;
			char *buff = calloc(cnt_t + slen + 1, sizeof(char)), bw[3] = "\0\0";
			for (size_t i = from; i < till; i++)
			{
				fast_strncat(buff, src[i], &track);
				if (i < till - 1 && (bw[0] = char_between) != '\0')
					fast_strncat(buff, (const char *)bw, &track);
			}
			if (cnt_t > 2 && (bw[0] = char_between) != '\0')
				fast_strncat(buff, (const char *)bw, &track);
			fast_strncat(buff, (const char *)a->str.src, &track);
			free(a->str.src);
			a->str.src = calloc(track + 1, sizeof(char));
			track = 0;
			fast_strncat(a->str.src, (const char *)buff, &track);
			free(buff);
			a->str.len = track;
		}
	}
}

bool _sstring_empty(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
		if (a->str.len == 0)
			return true;
	return false;
}

void _sstring_replace_char(sstring *a, const char old, const char new_)
{
	if (a && a->str.src && a->str.init == true)
	{
		for (size_t i = 0; a->str.src[i] != '\0'; ++i)
			if (a->str.src[i] == old)
				a->str.src[i] = new_;
	}
}

void _sstring_char_set(sstring *a, const char what, size_t where)
{
	if (a && a->str.src && a->str.init == true)
	{
		if (a->str.len >= where && what != '\0')
			a->str.src[where] = what;
	}
}

char _sstring_char_get(sstring *a, size_t where)
{
	if (a && a->str.src && a->str.init == true)
	{
		if (a->str.len >= where)
			return a->str.src[where];
	}
	return (char)'\0';
}

size_t _sstring_last_index_of(sstring *a, char ch)
{
	if (a && a->str.src && a->str.init == true && ch != '\0')
	{
		for (size_t i = a->str.len - 1; i != (size_t)-1; i--)
			if (a->str.src[i] == ch)
				return i;
	}
	return (size_t)-1;
}

size_t _sstring_length(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
		return strlen((const char *)a->str.src);
	return (size_t)0;
}

bool _sstring_compare(sstring *a, const char *T1)
{
	if (a && T1 && a->str.init == true && a->str.src)
	{
		if (strcmp((const char *)a->str.src, T1) == 0)
			return true;
	}
	return false;
}

bool _sstring_compare_upto(sstring *a, const char *T1, size_t N)
{
	if (a && T1 && a->str.init == true && a->str.src)
	{
		if (strncmp((const char *)a->str.src, T1, N) == 0)
			return true;
	}
	return false;
}

int _sstring_lexicographical_comparison(sstring *a, const char *str)
{
	if (a && str)
	{
		size_t str_len = 0;
		for (size_t i = 0; a->str.src[i] && str[str_len]; i++, str_len++)
		{
			if (a->str.src[i] == str[i])
				continue;
			return (int)a->str.src[i] - (int)str[i];
		}
		return a->str.len - str_len;
	}
	return 0;
}

void _sstring_print(sstring *a, bool add_next_line, const char *__format__, ...)
{
	if (a && __format__ && a->str.init == true && a->str.src)
	{
		va_list ar;
		va_start(ar, __format__);
		printf("%s", a->str.src);
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

void _sstring_replace(sstring *a, const char *old, const char *new_)
{
	if (a && old && new_ && a->str.init == true && a->str.src)
	{
		size_t i, count_old = 0, len_o = strlen(old), len_n = strlen(new_);
		const char *temp = (const char *)a->str.src;
		for (i = 0; temp[i] != '\0'; ++i)
		{
			if (strstr((const char *)&temp[i], old) == &temp[i])
			{
				count_old++;
				i += len_o - 1;
			}
		}
		char *buff = calloc((i + count_old * (len_n - len_o) + 1), sizeof(char));
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
		free(a->str.src);
		a->str.src = calloc(i + 1, sizeof(char));
		a->str.len = i;
		i = 0;
		fast_strncat(a->str.src, (const char *)buff, &i);
		free(buff);
	}
}

bool _sstring_destructor(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		free(a->str.src);
		a->str.init = false;
		a->str.len = 0;
		return true;
	}
	return false;
}

const char *_sstring_c_str(sstring *a)
{
	if (a && a->str.init == true && a->str.src)
		return (const char *)a->str.src;
	return (const char *)NULL;
}

bool _sstring_save(sstring *a, const char *location)
{
	if (a && a->str.src && location && a->str.init == true)
	{
		FILE *f = fopen(location, "wb");
		if (f != NULL)
		{
			fwrite((const char *)a->str.src, a->str.len, sizeof(char), f);
			fclose(f);
			return true;
		}
	}
	return false;
}

bool _sstring_append_file(sstring *a, const char *location)
{
	if (a && a->str.src && location && a->str.init == true)
	{
		FILE *f = fopen(location, "ab");
		if (f != NULL)
		{
			fwrite((const char *)a->str.src, a->str.len, sizeof(char), f);
			fclose(f);
			return true;
		}
	}
	return false;
}

bool _sstring_open(sstring *a, const char *location)
{
	if (a && location && a->str.init == true)
	{
		FILE *f = fopen(location, "rb");
		if (f != NULL)
		{
			fseek(f, 0, SEEK_END);
			size_t len = ftell(f);
			fseek(f, 0, SEEK_SET);
			free(a->str.src);
			a->str.src = calloc(len + 1, sizeof(char));
			fread(a->str.src, len, sizeof(char), f);
			fclose(f);
			a->str.len = len;
			return true;
		}
	}
	return false;
}

bool _sstring_clear(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		free(a->str.src);
		a->str.src = calloc(1, sizeof(char));
		a->str.len = 0;
		a->str.init = true;
		return true;
	}
	return false;
}

void _sstring_to_upper(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		for (size_t i = 0; a->str.src[i] != '\0'; ++i)
		{
			if (a->str.src[i] <= 122 && a->str.src[i] >= 97)
				a->str.src[i] -= 32;
		}
	}
}

void _sstring_to_lower(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		for (size_t i = 0; a->str.src[i] != '\0'; ++i)
		{
			if (a->str.src[i] <= 90 && a->str.src[i] >= 65)
				a->str.src[i] += 32;
		}
	}
}

void _sstring_swap_case(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		for (size_t i = 0; a->str.src[i] != '\0'; ++i)
		{
			if (a->str.src[i] <= 90 && a->str.src[i] >= 65)
				a->str.src[i] += 32;
			else if (a->str.src[i] <= 122 && a->str.src[i] >= 97)
				a->str.src[i] -= 32;
		}
	}
}

bool _sstring_is_initialized(sstring *a)
{
	if (a)
		if (a->str.init == true)
			return true;
	return false; // never reaches this point by the way, call this function(_is_initialized) directly to get a value i.e, true or false.
}

#include "binary.h"

void _sstring_to_binary(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len, size = 0;
		char *buff = calloc(((2 * (len * 8)) + 1), sizeof(char));
		for (size_t i = 0; i < len; ++i)
		{
			fast_strncat(buff, binary_data[(size_t)a->str.src[i]], &size);
			if (i < len - 1)
				fast_strncat(buff, " ", &size);
		}
		free(a->str.src);
		a->str.src = calloc(size + 1, sizeof(char));
		size = 0;
		fast_strncat(a->str.src, (const char *)buff, &size);
		a->str.len = size;
		free(buff);
	}
}

bool _sstring_from_binary(sstring *a)
{
	bool valid = true;
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len;
		// test 1 for checking binary input format
		for (size_t i = 0; i < len; i++)
		{
			switch (a->str.src[i])
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
				if (a->str.src[i] == ' ')
					cnt++;
			}
			if ((len - cnt) % 8 == 0 && ((len - cnt) / 8) == (cnt + 1))
				valid = true;
			else
				valid = false;
		}
		if (valid == true)
		{
			char *buff = calloc((len / 8) + 1, sizeof(char));
			char bin[9] = "\0", store[2] = "\0";
			char c = '\0';
			size_t z = 0;
			for (size_t i = 0, j = 0; i < len; ++i, ++j)
			{
				if (a->str.src[i] == ' ')
				{
					c = strtol(bin, (char **)NULL, 2);
					store[0] = c;
					fast_strncat(buff, (const char *)store, &z);
					j = 0;
				}
				if (i == len - 1)
				{
					bin[j] = a->str.src[i]; // append last character
					c = strtol(bin, (char **)NULL, 2);
					store[0] = c;
					fast_strncat(buff, store, &z);
				}
				bin[j] = a->str.src[i];
			}
			free(a->str.src);
			a->str.src = calloc(z + 1, sizeof(char));
			z = 0;
			fast_strncat(a->str.src, (const char *)buff, &z);
			a->str.len = z;
			free(buff);
		}
	}
	return valid;
}

double _sstring_entropy(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t frequencies[1 << CHAR_BIT] = {0};
		for (const char *p = a->str.src; *p != 0; p++)
		{
			frequencies[*p - CHAR_MIN] += 1;
		}

		size_t len = a->str.len;
		double result = 0.0;
		for (size_t i = 0; i < (1 << CHAR_BIT); i++)
		{
			if (frequencies[i] != 0)
			{
				double freq = (double)frequencies[i] / (double)len;
				result -= freq * (log(freq) / log(2.0));
			}
		}
		return result;
	}
	return 0.0f;
}

bool _sstring_contains(sstring *a, const char *str)
{
	if (a && a->str.src && a->str.init == true && str)
		if (strstr((const char *)a->str.src, str) != NULL)
			return true;
	return false;
}

size_t _sstring_contains_char(sstring *a, const char c)
{
	if (a && a->str.src && a->str.init == true && c != '\0')
	{
		for (size_t i = 0; a->str.src[i] != '\0'; i++)
			if (a->str.src[i] == c)
				return (size_t)i;
	}
	return (size_t)-1;
}

void _sstring_to_set(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len;
		size_t cnt = 0, map_append = 0, o = 0;
		bool check = false;
		char *set_char = calloc(len + 1, sizeof(char));
		for (cnt = 0; cnt < len; cnt++)
		{
			check = false;
			for (o = 0; set_char[o] != '\0'; o++)
			{
				if (set_char[o] == a->str.src[cnt])
				{
					check = true;
					break;
				}
			}
			if (check == false)
			{
				set_char[map_append] = a->str.src[cnt];
				map_append++;
			}
		}
		free(a->str.src);
		size_t set_len = strlen((const char *)set_char);
		a->str.src = calloc(set_len + 1, sizeof(char));
		strcpy(a->str.src, (const char *)set_char);
		a->str.len = set_len;
		free(set_char);
	}
}

bool _sstring_copy(sstring *a, sstring *dest)
{
	if (a && dest && dest->str.src && dest->str.init == true && a->str.src && a->str.init == true)
	{
		free(dest->str.src);
		dest->str.src = calloc(a->str.len + 1, sizeof(char));
		strcpy(dest->str.src, (const char *)a->str.src);
		dest->str.len = a->str.len;
		return true;
	}
	return false;
}

void _sstring_to_hexadecimal(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		char *buff = calloc((a->str.len * 2) + 1, sizeof(char));
		size_t i = 0, j = 0;
		while (a->str.src[i] != '\0')
		{
			sprintf((char *)buff + j, "%02X", a->str.src[i]);
			i++, j += 2;
		}
		free(a->str.src);
		a->str.src = calloc(j + 1, sizeof(char));
		j = 0;
		fast_strncat(a->str.src, (const char *)buff, &j);
		a->str.len = j;
		free(buff);
	}
}

bool _sstring_from_hexadecimal(sstring *a)
{
	bool valid = true;
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len;
		// test 1 for checking hexadecimal input format
		for (size_t i = 0; i < len; i++)
		{
			switch (a->str.src[i])
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
			char *buff = calloc((len) / 2 + 1, sizeof(char));
			char bin[3] = "\0", store[2] = "\0";
			char c = '\0';
			size_t z = 0;
			for (size_t i = 0, j = 0; i < len; ++i)
			{
				if (i == len - 1)
				{
					bin[j] = a->str.src[i];
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
				bin[j] = a->str.src[i];
				j++;
			}
			free(a->str.src);
			a->str.src = calloc(z + 1, sizeof(char));
			z = 0;
			fast_strncat(a->str.src, (const char *)buff, &z);
			a->str.len = z;
			free(buff);
		}
	}
	return valid;
}

size_t _sstring_find(sstring *a, const char *sub)
{
	if (a && a->str.src && a->str.init == true && sub)
	{
		char *buff;
#ifdef __cplusplus
		buff = (char *)strstr((const char *)a->str.src, sub);
#else
		buff = strstr((const char *)a->str.src, sub);
#endif
		if (buff != NULL)
			return (size_t)a->str.len - strlen((const char *)buff); // buff is subset of a, if buff != NULL
	}
	return (size_t)-1;
}

void _sstring_in(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		char *ptr = calloc(2, sizeof(char)), ch;
		size_t len = 0;
		while ((ch = getchar()))
		{
			if (ch == 10 || ch == 0)
				break;
			ptr[len++] = ch;
			ptr = realloc(ptr, len + 1);
		}
		ptr[len] = 0;
		free(a->str.src);
		a->str.src = calloc(len + 1, sizeof(char));
		fast_strncat(a->str.src, ptr, &a->str.len);
		free(ptr);
	}
}

char *_sstring_getline(sstring *a, size_t line)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len, cnt = 0;
		char *temp = calloc(len + 1, sizeof(char)), *tok;
		strcpy(temp, a->str.src);
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
		char *res = calloc(strlen((const char *)tok) + 1, sizeof(char));
		strcpy(res, (const char *)tok);
		free(temp);
		return res;
	}
	return (char *)NULL;
}

void _sstring_reverse(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len, l = len / 2;
		char c = '\0';
		for (size_t i = 0; i < l; i++)
		{
			c = a->str.src[i];
			a->str.src[i] = a->str.src[len - i - 1];
			a->str.src[len - i - 1] = c;
		}
	}
}

size_t _sstring_remove(sstring *a, const char *sub)
{
	if (a && a->str.src && a->str.init == true && sub && sub[0] != '\0')
	{
		char *buff = calloc(a->str.len + 1, sizeof(char));
		strcpy(buff, (const char *)a->str.src);
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
		free(a->str.src);
		size_t len_buff = strlen((const char *)buff);
		a->str.src = calloc(len_buff + 1, sizeof(char));
		strcpy(a->str.src, (const char *)buff);
		free(buff);
		a->str.len = len_buff;
		return cnt;
	}
	return 0;
}

size_t _sstring_remove_char(sstring *a, const char c)
{
	if (a && a->str.src && a->str.init == true && c != '\0')
	{
		char *buff = calloc(a->str.len + 1, sizeof(char));
		size_t cnt = 0;
		for (size_t i = 0, k = 0; a->str.src[i] != '\0'; i++)
		{
			if (a->str.src[i] != c)
			{
				buff[k] = a->str.src[i];
				k++;
			}
			else
				cnt++;
		}
		free(a->str.src);
		size_t buff_len = strlen((const char *)buff);
		a->str.src = calloc(buff_len + 1, sizeof(char));
		strcpy(a->str.src, (const char *)buff);
		free(buff);
		a->str.len = buff_len;
		return cnt;
	}
	return 0;
}

size_t _sstring_remove_extra_char(sstring *a, const char c)
{
	if (a && a->str.src && a->str.init == true && c != '\0')
	{
		char *buff = calloc(a->str.len + 1, sizeof(char));
		size_t p = 0, i = 0, cnt = 0;
		while (a->str.src[p] != '\0')
		{
			if (!(a->str.src[p] == c && a->str.src[p + 1] == c))
			{
				buff[i] = a->str.src[p];
				i++;
			}
			else
				cnt++;
			p++;
		}
		buff[i] = '\0';
		free(a->str.src);
		size_t buff_len = strlen((const char *)buff);
		a->str.src = calloc(buff_len + 1, sizeof(char));
		strcpy(a->str.src, (const char *)buff);
		free(buff);
		a->str.len = buff_len;
		return cnt;
	}
	return 0;
}

size_t _sstring_remove_range(sstring *a, size_t from, size_t till)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len, cnt = 0;
		if (till > len || from > len || from > till)
			return cnt;
		char *buff = calloc((len - (till - from) + 1), sizeof(char));
		for (size_t i = 0, k = 0; i < len; i++)
		{
			if (i == from)
			{
				i += till - from;
				cnt += (till - from);
			}
			if (i < from || i > from)
			{
				buff[k] = a->str.src[i];
				k++;
			}
		}
		free(a->str.src);
		size_t buff_len = strlen((const char *)buff);
		a->str.src = calloc(buff_len + 1, sizeof(char));
		strcpy(a->str.src, (const char *)buff);
		free(buff);
		a->str.len = buff_len;
		return cnt;
	}
	return 0;
}

bool _sstring_intersect(sstring *a, size_t from, size_t till)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len;
		if (till > len || from > len || from > till)
			return false;
		char *buff = calloc((till - from) + 1, sizeof(char));
		for (size_t i = from, k = 0; i < till; i++)
		{
			buff[k] = a->str.src[i];
			k++;
		}
		free(a->str.src);
		size_t buff_len = strlen((const char *)buff);
		a->str.src = calloc(buff_len + 1, sizeof(char));
		strcpy(a->str.src, (const char *)buff);
		free(buff);
		a->str.len = buff_len;
		return true;
	}
	return false;
}

size_t _sstring_distance(sstring *a, const char *src)
{
	if (a && a->str.src && a->str.init == true && src)
	{
		if (strlen(src) == a->str.len)
		{
			size_t cnt = 0;
			for (size_t i = 0; a->str.src[i] != '\0'; i++)
				if (a->str.src[i] != src[i])
					cnt++;
			return (size_t)cnt;
		}
	}
	return (size_t)-1;
}

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX2(x, y) ((x > y) ? x : y)
size_t _sstring_edit_distance(sstring *a, const char *src)
{
	if (a && a->str.src && a->str.init == true && src)
	{
		size_t len1 = a->str.len, len2 = strlen(src), x, y, last, old;
		size_t cols[len1 + 1];
		for (y = 1; y <= len1; y++)
			cols[y] = y;
		for (x = 1; x <= len2; x++)
		{
			cols[0] = x;
			for (y = 1, last = x - 1; y <= len1; y++)
			{
				old = cols[y];
				cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + (a->str.src[y - 1] == src[x - 1] ? 0 : 1));
				last = old;
			}
		}
		return (size_t)cols[len1];
	}
	return (size_t)-1;
}

double _sstring_percentage_matched(sstring *a, const char *src)
{
	if (a && a->str.src && a->str.init == true && src)
	{
		size_t len1 = a->str.len, len2 = strlen(src), x, y, last, old;
		size_t cols[len1 + 1];
		for (y = 1; y <= len1; y++)
			cols[y] = y;
		for (x = 1; x <= len2; x++)
		{
			cols[0] = x;
			for (y = 1, last = x - 1; y <= len1; y++)
			{
				old = cols[y];
				cols[y] = MIN3(cols[y] + 1, cols[y - 1] + 1, last + (a->str.src[y - 1] == src[x - 1] ? 0 : 1));
				last = old;
			}
		}
		size_t max = MAX2(len1, len2);
		return (max - cols[len1]) * 100.0 / max;
	}
	return 0.0;
}

size_t _sstring_count(sstring *a, const char *what)
{
	if (a && a->str.src && a->str.init == true && what)
	{
		size_t cnt = 0, len = strlen(what);
		const char *sub = (const char *)a->str.src;
		while ((sub = strstr(sub, what)))
		{
			cnt++;
			sub += len;
		}
		return cnt;
	}
	return 0;
}

size_t _sstring_count_char(sstring *a, const char what)
{
	if (a && a->str.src && a->str.init == true && what != '\0')
	{
		size_t cnt = 0;
		for (size_t i = 0; a->str.src[i] != '\0'; i++)
			if (a->str.src[i] == what)
				cnt++;
		return cnt;
	}
	return 0;
}

char *_sstring_soundex(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t s = 1, len = a->str.len;
		const char *map = "01230120022455012623010202"; // not stored in heap memory, do not free it
		char c, *res = calloc(5, sizeof(char));
		res[0] = toupper(a->str.src[0]);
		for (size_t i = 1; i < len; ++i)
		{
			c = toupper(a->str.src[i]) - 65;
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

char *_sstring_most_used(sstring *a, const char *dl)
{
	if (a && a->str.src && a->str.init == true && dl)
	{
		size_t len = a->str.len, cnt = 0, l = 0;
		cnt = a->count(a, dl);
		if (cnt == 0)
			return (char *)NULL;
		char *temp = calloc(len + 1, sizeof(char));
		strcpy(temp, a->str.src);
		char **buff = calloc(cnt + 1, sizeof(char *)), *tok = strtok(temp, dl);
		while (tok != NULL)
		{
			buff[l] = tok;
			tok = strtok(NULL, dl);
			l++;
		}
		qsort(buff, l, sizeof(char *), strcmp_void);
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
		char *x = calloc(strlen((const char *)res) + 1, sizeof(char));
		strcpy(x, res);
		free(temp);
		free(buff);
		return x;
	}
	return (char *)NULL;
}

char _sstring_most_used_char(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = a->str.len;
		size_t cnt = 0, map_append = 0, o = 0;
		bool check = false;
		char *map_char = calloc(len + 1, sizeof(char));
		size_t *map_cnt = calloc(len + 1, sizeof(size_t));
		for (cnt = 0; cnt < len; cnt++)
		{
			check = false;
			for (o = 0; map_char[o] != '\0'; o++)
			{
				if (map_char[o] == a->str.src[cnt])
				{
					check = true;
					break;
				}
			}
			if (check == false)
			{
				map_char[map_append] = a->str.src[cnt];
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

split_t _sstring_split(sstring *a, const char *dl)
{
	if (a && a->str.src && a->str.init == true && dl && dl[0] != '\0')
	{
		split_t x;
		x.data = (char **)NULL;
		x.len = 0;
		size_t len = a->str.len, cnt = 0;
		char *temp = calloc(len + 1, sizeof(char)), *tok;
		strcpy(temp, a->str.src);
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
		temp = calloc(len + 1, sizeof(char));
		strcpy(temp, a->str.src);
		x.data = calloc(cnt + 1, sizeof(char *));
		tok = strtok(temp, dl);
		while (tok)
		{
			x.data[x.len] = calloc(strlen((const char *)tok) + 1, sizeof(char));
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

void _sstring_sort(sstring *a)
{
	if (a && a->str.src && a->str.init == true && a->str.src[0] != '\0')
		qsort(a->str.src, a->str.len, sizeof(char), compare_chars);
}

size_t _sstring_open_binary(sstring *a, const char *location)
{
	if (a && a->str.src && a->str.init == true && location)
	{
		FILE *f = fopen(location, "rb");
		if (f != NULL)
		{
			fseek(f, 0, SEEK_END);
			size_t len = ftell(f);
			fseek(f, 0, SEEK_SET);
			unsigned char *_temp_ = calloc(len + 1, sizeof(unsigned char));
			free(a->str.src);
			a->str.src = calloc(len + 1, sizeof(char));
			fread(_temp_, len, sizeof(unsigned char), f);
			memcpy(a->str.src, (const void *)_temp_, len);
			fclose(f);
			free(_temp_);
			return len;
		}
	}
	return 0;
}

bool _sstring_save_binary(sstring *a, const char *location, size_t len)
{
	if (a && a->str.src && a->str.init == true && location)
	{
		unsigned char *_temp_ = calloc(len + 1, sizeof(unsigned char));
		memcpy(_temp_, (const void *)a->str.src, len);
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

bool _sstring_append_binary(sstring *a, const char *location, size_t len)
{
	if (a && a->str.src && a->str.init == true && location)
	{
		unsigned char *_temp_ = calloc(len + 1, sizeof(unsigned char));
		memcpy(_temp_, (const void *)a->str.src, len);
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

size_t _sstring_add_binary(sstring *a, const char *data, size_t len)
{
	if (a && a->str.src && a->str.init == true && data)
	{
		size_t size = len;
		a->str.src = realloc(a->str.src, (sizeof(char) * (len + strlen(data) + 1)));
		fast_strncat(a->str.src, data, &size);
		return size - len; // total data written
	}
	return 0;
}

bool _sstring_print_binary(sstring *a, size_t len)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t x = 0;
		while (x != len)
			printf("%c", a->str.src[x++]);
		return true;
	}
	return false;
}

bool _sstring_encrypt(sstring *a, const char *key)
{
	if (a && a->str.src && a->str.init == true && key)
	{
		sstring __temp__ = new_sstring(0, key);
		size_t val = __temp__.hash(&__temp__) % 128;
		__temp__.destructor(&__temp__);
		size_t len = a->str.len;
		bool add = true;
		char *buff = calloc(len + 1, sizeof(char));
		for (size_t i = 0; a->str.src[i] != '\0'; i++)
		{
			if (add == true && a->str.src[i] + val > '\0')
			{
				buff[i] = a->str.src[i] + val;
				add = false;
			}
			else if (add == false && a->str.src[i] - val > '\0')
			{
				buff[i] = a->str.src[i] - val;
				add = true;
			}
			else
			{
				free(buff);
				return false;
			}
		}
		free(a->str.src);
		a->str.src = calloc(len + 1, sizeof(char));
		len = 0;
		fast_strncat(a->str.src, (const char *)buff, &len);
		a->str.len = len;
		free(buff);
		return true;
	}
	return false;
}

bool _sstring_decrypt(sstring *a, const char *key)
{
	if (a && a->str.src && a->str.init == true && key)
	{
		sstring __temp__ = new_sstring(0, key);
		size_t val = __temp__.hash(&__temp__) % 128;
		__temp__.destructor(&__temp__);
		size_t len = a->str.len;
		bool add_inrv = true;
		char *buff = calloc(len + 1, sizeof(char));
		for (size_t i = 0; a->str.src[i] != '\0'; i++)
		{
			if (add_inrv == true && a->str.src[i] - val > '\0')
			{
				buff[i] = a->str.src[i] - val;
				add_inrv = false;
			}
			else if (add_inrv == false && a->str.src[i] + val > '\0')
			{
				buff[i] = a->str.src[i] + val;
				add_inrv = true;
			}
			else
			{
				free(buff);
				return false;
			}
		}
		free(a->str.src);
		a->str.src = calloc(len + 1, sizeof(char));
		len = 0;
		fast_strncat(a->str.src, (const char *)buff, &len);
		a->str.len = len;
		free(buff);
		return true;
	}
	return false;
}

size_t _sstring_begin(void)
{
	return 0;
}

void __advance__iter_sstring(iter_sstring *is, signed long long int move_by)
{
	if (is)
		is->cur += move_by;
}

bool __c_loop__iter_sstring(iter_sstring *is)
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

iter_sstring _sstring_iterator(sstring *a)
{
	return (iter_sstring){.cur = 0, .max = a->str.len, .is_max_smaller = false, .advance = __advance__iter_sstring, .c_loop = __c_loop__iter_sstring};
}

iter_sstring __sstring_reverse_iterator(sstring *a)
{
	return (iter_sstring){.cur = a->str.len, .max = -1, .is_max_smaller = true, .advance = __advance__iter_sstring, .c_loop = __c_loop__iter_sstring};
}

size_t _sstring_end_sstring(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
		return a->str.len;
	return 0;
}

#include "morse_code.h"
bool _sstring_to_morse_code(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		for (size_t i = 0; i < a->str.len; i++)
			if (!isdigit(a->str.src[i]) && !isalpha(a->str.src[i]) && a->str.src[i] != ' ')
				return false;
		char *buff = calloc(a->str.len * 8 + 1, sizeof(char));
		size_t track = 0;
		for (size_t i = 0; i < a->str.len; i++)
		{
			if (isdigit(a->str.src[i]))
				fast_strncat(buff, morse_code[(size_t)a->str.src[i] - 48].code, &track);
			else if (a->str.src[i] == ' ')
				fast_strncat(buff, morse_code[(size_t)36].code, &track);
			else
			{
				if (a->str.src[i] >= 65 && a->str.src[i] <= 90)
					fast_strncat(buff, morse_code[(size_t)a->str.src[i] - 55].code, &track);
				else
					fast_strncat(buff, morse_code[(size_t)a->str.src[i] - 87].code, &track);
			}
			if (i < a->str.len - 1)
				fast_strncat(buff, " ", &track);
		}
		free(a->str.src);
		a->str.src = calloc(track + 1, sizeof(char));
		track = 0;
		fast_strncat(a->str.src, (const char *)buff, &track);
		free(buff);
		a->str.len = track;
		return true;
	}
	return false;
}

bool _sstring_from_morse_code(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		for (size_t i = 0; i < a->str.len; i++)
		{
			switch (a->str.src[i])
			{
			case '-':
			case '.':
			case ' ':
				break;
			default:
				return false;
			}
		}
		char *buff = calloc(a->str.len + 1, sizeof(char)), *temp = calloc(8, sizeof(char));
		size_t track = 0, x = 0;
		char arr[3] = "\0\0";
		for (size_t i = 0, k = 0; i < a->str.len; i++, k++)
		{
			if (i == a->str.len - 1)
			{
				x = 0;
				temp[k] = a->str.src[i];
				while ((strcmp(temp, morse_code[x].code)) != 0)
					x++;
				arr[0] = morse_code[x].character;
				fast_strncat(buff, (const char *)arr, &track);
			}
			if (a->str.src[i] == ' ')
			{
				i++, x = 0;
				while ((strcmp(temp, morse_code[x].code)) != 0)
					x++;
				arr[0] = morse_code[x].character;
				fast_strncat(buff, (const char *)arr, &track);
				memset(temp, 0, 8);
				k = 0;
			}
			temp[k] = a->str.src[i];
		}
		free(a->str.src);
		a->str.src = calloc(track + 1, sizeof(char));
		track = 0;
		fast_strncat(a->str.src, (const char *)buff, &track);
		free(buff);
		free(temp);
		a->str.len = track;
		return true;
	}
	return false;
}

bool _sstring_is_digit(sstring *a)
{
	if (a && a->str.src && a->str.init == true && a->str.src[0] != '\0')
	{
		for (size_t i = 0; i < a->str.len; i++)
			if (!isdigit((unsigned int)a->str.src[i]))
				return false;
		return true;
	}
	return false;
}

bool _sstring_is_decimal(sstring *a)
{
	if (a && a->str.src && a->str.init == true && a->str.src[0] != '\0')
	{
		size_t point_cnt = 0;
		for (size_t i = 0; i < a->str.len; i++)
		{
			if (a->str.src[i] == 46)
			{
				point_cnt++;
				if (point_cnt > 1)
					return false;
			}
			else if (!isdigit((unsigned int)a->str.src[i]))
				return false;
		}
		if (point_cnt == 1)
			return true;
	}
	return false;
}

bool _sstring_is_ascii(sstring *a)
{
	if (a && a->str.src && a->str.init == true && a->str.src[0] != '\0')
	{
		for (size_t i = 0; i < a->str.len; i++)
			if (a->str.src[i] <= 0 || a->str.src[i] >= 127)
				return false;
		return true;
	}
	return false;
}

bool _sstring_is_alphabetic(sstring *a)
{
	if (a && a->str.src && a->str.init == true && a->str.src[0] != '\0')
	{
		for (size_t i = 0; i < a->str.len; i++)
			if (!isalpha((unsigned int)a->str.src[i]))
				return false;
		return true;
	}
	return false;
}

bool _sstring_format_escape_sequence(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		_sstring_replace(a, "\\", "\\\\");
		_sstring_replace(a, "\a", "\\a");
		_sstring_replace(a, "\b", "\\b");
		_sstring_replace(a, "\f", "\\f");
		_sstring_replace(a, "\n", "\\n");
		_sstring_replace(a, "\r", "\\r");
		_sstring_replace(a, "\t", "\\t");
		_sstring_replace(a, "\v", "\\v");
		_sstring_replace(a, "\"", "\\\"");
		_sstring_replace(a, "\'", "\\\'");
		_sstring_replace(a, "\?", "\\\?");
		return true;
	}
	return false;
}

bool _sstring_insert(sstring *a, const char *src, size_t index)
{
	if (a && a->str.src && src && a->str.init == true && index <= a->str.len)
	{
		size_t len = strlen(src);
		a->str.src = realloc(a->str.src, sizeof(char) * (a->str.len + len + 1));
		for (size_t i = a->str.len; i >= index; i--)
		{
			a->str.src[i + len] = a->str.src[i];
			a->str.src[i] = '\0';
			if (i == 0)
				break;
		}
		memcpy(a->str.src + index, src, len);
		a->str.len += len;
		return true;
	}
	return false;
}

bool _sstring_starts_with(sstring *a, const char *src)
{
	if (a && a->str.src && a->str.init == true && src)
	{
		if (strlen(src) > a->str.len)
			return false;
		for (size_t i = 0; src[i] != '\0' && a->str.src[i] != '\0'; i++)
			if (a->str.src[i] != src[i])
				return false;
		return true;
	}
	return false;
}

bool _sstring_ends_with(sstring *a, const char *src)
{
	if (a && a->str.src && a->str.init == true && src)
	{
		size_t len = strlen(src);
		if (len > a->str.len)
			return false;
		for (size_t i = a->str.len - len, z = 0; src[z] != '\0' && a->str.src[i] != '\0'; i++, z++)
			if (a->str.src[i] != src[z])
				return false;
		return true;
	}
	return false;
}

parse_t _sstring_parse(sstring *a)
{
	if (a && a->str.src && a->str.init == true)
	{
		size_t len = 0;
		for (size_t i = 0; i < a->str.len;)
		{
			if ((a->str.src[i] >= 97 && a->str.src[i] <= 122) || (a->str.src[i] >= 65 && a->str.src[i] <= 90))
			{
				while ((a->str.src[i] >= 97 && a->str.src[i] <= 122) || (a->str.src[i] >= 65 && a->str.src[i] <= 90))
					i++;
				len++;
			}
			else if (a->str.src[i] == 32)
				i++, len++;
			else if (isdigit(a->str.src[i]))
			{
				while (isdigit(a->str.src[i]))
					i++;
				len++;
			}
			else if (a->str.src[i] == '\\' || a->str.src[i] == '\a' || a->str.src[i] == '\b' || a->str.src[i] == '\f' || a->str.src[i] == '\n' || a->str.src[i] == '\r' || a->str.src[i] == '\t' || a->str.src[i] == '\v' || a->str.src[i] == '\"' || a->str.src[i] == '\'' || a->str.src[i] == '\?')
			{
				while (a->str.src[i] == '\\' || a->str.src[i] == '\a' || a->str.src[i] == '\b' || a->str.src[i] == '\f' || a->str.src[i] == '\n' || a->str.src[i] == '\r' || a->str.src[i] == '\t' || a->str.src[i] == '\v' || a->str.src[i] == '\"' || a->str.src[i] == '\'' || a->str.src[i] == '\?')
					i++, len++;
			}
			else if ((a->str.src[i] == 33) || (a->str.src[i] >= 35 && a->str.src[i] <= 38) || (a->str.src[i] >= 40 && a->str.src[i] <= 47) || (a->str.src[i] >= 58 && a->str.src[i] <= 62) || (a->str.src[i] == 64) || (a->str.src[i] == 91) || (a->str.src[i] >= 93 && a->str.src[i] <= 96) || (a->str.src[i] >= 123 && a->str.src[i] <= 126))
			{
				while ((a->str.src[i] == 33) || (a->str.src[i] >= 35 && a->str.src[i] <= 38) || (a->str.src[i] >= 40 && a->str.src[i] <= 47) || (a->str.src[i] >= 58 && a->str.src[i] <= 62) || (a->str.src[i] == 64) || (a->str.src[i] == 91) || (a->str.src[i] >= 93 && a->str.src[i] <= 96) || (a->str.src[i] >= 123 && a->str.src[i] <= 126))
					i++, len++;
			}
			else
				return (parse_t){.src = (char **)NULL, .length = 0, .type = (enum parse_token *)NULL};
		}
		len++;
		parse_t pt;
		pt.src = calloc(len, sizeof(char *));
		pt.type = calloc(len, sizeof(enum parse_token));
		sstring toks = new_sstring(1, NULL);
		size_t sigma = 0, track = 0;
		for (size_t i = 0; i < a->str.len;)
		{
			if ((a->str.src[i] >= 97 && a->str.src[i] <= 122) || (a->str.src[i] >= 65 && a->str.src[i] <= 90))
			{
				_sstring_clear(&toks);
				while ((a->str.src[i] >= 97 && a->str.src[i] <= 122) || (a->str.src[i] >= 65 && a->str.src[i] <= 90))
					_sstring_append_char(&toks, a->str.src[i++]);
				pt.src[sigma] = calloc(_sstring_end_sstring(&toks) + 1, sizeof(char));
				track = 0;
				fast_strncat(pt.src[sigma], _sstring_c_str(&toks), &track);
				pt.type[sigma++] = WORD;
			}
			else if (a->str.src[i] == 32)
			{
				_sstring_clear(&toks);
				_sstring_append_char(&toks, a->str.src[i++]);
				pt.src[sigma] = calloc(_sstring_end_sstring(&toks) + 1, sizeof(char));
				track = 0;
				fast_strncat(pt.src[sigma], _sstring_c_str(&toks), &track);
				pt.type[sigma++] = WHITESPACE;
			}
			else if (isdigit(a->str.src[i]))
			{
				_sstring_clear(&toks);
				while (isdigit(a->str.src[i]))
					_sstring_append_char(&toks, a->str.src[i++]);
				pt.src[sigma] = calloc(_sstring_end_sstring(&toks) + 1, sizeof(char));
				track = 0;
				fast_strncat(pt.src[sigma], _sstring_c_str(&toks), &track);
				pt.type[sigma++] = INTEGER;
			}
			else if (a->str.src[i] == '\\' || a->str.src[i] == '\a' || a->str.src[i] == '\b' || a->str.src[i] == '\f' || a->str.src[i] == '\n' || a->str.src[i] == '\r' || a->str.src[i] == '\t' || a->str.src[i] == '\v' || a->str.src[i] == '\"' || a->str.src[i] == '\'' || a->str.src[i] == '\?')
			{
				_sstring_clear(&toks);
				while (a->str.src[i] == '\\' || a->str.src[i] == '\a' || a->str.src[i] == '\b' || a->str.src[i] == '\f' || a->str.src[i] == '\n' || a->str.src[i] == '\r' || a->str.src[i] == '\t' || a->str.src[i] == '\v' || a->str.src[i] == '\"' || a->str.src[i] == '\'' || a->str.src[i] == '\?')
				{
					_sstring_clear(&toks);
					_sstring_set_char(&toks, a->str.src[i++]);
					pt.src[sigma] = calloc(_sstring_end_sstring(&toks) + 1, sizeof(char));
					track = 0;
					fast_strncat(pt.src[sigma], _sstring_c_str(&toks), &track);
					pt.type[sigma++] = ESC_SEQ;
				}
			}
			else if ((a->str.src[i] == 33) || (a->str.src[i] >= 35 && a->str.src[i] <= 38) || (a->str.src[i] >= 40 && a->str.src[i] <= 47) || (a->str.src[i] >= 58 && a->str.src[i] <= 62) || (a->str.src[i] == 64) || (a->str.src[i] == 91) || (a->str.src[i] >= 93 && a->str.src[i] <= 96) || (a->str.src[i] >= 123 && a->str.src[i] <= 126))
			{
				_sstring_clear(&toks);
				while ((a->str.src[i] == 33) || (a->str.src[i] >= 35 && a->str.src[i] <= 38) || (a->str.src[i] >= 40 && a->str.src[i] <= 47) || (a->str.src[i] >= 58 && a->str.src[i] <= 62) || (a->str.src[i] == 64) || (a->str.src[i] == 91) || (a->str.src[i] >= 93 && a->str.src[i] <= 96) || (a->str.src[i] >= 123 && a->str.src[i] <= 126))
				{
					_sstring_clear(&toks);
					_sstring_set_char(&toks, a->str.src[i++]);
					pt.src[sigma] = calloc(_sstring_end_sstring(&toks) + 1, sizeof(char));
					track = 0;
					fast_strncat(pt.src[sigma], _sstring_c_str(&toks), &track);
					pt.type[sigma++] = SPECIAL_CHAR;
				}
			}
			else
				return (parse_t){.src = (char **)NULL, .length = 0, .type = (enum parse_token *)NULL};
		}
		// append \0 as the end of file or string
		pt.src[sigma] = calloc(1, sizeof(char));
		track = 0;
		fast_strncat(pt.src[sigma], "\0", &track);
		pt.type[sigma++] = NULL_END;
		_sstring_destructor(&toks);
		pt.length = sigma;
		return pt;
	}
	return (parse_t){.src = (char **)NULL, .length = 0, .type = (enum parse_token *)NULL};
}

bool _sstring_from_parse_t(sstring *a, parse_t *toks)
{
	if (a && a->str.src && a->str.init == true && toks && toks->src && toks->type && toks->length > 0)
	{
		size_t len = 0;
		for (size_t i = 0; i < toks->length; i++)
			len += strlen((const char *)toks->src[i]);
		free(a->str.src);
		a->str.src = calloc(len + 1, sizeof(char));
		len = 0;
		for (size_t i = 0; i < toks->length; i++)
			fast_strncat(a->str.src, (const char *)toks->src[i], &len);
		a->str.len = len;
		return true;
	}
	return false;
}

bool _sstring_set_formatted(sstring *a, size_t buffer_length, const char *__format__, ...)
{
	if (__format__ == NULL)
		return false;
	size_t buff_l = strlen(__format__);
	if (a && a->str.src && a->str.init == true && buffer_length >= buff_l)
	{
		char *buff = calloc(buffer_length + 1, sizeof(char));
		va_list ar;
		va_start(ar, __format__);
		vsnprintf(buff, buffer_length, __format__, ar);
		va_end(ar);
		free(a->str.src);
		a->str.src = calloc(strlen((const char *)buff) + 1, sizeof(char));
		size_t len = 0;
		fast_strncat(a->str.src, (const char *)buff, &len);
		a->str.len = len;
		free(buff);
		return true;
	}
	return false;
}

bool _sstring_append_formatted(sstring *a, size_t buffer_length, const char *__format__, ...)
{
	if (__format__ == NULL)
		return false;
	size_t buff_l = strlen(__format__);
	if (a && a->str.src && a->str.init == true && buffer_length >= buff_l)
	{
		char *buff = calloc(buffer_length + 1, sizeof(char));
		va_list ar;
		va_start(ar, __format__);
		vsnprintf(buff, buffer_length, __format__, ar);
		va_end(ar);
		a->str.src = realloc(a->str.src, sizeof(char) * (strlen((const char *)buff) + a->str.len + 1));
		size_t len = a->str.len;
		fast_strncat(a->str.src, (const char *)buff, &len);
		a->str.len = len;
		free(buff);
		return true;
	}
	return false;
}

bool _sstring_resize(sstring *a, size_t new_len)
{
	if (a && a->str.src && a->str.init == true && new_len > 0)
	{
		a->str.src = realloc(a->str.src, new_len);
		return true;
	}
	return false;
}

size_t _sstring_hash(sstring *a)
{
	if (a && a->str.src && a->str.init == true && a->str.len != 0)
	{
		size_t p = 53;
		size_t m = 1e9 + 9;
		long long power_of_p = 1;
		long long hash_val = 0;

		for (size_t i = 0; i < a->str.len; i++)
		{
			hash_val = (hash_val + (a->str.src[i] - 97 + 1) * power_of_p) % m;
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
bool free_split(split_t *a)
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
bool free_parse(parse_t *a)
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
bool init_sstr(sstring *a, size_t alloc_size)
{
	if (a)
	{
		a->set = _sstring_set;
		a->set_char = _sstring_set_char;
		a->set_upto = _sstring_set_upto;
		a->set_random = _sstring_set_random;
		a->set_array = _sstring_set_array;
		a->get = _sstring_get;
		a->append = _sstring_append;
		a->append_char = _sstring_append_char;
		a->append_upto = _sstring_append_upto;
		a->append_start = _sstring_append_start;
		a->append_start_char = _sstring_append_start_char;
		a->append_start_upto = _sstring_append_start_upto;
		a->append_array = _sstring_append_array;
		a->append_start_array = _sstring_append_start_array;
		a->empty = _sstring_empty;
		a->replace_char = _sstring_replace_char;
		a->char_set = _sstring_char_set;
		a->char_get = _sstring_char_get;
		a->last_index_of = _sstring_last_index_of;
		a->length = _sstring_length;
		a->compare = _sstring_compare;
		a->compare_upto = _sstring_compare_upto;
		a->lexicographical_comparison = _sstring_lexicographical_comparison;
		a->print = _sstring_print;
		a->replace = _sstring_replace;
		a->destructor = _sstring_destructor;
		a->c_str = _sstring_c_str;
		a->save = _sstring_save;
		a->append_file = _sstring_append_file;
		a->open = _sstring_open;
		a->clear = _sstring_clear;
		a->to_upper = _sstring_to_upper;
		a->to_lower = _sstring_to_lower;
		a->swap_case = _sstring_swap_case;
		a->is_initialized = _sstring_is_initialized;
		a->to_binary = _sstring_to_binary;
		a->from_binary = _sstring_from_binary;
		a->entropy = _sstring_entropy;
		a->contains = _sstring_contains;
		a->contains_char = _sstring_contains_char;
		a->to_set = _sstring_to_set;
		a->copy = _sstring_copy;
		a->to_hexadecimal = _sstring_to_hexadecimal;
		a->from_hexadecimal = _sstring_from_hexadecimal;
		a->find = _sstring_find;
		a->in = _sstring_in;
		a->getline = _sstring_getline;
		a->reverse = _sstring_reverse;
		a->remove = _sstring_remove;
		a->remove_char = _sstring_remove_char;
		a->remove_extra_char = _sstring_remove_extra_char;
		a->remove_range = _sstring_remove_range;
		a->intersect = _sstring_intersect;
		a->distance = _sstring_distance;
		a->edit_distance = _sstring_edit_distance;
		a->percentage_matched = _sstring_percentage_matched;
		a->count = _sstring_count;
		a->count_char = _sstring_count_char;
		a->soundex = _sstring_soundex;
		a->most_used = _sstring_most_used;
		a->most_used_char = _sstring_most_used_char;
		a->split = _sstring_split;
		a->sort = _sstring_sort;
		a->open_binary = _sstring_open_binary;
		a->save_binary = _sstring_save_binary;
		a->append_binary = _sstring_append_binary;
		a->add_binary = _sstring_add_binary;
		a->print_binary = _sstring_print_binary;
		a->encrypt = _sstring_encrypt;
		a->decrypt = _sstring_decrypt;
		a->begin = _sstring_begin;
		a->iterator = _sstring_iterator;
		a->reverse_iterator = __sstring_reverse_iterator;
		a->end = _sstring_end_sstring;
		a->to_morse_code = _sstring_to_morse_code;
		a->from_morse_code = _sstring_from_morse_code;
		a->is_digit = _sstring_is_digit;
		a->is_decimal = _sstring_is_decimal;
		a->is_ascii = _sstring_is_ascii;
		a->is_alphabetic = _sstring_is_alphabetic;
		a->format_escape_sequence = _sstring_format_escape_sequence;
		a->insert = _sstring_insert;
		a->starts_with = _sstring_starts_with;
		a->ends_with = _sstring_ends_with;
		a->parse = _sstring_parse;
		a->from_parse_t = _sstring_from_parse_t;
		a->set_formatted = _sstring_set_formatted;
		a->append_formatted = _sstring_append_formatted;
		a->resize = _sstring_resize;
		a->hash = _sstring_hash;
		a->nerr = (size_t)-1;

		a->str.src = calloc(alloc_size + 1, sizeof(char));
		a->str.len = 0;
		a->str.init = true; // initialized properly
		return true;
	}
	return false;
}

#endif