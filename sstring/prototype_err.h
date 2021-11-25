/**
* This header file is written to solve `prototype` missing error. Do not include this file.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "prototype_err.h" under "sstring" directory
* sstring: version 49.0.0
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

void fast_strncat(char *dest, const char *src, size_t *size);

void _set(sstring *a, const char *src);
void _set_char(sstring *a, const char c);
void _set_upto(sstring *a, const char *src, size_t N);
void _set_random(sstring *a, const size_t len);
void _set_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);
char *_get(sstring *a);
void _append(sstring *a, const char *src);
void _append_char(sstring *a, const char c);
void _append_upto(sstring *a, const char *src, size_t N);
void _append_start(sstring *a, const char *src);
void _append_start_char(sstring *a, const char src);
void _append_start_upto(sstring *a, const char *src, size_t N);
void _append_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);
void _append_start_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);
int _empty(sstring *a);
void _replace_char(sstring *a, const char old, const char new_);
void _char_set(sstring *a, const char what, size_t where);
char _char_get(sstring *a, size_t where);
size_t _length(sstring *a);
int _compare(sstring *a, const char *T1);
int _compare_upto(sstring *a, const char *T1, size_t N);
void _print(sstring *a, int add_next_line, const char *__format__, ...);
void _replace(sstring *a, const char *old, const char *new_);
int _destructor(sstring *a);
const char *_c_str(sstring *a);
int _save(sstring *a, const char *location);
int _append_file(sstring *a, const char *location);
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
int _in(sstring *a, int get_line, size_t buff_size);
char *_getline(sstring *a, size_t line);
void _reverse(sstring *a);
size_t _remove(sstring *a, const char *sub);
size_t _remove_char(sstring *a, const char c);
size_t _remove_extra_char(sstring *a, const char c);
size_t _remove_range(sstring *a, size_t from, size_t till);
int _intersect(sstring *a, size_t from, size_t till);
signed long long int _distance(sstring *a, const char *src);
signed long long int _edit_distance(sstring *a, const char *src);
long double _percentage_matched(sstring *a, const char *src);
long double _positional_average(sstring *a);
size_t _positional_modulus(sstring *a);
size_t _count(sstring *a, const char *what);
size_t _count_char(sstring *a, const char what);
char *_soundex(sstring *a);
char *_most_used(sstring *a);
char _most_used_char(sstring *a);
split_t _split(sstring *a, const char *dl);
void _sort(sstring *a);
size_t _open_binary(sstring *a, const char *location);
int _save_binary(sstring *a, const char *location, size_t len);
int _append_binary(sstring *a, const char *location, size_t len);
size_t _add_binary(sstring *a, const char *data, size_t len);
int _print_binary(sstring *a, size_t len);
int _encrypt(sstring *a, const char *key);
int _decrypt(sstring *a, const char *key);
size_t _begin(void);
iter_sstring _iterator(signed long long int init_value, signed long long int max_value);
size_t _end_sstring(sstring *a);
int _to_morse_code(sstring *a);
int _from_morse_code(sstring *a);
int _is_digit(sstring *a);
int _is_decimal(sstring *a);
int _is_ascii(sstring *a);
int _is_alphabetic(sstring *a);
int _format_escape_sequence(sstring *a);
int _insert(sstring *a, const char *src, size_t index);
int _starts_with(sstring *a, const char *src);
int _ends_with(sstring *a, const char *src);
parse_t _parse(sstring *a);
int _from_parse_t(sstring *a, parse_t *toks);
int _set_formatted(sstring *a, size_t buffer_length, const char *__format__, ...);
int _append_formatted(sstring *a, size_t buffer_length, const char *__format__, ...);
int _resize(sstring *a, size_t new_len);

void __advance__iter_sstring(iter_sstring *is, signed long long int move_by);
int __c_loop__iter_sstring(iter_sstring *is);

int strcmp_void(const void *a1, const void *a2);
const char *char_to_esc_seq(char c);
const char *esc_seq_to_char_ptr(const char *c);
int free_parse(parse_t *a);
int free_split(split_t *a);
void merge(char *arr, size_t l, size_t m, size_t r);
void merge_sort(char *arr, size_t l, size_t r);
sstring new_sstring(size_t alloc_size, const char *src);
int init_sstr(sstring *a, size_t alloc_size);