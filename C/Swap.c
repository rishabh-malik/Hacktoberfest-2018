#include<stdio.h>
main()
{
int a,b,c;
printf("\nEnter a and b:");
scanf("%d%d",&a,&b);
  c=a;
  a=b;
  b=c;
printf("a=%d and b=%d",a,b);
}
