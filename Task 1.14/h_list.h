#pragma once

typedef struct _PERSON
{
	char *surname;
	unsigned long long number;
} PERSON, *PPERSON;

typedef struct _LIST_NODE
{
	PERSON value;
	struct _LIST_NODE *prev;
	struct _LIST_NODE *next;
} LIST_NODE;

typedef struct _LIST
{
	LIST_NODE *first;
} LIST;

LIST *list_new();

int list_del(LIST *l);

int unshift(LIST *l, PERSON a);

int find_l(LIST *l, PERSON *x);

void print_dl_list(LIST *l);
