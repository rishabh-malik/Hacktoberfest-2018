#include <stdio.h>

	void calcHigherSmaller(int *num, int *maior, int *menor)
	{
		int i;
		int maiorx=0, menorx=0;
		i=0;
		
		maiorx=num[0];
		menorx=num[0];
		for(i=0; i<=9; i++)
		{
			if(num[i]>maiorx)
				maiorx = num[i];
		
			if(num[i]<menorx)
				menorx = num[i];
    	}

		*maior = maiorx;
		*menor = menorx;
	}




int main()
{
	int num[9], soma=0, media=0;
	int i;
	int maior=0, menor=0;

	printf("Type 10 integer numbers:");
	for(i=0; i<=9; i++)
	{
		scanf("%d", &num[i]);
		soma+=num[i];		
	}

	media=soma/10;
	calcHigherSmaller(num, &maior, &menor); 
	printf("Numbers sum: %d\n", soma);
	printf("Numbers average: %d\n", media);
	printf("Higher number: %d\n", maior);
	printf("Smaller number: %d\n", menor);

	return 0;
}