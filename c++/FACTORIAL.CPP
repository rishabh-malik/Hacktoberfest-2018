#include<iostream.h>
#include<conio.h>
void main()
{
  int num;
  cout<<"enter the digit";
  cin>>num;
  int fct=fact(num);
  cout>>"factorial is ">>fct;
}
int fact(int a)
{
  int n=1;
  while(a)
  {
    n=n*fact(--a);
  }
 return n;
}
