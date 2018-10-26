#include<stdio.h>
#include<conio.h>
void palindrome(int n);
void main()
{
 int a;
 clrscr();
 printf("enter any number");
 scanf("%d",&a);
 palindrome(a);
 getch();
}
void palindrome(int n)
{
 int rev=0,rem,b;
 b=n;
 while(n>0)
 {
  rem=n%10;
  rev=rev*10+rem;
  n=n/10;
 }
 if(rev==b)
 {
  printf("number is a palindrome");
 }
 else
 {
 printf("number is not a palindrome");
 }
}