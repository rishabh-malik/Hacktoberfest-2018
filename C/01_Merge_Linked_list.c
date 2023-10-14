#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// main logic function
struct node *mergelists(struct node *list1, struct node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->data < list2->data)
    {
        list1->next = mergelists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergelists(list2->next, list1);
        return list2;
    }
}

// print linkedlist function
void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf(" \n");
}

// new node create function
struct node *newnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int main()
{
    struct node *list1 = newnode(1);
    list1->next = newnode(5);
    list1->next->next = newnode(7);

    struct node *list2 = newnode(3);
    list2->next = newnode(6);
    list2->next->next = newnode(9);

    struct node *mergedlist = mergelists(list1, list2);

    printf("Merged Linked list: ");
    printlist(mergedlist);

    return 0;
}