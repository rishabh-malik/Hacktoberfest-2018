#include<stdio.h>
#include<stdlib.h>
struct BST
{
	int info;
	struct BST*left;
	struct BST*right;
};
struct BST* insert(struct BST*,int);
void preorder(struct BST*);
void inorder(struct BST*);
void postorder(struct BST*);
void main()
{
	struct BST *start=NULL;
	int val;
	char ch='y';
	while(ch=='y')
	{
		printf("Enter a value to insert\n");
		scanf("%d",&val);
		start=insert(start,val);
		printf("Do you want to continue\n");
		fflush(stdin);
		scanf("%c",&ch);
	}
		printf("Pre order \n");
		preorder(start);
		printf("\n Inorder");
		inorder(start);
		printf("\nPre order \n");
		postorder(start);
}
struct BST* insert(struct BST *temp,int x)
{
	if(temp==NULL)
	{
		temp=(struct BST*)malloc(sizeof(struct BST));
		if(temp==NULL)
		{
			printf("out of memory\n");
			exit(1);
		}
		else
		{
			temp->info=x;
			temp->left=NULL;
			temp->right=NULL;
		}
	}
	else
	{
		if(x<temp->info)
		{
			temp->left=insert(temp->left,x);
		}
		else if(x>temp->info)
		{
			temp->right=insert(temp->right,x);
		}
	}
	return temp;
}
void inorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->info);
		inorder(temp->right);
	}
}
void postorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->info);
	}
}
void preorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		printf("%d\t",temp->info);
		preorder(temp->left);
		preorder(temp->right);
	}
}
