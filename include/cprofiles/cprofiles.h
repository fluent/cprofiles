/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  CProfiles
 *  =========
 *  Copyright 2024 The CProfiles Authors
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

#ifndef CPROF_H
#define CPROF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <inttypes.h>

#include <cfl/cfl.h>

#include <cprofiles/cprof_info.h>
#include <cprofiles/cprof_version.h>

enum aggregation_temporality {
    CPROF_AGGREGATION_TEMPORALITY_UNSPECIFIED = 0,
    CPROF_AGGREGATION_TEMPORALITY_DELTA = 1,
    CPROF_AGGREGATION_TEMPORALITY_CUMULATIVE = 2
};

struct cprof_value_type {
    int64_t type;
    int64_t unit;

    /* CPROF_AGGREGATION_TEMPORALITY_* */
    int aggregation_temporality;

    /* Linked list for nodes of cprof_value_type */
    struct cfl_list _head;
};

struct cprof_sample {
    uint64_t *location_index;
    size_t location_index_count;
    size_t location_index_size;

    uint64_t locations_start_index;
    uint64_t locations_length;

    int64_t *values;
    size_t value_count;
    size_t value_size;

    uint64_t *attributes;
    size_t attributes_count;
    size_t attributes_size;

    uint64_t link;

    uint64_t *timestamps_unix_nano;
    size_t timestamps_count;
    size_t timestamps_size;

    /* struct cprof_profile->samples */
    struct cfl_list _head;
};

struct cprof_mapping {
    uint64_t id; /* deprecated */
    uint64_t memory_start;
    uint64_t memory_limit;
    uint64_t file_offset;
    int64_t filename;

    uint64_t *attributes;
    size_t attributes_count;
    size_t attributes_size;

    bool has_functions;
    bool has_filenames;
    bool has_line_numbers;
    bool has_inline_frames;

    /* struct cfl_profile->mappings */
    struct cfl_list _head;
};

struct cprof_line {
    uint64_t function_index;
    int64_t line;
    int64_t column;

    /* cprof_location->lines */
    struct cfl_list _head;
};

struct cprof_location {
    uint64_t id;             /* deprecated */
    uint64_t mapping_index;
    uint64_t address;

    struct cfl_list lines;

    bool is_folded;

    uint64_t *attributes;
    size_t attributes_count;
    size_t attributes_size;

    /* struct cfl_profile->locations */
    struct cfl_list _head;
};

struct cprof_function {
    uint64_t id;         /* deprecated */
    int64_t name;
    int64_t system_name;
    int64_t filename;
    int64_t start_line;

    /* struct cfl_profile->functions */
    struct cfl_list _head;
};

struct cprof_attribute_unit {
    int64_t attribute_key;
    int64_t unit;

    /* struct cfl_profile->attribute_units */
    struct cfl_list _head;
};

struct cprof_link {
    uint8_t trace_id[16];
    uint8_t span_id[8];

    /* struct cfl_profile->link_table */
    struct cfl_list _head;
};

struct cprof_profile {
    /* These fields correspond to the ProfileContainer
     * Message type
     */
    uint8_t profile_id[16];

    int64_t start_time_unix_nano;
    int64_t end_time_unix_nano;

    struct cfl_kvlist *attributes;
    uint32_t dropped_attributes_count;

    cfl_sds_t original_payload_format;

    cfl_sds_t original_payload;

    /* These fields correspond to the Profile
     * Message type
     */

    struct cfl_list sample_type;
    struct cfl_list samples;
    struct cfl_list mappings;
    struct cfl_list locations;

    int64_t *location_indices;
    size_t location_indices_count;
    size_t location_indices_size;

    struct cfl_list functions;

    struct cfl_kvlist *attribute_table;

    struct cfl_list attribute_units;

    struct cfl_list link_table;

    /* array of strings */
    cfl_sds_t *string_table;
    size_t string_table_count;
    size_t string_table_size;

    int64_t drop_frames;
    int64_t keep_frames;

    int64_t time_nanos;
    int64_t duration_nanos;

    struct cprof_value_type period_type;
    int64_t period;

    int64_t *comments;
    size_t comments_count;
    size_t comments_size;

    int64_t default_sample_type;

    /* used in cprof_scope_profiles->profiles */
    struct cfl_list _head;
};

struct cprof_resource_profiles {
    struct cprof_resource *resource;

    /* Linked list for nodes of cprof_scope_profile type */
    struct cfl_list scope_profiles;

    cfl_sds_t schema_url;

    /* link to struct cprof->profiles */
    struct cfl_list _head;
};

