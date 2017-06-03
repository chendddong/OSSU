#include <stdio.h>

int main(void) {
    for (int i = 65; i < 65 + 26; ++i) {
        // could be (char) i
        printf("%c is %i\n", i, i);
    }
}