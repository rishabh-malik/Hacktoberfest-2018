
#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int val;
    struct nod* next;
} nod;

int isEmpty(nod* cap)
{
    return cap == NULL;
}

void printQueue(nod* cap)
{
    nod* p = cap;
    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

/* functia peak arata ce se afla in varful cozii fara a scoate vreun
element din coada 0.5p*/
int peak(nod* cap)
{
	// TODO inlocuiti cu valorile corespunzatoare
	nod *current = cap;
	while( current -> next != NULL )
	{
		current = current -> next;
	}
    return current -> val;
}

/* functia push adauga un element in coada ->
    se va insera element la sfarsitul listei 1p*/
void push(nod** cap, int val)
{
	nod *current = (nod *)malloc(sizeof(nod));
	nod *last = *cap;
	current -> val = val;
	current -> next = NULL;
	if( *cap == NULL )
	{
		*cap = current;
		return;
	}

	while(last -> next != NULL)
		last = last -> next;

	last -> next = current;
	return;
}

/* functia pop scoate un element din coada il intoarce ->
    se va scoate elementul de la inceputul listei 1p*/
int pop(nod** cap)
{
	int valueFirst;
	nod *current = *cap;
	valueFirst = current -> val;
	*cap = current -> next;
	free(current);
	return valueFirst;
}

/*
    BONUS 2p
    Implementati o stiva folosind 2 cozi.
    Indicatii:
    push(s, x) // x is the element to be pushed and s is stack
    1) Enqueue x to q2
    2) One by one dequeue everything from q1 and enqueue to q2.
    3) Swap the names of q1 and q2
    // Swapping of names is done to avoid one more movement of all elements
    // from q2 to q1.

    pop(s)
    1) Dequeue an item from q1 and return it.
*/

int main()
{
    nod* queue =  NULL;
    push(&queue, 2);
    printQueue(queue);
    push(&queue, 3);
    push(&queue, 4);

    printQueue(queue);
    printf("Peak-ul este: %d\n", peak(queue));
    printf("Am scos: %d \n", pop(&queue));
    printQueue(queue);
    printf("Am scos: %d \n", pop(&queue));
    printQueue(queue);
    printf("Am scos: %d \n", pop(&queue));
    printQueue(queue);

    return 0;
}
