//Keep

#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int i,n,first,sec,third;
cout<<"enter range:";
cin>>n;
first=0;
sec=1;
cout<<first<<"\t"<<sec;
for(i=2;i<=n;i++)
{
third=first+sec;
cout<<"\t"<<third;
first=sec;
sec=third;
}
getch();
}
