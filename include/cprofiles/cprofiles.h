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
    struct cfl_list sample_type;
    struct cfl_list samples;
    struct cfl_list mappings;
    struct cfl_list locations;

    int64_t *location_indices;
    size_t location_indices_count;
    size_t location_indices_size;

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

    /* 16-byte profile ID */
    uint8_t profile_id[16];

    struct cfl_kvlist *attributes;
    uint32_t dropped_attributes_count;

    cfl_sds_t original_payload_format;

    cfl_sds_t original_payload;

    /* link to struct cprof->profiles */
    struct cfl_list _head;
};

struct cprof_resource_profiles {
    struct cprof_resource *resource;

    /* Linked list for nodes of cprof_scope_profile type */
    struct cfl_list scope_profiles;

    cfl_sds_t schema_url;
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

struct cprof *cprof_create();
void cprof_destroy(struct cprof *cprof);
char *cprof_version();

/* Profile */
struct cprof_profile *cprof_profile_create(struct cprof *cprof);
void cprof_profile_destroy(struct cprof_profile *profile);
size_t cprof_profile_string_add(struct cprof_profile *profile, char *str, int str_len);

/* Sample */
struct cprof_sample *cprof_sample_create(struct cprof_profile *profile);
void cprof_sample_destroy(struct cprof_sample *sample);
void cprof_sample_destroy_all(struct cprof_profile *profile);
int cprof_sample_add_timestamp(struct cprof_sample *sample, uint64_t timestamp);

int cprof_sample_add_value(struct cprof_sample *sample, int64_t value);
int cprof_sample_add_location_index(struct cprof_sample *sample, uint64_t location_index);

/* Sample type */
struct cprof_value_type *cprof_sample_type_create(struct cprof_profile *profile,
                                                  int64_t type, int64_t unit, int aggregation_temporality);
struct cprof_value_type *cprof_sample_type_str_create(struct cprof_profile *profile,
                                                      char *type_str, char *unit_str,
                                                      int aggregation_temporality);

void cprof_sample_type_destroy(struct cprof_value_type *sample_type);
void cprof_sample_type_destroy_all(struct cprof_profile *profile);

#endif
