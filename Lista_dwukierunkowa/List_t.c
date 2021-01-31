#include "List_t.h"

bool check_absolut_equals(char *base, char *compared_to_base)
{
    int len = (int)strlen(base);

    int i = 0;
    while (*(base + i) == *(compared_to_base + i))
    {
        if (*(base + i) == '\0' && *(compared_to_base + i) == '\0')
            break;
        i++;
    }

    if (i != len)
        return false;
    else
        return true;
}

void free_concent(List_t *head)
{
    free(head->word);
    free(head->definition);
}

List_t *list_inic(char *w, char *d)
{
    List_t *head = create_elem_with_word_and_definition(w, d);
    return head;
}

List_t *push_back(List_t *head, char *w, char *d)
{
    if (head == NULL)
        head = create_elem_with_word_and_definition(w, d);
    else
    {
        List_t *iterator = head;
        while (iterator->next != NULL)
            iterator = iterator->next;

        iterator->next = create_elem_with_word_and_definition(w, d);
        iterator->next->previous = iterator;
        iterator->next->next = NULL;
    }

    return head;
}

List_t *push_front(List_t *head, char *w, char *d)
{
    if (head == NULL)
        head = create_elem_with_word_and_definition(w, d);
    else
    {
        List_t *new_elem = create_elem_with_word_and_definition(w, d);
        new_elem->previous = NULL;
        new_elem->next = head;
        head->previous = new_elem;
        head = new_elem;
    }

    return head;
}

List_t *pop_front(List_t *head)
{
    if (head == NULL)
        return NULL;

    free(head->word);
    free(head->definition);

    head = head->next;
    head->previous = NULL;
    return head;
}

List_t *pop_back(List_t *head)
{
    if (head == NULL)
        return NULL;

    List_t *iterator = head;
    while (iterator->next->next != NULL)
        iterator = iterator->next;

    free_concent(iterator->next);
    iterator->next = NULL;

    return head;
}

List_t *pop_element(List_t *head, char *w)
{
    if (!strcmp(head->word, w))
    {
        return pop_back(head);
    }

    List_t *iterator = head;

    while (strcmp(iterator->next->word, w))
    {
        if (iterator->next->next == NULL)
            return head; //nie odnaleziono slowa
        iterator = iterator->next;
    }

    free_concent(iterator->next);

    if (iterator->next->next)
    {
        iterator->next = iterator->next->next;
        iterator->next->previous = iterator;
    }
    else
        iterator->next = NULL;

    return head;
}

List_t *search(List_t *head, char *w)
{
    List_t *notion;

    if (head == NULL)
        return NULL;

    for (List_t *iterator = head->next; iterator != NULL; iterator = iterator->next)
    {
        if (check_absolut_equals(iterator->word, w))
        {
            notion = create_elem_with_word_and_definition(iterator->word, iterator->definition);
            break;
        }
    }

    return notion;
}

void show_list(List_t *head)
{
    for (List_t *iterator = head; iterator != NULL; iterator = iterator->next)
    {
        printf("(actual - %p) %s -> %s (prev - %p, next - %p)\n",
               iterator, iterator->word, iterator->definition, iterator->previous, iterator->next);
    }
}

void show_revers_list(List_t *head)
{
    List_t *iterator = head;
    while (iterator->next != NULL)
        iterator = iterator->next;

    for (; iterator != NULL; iterator = iterator->previous)
    {
        printf("(actual - %p) %s -> %s (prev - %p, next - %p)\n",
               iterator, iterator->word, iterator->definition, iterator->previous, iterator->next);
    }
}

int number_of_elements(List_t *head)
{
    if (head == NULL)
        return 0;

    int counter = 1;
    List_t *iterator = head;

    while (iterator->next != NULL)
    {
        counter++;
        iterator = iterator->next;
    }

    return counter;
}

void cleaner(List_t *head)
{
    while (head != NULL)
    {
        free(head->word);
        free(head->definition);
        head = head->next;
    }

    free(head);
}

List_t *create_elem_with_word_and_definition(char *w, char *d)
{
    List_t *tmp = (List_t *)malloc(sizeof(List_t));
    tmp->word = (char *)malloc(sizeof(char) * (1 + strlen(w)));
    tmp->definition = (char *)malloc(sizeof(char) * (1 + strlen(d)));
    strcpy(tmp->word, w);
    strcpy(tmp->definition, d);

    tmp->next = NULL;
    tmp->previous = NULL;

    return tmp;
}
