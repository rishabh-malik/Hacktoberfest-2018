#include <stdio.h>

int main()
{
	int num;
	int i;
	printf("Type a integer number: ");
	scanf("%d", &num);
	printf("%d dividers: ", num);
	for(i=1; i<=num; i++)
	{
		if(num%i==0)
		{
			printf("%d, ", i);
		}
	}

	return 0;
}