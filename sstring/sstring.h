#pragma once

/**
* This header file is written to manage string data safely under C programming language.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "sstring.h" under "sstring" directory
* sstring: version 21.0.0
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

#define sstring_version "21.0.0"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>

#define true 0
#define false 1
typedef unsigned long long int SIZE_T;

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
} __str__;

/**
 * This struct is made to store double-pointer char and its length.
 * Use `free_split` function to free this struct.
 */
typedef struct split_t
{
    /* contains the splitted strings */
    char **data;
    /* length of double-pointer `data` */
    SIZE_T len;
} split_t;

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
    void (*set_upto)(sstring *a, const char *src, SIZE_T N);

    /** Sets random data to `a`. NOTE: length should be greater than 0, (not equal to 0). Well, no error and result if assigned 0. 
     * NOTE: use srand function before calling this function. 
     * @code {.c} 
     * srand((unsigned int)(time(NULL) * getpid() * getpid() + getpid())); 
     * @endcode 
     * @param a pointer to struct sstring
     * @param len size of random string
     */
    void (*set_random)(sstring *a, const SIZE_T len);

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
    void (*set_array)(sstring *a, const char **src, char char_between, SIZE_T from, SIZE_T till, SIZE_T len);

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
    void (*append_upto)(sstring *a, const char *src, SIZE_T N);

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
    void (*append_start_upto)(sstring *a, const char *src, SIZE_T N);

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
    void (*append_array)(sstring *a, const char **src, char char_between, SIZE_T from, SIZE_T till, SIZE_T len);

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
    void (*append_start_array)(sstring *a, const char **src, char char_between, SIZE_T from, SIZE_T till, SIZE_T len);

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
    void (*char_set)(sstring *a, const char what, SIZE_T where);

    /**
     * Returns character from `a` at `where`.
     * Only returns if `where` is less than size of `a`.
     * @param a pointer to struct sstring
     * @param where get an element from where in `a`
     * @returns character from `a` at `where`.
     */
    char (*char_get)(sstring *a, SIZE_T where);

    /**
     * Returns length of `a`, does not include the count of NUL(0).
     * @param a pointer to struct sstring
     * @returns length of `a`
     */
    SIZE_T(*length)
    (sstring *a);

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
    int (*compare_upto)(sstring *a, const char *T1, SIZE_T N);

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
     * Free `a->str.src`. 
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
     * If character was found returns its index (first occurrence only) in `a`, otherwise returns -1.
     * @param a pointer to struct sstring
     * @param c character to be tested
     * @returns If character was found returns its index (first occurrence only) in `a`, otherwise returns -1.
    */
    signed long long int (*contains_char)(sstring *a, const char c);

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
     * Returns index of first occurrence of sub-string `sub` in `a`. Returns -1 if `sub` was not found in `a`.
     * @param a pointer to struct sstring
     * @param sub sub-string to find in `a`
     * @returns index of first occurrence of sub-string `sub` in `a`
    */
    signed long long int (*find)(sstring *a, const char *sub);

    /**
     * Get input from user and then sets that input to `a`.
     * @param a pointer to struct sstring
     * @param get_line set false to break input after SPACE, otherwise set true to break after EOL
     * @param buff_size memory to allocate for buffer size, data may not be written after `buff_size`, be careful while assigning this value.
     * @returns true if got input and assigned that to `a`, otherwise returns false
     */
    int (*in)(sstring *a, int get_line, SIZE_T buff_size);

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
    char *(*getline)(sstring *a, SIZE_T line);

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
    SIZE_T(*remove)
    (sstring *a, const char *sub);

    /**
     * Removes all occurrence of character `c` from `a`.
     * @param a pointer to struct sstring
     * @param c character to remove
     * @returns total number of characters removed
     */
    SIZE_T(*remove_char)
    (sstring *a, char c);

    /**
     * Removes all extra occurrence of character `c` from `a`. Eg.: "Hello__1" -> "Hello_1", here `c` was underscore('_'). 
     * Mainly used to remove extra whitespaces from a string.
     * @param a pointer to struct sstring
     * @param c character to remove
     * @returns total number of characters removed
     */
    SIZE_T(*remove_extra_char)
    (sstring *a, char c);

    /**
     * Removes characters between `from` and `till`.
     * @param a pointer to struct sstring
     * @param from where to start removing characters
     * @param till when to stop removing characters
     * @returns total number of characters removed
     */
    SIZE_T(*remove_range)
    (sstring *a, SIZE_T from, SIZE_T till);

    /**
     * Assings characters to `a` between `from` and `till`.
     * @param a pointer to struct sstring
     * @param from where to start assigning characters
     * @param till when to stop assigning characters
     * @returns true if assigned, otherwise false
     */
    int (*intersect)(sstring *a, SIZE_T from, SIZE_T till);

    /**
     * Calculates hamming distance (From Information Theory) between two strings. NOTE: string's length should be same.
     * @param a pointer to struct sstring
     * @param src second string to compare with
     * @returns returns -1 if length does not match, otherwise number of characters didn't matched.
     */
    signed long long int (*distance)(sstring *a, const char *src);

    /**
     * Returns `Levenshtein Distance` (From Information Theory) against `src`.
     * @param a pointer to struct sstring
     * @param src string to be matched
     * @returns edit distance
     */
    signed long long int (*edit_distance)(sstring *a, const char *src);

    /**
     * Returns percentage matched against `src` using `Levenshtein Distance` algorithm (From Information Theory).
     * @param a pointer to struct sstring
     * @param src string to be matched
     * @returns percentage matched, NOTE: returned value belongs to [0, 100]
     */
    long double (*percentage_matched)(sstring *a, const char *src);

    /**
     * Return average of `a` with respect to its position.
     * @param a pointer to struct sstring
     * @returns average of `a` with respect to its position.
     */
    long double (*positional_average)(sstring *a);

    /**
     * Return modulus of `a` with respect to its position.
     * @param a pointer to struct sstring
     * @returns modulus of `a` with respect to its position.
     */
    SIZE_T(*positional_modulus)
    (sstring *a);

    /**
     * Counts the number of occurrence of `what` in `a`.
     * @param a pointer to struct sstring
     * @param what string to find in `a`
     * @returns number of occurrence of `what`
     */
    SIZE_T(*count)
    (sstring *a, const char *what);

    /**
     * Counts the number of occurrence of `what` in `a`.
     * @param a pointer to struct sstring
     * @param what character to find in `a`
     * @returns number of occurrence of `what`
     */
    SIZE_T(*count_char)
    (sstring *a, const char what);

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
     * @returns most used / occurred word in `a`
     */
    char *(*most_used)(sstring *a);

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
    SIZE_T(*open_binary)
    (sstring *a, const char *location);

    /**
     * Saves the content of `a` to the file at `location`.
     * @param a pointer to struct sstring
     * @param location file to be saved
     * @param len length of the data (returned value of `open_binary` function)
     * @returns true if saved, otherwise false
     */
    int (*save_binary)(sstring *a, const char *location, SIZE_T len);

    /**
     * Appends the content of `a` to the file at `location`.
     * @param a pointer to struct sstring
     * @param location file to be appended
     * @param len length of the data (returned value of `open_binary` function)
     * @returns true if appended, otherwise false
     */
    int (*append_binary)(sstring *a, const char *location, SIZE_T len);

    /**
     * Appends the content of `data` to `a`.
     * @param a pointer to struct sstring
     * @param data data to add to `a`
     * @param len length of the `a` (returned value of `open_binary` function)
     * @returns size of data written in bytes, if returned value is 0 then no data is written
     */
    SIZE_T(*add_binary)
    (sstring *a, const char *data, SIZE_T len);

    /**
     * Prints `a` till `len`.
     * @param a pointer to struct sstring
     * @param len length of the data (returned value of `open_binary` function)
     * @returns true if appended, otherwise false
     */
    int (*print_binary)(sstring *a, SIZE_T len);

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
} __string__;

