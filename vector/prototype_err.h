/**
* This header file is written to solve `prototype` missing error. Do not include this file.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/vector.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "prototype_err.h" under "vector" directory
* vector: version 5.0.0
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

#pragma once

int __append(vector *v, void *data);
int __append_start(vector *v, void *data);
SIZE_T __length(vector *v);
void *__get(vector *v, SIZE_T index);
int __set(vector *v, SIZE_T index, void *data);
int __remove(vector *v, SIZE_T index);
int __clear(vector *v);
int __is_initialized(vector *v);
int __destructor(vector *v);
int __swap(vector *v, SIZE_T x1, SIZE_T x2);
int __reverse(vector *v);
signed long long int __find(vector *v, void *data, int (*compare)(void *, void *));
int __empty(vector *v);
int __copy(vector *src, vector *dest);
SIZE_T __compare(vector *v, vector *v1, int (*compare)(void *, void *));

void vec_init(vector *v);