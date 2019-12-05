#pragma once

#define N 16

typedef struct _NODE
{
	void *number;
	char *surname;
} NODE, *PNODE;

NODE hash_map[N];

void hash_map_init(void);

void hash_map_deinit(void);

unsigned int add(void *number, char *surname);

unsigned int del(void *number);

PNODE find(void *number);
