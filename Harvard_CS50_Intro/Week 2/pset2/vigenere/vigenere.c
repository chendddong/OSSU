#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(int argc, string argv[])
{

    // var stores user message
    string msg = NULL; 
    // variable stores key
    string key = argv[1];
    // last character examined
    int lastChar = 0; 
    // counter
    int counter = 0; 
   

   
    // validate arguments
    if (argc != 2) {
        // warn user
        printf("You must enter a single command-line argument: \n");
        // value of 1 returns error
        return 1;
    }
    
    // make sure keyword is from A-Z
    for (int i = 0, n = strlen(key); i < n; i++) {
         // if it is not alphabetical
        if (!isalpha(argv[1][i])) {
            // warn the user
            printf("you've entered non-alphabetical chars\n"); 
            // return error
            return 1;  
                  
            }
        }
         
    // loop through as long as message is NULL or empty 
    do {
        // get message from user
        printf("plaintext: ");
        msg = get_string(); 
    
    } while (msg == '\0'); 
     
    
    // loop through message and manipulate string 
    // using functions from imported libraries
    int msgN = strlen(msg);
    int keyN = strlen(key);
    printf("ciphertext: ");

    for (int i = 0, j = msgN; i < j; i++) { 
    
        // alphabetical letters   
        if (isalpha(msg[i])) {
            // set counter to modulo length of keyword
            counter = lastChar % keyN;
            // preserve LOWERCASE
            if (islower(msg[i])) {
                if (islower(key[counter])) {
                    msg[i] = ((msg[i] - 'a' + key[counter] - 97) % 26) + 97;
                    printf("%c", msg[i]);
                } else {
                    msg[i] = ((msg[i] - 'a' + key[counter] - 65) % 26) + 97;
                    printf("%c", msg[i]);
                }
            }
            
            // preserve UPPERCASE
            if (isupper(msg[i])) {
                if (islower(key[lastChar])) {
                    msg[i] = ((msg[i] - 'A' + key[counter] - 97) % 26) + 65;
                    printf("%c", msg[i]);
                } else {
                    msg[i] = ((msg[i] - 'A' + key[counter] - 65) % 26) + 65;
                    printf("%c", msg[i]);
                }
            }
            lastChar++;
        } else {   
            // print non-alphabetical charachter
            printf("%c", msg[i]);
        }
    }
    
    // newline
    printf("\n");
    
    
    // No errors exist! 
    return 0; 
}