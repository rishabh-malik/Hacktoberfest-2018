#include<stdio.h>
#define max 200
main()
{
	int i=0,j=0,top=0,flag;
	char a[max],org[max];
	printf("\nEnter a string\n");
	gets(a);
	while(a[i]!='\0')
	{
		flag=0;
		j=0;
		while(j<top)
		{
			if(a[i]==org[j])
			{
				flag=1;
			}
			j++;
		}
		if(flag==0)
		{
			org[top]=a[i];
			top++;
		}
		i++;		
	}
	org[top++]='\0';
	puts(org);
	
}
