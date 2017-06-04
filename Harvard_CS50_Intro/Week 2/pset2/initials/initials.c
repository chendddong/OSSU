#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_name(string name);
void get_initials(string valid_name);

int main(void) {
    // Get user's name and check if they have characters
    // other than letters and space.
    string name;
    do {
        // printf("Your full name: ");
        name = get_string();        
    } while (!check_name(name));

    get_initials(name);
}

bool check_name(string name) {
    // check the character they must between 'A'-'Z', 'a'-'z' and ' '
    for (int i = 0, n = strlen(name); i < n; ++i) {
        if ((name[i] >= 'A' && name[i] <= 'Z') || 
            (name[i] >= 'a' && name[i] <= 'z') ||
            (name[i] == ' ')) {
                continue;
        } else {
            return false;
        }   
    }
    return true;
}
// Test cases: 
//          "cd off ab"
//          "cd  off"
//          "   ab   "
void get_initials(string valid_name) {
    
    bool last_is_space = true;
    for (int i = 0, n = strlen(valid_name); i < n; ++i) {
        char ch = valid_name[i];
        if (ch == ' ') {
            last_is_space = true;
            continue;
        }
        
        if (last_is_space) {
            printf("%c", toupper(ch));
            last_is_space = false;
        }
    }
    printf("\n");
    
}