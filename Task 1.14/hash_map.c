#include "common.h"

unsigned int hash(char *surname)
{
	int s = 0;
	while (*surname)
	{
		s += *surname++;
	}
	return s % N;
}

void hash_map_init(void)
{

}

void hash_map_deinit(void)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (NULL != hash_map[i]->first->value.surname) {
			free(hash_map[i]->first->value.surname);
		}
	}
}

char *make_str(char *str)
{
	char *new_str = (char *)malloc(sizeof(strlen(str) + 1));
	if (NULL == new_str)
	{
		exit(-1);
	}
	strcpy(new_str, str);
	return new_str;
}

void add(char *surname, unsigned long long number)
{
	unsigned int index = hash(surname);
	PERSON node;
	node.number = number;
	node.surname = make_str(surname);
	if (NULL == hash_map[index])
	{
		hash_map[index] = list_new();
	}
	unshift(hash_map[index], node);
}

LIST *find(char *surname)
{
	unsigned int index = hash(surname);
	if (NULL != hash_map[index])
	{
		return hash_map[index];
	}
}

/*
int del(char *surname)
{
unsigned int index = hash(surname);

if (NULL == hash_map[index].surname)
{
return -1;
}
if (NULL != hash_map[index].surname)
{
free(hash_map[index].surname);
}
hash_map[index].surname = NULL;
return index;
}*/
