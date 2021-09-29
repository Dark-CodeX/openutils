#pragma once

/**
* This header file is written to create vectors in C, like we do in C++.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/vector.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "vector.h" under "vector" directory
* vector: version 1.0.0
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

#define vector_version "1.0.0"

#include <stdlib.h>

#define true 0
#define false 1
typedef unsigned long long int SIZE_T;

typedef struct _vec_
{
    void **src;
    int init;
    SIZE_T len;
} _vec_;

struct __vector__
{
    _vec_ vec;
    int (*append)(vector *v, void *data);
    int (*append_start)(vector *v, void *data);
    SIZE_T(*length)
    (vector *v);
    void *(*get)(vector *v, SIZE_T index);
    int (*set)(vector *v, SIZE_T index, void *data);
    int (*remove)(vector *v, SIZE_T index);
    int (*clear)(vector *v);
    int (*is_initialized)(vector *v);
    int (*destructor)(vector *v);
    int (*swap)(vector *v, SIZE_T x1, SIZE_T x2);
    int (*reverse)(vector *v);
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

#define VECTOR(x) \
    vector x;     \
    vec_init(&x);

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

    v->vec.src = (void **)calloc(sizeof(void *) * 1, sizeof(void *));
    v->vec.len = 0;
    v->vec.init = true;
}