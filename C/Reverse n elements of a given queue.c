/*
int front=-1, rear=-1;
int array[SIZE];
void enqueue(int item);
int dequeue();

Above variables are used for queue, SIZE, front and rear and all are global variables. Complete the below two methods. */
#include<stdlib.h>
static int check=1,l=1;
void reverseQueue(int q[])
{
	if(front<rear)
    {
      int x=dequeue();
      l++;
      reverseQueue(q);
      enqueue(x);
    }
}
void reverseKelementsQueue (int q[],int k)
{
  if(k==0)
  {
    check=1;
    l=1;
    return;
  }
  if(check==1)
  {
    check=0;
    reverseQueue(q);
    k=l-k;
  }
    if(front<rear&&check==0)
    {
      int x=dequeue();
      reverseKelementsQueue(q,k-1);
      enqueue(x);
    }
}
