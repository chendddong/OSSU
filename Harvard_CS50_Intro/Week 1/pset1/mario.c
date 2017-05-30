#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void) {
    /* Getting input from user */
    int height;
    do {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height > 23);
    
    if (height == 0) {
        exit(0);
    }
    
    /* height = 4 */ 
    // index = 1 -> height;
    // print 
    // height - index " " and then index # then 2 " " then index # then height - index " "
    // height - (index + 1) " " and then index # then 2 " " then index # then height - (index + 1) " ";
    // .
    // .
    // .
    /* The total number of rows we need */
    for (int i = 1; i <= height; i++) {
        /* left-side space */
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        /* left-side hashes */
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        /* middle space*/
        for (int j = 0; j < 2; j++) {
            printf(" ");
        }
        /* right-side space */
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        /* This is too harsh, I guess for saving some space? :) */
        // for (int j = 0; j < height - i; j++) {
        //     printf(" ");
        // }
        printf("\n");
    }
}
