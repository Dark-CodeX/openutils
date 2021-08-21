#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define true 0
#define false 1

typedef struct __str__
{
    /* Do not modify it directly (segfault), most probably and use 'str.destructor(&str);' at the end */
    char *src;
} __str__;

typedef struct __string__ string;
struct __string__
{
    /* Do not use this. */
    __str__ str;

    /** Sets `src` to `a`.
     * @param a pointer to struct string
     * @param src string to assign
     */
    void (*set)(string *a, const char *src);

    /** Returns `a` as `char *`.
     * @param a pointer to struct string
     * @returns return `a` as `char *`
     */
    char *(*get)(string *a);

    /** Appends `src` to `a`.
     * @param a pointer to struct string
     * @param src string to append
     */
    void (*append)(string *a, const char *src);

    /** Checks wether `a` is empty or not.
     * @param a pointer to struct string
     * @returns return 0 if empty, otherwise return 1
     */
    int (*empty)(string *a);

    /** Linear time complexity, O(n), where n is the length of the char array.
     * Replaces `old` to `new`.
     * @param a pointer to struct string
     * @param old old character (character to be replaced)
     * @param new_ new character (character to be replaced with)
    */
    void (*replace_char)(string *a, const char old, const char new_);

    /**
     * Sets `what` at `where` in `a`.
     * Only sets if `where` is less than size of `a`.
     * @param a pointer to struct string
     * @param what character to set
     * @param where sets `what` at a fixed position
     */
    void (*char_set)(string *a, const char what, size_t where);

    /**
     * Returns character from `a` at `where`.
     * Only returns if `where` is less than size of `a`.
     * @param a pointer to struct string
     * @param where get an element from where in `a`
     * @returns character from `a` at `where`.
     */
    char (*char_get)(string *a, size_t where);

    /**
     * Returns length of `a`, if `a` != NULL.
     * @param a pointer to struct string
     * @returns length of `a`
     */
    size_t (*length)(string *a);

    /**
     * Returns memory used in Bytes.
     * @param a pointer to struct string
     * @returns memory used in Bytes
     */
    size_t (*mem_used)(string *a);

    /**
     * Compares `a` against `T1`.
     * @param a pointer to struct string
     * @param T1 string to compare with
     * @returns return 0 if true, otherwise return 1
     */
    int (*compare)(string *a, const char *T1);

    /**
    * Prints `a`.
    * @param a pointer to struct string
    * @param add_next_line set 0 if append next line, otherwise set 1
    * @param __format__ arguments for ...
     */
    void (*print)(string *a, int add_next_line, const char *__format__, ...);

    /**
     * Replaces `old` in `a` with `new_`.
     * @param a pointer to struct string
     * @param old what to replace
     * @param new_ replace with
     */
    void (*replace)(string *a, const char *old, const char *new_);

    /**
     * Free `a->str.src`.
     * Do not forget to use this function at the end.
     * @param a pointer to struct string
     */
    int (*destructor)(string *a);

    /** 
     * Returns `a` as `const char *`.
     * @param a pointer to struct string
     * @returns return `a` as `const char *`
     */
    const char *(*c_str)(string *a);

    /**
     * Saves `a` at `location`.
     * @param a pointer to struct string
     * @param location where to save
     * @returns 0 if save successfully, otherwise return 1
     */
    int (*save)(string *a, const char *location);

    /**
     * Opens file at `location` and then sets `a` the contents of the file.
     * @param a pointer to struct string
     * @param location file to open
     * @returns 0 if opened successfully, otherwise return 1
     */
    int (*open)(string *a, const char *location);

    /**
     * Clears `a` using `calloc` function defined in <stdlib.h> header.
     * @param a pointer to struct string
     * @returns 0 if cleared successfully, otherwise return 1
     */
    int (*clear)(string *a);

    /**
     * Converts `a` to upper case.
     * @param a pointer to struct string
     */
    void (*to_upper)(string *a);

    /**
     * Converts `a` to lower case.
     * @param a pointer to struct string
     */
    void (*to_lower)(string *a);

    /**
     * Compresses `a` using Run Length Encoding.
     * @param a pointer to struct string
     */
    void (*compress)(string *a);
} __string__;

void _set(string *a, const char *src)
{
    if (a)
    {
        a->str.src = "\0";
        a->str.src = (char *)malloc(sizeof(char) * (strlen(src) + 1));
        strcpy(a->str.src, src);
    }
}

char *_get(string *a)
{
    if (a)
        return a->str.src;
    return (char *)NULL;
}

void _append(string *a, const char *src)
{
    if (a)
    {
        if (strlen((const char *)a->str.src) == 0) // string is empty
        {
            a->str.src = "\0";
            a->str.src = (char *)malloc(sizeof(char) * (strlen(src) + 1));
            strcpy(a->str.src, src); // copy `src` it.
        }
        else
        {
            a->str.src = (char *)realloc(a->str.src, sizeof(char) * (strlen(src) + strlen(a->str.src) + 1));
            strcat(a->str.src, src);
        }
    }
}

int _empty(string *a)
{
    if (a)
        if (strlen((const char *)a->str.src) == 0)
            return true;
    return false;
}

void _replace_char(string *a, const char old, const char new_)
{
    if (a)
    {
        size_t len = strlen((const char *)a->str.src);
        for (size_t i = 0; i < len; ++i)
            if (a->str.src[i] == old)
                a->str.src[i] = new_;
    }
}

void _char_set(string *a, const char what, size_t where)
{
    if (a)
    {
        if (strlen((const char *)a->str.src) > where)
            a->str.src[where] = what;
    }
}

