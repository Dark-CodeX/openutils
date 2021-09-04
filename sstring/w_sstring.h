/**
* This header file is written to manage wide string data safely under C programming language.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Copyright Tushar Chaurasia 2021 - 2022.
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "w_sstring.h" under "sstring" directory
* sstring: version 3.5.1
*/

#pragma once

#define sstring_version "3.5.1"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>

#define true 0
#define false 1

typedef struct w__str__
{
    /* Do not modify it directly (segfault), most probably and use 'str.destructor(&str);' at the end */
    wchar_t *src;
    /* Do not change this value. */
    int init;
} w__str__;

typedef struct w__string__ w_sstring;
struct w__string__
{
    /* Do not use this. */
    w__str__ w_str;

    /** Sets `src` to `a`.
     * @param a pointer to struct w_sstring
     * @param src string to assign
     */
    void (*set)(w_sstring *a, const wchar_t *src);

    /** Sets random data to `a`. Note: length should be greater than 0, (not equal to 0). Well, no error and result if assigned 0. 
     * Note: use srand function before calling this function.
     * `srand((unsigned int)(time(NULL) * getpid() * getpid() + getpid()));`
     * @param a pointer to struct w_sstring
     * @param len size of random string
     */
    void (*set_random)(w_sstring *a, const size_t len);

    /** @brief Sets `src` array to `a`. Note: `from`, `till` belongs to [0, sizeof(`src`)]. 
     * Set `char_between` to 0 if you want nothing to append in-between. 
     * Note: `src[till]` is not included in resultant string.
     * @param a pointer to struct w_sstring
     * @param src string array to assign
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start assigning `src[from]`
     * @param till assign till `src[till]`
     * @param len length of `src` array
     */
    void (*set_array)(w_sstring *a, const wchar_t *src[], wchar_t char_between, size_t from, size_t till, size_t len);

    /** Returns `a` as `wchar_t *`. 
     * @param a pointer to struct w_sstring
     * @returns return `a` as `wchar_t *`
     */
    wchar_t *(*get)(w_sstring *a);

    /** Appends `src` to `a` at the end.
     * @param a pointer to struct w_sstring
     * @param src string to append
     */
    void (*append)(w_sstring *a, const wchar_t *src);

    /** Appends `src` to `a` at the starting.
     * @param a pointer to struct w_sstring
     * @param src string to append
     */
    void (*append_start)(w_sstring *a, const wchar_t *src);

    /** @brief Appends `src` array to `a` at the end. Note: `from`, `till` belongs to [0, sizeof(`src`)]. 
     * Set `char_between` to 0 if you want nothing to append in-between. 
     * Note: `src[till]` is not included in resultant string.
     * @param a pointer to struct w_sstring
     * @param src string array to append
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start appending `src[from]`
     * @param till append till `src[till]`
     * @param len length of `src` array
     */
    void (*append_array)(w_sstring *a, const wchar_t *src[], wchar_t char_between, size_t from, size_t till, size_t len);

    /** @brief Appends `src` array to `a` at the starting. Note: `from`, `till` belongs to [0, sizeof(`src`)]. 
     * Set `char_between` to 0 if you want nothing to append in-between. 
     * Note: `src[till]` is not included in resultant string.
     * @param a pointer to struct w_sstring
     * @param src string array to append
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start appending `src[from]`
     * @param till append till `src[till]`
     * @param len length of `src` array
     */
    void (*append_start_array)(w_sstring *a, const wchar_t *src[], wchar_t char_between, size_t from, size_t till, size_t len);

    /** Checks whether `a` is empty or not.
     * @param a pointer to struct w_sstring
     * @returns return true if empty, otherwise return false
     */
    int (*empty)(w_sstring *a);

    /** Linear time complexity, O(n), where n is the length of the wchar_t array.
     * Replaces `old` to `new`.
     * @param a pointer to struct w_sstring
     * @param old old character (character to be replaced)
     * @param new_ new character (character to be replaced with)
    */
    void (*replace_char)(w_sstring *a, const wchar_t old, const wchar_t new_);

    /**
     * Sets `what` at `where` in `a`.
     * Only sets if `where` is less than size of `a`.
     * @param a pointer to struct w_sstring
     * @param what character to set
     * @param where sets `what` at a fixed position
     */
    void (*char_set)(w_sstring *a, const wchar_t what, size_t where);

