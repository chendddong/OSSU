#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    string s = get_string();
    if (s != NULL) {
         for (int i = 0, n = strlen(s); i < n; i++) {
             if (s[i] >= 'a' && s[i] <= 'z') {
                 /* Capitalize */
                 printf("%c", s[i] - ('a' - 'A'));
             } else {
                 printf("%c", s[i]);
             }
         }
         printf("\n");
    }

}