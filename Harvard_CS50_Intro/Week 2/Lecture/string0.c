#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string s = get_string();
    /* big NULL in C*/
    if (s != NULL) {
        /* C can't use for each loop */
        for (int i = 0; i < strlen(s); i++) {
            printf("%c\n", s[i]);    
        }
        
    }    
}
