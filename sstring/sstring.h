/**
* This header file is written to manage string data safely under C programming language.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "sstring.h" under "sstring" directory
* sstring: version 4.2.5
* 
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

#pragma once

#define sstring_version "4.2.5"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>

#define true 0
#define false 1
typedef unsigned long long int SIZE_T;

typedef struct __str__
{
    /* Do not modify it directly (segfault), most probably and use 'str.destructor(&str);' at the end */
    char *src;
    /* Do not change this value. */
    int init;
} __str__;

struct __string__
{
    /* Do not use this. */
    __str__ str;

    /** Sets `src` to `a`.
     * @param a pointer to struct sstring
     * @param src string to assign
     */
    void (*set)(sstring *a, const char *src);

    /** Sets `src` to `a` upto `N`.
     * @param a pointer to struct sstring
     * @param src string to assign
     * @param N sets upto a number
     */
    void (*set_upto)(sstring *a, const char *src, SIZE_T N);

    /** Sets random data to `a`. Note: length should be greater than 0, (not equal to 0). Well, no error and result if assigned 0. 
     * Note: use srand function before calling this function.
     * `srand((unsigned int)(time(NULL) * getpid() * getpid() + getpid()));`
     * @param a pointer to struct sstring
     * @param len size of random string
     */
    void (*set_random)(sstring *a, const SIZE_T len);

    /** @brief Sets `src` array to `a`. Note: `from`, `till` belongs to [0, sizeof(`src`)]. 
     * Set `char_between` to 0 if you want nothing to append in-between. 
     * Note: `src[till]` is not included in resultant string.
     * @param a pointer to struct sstring
     * @param src string array to assign
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start assigning `src[from]`
     * @param till assign till `src[till]`
     * @param len length of `src` array
     */
    void (*set_array)(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);

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

    /** Appends `src` to `a` at the starting upto `N`.
     * @param a pointer to struct sstring
     * @param src string to append
     * @param N append upto a number
     */
    void (*append_start_upto)(sstring *a, const char *src, SIZE_T N);

    /** @brief Appends `src` array to `a` at the end. Note: `from`, `till` belongs to [0, sizeof(`src`)]. 
     * Set `char_between` to 0 if you want nothing to append in-between. 
     * Note: `src[till]` is not included in resultant string.
     * @param a pointer to struct sstring
     * @param src string array to append
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start appending `src[from]`
     * @param till append till `src[till]`
     * @param len length of `src` array
     */
    void (*append_array)(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);

    /** @brief Appends `src` array to `a` at the starting. Note: `from`, `till` belongs to [0, sizeof(`src`)]. 
     * Set `char_between` to 0 if you want nothing to append in-between. 
     * Note: `src[till]` is not included in resultant string.
     * @param a pointer to struct sstring
     * @param src string array to append
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start appending `src[from]`
     * @param till append till `src[till]`
     * @param len length of `src` array
     */
    void (*append_start_array)(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);

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
     * Returns length of `a`, if `a` != NULL.
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
     * @returns true if save successfully, otherwise return false
     */
    int (*save)(sstring *a, const char *location);

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
     * Returns whether `a` is initialized or not using `init_str` function.
     * @param a pointer to struct sstring
     * @returns true if initialized, otherwise return nothing because this method have to be initialized using `init_str` function.
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
     * If character was found returns it's index (first occurrence only) in `a`, otherwise returns -1.
     * @param a pointer to struct sstring
     * @param c character to be tested
     * @returns If character was found returns it's index (first occurrence only) in `a`, otherwise returns -1.
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
} __string__;

#include "prototype_err.h"

void _set(sstring *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (strlen(src) + 1), sizeof(char));
        strcpy(a->str.src, src);
    }
}

void _set_upto(sstring *a, const char *src, SIZE_T N)
{
    if (a && src && a->str.init == true && a->str.src && N <= strlen(src))
    {
        free(a->str.src);
        SIZE_T l = strlen(src);
        a->str.src = (char *)calloc(((sizeof(char) * l) + 1) + (-l + N), sizeof(char));
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

void _set_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len)
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
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + 1, sizeof(char));
            for (SIZE_T i = from; i < till; i++)
            {
                strcat(buff, src[i]);
                if (i < till - 1 && char_between != '\0')
                    strncat(buff, &char_between, 1);
            }
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
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
        if (strlen((const char *)a->str.src) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * (strlen(src) + 1), sizeof(char));
            strcpy(a->str.src, src); // copy `src` to `a`.
        }
        else
        {
            a->str.src = (char *)realloc(a->str.src, sizeof(char) * (strlen(src) + strlen(a->str.src) + 1));
            strcat(a->str.src, src);
        }
    }
}

