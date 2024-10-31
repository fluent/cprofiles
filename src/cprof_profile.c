/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  CProfiles
 *  =========
 *  Copyright (C) 2024 The CProfiles Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


#include <cprofiles/cprofiles.h>

struct cprof_profile *cprof_profile_create(struct cprof *cprof)
{
    struct cprof_profile *profile;

    profile = calloc(1, sizeof(struct cprof_profile));
    if (!profile) {
        return NULL;
    }

    cfl_list_init(&profile->sample_type);
    cfl_list_init(&profile->samples);
    cfl_list_init(&profile->mappings);
    cfl_list_init(&profile->locations);
    cfl_list_init(&profile->attribute_units);
    cfl_list_init(&profile->link_table);

    profile->attribute_table = cfl_kvlist_create();
    if (!profile->attribute_table) {
        free(profile);
        return NULL;
    }

    profile->attributes = cfl_kvlist_create();
    if (!profile->attributes) {
        cfl_kvlist_destroy(profile->attribute_table);
        free(profile);
        return NULL;
    }

    cfl_list_add(&profile->_head, &cprof->profiles);
    return profile;
}


void cprof_profile_destroy(struct cprof_profile *profile)
{
    int i;
    if (!profile) {
        return;
    }

    if (profile->location_indices) {
        free(profile->location_indices);
    }

    cfl_kvlist_destroy(profile->attribute_table);
    cfl_kvlist_destroy(profile->attributes);

    /* delete strings */
    if (profile->string_table) {
        for (i = 0; i < profile->string_table_count; i++) {
            cfl_sds_destroy(profile->string_table[i]);
        }
        free(profile->string_table);
    }

    /* destroy sample types */
    cprof_sample_type_destroy_all(profile);

    /* destroy samples */
    cprof_sample_destroy_all(profile);

    free(profile);
}

size_t cprof_profile_string_add(struct cprof_profile *profile, char *str, int str_len)
{
    int alloc_size = 64;
    size_t id;
    size_t new_size;

    if (!str) {
        return -1;
    }

    if (str_len <= 0) {
        str_len = strlen(str);
    }

    if (!profile->string_table) {
        profile->string_table = malloc(alloc_size * sizeof(cfl_sds_t));
        if (!profile->string_table) {
            return -1;
        }
        profile->string_table_size = alloc_size;

        /* string_table[0] must always be "" */
        profile->string_table[0] = cfl_sds_create_len("", 0);
        if (!profile->string_table[0]) {
            return -1;
        }
        profile->string_table_count = 1;
    }

    /* check there is enough room for a new entry */
    if (profile->string_table_count >= profile->string_table_size) {
        new_size = profile->string_table_size + alloc_size;
        profile->string_table = realloc(profile->string_table, new_size * sizeof(cfl_sds_t));
        if (!profile->string_table) {
            return -1;
        }
        profile->string_table_size = alloc_size;
    }

    id = profile->string_table_count;
    profile->string_table[id] = cfl_sds_create_len(str, str_len);
    if (!profile->string_table[id]) {
        return -1;
    }
    profile->string_table_count++;

    return id;
}
