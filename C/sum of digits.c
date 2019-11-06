#include<stdio.h>
int main()
{
	int b,sum=0;
	printf("enter the number ");
	scanf("%d",&b);
	printf("the sum of digits of %d is:",b);
	while(b>0)
	{
		sum+=b%10;
		b=b/10;
	}
	printf("%d",sum);
}
