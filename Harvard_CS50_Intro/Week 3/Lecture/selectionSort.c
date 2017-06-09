#include <cs50.h>
#include <stdio.h>
#include <limits.h>
int main(void) {
    int arr[7] = {3, 9, 1, 2, 7, 5, 6};
    int num = 7;
    printf("The unsorted array is: \n");
    for (int i = 0; i < num; i++) {
      printf("\narr[%d] = %d", i, arr[i]);
    }  
    printf("\n\n");
    
    /* Selection Sort */
    for (int i = 0; i < num; i++) {
        int min = INT_MAX;
        int minIndex = 0;
        for (int j = i; j < num; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    
    printf("The sorted array is: \n");

    for (int i = 0; i < num; i++) {
      printf("\narr[%d] = %d", i, arr[i]);
    }  
    printf("\n");

}

