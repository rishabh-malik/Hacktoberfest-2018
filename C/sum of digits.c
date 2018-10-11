#include<stdio.h>
int main()
{
	int a,b,rem,sum=0;
	printf("enter the number ");
	scanf("%d",&a);
	b=a;
	while(b>0)
	{
		rem=b%10;
		sum=sum+rem;
		b=b/10;
	}
	printf("the sum of digits of %d is %d",a,sum);
}
