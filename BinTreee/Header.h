/*
 * File:  Header.h 
 * Brief: Definitions for header for task 1.8 and 1.9 with BinTree
 * Author: Code squad 1337
 * Created on 18.11.2019
 * (c) MIPT 2019
 */
#pragma once
#define ROOT_PARENT NULL

typedef struct node{
	int value;
	struct node* left, * right;
}node;
node* tree_dfs(node* root);

node* find_node(node* root, int key);

node* find_nodeparent(node* parent, node* root, int key);

node* find_rightleafparent(node* parent, node* root);

void delete_leaf(node* leafparent, node* leaf);

void delete_node(node* root, int key);

node* tree_bfs(node* root);

node* create_node(int x);

node* insert_node(node* n, int x);

void print_node(node* n);
