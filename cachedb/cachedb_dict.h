/*
 * Doubly-linked list implementation of a dictionary
 *
 * Copyright (C) 2018 OpenSIPS Solutions
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,USA
 */

#ifndef __CACHEDB_DICT_H__
#define __CACHEDB_DICT_H__

struct cdb_key;
struct cdb_val;
struct cdb_pair;

#include "../lib/list.h"

typedef struct list_head cdb_dict_t; /* list of cdb_pair_t */

static inline void cdb_dict_init(cdb_dict_t *dict)
{
	INIT_LIST_HEAD(dict);
}

void cdb_dict_add(struct cdb_pair *pair, cdb_dict_t *dict);
void cdb_free_entries(cdb_dict_t *dict);

struct cdb_pair *dict_fetch(const struct cdb_key *key, const cdb_dict_t *dict);
int dict_has_pair(const cdb_dict_t *haystack, const struct cdb_pair *pair);
struct cdb_pair *nth_pair(const cdb_dict_t *dict, int nth);
int dict_cmp(const cdb_dict_t *a, const cdb_dict_t *b);
int val_cmp(const struct cdb_val *v1, const struct cdb_val *v2);

static inline int cdb_dict_empty(cdb_dict_t *dict)
{
	return list_empty(dict);
}

#define dbg_cdb_dict(_pre_text, _dict_ptr) \
	do { \
		if (is_printable(L_DBG)) \
			_dbg_cdb_dict(_pre_text, _dict_ptr); \
	} while (0)
void _dbg_cdb_dict(const char *pre_txt, const cdb_dict_t *dict);

#endif /* __CACHEDB_DICT_H__ */
