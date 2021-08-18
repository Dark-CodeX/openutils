#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 0
#define false 1

typedef struct __str__
{
    char *src; // Do not modify it directly (segfault)
} __str__;

typedef struct __string__ string;
struct __string__
{
    __str__ str;
    void (*set)(string *, const char *);
    char *(*get)(string *);
    void (*append)(string *, const char *);
    int (*empty)(string *);
    void (*replace_char)(string *, const char, const char); /* Linear time complexity, O(n), where n is the length of the char array. */
    void (*char_set)(string *, const char, size_t);
    char (*char_get)(string *, size_t);
    size_t (*length)(string *);
    long double (*mem_used)(string *); /* returns memory used in mB (Mebibyte(s)) */
    int (*compare)(string *, const char *);
    void (*print)(string *, int);
    void (*replace)(string *, const char *, const char *);

} __string__;

void _set(string *a, const char *src)
{
    if (a)
    {
        a->str.src = (char *)malloc(strlen(src));
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
            a->str.src = (char *)malloc(strlen(src));
            strcpy(a->str.src, src); // copy `src` it.
        }
        else
            strcat(a->str.src, src); // append `src`.
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

long double _mem_used(string *a)
{
    if (a)
        return (strlen((const char *)a->str.src) / 1048576.0f);
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

void _print(string *a, int add_next_line)
{
    if (a)
    {
        if (add_next_line == true)
            printf("%s\n", a->str.src);
        else
            printf("%s", a->str.src);
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
    r = (char *)malloc(i + count_old * (len_n - len_o) + 1);

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
    a->str.src = (char *)malloc(strlen(r));
    strcpy(a->str.src, r);
    free(r);
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
    // You can add more function to it
    a->str.src = "\0";               // default init instead of some `garbage value`
}