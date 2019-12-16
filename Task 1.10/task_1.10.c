  
/*
 * File:  task_1.10.c
 * Brief: task 1.10 solution
 * Autor: code squad 1337
 * Created on 16.12.2019
 * (c) MIPT 2019
 */

#include "common.h"

void insert(char *name, unsigned long long num)
{
	unsigned long long old_num = 0;
	if (NULL == find(name))
	{
		add(name, num);
		printf("OK\n");
	}
	else
	{
		old_num = find(name)->first->value.number;
		del(name);
		add(name, num);
		printf("Changed. Old value = %llu\n", old_num);
	}
}

int main(void)
{
	char c;
	char name[30];
	char com[10];
	unsigned long long num = 0;
	hash_map_init();
	while ((c = getchar()) != '\0')
	{
		ungetc(c, stdin);
		if ((c = getchar()) != ',')
		{
			ungetc(c, stdin);
		}
		scanf("%s %s", com, name);
		if (com[0] == 'I')
		{
			scanf("%llu", &num);
			insert(name, num);
		}
		if (com[0] == 'F')
		{
			if (NULL == find(name))
			{
				printf("NO\n");
			}
			else
			{
				printf("%llu", find(name)->first->value.number);
			}
		}
	}
	return 0;
}