    /**
     * Returns character from `a` at `where`.
     * Only returns if `where` is less than size of `a`.
     * @param a pointer to struct w_sstring
     * @param where get an element from where in `a`
     * @returns character from `a` at `where`.
     */
    wchar_t (*char_get)(w_sstring *a, size_t where);

    /**
     * Returns length of `a`, if `a` != NULL.
     * @param a pointer to struct w_sstring
     * @returns length of `a`
     */
    size_t (*length)(w_sstring *a);

    /**
     * Compares `a` against `T1`.
     * @param a pointer to struct w_sstring
     * @param T1 string to compare with
     * @returns return true if true, otherwise return false
     */
    int (*compare)(w_sstring *a, const wchar_t *T1);

    /**
    * Prints `a`.
    * @param a pointer to struct w_sstring
    * @param add_next_line set 0 if append next line, otherwise set 1
    * @param __format__ arguments for ...
     */
    void (*print)(w_sstring *a, int add_next_line, const char *__format__, ...);

    /**
     * Replaces `old` in `a` with `new_`.
     * @param a pointer to struct w_sstring
     * @param old what to replace
     * @param new_ replace with
     */
    void (*replace)(w_sstring *a, const wchar_t *old, const wchar_t *new_);

    /**
     * Free `a->w_str.src`.
     * Do not forget to use this function at the end.
     * @param a pointer to struct w_sstring
     * @returns true if freed successfully, otherwise return false
     */
    int (*destructor)(w_sstring *a);

    /** 
     * Returns `a` as `const wchar_t *`.
     * @param a pointer to struct w_sstring
     * @returns return `a` as `const wchar_t *`
     */
    const wchar_t *(*c_str)(w_sstring *a);

    /**
     * Saves `a` at `location`.
     * @param a pointer to struct w_sstring
     * @param location where to save
     * @returns true if save successfully, otherwise return false
     */
    int (*save)(w_sstring *a, const char *location);

    /**
     * Opens file at `location` and then sets `a` the contents of the file.
     * @param a pointer to struct w_sstring
     * @param location file to open
     * @returns true if opened successfully, otherwise return false
     */
    int (*open)(w_sstring *a, const char *location);

    /**
     * Clears `a` using `calloc` function defined in <stdlib.h> header.
     * @param a pointer to struct w_sstring
     * @returns true if cleared successfully, otherwise return false
     */
    int (*clear)(w_sstring *a);

    /**
     * Converts `a` to upper case.
     * @param a pointer to struct w_sstring
     */
    void (*to_upper)(w_sstring *a);

    /**
     * Converts `a` to lower case.
     * @param a pointer to struct w_sstring
     */
    void (*to_lower)(w_sstring *a);

    /**
     * Returns whether `a` is initialized or not using `init_str` function.
     * @param a pointer to struct w_sstring
     * @returns true if initialized, otherwise return nothing because this method have to be initialized using `init_str` function.
     */
    int (*is_initialized)(w_sstring *a);

    /** 
     * Converts `a` (as string) to base 2 (as binary).
     * @param a pointer to struct w_sstring
    */
    void (*to_binary)(w_sstring *a);

    /** 
     * Converts `a` from base 2 (as binary) to string. Not executed if `a` is not in binary form i.e, [1, 0].
     * @param a pointer to struct w_sstring
    */
    int (*from_binary)(w_sstring *a);

    /**
     * Calculates the entropy using `Shannon's entropy` formula, which was introduced in his 1948 paper "A Mathematical Theory of Communication". For more information https://en.wikipedia.org/wiki/Entropy_(information_theory)
     * @param a pointer to struct w_sstring
     * @returns entropy of `a`.
     */
    long double (*entropy)(w_sstring *a);

    /** 
     * Returns true if contains `str`, otherwise returns false.
     * @param a pointer to struct w_sstring
     * @param str string to be tested
     * @returns true if contains, otherwise return false
    */
    int (*contains)(w_sstring *a, const wchar_t *str);

    /** 
     * Assigns `a` as a set. (From Set Theory) 
     * @param a pointer to struct w_sstring
    */
    void (*to_set)(w_sstring *a);

    /** 
     * Copies `a` to `dest`. If copied successfully then, returns true otherwise false.
     * @param a pointer to struct w_sstring
     * @param dest pointer to struct w_sstring
     * @returns If copied successfully then, returns true otherwise false.
    */
    int (*copy)(w_sstring *a, w_sstring *dest);
} w__string__;

