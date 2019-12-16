#pragma once

struct list* create_root(void);

struct list* create_unit(seed);

//adds a unit into the end of the list
struct link* add_to_end(struct list* temp, struct list* tail);

void read_list(struct list* root, int amountOfUnits);

void create_bare_list(struct list* root, int amountOfUnits);

void insert_value(struct list* root, int amountOfUnits);

void print_list(struct list* root);

void add_to_middle(struct list* root, int amountOfUnits);

struct list* find_unit(struct list* root, int amountOfUnits);

void delete_unit(struct list* root, int amountOfUnits);

void delete_list(struct list* root);