#include <stdio.h>
#include "List_t.h"

int main(void)
{
    List_t *head;
    head = list_inic("inic", "argument inicjujacy");

    head = push_back(head, "push back", "dodawanie na koniec");
    head = push_back(head, "push front", "dodawanie na poczatek");
    head = push_back(head, "calka", "calka rimana");
    head = push_back(head, "kolejka", "struktura danych");
    head = push_back(head, "stos", "struktura ksiazkowa");
    head = push_back(head, "drzewo binarne", "drzewo z danymi");

    show_list(head);

    head = push_front(head, "Fr2ont", "Dodaj na poczatek");
    head = push_front(head, "Front3332", "Dodaj na poczatek 3 wyrazy");

    printf("\n\n\nPo dodaniu na poczatek:\n");
    show_list(head);

    List_t *notion = search(head, "drzewo binarne");
    printf("\n\nSzukane powiazanie: %s -> %s\n\n", notion->word, notion->definition);

    head = pop_front(head);
    head = pop_back(head);
    head = pop_element(head, "stos");
    head = pop_element(head, "calka");

    show_list(head);

    printf("\n\nLista od konca:\n");
    show_revers_list(head);

    printf("\n\nIle elementow zawiera lista: %d\n", number_of_elements(head));

    cleaner(head);

    return 0;
}