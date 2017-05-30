#include <cs50.h>
#include <stdio.h>
void print_name(string s);
/* function sequence matters */ 


int main (void) {
    string s = get_string();
    print_name(s);
}

void print_name(string s) {
    printf("hello, %s\n", s);
}


