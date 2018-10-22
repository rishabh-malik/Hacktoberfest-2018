#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod 
{
    char val;
    struct nod* next;
} nod;

int isEmpty(nod* cap)
{
    return cap == NULL;
}

void printStack(nod* cap)
{
    nod* p = cap;
    while(p != NULL)
    {
        printf("%c ", p->val);
        p = p->next;
    }
    printf("\n");
}

/* functia peak arata ce se afla in varful stivei fara a scoate vreun 
element de pe stiva 0.5p */
char peak(nod* cap) 
{
    nod *current = cap;
    while( current -> next != NULL )
    {
        current = current -> next;
    }
    return current -> val;
}

/* functia push adauga un element pe stiva ->
    se va insera element la inceputul listei 1p*/
void push(nod** cap, char val) 
{
    nod *current = (nod *)malloc(sizeof(nod));
    current -> val = val;
    current -> next = (*cap);
    (*cap) = current;
}

/* functia pop scoate un element de pe stiva si il intoarce ->
    se va scoate element de la inceputul listei 1p*/
char pop(nod** cap)
{
    char valueFirst;
    nod *current = *cap;
    valueFirst = current -> val;
    *cap = current -> next;
    free(current);
    return valueFirst;
}

/* 
    functia primeste o expresie matematica,
    si verifica daca ordinea parantezelor este corecta
    (se va verifica daca atunci cand se deschide o paranteza
    de un tip se va inchide o paranteza de acelasi timp)
    functia va returna 1 in cazul in care expresia este corecta
    va returna 0 in cazul in care expresia este gresita
    exemplu :
        {()} -> corect
        {(]} -> gresit
    indicatii: se va crea si folosi o stiva pentru verificare
    Stiva se va crea si folosi cu ajutorul functiilor definite anterior
    2p
*/
int douaparanteze(char char1,char char2)
{
   if (char1 == '(' && char2 == ')')
     return 1;
   else if (char1 == '{' && char2 == '}')
     return 1;
   else if (char1 == '[' && char2 == ']')
     return 1;
   else
     return 0;
}


int checkForBalancedParanthesis(char* expresie)
{
    int i = 0;
    nod *stiva = NULL;
    while(expresie[i])
    {
        if(expresie[i] == '{' || expresie[i] == '(' || expresie[i] == '[')
            push(&stiva,expresie[i]);
        if(expresie[i] == '}' || expresie[i] == ')' || expresie[i] == ']')
        {
            if(stiva == NULL)
                return 0;
            else
                if(!douaparanteze(pop(&stiva),expresie[i]))
                    return 0;
        }
        i++;
    }
    if(stiva == NULL)
        return 1;
    else
        return 0;
}

/* 
    functia primeste un sir de caractere si afiseaza sirul de caractere
    in ordine inversa.
    Pentru aceasta se va folosi o stiva.
    Stiva se va crea si folosi cu ajutorul functiilor definite anterior
    1p
*/
void reverseOrder(char* inputString)
{
    int i = 0;
    nod *stiva = NULL;
    while(i < strlen(inputString))
    {
        push(&stiva,inputString[i]);
        i++;
    }
    printStack(stiva);
}

/*
    functia primeste o expresie in forma prefixata si 
    afiseaza expresia in forma infixata
    pseudo-cod:x
    This algorithm is a non-tail recursive method. 
    1.The reversed input string is completely pushed into a stack. 
	    prefixToInfix(stack) 
    2.IF stack is not empty 
        a. Temp -->pop the stack 
        b. IF temp is a operator 
		    Write a opening parenthesis to output 
		    prefixToInfix(stack) 
		    Write temp to output 
		    prefixToInfix(stack) 
		    Write a closing parenthesis to output 
    c. ELSE IF temp is a space -->prefixToInfix(stack)  
    d. ELSE 
		Write temp to output 
		IF stack.top NOT EQUAL to space -->prefixToInfix(stack)
		
	Exemplu:
	input: *+a-bc/-de+-fgh
	output: (a+b-c)*(d-e)/(f-g+h) 
	2p
*/
void prefixInfix(char* expresie)
{
    nod *stiva = NULL;
    char a,op;
    int i;
    int n = strlen(expresie);
    for(i=0;i<n-1;i++)
   {
      if(expresie[i]=='+'||expresie[i]=='-'||expresie[i]=='*'||expresie[i]=='/')
      {
        push(&stiva,expresie[i]);
      }
      else
      {
        op=pop(&stiva);
        a=expresie[i];
        printf("%c%c",a,op);
      }
   }
   printf("%c",expresie[n-1]);
}
int main()
{
    nod* stack =  NULL;
    push(&stack, 'a');
    push(&stack, 'b');
    push(&stack, 'c');
    printStack(stack);
    printf("Peak-ul este: %c\n", peak(stack));
    printf("Am scos: %c \n", pop(&stack));
    printStack(stack);
    printf("Am scos: %c \n", pop(&stack));
    printStack(stack);
    printf("Am scos: %c \n", pop(&stack));
    printStack(stack);

    int check = checkForBalancedParanthesis("{((()))}");
    printf("Should be true %d\n", check); // should print 1
    
    check = checkForBalancedParanthesis("{((())}");
    printf("Should be false %d\n", check); // should print 0
    
    reverseOrder("WORDS");
    
   prefixInfix("*+a-bc/-de+-fgh");
   printf("\n");
    return 0;
}
