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

#include <time.h>
#include "cprof_tests.h"
#include <cprofiles/cprof_decode_opentelemetry.h>
#include <cprofiles/cprof_encode_opentelemetry.h>

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

/*
unsigned char encoded_packet[] = {  0x0A, 0x9F, 0x11, 0x0A, 0x72, 0x0A, 0x0E, 0x0A, 0x07, 0x68, 0x6F, 0x73, 0x74, 0x2E, 0x69, 0x64, 0x12, 0x03, 0x0A, 0x01, 0x30, 0x0A, 0x16, 0x0A, 0x07, 0x68, 0x6F, 0x73, 0x74, 0x2E, \
                                    0x69, 0x70, 0x12, 0x0B, 0x0A, 0x09, 0x31, 0x32, 0x37, 0x2E, 0x30, 0x2E, 0x30, 0x2E, 0x31, 0x0A, 0x1B, 0x0A, 0x09, 0x68, 0x6F, 0x73, 0x74, 0x2E, 0x6E, 0x61, 0x6D, 0x65, 0x12, 0x0E, \
                                    0x0A, 0x0C, 0x6C, 0x69, 0x6D, 0x61, 0x2D, 0x64, 0x65, 0x66, 0x61, 0x75, 0x6C, 0x74, 0x0A, 0x15, 0x0A, 0x0F, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x2E, 0x76, 0x65, 0x72, 0x73, \
                                    0x69, 0x6F, 0x6E, 0x12, 0x02, 0x0A, 0x00, 0x0A, 0x14, 0x0A, 0x09, 0x6F, 0x73, 0x2E, 0x6B, 0x65, 0x72, 0x6E, 0x65, 0x6C, 0x12, 0x07, 0x0A, 0x05, 0x36, 0x2E, 0x35, 0x2E, 0x30, 0x12, \
                                    0xA8, 0x10, 0x0A, 0x00, 0x12, 0xA3, 0x10, 0x0A, 0x10, 0xA4, 0x58, 0x33, 0xE6, 0x18, 0xE6, 0x34, 0x8D, 0xD6, 0xFE, 0x00, 0x58, 0x56, 0xF5, 0xA7, 0x54, 0x11, 0x69, 0x39, 0xAC, 0x2C, \
                                    0x53, 0xC7, 0x04, 0x18, 0x19, 0x69, 0x39, 0xAC, 0x2C, 0x53, 0xC7, 0x04, 0x18, 0x42, 0xFC, 0x0F, 0x0A, 0x04, 0x08, 0x01, 0x10, 0x02, 0x12, 0x16, 0x12, 0x01, 0x01, 0x40, 0x05, 0x48, \
                                    0x05, 0x52, 0x02, 0x01, 0x02, 0x6A, 0x09, 0xF6, 0xEA, 0xCA, 0xD2, 0xAC, 0xEA, 0xB1, 0x82, 0x18, 0x12, 0x18, 0x12, 0x01, 0x01, 0x38, 0x05, 0x40, 0x0E, 0x48, 0x07, 0x52, 0x02, 0x06, \
                                    0x07, 0x6A, 0x09, 0xA8, 0xD3, 0xE3, 0x8E, 0xB1, 0xEA, 0xB1, 0x82, 0x18, 0x12, 0x18, 0x12, 0x01, 0x01, 0x38, 0x13, 0x40, 0x12, 0x48, 0x09, 0x52, 0x02, 0x09, 0x0A, 0x6A, 0x09, 0xE9, \
                                    0xF2, 0xB0, 0xE5, 0xB2, 0xEA, 0xB1, 0x82, 0x18, 0x1A, 0x04, 0x30, 0x06, 0x58, 0x01, 0x1A, 0x10, 0x10, 0x80, 0x80, 0x80, 0x02, 0x18, 0x80, 0x80, 0xF4, 0x08, 0x28, 0x08, 0x62, 0x02, \
                                    0x04, 0x05, 0x1A, 0x0E, 0x10, 0x80, 0x80, 0x04, 0x18, 0x80, 0xC0, 0xFB, 0x07, 0x28, 0x0A, 0x62, 0x01, 0x08, 0x22, 0x0B, 0x18, 0xDB, 0xC1, 0x43, 0x22, 0x02, 0x08, 0x01, 0x3A, 0x01, \
                                    0x00, 0x22, 0x0C, 0x18, 0xC7, 0x8B, 0xD2, 0x0A, 0x22, 0x02, 0x08, 0x02, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xB7, 0x94, 0x3A, 0x22, 0x02, 0x08, 0x03, 0x3A, 0x01, 0x00, 0x22, 0x0B, \
                                    0x18, 0xF7, 0x96, 0x3D, 0x22, 0x02, 0x08, 0x04, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0x87, 0xFA, 0x01, 0x22, 0x02, 0x08, 0x05, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xC3, 0xD6, 0xA1, \
                                    0x02, 0x22, 0x02, 0x08, 0x06, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xBB, 0xB5, 0xB3, 0x02, 0x22, 0x02, 0x08, 0x07, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xE7, 0xB7, 0xB3, 0x02, 0x22, \
                                    0x02, 0x08, 0x08, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0x93, 0xD5, 0xB9, 0x01, 0x22, 0x02, 0x08, 0x09, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xD7, 0x8C, 0xB8, 0x01, 0x22, 0x02, 0x08, \
                                    0x0A, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0x97, 0x93, 0xBA, 0x01, 0x22, 0x02, 0x08, 0x0B, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0x9F, 0xA8, 0xBA, 0x01, 0x22, 0x02, 0x08, 0x0C, 0x3A, \
                                    0x01, 0x00, 0x22, 0x0B, 0x18, 0xEB, 0xFA, 0x08, 0x22, 0x02, 0x08, 0x0D, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xD3, 0xFE, 0x08, 0x22, 0x02, 0x08, 0x0E, 0x3A, 0x01, 0x00, 0x22, 0x0B, \
                                    0x18, 0xB7, 0xFF, 0x08, 0x22, 0x02, 0x08, 0x0F, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xA7, 0xBD, 0xCF, 0x0A, 0x22, 0x02, 0x08, 0x10, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xCF, 0xCA, \
                                    0xCF, 0x0A, 0x22, 0x02, 0x08, 0x11, 0x3A, 0x01, 0x00, 0x22, 0x0A, 0x18, 0xC7, 0x3C, 0x22, 0x02, 0x08, 0x12, 0x3A, 0x01, 0x00, 0x22, 0x0A, 0x10, 0x01, 0x18, 0x9F, 0xA6, 0x81, 0x02, \
                                    0x3A, 0x01, 0x03, 0x22, 0x0C, 0x18, 0x9F, 0xCD, 0xA9, 0x02, 0x22, 0x02, 0x08, 0x13, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xC3, 0xDF, 0xAC, 0x02, 0x22, 0x02, 0x08, 0x14, 0x3A, 0x01, \
                                    0x00, 0x22, 0x0C, 0x18, 0xB3, 0x9F, 0xAD, 0x02, 0x22, 0x02, 0x08, 0x15, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0x9B, 0xE1, 0xA0, 0x02, 0x22, 0x02, 0x08, 0x16, 0x3A, 0x01, 0x00, 0x22, \
                                    0x0C, 0x18, 0xCB, 0xE8, 0x86, 0x09, 0x22, 0x02, 0x08, 0x17, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xEB, 0xE3, 0x87, 0x09, 0x22, 0x02, 0x08, 0x18, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, \
                                    0xFB, 0xAE, 0xFE, 0x09, 0x22, 0x02, 0x08, 0x19, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xE7, 0xB0, 0xFE, 0x09, 0x22, 0x02, 0x08, 0x1A, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xEF, 0x90, \
                                    0x85, 0x09, 0x22, 0x02, 0x08, 0x1B, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xF7, 0xF3, 0x85, 0x09, 0x22, 0x02, 0x08, 0x1C, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xCB, 0xF5, 0x85, 0x09, \
                                    0x22, 0x02, 0x08, 0x1D, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xEB, 0xFA, 0x08, 0x22, 0x02, 0x08, 0x0D, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xD3, 0xFE, 0x08, 0x22, 0x02, 0x08, 0x0E, \
                                    0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xB7, 0xFF, 0x08, 0x22, 0x02, 0x08, 0x0F, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xA7, 0xBD, 0xCF, 0x0A, 0x22, 0x02, 0x08, 0x10, 0x3A, 0x01, 0x00, \
                                    0x22, 0x0C, 0x18, 0xCF, 0xCA, 0xCF, 0x0A, 0x22, 0x02, 0x08, 0x11, 0x3A, 0x01, 0x00, 0x22, 0x0A, 0x18, 0xC7, 0x3C, 0x22, 0x02, 0x08, 0x12, 0x3A, 0x01, 0x00, 0x22, 0x09, 0x10, 0x02, \
                                    0x18, 0xAF, 0xBF, 0x05, 0x3A, 0x01, 0x03, 0x2A, 0x00, 0x2A, 0x02, 0x10, 0x18, 0x2A, 0x02, 0x10, 0x10, 0x2A, 0x02, 0x10, 0x24, 0x2A, 0x02, 0x10, 0x19, 0x2A, 0x02, 0x10, 0x21, 0x2A, \
                                    0x02, 0x10, 0x1A, 0x2A, 0x02, 0x10, 0x25, 0x2A, 0x02, 0x10, 0x0B, 0x2A, 0x02, 0x10, 0x26, 0x2A, 0x02, 0x10, 0x11, 0x2A, 0x02, 0x10, 0x14, 0x2A, 0x02, 0x10, 0x15, 0x2A, 0x02, 0x10, \
                                    0x12, 0x2A, 0x02, 0x10, 0x22, 0x2A, 0x02, 0x10, 0x16, 0x2A, 0x02, 0x10, 0x0E, 0x2A, 0x02, 0x10, 0x1B, 0x2A, 0x02, 0x10, 0x1E, 0x2A, 0x02, 0x10, 0x17, 0x2A, 0x02, 0x10, 0x27, 0x2A, \
                                    0x02, 0x10, 0x0C, 0x2A, 0x02, 0x10, 0x13, 0x2A, 0x02, 0x10, 0x1F, 0x2A, 0x02, 0x10, 0x23, 0x2A, 0x02, 0x10, 0x0F, 0x2A, 0x02, 0x10, 0x1C, 0x2A, 0x02, 0x10, 0x0D, 0x2A, 0x02, 0x10, \
                                    0x20, 0x2A, 0x02, 0x10, 0x1D, 0x32, 0x00, 0x32, 0x07, 0x73, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x73, 0x32, 0x05, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x32, 0x03, 0x63, 0x70, 0x75, 0x32, 0x0B, \
                                    0x6E, 0x61, 0x6E, 0x6F, 0x73, 0x65, 0x63, 0x6F, 0x6E, 0x64, 0x73, 0x32, 0x16, 0x41, 0x54, 0x73, 0x51, 0x46, 0x31, 0x72, 0x72, 0x49, 0x63, 0x30, 0x35, 0x74, 0x65, 0x6A, 0x66, 0x79, \
                                    0x65, 0x73, 0x5A, 0x52, 0x77, 0x32, 0x20, 0x62, 0x61, 0x31, 0x63, 0x39, 0x61, 0x35, 0x61, 0x38, 0x32, 0x35, 0x36, 0x61, 0x36, 0x65, 0x66, 0x33, 0x65, 0x36, 0x36, 0x33, 0x63, 0x63, \
                                    0x37, 0x33, 0x31, 0x36, 0x38, 0x30, 0x33, 0x64, 0x39, 0x32, 0x16, 0x7A, 0x6A, 0x32, 0x51, 0x75, 0x43, 0x52, 0x61, 0x70, 0x75, 0x6E, 0x30, 0x32, 0x73, 0x79, 0x68, 0x6C, 0x41, 0x48, \
                                    0x71, 0x54, 0x77, 0x32, 0x0D, 0x65, 0x62, 0x70, 0x66, 0x2D, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x72, 0x32, 0x16, 0x36, 0x34, 0x41, 0x49, 0x75, 0x76, 0x39, 0x69, 0x70, 0x47, \
                                    0x42, 0x41, 0x41, 0x64, 0x30, 0x52, 0x5A, 0x6D, 0x76, 0x4C, 0x4C, 0x77, 0x32, 0x0A, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, 0x72, 0x64, 0x32, 0x13, 0x5F, 0x5F, 0x63, 0x68, \
                                    0x65, 0x63, 0x6B, 0x5F, 0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x5F, 0x73, 0x69, 0x7A, 0x65, 0x32, 0x11, 0x6F, 0x62, 0x6A, 0x5F, 0x63, 0x67, 0x72, 0x6F, 0x75, 0x70, 0x5F, 0x63, 0x68, \
                                    0x61, 0x72, 0x67, 0x65, 0x32, 0x0D, 0x5F, 0x5F, 0x73, 0x6F, 0x63, 0x6B, 0x5F, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x32, 0x07, 0x65, 0x6C, 0x30, 0x5F, 0x73, 0x76, 0x63, 0x32, 0x0C, \
                                    0x75, 0x6E, 0x69, 0x78, 0x5F, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x31, 0x32, 0x08, 0x73, 0x63, 0x68, 0x65, 0x64, 0x75, 0x6C, 0x65, 0x32, 0x10, 0x62, 0x70, 0x66, 0x5F, 0x6D, 0x61, \
                                    0x70, 0x5F, 0x64, 0x6F, 0x5F, 0x62, 0x61, 0x74, 0x63, 0x68, 0x32, 0x0E, 0x69, 0x6E, 0x76, 0x6F, 0x6B, 0x65, 0x5F, 0x73, 0x79, 0x73, 0x63, 0x61, 0x6C, 0x6C, 0x32, 0x10, 0x6B, 0x6D, \
                                    0x65, 0x6D, 0x5F, 0x63, 0x61, 0x63, 0x68, 0x65, 0x5F, 0x61, 0x6C, 0x6C, 0x6F, 0x63, 0x32, 0x09, 0x5F, 0x5F, 0x73, 0x79, 0x73, 0x5F, 0x62, 0x70, 0x66, 0x32, 0x0F, 0x5F, 0x5F, 0x61, \
                                    0x72, 0x6D, 0x36, 0x34, 0x5F, 0x73, 0x79, 0x73, 0x5F, 0x62, 0x70, 0x66, 0x32, 0x0A, 0x64, 0x6F, 0x5F, 0x65, 0x6C, 0x30, 0x5F, 0x73, 0x76, 0x63, 0x32, 0x19, 0x70, 0x72, 0x6F, 0x70, \
                                    0x61, 0x67, 0x61, 0x74, 0x65, 0x5F, 0x70, 0x72, 0x6F, 0x74, 0x65, 0x63, 0x74, 0x65, 0x64, 0x5F, 0x75, 0x73, 0x61, 0x67, 0x65, 0x32, 0x19, 0x66, 0x69, 0x6E, 0x69, 0x73, 0x68, 0x5F, \
                                    0x74, 0x61, 0x73, 0x6B, 0x5F, 0x73, 0x77, 0x69, 0x74, 0x63, 0x68, 0x2E, 0x69, 0x73, 0x72, 0x61, 0x2E, 0x30, 0x32, 0x07, 0x6B, 0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x32, 0x13, 0x5F, \
                                    0x5F, 0x63, 0x68, 0x65, 0x63, 0x6B, 0x5F, 0x68, 0x65, 0x61, 0x70, 0x5F, 0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x32, 0x14, 0x65, 0x6C, 0x30, 0x74, 0x5F, 0x36, 0x34, 0x5F, 0x73, 0x79, \
                                    0x6E, 0x63, 0x5F, 0x68, 0x61, 0x6E, 0x64, 0x6C, 0x65, 0x72, 0x32, 0x0B, 0x75, 0x6E, 0x69, 0x78, 0x5F, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x32, 0x12, 0x5F, 0x5F, 0x61, 0x72, 0x6D, \
                                    0x36, 0x34, 0x5F, 0x73, 0x79, 0x73, 0x5F, 0x73, 0x6F, 0x63, 0x6B, 0x65, 0x74, 0x32, 0x0C, 0x65, 0x6C, 0x30, 0x74, 0x5F, 0x36, 0x34, 0x5F, 0x73, 0x79, 0x6E, 0x63, 0x32, 0x0D, 0x73, \
                                    0x6B, 0x5F, 0x70, 0x72, 0x6F, 0x74, 0x5F, 0x61, 0x6C, 0x6C, 0x6F, 0x63, 0x32, 0x0C, 0x5F, 0x5F, 0x73, 0x79, 0x73, 0x5F, 0x73, 0x6F, 0x63, 0x6B, 0x65, 0x74, 0x32, 0x0D, 0x72, 0x65, \
                                    0x74, 0x5F, 0x66, 0x72, 0x6F, 0x6D, 0x5F, 0x66, 0x6F, 0x72, 0x6B, 0x32, 0x1A, 0x65, 0x6C, 0x30, 0x5F, 0x73, 0x76, 0x63, 0x5F, 0x63, 0x6F, 0x6D, 0x6D, 0x6F, 0x6E, 0x2E, 0x63, 0x6F, \
                                    0x6E, 0x73, 0x74, 0x70, 0x72, 0x6F, 0x70, 0x2E, 0x30, 0x32, 0x08, 0x73, 0x6B, 0x5F, 0x61, 0x6C, 0x6C, 0x6F, 0x63, 0x32, 0x0D, 0x77, 0x6F, 0x72, 0x6B, 0x65, 0x72, 0x5F, 0x74, 0x68, \
                                    0x72, 0x65, 0x61, 0x64, 0x32, 0x1A, 0x5F, 0x5F, 0x63, 0x68, 0x65, 0x63, 0x6B, 0x5F, 0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x5F, 0x73, 0x69, 0x7A, 0x65, 0x2E, 0x70, 0x61, 0x72, 0x74, \
                                    0x2E, 0x30, 0x32, 0x18, 0x67, 0x65, 0x6E, 0x65, 0x72, 0x69, 0x63, 0x5F, 0x6D, 0x61, 0x70, 0x5F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x5F, 0x62, 0x61, 0x74, 0x63, 0x68, 0x32, 0x10, \
                                    0x74, 0x72, 0x79, 0x5F, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x5F, 0x6D, 0x65, 0x6D, 0x63, 0x67, 0x48, 0xE9, 0xF2, 0xB0, 0xE5, 0xB2, 0xEA, 0xB1, 0x82, 0x18, 0x5A, 0x04, 0x08, 0x03, \
                                    0x10, 0x04, 0x60, 0x80, 0xE1, 0xEB, 0x17, 0x7A, 0x25, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, \
                                    0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x82, 0x01, 0x1E, 0x0A, 0x12, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x2E, 0x66, \
                                    0x72, 0x61, 0x6D, 0x65, 0x2E, 0x74, 0x79, 0x70, 0x65, 0x12, 0x08, 0x0A, 0x06, 0x6B, 0x65, 0x72, 0x6E, 0x65, 0x6C, 0x82, 0x01, 0x13, 0x0A, 0x0C, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, \
                                    0x6E, 0x65, 0x72, 0x2E, 0x69, 0x64, 0x12, 0x03, 0x0A, 0x01, 0x2F, 0x82, 0x01, 0x1C, 0x0A, 0x0B, 0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x2E, 0x6E, 0x61, 0x6D, 0x65, 0x12, 0x0D, 0x0A, \
                                    0x0B, 0x6B, 0x77, 0x6F, 0x72, 0x6B, 0x65, 0x72, 0x2F, 0x36, 0x3A, 0x31, 0x82, 0x01, 0x1E, 0x0A, 0x12, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x2E, 0x66, 0x72, 0x61, 0x6D, 0x65, \
                                    0x2E, 0x74, 0x79, 0x70, 0x65, 0x12, 0x08, 0x0A, 0x06, 0x6E, 0x61, 0x74, 0x69, 0x76, 0x65, 0x82, 0x01, 0x4D, 0x0A, 0x1F, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x2E, 0x65, 0x78, \
                                    0x65, 0x63, 0x75, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x2E, 0x62, 0x75, 0x69, 0x6C, 0x64, 0x5F, 0x69, 0x64, 0x2E, 0x67, 0x6E, 0x75, 0x12, 0x2A, 0x0A, 0x28, 0x33, 0x34, 0x31, 0x39, 0x61, \
                                    0x33, 0x65, 0x66, 0x30, 0x30, 0x31, 0x35, 0x34, 0x35, 0x64, 0x38, 0x65, 0x65, 0x39, 0x66, 0x63, 0x64, 0x34, 0x62, 0x31, 0x38, 0x64, 0x34, 0x63, 0x65, 0x31, 0x37, 0x32, 0x30, 0x35, \
                                    0x37, 0x65, 0x33, 0x33, 0x39, 0x82, 0x01, 0x4B, 0x0A, 0x25, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x2E, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x2E, 0x62, \
                                    0x75, 0x69, 0x6C, 0x64, 0x5F, 0x69, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x69, 0x6E, 0x67, 0x12, 0x22, 0x0A, 0x20, 0x37, 0x30, 0x35, 0x62, 0x64, 0x66, 0x31, 0x34, 0x39, \
                                    0x38, 0x30, 0x66, 0x32, 0x63, 0x32, 0x32, 0x64, 0x63, 0x34, 0x64, 0x65, 0x32, 0x65, 0x36, 0x35, 0x37, 0x36, 0x65, 0x64, 0x66, 0x66, 0x38, 0x82, 0x01, 0x3C, 0x0A, 0x0C, 0x63, 0x6F, \
                                    0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, 0x72, 0x2E, 0x69, 0x64, 0x12, 0x2C, 0x0A, 0x2A, 0x2F, 0x75, 0x73, 0x65, 0x72, 0x2E, 0x73, 0x6C, 0x69, 0x63, 0x65, 0x2F, 0x75, 0x73, 0x65, 0x72, \
                                    0x2D, 0x35, 0x30, 0x31, 0x2E, 0x73, 0x6C, 0x69, 0x63, 0x65, 0x2F, 0x73, 0x65, 0x73, 0x73, 0x69, 0x6F, 0x6E, 0x2D, 0x32, 0x2E, 0x73, 0x63, 0x6F, 0x70, 0x65, 0x82, 0x01, 0x1E, 0x0A, \
                                    0x0B, 0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x2E, 0x6E, 0x61, 0x6D, 0x65, 0x12, 0x0F, 0x0A, 0x0D, 0x65, 0x62, 0x70, 0x66, 0x2D, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x72, 0x82, \
                                    0x01, 0x4B, 0x0A, 0x25, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x2E, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x2E, 0x62, 0x75, 0x69, 0x6C, 0x64, 0x5F, 0x69, \
                                    0x64, 0x2E, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x69, 0x6E, 0x67, 0x12, 0x22, 0x0A, 0x20, 0x64, 0x37, 0x38, 0x30, 0x31, 0x36, 0x30, 0x34, 0x65, 0x38, 0x62, 0x38, 0x39, 0x64, 0x64, \
                                    0x61, 0x63, 0x66, 0x65, 0x31, 0x39, 0x38, 0x39, 0x39, 0x64, 0x36, 0x62, 0x61, 0x33, 0x35, 0x36, 0x34, 0x82, 0x01, 0x5A, 0x0A, 0x0C, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, \
                                    0x72, 0x2E, 0x69, 0x64, 0x12, 0x4A, 0x0A, 0x48, 0x2F, 0x75, 0x73, 0x65, 0x72, 0x2E, 0x73, 0x6C, 0x69, 0x63, 0x65, 0x2F, 0x75, 0x73, 0x65, 0x72, 0x2D, 0x35, 0x30, 0x31, 0x2E, 0x73, \
                                    0x6C, 0x69, 0x63, 0x65, 0x2F, 0x75, 0x73, 0x65, 0x72, 0x40, 0x35, 0x30, 0x31, 0x2E, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x2F, 0x61, 0x70, 0x70, 0x2E, 0x73, 0x6C, 0x69, 0x63, \
                                    0x65, 0x2F, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, 0x72, 0x64, 0x2E, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x82, 0x01, 0x1B, 0x0A, 0x0B, 0x74, 0x68, 0x72, 0x65, 0x61, \
                                    0x64, 0x2E, 0x6E, 0x61, 0x6D, 0x65, 0x12, 0x0C, 0x0A, 0x0A, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, 0x72, 0x64
                                };
*/

