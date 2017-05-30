#include <cs50.h>
#include <stdio.h>

int main (void) {
    char c = get_char();
    
    switch (c) {
        case 'y':
        case 'Y':
            printf("yes\n");
            break;
        case 'n':
        case 'N':
            printf("no\n");
            
        default:
            printf("error\n");
            break;
    }
}