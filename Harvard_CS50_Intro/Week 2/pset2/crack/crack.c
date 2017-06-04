#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

#define _XOPEN_SOURCE
#define MAGIC 25

char *crypt(const char *key, const char *salt);

int main(int argc, string argv[]) {
    // validate arguments
    if (argc != 2) {
        // warn user
        printf("Usage: %s hash\n", argv[0]);
        return 1;
    }
    
    // get the hashed password
    string hash = argv[1];
    // andi:50.jPgLzVirkc
    // jason:50YHuxoCN9Jkc
    // malan:50QvlJWn2qJGE
    // mzlatkova:50CPlMDLT06yY
    // patrick:50WUNAFdX/yjA
    // rbowden:50fkUxYHbnXGw
    // summer:50C6B0oz0HWzo
    // stelios:50nq4RV/NVU0I
    // wmartin:50vtwu4ujL.Dk
    // zamyla:50i2t3sOSAZtk
    
    string salt = "50";
    // key : guess them (1, 2, 3, 4, characters, alphabetical)
    // crack the password




    // one letter
    char string1[] = "A";

    for (int i = 0; i <= MAGIC; i++) {
        string1[0] = i + 'A';
        int v;
        char *str2 = crypt(string1, salt);
        v = strcmp(hash, str2);
        if (v == 0) {
            printf("%c\n", string1[0]);
            return 0;
        }
        eprintf("%c\n", string1[0]);
    }

    for (int i = 0; i <= MAGIC; i++) {
        string1[0] = i + 'a';
        int v;
        char *str2 = crypt(string1, salt);
        v = strcmp(hash, str2);
        if (v == 0) {
            printf("%c\n", string1[0]);
            return 0;
        }
        eprintf("%c\n", string1[0]);
    } 
    
    // two letter
    char string2[] = "AA";
    
    for (int i = 0; i <= MAGIC; i++) {
        string2[0] = i + 'A';
        for (int j = 0; j <= MAGIC; j++) {
            string2[1] = j + 'A';
            int v;
            char *str2 = crypt(string2, salt);
            v = strcmp(hash, str2);
            if (v == 0) {
                printf("%c%c\n", string2[0], string2[1]);
                return 0;
            }
            eprintf("%c%c\n", string2[0], string2[1]);
        }
        
        for (int j = 0; j <= MAGIC; j++) {
            string2[1] = j + 'a';
            int v;
            char *str2 = crypt(string2, salt);
            v = strcmp(hash, str2);
            if (v == 0) {
                // Aa
                printf("%c%c\n", string2[0], string2[1]);
                return 0;
            }
            eprintf("%c%c\n", string2[0], string2[1]);        
        }        
    }
    
    for (int i = 0; i <= MAGIC; i++) {
        string2[0] = i + 'a';
        for (int j = 0; j <= MAGIC; j++) {
            string2[1] = j + 'A';
            int v;
            char *str2 = crypt(string2, salt);
            v = strcmp(hash, str2);
            if (v == 0) {
                // aA
                printf("%c%c\n", string2[0], string2[1]);
                return 0;
            }
            eprintf("%c%c\n", string2[0], string2[1]);
        }
        
        for (int j = 0; j <= MAGIC; j++) {
            string2[1] = j + 'a';
            int v;
            char *str2 = crypt(string2, salt);
            v = strcmp(hash, str2);
            if (v == 0) {                
                // aa
                printf("%c%c\n", string2[0], string2[1]);
                return 0;
            }
            eprintf("%c%c\n", string2[0], string2[1]);
        }        
    }
    
    // aaa
    // aaA
    // aAa
    // aAA

    
    // three letter
    char string3[] = "AAA";
    for (int i = 0; i <= MAGIC; i++) {
        string3[0] = i + 'a';
        
        for (int j = 0; j <= MAGIC; j++) {
            string3[1] = j + 'a';
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'a';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                    // aaa
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
                eprintf("%c%c%c\n", string3[0], string3[1], string3[2]);
                
            }
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'A';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                      // aaA
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
                eprintf("%c%c%c\n", string3[0], string3[1], string3[2]);
            }
        }
        
        for (int j = 0; j <= MAGIC; j++) {
            string3[1] = j + 'A';
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'a';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                      // aAa
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
                eprintf("%c%c%c\n", string3[0], string3[1], string3[2]);
            
            }
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'A';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                      // aAA
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
                eprintf("%c%c%c\n", string3[0], string3[1], string3[2]);
            
            }
        }
    }
    
    // Aaa
    // AaA
    // AAa
    // AAA

    for (int i = 0; i <= MAGIC; i++) {
        string3[0] = i + 'A';
        
        for (int j = 0; j <= MAGIC; j++) {
            string3[1] = j + 'a';
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'a';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                      // aaa
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
                eprintf("%c%c%c\n", string3[0], string3[1], string3[2]);
                
            }
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'A';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                      // aaA
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
            }
        }
        
        for (int j = 0; j <= MAGIC; j++) {
            string3[1] = j + 'A';
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'a';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                      // aAa
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
                eprintf("%c%c%c\n", string3[0], string3[1], string3[2]);
                
            }
            for (int k = 0; k <= MAGIC; k++) {
                string3[2] = k + 'A';
                int v;
                char *str2 = crypt(string3, salt);
                v = strcmp(hash, str2);
                if (v == 0) {                      // aAA
                    printf("%c%c%c\n", string3[0], string3[1], string3[2]);
                    return 0;
                }
                eprintf("%c%c%c\n", string3[0], string3[1], string3[2]);
                
            }
        }
    }    
    
    // aaaa
    // aaaA
    // aaAa
    // aaAA
    // aAaa
    // aAaA
    // aAAa
    // aAAA
    // -------
    // Aaaa
    // AaaA
    // AaAa
    // AaAA
    // AAaa
    // AAaA
    // AAAa
    // AAAA
        
    // four letter
    char string4[] = "AAAA";
    
    for (int i = 0; i <= MAGIC; i++) {
        string4[0] = i + 'a';
        for (int j = 0; j <= MAGIC; j++) {
            string4[1] = j + 'a';        
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'a';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                         // aaaa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aaaA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'A';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aaAa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aaAA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
        }
            
        for (int j = 0; j <= MAGIC; j++) {
            string4[1] = j + 'A';        
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'a';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAaa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAaA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'A';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAAa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAAA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
        }
    }

    for (int i = 0; i <= MAGIC; i++) {
        string4[0] = i + 'A';
        for (int j = 0; j <= MAGIC; j++) {
            string4[1] = j + 'a';        
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'a';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aaaa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aaaA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'A';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aaAa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aaAA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
        }
            
        for (int j = 0; j <= MAGIC; j++) {
            string4[1] = j + 'A';        
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'a';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAaa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAaA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
            for (int k = 0; k <= MAGIC; k++) {
                string4[2] = k + 'A';    
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'a';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAAa
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
                for (int l = 0; l <= MAGIC; l++) {
                    string4[3] = l + 'A';  
                    int v;
                    char *str2 = crypt(string4, salt);
                    v = strcmp(hash, str2);
                    if (v == 0) {                          // aAAA
                        printf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);
                        return 0;
                    }
                    eprintf("%c%c%c%c\n", string4[0], string4[1], string4[2], string4[3]);                    
                }
            }
        }
    }    
    
        
                
                
                
    return 0;
}