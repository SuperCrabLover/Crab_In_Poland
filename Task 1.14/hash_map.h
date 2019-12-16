/*
 * File:  dl_list.h
 * Brief: Hash map header
 * Autor: code squad 1337
 * Created on 16.12.2019
 * (c) MIPT 2019
 */

#pragma once

#include "h_list.h"
#define N 16

LIST *hash_map[N];

void hash_map_init(void);

void hash_map_deinit(void);

void add(char *surname, unsigned long long number);

void del(char *surname);

LIST *find(char *surname);
