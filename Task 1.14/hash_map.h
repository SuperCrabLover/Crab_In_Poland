#pragma once

#include "h_list.h"
#define N 16

LIST *hash_map[N];

void hash_map_init(void);

void hash_map_deinit(void);

void add(char *surname, unsigned long long number);

unsigned int del(char *surname);

LIST *find(char *surname);
