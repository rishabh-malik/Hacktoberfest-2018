#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int info;
	struct Node *next;
};

typedef struct Node NODE;

NODE * create(NODE *start);
void display(NODE *last);
NODE * delevenpos(NODE *last);
NODE * insertend(NODE *last);
void insertstart(NODE *last);
void insertmiddle(NODE *last, int n);
NODE * deletelast(NODE *last);
void deletestart(NODE *last);
void deletenode(NODE *last, int val);
void search(NODE *last, int val);


void main()
{
    NODE *start=NULL;
    NODE *last;

	int n, a, val, c, searchval;

    last=create(start);
    //last=delevenpos(last);
    display(last);

	do{

        printf("Enter 1 for inserting a node at the starting.\n");
        printf("Enter 2 for inserting a node at the ending.\n");
        printf("Enter 3 for inserting a node next to the value needed.\n");
        printf("Enter 4 for deleting a node from the beginning.\n");
        printf("Enter 5 for deleting a node from the end.\n");
        printf("Enter 6 for deleting a node containing the value needed.\n");
        printf("Enter 7 to search a value in the linked list.\n");

        scanf("%d", &a);

        switch(a)
        {
            case 2:     last=insertend(last);

                        printf("After inserting at the end, \n");
                        display(last);
                        break;


            case 1:     insertstart(last);

        	            printf("After inserting at the beginning, \n");
        	            display(last);
                        break;


            case 3:     printf("Enter the info part of the node after which you want to add a new node \n");
        	            scanf("%d", &n);

        	            insertmiddle(last,n);

        	            printf("After inserting in the middle, \n");
        	            display(last);
                        break;

            case 4:     deletestart(last);

                        printf("After deleting at the beginning, \n");
                        display(last);
                        break;

            case 5:     last = deletelast(last);

                	    printf("After deleting at the end, \n");
                	    display(last);
                        break;

            case 6:     printf("Enter the info part of the node you want to delete.\n");
                        scanf("%d", &val);

                        deletenode(last, val);

                        printf("After deleting in the middle, \n");
                        display(last);
                        break;

            case 7:     printf("Enter the value you want to search.\n");
                        scanf("%d", &searchval);

                        search(last, searchval);
                        break;

        }

        printf("Press 1 to perform more operations.\n");
        scanf("%d", &c);

    }while(c==1);
}

NODE * create(NODE *start)
{
	NODE *newnode, *prev;
	int n;

	do
	{
		newnode= (NODE *)malloc(sizeof(NODE));

		printf("Enter the information part \n");
		scanf("%d", &newnode->info);

		newnode->next=NULL;

		if(start==NULL)
			start=newnode;

		else
			prev->next=newnode;

		prev=newnode;

		printf("Enter 1 if you want more nodes to be added\n");
		scanf("%d", &n);

        newnode->next=start;

	}while(n==1);

	return newnode;
}

void display(NODE *last)
{
    NODE *start;
    start=last->next;

	printf("The linked list is : \n");

	do
	{
		printf("%d\t", start->info);

        start=start->next;

	}while(start!=last->next);

	printf("\n");
}

//Deletion of even positions, don't write in file
NODE * delevenpos(NODE *last)
{
    NODE *start, *temp, *temp1, *temp2;
    start=last->next;

    int c=0;

    do
    {
            if(c%2==0)
            {
                temp=start->next;

                if(start==last->next)
                {
                    start->next=temp->next;
                    free(temp);
                }

                else
                {   temp1->next=start->next;
                    temp2=start;
                    free(temp2);
                }
            }

            else
                temp1=start;

            c++;

            start=start->next;

    } while(start!=last->next);

    return start->next;
}

void insertstart(NODE *last)
{
	printf("Enter an element at the beginning of the linked list : \n");

	NODE *newnode, *start;
	start=last->next;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part\n");
	scanf("%d", &newnode->info);

	last->next=newnode;
	newnode->next=start;
}

NODE * insertend(NODE *last)
{
	printf("Enter an element at the end of the linked list : \n");

	NODE *newnode;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part\n");
	scanf("%d", &newnode->info);

	newnode->next=last->next;
	last->next=newnode;

	return newnode;
}

void insertmiddle(NODE *last, int n)
{
	NODE *newnode, *start;
	start=last->next;

	while(start->info!=n)
		start=start->next;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part : \n");
	scanf("%d", &newnode->info);

	newnode->next=start->next;
	start->next=newnode;
}

NODE * deletelast(NODE *last)
{
	NODE *start, *temp;

	start=last->next;
	printf("%d", start->info);

	do
	{
		temp=start;
		start=start->next;
	}while(start->next!=last->next);

	temp->next=start->next;

	free(start);

	printf("%d", temp->info);

	return temp;
}

void deletestart(NODE *last)
{
	NODE *start;

	start=last->next;
	last->next=start->next;

	free(start);
}


void deletenode(NODE *last, int val)
{
	NODE * temp, *start;
	start=last->next;

    while(start->info!=val)
    {
        temp=start;
        start=start->next;
    }

    temp->next=start->next;

    free(start);
}

void search(NODE *last, int val)
{
	NODE *start;
	start=last->next;

	do
    {
        if(start->info==val)
        {
            printf("Value found.\n");
            return;
        }

        start=start->next;

    }while(start!=last->next);

    printf("Not found.\n");
}
