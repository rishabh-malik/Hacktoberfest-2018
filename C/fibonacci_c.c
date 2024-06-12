#include<stdio.h>
#include<conio.h>

void main()
 {
  long long int a=0,b=1,c=0,i,n;
  clrscr();
  
  printf("How many terms for fibonacci series...?\n");
  scanf("%ld",&n);
  
  printf("Fibonacci series:\n%ld",a);
  for (i=0;i<n-1;i++)
   {
    a=b;
    b=c;
    c=a+b;
    printf(" %ld",c);
   }
  
  getch();
 }
