#define MALLOC_ERROR -1
#define NEGATIVE_VALUE -42
#define ROOT_VALUE 42
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

struct list* create_unit(seed)
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
	tail->next = temp;
	return tail->next;
}

//creates an empty list without value (all values are zero)
void create_bare_list(struct list* root, int amountOfUnits)
{
	int i;
	struct list* unit;//temporary variable for moving forward through the list
	struct list* tail = root;//a variable to store the NULL pointer fo add_to_the_end
	struct list* temp = root;
	for (i = 0; i < amountOfUnits; ++i)
	{
		unit = create_unit();
		tail = add_to_end(unit, tail);
	}
}

//inserts value into a list from begining till amountOfUnits
void insert_value(struct list* root, int amountOfUnits)
{
	int i, seed;
	struct list* temp = root->next;
	for (i = 0; i < amountOfUnits; ++i)
	{
		printf("Insert the %d value of the list\n", i + 1);
		scanf_s("%d", &seed);
		temp->value = seed;
		temp = temp->next;
	}
}

//creates list with values from N to 1
void first_integers(struct list* root, int valueofN)
{	
	if (valueofN < 0)
	{
		printf("Number of units can't be negative\n");
		return NEGATIVE_VALUE;
	}
	if (root == NULL)
	{
		printf("NOT enough memory\n");
		return MALLOC_ERROR;
	}
	create_bare_list(root, valueofN);
	int i;
	struct list* temp = root->next;

	for (i = 0; i < valueofN; i++)
	{
		temp->value = valueofN - i;
		temp = temp->next;
		
	}
}
//creates list with values from N to 1. The same as previous
struct list* first_int(int valueofN)
{
	struct list *st = NULL;
	st = create_root();
	if (valueofN == 0)
	{
		return st;
	}
	if (valueofN < 0)
	{
		printf("Number of units can't be negative\n");
		return NEGATIVE_VALUE;
	}
	create_bare_list(st, valueofN);
	int i;
	struct list* temp = st->next;
	for (i = 0; i < valueofN; i++)
	{
		temp->value = valueofN - i;
		temp = temp->next;
	}
	return st;
}
//Print list in the console
void print_list(struct list* root)
{	
	if (root == NULL)
	{
		printf("NOT enough memory\n");
		return MALLOC_ERROR;
	}
	if (root == -42)
	{
		printf("This list has negative number of units, so i can't print it in this reality\n");
		return MALLOC_ERROR;
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
// Deletes list
void delete_list(struct list* root)
{
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
