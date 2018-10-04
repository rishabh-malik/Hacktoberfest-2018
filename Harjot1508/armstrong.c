#include <stdio.h>
#include <math.h>

int main()
{
  int num, temp1,temp2, rem, sum=0,dgt=0;
  printf("Enter a positive  integer: ");
  scanf("%d",num);

  temp1 = num;
  temp2 = num;

  while(temp1 != 0)
  {
      temp1/=10;
      dgt++;

  }

    while(temp2 != 0)
  {
      rem= temp2%10;
      sum+= pow(rem,dgt);
      temp2/=10;


  }

  if (sum==num)
      printf("%d is an Armstrong number.",num);
  else
      printf("%d is not an Armstrong number.",num);

  return 0;
}
