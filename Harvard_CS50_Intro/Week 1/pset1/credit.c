#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
int howManyDigits(long long cardNumber);
long long startWithTwo(long long cardNumber);
long long startWithOne(long long cardNumber);

int main(void) {
   /**
    * AMEX\n 15-digit 34 or 37
    * MASTERCARD\n 16-digit numbers 51, 52, 53, 54, or 55
    * VISA\n 13- and 16-digit 4
    * INVALID\n
   */ 
    long long cardNumber;
    do {
        printf("Number: ");
        cardNumber = get_long_long();  
        break;
    } while (true);
    
    // 3 7 8 2 8 2 2 4 6 3 1 0 0 0 5

    
    /* Check if the card is legit */  
    
    /* sum of even numbers */
    long long sumOfEvens = 0;
    long long numberOfP = 10;
    while (numberOfP < cardNumber) {
        long long remain = (cardNumber / numberOfP) % 10;
        remain *= 2;
        if (remain >= 10) {
            /* Last digit */
            int temp = remain % 10;
            remain = temp + remain / 10;
        }
        sumOfEvens += remain;
        numberOfP *= 100;
        // printf("The remainer is %lld\n, the sum is %lld\n",remain, sumOfEvens);
    }
    
    /* sum of odd numbers */

    long long sumOfOdds = 0;
    long long numberOfPo = 1;
    while (numberOfPo < cardNumber) {
        long long remain = (cardNumber / numberOfPo) % 10;
        sumOfOdds += remain;
        numberOfPo *= 100;
        // printf("The remainer is %lld\n, the sum is %lld\n",remain, sumOfOdds);
    }
    
    if ((sumOfOdds + sumOfEvens) % 10 == 0) {
        if (startWithTwo(cardNumber) == 34 || startWithTwo(cardNumber) == 37) {
            if (howManyDigits(cardNumber) == 15) {
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
            }
        } else if (startWithTwo(cardNumber) >= 51 && startWithTwo(cardNumber) <= 55) {
            if (howManyDigits(cardNumber) == 16) {
                printf("MASTERCARD\n"); 
            } else {
                printf("INVALID\n");
            }
        } else if (startWithOne(cardNumber) == 4) {
            if (howManyDigits(cardNumber) == 16 || howManyDigits(cardNumber) == 13) {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }  
    } else {
        /* INVALID situation */
        printf("INVALID\n");
    }
}

int howManyDigits(long long cardNumber) {
    long long number = cardNumber;
    int count = 0;

    while(number != 0)
    {
        number /= 10;
        ++count;
    } 
    return count;
}

long long startWithTwo(long long cardNumber) {
    long long first = cardNumber;
    /* Remove last digit from number till only one digit is left */
    while(first >= 100)
    {
        first = first / 10;
    }
    return first;        
}

long long startWithOne(long long cardNumber) {
    long long first = cardNumber;
    /* Remove last digit from number till only one digit is left */
    while(first >= 10)
    {
        first = first / 10;
    }
    return first;        
}