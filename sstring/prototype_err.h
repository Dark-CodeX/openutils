/**
* This header file is written to solve `prototype` missing error. Do not include this file.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Copyright Tushar Chaurasia
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on github.com
* File: "prototype_err.h" under "sstring" directory
* License: MIT
* sstring: version 3.8.1
*/

#pragma once

void _set(sstring *a, const char *src);
void _set_random(sstring *a, const SIZE_T len);
void _set_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);
char *_get(sstring *a);
void _append(sstring *a, const char *src);
void _append_start(sstring *a, const char *src);
void _append_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);
void _append_start_array(sstring *a, const char *src[], char char_between, SIZE_T from, SIZE_T till, SIZE_T len);
int _empty(sstring *a);
void _replace_char(sstring *a, const char old, const char new_);
void _char_set(sstring *a, const char what, SIZE_T where);
char _char_get(sstring *a, SIZE_T where);
SIZE_T _length(sstring *a);
int _compare(sstring *a, const char *T1);
void _print(sstring *a, int add_next_line, const char *__format__, ...);
void _replace(sstring *a, const char *old, const char *new_);
int _destructor(sstring *a);
const char *_c_str(sstring *a);
int _save(sstring *a, const char *location);
int _open(sstring *a, const char *location);
int _clear(sstring *a);
void _to_upper(sstring *a);
void _to_lower(sstring *a);
int _is_initialized(sstring *a);
void _to_binary(sstring *a);
int _from_binary(sstring *a);
long double _entropy(sstring *a);
int _contains(sstring *a, const char *str);
void _to_set(sstring *a);
int _copy(sstring *a, sstring *dest);
void _to_hexadecimal(sstring *a);
int _from_hexadecimal(sstring *a);
signed long long _find(sstring *a, const char *sub);

void init_sstr(sstring *a);
void init_sstr_array(sstring *a[], SIZE_T len);