char _char_get(string *a, size_t where)
{
    if (a)
    {
        if (strlen((const char *)a->str.src) > where)
            return a->str.src[where];
    }
    return (char)'\0';
}

size_t _length(string *a)
{
    if (a)
        return strlen((const char *)a->str.src);
    return (size_t)0;
}

size_t _mem_used(string *a)
{
    if (a)
        return ((strlen((const char *)a->str.src)) * (sizeof(__string__)));
    return (long double)0.0f;
}

int _compare(string *a, const char *T1)
{
    if (a)
    {
        if (strcmp((const char *)a->str.src, T1) == true)
            return true;
    }
    return false;
}

void _print(string *a, int add_next_line, const char *__format__, ...)
{
    if (a)
    {
        va_list ar;
        va_start(ar, (const char *)__format__);
        if (add_next_line == true)
            printf("%s\n", a->str.src);
        else
            printf("%s", a->str.src);
        vprintf((const char *)__format__, ar);
        va_end(ar);
        fflush(stdout);
    }
}

void _replace(string *a, const char *old, const char *new_)
{
    char *r;
    size_t i, count_old = 0, len_o = strlen(old), len_n = strlen(new_);
    for (i = 0; a->str.src[i] != '\0'; ++i)
    {
        if (strstr((const char *)&a->str.src[i], old) == &a->str.src[i])
        {
            count_old++;
            i += len_o - 1;
        }
    }
    r = (char *)malloc(sizeof(char) * (i + count_old * (len_n - len_o) + 1));

    i = 0;
    while (*a->str.src)
    {
        if (strstr(a->str.src, old) == a->str.src)
        {
            strcpy(&r[i], new_);
            i += len_n;
            a->str.src += len_o;
        }
        else
            r[i++] = *a->str.src++;
    }
    r[i] = '\0';
    a->str.src = "\0";
    a->str.src = (char *)malloc(sizeof(char) * (strlen((const char *)r) + 1));
    strcpy(a->str.src, (const char *)r);
    free(r);
}

int _destructor(string *a)
{
    if (a && a->str.src)
    {
        free(a->str.src);
        return true;
    }
    return false;
}

const char *_c_str(string *a)
{
    if (a)
        return (const char *)a->str.src;
    return (const char *)NULL;
}

int _save(string *a, const char *location)
{
    if (a && a->str.src && location)
    {
        FILE *f = fopen(location, "w");
        if (f)
        {
            fwrite((const char *)a->str.src, strlen((const char *)a->str.src), sizeof(char), f);
            fclose(f);
            return true;
        }
        fclose(f);
        return false;
    }
    return false;
}

int _open(string *a, const char *location)
{
    if (a && location)
    {
        FILE *f = fopen(location, "r");
        if (f)
        {
            fseek(f, 0, SEEK_END);
            size_t len = ftell(f);
            fseek(f, 0, SEEK_SET);
            a->str.src = (char *)calloc(len + 1, sizeof(char));
            fread(a->str.src, sizeof(char), len, f);
            fclose(f);
            return true;
        }
        fclose(f);
        return false;
    }
    return false;
}

int _clear(string *a)
{
    if (a)
    {
        a->str.src = (char *)calloc(1, sizeof(char));
        return true;
    }
    return false;
}

void _to_upper(string *a)
{
    if (a)
    {
        for (size_t i = 0; i < strlen((const char *)a->str.src); ++i)
        {
            if (a->str.src[i] <= 122 && a->str.src[i] >= 97)
                a->str.src[i] -= 32;
        }
    }
}

void _to_lower(string *a)
{
    if (a)
    {
        for (size_t i = 0; i < strlen((const char *)a->str.src); ++i)
        {
            if (a->str.src[i] <= 90 && a->str.src[i] >= 65)
                a->str.src[i] += 32;
        }
    }
}

void _compress(string *a)
{
    if (a)
    {
        char num[20] = "\0";
        size_t len = strlen((const char *)a->str.src);
        char *buff = (char *)malloc(sizeof(char) * (len * 2 + 1));
        size_t q = 0, cnt = 0;
        for (size_t i = 0; i < len; ++i)
        {
            buff[q++] = a->str.src[i];
            cnt = 1;
            while (i + 1 < len && a->str.src[i] == a->str.src[i + 1])
                cnt++, i++;
            sprintf(num, "%llu", cnt);

            for (size_t k = 0; *(num + k); ++k, ++q)
                buff[q] = num[k];
        }
        buff[q] = '\0';
        a->str.src = "\0";
        a->str.src = (char *)malloc(sizeof(char) * (strlen((const char *)buff) + 1));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
    }
}

void init_str(string *a)
{
    a->set = _set;                   // working
    a->get = _get;                   // working
    a->append = _append;             // working
    a->empty = _empty;               // working
    a->replace_char = _replace_char; // working
    a->char_set = _char_set;         // working
    a->char_get = _char_get;         // working
    a->length = _length;             // working
    a->mem_used = _mem_used;         // working
    a->compare = _compare;           // working
    a->print = _print;               // working
    a->replace = _replace;           // working
    a->destructor = _destructor;     // working
    a->c_str = _c_str;               // working
    a->save = _save;                 // working
    a->open = _open;                 // working
    a->clear = _clear;               // working
    a->to_upper = _to_upper;         // working
    a->to_lower = _to_lower;         // working
    a->compress = _compress;         // working
    // You can add more function to it
    a->str.src = "\0"; // default init instead of some `garbage value`
}
