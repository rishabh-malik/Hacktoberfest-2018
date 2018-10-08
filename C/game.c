#include <stdio.h>
void main()
{
  int user,comp,i,j;
  printf("WE HAVE 21 CHOCOLATES YOU CAN PICK ANY NUMBER OF IT RANGING FROM 1 TO 4 \n BUT THE ONE WHO PICKS 21st CHOCOLATE HAS TO PAY FOR ALL ");

  for( i=1;i<=4;i++)
  {
   printf("\n\n YOUR CHOICE    =");
   scanf("%d" ,& user);
   
   j=21-(i*5);
   comp=5-user;
   printf("\n COMP CHOICE      =%d" ,comp);

  }
 printf("\n THNKNG..............TRY AGAIN");
}
