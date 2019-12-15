#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
#define MALLOC_ERROR -1

node* create_node(int x) {
	node* n = (node *)malloc(sizeof(node));
	if (NULL == n)
	{
		printf("create_node() error: MALLOC_ERROR");
		return MALLOC_ERROR;
	}
	n->value = x;
	n->left = n->right = NULL;
	return n;
}

node* insert_node(node* n, int x) {
	if (n == NULL)
		return create_node(x);
	if (n->value > x)
		n->left = insert_node(n->left, x);
	else
		n->right = insert_node(n->right, x);
	return n;
}

node* tree_dfs(node* root)
{		
	if (NULL == root)
	{
		return;
	}
	printf("%d\n", root->value);
	tree_dfs(root->left);
	tree_dfs(root->right);
}

node* tree_bfs(node* root)
{
	static int counter = 0;
	if (root == NULL)
		return NULL;
	printf("%d ", root->value);
	if (counter % 2 == 0)
	{
		counter++;
		tree_bfs(root->left);
	}
	counter = 1;
	if (counter % 2 == 1)
	{
		counter++;
		tree_bfs(root->right);
	}
}

node* find_rightleafparent(node* parent, node* root) //goes to the end of the tree (always to the right) from the given element
{ 
	
	if (root == NULL || root->right == NULL)
	{
		return parent;
	}
	return find_rightleafparent(root, root->right);
}

node* find_node(node* root, int key)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->value > key)
	{
		return find_node(root->left, key);
	}
	if (root->value < key)
	{
		return find_node(root->right, key);
	}
	if (root->value == key)
	{
		return root;
	}
}

node* find_nodeparent(node* parent, node* root, int key) // find_nodeparent(NULL, NODE*, INT) returns NULL if he didn't find any
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->value > key)
	{
		return find_nodeparent(root, root->left, key);
	}
	if (root->value < key)
	{
		return find_nodeparent(root, root->right, key);
	}
	if (root->value == key)
	{
		return parent;
	}
}

void delete_leaf(node* leafparent, node* leaf)
{
	if (leafparent == NULL)
	{
		printf("deleteleaf() error: leafparent is null\n");
		return;
	}
	if (leafparent->left == leaf)
	{
		free(leaf);
		leafparent->left = NULL;
	}
	if (leafparent->right == leaf)
	{
		leafparent->right = NULL;
		free(leaf);
	}
}

void delete_node(node* root, int key)
{
	node* deletingNode = find_node(root, key);
	if (deletingNode == NULL)
	{
		printf("delete_node() error: deleting node\n");
		return -1;
	}
	
	if (deletingNode->left == NULL && deletingNode->right == NULL)
	{
		delete_leaf(find_nodeparent(ROOT_PARENT, root, deletingNode->value), deletingNode);
		return;
	}

	if (deletingNode->left == NULL && NULL != deletingNode->right)
	{
		find_nodeparent(ROOT_PARENT, root, deletingNode->value)->right = deletingNode->right;
		//free(deletingNode);// I think it should be there
		return;
	}
	node* rightLeafParent = find_rightleafparent(ROOT_PARENT, deletingNode->left);
	
	if (rightLeafParent == NULL)
	{
		deletingNode->value = deletingNode->left->value;
		free(deletingNode->left);
		deletingNode->left = NULL;
		return;
	}

	deletingNode->value = rightLeafParent->right->value;
	free(rightLeafParent->right);
	rightLeafParent->right = NULL;
	//free(deletingNode);// I think it should be there
	return;
}

void deleteTree(node* root)
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

