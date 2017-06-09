#include <cs50.h>
#include <stdio.h>

int main(void) {
    int arr[7] = {3, 9, 1, 2, 7, 5, 6};
    bool swapped = true;
    int offset = 0;
    int num = 7;
    int swaps = 0;
    printf("The unsorted array is: \n");
    for (int i = 0; i < num; i++) {
      printf("\narr[%d] = %d", i, arr[i]);
    }  
    printf("\n\n");

    while (swapped) {
        swapped = false;
        for (int i = 1; i < 7 - offset; i++) {
            if (arr[i - 1] > arr[i]) {
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = true;
                swaps++;
            }
        }
        offset++;
    }
    
    printf("The sorted array is: \n");
    printf("The total swap is: %d\n", swaps);
    
    for (int i = 0; i < num; i++) {
      printf("\narr[%d] = %d", i, arr[i]);
    }  
    printf("\n");

}

