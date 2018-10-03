//area of triangle using heron's formula
#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int a,b,c,s;
float d,f;
cout<<"enter a:";
cin>>a;
cout<<"enter b:";
cin>>b;
cout<<"enter c:";
cin>>c;
s=(a+b+c)/2;
cout<<"s="<<s;
d=(s*(s-a)*(s-b)*(s-c));
f=pow(d,1.0/2.0);
cout<<"\n"<<"area="<<f;
getch();
}