#include "w_prototype_err.h"

void _w_set(w_sstring *a, const wchar_t *src)
{
    if (a && src && a->w_str.init == true && a->w_str.src)
    {
        free(a->w_str.src);
        a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen(src) + 1), sizeof(wchar_t));
        wcscpy(a->w_str.src, src);
    }
}

void _w_set_random(w_sstring *a, const size_t len)
{
    if (a && a->w_str.init == true && a->w_str.src && len > 0)
    {
        wchar_t *buff = (wchar_t *)calloc((sizeof(wchar_t) * len) + 1, sizeof(wchar_t));
        // random UTF-8 character betweem 32 and 255, inclusive
        for (size_t i = 0; i < len; i++)
            buff[i] = (rand() % (255 - 32 + 1)) + 32;
        free(a->w_str.src);
        a->w_str.src = (wchar_t *)calloc((sizeof(wchar_t) * len) + 1, sizeof(wchar_t));
        wcscpy(a->w_str.src, (const wchar_t *)buff);
        free(buff);
    }
}

void _w_set_array(w_sstring *a, const wchar_t *src[], wchar_t char_between, size_t from, size_t till, size_t len)
{
    if (a && src && a->w_str.init == true && a->w_str.src)
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
                    cnt_t += wcslen(src[i]);
            }
        }
        if (valid == true)
        {
            if (char_between != '\0')
                cnt_t += len + 1;
            wchar_t *buff = (wchar_t *)calloc((sizeof(wchar_t) * cnt_t) + 1, sizeof(wchar_t));
            for (size_t i = from; i < till; i++)
            {
                wcscat(buff, src[i]);
                if (i < till - 1 && char_between != '\0')
                    wcsncat(buff, &char_between, 1);
            }
            free(a->w_str.src);
            a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)buff) + 1), sizeof(wchar_t));
            wcscpy(a->w_str.src, (const wchar_t *)buff);
            free(buff);
        }
    }
}

wchar_t *_w_get(w_sstring *a)
{
    if (a && a->w_str.init == true && a->w_str.src)
        return a->w_str.src;
    return (wchar_t *)NULL;
}

void _w_append(w_sstring *a, const wchar_t *src)
{
    if (a && src && a->w_str.init == true && a->w_str.src)
    {
        if (wcslen((const wchar_t *)a->w_str.src) == 0) // string is empty
        {
            free(a->w_str.src); // used calloc in `init_str` function
            a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen(src) + 1), sizeof(wchar_t));
            wcscpy(a->w_str.src, src); // copy `src` it.
        }
        else
        {
            a->w_str.src = (wchar_t *)realloc(a->w_str.src, sizeof(wchar_t) * (wcslen(src) + wcslen(a->w_str.src) + 1));
            wcscat(a->w_str.src, src);
        }
    }
}

void _w_append_start(w_sstring *a, const wchar_t *src)
{
    if (a && src && a->w_str.init == true && a->w_str.src)
    {
        if (wcslen((const wchar_t *)a->w_str.src) == 0) // string is empty
        {
            free(a->w_str.src); // used calloc in `init_str` function
            a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen(src) + 1), sizeof(wchar_t));
            wcscpy(a->w_str.src, src); // copy `src` it.
        }
        else
        {
            wchar_t *buff = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen(src) + wcslen(a->w_str.src) + 1), sizeof(wchar_t));
            wcscpy(buff, src);
            wcscat(buff, (const wchar_t *)a->w_str.src);
            free(a->w_str.src);
            a->w_str.src = (wchar_t *)calloc((sizeof(wchar_t) * wcslen((const wchar_t *)buff)) + 1, sizeof(wchar_t));
            wcscpy(a->w_str.src, (const wchar_t *)buff);
            free(buff);
        }
    }
}

