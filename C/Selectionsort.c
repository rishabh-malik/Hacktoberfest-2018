#include <stdio.h>
void Selectionsort(int a[], int n);
int main() {
    int n, i;
    printf("How many elements?");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter array elements:");

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    Selectionsort(a, n);

    printf("\nArray after sorting:");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void Selectionsort(int a[], int n){
    int min, h;
    for (int j = 1; j < n; j++) {
        min = j;
        for (int i = j+1; i < n; i++) {
            if(a[i]<a[min]) {
                min = i;
            }
        }
        h = a[min];
        a[min] = a[j];
        a[j] = h;
    }
}