void _append_upto(sstring *a, const char *src, SIZE_T N)
{
    if (a && src && a->str.init == true && a->str.src && N <= strlen(src))
    {
        SIZE_T l = strlen(src);
        if (strlen((const char *)a->str.src) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(((sizeof(char) * l) + 1) + (-l + N), sizeof(char));
            strncpy(a->str.src, src, N); // copy `src` to `a`.
        }
        else
        {
            a->str.src = (char *)realloc(a->str.src, sizeof(char) * (l + (-l + N)) + strlen(a->str.src) + 1);
            strncat(a->str.src, src, N);
        }
    }
}

void _append_start(sstring *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        if (strlen((const char *)a->str.src) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(sizeof(char) * (strlen(src) + 1), sizeof(char));
            strcpy(a->str.src, src); // copy `src` to `a`.
        }
        else
        {
            char *buff = (char *)calloc(sizeof(char) * (strlen(src) + strlen(a->str.src) + 1), sizeof(char));
            strcpy(buff, src);
            strcat(buff, (const char *)a->str.src);
            free(a->str.src);
            a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
}

void _append_start_upto(sstring *a, const char *src, SIZE_T N)
{
    if (a && src && a->str.init == true && a->str.src && N <= strlen(src))
    {
        SIZE_T l = strlen(src);
        if (strlen((const char *)a->str.src) == 0) // string is empty
        {
            free(a->str.src); // used calloc in `init_str` function
            a->str.src = (char *)calloc(((sizeof(char) * l) + 1) + (-l + N), sizeof(char));
            strncpy(a->str.src, src, N); // copy `src` to `a`.
        }
        else
        {
            char *buff = (char *)calloc((sizeof(char) * (l + (-l + N)) + strlen(a->str.src)) + 1, sizeof(char));
            strncpy(buff, src, N);
            strcat(buff, (const char *)a->str.src);
            free(a->str.src);
            a->str.src = (char *)calloc((sizeof(char) * strlen((const char *)buff)) + 1, sizeof(char));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
}

void _append_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len)
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
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + strlen((const char *)a->str.src) + 1, sizeof(char));
            strcpy(buff, (const char *)a->str.src);
            if (strlen((const char *)a->str.src) > 0 && char_between != '\0')
                strncat(buff, &char_between, 1);
            for (SIZE_T i = from; i < till; i++)
            {
                strcat(buff, src[i]);
                if (i < till - 1 && char_between != '\0')
                    strncat(buff, &char_between, 1);
            }
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
}

void _append_start_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len)
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
            char *buff = (char *)calloc((sizeof(char) * cnt_t) + strlen((const char *)a->str.src) + 1, sizeof(char));
            for (SIZE_T i = from; i < till; i++)
            {
                strcat(buff, src[i]);
                if (i < till - 1 && char_between != '\0')
                    strncat(buff, &char_between, 1);
            }
            if (cnt_t > 2 && char_between != '\0')
                strncat(buff, &char_between, 1);
            strcat(buff, (const char *)a->str.src);
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
            strcpy(a->str.src, (const char *)buff);
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
        for (i = 0; a->str.src[i] != '\0'; ++i)
        {
            if (strstr((const char *)&a->str.src[i], old) == &a->str.src[i])
            {
                count_old++;
                i += len_o - 1;
            }
        }
        char *buff = (char *)calloc(sizeof(char) * (i + count_old * (len_n - len_o) + 1), sizeof(char));
        i = 0;
        while (*a->str.src)
        {
            if (strstr(a->str.src, old) == a->str.src)
            {
                strncpy(&buff[i], new_, len_n + 1);
                i += len_n;
                a->str.src += len_o;
            }
            else
                buff[i++] = *a->str.src++;
        }
        buff[i] = 0;
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

int _is_initialized(sstring *a)
{
    if (a)
        if (a->str.init == true)
            return true;
    return false; // never reaches this point by the way
}

