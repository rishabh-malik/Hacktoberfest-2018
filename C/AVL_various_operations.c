#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
	int ht;
};
struct node *insert(struct node *,int);
struct node *Delete(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
int height( struct node *);
struct node *rotateright(struct node *);
struct node *rotateleft(struct node *);
struct node *RR(struct node *);
struct node *LL(struct node *);
struct node *LR(struct node *);
struct node *RL(struct node *);
int BalanceFactor(struct node *);

void main()
{
	struct node *start=NULL;
	int x,n,i,op;

	do
	{
		printf("\n1)Create:");
		printf("\n2)Insert:");
		printf("\n3)Delete:");
		printf("\n4)Print:");
		printf("\n5)Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&op);

		switch(op)
		{
			case 1: printf("\nEnter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data:");
					start=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						start=insert(start,x);
					}
					break;

			case 2: printf("\nEnter a data:");
					scanf("%d",&x);
					start=insert(start,x);
					break;

			case 3: printf("\nEnter a data:");
					scanf("%d",&x);
					start=Delete(start,x);
					break;

			case 4: printf("\nPreorder sequence:\n");
					preorder(start);
					printf("\n\nInorder sequence:\n");
					inorder(start);
					printf("\n");
					break;
		}
	}while(op!=5);
}

struct node * insert(struct node *temp,int x)
{
	if(temp==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
	}
	else
		if(x > temp->data)		// insert in right subtree
		{
			temp->right=insert(temp->right,x);
			if(BalanceFactor(temp)==-2)
				if(x>temp->right->data)
					temp=RR(temp);
				else
					temp=RL(temp);
		}
		else
			if(x<temp->data)
			{
				temp->left=insert(temp->left,x);
				if(BalanceFactor(temp)==2)
					if(x < temp->left->data)
						temp=LL(temp);
					else
						temp=LR(temp);
			}

		temp->ht=height(temp);

		return(temp);
}

struct node * Delete(struct node *temp,int x)
{
	struct node *p;

	if(temp==NULL)
	{
		return NULL;
	}
	else
		if(x > temp->data)		// insert in right subtree
		{
			temp->right=Delete(temp->right,x);
			if(BalanceFactor(temp)==2)
				if(BalanceFactor(temp->left)>=0)
					temp=LL(temp);
				else
					temp=LR(temp);
		}
		else
			if(x<temp->data)
			{
				temp->left=Delete(temp->left,x);
				if(BalanceFactor(temp)==-2)	//Rebalance during windup
					if(BalanceFactor(temp->right)<=0)
						temp=RR(temp);
					else
						temp=RL(temp);
			}
			else
			{
				//data to be deleted is found
				if(temp->right!=NULL)
				{	//delete its inorder succesor
					p=temp->right;

					while(p->left!= NULL)
						p=p->left;

					temp->data=p->data;
					temp->right=Delete(temp->right,p->data);

					if(BalanceFactor(temp)==2)//Rebalance during windup
						if(BalanceFactor(temp->left)>=0)
							temp=LL(temp);
						else
							temp=LR(temp);
				}
				else
					return(temp->left);
			}
	temp->ht=height(temp);
	return(temp);
}

int height(struct node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return(0);

	if(temp->left==NULL)
		lh=0;
	else
		lh=1+temp->left->ht;

	if(temp->right==NULL)
		rh=0;
	else
		rh=1+temp->right->ht;

	if(lh>rh)
		return(lh);

	return(rh);
}

struct node * rotateright(struct node *x)
{
	struct node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

struct node * rotateleft(struct node *x)
{
	struct node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);

	return(y);
}

struct node * RR(struct node *temp)
{
	temp=rotateleft(temp);
	return(temp);
}

struct node * LL(struct node *temp)
{
	temp=rotateright(temp);
	return(temp);
}

struct node * LR(struct node *temp)
{
	temp->left=rotateleft(temp->left);
	temp=rotateright(temp);

	return(temp);
}

struct node * RL(struct node *temp)
{
	temp->right=rotateright(temp->right);
	temp=rotateleft(temp);
	return(temp);
}

int BalanceFactor(struct node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return(0);

	if(temp->left==NULL)
		lh=0;
	else
		lh=1+temp->left->ht;

	if(temp->right==NULL)
		rh=0;
	else
		rh=1+temp->right->ht;

	return(lh-rh);
}

void preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d(BalanceFactor=%d)",temp->data,BalanceFactor(temp));
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d(BalanceFactor=%d)",temp->data,BalanceFactor(temp));
		inorder(temp->right);
	}
}