/*
 * Generic OTel metadata structures
 * --------------------------------
 */
struct cprof_instrumentation_scope {
    cfl_sds_t name;
    cfl_sds_t version;
    struct cfl_kvlist *attributes;
    uint32_t dropped_attributes_count;
};

struct cprof_resource {
    struct cfl_kvlist *attributes;
    uint32_t dropped_attributes_count;

};

struct cprof_scope_profiles {
    struct cprof_instrumentation_scope *scope;

    /* Linked list for nodes of cprof_profile types */
    struct cfl_list profiles;

    cfl_sds_t schema_url;

    /* link to struct cprof_resource_profiles */
    struct cfl_list _head;
};


/* Main CProfile context */
struct cprof {

    struct cfl_list profiles;

    // /* logging */
    // int log_level;
    // void (*log_cb)(void *, int, const char *, int, const char *);

    /* Only used by the caller */
    struct cfl_list _head;
};

/*
 * Library API
 * -----------
 */


static struct cprof_profile *cprof_profile_create();
static int cprof_profile_add_location_index(struct cprof_profile *profile, int64_t index);
static void cprof_profile_destroy(struct cprof_profile *instance);

static int cprof_resource_profiles_add(struct cprof *context,
                                       struct cprof_resource_profiles *resource_profiles);


static struct cprof_attribute_unit *cprof_attribute_unit_create(struct cprof_profile *profile);
static void cprof_attribute_unit_destroy(struct cprof_attribute_unit *instance);


static struct cprof_mapping *cprof_mapping_create(struct cprof_profile *profile);
static void cprof_mapping_destroy(struct cprof_mapping *instance);
static int cprof_mapping_add_attribute(struct cprof_mapping *mapping, uint64_t attribute);

static struct cprof_line *cprof_line_create(struct cprof_location *location);
static void cprof_line_destroy(struct cprof_line *instance);
static struct cprof_location *cprof_location_create(struct cprof_profile *profile);
static int cprof_location_add_attribute(struct cprof_location *location, uint64_t attribute);
static void cprof_location_destroy(struct cprof_location *instance);


static struct cprof_resource *cprof_resource_create(struct cfl_kvlist *attributes);
static void cprof_resource_destroy(struct cprof_resource *resource);

static struct cprof_instrumentation_scope *cprof_instrumentation_scope_create(
                                            char *name,
                                            char *version,
                                            struct cfl_kvlist *attributes,
                                            uint32_t dropped_attributes_count);
static void cprof_instrumentation_scope_destroy(
                struct cprof_instrumentation_scope *instance);


static struct cprof_scope_profiles *cprof_scope_profiles_create(
    struct cprof_resource_profiles *resource_profiles,
    char *schema_url);
static void cprof_scope_profiles_destroy(struct cprof_scope_profiles *instance);
static struct cprof_resource_profiles *cprof_resource_profiles_create(char *schema_url);
static void cprof_resource_profiles_destroy(struct cprof_resource_profiles *instance);

static struct cprof_link *cprof_link_create(struct cprof_profile *profile);
static void cprof_link_destroy(struct cprof_link *instance);


struct cprof *cprof_create();
void cprof_destroy(struct cprof *cprof);
char *cprof_version();

/* Profile */
//struct cprof_profile *cprof_profile_create(struct cprof *cprof);
//void cprof_profile_destroy(struct cprof_profile *profile);
size_t cprof_profile_string_add(struct cprof_profile *profile, char *str, int str_len);
int cprof_profile_add_comment(struct cprof_profile *profile, int64_t comment);

static struct cprof_profile *cprof_profile_create()
{
    struct cprof_profile *profile;

    profile = calloc(1, sizeof(struct cprof_profile));

    if (profile == NULL) {
        return NULL;
    }

    cfl_list_init(&profile->sample_type);
    cfl_list_init(&profile->samples);
    cfl_list_init(&profile->mappings);
    cfl_list_init(&profile->locations);
    cfl_list_init(&profile->functions);
    cfl_list_init(&profile->attribute_units);
    cfl_list_init(&profile->link_table);

    profile->attributes = cfl_kvlist_create();

    if (profile->attributes == NULL) {
        cprof_profile_destroy(profile);

        return NULL;
    }

    profile->attribute_table = cfl_kvlist_create();

    if (profile->attribute_table == NULL) {
        cprof_profile_destroy(profile);

        return NULL;
    }

    return profile;
}

