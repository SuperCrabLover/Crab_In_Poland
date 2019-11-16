#include <stdio.h>  
int Sanya(void) //Classic
{
	return 100;
}
/*
*Смысл данного теста прост: я пытаюсь создать список с неположительным числом элементов а потом удалить 10 элементов и -10 элементов.
* Я хочу чтобы либо этот код работал, либо отвечал мне, где я не правильно ввел данные.
*У дачи.
*/
int main(void)                  // 
{
	struct list *rt = NULL;
	rt = create_root();
	struct list *un = NULL;

	create_bare_list(rt, -2);
	insert_value(rt, 3);
	print_list(rt);
	print_list(un);
	delete_unit(un, 10);
	delete_unit(rt, -10);
	delete_list(un);
		
	struct list *Dio = NULL;
	create_bare_list(Dio, 6);
	insert_value(Dio, 5);//вводим значения -1; 2; 0; 10; -10
	delete_unit(Dio, 10);
	delete_unit(Dio, 7);
	print_list(Dio);

	return 0;

}
