/*
* Test1.3.c
* Brief task 1.3 testing
* Created 15.12.2019
* (c) MIPT 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void test1() //Базовый тест на работу всех сущесвующих функций
{
int a = (rand() % 15) + 1;
int b = rand() % a + 1;
int c = rand() % 10 + 1;
int d = rand() % 5 + 1;
int x = 0;
LIST *l = list_new();
unshift(l, a);
unshift(l, b);
push(l, c);
push(l, d);
pop(l, &x);
if (x != d)
{
printf("Error");
exit(-1);
}
shift(l, &x);
if (x != a)
{
printf("Error");
exit(-1);
}
reverse(l);
list_del(l);
}