unsigned char serialized_data[] = {
    0x0A, 0x9F, 0x11, 0x0A, 0x72, 0x0A, 0x0E, 0x0A, 0x07, 0x68, 0x6F, 0x73,
    0x74, 0x2E, 0x69, 0x64, 0x12, 0x03, 0x0A, 0x01, 0x30, 0x0A, 0x16, 0x0A,
    0x07, 0x68, 0x6F, 0x73, 0x74, 0x2E, 0x69, 0x70, 0x12, 0x0B, 0x0A, 0x09,
    0x31, 0x32, 0x37, 0x2E, 0x30, 0x2E, 0x30, 0x2E, 0x31, 0x0A, 0x1B, 0x0A,
    0x09, 0x68, 0x6F, 0x73, 0x74, 0x2E, 0x6E, 0x61, 0x6D, 0x65, 0x12, 0x0E,
    0x0A, 0x0C, 0x6C, 0x69, 0x6D, 0x61, 0x2D, 0x64, 0x65, 0x66, 0x61, 0x75,
    0x6C, 0x74, 0x0A, 0x15, 0x0A, 0x0F, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63,
    0x65, 0x2E, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x12, 0x02, 0x0A,
    0x00, 0x0A, 0x14, 0x0A, 0x09, 0x6F, 0x73, 0x2E, 0x6B, 0x65, 0x72, 0x6E,
    0x65, 0x6C, 0x12, 0x07, 0x0A, 0x05, 0x36, 0x2E, 0x35, 0x2E, 0x30, 0x12,
    0xA8, 0x10, 0x0A, 0x00, 0x12, 0xA3, 0x10, 0x0A, 0x10, 0xA4, 0x58, 0x33,
    0xE6, 0x18, 0xE6, 0x34, 0x8D, 0xD6, 0xFE, 0x00, 0x58, 0x56, 0xF5, 0xA7,
    0x54, 0x11, 0x69, 0x39, 0xAC, 0x2C, 0x53, 0xC7, 0x04, 0x18, 0x19, 0x69,
    0x39, 0xAC, 0x2C, 0x53, 0xC7, 0x04, 0x18, 0x42, 0xFC, 0x0F, 0x0A, 0x04,
    0x08, 0x01, 0x10, 0x02, 0x12, 0x16, 0x12, 0x01, 0x01, 0x40, 0x05, 0x48,
    0x05, 0x52, 0x02, 0x01, 0x02, 0x6A, 0x09, 0xF6, 0xEA, 0xCA, 0xD2, 0xAC,
    0xEA, 0xB1, 0x82, 0x18, 0x12, 0x18, 0x12, 0x01, 0x01, 0x38, 0x05, 0x40,
    0x0E, 0x48, 0x07, 0x52, 0x02, 0x06, 0x07, 0x6A, 0x09, 0xA8, 0xD3, 0xE3,
    0x8E, 0xB1, 0xEA, 0xB1, 0x82, 0x18, 0x12, 0x18, 0x12, 0x01, 0x01, 0x38,
    0x13, 0x40, 0x12, 0x48, 0x09, 0x52, 0x02, 0x09, 0x0A, 0x6A, 0x09, 0xE9,
    0xF2, 0xB0, 0xE5, 0xB2, 0xEA, 0xB1, 0x82, 0x18, 0x1A, 0x04, 0x30, 0x06,
    0x58, 0x01, 0x1A, 0x10, 0x10, 0x80, 0x80, 0x80, 0x02, 0x18, 0x80, 0x80,
    0xF4, 0x08, 0x28, 0x08, 0x62, 0x02, 0x04, 0x05, 0x1A, 0x0E, 0x10, 0x80,
    0x80, 0x04, 0x18, 0x80, 0xC0, 0xFB, 0x07, 0x28, 0x0A, 0x62, 0x01, 0x08,
    0x22, 0x0B, 0x18, 0xDB, 0xC1, 0x43, 0x22, 0x02, 0x08, 0x01, 0x3A, 0x01,
    0x00, 0x22, 0x0C, 0x18, 0xC7, 0x8B, 0xD2, 0x0A, 0x22, 0x02, 0x08, 0x02,
    0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xB7, 0x94, 0x3A, 0x22, 0x02, 0x08,
    0x03, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xF7, 0x96, 0x3D, 0x22, 0x02,
    0x08, 0x04, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0x87, 0xFA, 0x01, 0x22,
    0x02, 0x08, 0x05, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xC3, 0xD6, 0xA1,
    0x02, 0x22, 0x02, 0x08, 0x06, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xBB,
    0xB5, 0xB3, 0x02, 0x22, 0x02, 0x08, 0x07, 0x3A, 0x01, 0x00, 0x22, 0x0C,
    0x18, 0xE7, 0xB7, 0xB3, 0x02, 0x22, 0x02, 0x08, 0x08, 0x3A, 0x01, 0x00,
    0x22, 0x0C, 0x18, 0x93, 0xD5, 0xB9, 0x01, 0x22, 0x02, 0x08, 0x09, 0x3A,
    0x01, 0x00, 0x22, 0x0C, 0x18, 0xD7, 0x8C, 0xB8, 0x01, 0x22, 0x02, 0x08,
    0x0A, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0x97, 0x93, 0xBA, 0x01, 0x22,
    0x02, 0x08, 0x0B, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0x9F, 0xA8, 0xBA,
    0x01, 0x22, 0x02, 0x08, 0x0C, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xEB,
    0xFA, 0x08, 0x22, 0x02, 0x08, 0x0D, 0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18,
    0xD3, 0xFE, 0x08, 0x22, 0x02, 0x08, 0x0E, 0x3A, 0x01, 0x00, 0x22, 0x0B,
    0x18, 0xB7, 0xFF, 0x08, 0x22, 0x02, 0x08, 0x0F, 0x3A, 0x01, 0x00, 0x22,
    0x0C, 0x18, 0xA7, 0xBD, 0xCF, 0x0A, 0x22, 0x02, 0x08, 0x10, 0x3A, 0x01,
    0x00, 0x22, 0x0C, 0x18, 0xCF, 0xCA, 0xCF, 0x0A, 0x22, 0x02, 0x08, 0x11,
    0x3A, 0x01, 0x00, 0x22, 0x0A, 0x18, 0xC7, 0x3C, 0x22, 0x02, 0x08, 0x12,
    0x3A, 0x01, 0x00, 0x22, 0x0A, 0x10, 0x01, 0x18, 0x9F, 0xA6, 0x81, 0x02,
    0x3A, 0x01, 0x03, 0x22, 0x0C, 0x18, 0x9F, 0xCD, 0xA9, 0x02, 0x22, 0x02,
    0x08, 0x13, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xC3, 0xDF, 0xAC, 0x02,
    0x22, 0x02, 0x08, 0x14, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xB3, 0x9F,
    0xAD, 0x02, 0x22, 0x02, 0x08, 0x15, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18,
    0x9B, 0xE1, 0xA0, 0x02, 0x22, 0x02, 0x08, 0x16, 0x3A, 0x01, 0x00, 0x22,
    0x0C, 0x18, 0xCB, 0xE8, 0x86, 0x09, 0x22, 0x02, 0x08, 0x17, 0x3A, 0x01,
    0x00, 0x22, 0x0C, 0x18, 0xEB, 0xE3, 0x87, 0x09, 0x22, 0x02, 0x08, 0x18,
    0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xFB, 0xAE, 0xFE, 0x09, 0x22, 0x02,
    0x08, 0x19, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xE7, 0xB0, 0xFE, 0x09,
    0x22, 0x02, 0x08, 0x1A, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xEF, 0x90,
    0x85, 0x09, 0x22, 0x02, 0x08, 0x1B, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18,
    0xF7, 0xF3, 0x85, 0x09, 0x22, 0x02, 0x08, 0x1C, 0x3A, 0x01, 0x00, 0x22,
    0x0C, 0x18, 0xCB, 0xF5, 0x85, 0x09, 0x22, 0x02, 0x08, 0x1D, 0x3A, 0x01,
    0x00, 0x22, 0x0B, 0x18, 0xEB, 0xFA, 0x08, 0x22, 0x02, 0x08, 0x0D, 0x3A,
    0x01, 0x00, 0x22, 0x0B, 0x18, 0xD3, 0xFE, 0x08, 0x22, 0x02, 0x08, 0x0E,
    0x3A, 0x01, 0x00, 0x22, 0x0B, 0x18, 0xB7, 0xFF, 0x08, 0x22, 0x02, 0x08,
    0x0F, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xA7, 0xBD, 0xCF, 0x0A, 0x22,
    0x02, 0x08, 0x10, 0x3A, 0x01, 0x00, 0x22, 0x0C, 0x18, 0xCF, 0xCA, 0xCF,
    0x0A, 0x22, 0x02, 0x08, 0x11, 0x3A, 0x01, 0x00, 0x22, 0x0A, 0x18, 0xC7,
    0x3C, 0x22, 0x02, 0x08, 0x12, 0x3A, 0x01, 0x00, 0x22, 0x09, 0x10, 0x02,
    0x18, 0xAF, 0xBF, 0x05, 0x3A, 0x01, 0x03, 0x2A, 0x00, 0x2A, 0x02, 0x10,
    0x18, 0x2A, 0x02, 0x10, 0x10, 0x2A, 0x02, 0x10, 0x24, 0x2A, 0x02, 0x10,
    0x19, 0x2A, 0x02, 0x10, 0x21, 0x2A, 0x02, 0x10, 0x1A, 0x2A, 0x02, 0x10,
    0x25, 0x2A, 0x02, 0x10, 0x0B, 0x2A, 0x02, 0x10, 0x26, 0x2A, 0x02, 0x10,
    0x11, 0x2A, 0x02, 0x10, 0x14, 0x2A, 0x02, 0x10, 0x15, 0x2A, 0x02, 0x10,
    0x12, 0x2A, 0x02, 0x10, 0x22, 0x2A, 0x02, 0x10, 0x16, 0x2A, 0x02, 0x10,
    0x0E, 0x2A, 0x02, 0x10, 0x1B, 0x2A, 0x02, 0x10, 0x1E, 0x2A, 0x02, 0x10,
    0x17, 0x2A, 0x02, 0x10, 0x27, 0x2A, 0x02, 0x10, 0x0C, 0x2A, 0x02, 0x10,
    0x13, 0x2A, 0x02, 0x10, 0x1F, 0x2A, 0x02, 0x10, 0x23, 0x2A, 0x02, 0x10,
    0x0F, 0x2A, 0x02, 0x10, 0x1C, 0x2A, 0x02, 0x10, 0x0D, 0x2A, 0x02, 0x10,
    0x20, 0x2A, 0x02, 0x10, 0x1D, 0x32, 0x00, 0x32, 0x07, 0x73, 0x61, 0x6D,
    0x70, 0x6C, 0x65, 0x73, 0x32, 0x05, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x32,
    0x03, 0x63, 0x70, 0x75, 0x32, 0x0B, 0x6E, 0x61, 0x6E, 0x6F, 0x73, 0x65,
    0x63, 0x6F, 0x6E, 0x64, 0x73, 0x32, 0x16, 0x41, 0x54, 0x73, 0x51, 0x46,
    0x31, 0x72, 0x72, 0x49, 0x63, 0x30, 0x35, 0x74, 0x65, 0x6A, 0x66, 0x79,
    0x65, 0x73, 0x5A, 0x52, 0x77, 0x32, 0x20, 0x62, 0x61, 0x31, 0x63, 0x39,
    0x61, 0x35, 0x61, 0x38, 0x32, 0x35, 0x36, 0x61, 0x36, 0x65, 0x66, 0x33,
    0x65, 0x36, 0x36, 0x33, 0x63, 0x63, 0x37, 0x33, 0x31, 0x36, 0x38, 0x30,
    0x33, 0x64, 0x39, 0x32, 0x16, 0x7A, 0x6A, 0x32, 0x51, 0x75, 0x43, 0x52,
    0x61, 0x70, 0x75, 0x6E, 0x30, 0x32, 0x73, 0x79, 0x68, 0x6C, 0x41, 0x48,
    0x71, 0x54, 0x77, 0x32, 0x0D, 0x65, 0x62, 0x70, 0x66, 0x2D, 0x70, 0x72,
    0x6F, 0x66, 0x69, 0x6C, 0x65, 0x72, 0x32, 0x16, 0x36, 0x34, 0x41, 0x49,
    0x75, 0x76, 0x39, 0x69, 0x70, 0x47, 0x42, 0x41, 0x41, 0x64, 0x30, 0x52,
    0x5A, 0x6D, 0x76, 0x4C, 0x4C, 0x77, 0x32, 0x0A, 0x63, 0x6F, 0x6E, 0x74,
    0x61, 0x69, 0x6E, 0x65, 0x72, 0x64, 0x32, 0x13, 0x5F, 0x5F, 0x63, 0x68,
    0x65, 0x63, 0x6B, 0x5F, 0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x5F, 0x73,
    0x69, 0x7A, 0x65, 0x32, 0x11, 0x6F, 0x62, 0x6A, 0x5F, 0x63, 0x67, 0x72,
    0x6F, 0x75, 0x70, 0x5F, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x32, 0x0D,
    0x5F, 0x5F, 0x73, 0x6F, 0x63, 0x6B, 0x5F, 0x63, 0x72, 0x65, 0x61, 0x74,
    0x65, 0x32, 0x07, 0x65, 0x6C, 0x30, 0x5F, 0x73, 0x76, 0x63, 0x32, 0x0C,
    0x75, 0x6E, 0x69, 0x78, 0x5F, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x31,
    0x32, 0x08, 0x73, 0x63, 0x68, 0x65, 0x64, 0x75, 0x6C, 0x65, 0x32, 0x10,
    0x62, 0x70, 0x66, 0x5F, 0x6D, 0x61, 0x70, 0x5F, 0x64, 0x6F, 0x5F, 0x62,
    0x61, 0x74, 0x63, 0x68, 0x32, 0x0E, 0x69, 0x6E, 0x76, 0x6F, 0x6B, 0x65,
    0x5F, 0x73, 0x79, 0x73, 0x63, 0x61, 0x6C, 0x6C, 0x32, 0x10, 0x6B, 0x6D,
    0x65, 0x6D, 0x5F, 0x63, 0x61, 0x63, 0x68, 0x65, 0x5F, 0x61, 0x6C, 0x6C,
    0x6F, 0x63, 0x32, 0x09, 0x5F, 0x5F, 0x73, 0x79, 0x73, 0x5F, 0x62, 0x70,
    0x66, 0x32, 0x0F, 0x5F, 0x5F, 0x61, 0x72, 0x6D, 0x36, 0x34, 0x5F, 0x73,
    0x79, 0x73, 0x5F, 0x62, 0x70, 0x66, 0x32, 0x0A, 0x64, 0x6F, 0x5F, 0x65,
    0x6C, 0x30, 0x5F, 0x73, 0x76, 0x63, 0x32, 0x19, 0x70, 0x72, 0x6F, 0x70,
    0x61, 0x67, 0x61, 0x74, 0x65, 0x5F, 0x70, 0x72, 0x6F, 0x74, 0x65, 0x63,
    0x74, 0x65, 0x64, 0x5F, 0x75, 0x73, 0x61, 0x67, 0x65, 0x32, 0x19, 0x66,
    0x69, 0x6E, 0x69, 0x73, 0x68, 0x5F, 0x74, 0x61, 0x73, 0x6B, 0x5F, 0x73,
    0x77, 0x69, 0x74, 0x63, 0x68, 0x2E, 0x69, 0x73, 0x72, 0x61, 0x2E, 0x30,
    0x32, 0x07, 0x6B, 0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x32, 0x13, 0x5F,
    0x5F, 0x63, 0x68, 0x65, 0x63, 0x6B, 0x5F, 0x68, 0x65, 0x61, 0x70, 0x5F,
    0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x32, 0x14, 0x65, 0x6C, 0x30, 0x74,
    0x5F, 0x36, 0x34, 0x5F, 0x73, 0x79, 0x6E, 0x63, 0x5F, 0x68, 0x61, 0x6E,
    0x64, 0x6C, 0x65, 0x72, 0x32, 0x0B, 0x75, 0x6E, 0x69, 0x78, 0x5F, 0x63,
    0x72, 0x65, 0x61, 0x74, 0x65, 0x32, 0x12, 0x5F, 0x5F, 0x61, 0x72, 0x6D,
    0x36, 0x34, 0x5F, 0x73, 0x79, 0x73, 0x5F, 0x73, 0x6F, 0x63, 0x6B, 0x65,
    0x74, 0x32, 0x0C, 0x65, 0x6C, 0x30, 0x74, 0x5F, 0x36, 0x34, 0x5F, 0x73,
    0x79, 0x6E, 0x63, 0x32, 0x0D, 0x73, 0x6B, 0x5F, 0x70, 0x72, 0x6F, 0x74,
    0x5F, 0x61, 0x6C, 0x6C, 0x6F, 0x63, 0x32, 0x0C, 0x5F, 0x5F, 0x73, 0x79,
    0x73, 0x5F, 0x73, 0x6F, 0x63, 0x6B, 0x65, 0x74, 0x32, 0x0D, 0x72, 0x65,
    0x74, 0x5F, 0x66, 0x72, 0x6F, 0x6D, 0x5F, 0x66, 0x6F, 0x72, 0x6B, 0x32,
    0x1A, 0x65, 0x6C, 0x30, 0x5F, 0x73, 0x76, 0x63, 0x5F, 0x63, 0x6F, 0x6D,
    0x6D, 0x6F, 0x6E, 0x2E, 0x63, 0x6F, 0x6E, 0x73, 0x74, 0x70, 0x72, 0x6F,
    0x70, 0x2E, 0x30, 0x32, 0x08, 0x73, 0x6B, 0x5F, 0x61, 0x6C, 0x6C, 0x6F,
    0x63, 0x32, 0x0D, 0x77, 0x6F, 0x72, 0x6B, 0x65, 0x72, 0x5F, 0x74, 0x68,
    0x72, 0x65, 0x61, 0x64, 0x32, 0x1A, 0x5F, 0x5F, 0x63, 0x68, 0x65, 0x63,
    0x6B, 0x5F, 0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x5F, 0x73, 0x69, 0x7A,
    0x65, 0x2E, 0x70, 0x61, 0x72, 0x74, 0x2E, 0x30, 0x32, 0x18, 0x67, 0x65,
    0x6E, 0x65, 0x72, 0x69, 0x63, 0x5F, 0x6D, 0x61, 0x70, 0x5F, 0x75, 0x70,
    0x64, 0x61, 0x74, 0x65, 0x5F, 0x62, 0x61, 0x74, 0x63, 0x68, 0x32, 0x10,
    0x74, 0x72, 0x79, 0x5F, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x5F, 0x6D,
    0x65, 0x6D, 0x63, 0x67, 0x48, 0xE9, 0xF2, 0xB0, 0xE5, 0xB2, 0xEA, 0xB1,
    0x82, 0x18, 0x5A, 0x04, 0x08, 0x03, 0x10, 0x04, 0x60, 0x80, 0xE1, 0xEB,
    0x17, 0x7A, 0x25, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14,
    0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x21, 0x22, 0x23, 0x24, 0x82, 0x01, 0x1E, 0x0A, 0x12, 0x70, 0x72, 0x6F,
    0x66, 0x69, 0x6C, 0x65, 0x2E, 0x66, 0x72, 0x61, 0x6D, 0x65, 0x2E, 0x74,
    0x79, 0x70, 0x65, 0x12, 0x08, 0x0A, 0x06, 0x6B, 0x65, 0x72, 0x6E, 0x65,
    0x6C, 0x82, 0x01, 0x13, 0x0A, 0x0C, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69,
    0x6E, 0x65, 0x72, 0x2E, 0x69, 0x64, 0x12, 0x03, 0x0A, 0x01, 0x2F, 0x82,
    0x01, 0x1C, 0x0A, 0x0B, 0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x2E, 0x6E,
    0x61, 0x6D, 0x65, 0x12, 0x0D, 0x0A, 0x0B, 0x6B, 0x77, 0x6F, 0x72, 0x6B,
    0x65, 0x72, 0x2F, 0x36, 0x3A, 0x31, 0x82, 0x01, 0x1E, 0x0A, 0x12, 0x70,
    0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x2E, 0x66, 0x72, 0x61, 0x6D, 0x65,
    0x2E, 0x74, 0x79, 0x70, 0x65, 0x12, 0x08, 0x0A, 0x06, 0x6E, 0x61, 0x74,
    0x69, 0x76, 0x65, 0x82, 0x01, 0x4D, 0x0A, 0x1F, 0x70, 0x72, 0x6F, 0x63,
    0x65, 0x73, 0x73, 0x2E, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x61, 0x62,
    0x6C, 0x65, 0x2E, 0x62, 0x75, 0x69, 0x6C, 0x64, 0x5F, 0x69, 0x64, 0x2E,
    0x67, 0x6E, 0x75, 0x12, 0x2A, 0x0A, 0x28, 0x33, 0x34, 0x31, 0x39, 0x61,
    0x33, 0x65, 0x66, 0x30, 0x30, 0x31, 0x35, 0x34, 0x35, 0x64, 0x38, 0x65,
    0x65, 0x39, 0x66, 0x63, 0x64, 0x34, 0x62, 0x31, 0x38, 0x64, 0x34, 0x63,
    0x65, 0x31, 0x37, 0x32, 0x30, 0x35, 0x37, 0x65, 0x33, 0x33, 0x39, 0x82,
    0x01, 0x4B, 0x0A, 0x25, 0x70, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x2E,
    0x65, 0x78, 0x65, 0x63, 0x75, 0x74, 0x61, 0x62, 0x6C, 0x65, 0x2E, 0x62,
    0x75, 0x69, 0x6C, 0x64, 0x5F, 0x69, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x66,
    0x69, 0x6C, 0x69, 0x6E, 0x67, 0x12, 0x22, 0x0A, 0x20, 0x37, 0x30, 0x35,
    0x62, 0x64, 0x66, 0x31, 0x34, 0x39, 0x38, 0x30, 0x66, 0x32, 0x63, 0x32,
    0x32, 0x64, 0x63, 0x34, 0x64, 0x65, 0x32, 0x65, 0x36, 0x35, 0x37, 0x36,
    0x65, 0x64, 0x66, 0x66, 0x38, 0x82, 0x01, 0x3C, 0x0A, 0x0C, 0x63, 0x6F,
    0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, 0x72, 0x2E, 0x69, 0x64, 0x12, 0x2C,
    0x0A, 0x2A, 0x2F, 0x75, 0x73, 0x65, 0x72, 0x2E, 0x73, 0x6C, 0x69, 0x63,
    0x65, 0x2F, 0x75, 0x73, 0x65, 0x72, 0x2D, 0x35, 0x30, 0x31, 0x2E, 0x73,
    0x6C, 0x69, 0x63, 0x65, 0x2F, 0x73, 0x65, 0x73, 0x73, 0x69, 0x6F, 0x6E,
    0x2D, 0x32, 0x2E, 0x73, 0x63, 0x6F, 0x70, 0x65, 0x82, 0x01, 0x1E, 0x0A,
    0x0B, 0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x2E, 0x6E, 0x61, 0x6D, 0x65,
    0x12, 0x0F, 0x0A, 0x0D, 0x65, 0x62, 0x70, 0x66, 0x2D, 0x70, 0x72, 0x6F,
    0x66, 0x69, 0x6C, 0x65, 0x72, 0x82, 0x01, 0x4B, 0x0A, 0x25, 0x70, 0x72,
    0x6F, 0x63, 0x65, 0x73, 0x73, 0x2E, 0x65, 0x78, 0x65, 0x63, 0x75, 0x74,
    0x61, 0x62, 0x6C, 0x65, 0x2E, 0x62, 0x75, 0x69, 0x6C, 0x64, 0x5F, 0x69,
    0x64, 0x2E, 0x70, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x69, 0x6E, 0x67, 0x12,
    0x22, 0x0A, 0x20, 0x64, 0x37, 0x38, 0x30, 0x31, 0x36, 0x30, 0x34, 0x65,
    0x38, 0x62, 0x38, 0x39, 0x64, 0x64, 0x61, 0x63, 0x66, 0x65, 0x31, 0x39,
    0x38, 0x39, 0x39, 0x64, 0x36, 0x62, 0x61, 0x33, 0x35, 0x36, 0x34, 0x82,
    0x01, 0x5A, 0x0A, 0x0C, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65,
    0x72, 0x2E, 0x69, 0x64, 0x12, 0x4A, 0x0A, 0x48, 0x2F, 0x75, 0x73, 0x65,
    0x72, 0x2E, 0x73, 0x6C, 0x69, 0x63, 0x65, 0x2F, 0x75, 0x73, 0x65, 0x72,
    0x2D, 0x35, 0x30, 0x31, 0x2E, 0x73, 0x6C, 0x69, 0x63, 0x65, 0x2F, 0x75,
    0x73, 0x65, 0x72, 0x40, 0x35, 0x30, 0x31, 0x2E, 0x73, 0x65, 0x72, 0x76,
    0x69, 0x63, 0x65, 0x2F, 0x61, 0x70, 0x70, 0x2E, 0x73, 0x6C, 0x69, 0x63,
    0x65, 0x2F, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65, 0x72, 0x64,
    0x2E, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x82, 0x01, 0x1B, 0x0A,
    0x0B, 0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x2E, 0x6E, 0x61, 0x6D, 0x65,
    0x12, 0x0C, 0x0A, 0x0A, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x65,
    0x72, 0x64
};

