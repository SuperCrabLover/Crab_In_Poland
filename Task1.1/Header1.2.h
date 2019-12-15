/*
 * File:  Header1.2.h
 * Brief: Definitions for 1.2 task
 * Author: Code squad 1337
 * Created on 18.11.2019
 * (c) MIPT 2019
 */
#pragma once

struct list* create_root(void);

struct list* create_unit(seed);

//adds a unit into the end of the list
struct link* add_to_end(struct list* temp, struct list* tail);

void create_bare_list(struct list* root, int amountOfUnits);

void insert_value(struct list* root, int amountOfUnits);

void first_integers(struct list* root, int valueofN);

struct list* first_int(int valueofN);

void print_list(struct list* root);

void delete_list(struct list* root); 
