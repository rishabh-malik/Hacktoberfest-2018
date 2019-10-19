#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val,pr;
	struct node *next;
};
struct node *start;
void enqueue(int,int);
void dequeue();
void display();
void main()
{
	int ch,ele,pr;
	while(1)
	{
		printf("1. Insert\n");
		printf("2. Remove\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("Enter elements and its priority :");
					scanf("%d %d",&ele,&pr);
					enqueue(ele,pr);
					break;
				}
			case 2:
				{
					dequeue();
					break;
				}
			case 3:
				{
					display();
				}
			case 4:
				{
					exit(1);
				}
		}
	}
}
void enqueue(int ele,int pri)
{
	struct node *temp,*t;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=ele;
	temp->pr=pri;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else if(start->pr>pri)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		t=start;
		while(t->next!=NULL&&(t->next)->pr<=pri)
		{
			t=t->next;
		}
		temp->next=t->next;
		t->next=temp;
	}
}
void dequeue()
{
	if(start!=NULL)
	{
		printf("\n\tRemoved :%d",start->val);
		start=start->next;
	}
	else
	{
		printf("\nQueue is empty");
	}
}
void display()
{
	struct node *temp;
	temp=start;
	printf("priority queue :\n");
	while(temp!=NULL)
	{
		printf("%d,%d|t",temp->val,temp->pr);
		temp=temp->next;
	}
}
