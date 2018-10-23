#include<stdio.h>
#include<conio.h>
void main()
{int A[3][3];
int i,j,d=0,l=0,u=0;
clrscr();
printf("enter element in array \n");
for(i=0;i<3;i++)
 {for(j=0;j<3;j++)
   { printf("\t");
   scanf("%d",&A[i][j]);
   }
    printf("\n");
  }
printf("entered matrix is: \n");
for(i=0;i<3;i++)
 {for (j=0;j<3;j++)
  { printf("  %d \t ",A[i][j]);
   }
    printf("\n");
 }
  for(i=0;i<3;i++)
   {for (j=0;j<3;j++)
    { if (i>j)
      l=l+A[i][j];
      else if(i<j)
       u=u+A[i][j];
	else
       d=d+A[i][j];
       }
     }
      printf("upper elements sum is: %d \n " ,u);
      printf("lower elements sum is : %d  \n ",l);
      printf("diagonal element sum is : %d \n ",d);
      getch();
      }
