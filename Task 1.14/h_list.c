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

int list_del(LIST *l)
{
	if (l == NULL)
	{
		return 1;
	}
	LIST_NODE *node = l->first;
	LIST_NODE *tmp;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(l);
	l = NULL;
	return 0;
}

int unshift(LIST *l, PERSON a)
{
	LIST_NODE *new = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (NULL == new)
	{
		return 1;
	}
	new->value = a;
	new->next = l->first;
	new->prev = NULL;
	if (l->first)
	{
		l->first->prev = new;
	}
	l->first = new;
	return 0;
}

void print_dl_list(LIST *l)
{
	if (NULL == l)
	{
		printf("Error: this list doesnt exist!");
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
