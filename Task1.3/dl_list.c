/*
* File:  dl_list.c
* Brief: Double linked list implementation
* Created on 01.12.2019
* Autor: Makarov Gleb
*/

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
	if (NULL == l)
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

int push(LIST *l, int a)
{
	LIST_NODE *new = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (NULL == new)
	{
		return 1;
	}
	LIST_NODE *tmp;
	tmp = l->first;
	new->value = a;
	new->next = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	new->prev = tmp;
	tmp->next = new;
	return 0;
}

int pop(LIST *l, int *x)
{
	if (NULL == l)
	{
		return 1;
	}
	LIST_NODE *tmp = l->first;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	*x = tmp->value;
	return 0;
}

int unshift(LIST *l, int a)
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

int shift(LIST *l, int *x)
{
	*x = l->first->value;
	return 0;
}

void reverse(LIST *l)
{
	LIST_NODE *node = l->first;
	LIST_NODE *tmp;
	while (node->next != NULL)
	{
		tmp = node->next;
		node->next = node->prev;
		node->prev = tmp;
		node = node->prev;
	}
	tmp = node->next;
	node->next = node->prev;
	node->prev = tmp;
	l->first = node;
}

void print_dl_list(LIST *l)
{
	if (NULL == l)
	{
		printf("Error: Sthis list doesnt exist!");
		return;
	}
	LIST_NODE *node = l->first;
	printf("(");
	while (node->next != NULL)
	{
		printf("%d, ", node->value);
		node = node->next;
	}
	printf("%d)\n", node->value);
}
