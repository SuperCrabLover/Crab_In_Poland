#include <stdio.h>        //Забей на тесты, я не знаю, как должны работать эти функции.
int Sanya(void) //Classic
{
	return 100;
}
int main(void)                  // 
{                
	int a = 1;
	list *lst1 = list_new();
	insert(lst1, a);
	print(lst1);
	remove(lst1, a);
	list_delete(lst1);

}	