#include "prototype_err.h"

/**
 * Linear time complexity = O(n), where n is the length of `src`. NOTE: `dest` must have enough space for `src`.
 * @param dest string where `src` is going to append
 * @param src string to be appended
 * @param size where to append `src`, pass your variable like &size);
 */
void fast_strncat(char *dest, const char *src, SIZE_T *size)
{
    if (dest && src)
        while ((dest[*size] = *src++))
            *size += 1;
}

void _set(sstring *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (strlen(src) + 1), sizeof(char));
        strcpy(a->str.src, src);
    }
}

void _set_char(sstring *a, const char c)
{
    if (a && c != '\0' && a->str.init == true && a->str.src)
    {
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * 2, sizeof(char));
        strncpy(a->str.src, &c, 1);
    }
}

void _set_upto(sstring *a, const char *src, SIZE_T N)
{
    SIZE_T l = 0;
    if (a && src && a->str.init == true && a->str.src && N <= (l = strlen(src)))
    {
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
        strncpy(a->str.src, src, N);
    }
}

void _set_random(sstring *a, const SIZE_T len)
{
    if (a && a->str.init == true && a->str.src && len > 0)
    {
        char *buff = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        // random ascii character betweem 32 and 126, inclusive
        for (SIZE_T i = 0; i < len; i++)
            buff[i] = (rand() % (126 - 32 + 1)) + 32;
        free(a->str.src);
        a->str.src = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
    }
}

void _set_array(sstring *a, const char **src, char char_between, SIZE_T from, SIZE_T till, SIZE_T len)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        int valid = true;
        if (till > len || from > len)
        {
            valid = false;
            return;
        }
        SIZE_T cnt_t = 0;
        if (valid == true)
        {
            for (SIZE_T i = from; i < till; i++)
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
            SIZE_T track = 0;
            for (SIZE_T i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], &track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, &track);
            }
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
}

