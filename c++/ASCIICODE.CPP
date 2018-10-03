#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
char ch='A';
int num=ch;
cout<<"the ASCII code for"<<ch<<"is"<<num<<"\n";
cout<<"adding 1 to the character code\n";
ch=ch+1;
num=ch;
cout<<"the ASCII code for"<<ch<<"is"<<num<<"\n";
getch();
}