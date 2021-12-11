#ifndef __cplusplus

#pragma once

/**
 * This header file is written to create vectors in C, like we do in C++.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/vector.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "vector.h" under "vector" directory
 * vector version: 1.5.3
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

#include <stdlib.h>
#include <stdbool.h>

#define vector_version "1.5.3"

/**
 * Appends `data` to `vec` at the end.
 * @param vec vector
 * @param data data to append
 */
#define vector_add(vec, data)                                                         \
    if (vec.init == true && vec.src && sizeof(vec._def[0]) == sizeof(data))           \
    {                                                                                 \
        if (vec.length == vec.capacity)                                               \
        {                                                                             \
            vec.capacity *= 3;                                                        \
            vec.src = realloc(vec.src, (vec.capacity * sizeof(data)) + sizeof(data)); \
        }                                                                             \
        vec.src[vec.length++] = data;                                                 \
    }

/**
 * Removes data at `index` from `vec`.
 * @param vec vector
 * @param index index of the data to be removed
 */
#define vector_remove(vec, index)                          \
    if (vec.init == true && vec.src && index < vec.length) \
    {                                                      \
        vec.src[index] = vec._def[0];                      \
        for (size_t i = index; i < vec.length - 1; i++)    \
        {                                                  \
            vec.src[i] = vec.src[i + 1];                   \
            vec.src[i + 1] = vec._def[0];                  \
        }                                                  \
        vec.length--;                                      \
    }

/**
 * Returns `vec`'s length
 * @param vec vector
 */
#define vector_length(vec) (vec.src && vec.init == true) ? vec.length : 0

/**
 * Returns whether `vec` is empty or not.
 * @param vec vector
 * @returns true if empty, otherwise false
 */
#define vector_empty(vec) (vec.src && vec.init == true && vec.length == 0) ? true : false

/**
 * Clears `vec` (removes all the data). NOTE: if `v`'s elements are pointers then it will not be freed, you will have to free it.
 * @param vec vector
 */
#define vector_clear(vec)                                               \
    if (vec.init == true && vec.src)                                    \
    {                                                                   \
        free(vec.src);                                                  \
        vec.capacity = 10;                                               \
        vec.length = 0;                                                 \
        vec.src = calloc(sizeof(vec._def[0]) * 10, sizeof(vec._def[0])); \
    }

/**
 * Returns data at `index` from `vec`.
 * @param vec vector
 * @param index index of the data
 * @returns data at `index`, if `index` is larger than `vec`'s length than default value of vector's data type is returned
 */
#define vector_get(vec, index) \
    (vec.init == true && vec.src && index < vec.length) ? vec.src[index] : vec._def[0]

/**
 * Assigns `data` at `index` in `vec`.
 * @param vec vector
 * @param data data to assign
 * @param index index of the data
 */
#define vector_set(vec, data, index)                                                              \
    if (vec.init == true && vec.src && index < vec.length && sizeof(vec._def[0]) == sizeof(data)) \
        vec.src[index] = data;

/**
 * Swaps `vec[x1]` with `vec[x2]` and vice-versa.
 * @param vec vector
 * @param x1 data to be swaped
 * @param x2 data to be swaped
 * @param type data type eg. int, char *, long, float
 */
#define vector_swap(vec, type, x1, x2)                                     \
    if (vec.init == true && vec.src && x1 < vec.length && x2 < vec.length) \
    {                                                                      \
        type x = vec.src[x1];                                              \
        vec.src[x1] = vec.src[x2];                                         \
        vec.src[x2] = x;                                                   \
    }

/**
 * Free `vec.src`. Do not forget to use this function at the end.
 * NOTE: if `vec`'s elements are pointers then it will not be freed, you will have to free it.
 * @param vec vector
 */
#define vector_destructor(vec)       \
    if (vec.init == true && vec.src) \
    {                                \
        free(vec.src);               \
        vec.length = 0;              \
        vec.init = false;            \
    }

/**
 * Reverse `vec` means `vec[0]` = `vec[n]`, `vec[n]` = `vec[0]` and so on. NOTE: n is the length of `vec`.
 * @param vec vector
 * @param type data type eg. int, char *, long, float
 */
#define vector_reverse(vec, type)                     \
    if (vec.init == true && vec.src)                  \
    {                                                 \
        type c;                                       \
        for (size_t i = 0; i < vec.length / 2; i++)   \
        {                                             \
            c = vec.src[i];                           \
            vec.src[i] = vec.src[vec.length - i - 1]; \
            vec.src[vec.length - i - 1] = c;          \
        }                                             \
    }

