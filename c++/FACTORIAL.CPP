#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int num,fact=1;
cout<<"enter an integer";
cin>>num;
while (num)
{
fact=fact*num;
--num;
}
cout<<"res="<<fact;
getch();
}