static int cprof_profile_add_location_index(struct cprof_profile *profile, int64_t index)
{
    size_t new_size;
    size_t alloc_slots = 32;
    uint64_t *reallocated_array;

    if (profile->location_indices == NULL) {
        profile->location_indices = calloc(alloc_slots, sizeof(int64_t));

        if (profile->location_indices == NULL) {
            return -1;
        }

        profile->location_indices_count = 0;
        profile->location_indices_size = alloc_slots;
    }

    if (profile->location_indices_count >= profile->location_indices_size) {
        new_size = profile->location_indices_size + alloc_slots;
        reallocated_array = realloc(profile->location_indices, new_size * sizeof(int64_t));

        if (reallocated_array == NULL) {
            return -1;
        }

        profile->location_indices = reallocated_array;
        profile->location_indices_size = new_size;
    }

    profile->location_indices[profile->location_indices_count] = index;
    profile->location_indices_count++;

    return 0;
}


static void cprof_profile_destroy(struct cprof_profile *instance)
{

}

static int cprof_resource_profiles_add(struct cprof *context,
                                       struct cprof_resource_profiles *resource_profiles)
{
    cfl_list_add(&resource_profiles->_head, &context->profiles);

    return 0; /* CPROF_DECODE_OPENTELEMETRY_SUCCESS; */
}


/* Resource */
static struct cprof_resource *cprof_resource_create(struct cfl_kvlist *attributes)
{
    struct cprof_resource *resource;

    resource = calloc(1, sizeof(struct cprof_resource));

    if (resource == NULL) {
        return NULL;
    }

    if (attributes == NULL) {
        resource->attributes = cfl_kvlist_create();

        if (resource->attributes == NULL) {
            free(resource);

            return NULL;
        }
    }
    else {
        resource->attributes = attributes;
    }

    return resource;
}

static void cprof_resource_destroy(struct cprof_resource *resource)
{
    if (resource->attributes != NULL) {
        cfl_kvlist_destroy(resource->attributes);
    }

    free(resource);
}

/* Instrumentation Scope */
static struct cprof_instrumentation_scope *cprof_instrumentation_scope_create(
                                            char *name,
                                            char *version,
                                            struct cfl_kvlist *attributes,
                                            uint32_t dropped_attributes_count)

    {
    struct cprof_instrumentation_scope *instance;

    instance = calloc(1, sizeof(struct cprof_instrumentation_scope));

    if (instance == NULL) {
        return NULL;
    }

    if (name != NULL) {
        instance->name = cfl_sds_create(name);

        if (instance->name == NULL) {
            cprof_instrumentation_scope_destroy(instance);

            return NULL;
        }
    }

    if (version != NULL) {
        instance->version = cfl_sds_create(version);

        if (instance->version == NULL) {
            cprof_instrumentation_scope_destroy(instance);

            return NULL;
        }
    }

    if (attributes != NULL) {
        instance->attributes = attributes;
    }
    else {
        instance->attributes = cfl_kvlist_create();

        if (instance->attributes == NULL) {
            cprof_instrumentation_scope_destroy(instance);

            return NULL;
        }
    }

    instance->dropped_attributes_count = dropped_attributes_count;

    return instance;
}

static void cprof_instrumentation_scope_destroy(
                struct cprof_instrumentation_scope *instance)
{
    if (instance != NULL) {
        if (instance->name != NULL) {
            cfl_sds_destroy(instance->name);
        }

        if (instance->version != NULL) {
            cfl_sds_destroy(instance->version);
        }

        if (instance->attributes != NULL) {
            cfl_kvlist_destroy(instance->attributes);
        }

        free(instance);
    }
}

/* Scope profiles */
static struct cprof_scope_profiles *cprof_scope_profiles_create(
        struct cprof_resource_profiles *resource_profiles,
        char *schema_url) {
    struct cprof_scope_profiles *instance;

    instance = calloc(1, sizeof(struct cprof_scope_profiles));

    if (instance != NULL) {
        if (schema_url != NULL) {
            instance->schema_url = cfl_sds_create(schema_url);

            cfl_list_init(&instance->profiles);

            cfl_list_add(&instance->_head, &resource_profiles->scope_profiles);
        }
        else {
            free(instance);

            instance = NULL;
        }
    }

    return instance;
}


