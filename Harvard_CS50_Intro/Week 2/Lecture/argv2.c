#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]) {
    // the outer argv
    for (int i = 0; i < argc; i++) {
        // the inner characters of each argv
        for (int j = 0, n = strlen(argv[i]); j < n; j++) {
            printf("%c\n", argv[i][j]);
        }
    }
}