char *_get(sstring *a)
{
    if (a && a->str.init == true && a->str.src)
        return a->str.src;
    return (char *)NULL;
}

void _append(sstring *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        SIZE_T len = 0;
        if ((len = strlen((const char *)a->str.src)) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * (strlen(src) + 1), sizeof(char));
            strcpy(a->str.src, src); // copy `src` to `a`.
        }
        else
        {
            a->str.src = (char *)realloc(a->str.src, sizeof(char) * (strlen(src) + len + 1));
            fast_strncat(a->str.src, src, &len);
        }
    }
}

void _append_char(sstring *a, const char c)
{
    if (a && c != '\0' && a->str.init == true && a->str.src)
    {
        SIZE_T len = 0;
        if ((len = strlen((const char *)a->str.src)) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * 2, sizeof(char));
            strncpy(a->str.src, &c, 1); // copy `c` to `a`.
        }
        else
        {
            a->str.src = (char *)realloc(a->str.src, (sizeof(char) * 2) + (len + 1));
            char __dat[3] = "\0\0";
            __dat[0] = c;
            fast_strncat(a->str.src, (const char *)__dat, &len);
        }
    }
}

void _append_upto(sstring *a, const char *src, SIZE_T N)
{
    SIZE_T l = 0;
    if (a && src && a->str.init == true && a->str.src && N <= (l = strlen(src)) && N != 0)
    {
        SIZE_T len = 0;
        if ((len = strlen((const char *)a->str.src)) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
            strncpy(a->str.src, src, N); // copy `src` to `a`.
        }
        else
        {
            a->str.src = (char *)realloc(a->str.src, sizeof(char) * (N + len + 1));
            char *buff = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
            strncpy(buff, src, N);
            fast_strncat(a->str.src, (const char *)buff, &len);
            free(buff);
        }
    }
}

void _append_start(sstring *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        SIZE_T len = 0;
        if ((len = strlen((const char *)a->str.src)) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * (strlen(src) + 1), sizeof(char));
            strcpy(a->str.src, src); // copy `src` to `a`.
        }
        else
        {
            char *buff = (char *)calloc(sizeof(char) * (strlen(src) + len + 1), sizeof(char));
            SIZE_T track = 0;
            fast_strncat(buff, src, &track);
            fast_strncat(buff, (const char *)a->str.src, &track);
            free(a->str.src);
            a->str.src = (char *)calloc((sizeof(char) * track) + 1, sizeof(char));
            track = 0;
            fast_strncat(a->str.src, (const char *)buff, &track);
            free(buff);
        }
    }
}

void _append_start_char(sstring *a, const char c)
{
    if (a && c != '\0' && a->str.init == true && a->str.src)
    {
        SIZE_T len = 0;
        if ((len = strlen((const char *)a->str.src)) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * 2, sizeof(char));
            strncpy(a->str.src, &c, 1); // copy `c` to `a`.
        }
        else
        {
            char ___c[3] = "\0\0";
            ___c[0] = c;
            SIZE_T track = 0;
            char *buff = (char *)calloc((sizeof(char) * 2) + (len + 1), sizeof(char));
            fast_strncat(buff, (const char *)___c, &track);
            fast_strncat(buff, (const char *)a->str.src, &track);
            free(a->str.src);
            a->str.src = (char *)calloc((sizeof(char) * track) + 1, sizeof(char));
            track = 0;
            fast_strncat(a->str.src, (const char *)buff, &track);
            free(buff);
        }
    }
}

void _append_start_upto(sstring *a, const char *src, SIZE_T N)
{
    SIZE_T l = 0;
    if (a && src && a->str.init == true && a->str.src && N <= (l = strlen(src)) && N != 0)
    {
        SIZE_T len = 0;
        if ((len = strlen((const char *)a->str.src)) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * (N + 1), sizeof(char));
            strncpy(a->str.src, src, N); // copy `src` to `a`.
        }
        else
        {
            char *buff = (char *)calloc((sizeof(char) * (len + N + 1)), sizeof(char));
            strncpy(buff, src, N);
            SIZE_T track = N;
            fast_strncat(buff, (const char *)a->str.src, &track);
            free(a->str.src);
            a->str.src = (char *)calloc((sizeof(char) * track) + 1, sizeof(char));
            track = 0;
            fast_strncat(a->str.src, (const char *)buff, &track);
            free(buff);
        }
    }
}

void _append_array(sstring *a, const char **src, char char_between, SIZE_T from, SIZE_T till, SIZE_T len)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        int valid = true;
        if (till > len || from > len)
        {
            valid = false;
            return;
        }
        SIZE_T cnt_t = 0;
        if (valid == true)
        {
            for (SIZE_T i = from; i < till; i++)
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
            SIZE_T slen = strlen((const char *)a->str.src), track = 0;
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + slen + 1, sizeof(char)), bw[3] = "\0\0";
            fast_strncat(buff, (const char *)a->str.src, &track);

            if (slen > 0 && (bw[0] = char_between) != '\0')
                fast_strncat(buff, (const char *)bw, &track);
            for (SIZE_T i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], &track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, &track);
            }
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
            track = 0;
            fast_strncat(a->str.src, (const char *)buff, &track);
            free(buff);
        }
    }
}

