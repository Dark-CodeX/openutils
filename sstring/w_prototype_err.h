/**
* This header file is written to solve `prototype` missing error. Do not include this file.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Copyright Tushar Chaurasia 2021 - 2022.
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "w_prototype_err.h" under "sstring" directory
* sstring: version 3.5.1
*/

#pragma once

void _w_set(w_sstring *a, const wchar_t *src);
void _w_set_random(w_sstring *a, const SIZE_T len);
void _w_set_array(w_sstring *a, const wchar_t *src[], wchar_t char_between, SIZE_T from, SIZE_T till, SIZE_T len);
wchar_t *_w_get(w_sstring *a);
void _w_append(w_sstring *a, const wchar_t *src);
void _w_append_start(w_sstring *a, const wchar_t *src);
void _w_append_array(w_sstring *a, const wchar_t *src[], wchar_t char_between, SIZE_T from, SIZE_T till, SIZE_T len);
void _w_append_start_array(w_sstring *a, const wchar_t *src[], wchar_t char_between, SIZE_T from, SIZE_T till, SIZE_T len);
int _w_empty(w_sstring *a);
void _w_replace_char(w_sstring *a, const wchar_t old, const wchar_t new_);
void _w_char_set(w_sstring *a, const wchar_t what, SIZE_T where);
wchar_t _w_char_get(w_sstring *a, SIZE_T where);
SIZE_T _w_length(w_sstring *a);
int _w_compare(w_sstring *a, const wchar_t *T1);
void _w_print(w_sstring *a, int add_next_line, const char *__format__, ...);
void _w_replace(w_sstring *a, const wchar_t *old, const wchar_t *new_);
int _w_destructor(w_sstring *a);
const wchar_t *_w_c_str(w_sstring *a);
int _w_save(w_sstring *a, const char *location);
int _w_open(w_sstring *a, const char *location);
int _w_clear(w_sstring *a);
void _w_to_upper(w_sstring *a);
void _w_to_lower(w_sstring *a);
int _w_is_initialized(w_sstring *a);
void _w_to_binary(w_sstring *a);
int _w_from_binary(w_sstring *a);
long double _w_entropy(w_sstring *a);
int _w_contains(w_sstring *a, const wchar_t *str);
void _w_to_set(w_sstring *a);
int _w_copy(w_sstring *a, w_sstring *dest);

void init_w_sstr(w_sstring *a);
void init_w_sstr_array(w_sstring *a[], SIZE_T len);