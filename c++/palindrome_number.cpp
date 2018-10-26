 #include<iostream.h>

//  this file checks wheather a given no. is palindrome or not



 void main()
 {
   int a  ,b ;
   cin>>a ;
   while(a)
   {
        b+=a%10;
        a/=10;
   }
   if(b==a)
   {
       cout<<"the no is palindrome ";
   }
   else
   {
       cout<<"the no id not a palindrome";
   }

 }
 
