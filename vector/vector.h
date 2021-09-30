#pragma once

/**
* This header file is written to create vectors in C, like we do in C++.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/vector.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "vector.h" under "vector" directory
* vector: version 4.0.0
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
typedef struct __vector__ vector;

#define vector_version "4.0.0"

#include <stdlib.h>

#define true 0
#define false 1
typedef unsigned long long int SIZE_T;

/**
 * This struct is made to store double-pointer void and it's initialized value.
 * Do not use this directly, instead use `vector` struct.
 */
typedef struct _vec_
{
    /* Do not modify it directly (segfault), most probably and use 'v.destructor(&v);' at the end */
    void **src;
    /* Do not change this value. */
    int init;
    /* Do not change this value. */
    SIZE_T len;
} _vec_;

struct __vector__
{
    /* Do not use this. */
    _vec_ vec;

    /**
     * Appends `data` to `v` at the end.
     * @param v pointer to struct vector
     * @param data data to append
     * @returns true if appended successfully, otherwise false
     */
    int (*append)(vector *v, void *data);

    /**
     * Appends `data` to `v` at the start.
     * @param v pointer to struct vector
     * @param data data to append
     * @returns true if appended successfully, otherwise false
     */
    int (*append_start)(vector *v, void *data);

    /**
     * Returns the length of `v`.
     * @returns length of `v`.
     */
    SIZE_T(*length)
    (vector *v);

    /**
     * Returns data at `index` from `v`.
     * @param v pointer to struct vector
     * @param index index of the data
     * @returns data at `index`
     */
    void *(*get)(vector *v, SIZE_T index);

    /**
     * Assigns `data` at `index`.
     * @param v pointer to struct vector
     * @param index index of the data
     * @param data data to assign
     * @returns true if assigned successfully, otherwise false
     */
    int (*set)(vector *v, SIZE_T index, void *data);

    /**
     * Removes data at `index` from `v`.
     * @param v pointer to struct vector
     * @param index index of the data to be removed
     * @returns true if removed successfully, otherwise false
     */
    int (*remove)(vector *v, SIZE_T index);

    /**
     * Clears the vector `v`.
     * @param v pointer to struct vector
     * @returns true if cleared successfully, otherwise false
     */
    int (*clear)(vector *v);

    /**
     * Returns whether `v` is initialized or not using `vec_init` function.
     * @param v pointer to struct vector
     * @returns true if initialized successfully, otherwise return nothing because this method have to be initialized using `vec_init` function. Use `__is_initialized` function to get a result i.e, true or false.
     */
    int (*is_initialized)(vector *v);

    /**
     * Free `v->vec.src`. Do not forget to use this function at the end.
     * @param v pointer to struct vector
     * @returns true if freed successfully, otherwise false
     */
    int (*destructor)(vector *v);

    /**
     * Swaps `v[x1]` with `v[x2]` and vice-versa.
     * @param v pointer to struct vector
     * @param x1 data to be swaped
     * @param x2 data to be swaped
     * @returns true if swaped successfully, otherwise false
     */
    int (*swap)(vector *v, SIZE_T x1, SIZE_T x2);

    /**
     * Reverse `v` means `v[0]` = `v[n]`, `v[n]` = `v[0]` and so on. NOTE: n is the length of `v`.
     * @param v pointer to struct vector
     * @returns true if reversed successfully, otherwise false
     */
    int (*reverse)(vector *v);

    /**
     * Finds `data` in `v` using `compare` function.
     * @param v pointer to struct vector
     * @param data data to find
     * @param compare function to be used to compare `v[i]` and `data`. NOTE: i is the iterator.
     * @returns index of `data` if found, otherwise -1
     */
    signed long long int (*find)(vector *v, void *data, int (*compare)(void *, void *));
    
    /**
     * Returns whether `v` is empty or not.
     * @param v pointer to struct vector
     * @returns true if empty, otherwise false
     */
    int (*empty)(vector *v);
} __vector__;

#include "prototype_err.h"

int __append(vector *v, void *data)
{
    if (v && data && v->vec.init == true && v->vec.src)
    {
        v->vec.src = (void **)realloc(v->vec.src, (v->vec.len * sizeof(void *)) + sizeof(void *));
        v->vec.src[v->vec.len] = data;
        v->vec.len++;
        return true;
    }
    return false;
}

