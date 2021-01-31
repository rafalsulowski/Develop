#ifndef LIST_T_H
#define LIST_T_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct list
{
    char *word;
    char *definition;

    struct list *next;
    struct list *previous;
} List_t;

List_t *list_inic(char *, char *);
List_t *push_back(List_t *, char *, char *);
List_t *push_front(List_t *, char *, char *);
List_t *pop_front(List_t *);
List_t *pop_back(List_t *);
List_t *pop_element(List_t *, char *);
List_t *search(List_t *, char *);
void show_list(List_t *);
void show_revers_list(List_t *);
int number_of_elements(List_t *);
void cleaner(List_t *);
void free_content(List_t *);
List_t *create_elem_with_word_and_definition(char *w, char *d);
List_t *fill_with_Data(List_t *, char *, char *);

#endif