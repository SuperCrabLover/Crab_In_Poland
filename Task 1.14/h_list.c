#include "common.h"

LIST *list_new()
{
	LIST *list = (LIST *)malloc(sizeof(LIST));
	if (NULL == list)
	{
		exit(-1);
	}
	list->first = NULL;
	return list;
}

void list_del(LIST *l)
{
	if (l == NULL)
	{
		return -1;
	}
	LIST_NODE *node = l->first;
	LIST_NODE *tmp;
	while (node->next)
	{
		tmp = node->next;
		free(node);
		node = NULL;
		node = tmp;
	}
	free(node);
	node = NULL;
	free(l);
	l = NULL;
}

LIST *find_l(LIST *l, char *surname)
{
	LIST *ans_list = list_new();
	LIST_NODE *node = l->first;
	while (node)
	{
		if (strcmp(node->value.surname, surname) == 0)
		{
			unshift(ans_list, node->value);
		}
		node = node->next;
	}
	return ans_list;
}

void unshift(LIST *l, PERSON a)
{
	LIST_NODE *new = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (NULL == new)
	{
		return -1;
	}
	new->value = a;
	new->next = l->first;
	new->prev = NULL;
	if (l->first)
	{
		l->first->prev = new;
	}
	l->first = new;
}

void print_dl_list(LIST *l)
{
	if (NULL == l)
	{
		printf("Error: this list doesnt exist!");
		return;
	}
	if (NULL == l->first)
	{
		printf("( )\n");
		return;
	}
	LIST_NODE *node = l->first;
	printf("(");
	while (node->next != NULL)
	{
		printf("(%s : %llu), ", node->value.surname, node->value.number);
		node = node->next;
	}
	printf("(%s : %llu))", node->value.surname, node->value.number);
}
