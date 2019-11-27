/*
 * File:  double_list_1.3.h
 * Brief: Double linked list header
 * Created on 27.11.2019
 * Autor: Makarov Gleb
 */

#pragma once

typedef struct _LIST_NODE
{
	int value;
	LIST_NODE *prev;
	LIST_NODE *next;
} LIST_NODE;

typedef struct _LIST
{
	LIST_NODE *first;
} LIST;

LIST *list_new()
{

}

int list_del(LIST *l)
{

}

int push(LIST *l, int a)
{

}

int pop(LIST *list, int *value)
{

}

int unshift(LIST *list, int value)
{

}

int shift(LIST *list, int *value)
{

}