void _append_start_array(sstring *a, const char **src, char char_between, SIZE_T from, SIZE_T till, SIZE_T len)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        int valid = true;
        if (till > len || from > len)
        {
            valid = false;
            return;
        }
        SIZE_T cnt_t = 0;
        if (valid == true)
        {
            for (SIZE_T i = from; i < till; i++)
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
            SIZE_T slen = strlen((const char *)a->str.src), track = 0;
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + slen + 1, sizeof(char)), bw[3] = "\0\0";
            for (SIZE_T i = from; i < till; i++)
            {
                fast_strncat(buff, src[i], &track);
                if (i < till - 1 && (bw[0] = char_between) != '\0')
                    fast_strncat(buff, (const char *)bw, &track);
            }
            if (cnt_t > 2 && (bw[0] = char_between) != '\0')
                fast_strncat(buff, (const char *)bw, &track);
            fast_strncat(buff, (const char *)a->str.src, &track);
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (track + 1), sizeof(char));
            track = 0;
            fast_strncat(a->str.src, (const char *)buff, &track);
            free(buff);
        }
    }
}

int _empty(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
        if (strlen((const char *)a->str.src) == 0)
            return true;
    return false;
}

void _replace_char(sstring *a, const char old, const char new_)
{
    if (a && a->str.src && a->str.init == true)
    {
        for (SIZE_T i = 0; a->str.src[i] != '\0'; ++i)
            if (a->str.src[i] == old)
                a->str.src[i] = new_;
    }
}

void _char_set(sstring *a, const char what, SIZE_T where)
{
    if (a && a->str.src && a->str.init == true)
    {
        if (strlen((const char *)a->str.src) > where && what != '\0')
            a->str.src[where] = what;
    }
}

char _char_get(sstring *a, SIZE_T where)
{
    if (a && a->str.src && a->str.init == true)
    {
        if (strlen((const char *)a->str.src) > where)
            return a->str.src[where];
    }
    return (char)'\0';
}

SIZE_T _length(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
        return strlen((const char *)a->str.src);
    return (SIZE_T)0;
}

int _compare(sstring *a, const char *T1)
{
    if (a && T1 && a->str.init == true && a->str.src)
    {
        if (strcmp((const char *)a->str.src, T1) == true)
            return true;
    }
    return false;
}

int _compare_upto(sstring *a, const char *T1, SIZE_T N)
{
    if (a && T1 && a->str.init == true && a->str.src && strlen(T1) >= N)
    {
        if (strncmp((const char *)a->str.src, T1, N) == true)
            return true;
    }
    return false;
}

void _print(sstring *a, int add_next_line, const char *__format__, ...)
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
#ifdef _WIN32
            printf("\r\n");
#elif defined __unix__
            printf("\n");
#elif defined __APPLE__
            printf("\n");
#endif
        }
        fflush(stdout);
    }
}

void _replace(sstring *a, const char *old, const char *new_)
{
    if (a && old && new_ && a->str.init == true && a->str.src)
    {
        SIZE_T i, count_old = 0, len_o = strlen(old), len_n = strlen(new_);
        const char *temp = (const char *)a->str.src;
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
                strcpy(&buff[i], new_);
                i += len_n;
                temp += len_o;
            }
            else
                buff[i++] = *temp++;
        }
        buff[i] = '\0';
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
    }
}

int _destructor(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        free(a->str.src);
        a->str.init = false;
        return true;
    }
    return false;
}

const char *_c_str(sstring *a)
{
    if (a && a->str.init == true && a->str.src)
        return (const char *)a->str.src;
    return (const char *)NULL;
}

