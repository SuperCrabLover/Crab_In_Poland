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
		if (NULL != hash_map[i]) 
		{
			list_del(hash_map[i]);
			hash_map[i] = NULL;
		}
	}
}

void add(char *surname, unsigned long long number)
{
	unsigned int index = hash(surname);
	PERSON node;
	node.number = number;
	node.surname = surname;
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
		return find_l(hash_map[index], surname);
	}
}


void del(char *surname)
{
	unsigned int index = hash(surname);
	if (NULL == hash_map[index])
	{
		return -1;
	}
	if (NULL != hash_map[index])
	{
		list_del(hash_map[index]);
	}
	hash_map[index] = NULL;
}