void _w_append_array(w_sstring *a, const wchar_t *src[], wchar_t char_between, size_t from, size_t till, size_t len)
{
    if (a && src && a->w_str.init == true && a->w_str.src)
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
                    cnt_t += wcslen(src[i]);
            }
        }
        if (valid == true)
        {
            if (char_between != '\0')
                cnt_t += len + 1;
            wchar_t *buff = (wchar_t *)calloc((sizeof(wchar_t) * cnt_t) + wcslen((const wchar_t *)a->w_str.src) + 1, sizeof(wchar_t));
            wcscpy(buff, (const wchar_t *)a->w_str.src);
            if (wcslen((const wchar_t *)a->w_str.src) > 0 && char_between != '\0')
                wcsncat(buff, &char_between, 1);
            for (size_t i = from; i < till; i++)
            {
                wcscat(buff, src[i]);
                if (i < till - 1 && char_between != '\0')
                    wcsncat(buff, &char_between, 1);
            }
            free(a->w_str.src);
            a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)buff) + 1), sizeof(wchar_t));
            wcscpy(a->w_str.src, (const wchar_t *)buff);
            free(buff);
        }
    }
}

void _w_append_start_array(w_sstring *a, const wchar_t *src[], wchar_t char_between, size_t from, size_t till, size_t len)
{
    if (a && src && a->w_str.init == true && a->w_str.src)
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
                    cnt_t += wcslen(src[i]);
            }
        }
        if (valid == true)
        {
            if (char_between != '\0')
                cnt_t += len + 1;
            wchar_t *buff = (wchar_t *)calloc((sizeof(wchar_t) * cnt_t) + wcslen((const wchar_t *)a->w_str.src) + 1, sizeof(wchar_t));
            for (size_t i = from; i < till; i++)
            {
                wcscat(buff, src[i]);
                if (i < till - 1 && char_between != '\0')
                    wcsncat(buff, &char_between, 1);
            }
            if (cnt_t > 2 && char_between != '\0')
                wcsncat(buff, &char_between, 1);
            wcscat(buff, (const wchar_t *)a->w_str.src);
            free(a->w_str.src);
            a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)buff) + 1), sizeof(wchar_t));
            wcscpy(a->w_str.src, (const wchar_t *)buff);
            free(buff);
        }
    }
}

int _w_empty(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
        if (wcslen((const wchar_t *)a->w_str.src) == 0)
            return true;
    return false;
}

void _w_replace_char(w_sstring *a, const wchar_t old, const wchar_t new_)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        for (size_t i = 0; a->w_str.src[i] != '\0'; ++i)
            if (a->w_str.src[i] == old)
                a->w_str.src[i] = new_;
    }
}

void _w_char_set(w_sstring *a, const wchar_t what, size_t where)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        if (wcslen((const wchar_t *)a->w_str.src) > where)
            a->w_str.src[where] = what;
    }
}

wchar_t _w_char_get(w_sstring *a, size_t where)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        if (wcslen((const wchar_t *)a->w_str.src) > where)
            return a->w_str.src[where];
    }
    return (wchar_t)'\0';
}

size_t _w_length(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
        return wcslen((const wchar_t *)a->w_str.src);
    return (size_t)0;
}

int _w_compare(w_sstring *a, const wchar_t *T1)
{
    if (a && T1 && a->w_str.init == true && a->w_str.src)
    {
        if (wcscmp((const wchar_t *)a->w_str.src, T1) == true)
            return true;
    }
    return false;
}

void _w_print(w_sstring *a, int add_next_line, const char *__format__, ...)
{
    if (a && __format__ && a->w_str.init == true && a->w_str.src)
    {
        va_list ar;
        va_start(ar, __format__);
        printf("%ls", a->w_str.src);
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

void _w_replace(w_sstring *a, const wchar_t *old, const wchar_t *new_)
{
    if (a && old && new_ && a->w_str.init == true && a->w_str.src)
    {
        size_t i, count_old = 0, len_o = wcslen(old), len_n = wcslen(new_);
        for (i = 0; a->w_str.src[i] != '\0'; ++i)
        {
            if (wcsstr((const wchar_t *)&a->w_str.src[i], old) == &a->w_str.src[i])
            {
                count_old++;
                i += len_o - 1;
            }
        }
        wchar_t *r = (wchar_t *)calloc(sizeof(wchar_t) * (i + count_old * (len_n - len_o) + 1), sizeof(wchar_t));
        i = 0;
        while (*a->w_str.src)
        {
            if (wcsstr(a->w_str.src, old) == a->w_str.src)
            {
                wcsncpy(&r[i], new_, len_n + 1);
                i += len_n;
                a->w_str.src += len_o;
            }
            else
                r[i++] = *a->w_str.src++;
        }
        a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)r) + 1), sizeof(wchar_t));
        wcscpy(a->w_str.src, (const wchar_t *)r);
        free(r);
    }
}

