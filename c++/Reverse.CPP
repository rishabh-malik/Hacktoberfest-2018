#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

void main()
{
clrscr();

int i,j,k,len,temp;
char str[80];

cout<<"Enter string: ";
gets(str);

len=strlen(str);

for(i=0,j=0; j<len; j++)
{
if(!isalnum(str[j]) || j==len-1)
{
if(j<len-1)
k=j-1;
else
k=j;


while(i<k)
{
temp=str[i];
str[i]=str[k];
str[k]=temp;
i++;
k--;
}

i=j+1;
}
}

cout<<"Reversed string is: ";
puts(str);

getch();
}

