#include <stdio.h>
#include <cs50.h>

int main(void) {
    int showerTime;
    do {
        printf("Minutes: ");
        showerTime = get_int();        
    } while (showerTime <= 0);
        
    printf("Bottles: %i\n", showerTime * 12 );
}