int _w_destructor(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        free(a->w_str.src);
        return true;
    }
    return false;
}

const wchar_t *_w_c_str(w_sstring *a)
{
    if (a && a->w_str.init == true && a->w_str.src)
        return (const wchar_t *)a->w_str.src;
    return (const wchar_t *)NULL;
}

int _w_save(w_sstring *a, const char *location)
{
    if (a && a->w_str.src && location && a->w_str.init == true)
    {
        FILE *f = fopen(location, "wb");
        if (f != NULL)
        {
            fwrite((const wchar_t *)a->w_str.src, wcslen((const wchar_t *)a->w_str.src), sizeof(wchar_t), f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _w_open(w_sstring *a, const char *location)
{
    if (a && location && a->w_str.init == true)
    {
        FILE *f = fopen(location, "rb");
        if (f != NULL)
        {
            fseek(f, 0, SEEK_END);
            size_t len = ftell(f);
            fseek(f, 0, SEEK_SET);
            free(a->w_str.src);
            a->w_str.src = (wchar_t *)calloc(len + 1, sizeof(wchar_t));
            fread(a->w_str.src, sizeof(wchar_t), len, f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _w_clear(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        free(a->w_str.src);
        a->w_str.src = (wchar_t *)calloc(1, sizeof(wchar_t));
        return true;
    }
    return false;
}

void _w_to_upper(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        for (size_t i = 0; a->w_str.src[i] != '\0'; ++i)
        {
            if (a->w_str.src[i] <= 122 && a->w_str.src[i] >= 97)
                a->w_str.src[i] -= 32;
        }
    }
}

void _w_to_lower(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        for (size_t i = 0; a->w_str.src[i] != '\0'; ++i)
        {
            if (a->w_str.src[i] <= 90 && a->w_str.src[i] >= 65)
                a->w_str.src[i] += 32;
        }
    }
}

int _w_is_initialized(w_sstring *a)
{
    if (a)
        if (a->w_str.init == true)
            return true;
    return false; // never reaches this point by the way
}

void _w_to_binary(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        size_t len = wcslen((const wchar_t *)a->w_str.src);
        wchar_t *buff = (wchar_t *)calloc(((2 * (len * 8)) + 1) * sizeof(wchar_t), sizeof(wchar_t));
        wchar_t c = L'\0';
        for (size_t i = 0; i < len; ++i)
        {
            c = a->w_str.src[i];
            for (int j = 7; j >= 0; --j)
            {
                if (c & (1 << j))
                    wcscat(buff, L"1");
                else
                    wcscat(buff, L"0");
            }
            if (i < len - 1)
                wcscat(buff, L" ");
        }
        free(a->w_str.src);
        a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)buff) + 1), sizeof(wchar_t));
        wcscpy(a->w_str.src, (const wchar_t *)buff);
        free(buff);
    }
}

int _w_from_binary(w_sstring *a)
{
    int valid = true;
    if (a && a->w_str.src && a->w_str.init == true)
    {
        size_t len = wcslen((const wchar_t *)a->w_str.src);
        // test 1 for checking binary input format
        for (size_t i = 0; i < len; i++)
        {
            switch (a->w_str.src[i])
            {
            case L'1':
            case L'0':
            case L' ':
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
                if (a->w_str.src[i] == L' ')
                    cnt++;
            }
            if ((len - cnt) % 8 == 0 && ((len - cnt) / 8) == (cnt + 1))
                valid = true;
            else
                valid = false;
        }
        if (valid == true)
        {
            wchar_t *buff = (wchar_t *)calloc((len / 8) + 1, sizeof(wchar_t));
            wchar_t bin[9] = L"\0";
            wchar_t c = L'\0';
            for (size_t i = 0, j = 0; i < len; ++i, ++j)
            {
                if (a->w_str.src[i] == L' ')
                {
                    c = wcstol(bin, (wchar_t **)NULL, 2);
                    wcsncat(buff, &c, 1);
                    j = 0;
                }
                if (i == len - 1)
                {
                    bin[j] = a->w_str.src[i]; // append last character
                    c = wcstol(bin, (wchar_t **)NULL, 2);
                    wcsncat(buff, &c, 1);
                }
                bin[j] = a->w_str.src[i];
            }
            free(a->w_str.src);
            a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)buff) + 1), sizeof(wchar_t));
            wcscpy(a->w_str.src, (const wchar_t *)buff);
            free(buff);
        }
    }
    return valid;
}

