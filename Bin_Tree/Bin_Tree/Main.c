
/*
* main 1.8.c
* Main for 1.8 task
* Created 14.12.2019
* (c) MIPT 2019
*/

#define N 10
#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

void test_code_anhibilator()
{
	struct node* n2 = create_node(1);
	int i;
	for (i = 0; i < N; i++)
	{
		insert_node(n2, i + (rand() % 10));
	}

	delete_node(n2, 1);
	printf("\n");
}

void test_Beklemishev_and_Shankov_bizzare_team()
{
	//значение 16 не удаляется
	struct node* n2 = create_node(16);
	int i;
	printf("\n");
	delete_node(n2, 16);
	printf("\n");
	insert_node(n2, 22);
}
int main(void)
{
	test_code_anhibilator();
	//Как следует из названия, этот тест ломает код.

	test_Beklemishev_and_Shankov_bizzare_team();

	return 0;
}