int _save(sstring *a, const char *location)
{
    if (a && a->str.src && location && a->str.init == true)
    {
        FILE *f = fopen(location, "wb");
        if (f != NULL)
        {
            fwrite((const char *)a->str.src, strlen((const char *)a->str.src), sizeof(char), f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _append_file(sstring *a, const char *location)
{
    if (a && a->str.src && location && a->str.init == true)
    {
        FILE *f = fopen(location, "ab");
        if (f != NULL)
        {
            fwrite((const char *)a->str.src, strlen((const char *)a->str.src), sizeof(char), f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _open(sstring *a, const char *location)
{
    if (a && location && a->str.init == true)
    {
        FILE *f = fopen(location, "rb");
        if (f != NULL)
        {
            fseek(f, 0, SEEK_END);
            SIZE_T len = ftell(f);
            fseek(f, 0, SEEK_SET);
            free(a->str.src);
            a->str.src = (char *)calloc(len + 1, sizeof(char));
            fread(a->str.src, sizeof(char), len, f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _clear(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        free(a->str.src);
        a->str.src = (char *)calloc(1, sizeof(char));
        return true;
    }
    return false;
}

void _to_upper(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        for (SIZE_T i = 0; a->str.src[i] != '\0'; ++i)
        {
            if (a->str.src[i] <= 122 && a->str.src[i] >= 97)
                a->str.src[i] -= 32;
        }
    }
}

void _to_lower(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        for (SIZE_T i = 0; a->str.src[i] != '\0'; ++i)
        {
            if (a->str.src[i] <= 90 && a->str.src[i] >= 65)
                a->str.src[i] += 32;
        }
    }
}

void _swap_case(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        for (SIZE_T i = 0; a->str.src[i] != '\0'; ++i)
        {
            if (a->str.src[i] <= 90 && a->str.src[i] >= 65)
                a->str.src[i] += 32;
            else if (a->str.src[i] <= 122 && a->str.src[i] >= 97)
                a->str.src[i] -= 32;
        }
    }
}

int _is_initialized(sstring *a)
{
    if (a)
        if (a->str.init == true)
            return true;
    return false; // never reaches this point by the way, call this function(_is_initialized) directly to get a value i.e, true or false.
}

#include "binary.h"

void _to_binary(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src), size = 0;
        char *buff = (char *)calloc(((2 * (len * 8)) + 1) * sizeof(char), sizeof(char));
        for (SIZE_T i = 0; i < len; ++i)
        {
            fast_strncat(buff, binary_data[(SIZE_T)a->str.src[i]], &size);
            if (i < len - 1)
                fast_strncat(buff, " ", &size);
        }
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (size + 1), sizeof(char));
        size = 0;
        fast_strncat(a->str.src, (const char *)buff, &size);
        free(buff);
    }
}

int _from_binary(sstring *a)
{
    int valid = true;
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src);
        // test 1 for checking binary input format
        for (SIZE_T i = 0; i < len; i++)
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
            SIZE_T cnt = 0;
            for (SIZE_T i = 0; i < len; i++)
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
            char *buff = (char *)calloc((len / 8) + 1, sizeof(char));
            char bin[9] = "\0", store[2] = "\0";
            char c = '\0';
            SIZE_T z = 0;
            for (SIZE_T i = 0, j = 0; i < len; ++i, ++j)
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
            a->str.src = (char *)calloc(sizeof(char) * (z + 1), sizeof(char));
            z = 0;
            fast_strncat(a->str.src, (const char *)buff, &z);
            free(buff);
        }
    }
    return valid;
}

long double _entropy(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src);
        SIZE_T cnt = 0, map_append = 0, o = 0;
        int check = false;
        char *map_char = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        SIZE_T *map_cnt = (SIZE_T *)calloc((sizeof(SIZE_T) * len) + 1, sizeof(SIZE_T));
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
        long double result = 0.0f;
        long double freq = 0.0f;
        for (SIZE_T i = 0; map_char[i] != '\0'; i++)
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
    if (a && a->str.src && a->str.init == true && str)
        if (strstr((const char *)a->str.src, str) != NULL)
            return true;
    return false;
}

signed long long int _contains_char(sstring *a, const char c)
{
    if (a && a->str.src && a->str.init == true && c != '\0')
    {
        for (SIZE_T i = 0; a->str.src[i] != '\0'; i++)
            if (a->str.src[i] == c)
                return (SIZE_T)i;
    }
    return -1;
}

void _to_set(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src);
        SIZE_T cnt = 0, map_append = 0, o = 0;
        int check = false;
        char *set_char = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
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
        a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)set_char) + 1), sizeof(char));
        strcpy(a->str.src, (const char *)set_char);
        free(set_char);
    }
}

int _copy(sstring *a, sstring *dest)
{
    if (a && dest && dest->str.src && dest->str.init == true && a->str.src && a->str.init == true)
    {
        free(dest->str.src);
        dest->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)a->str.src) + 1), sizeof(char));
        strcpy(dest->str.src, (const char *)a->str.src);
        return true;
    }
    return false;
}

void _to_hexadecimal(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        char *buff = (char *)calloc((sizeof(char) * strlen((const char *)a->str.src) * 2) + 1, sizeof(char));
        SIZE_T i = 0, j = 0;
        while (a->str.src[i] != '\0')
        {
            sprintf((char *)buff + j, "%02X", a->str.src[i]);
            i++, j += 2;
        }
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (j + 1), sizeof(char));
        j = 0;
        fast_strncat(a->str.src, (const char *)buff, &j);
        free(buff);
    }
}

