#include<stdio.h>
#include<conio.h>

void qs(int no[25], int first, int last){
int i,j,pivot,temp;
if(first<last){
pivot=first;
i=first;
j=last;
while(no[i]<=no[pivot] && i<last)
i++;
while(no[j]>no[pivot])
j--;
if(i<j){
temp = no[i];
no[i]=no[j];
no[j]=temp;
}
}
temp=no[pivot];
no[pivot]=no[j];
no[j]=temp;
qs(no,first,j-1);
qs(no,j+1,last);
}

int main(){
int i, count, no[25];
printf("Elements to be entered");
scanf("%d",&count);
printf(" Enter %d numbers:\n", count);
 for(i=0; i<count; i++)
 scanf("%d", &no[i]);
printf(" The sorted element");
 for(i=0; i<count; i++)
 scanf("%d", &no[i]);

 return 0;

}
