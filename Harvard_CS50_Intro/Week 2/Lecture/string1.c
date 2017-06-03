#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    /* ask user for input */
    string s = get_string();
    /* big NULL in C & and make sure it is a string                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            */
    if (s != NULL) {
        /* C can't use for each loop */
        for (int i = 0 , n = strlen(s); i < n; i++) {
            printf("%c\n", s[i]);    
        }
        
    }    
}
