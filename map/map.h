/**
 * This header file is written to create maps in C language.
 * Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
 * Commit to this repository at https://github.com/Dark-CodeX/map.git
 * You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
 * File: "map.h" under "map" directory
 * map version: 1.6.5
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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __cplusplus

#ifndef MAP_T
#define MAP_T

#define map_t_version "1.6.5"

#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t node_t;
struct node_t
{
	void *key;
	void *value;
	struct node_t *next;
};

typedef struct iter_map_t iter_map_t;

typedef struct map_t map_t;
struct map_t
{
	// private members and variables
	size_t cap, len, kcap, klen, size_key, size_val;
	float load_factor;
	size_t (*key_type_hash)(void *key);
	size_t (*value_type_hash)(void *value);
	size_t (*get_hash)(map_t *map, void *key, size_t capacity);
	int (*equal)(void *key1, void *key2);
	void (*rehash)(map_t *map);
	node_t **table;
	void **keys;
	char init;

	// public functions
	int (*add)(map_t *map, void *key, void *value);
	int (*add_node)(map_t *map, node_t *node);
	int (*remove)(map_t *map, void *key);
	int (*remove_node)(map_t *map, node_t *node);
	int (*contains)(map_t *map, void *key);
	int (*contains_node)(map_t *map, node_t *node);
	void *(*get)(map_t *map, void *key);
	node_t *(*get_node)(map_t *map, void *key);
	size_t (*get_index)(map_t *map, void *key);
	size_t (*get_index_node)(map_t *map, node_t *node);
	void (*erase)(map_t *map);
	void (*sort)(map_t *map, int (*compt)(const void *a, const void *b));
	int (*empty)(map_t *map);
	size_t (*length)(map_t *map);
	size_t (*capacity)(map_t *map);
	long double (*error_rate)(map_t *map, size_t expected_size);
	iter_map_t (*iterator)(map_t *map);
	size_t (*hash)(map_t *map);
	int (*compare)(map_t *map, map_t *map2);
	int (*compare_hash)(map_t *map, map_t *map2);
	size_t (*max_depth)(map_t *map);
	void (*copy)(map_t *src, map_t *dest);
	void (*destructor)(map_t *map);
	size_t nerr;
};

struct iter_map_t
{
	// private
	map_t *m;
	node_t *curr;
	size_t index;

	// public
	int (*c_loop)(iter_map_t *iter);
	node_t *(*get)(iter_map_t *iter);
	const node_t *(*cget)(iter_map_t *iter);
	void (*next)(iter_map_t *iter);
};

#include "prototype_err.h"

void make_null_array(void **ptr, size_t len)
{
	if (!ptr)
		return;
	for (size_t i = 0; i < len; i++)
		ptr[i] = (void *)NULL;
}

size_t _get_hash_map_t(map_t *map, void *key, size_t capacity)
{
	if (!map)
		return (size_t)-1;
	return map->key_type_hash(key) % capacity;
}

void _rehash_map_t(map_t *map)
{
	if (!map)
		return;
	size_t new_cap = map->cap * 2;
	node_t **new_table = (node_t **)malloc(sizeof(node_t *) * new_cap);
	make_null_array((void **)new_table, new_cap);
	for (size_t i = 0; i < map->cap; i++)
	{
		node_t *cur = map->table[i];
		while (cur != NULL)
		{
			size_t hash = map->get_hash(map, cur->key, new_cap);
			node_t *next = cur->next;
			cur->next = new_table[hash];
			new_table[hash] = cur;
			cur = next;
		}
	}
	free(map->table);
	map->table = new_table;
	map->cap = new_cap;
}

int _add_map_t(map_t *map, void *key, void *value)
{
	if (!map)
		return false;
	size_t hash = map->get_hash(map, key, map->cap);
	node_t *cur = map->table[hash];
	while (cur != NULL)
	{
		if (map->equal(cur->key, key))
			return false;
		cur = cur->next;
	}
	map->keys[map->klen++] = key;
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->key = key;
	new_node->value = value;
	new_node->next = map->table[hash];
	map->table[hash] = new_node;
	map->len++;
	if (map->len >= map->cap * map->load_factor)
		map->rehash(map);
	if (map->klen >= map->kcap)
	{
		map->kcap *= 2;
		map->keys = (void **)realloc(map->keys, map->kcap * map->size_key);
	}
	return true;
}

int _add_node_map_t(map_t *map, node_t *node)
{
	if (!map || !node)
		return false;
	return map->add(map, node->key, node->value);
}

int _remove_map_t(map_t *map, void *key)
{
	if (!map)
		return false;
	size_t hash = map->get_hash(map, key, map->cap);
	node_t *cur = map->table[hash];
	node_t *prev = NULL;
	while (cur != NULL)
	{
		if (map->equal(cur->key, key))
		{
			if (prev == NULL)
				map->table[hash] = cur->next;
			else
				prev->next = cur->next;
			free(cur);
			map->len--;
			return true;
		}
		prev = cur;
		cur = cur->next;
	}
	return false;
}

int _remove_node_map_t(map_t *map, node_t *node)
{
	if (!map || !node)
		return false;
	return map->remove(map, node->key);
}

int _contains_map_t(map_t *map, void *key)
{
	if (!map)
		return false;
	size_t hash = map->get_hash(map, key, map->cap);
	node_t *cur = map->table[hash];
	while (cur != NULL)
	{
		if (map->equal(cur->key, key))
			return true;
		cur = cur->next;
	}
	return false;
}

int _contains_node_map_t(map_t *map, node_t *node)
{
	if (!map || !node)
		return false;
	return map->contains(map, node->key);
}

void *_get_map_t(map_t *map, void *key)
{
	if (!map)
		return NULL;
	size_t hash = map->get_hash(map, key, map->cap);
	node_t *cur = map->table[hash];
	while (cur != NULL)
	{
		if (map->equal(cur->key, key))
			return cur->value;
		cur = cur->next;
	}
	return NULL;
}

node_t *_get_node_map_t(map_t *map, void *key)
{
	if (!map)
		return NULL;
	size_t hash = map->get_hash(map, key, map->cap);
	node_t *cur = map->table[hash];
	while (cur != NULL)
	{
		if (map->equal(cur->key, key))
			return cur;
		cur = cur->next;
	}
	return NULL;
}

size_t _get_index_map_t(map_t *map, void *key)
{
	if (!map)
		return (size_t)-1;
	size_t hash = map->get_hash(map, key, map->cap);
	node_t *cur = map->table[hash];
	if (!cur)
		return (size_t)-1;
	return hash;
}

size_t _get_index_node_map_t(map_t *map, node_t *node)
{
	if (!map || !node)
		return (size_t)-1;
	return map->get_index(map, node->key);
}

void _erase_map_t(map_t *map)
{
	if (!map)
		return;
	for (size_t i = 0; i < map->cap; i++)
	{
		node_t *cur = map->table[i];
		while (cur != NULL)
		{
			node_t *next = cur->next;
			free(cur);
			cur = next;
		}
		map->table[i] = NULL;
	}
	free(map->keys);
	map->keys = (void **)malloc(map->size_key * map->kcap);
	map->len = 0, map->klen = 0;
}

void _sort_map_t(map_t *map, int (*compt)(const void *a, const void *b))
{
	if (!map)
		return;
	qsort(map->keys, map->klen, map->size_key, compt);
}

int _empty_map_t(map_t *map)
{
	if (!map)
		return true;
	if (map->len == 0)
		return true;
	return false;
}

size_t _length_map_t(map_t *map)
{
	if (!map)
		return (size_t)-1;
	return map->len;
}

size_t _capacity_map_t(map_t *map)
{
	if (!map)
		return (size_t)-1;
	return map->cap;
}

long double _error_rate_map_t(map_t *map, size_t expected_size)
{
	if (!map)
		return -1.0L;
	return (expected_size - map->len) * 100.0L / map->len;
}

int _c_loop_iter_map_t(iter_map_t *iter)
{
	if (!iter)
		return false;
	return iter->curr != NULL;
}

node_t *_get_iter_map_t(iter_map_t *iter)
{
	if (!iter)
		return NULL;
	return iter->curr;
}

const node_t *_cget_iter_map_t(iter_map_t *iter)
{
	if (!iter)
		return NULL;
	return (const node_t *)iter->curr;
}

void _next_iter_map_t(iter_map_t *iter)
{
	if (!iter)
		return;
	iter->index++;
	while (iter->index < iter->m->klen && iter->m->get_node(iter->m, iter->m->keys[iter->index]) == NULL)
		iter->index++;
	iter->curr = iter->m->get_node(iter->m, iter->m->keys[iter->index]);
}

iter_map_t _iterator_map_t(map_t *map)
{
	if (!map)
		return (iter_map_t){NULL};
	iter_map_t iter;
	iter.m = map;
	iter.index = 0;
	while (iter.index < iter.m->klen && iter.m->get_node(iter.m, iter.m->keys[iter.index]) == NULL)
		iter.index++;
	iter.curr = iter.m->get_node(iter.m, iter.m->keys[iter.index]);

	iter.c_loop = _c_loop_iter_map_t;
	iter.get = _get_iter_map_t;
	iter.cget = _cget_iter_map_t;
	iter.next = _next_iter_map_t;
	return iter;
}

void hash_combine_map_t(map_t *map, size_t *seed, void *key, void *value)
{
	*seed ^= map->key_type_hash(key) + map->value_type_hash(value) + (size_t)0xc70f6907UL + (*seed << 7) + (*seed >> 3);
}

size_t _hash_map_t(map_t *map)
{
	if (!map)
		return 0;
	size_t h = 0;
	for (iter_map_t i = map->iterator(map); i.c_loop(&i); i.next(&i))
		hash_combine_map_t(map, &h, i.get(&i)->key, i.get(&i)->value);
	return h;
}

int _compare_map_t(map_t *map, map_t *map2)
{
	if (!map || !map2)
		return false;
	if (map->len != map2->len)
		return false;
	for (iter_map_t i = map->iterator(map), j = map2->iterator(map2); i.c_loop(&i) && j.c_loop(&j); i.next(&i), j.next(&j))
		if (!map->equal(i.get(&j)->key, j.get(&j)->key) || i.get(&i)->value != j.get(&i)->value)
			return false;
	return true;
}

int _compare_hash_map_t(map_t *map, map_t *map2)
{
	if (!map || !map2)
		return false;
	if (map->hash(map) == map2->hash(map2))
		return true;
	return false;
}

size_t _max_depth_map_t(map_t *map)
{
	if (!map)
		return 0;
	size_t max = 0, x = 0;
	for (size_t i = 0; i < map->cap; i++)
	{
		node_t *temp = map->table[i];
		while (temp)
			x++, temp = temp->next;
		if (x > max)
			max = x;
		x = 0;
	}
	return max;
}

void _copy_map_t(map_t *src, map_t *dest)
{
	if (!src || !dest)
		return;
	dest->destructor(dest);
	map_init(dest, 10, 0.75f, dest->key_type_hash, dest->value_type_hash, dest->equal, dest->size_key, dest->size_val);
	for (iter_map_t i = src->iterator(src); i.c_loop(&i); i.next(&i))
		dest->add(dest, i.get(&i)->key, i.get(&i)->value);
}

void _destructor_map_t(map_t *map)
{
	if (!map)
		return;
	for (size_t i = 0; i < map->cap; i++)
	{
		node_t *cur = map->table[i];
		while (cur)
		{
			node_t *next = cur->next;
			free(cur);
			cur = next;
		}
	}
	free(map->table);
	free(map->keys);
}

map_t new_map_t(size_t (*get_key_hash)(void *key), size_t (*get_value_hash)(void *value), int (*equal)(void *key1, void *key2), size_t size_of_key, size_t size_of_val)
{
	map_t m;
	map_init(&m, 10, 0.75f, get_key_hash, get_value_hash, equal, size_of_key, size_of_val);
	return m;
}

int map_init(map_t *map, size_t capacity, float load_factor, size_t (*get_key_hash)(void *key), size_t (*get_value_hash)(void *value), int (*equal)(void *key1, void *key2), size_t size_of_key, size_t size_of_val)
{
	if (!map || !get_key_hash || !get_value_hash || !equal || load_factor < 0.0f)
		return false;
	map->cap = capacity, map->load_factor = load_factor, map->key_type_hash = get_key_hash, map->value_type_hash = get_value_hash, map->equal = equal, map->kcap = capacity, map->klen = 0, map->len = 0, map->size_key = size_of_key, map->size_val = size_of_val;
	map->table = (node_t **)malloc(sizeof(node_t *) * map->cap);
	make_null_array((void **)map->table, map->cap);
	map->keys = (void **)malloc(map->size_key * map->kcap);
	make_null_array((void **)map->keys, map->kcap);

	map->get_hash = _get_hash_map_t;
	map->rehash = _rehash_map_t;

	map->add = _add_map_t;
	map->add_node = _add_node_map_t;
	map->remove = _remove_map_t;
	map->remove_node = _remove_node_map_t;
	map->contains = _contains_map_t;
	map->contains_node = _contains_node_map_t;
	map->get = _get_map_t;
	map->get_node = _get_node_map_t;
	map->get_index = _get_index_map_t;
	map->get_index_node = _get_index_node_map_t;
	map->erase = _erase_map_t;
	map->sort = _sort_map_t;
	map->empty = _empty_map_t;
	map->length = _length_map_t;
	map->capacity = _capacity_map_t;
	map->error_rate = _error_rate_map_t;
	map->iterator = _iterator_map_t;
	map->hash = _hash_map_t;
	map->compare = _compare_map_t;
	map->compare_hash = _compare_hash_map_t;
	map->max_depth = _max_depth_map_t;
	map->copy = _copy_map_t;
	map->destructor = _destructor_map_t;

	map->init = true;
	map->nerr = (size_t)-1;
	return (int)map->init;
}

#endif
#endif