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

struct cprof *cprof_create()
{
    struct cprof *cprof;

    cprof = calloc(1, sizeof(struct cprof));
    if (!cprof) {
        return NULL;
    }
    cfl_list_init(&cprof->profiles);

    return cprof;
}

void cprof_destroy(struct cprof *cprof)
{
    struct cfl_list *tmp;
    struct cfl_list *head;
    struct cprof_profile *profile;

    if (!cprof) {
        return;
    }

    cfl_list_foreach_safe(head, tmp, &cprof->profiles) {
        profile = cfl_list_entry(head, struct cprof_profile, _head);
        cfl_list_del(&profile->_head);
        cprof_profile_destroy(profile);
    }
    free(cprof);
}

char *cprof_version()
{
    return CPROF_VERSION_STR;
}
