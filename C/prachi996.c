#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,nE;
    int *ptr;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    ptr=(int*) calloc(n,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ptr[i]);
    }
     printf("1.Add an elment to arrray \n2.Delete an element from array \n3.Search an element from array\n0.EXIT\n");
     scanf("%d",&nE);
    while (nE!=0)
    {
    
     switch (nE)
     {
         int a;
     case 1:
     printf("enter a element which you want to add :");
     scanf("%d",&a);
     n=n+1;
      printf("NEW ARRAY IS\n");
     for (int i = 0; i <n; i++)
     {
         ptr[n-1]=a;
        printf("%d\n",ptr[i]);
     }
     
     break;

      case 2:
      printf("enter a position of element which you want to delete :");
     scanf("%d",&a);
     for (int i = a-1; i < n-1; i++)
     {
         ptr[i]=ptr[i+1];
     }
     for (int i = 0; i < n-1; i++)
     {
         printf("%d\n",ptr[i]);
     }
     
     break;

      case 3:
      printf("enter a element which you want to search :");
     scanf("%d",&a);
      for (int i = 0; i < n; i++)
      {
          if (ptr[i]==a)
          {
              printf("element found at position %d \n",i+1);
          }
      }
       
     break;
     
     default:
     printf("INVALID!!!");
         break;
     }
    }
    
    
    return 0;
}
