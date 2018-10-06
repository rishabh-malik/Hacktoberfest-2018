#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int binarySearch(int array[], int start, int size, int number) {
    if(size >= 1) {

        int middle = start + (size - 1) / 2;

        if (array[middle] == number)
            return middle;

        if(array[middle] > number) {
            return binarySearch(array, start, middle - 1, number);
        }

        if(array[middle] < number) {
            return binarySearch(array, middle + 1, size, number);
        }
    }

    return -1;
}

int main() {

    int numbers[10];
    int n = 10;
    srand(time(0));
    for(int i = 0; i < n; i++) {
        int random = rand() % 20;
        numbers[i] = random;
        printf("%d ", random);
    }

    printf("\n");

    int searchFor = numbers[rand() % n];
    printf("%d\n",searchFor);

    int i, j;
    for ( i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(numbers[j] > numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    int a = binarySearch(numbers, 0, n, searchFor);
    printf("%d", a);

    return 0;
}