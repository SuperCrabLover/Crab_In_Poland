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
		return 0;
	}
	list->first = NULL;
	return list;
}

int list_del(LIST *l)
{

}

int push(LIST *l, int a)
{
	LIST_NODE *new = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (NULL == new)
	{
		return 0;
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
	return 1;
}

int pop(LIST *l, int *x)
{

}

int unshift(LIST *l, int a)
{
	LIST_NODE *new = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	new->value = a;
	new->next = l->first;
	new->prev = NULL;
	l->first->prev = new;
	l->first = new;
	return 1;
}

int shift(LIST *l, int *x)
{
	x = l->first->value;
	return 1;
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
	l->first = node;
}
