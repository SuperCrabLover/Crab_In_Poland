#include <stdlib.h>
#include <stdio.h>
#include "sl_list.h"
#define MALLOC_ERROR -1
#define ROOT_VALUE 42

int main(void)                  // 
{
	struct list* un = NULL;//Как видишь, я могу удалить лист, а затем прочитать его и вызвать ошибку.
	un = create_root();
	printf("\n");
	create_bare_list(un, 10);
	insert_value(un, 5);
	print_list(un);
	delete_list(un);
	print_list(un);
	return 0;
}