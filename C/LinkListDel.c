#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int info;
	struct Node *next;
};

typedef struct Node NODE;
NODE * deleven(NODE*);
NODE * create(NODE*);
NODE * Delend(NODE*);
void display(NODE*);
NODE * insertstart(NODE *start);
//void insertend(NODE *start);
//void insertmiddle(NODE *start, int n);

void main()
{
	NODE *start=NULL;
	int n;
	start=create(start);
	display(start);
	//start = deleven(start);
	start = Delend(start);
    display(start);
	insertend(start);
//	printf("After inserting at the end, \n");
//	display(start);
//	start=insertstart(start);

/*	printf("After inserting at the beginning, \n");
	display(start);

	printf("Enter the info part of the node after which you want to add a new node \n");
	scanf("%d", &n);

	insertmiddle(start,n);

	printf("After inserting in the middle, \n");
	display(start); */
}
NODE* Delend(NODE* start){
    int count=0;
    count = 0;
    printf("COunt = %d",count);
    NODE *temp, *temp2;
    temp = start;
    do{
        start = start->next;
        count++;

    }while(start!=temp);
    start = temp;
    count--;
    printf("COunt = %d",&count);
    while(count>=0){
        count--;
        start = start->next;
    }
    temp2 = start->next;
    start->next = temp2->next;
    free(temp2);
    start = temp;
    return start;


}
NODE * deleven(NODE *start){
    NODE *temp1, *temp, *temp2, *num;
    int max =0, count =0;
    num = start;
    do{
        start = start->next;
        max++;

    }while(start!=num);
    start = num;
    max = max/2;
    //temp1 = start;
    //start = start->next;
    //free(temp1);
    //temp2 = start;
    count++;
    temp1 = start;
    while(count !=max){
        temp = start;
        start = start->next;
        temp->next = start->next;
        free(start);
        start = temp->next;
        count++;
    }
    temp = start->next;
    free(temp);
    start->next = temp1;
    start = temp1;
    return start;
}

NODE* create(NODE* start)
{
	NODE *newnode, *prev;
	int n;

	do
	{
		newnode= (NODE *)malloc(sizeof(NODE));

		printf("Enter the information part \n");
		scanf("%d", &newnode->info);

		newnode->next=NULL;

		if(start==NULL){
			start=newnode;
			newnode->next = start;
			}

		else{
			prev->next=newnode;
			newnode->next = start;
			}

		prev=newnode;

		printf("Enter 1 if you want more nodes to be added\n");
		scanf("%d", &n);

	}while(n==1);

	return start;
}

void display(NODE *start){
    NODE* temp;
	printf("The linked list is : \n");
    temp = start;

	do{

		printf("%d\n", start->info);

		start=start->next;
	}while(start!=temp);
}

void insertend(NODE *start)
{
	printf("Enter an element at the end of the linked list : \n");

	NODE *newnode;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part\n");
	scanf("%d", &newnode->info);

	while(start->next!=NULL)
		start=start->next;

	start->next=newnode;
	newnode->next=NULL;
}

NODE * insertstart(NODE *start)
{
	printf("Enter an element at the beginning of the linked list : \n");

	NODE *newnode;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part\n");
	scanf("%d", &newnode->info);

	newnode->next=start;
	start=newnode;

	return start;
}*/
//testing
/*void insertmiddle(NODE *start, int n)
{
	NODE *newnode;

	while(start->info!=n)
		start=start->next;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part : \n");
	scanf("%d", &newnode->info);

	newnode->next=start->next;
	start->next=newnode;

}*/