int _from_hexadecimal(sstring *a)
{
    int valid = true;
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src);
        // test 1 for checking hexadecimal input format
        for (SIZE_T i = 0; i < len; i++)
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
            char *buff = (char *)calloc((len) / 2 + 1, sizeof(char));
            char bin[3] = "\0", store[2] = "\0";
            char c = '\0';
            SIZE_T z = 0;
            for (SIZE_T i = 0, j = 0; i < len; ++i)
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
            a->str.src = (char *)calloc(sizeof(char) * (z + 1), sizeof(char));
            z = 0;
            fast_strncat(a->str.src, (const char *)buff, &z);
            free(buff);
        }
    }
    return valid;
}

signed long long _find(sstring *a, const char *sub)
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
            return (SIZE_T)strlen((const char *)a->str.src) - strlen((const char *)buff); // buff is subset of a, if buff != NULL
    }
    return -1;
}

int _in(sstring *a, int get_line, SIZE_T buff_size)
{
    if (a && a->str.src && a->str.init == true)
    {
        char *buff = (char *)calloc((sizeof(char) * buff_size + 1), sizeof(char));
        if (get_line == false)
            scanf("%s", buff);
        else
        {
            fgets(buff, buff_size, stdin);
            SIZE_T l = strlen((const char *)buff);
            if (l != 0 && buff[l - 1] == '\n')
                buff[l - 1] = '\0';
        }
        if (buff)
        {
            free(a->str.src);
            a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
            return true;
        }
    }
    return false;
}

char *_getline(sstring *a, SIZE_T line)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src), cnt = 0;
        char *temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char)), *tok;
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
        char *res = (char *)calloc((sizeof(char) * strlen((const char *)tok)) + 1, sizeof(char));
        strcpy(res, (const char *)tok);
        free(temp);
        return res;
    }
    return (char *)NULL;
}

void _reverse(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src), l = len / 2;
        char c = '\0';
        for (SIZE_T i = 0; i < l; i++)
        {
            c = a->str.src[i];
            a->str.src[i] = a->str.src[len - i - 1];
            a->str.src[len - i - 1] = c;
        }
    }
}

SIZE_T _remove(sstring *a, const char *sub)
{
    if (a && a->str.src && a->str.init == true && sub && sub[0] != '\0')
    {
        char *buff = (char *)calloc((sizeof(char) * strlen((const char *)a->str.src)) + 1, sizeof(char));
        strcpy(buff, (const char *)a->str.src);
        SIZE_T len_s = strlen(sub), cnt = 0;
        {
            char *temp = buff;
            SIZE_T size = 0;
            while ((temp = strstr(temp, sub)))
            {
                size = (size == 0) ? (temp - buff) + strlen(temp + len_s) + 1 : size - len_s;
                memmove(temp, temp + len_s, size - (temp - buff));
                cnt += len_s;
            }
            free(temp);
        }
        free(a->str.src);
        a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
        return cnt;
    }
    return 0;
}

SIZE_T _remove_char(sstring *a, const char c)
{
    if (a && a->str.src && a->str.init == true && c != '\0')
    {
        char *buff = (char *)calloc((sizeof(char) * strlen((const char *)a->str.src)) + 1, sizeof(char));
        SIZE_T cnt = 0;
        for (SIZE_T i = 0, k = 0; a->str.src[i] != '\0'; i++)
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
        a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
        return cnt;
    }
    return 0;
}

SIZE_T _remove_extra_char(sstring *a, const char c)
{
    if (a && a->str.src && a->str.init == true && c != '\0')
    {
        char *buff = (char *)calloc((sizeof(char) * strlen((const char *)a->str.src)) + 1, sizeof(char));
        SIZE_T p = 0, i = 0, cnt = 0;
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
        a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
        return cnt;
    }
    return 0;
}

SIZE_T _remove_range(sstring *a, SIZE_T from, SIZE_T till)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src), cnt = 0;
        if (till > len || from > len || from > till)
            return cnt;
        char *buff = (char *)calloc(sizeof(char) * (len - (till - from) + 1), sizeof(char));
        for (SIZE_T i = 0, k = 0; i < len; i++)
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
        a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
        return cnt;
    }
    return 0;
}

int _intersect(sstring *a, SIZE_T from, SIZE_T till)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src);
        if (till > len || from > len || from > till)
            return false;
        char *buff = (char *)calloc(sizeof(char) * ((till - from) + 1), sizeof(char));
        for (SIZE_T i = from, k = 0; i < till; i++)
        {
            buff[k] = a->str.src[i];
            k++;
        }
        free(a->str.src);
        a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
        return true;
    }
    return false;
}

signed long long int _distance(sstring *a, const char *src)
{
    if (a && a->str.src && a->str.init == true && src)
    {
        if (strlen(src) == strlen((const char *)a->str.src))
        {
            SIZE_T cnt = 0;
            for (SIZE_T i = 0; a->str.src[i] != '\0'; i++)
                if (a->str.src[i] != src[i])
                    cnt++;
            return (SIZE_T)cnt;
        }
    }
    return -1;
}

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX2(x, y) ((x > y) ? x : y)
signed long long int _edit_distance(sstring *a, const char *src)
{
    if (a && a->str.src && a->str.init == true && src)
    {
        SIZE_T len1 = strlen((const char *)a->str.src), len2 = strlen(src), x, y, last, old;
        SIZE_T cols[len1 + 1];
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
        return (SIZE_T)cols[len1];
    }
    return -1;
}

