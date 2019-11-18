#define MALLOC_ERROR -1
#define NULL_ERROR -1
#define ROOT_VALUE 42
#define NO_VALUE 0
#include <stdlib.h>
#include <stdio.h>

struct list
{
	int value;
	struct list* next;
};

struct list* create_root(void)
{
	struct list* root;
	root = (struct list*)malloc(sizeof(struct list));
	if (root == NULL)
	{
		return NULL;
	}
	root->value = ROOT_VALUE;
	root->next = NULL;
	return root;
}

struct list* create_unit(int seed)
{
	struct list* unit;
	unit = (struct list*)malloc(sizeof(struct list));
	if (unit == NULL)
	{
		printf("Unit pointer is NULL. Something went worng. Try again.\n");
		return NULL;
	}
	unit->value = seed;
	unit->next = NULL;
	return unit;
}

//adds a unit into the end of the list
struct link* add_to_end(struct list* temp, struct list* tail)
{
	if (NULL == temp)
	{
		printf("add_to_end() error:\nThe pointer to a unit is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	tail->next = temp;
	return tail->next;
}

//creates an empty list without value (all values are zero)
void create_bare_list(struct list* root, int amountOfUnits)  
{
	if (NULL == root)
	{
		printf("create_bare_list() error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	int i;
	while (amountOfUnits == 0 || amountOfUnits <= 0)
	{
		printf("Create_bare_list() error:\nAmount of units can't be zero or less!\nPlease, reinsert the value:\n");
		scanf_s("%d", &amountOfUnits);
	}
	struct list* unit;//temporary variable for moving forward through the list
	struct list* tail = root;//a variable to store the NULL pointer fo add_to_the_end
	struct list* temp = root;
	for (i = 0; i < amountOfUnits; ++i)
	{
		unit = create_unit(NO_VALUE);
		tail = add_to_end(unit, tail);
	}
}

//inserts value into a list from begining till amountOfUnits
void insert_value(struct list* root, int amountOfUnits)
{
	if (NULL == root)
	{
		printf("insert_value() error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	int i, seed;
	while (amountOfUnits == 0 || amountOfUnits <= 0)
	{
		printf("insert_value() error:\nAmount of units can't be zero or less!\nPlease, reinsert the value:\n");
		scanf_s("%d", &amountOfUnits);
	}
	struct list* temp = root->next;
	for (i = 0; i < amountOfUnits; ++i)
	{
		printf("Insert the %d value of the list\n", i + 1);
		scanf_s("%d", &seed);
		temp->value = seed;
		temp = temp->next;
	}
}

//creates list with value in it
void read_list(struct list* root, int amountOfUnits)
{
	if (NULL == root)
	{
		printf("read_list() error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	int i, seed;
	while (amountOfUnits == 0 || amountOfUnits <= 0)
	{
		printf("Read_list error:\nAmount of units can't be zero or less!\nPlease, reinsert the value:\n");
		scanf_s("%d", &amountOfUnits);
	}
	struct list* unit;//temporary variable for moving forward through the list
	struct list* tail = root;//a variable to store the NULL pointer fo add_to_the_end
	struct list* temp = root;
	for (i = 0; i < amountOfUnits; ++i)
	{
		printf("Insert the %d value of the list\n", i + 1);
		scanf_s("%d", &seed);
		unit = create_unit(seed);
		tail = add_to_end(unit, tail);
	}
}

void print_list(struct list* root)
{
	if (NULL == root)
	{
		printf("print_list error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	struct list* temp = root->next;//temporary variables for moving forward through the list
	int i = 1;
	while (temp != NULL)
	{
		printf(" the %d value is %d\n", i, temp->value);
		temp = temp->next;
		++i;
	}

}

void add_to_middle(struct list* root, int amountOfUnits)
{
	if (NULL == root)
	{
		printf("add_to_middle() error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	int i;
	struct list* temp = root;
	int position;
	printf("Insert the position (integer) for a new unit int the list\n");
	scanf_s("%d", &position);
	while (amountOfUnits == 0 || amountOfUnits <= 0)
	{
		printf("add_to_middle() error:\nAmount of units can't be zero or less!\nPlease, reinsert the value:\n");
		scanf_s("%d", &amountOfUnits);
	}
	while ((position > amountOfUnits) || (position <= 0))
	{
		printf("The integer should be less than amount of units in the list and more than zero!\nInsert your integer again\n");
		scanf_s("%d", &position);
	}
	int seed;
	printf("Insert the value into the new unit\n");
	scanf_s("%d", &seed);
	struct list* unit = create_unit(seed);
	for (i = 1; i < position; ++i)
	{
		temp = temp->next;
	}
	unit->next = temp->next;
	temp->next = unit;
}

struct list* find_unit(struct list* root, int amountOfUnits)
{
	if (NULL == root)
	{
		printf("find_unit() error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	while (amountOfUnits == 0 || amountOfUnits <= 0)
	{
		printf("find_unit() error:\nAmount of units can't be zero or less!\nPlease, reinsert the value:\n");
		scanf_s("%d", &amountOfUnits);
	}
	struct list* temp = root;
	int i;
	printf("Insert the unit (integer) you wanna find\n");
	int position;
	scanf_s("%d", &position);
	while ((position > amountOfUnits) || (position <= 0))
	{
		printf("The integer should be less than amount of units in the list and more than zero!\nInsert your integer again\n");
		scanf_s("%d", &position);
	}
	for (i = 1; i <= position; ++i)
	{
		temp = temp->next;
	}
	printf("Found value is %d\n", temp->value);
	return temp;
}

void delete_unit(struct list* root, int amountOfUnits)
{
	if (NULL == root)
	{
		printf("delete_unit() error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	while (amountOfUnits == 0 || amountOfUnits <= 0)
	{
		printf("delete_unit() error:\nAmount of units can't be zero or less!\nPlease, reinsert the value:\n");
		scanf_s("%d", &amountOfUnits);
	}
	printf("Insert the position (integer) of the unit you wanna delete:\n");
	int position;
	scanf_s("%d", &position);
	while ((position > amountOfUnits) || (position <= 0))
	{
		printf("The integer should be less than amount of units in the list and more than zero!\nInsert your integer again\n");
		scanf_s("%d", &position);
	}
	printf("Deleting the %d unit...\n", position);
	struct list* temp1 = root;
	struct list* temp2 = root;
	int i;
	for (i = 1; i < position; ++i)
	{
		temp1 = temp1->next;
	}
	temp2 = temp1->next->next;
	printf("Deleting value is %d\n", temp1->next->value);
	free(temp1->next);
	temp1->next = temp2;
	printf("The unit %d was successfully deleted\n", position);
}

void delete_list(struct list* root)
{
	if (NULL == root)
	{
		printf("delete_list() error:\nThe root pointer is NULL!Something is wrong, check the input data!\n");
		return NULL_ERROR;
	}
	printf("Deleting the list...\n");
	struct list* temp1;
	struct list* temp2;
	temp1 = root->next;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		printf("deleting value %d...\n", temp1->value);
		free(temp1);
		temp1 = temp2;
	}
	free(root);
	printf("deleting finished successfully\n");
}
