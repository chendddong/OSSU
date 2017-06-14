#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    printf("s: ");
    string s = get_string();
    
    if (s == NULL) {
        return 1; // exit badly
    }  
    
    string t = s;
    if (strlen(t) > 0) { 
        t[0] = toupper(t[0]);
    }
    
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    
}