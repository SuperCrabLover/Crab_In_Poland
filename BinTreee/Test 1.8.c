#include <stdio.h>
#include <stdlib.h>
#define MALLOC_ERROR -1
#define N 10

void test_1()
{
	struct node* n2 = create_node(12);
	int i;
	for (i = 0; i < N; i++)
	{
		n2 = insert_node(n2, i);
	}
	print_node(n2);
	printf("\n");
	n2 = tree_dfs(n2);
	
}
/*
В чём смысл в dfs и bfs возвращать значение структуры, если они выводят ответ в консоль
а dfs вообще возвращает число?
*/
void test_2()
{
	struct node* n2 = create_node(10);
	int i;
	for (i = 0; i < N; i++)
	{
		n2 = insert_node(n2, i + (rand() % 10));
	}
	print_node(n2);
	n2 = tree_bfs(n2);
}

void test_3()
{
	struct node* n2 = create_node(10);
	int i;
	for (i = 0; i < N; i++)
	{
		n2 = insert_node(n2, i + (rand() % 10));
	}
	n2 = insert_node(n2, 10);//Этот тест показывает наличие автоматической сортировки
	print_node(n2);
	printf("\n");
	struct node* n1 = find_node(n2, 3);
	print_node(n1);
	printf("\n");
	n2 = find_node(n2, 100);
	print_node(n2);
}

void test_4()
{
	struct node* n2 = create_node(10);
	int i;
	for (i = 0; i < N; i++)
	{
		n2 = insert_node(n2, i + (rand() % 10));
	}
	n2 = insert_node(n2, 10);
	print_node(n2);
	delete_node(n2, 10);
	printf("\n");
	print_node(n2);
	delete_node(n2, 100);
	printf("\n");
	print_node(n2);
}

void test_code_anhibilator()
{
	struct node* n2 = create_node(1);
	int i;
	for (i = 0; i < N; i++)
	{
		n2 = insert_node(n2, i + (rand() % 10));
	}
	print_node(n2);
	delete_node(n2, 1);
	printf("\n");
	print_node(n2);
}

void test_Beklemishev_and_Shankov_bizzare_team()
{
	//значение 16 не удаляется
	struct node* n2 = create_node(16);
	int i;
	print_node(n2);
	printf("\n");
	delete_node(n2, 16);
	print_node(n2);
	printf("\n");
	n2 = insert_node(n2, 22);
	print_node(n2);
}
