#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *next;
};

struct Node* list_inic(int v)
{
	struct Node *h;
	//towrzymy pierwszy lement listy:
	h = malloc(sizeof (struct Node));

	//ustawiamy wskanizk na kolejny element na null bo nie ma innych elementow
	h->next = NULL;
	
	//wypelniamy danymi
	h->value = v;
	
	return h;
}

struct Node* list_add(int v)
{
	struct Node* n = malloc (sizeof (struct Node));
	n->next = NULL; //bo dodajemy na koncu
	n->vlaue = v;


	return n;
}






int main()
{
	struct Node* head = list_inic(3);
	struct Node* 2el = list_add(4);


	printf("Wartosc wynosi: %d", head->value);  

	






	return 0;
}

