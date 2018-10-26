#include<stdio.h>
#include<iostream.h>
#include<string.h>
int  main()
{
    char str[100] , rev[100];
    gets(str);
    rev = strrev(str);
    for (int i = 0 ; i < strlen(str) ; i++ )
    {
        if( str[i] != rev[i])
        {
            cout<<"this string is not palindrome \n";
            return;
        }
    }
    cout<<"this is palindrome string \n";
    return;
}