int __append_start(vector *v, void *data)
{
    if (v && data && v->vec.init == true && v->vec.src)
    {
        v->vec.src = (void **)realloc(v->vec.src, (v->vec.len * sizeof(void *)) + sizeof(void *));
        void *temp = v->vec.src[0], *tmp;
        for (SIZE_T i = 1; i < v->vec.len + 1; i++)
        {
            tmp = v->vec.src[i];
            v->vec.src[i] = temp;
            temp = tmp;
        }
        v->vec.src[0] = data;
        v->vec.len++;
        return true;
    }
    return false;
}

SIZE_T __length(vector *v)
{
    if (v && v->vec.init == true && v->vec.src)
        return v->vec.len;
    return 0;
}

void *__get(vector *v, SIZE_T index)
{
    if (v && v->vec.init == true && v->vec.src && index < v->vec.len)
        return v->vec.src[index];
    return NULL;
}

int __set(vector *v, SIZE_T index, void *data)
{
    if (v && v->vec.init == true && v->vec.src && index < v->vec.len && data)
    {
        v->vec.src[index] = data;
        return true;
    }
    return false;
}

int __remove(vector *v, SIZE_T index)
{
    if (v && v->vec.init == true && v->vec.src && index < v->vec.len)
    {
        v->vec.src[index] = NULL;
        for (SIZE_T i = index; i < v->vec.len - 1; i++)
        {
            v->vec.src[i] = v->vec.src[i + 1];
            v->vec.src[i + 1] = NULL;
        }
        v->vec.src = (void **)realloc(v->vec.src, (v->vec.len * sizeof(void *)) - sizeof(void *));
        v->vec.len--;
        return true;
    }
    return false;
}

int __clear(vector *v)
{
    if (v && v->vec.init == true && v->vec.src)
    {
        free(v->vec.src);
        v->vec.src = (void **)calloc(sizeof(void *) * 1, sizeof(void *));
        v->vec.len = 0;
        return true;
    }
    return false;
}

int __is_initialized(vector *v)
{
    if (v)
        if (v->vec.init == true)
            return true;
    return false;
}

int __destructor(vector *v)
{
    if (v && v->vec.init == true && v->vec.src)
    {
        free(v->vec.src);
        return true;
    }
    return false;
}

int __swap(vector *v, SIZE_T x1, SIZE_T x2)
{
    if (v && v->vec.init == true && v->vec.src && x1 < v->vec.len && x2 < v->vec.len)
    {
        void *temp = v->vec.src[x1];
        v->vec.src[x1] = v->vec.src[x2];
        v->vec.src[x2] = temp;
        return true;
    }
    return false;
}

int __reverse(vector *v)
{
    if (v && v->vec.init == true && v->vec.src)
    {
        void *c = NULL;
        for (SIZE_T i = 0; i < v->vec.len / 2; i++)
        {
            c = v->vec.src[i];
            v->vec.src[i] = v->vec.src[v->vec.len - i - 1];
            v->vec.src[v->vec.len - i - 1] = c;
        }
        return true;
    }
    return false;
}

signed long long int __find(vector *v, void *data, int (*compare)(void *, void *))
{
    if (v && data && v->vec.init == true && v->vec.src)
    {
        for (SIZE_T i = 0; i < v->vec.len; i++)
            if (compare(v->vec.src[i], data) == true)
                return (SIZE_T)i;
    }
    return -1;
}

int __empty(vector *v)
{
    if (v && v->vec.init == true && v->vec.src)
        if (v->vec.len == 0)
            return true;
    return false;
}

/**
 * Shortcut for initializing a `vector` struct.
 * @param x vector name or variable name
 */
#define VECTOR(x) \
    vector x;     \
    vec_init(&x);

/**
 * Always use this function after any `vector` declaration. 
 * This function initializes `v`. 
 * By the way use `VECTOR(x)` macro for shortcut.
 * @param a pointer to struct vector
 */
void vec_init(vector *v)
{
    v->append = __append;
    v->append_start = __append_start;
    v->length = __length;
    v->get = __get;
    v->set = __set;
    v->remove = __remove;
    v->clear = __clear;
    v->is_initialized = __is_initialized;
    v->destructor = __destructor;
    v->swap = __swap;
    v->reverse = __reverse;
    v->find = __find;
    v->empty = __empty;

    v->vec.src = (void **)calloc(sizeof(void *) * 1, sizeof(void *));
    v->vec.len = 0; // contains nothing
    v->vec.init = true; // initialized properly
}