long double _w_entropy(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        size_t len = wcslen((const wchar_t *)a->w_str.src);
        size_t cnt = 0, map_append = 0, o = 0;
        int check = false;
        wchar_t *map_char = (wchar_t *)calloc((sizeof(wchar_t) * len) + 1, sizeof(wchar_t));
        size_t *map_cnt = (size_t *)calloc((sizeof(size_t) * len) + 1, sizeof(size_t));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; map_char[o] != '\0'; o++)
            {
                if (map_char[o] == a->w_str.src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                map_char[map_append] = a->w_str.src[cnt];
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

int _w_contains(w_sstring *a, const wchar_t *str)
{
    if (a && a->w_str.src && a->w_str.init == true && str)
        if (wcsstr((const wchar_t *)a->w_str.src, str) != NULL)
            return true;
    return false;
}

void _w_to_set(w_sstring *a)
{
    if (a && a->w_str.src && a->w_str.init == true)
    {
        size_t len = wcslen((const wchar_t *)a->w_str.src);
        size_t cnt = 0, map_append = 0, o = 0;
        int check = false;
        wchar_t *set_char = (wchar_t *)calloc((sizeof(wchar_t) * len) + 1, sizeof(wchar_t));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; set_char[o] != '\0'; o++)
            {
                if (set_char[o] == a->w_str.src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                set_char[map_append] = a->w_str.src[cnt];
                map_append++;
            }
        }
        free(a->w_str.src);
        a->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)set_char) + 1), sizeof(wchar_t));
        wcscpy(a->w_str.src, (const wchar_t *)set_char);
        free(set_char);
    }
}

int _w_copy(w_sstring *a, w_sstring *dest)
{
    if (a && dest && dest->w_str.src && dest->w_str.init == true && a->w_str.src && a->w_str.init == true)
    {
        free(dest->w_str.src);
        dest->w_str.src = (wchar_t *)calloc(sizeof(wchar_t) * (wcslen((const wchar_t *)a->w_str.src) + 1), sizeof(wchar_t));
        wcscpy(dest->w_str.src, (const wchar_t *)a->w_str.src);
        return true;
    }
    return false;
}

void init_w_sstr(w_sstring *a)
{
    /** 
     * Here 1 means no memory leak, and 0 means memory leak was found.
     * Working means function works as expected.
    */
    if (a)
    {
        setlocale(LC_ALL, "");
        a->set = _w_set;                               /// working 1
        a->set_random = _w_set_random;                 /// working 1
        a->set_array = _w_set_array;                   /// working 1
        a->get = _w_get;                               /// working 1
        a->append = _w_append;                         /// working 1
        a->append_start = _w_append_start;             /// working 1
        a->append_array = _w_append_array;             /// working 1
        a->append_start_array = _w_append_start_array; /// working 1
        a->empty = _w_empty;                           /// working 1
        a->replace_char = _w_replace_char;             /// working 1
        a->char_set = _w_char_set;                     /// working 1
        a->char_get = _w_char_get;                     /// working 1
        a->length = _w_length;                         /// working 1
        a->compare = _w_compare;                       /// working 1
        a->print = _w_print;                           /// working 1
        a->replace = _w_replace;                       /// working 0
        a->destructor = _w_destructor;                 /// working 1
        a->c_str = _w_c_str;                           /// working 1
        a->save = _w_save;                             /// working 1
        a->open = _w_open;                             /// working 1
        a->clear = _w_clear;                           /// working 1
        a->to_upper = _w_to_upper;                     /// working 1
        a->to_lower = _w_to_lower;                     /// working 1
        a->is_initialized = _w_is_initialized;         /// working 1
        a->to_binary = _w_to_binary;                   /// working 1
        a->from_binary = _w_from_binary;               /// working 1
        a->entropy = _w_entropy;                       /// working 1
        a->contains = _w_contains;                     /// working 1
        a->to_set = _w_to_set;                         /// working 1
        a->copy = _w_copy;                             /// working 1
        a->w_str.src = (wchar_t *)calloc(1 * sizeof(wchar_t), sizeof(wchar_t));
        a->w_str.init = true; // initialized properly
    }
}

void init_w_sstr_array(w_sstring *a[], size_t len)
{
    if (a)
    {
        for (size_t i = 0; i < len; ++i)
            init_w_sstr(a[i]);
    }
}
