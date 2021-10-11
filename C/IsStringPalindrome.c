#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    int i,j,f=0;
    char str[20];

    printf("Enter String");
    gets(str);
    j=strlen(str)-1;
    while(i<j)
    {
        if(str[i]==str[j])
        {
            i++;
            j--;
        }
        else
        {
            f=1;
            break;
        }
    }
    if(f==0)
        printf("Given string is Palindrome");
    else
        printf("Given string is not Palindrome");
}