static void test_encoder()
{
    cfl_sds_t     otlp_encoder_result;
    struct cprof *context;
    int           result;
    size_t        offset;

    offset = 0;
    context = NULL;

    result = cprof_decode_opentelemetry_create(&context,
                                               serialized_data,
                                               sizeof(serialized_data),
                                               &offset);

    TEST_CHECK(result == CPROF_DECODE_OPENTELEMETRY_SUCCESS);

    if (result == CPROF_DECODE_OPENTELEMETRY_SUCCESS) {
        result = cprof_encode_opentelemetry_create(&otlp_encoder_result, context);

        TEST_CHECK(result == CPROF_ENCODE_OPENTELEMETRY_SUCCESS);

        if (result == CPROF_ENCODE_OPENTELEMETRY_SUCCESS) {
            cprof_encode_opentelemetry_destroy(otlp_encoder_result);
        }

        cprof_decode_opentelemetry_destroy(context);
    }
}

static void test_decoder()
{
    struct cprof *context;
    int           result;
    size_t        offset;

    offset = 0;
    context = NULL;

    result = cprof_decode_opentelemetry_create(&context,
                                               serialized_data,
                                               sizeof(serialized_data),
                                               &offset);

    TEST_CHECK(result == CPROF_DECODE_OPENTELEMETRY_SUCCESS);

    if (result == CPROF_DECODE_OPENTELEMETRY_SUCCESS) {
        cprof_decode_opentelemetry_destroy(context);
    }
}

TEST_LIST = {
    {"encoder", test_encoder},
    {"decoder", test_decoder},
    { 0 }
};
