//LINEAR SEARCH
#include<iostream.h>
#include<conio.h>
int search(int [],int,int);
void main()
{clrscr();
int a[100],m,n;
cout<<"enter the no. of elements:";
cin>>n;
cout<<"\nenter the elements of the array:";
for(int i=0;i<n;i++)
cin>>a[i];
cout<<"\nenter the element to be searched for:";
cin>>m;
int y= search(a,n,m);
if(y==-1)
cout<<"\nnot found";
getch();}
int search(int q[],int n,int m)
{ int flag=-1;
for(int j=0;j<n;j++)
{       if(q[j]==m){
		    int pos=j;
		    cout<<"\nelement found at position:"<<pos+1;
		    flag=j;}
}return flag;}