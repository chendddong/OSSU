#include <cs50.h>
#include <stdio.h>

int main(void) {
    int data[] = {23,35,15,7,87};
    int size = sizeof(data) / sizeof(data[0]); 
    int swaps = 0;
    // print the unsorted array
    printf("The unsorted array is: \n");
    for (int i = 0; i < size; i++) {
      printf("\ndata[%d] = %d", i, data[i]);
    }  
    printf("\n\n");
    
    // algorithm
    for (int i = 1; i < size; i++) {
        int currentData = data[i];
        int temp = i;
        while (temp > 0 && data[temp - 1] > currentData) {
            data[temp] = data[temp - 1];
            temp--;
            swaps++;
        }
        data[temp] = currentData;
    }
    
    // print the sorted array
    printf("The number of swaps is: %i\n" , swaps);
    printf("The sorted array is: \n");

    for (int i = 0; i < size; i++) {
      printf("\nadata[%d] = %d", i, data[i]);
    }  
    printf("\n");
        
        
    
}