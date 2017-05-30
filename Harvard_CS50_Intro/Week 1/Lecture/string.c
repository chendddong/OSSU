#include <cs50.h>
#include <stdio.h>

int main(void) {
    printf("Name: ");
    string name = get_string();
    printf("hello, %s\n", name);
}