/**
 * Finds `data` in `vec`.
 * @param vec vector
 * @param data data to find
 * @param result stores the result (index at which `data` was found, if not found -1 is assigned to `result`). NOTE: `result` data type should be `signed long long int`
 */
#define vector_find(vec, data, result)                                                                                        \
    if (vec.init == true && vec.src && sizeof(vec._def[0]) == sizeof(data) && sizeof(result) == sizeof(signed long long int)) \
    {                                                                                                                         \
        for (size_t i = 0; i < vec.length; i++)                                                                               \
        {                                                                                                                     \
            if (vec.src[i] == data)                                                                                           \
            {                                                                                                                 \
                result = i;                                                                                                   \
                break;                                                                                                        \
            }                                                                                                                 \
            else                                                                                                              \
                result = -1;                                                                                                  \
        }                                                                                                                     \
    }

/**
 * Copies `vec`'s data to `vec2`. NOTE: `vec2` data type should be same as of `vec`'s data type.
 * @param vec vector
 * @param vec2 vector
 */
#define vector_copy(vec, vec2)                                                                                       \
    if (vec.init == true && vec.src && vec2.init == true && vec2.src && sizeof(vec._def[0]) == sizeof(vec2._def[0])) \
    {                                                                                                                \
        free(vec2.src);                                                                                              \
        vec2.src = calloc(sizeof(vec2._def[0]) * vec.length, sizeof(vec2._def[0]));                                  \
        for (size_t i = 0; i < vec.length; i++)                                                                      \
            vec2.src[vec2.length++] = vec.src[i];                                                                    \
    }

/**
 * Returns whether `vec` is initialized or not using.
 * @param vec vector
 */
#define vector_is_initialized(vec) (vec.init == true) ? true : false

/**
 * Compares `vec` against `vec2` iteratively. NOTE: length of both vectors should be same
 * @param vec vector
 * @param vec2 vector
 * @param result if assigned value is true then, `vec` and `vec2` are same. NOTE: `result` data type should be `int`
 */
#define vector_compare(vec, vec2, result)                                                                                                                                              \
    if (sizeof(result) == sizeof(int) && vec.init == true && vec.src && vec2.init == true && vec2.src && (vec.length == vec2.length) && (sizeof(vec._def[0]) == sizeof(vec2._def[0]))) \
    {                                                                                                                                                                                  \
        for (size_t i = 0; i < vec.length; i++)                                                                                                                                        \
            if (vec.src[i] != vec2.src[i])                                                                                                                                             \
            {                                                                                                                                                                          \
                result = false;                                                                                                                                                        \
                break;                                                                                                                                                                 \
            }                                                                                                                                                                          \
            else                                                                                                                                                                       \
                result = true;                                                                                                                                                         \
    }                                                                                                                                                                                  \
    else                                                                                                                                                                               \
        result = vec.length;

/**
 * Inserts `data` at `nth` by moving items forward.
 * @param vec vector
 * @param data data to insert
 * @param nth where to insert
 */
#define vector_insert(vec, data, nth)                                                 \
    if (nth <= vec.length)                                                            \
    {                                                                                 \
        if (vec.length == vec.capacity)                                               \
        {                                                                             \
            vec.capacity *= 3;                                                        \
            vec.src = realloc(vec.src, (vec.capacity * sizeof(data)) + sizeof(data)); \
        }                                                                             \
        for (size_t i = vec.length; i >= nth; i--)                                    \
        {                                                                             \
            vec.src[i + 1] = vec.src[i];                                              \
            vec.src[i] = vec._def[0];                                                 \
            if (i == 0)                                                               \
                break;                                                                \
        }                                                                             \
        vec.src[nth] = data;                                                          \
        vec.length++;                                                                 \
    }

/**
 * Macro for initializing a `vector` struct.
 * @param var_name vector name or variable name
 * @param type data type eg. int, char *, long, float or even a struct
 */
#define vector(var_name, type)                                                     \
    struct var_name                                                                \
    {                                                                              \
        type *src;                                                                 \
        size_t length;                                                             \
        size_t capacity;                                                           \
        int init;                                                                  \
        type _def[1];                                                              \
    } var_name;                                                                    \
    var_name.capacity = 10;                                                         \
    var_name.src = (type *)calloc(sizeof(type) * var_name.capacity, sizeof(type)); \
    var_name.length = 0;                                                           \
    var_name.init = true;

#endif