long double _percentage_matched(sstring *a, const char *src)
{
    if (a && a->str.src && a->str.init == true && src)
    {
        SIZE_T len1 = strlen((const char *)a->str.src), len2 = strlen(src), x, y, last, old;
        SIZE_T cols[len1 + 1];
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
        SIZE_T max = MAX2(len1, len2);
        return (max - cols[len1]) * 100.0f / max;
    }
    return (long double)0.0f;
}

long double _positional_average(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        long double val = 0;
        for (SIZE_T i = 0; a->str.src[i] != '\0'; i++)
            val += (a->str.src[i] + i) / (2.0 + i);
        val /= strlen((const char *)a->str.src);
        return val;
    }
    return (long double)0;
}

SIZE_T _positional_modulus(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T val = 0;
        for (SIZE_T i = 0; a->str.src[i] != '\0'; i++)
            val += (a->str.src[i] + i) / (2 + i);
        val %= strlen((const char *)a->str.src);
        return val;
    }
    return 0ULL;
}

SIZE_T _count(sstring *a, const char *what)
{
    if (a && a->str.src && a->str.init == true && what)
    {
        SIZE_T cnt = 0, len = strlen(what);
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

SIZE_T _count_char(sstring *a, const char what)
{
    if (a && a->str.src && a->str.init == true && what != '\0')
    {
        SIZE_T cnt = 0;
        for (SIZE_T i = 0; a->str.src[i] != '\0'; i++)
            if (a->str.src[i] == what)
                cnt++;
        return cnt;
    }
    return 0;
}

char *_soundex(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T s = 1, len = strlen((const char *)a->str.src);
        const char *map = "01230120022455012623010202"; // not stored in heap memory, do not free it
        char c, *res = (char *)calloc(sizeof(char) * 5, sizeof(char));
        res[0] = toupper(a->str.src[0]);
        for (SIZE_T i = 1; i < len; ++i)
        {
            c = toupper(a->str.src[i]) - 65;
            if (c >= 0 && c <= 25) // from ASCII table
            {
                if (map[(SIZE_T)c] != '\0')
                {
                    if (map[(SIZE_T)c] != res[s - 1])
                    {
                        res[s] = map[(SIZE_T)c];
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

char *_most_used(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src), cnt = 0, l = 0;
        for (SIZE_T i = 0; i < len; i++)
            if (a->str.src[i] == ' ')
                cnt++;
        if (cnt == 0)
            return (char *)NULL;
        char *temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        strcpy(temp, a->str.src);
        char **buff = (char **)calloc((sizeof(char *) * cnt) + sizeof(char *), sizeof(char *)), *tok = strtok(temp, " ");
        while (tok != NULL)
        {
            buff[l] = tok;
            tok = strtok(NULL, " ");
            l++;
        }
        qsort(buff, l, sizeof(buff[0]), strcmp_void);
        char *res = NULL;
        SIZE_T m = 0, curr = 0;
        for (SIZE_T i = 0; i < l; i++)
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
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src);
        SIZE_T cnt = 0, map_append = 0, o = 0;
        int check = false;
        char *map_char = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        SIZE_T *map_cnt = (SIZE_T *)calloc((sizeof(SIZE_T) * len) + 1, sizeof(SIZE_T));
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
        SIZE_T n = map_cnt[0], q = 0;
        for (SIZE_T i = 1; map_char[i] != '\0'; i++)
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
    if (a && a->str.src && a->str.init == true && dl && dl[0] != '\0')
    {
        split_t x;
        x.data = (char **)NULL;
        x.len = 0;
        SIZE_T len = strlen((const char *)a->str.src), cnt = 0;
        char *temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char)), *tok;
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
        temp = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        strcpy(temp, a->str.src);
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

void merge(char *arr, SIZE_T l, SIZE_T m, SIZE_T r)
{
    SIZE_T i, j, k;
    SIZE_T n1 = m - l + 1;
    SIZE_T n2 = r - m;
    SIZE_T L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(char *arr, SIZE_T l, SIZE_T r)
{
    if (l < r)
    {
        SIZE_T m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void _sort(sstring *a)
{
    if (a && a->str.src && a->str.init == true && a->str.src[0] != '\0')
    {
        SIZE_T len = strlen((const char *)a->str.src);
        merge_sort(a->str.src, 0, len - 1);
    }
}

SIZE_T _open_binary(sstring *a, const char *location)
{
    if (a && a->str.src && a->str.init == true && location)
    {
        FILE *f = fopen(location, "rb");
        if (f != NULL)
        {
            fseek(f, 0, SEEK_END);
            SIZE_T len = ftell(f);
            fseek(f, 0, SEEK_SET);
            unsigned char *_temp_ = (unsigned char *)calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
            free(a->str.src);
            a->str.src = (char *)calloc(len + 1, sizeof(char));
            fread(_temp_, sizeof(unsigned char), len, f);
            memcpy(a->str.src, (const void *)_temp_, len);
            fclose(f);
            free(_temp_);
            return len;
        }
    }
    return 0;
}

int _save_binary(sstring *a, const char *location, SIZE_T len)
{
    if (a && a->str.src && a->str.init == true && location)
    {
        unsigned char *_temp_ = (unsigned char *)calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
        memcpy(_temp_, (const void *)a->str.src, len);
        FILE *f = fopen(location, "wb");
        if (f != NULL)
        {
            fwrite((unsigned char *)_temp_, len, sizeof(unsigned char), f);
            fclose(f);
        }
        free(_temp_);
        return true;
    }
    return false;
}

int _append_binary(sstring *a, const char *location, SIZE_T len)
{
    if (a && a->str.src && a->str.init == true && location)
    {
        unsigned char *_temp_ = (unsigned char *)calloc((sizeof(unsigned char) * len) + 1, sizeof(unsigned char));
        memcpy(_temp_, (const void *)a->str.src, len);
        FILE *f = fopen(location, "ab");
        if (f != NULL)
        {
            fwrite((unsigned char *)_temp_, len, sizeof(unsigned char), f);
            fclose(f);
        }
        free(_temp_);
        return true;
    }
    return false;
}

SIZE_T _add_binary(sstring *a, const char *data, SIZE_T len)
{
    if (a && a->str.src && a->str.init == true && data)
    {
        SIZE_T size = len;
        a->str.src = (char *)realloc(a->str.src, (sizeof(char) * (len + strlen(data) + 1)));
        fast_strncat(a->str.src, data, &size);
        return size - len; // total data written
    }
    return 0;
}

int _print_binary(sstring *a, SIZE_T len)
{
    if (a && a->str.src && a->str.init == true)
    {
        while (len != 0)
            printf("%c", a->str.src[len--]);
        return true;
    }
    return false;
}

int _encrypt(sstring *a, const char *key)
{
    if (a && a->str.src && a->str.init == true && key)
    {
        SIZE_T val = 0; // positional_modulus
        for (SIZE_T i = 0; key[i] != '\0'; i++)
            val += (key[i] + i) / (2.0 + i);
        val %= strlen(key);
        if (val == 0)
            return false;
        SIZE_T len = strlen((const char *)a->str.src);
        short add = true;
        char *buff = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        for (SIZE_T i = 0; a->str.src[i] != '\0'; i++)
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
                return false;
        }
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        len = 0;
        fast_strncat(a->str.src, (const char *)buff, &len);
        free(buff);
        return true;
    }
    return false;
}

int _decrypt(sstring *a, const char *key)
{
    if (a && a->str.src && a->str.init == true && key)
    {
        SIZE_T val = 0; // positional_modulus
        for (SIZE_T i = 0; key[i] != '\0'; i++)
            val += (key[i] + i) / (2.0 + i);
        val %= strlen(key);
        if (val == 0)
            return false;
        SIZE_T len = strlen((const char *)a->str.src);
        short add_inrv = true;
        char *buff = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        for (SIZE_T i = 0; a->str.src[i] != '\0'; i++)
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
                return false;
        }
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (len + 1), sizeof(char));
        len = 0;
        fast_strncat(a->str.src, (const char *)buff, &len);
        free(buff);
        return true;
    }
    return false;
}

/**
 * Frees `a` carefully. Always use this function when there is not use of `a` or before your program exits.
 * @param a pointer to struct split
 * @returns true if freed, otherwise false
 */
int free_split(split_t *a)
{
    if (a)
    {
        for (SIZE_T i = 0; i < a->len; i++)
        {
            if (a->data[i] != NULL)
                free(a->data[i]);
        }
        free(a->data);
        return true;
    }
    return false;
}

/**
 * Shortcut for initializing a `sstring` struct.
 * @param src data to assign by default, if `src` is NULL then nothing is assigned
 * @returns an initialized `sstring`
 */
sstring new_sstring(const char *src)
{
    sstring x;
    init_sstr(&x);
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
    init_sstr(&x);

/**
 * Always use this function after any `sstring` declaration. 
 * This function initializes `a`. 
 * By the way use `SSTRING(x)` macro for shortcut.
 * @param a pointer to struct sstring
 */
int init_sstr(sstring *a)
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
        a->positional_average = _positional_average;
        a->positional_modulus = _positional_modulus;
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
        a->str.src = (char *)calloc(1 * sizeof(char), sizeof(char));
        a->str.init = true; // initialized properly
        return true;
    }
    return false;
}