static void cprof_scope_profiles_destroy(struct cprof_scope_profiles *instance) {
    struct cprof_profile *profile;
    struct cfl_list      *iterator;
    struct cfl_list      *iterator_backup;

    if (instance != NULL) {
        if (instance->schema_url != NULL) {
            cfl_sds_destroy(instance->schema_url);
        }

        if (instance->scope != NULL) {
            cprof_instrumentation_scope_destroy(instance->scope);
        }

        cfl_list_foreach_safe(iterator,
                              iterator_backup,
                              &instance->profiles) {
            profile = cfl_list_entry(iterator,
                                     struct cprof_profile, _head);

            cfl_list_del(&profile->_head);

            cprof_profile_destroy(profile);
        }

        free(instance);
    }
}



/* Resource profiles */
static struct cprof_resource_profiles *cprof_resource_profiles_create(char *schema_url) {
    struct cprof_resource_profiles *instance;

    instance = calloc(1, sizeof(struct cprof_resource_profiles));

    if (instance != NULL) {
        if (schema_url != NULL) {
            instance->schema_url = cfl_sds_create(schema_url);

            cfl_list_init(&instance->scope_profiles);
        }
        else {
            free(instance);

            instance = NULL;
        }
    }

    return instance;
}


static void cprof_resource_profiles_destroy(struct cprof_resource_profiles *instance) {
    struct cfl_list             *iterator;
    struct cprof_scope_profiles *scope_profiles;
    struct cfl_list             *iterator_backup;

    if (instance != NULL) {
        if (instance->schema_url != NULL) {
            cfl_sds_destroy(instance->schema_url);
        }

        if (instance->resource != NULL) {
            cprof_resource_destroy(instance->resource);
        }

        cfl_list_foreach_safe(iterator,
                              iterator_backup,
                              &instance->scope_profiles) {
            scope_profiles = cfl_list_entry(iterator,
                                            struct cprof_scope_profiles, _head);

            cfl_list_del(&scope_profiles->_head);

            cprof_scope_profiles_destroy(scope_profiles);
        }

        free(instance);
    }
}




/* Sample */
struct cprof_sample *cprof_sample_create(struct cprof_profile *profile);
void cprof_sample_destroy(struct cprof_sample *sample);
void cprof_sample_destroy_all(struct cprof_profile *profile);
int cprof_sample_add_timestamp(struct cprof_sample *sample, uint64_t timestamp);

int cprof_sample_add_value(struct cprof_sample *sample, int64_t value);
int cprof_sample_add_location_index(struct cprof_sample *sample, uint64_t location_index);
int cprof_sample_add_attribute(struct cprof_sample *sample, uint64_t attribute);

/* Sample type */
struct cprof_value_type *cprof_sample_type_create(struct cprof_profile *profile,
                                                  int64_t type, int64_t unit, int aggregation_temporality);
struct cprof_value_type *cprof_sample_type_str_create(struct cprof_profile *profile,
                                                      char *type_str, char *unit_str,
                                                      int aggregation_temporality);

void cprof_sample_type_destroy(struct cprof_value_type *sample_type);
void cprof_sample_type_destroy_all(struct cprof_profile *profile);



/* Mapping */

static struct cprof_mapping *cprof_mapping_create(struct cprof_profile *profile)
{
    struct cprof_mapping *instance;

    instance = calloc(1, sizeof(struct cprof_mapping));

    if (instance == NULL) {
        return NULL;
    }

    cfl_list_add(&instance->_head, &profile->mappings);

    return instance;
}

static void cprof_mapping_destroy(struct cprof_mapping *instance)
{
    if (instance != NULL) {
        if (instance->attributes != NULL) {
            free(instance->attributes);

            instance->attributes = NULL;
        }

        if (cfl_list_entry_is_orphan(&instance->_head) == CFL_FALSE) {
            cfl_list_del(&instance->_head);
        }

        free(instance);
    }
}


static int cprof_mapping_add_attribute(struct cprof_mapping *mapping, uint64_t attribute)
{
    size_t new_size;
    size_t alloc_slots = 32;
    uint64_t *reallocated_attributes;

    if (mapping->attributes == NULL) {
        mapping->attributes = calloc(alloc_slots, sizeof(uint64_t));

        if (mapping->attributes == NULL) {
            return -1;
        }

        mapping->attributes_count = 0;
        mapping->attributes_size = alloc_slots;
    }

    if (mapping->attributes_count >= mapping->attributes_size) {
        new_size = mapping->attributes_size + alloc_slots;
        reallocated_attributes = realloc(mapping->attributes, new_size * sizeof(uint64_t));

        if (reallocated_attributes == NULL) {
            return -1;
        }

        mapping->attributes = reallocated_attributes;
        mapping->attributes_size = new_size;
    }

    mapping->attributes[mapping->attributes_count] = attribute;
    mapping->attributes_count++;

    return 0;
}

