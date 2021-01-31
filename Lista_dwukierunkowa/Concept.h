#ifndef CONCEPT_H
#define CONCEPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct concept_t
{
    char *word;
    char *definition;
} Concept_t;

Concept_t *fill_with_NULL();
Concept_t *fill_with_Data(char *, char *);

#endif