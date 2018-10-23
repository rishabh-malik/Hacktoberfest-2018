#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
struct node
{ int info;
  struct node*next;
}NODE;
struct node *start,*ptr,*p;
void create()
{
  ptr=(struct node*)malloc(sizeof(NODE));
  cout<<"enter information on the node:";
  cin>>ptr->info;
  ptr->next=start;
  start=ptr;
}
void display()
{ ptr=start;
  while(ptr!=NULL)
  {cout<<ptr->info <<"\n";
  ptr=ptr->next;
  }
}
void main()
{clrscr();
 int a=1;
 cout<<"creating a link list(insertion in the beginning) \n ";
 do
 {create();
  cout <<"want to enter a node again (1=yes):" ;
  cin>>a;
 }while(a==1);
 display();
 getch();
}