#include<stdio.h>
struct STACK
{
	char items[20];
	int top;
};
struct STACK s;
struct STACK *p = &s;

void push(char);
char pop();
int priority(char);

void main()
{
	p->top = -1;
	char exp[20],postfix[20];
	char x;
	printf("Enter the expression :: ");
	gets(exp);
	int i = 0;
	int j=0;
	while(exp[i] != '\0')
	{
		if(isalnum(exp[i]))
		{
			postfix[j]= exp[i];
			j++;
		}
		else if(exp[i] == '(')
		{
			push(exp[i]);
		}
		else if(exp[i] == ')')
		{
			while((x = pop()) != '(')
			{
				postfix[j]= x;
				j++;
			}
		}
		else
		{
			while(priority(p->items[p->top]) >= priority(exp[i]))
			{
				postfix[j]= pop();
				j++;
			}
			push(exp[i]);
		}
		i++;
    	}
	while(p->top != -1)
	{
		postfix[j]= pop();
		j++;
	}
	postfix[j] = '\0';
	printf("Postfix Expression : \n");
	i = 0;
	while(postfix[i] != '\0')
	{
		printf("%c",postfix[i]);
		i++;	
	}
}

void push(char x)
{
	p->top++;
	p->items[p->top] = x;
}
char pop()
{
	if(p->top == -1)
	{
		return -1;
	}
	else
	{
		int x = p->items[p->top];
		p->top--;
        return x;
	}
}
int priority(char x)
{
	if(x == '(')
	{
		return 0;
	}
	if(x == '+' || x == '-')		
	{
		return 1;
	}
	if(x == '*' || x == '/')	
	{	
		return 2;
	}
}
