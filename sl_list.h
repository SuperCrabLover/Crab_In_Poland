#pragma once
#define MALLOC_ERROR -1
#define ROOT_VALUE 42

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

void read_list(struct list* root, int amountOfUnits)
{
	int i, seed;
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
	int i;
	struct list* temp = root;
	int position;
	printf("Insert the position (integer) for a new unit int the list\n");
	scanf_s("%d", &position);
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

void delete_list(struct list* root)
{
	printf("deleting the list...\n");
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
