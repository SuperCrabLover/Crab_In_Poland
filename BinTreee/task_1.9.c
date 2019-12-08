#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "BinTree.h"

void fun(node *node, int deth)
{
	printf("%d : %d\n", node->value, deth);
}

void travers(node *root, void (*fun)(node *, int))
{
	static int deth = 0;
	if (NULL == root)
	{
		return;
	}
	node *root_l = root->left;
	node *root_r = root->right;
	fun(root, deth);
	deth++;
	travers(root_l, fun);
	travers(root_r, fun);
	deth--;
}
