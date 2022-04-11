/**
 * This header file is written to solve `prototype` missing error. Do not include this file.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/map.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "prototype_err.h" under "map" directory
 * map: version 1.6.2
 *
 * MIT License
 *
 * Copyright (c) 2022 Tushar Chaurasia
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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF oANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __cplusplus

#pragma once

void make_null_array(void **ptr, size_t len);
size_t _get_hash_map_t(map_t *map, void *key, size_t capacity);

void _rehash_map_t(map_t *map);

int _add_map_t(map_t *map, void *key, void *value);
int _add_node_map_t(map_t *map, node_t *node);
int _remove_map_t(map_t *map, void *key);
int _remove_node_map_t(map_t *map, node_t *node);
int _contains_map_t(map_t *map, void *key);
int _contains_node_map_t(map_t *map, node_t *node);
void *_get_map_t(map_t *map, void *key);
node_t *_get_node_map_t(map_t *map, void *key);
size_t _get_index_map_t(map_t *map, void *key);
size_t _get_index_node_map_t(map_t *map, node_t *node);
void _erase_map_t(map_t *map);
void _sort_map_t(map_t *map, int (*compt)(const void *a, const void *b));
int _empty_map_t(map_t *map);
size_t _length_map_t(map_t *map);
size_t _capacity_map_t(map_t *map);
long double _error_rate_map_t(map_t *map, size_t expected_size);
int _c_loop_iter_map_t(iter_map_t *iter);
node_t *_get_iter_map_t(iter_map_t *iter);
const node_t *_cget_iter_map_t(iter_map_t *iter);
void _next_iter_map_t(iter_map_t *iter);

iter_map_t _iterator_map_t(map_t *map);

void hash_combine_map_t(map_t *map, size_t *seed, void *key, void *value);

size_t _hash_map_t(map_t *map);
int _compare_map_t(map_t *map, map_t *map2);
int _compare_hash_map_t(map_t *map, map_t *map2);
size_t _max_depth_map_t(map_t *map);
void _copy_map_t(map_t *src, map_t *dest);
void _destructor_map_t(map_t *map);

map_t new_map_t(size_t (*get_key_hash)(void *key), size_t (*get_value_hash)(void *value), int (*equal)(void *key1, void *key2), size_t size_of_key, size_t size_of_val);
int map_init(map_t *map, size_t capacity, float load_factor, size_t (*get_key_hash)(void *key), size_t (*get_value_hash)(void *value), int (*equal)(void *key1, void *key2), size_t size_of_key, size_t size_of_val);
#endif