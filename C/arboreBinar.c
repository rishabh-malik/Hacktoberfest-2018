#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
}nod;

// typedef struct nod 
// {
//     char val;
//     struct nod* next;
// }stack;

void insert(nod ** root, int val)
{
    nod *temp = NULL;
    if((*root) == NULL)
    {
        temp = (nod *)malloc(sizeof(nod));
        temp->left = temp->right = NULL;
        temp->val = val;
        *root = temp;
        return;
    }
    if(val < (*root)->val)
    {
        insert(&(*root)->left, val);
    }
    if(val > (*root)->val)
    {
        insert(&(*root)->right, val);
    }

}
void inorder(nod *root)
{
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}

void preorder(nod *root)
{
	if(root == NULL)
		return ;
	printf("%d ",root->val);
	preorder(root->left);
	preorder(root->right);
}

void postorder(nod *root)
{
	if(root == NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root -> val);
}

void search(nod *root, int val)
{
	int ok = 0;
	while(root != NULL)
	{
		if(val > root -> val)
		{
			return search(root->right,val);
		}
		else if(val < root->val)
		{
			return search(root->left,val);
		}
		else
		{
			ok = 1;
		}
	}
	if(ok)
		printf("Am gasit numarul!\n");
	else
		printf("Nu am gasit numarul!\n");
}

int min(nod *root)
{
	nod *current = root;
	while(current->left)
		current = current -> left;
	return current -> val;
}
int max(nod *root)
{
	nod *current = root;
	while(current -> right)
		current = current -> right;
	return current -> val;
}
int main(int argc, char const *argv[])
{
	nod *root = NULL;
	insert(&root,10);
	insert(&root,6);
	insert(&root,18);
	insert(&root,4);
	insert(&root,8);
	insert(&root,15);
	insert(&root,21);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("Minimul este %d\n",min(root));
	printf("Maximul este %d\n",max(root));
	return 0;
}