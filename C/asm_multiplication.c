#include<stdio.h>
#include<stdlib.h>

int multiplication(int a, int b);

int main(void)
{
    int a, b;

    printf("Multiplication in assembly\n");
    printf("Type a number: ");
    scanf("%d", &a);
    printf("Type another number: ");
    scanf("%d", &b);

    printf("result: %d\n", multiplication(a, b));

    return EXIT_SUCCESS;
}

int multiplication(int a, int b)
{
   int res;

   asm volatile("imul %%ebx, %%eax\n\t" /* */
                : "=a"(res)             /*res eh output referido pelo registrador eax*/
                : "a"(a), "b"(b));      /*a e b sao input referidos por eax e ebx*/

   return res;
}