/* Line */
static struct cprof_line *cprof_line_create(struct cprof_location *location)
{
    struct cprof_line *instance;

    instance = calloc(1, sizeof(struct cprof_line));

    if (instance == NULL) {
        return NULL;
    }

    cfl_list_add(&instance->_head, &location->lines);

    return instance;
}

static void cprof_line_destroy(struct cprof_line *instance)
{
    if (instance != NULL) {
        if (cfl_list_entry_is_orphan(&instance->_head) == CFL_FALSE) {
            cfl_list_del(&instance->_head);
        }

        free(instance);
    }
}

/* Location */

static struct cprof_location *cprof_location_create(struct cprof_profile *profile)
{
    struct cprof_location *instance;

    instance = calloc(1, sizeof(struct cprof_location));

    if (instance == NULL) {
        return NULL;
    }

    cfl_list_init(&instance->lines);

    cfl_list_add(&instance->_head, &profile->locations);

    return instance;
}

static int cprof_location_add_attribute(struct cprof_location *location, uint64_t attribute)
{
    size_t new_size;
    size_t alloc_slots = 32;
    uint64_t *reallocated_attributes;

    if (location->attributes == NULL) {
        location->attributes = calloc(alloc_slots, sizeof(uint64_t));

        if (location->attributes == NULL) {
            return -1;
        }

        location->attributes_count = 0;
        location->attributes_size = alloc_slots;
    }

    if (location->attributes_count >= location->attributes_size) {
        new_size = location->attributes_size + alloc_slots;
        reallocated_attributes = realloc(location->attributes, new_size * sizeof(uint64_t));

        if (reallocated_attributes == NULL) {
            return -1;
        }

        location->attributes = reallocated_attributes;
        location->attributes_size = new_size;
    }

    location->attributes[location->attributes_count] = attribute;
    location->attributes_count++;

    return 0;
}


static void cprof_location_destroy(struct cprof_location *instance)
{
    struct cprof_line *line;
    struct cfl_list   *iterator;
    struct cfl_list   *iterator_backup;

    if (instance != NULL) {
        if (instance->attributes != NULL) {
            free(instance->attributes);

            instance->attributes = NULL;
        }

        cfl_list_foreach_safe(iterator,
                              iterator_backup,
                              &instance->lines) {
            line = cfl_list_entry(iterator,
                                  struct cprof_line, _head);

            cfl_list_del(&line->_head);

            cprof_line_destroy(line);
        }

        if (cfl_list_entry_is_orphan(&instance->_head) == CFL_FALSE) {
            cfl_list_del(&instance->_head);
        }

        free(instance);
    }
}

/* Function */

/* Mapping */

static struct cprof_function *cprof_function_create(struct cprof_profile *profile)
{
    struct cprof_function *instance;

    instance = calloc(1, sizeof(struct cprof_function));

    if (instance == NULL) {
        return NULL;
    }

    cfl_list_add(&instance->_head, &profile->functions);

    return instance;
}

static void cprof_function_destroy(struct cprof_function *instance)
{
    if (instance != NULL) {
        if (cfl_list_entry_is_orphan(&instance->_head) == CFL_FALSE) {
            cfl_list_del(&instance->_head);
        }

        free(instance);
    }
}

/* Attribute unit */

static struct cprof_attribute_unit *cprof_attribute_unit_create(struct cprof_profile *profile)
{
    struct cprof_attribute_unit *instance;

    instance = calloc(1, sizeof(struct cprof_attribute_unit));

    if (instance == NULL) {
        return NULL;
    }

    cfl_list_add(&instance->_head, &profile->attribute_units);

    return instance;
}

static void cprof_attribute_unit_destroy(struct cprof_attribute_unit *instance)
{
    if (instance != NULL) {
        if (cfl_list_entry_is_orphan(&instance->_head) == CFL_FALSE) {
            cfl_list_del(&instance->_head);
        }

        free(instance);
    }
}

/* Link */


static struct cprof_link *cprof_link_create(struct cprof_profile *profile)
{
    struct cprof_link *instance;

    instance = calloc(1, sizeof(struct cprof_link));

    if (instance == NULL) {
        return NULL;
    }

    cfl_list_add(&instance->_head, &profile->link_table);

    return instance;
}

static void cprof_link_destroy(struct cprof_link *instance)
{
    if (instance != NULL) {
        if (cfl_list_entry_is_orphan(&instance->_head) == CFL_FALSE) {
            cfl_list_del(&instance->_head);
        }

        free(instance);
    }
}

#endif
