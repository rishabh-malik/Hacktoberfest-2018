//  #include<iostream.h>
 #include<stdio.h>
 #include<string.h>
 void main()
 
{
    char string[100];
    gets(string);

    for(int i = 0 ; i < strlen(string) ; i++)
    {
        if(!isupper(string[i])
        {
            toupper(string[i]);
        }
    }
    puts(string);
//   here you ll get the upper cased string
}
