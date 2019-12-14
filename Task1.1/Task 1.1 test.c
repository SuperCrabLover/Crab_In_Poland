/*
* Test1.1.c
* Brief task 1.1 testing
* Created 14.11.2019
* (c) MIPT 2019
*/
#include <stdio.h>
#include <stdlib.h>
void test1() //Базовый тест на работу всех сущесвующих функций
{
	int a;

	a = (rand() % 15) + 1;
	int b = rand() % a + 1;
	int c = rand() % 10 + 1;
	int d = rand() % 5 + 1;
	struct list *root1 = NULL;
	root1 = create_root();
	create_bare_list(root1, a);
	insert_value(root1, b);
	struct list *rt2 = create_unit(c);
	add_to_end(root1, rt2);
	print_list(root1);
	delete_unit(root1, d);
	delete_list(root1);

	struct list *rt1 = NULL;
	rt1 = create_root();
	read_list(rt1, c + 3);
	add_to_middle(rt1, c / 2 + 1);
	find_unit(rt1, d);
	print_list(rt1);
	delete_list(rt1);

	return 0;
}

void test2()//Ломает код
{
	struct list *un = NULL;//Как видишь, я могу удалить лист, а затем прочитать его и вызвать ошибку.
	un = create_root();
	printf("\n");
	create_bare_list(un, 10);
	insert_value(un, 5);
	print_list(un);
	delete_list(un);
	print_list(un);
}

void test_1337_gachi_king_code_breaker()//Кто вообще будет читать эти тесты?
{
	struct list *Dio = NULL;
	Dio = create_root();
	create_bare_list(Dio, 6);
	insert_value(Dio, 5);
	delete_unit(Dio, 600);//Здесь вводим значение 7. Ошибка в том, что я могу ввести число юнитов больше, чем длина списка. А затем сослаться на элемент вне списка. (Если длина списка 6, а я сошлюсь на 7 -ой)
	find_unit(Dio, 100);// Здесь тоже вводим значение 7. Тот же самый баг.
	print_list(Dio);
}

void test_jojo_ORA_ORA_ORA_code_destructor()
{
	struct list *ban = NULL;
	ban = create_bare_list(ban, 6);
	ban = create_bare_list(ban, 6);
}

void test_fixed_bug()
{
	struct list *Glad_Valakas = NULL;
	Glad_Valakas = create_root();
	Glad_Valakas = add_to_end(Glad_Valakas, NULL);
}

void test_Moon_prism_give_me_power()
{
	struct list *ok_boomer = NULL;
	ok_boomer = create_root();
	create_bare_list(ok_boomer, 6);
	insert_value(ok_boomer, 7);
	print_list(ok_boomer);
}