void _to_binary(sstring *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        SIZE_T len = strlen((const char *)a->str.src);
        char *buff = (char *)calloc(((2 * (len * 8)) + 1) * sizeof(char), sizeof(char));
        char c = '\0';
        for (SIZE_T i = 0; i < len; ++i)
        {
            c = a->str.src[i];
            for (int j = 7; j >= 0; --j)
            {
                if (c & (1 << j))
                    strcat(buff, "1");
                else
                    strcat(buff, "0");
            }
            if (i < len - 1)
                strcat(buff, " ");
        }
        free(a->str.src);
        a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
        strcpy(a->str.src, (const char *)buff);
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
            char bin[9] = "\0";
            char c = '\0';
            for (SIZE_T i = 0, j = 0; i < len; ++i, ++j)
            {
                if (a->str.src[i] == ' ')
                {
                    c = strtol(bin, (char **)NULL, 2);
                    strncat(buff, &c, 1);
                    j = 0;
                }
                if (i == len - 1)
                {
                    bin[j] = a->str.src[i]; // append last character
                    c = strtol(bin, (char **)NULL, 2);
                    strncat(buff, &c, 1);
                }
                bin[j] = a->str.src[i];
            }
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
            strcpy(a->str.src, (const char *)buff);
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
        a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
        strcpy(a->str.src, (const char *)buff);
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
            char bin[3] = "\0";
            char c = '\0';
            for (SIZE_T i = 0, j = 0; i < len; ++i)
            {
                if (i == len - 1)
                {
                    bin[j] = a->str.src[i];
                    c = strtol(bin, (char **)NULL, 16);
                    strncat(buff, &c, 1);
                }
                if (j == 2)
                {
                    j = 0;
                    c = strtol(bin, (char **)NULL, 16);
                    strncat(buff, &c, 1);
                }
                bin[j] = a->str.src[i];
                j++;
            }
            free(a->str.src);
            a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)buff) + 1), sizeof(char));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
    return valid;
}

signed long long _find(sstring *a, const char *sub)
{
    if (a && a->str.src && a->str.init == true && sub)
    {
        char *buff = strstr((const char *)a->str.src, sub);
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
            scanf("%[^\n]", buff);
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

void init_sstr(sstring *a)
{
    /** 
     * Here 1 means no memory leak, and 0 means memory leak was found.
     * Working means function works as expected.
    */
    if (a)
    {
        a->set = _set;                               /// working 1
        a->set_upto = _set_upto;                     /// working 1
        a->set_random = _set_random;                 /// working 1
        a->set_array = _set_array;                   /// working 1
        a->get = _get;                               /// working 1
        a->append = _append;                         /// working 1
        a->append_upto = _append_upto;               /// working 1
        a->append_start = _append_start;             /// working 1
        a->append_start_upto = _append_start_upto;   /// working 1
        a->append_array = _append_array;             /// working 1
        a->append_start_array = _append_start_array; /// working 1
        a->empty = _empty;                           /// working 1
        a->replace_char = _replace_char;             /// working 1
        a->char_set = _char_set;                     /// working 1
        a->char_get = _char_get;                     /// working 1
        a->length = _length;                         /// working 1
        a->compare = _compare;                       /// working 1
        a->compare_upto = _compare_upto;             /// working 1
        a->print = _print;                           /// working 1
        a->replace = _replace;                       /// working 0
        a->destructor = _destructor;                 /// working 1
        a->c_str = _c_str;                           /// working 1
        a->save = _save;                             /// working 1
        a->open = _open;                             /// working 1
        a->clear = _clear;                           /// working 1
        a->to_upper = _to_upper;                     /// working 1
        a->to_lower = _to_lower;                     /// working 1
        a->is_initialized = _is_initialized;         /// working 1
        a->to_binary = _to_binary;                   /// working 1
        a->from_binary = _from_binary;               /// working 1
        a->entropy = _entropy;                       /// working 1
        a->contains = _contains;                     /// working 1
        a->contains_char = _contains_char;           /// working 1
        a->to_set = _to_set;                         /// working 1
        a->copy = _copy;                             /// working 1
        a->to_hexadecimal = _to_hexadecimal;         /// working 1
        a->from_hexadecimal = _from_hexadecimal;     /// working 1
        a->find = _find;                             /// working 1
        a->in = _in;                                 /// working 1
        a->str.src = (char *)calloc(1 * sizeof(char), sizeof(char));
        a->str.init = true; // initialized properly
    }
}