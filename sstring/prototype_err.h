/**
* This header file is written to solve `prototype` missing error. Do not include this file.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "prototype_err.h" under "sstring" directory
* sstring: version 7.7.3
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

#pragma once

void _set(sstring *a, const char *src);
void _set_char(sstring *a, const char c);
void _set_upto(sstring *a, const char *src, SIZE_T N);
void _set_random(sstring *a, const SIZE_T len);
void _set_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);
char *_get(sstring *a);
void _append(sstring *a, const char *src);
void _append_char(sstring *a, const char c);
void _append_upto(sstring *a, const char *src, SIZE_T N);
void _append_start(sstring *a, const char *src);
void _append_start_char(sstring *a, const char src);
void _append_start_upto(sstring *a, const char *src, SIZE_T N);
void _append_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);
void _append_start_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);
int _empty(sstring *a);
void _replace_char(sstring *a, const char old, const char new_);
void _char_set(sstring *a, const char what, SIZE_T where);
char _char_get(sstring *a, SIZE_T where);
SIZE_T _length(sstring *a);
int _compare(sstring *a, const char *T1);
int _compare_upto(sstring *a, const char *T1, SIZE_T N);
void _print(sstring *a, int add_next_line, const char *__format__, ...);
void _replace(sstring *a, const char *old, const char *new_);
int _destructor(sstring *a);
const char *_c_str(sstring *a);
int _save(sstring *a, const char *location);
int _open(sstring *a, const char *location);
int _clear(sstring *a);
void _to_upper(sstring *a);
void _to_lower(sstring *a);
void _swap_case(sstring *a);
int _is_initialized(sstring *a);
void _to_binary(sstring *a);
int _from_binary(sstring *a);
long double _entropy(sstring *a);
int _contains(sstring *a, const char *str);
signed long long int _contains_char(sstring *a, const char c);
void _to_set(sstring *a);
int _copy(sstring *a, sstring *dest);
void _to_hexadecimal(sstring *a);
int _from_hexadecimal(sstring *a);
signed long long _find(sstring *a, const char *sub);
int _in(sstring *a, int get_line, SIZE_T buff_size);
char *_getline(sstring *a, SIZE_T line);
void _reverse(sstring *a);
int _remove_range(sstring *a, SIZE_T from, SIZE_T till);
int _intersect(sstring *a, SIZE_T from, SIZE_T till);
signed long long int _distance(sstring *a, const char *src);
signed long long int _edit_distance(sstring *a, const char *src);
long double _percentage_matched(sstring *a, const char *src);
SIZE_T _count(sstring *a, const char *what);
SIZE_T _count_char(sstring *a, const char what);

void init_sstr(sstring *a);