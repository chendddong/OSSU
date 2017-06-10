/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n <= 0) {
        return false;
    }
    
    int start = 0;
    int end = n - 1;
    
    while (start + 1 < end) {
        int mid = (start + end) / 2;
        if (values[mid] == value) {
            return true;
        } else if (values[mid] < value) {
            start = mid;
        } else {
            end = mid;
        }
    }
    
    if (values[start] == value || values[end] == value) {
        return true;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
 


int findLargestNum(int * array, int size){
  
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }
  
  return largestNum;
}


void sort(int values[], int n)
{

  // Base 10 is used
  int i;
  int semiSorted[n];
  int significantDigit = 1;
  int largestNum = findLargestNum(values, n);
  
  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){
    
    int bucket[10] = { 0 };
    
    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < n; i++)
      bucket[(values[i] / significantDigit) % 10]++;
    
    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    // Use the bucket to fill a "semiSorted" array
    for (i = n - 1; i >= 0; i--)
      semiSorted[--bucket[(values[i] / significantDigit) % 10]] = values[i];
    
    
    for (i = 0; i < n; i++)
      values[i] = semiSorted[i];
    
    // Move to next significant digit
    significantDigit *= 10;
    
  }
}
