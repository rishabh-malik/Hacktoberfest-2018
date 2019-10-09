#include <stdio.h>

int main(){

        int i,j,flag=0;
        scanf("%d",&j);

        for (i =2;i<j;i++)
        {
                if (j%i==0)
                        flag = 1;
        }

        if (flag==0)
                printf("Yes\n");
        else
                printf("No\n");

        return 0;
}
