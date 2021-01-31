#include "Concept.h"

Concept_t *fill_with_NULL()
{
    Concept_t *notion = (Concept_t *)malloc(sizeof(Concept_t));
    notion->word = NULL;
    notion->definition = NULL;

    return notion;
}

Concept_t *fill_with_Data(char *w, char *d)
{
    Concept_t *notion = (Concept_t *)malloc(sizeof(Concept_t));
    notion->word = (char *)malloc(sizeof(char) * (1 + strlen(w)));
    notion->definition = (char *)malloc(sizeof(char) * (1 + strlen(d)));
    strcpy(notion->word, w);
    strcpy(notion->definition, d);

    return notion;
}