// Program to tell if a number is even or not.

#include <stdio.h>

int main(void){

int number;
printf("Enter an integer number\n");
scanf("%d",&number);
if(number%2==0)
    printf("The number %d is even\n",number);
else{
    printf("The number %d is not even\n",number);
 }
 
 return 0;
 }
