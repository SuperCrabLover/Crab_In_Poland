#include "common.h"

int main(void)
{
	char *a = "Ivanov";
	char *b = "Sidorov";
	char *c = "Petrov";
	char *d = "Makarov";
	char *e = "Tkach";
	char *f = "Ivanov";
	unsigned long long a1 = 1234567, b1 = 7654321, c1 = 1357264, d1 = 2641357, e1 = 7531264, f1 = 1326547;
	add(a, a1);
	add(b, b1);
	add(c, c1);
	add(d, d1);
	add(e, e1);
	add(f, f1);
	for (int i = 0; i < N; i++)
	{
		print_dl_list(hash_map[i]);
		printf("\n");
	}
	print_dl_list(find("Ivanov"));
	_getch();
	return 0;
}