# Notes in Week 1

* ###  [notes](http://docs.cs50.net/2016/fall/notes/1/week1.html)
* ###  [slides](http://cdn.cs50.net/2016/fall/lectures/1/week1.pdf)


1. int
    * range : -2^31 -- 2^31
2. char
    * range : -128 - 127
3. float 32 bits
4. double 64 bits
5. void
6. bool -- #include <cs50.h>

    ##### Use boolean in C
    ###### Option 1

    typedef int bool;
    #define true 1
    #define false 0

    ###### Option 2

    typedef int bool;
    enum { false, true };

    ###### Option 3

    typedef enum { false, true } bool;

    ###### Option 4 (C99)

    #include <stdbool.h>

    **Explanation**

    >Options 1, 2 and 3 will have in practice the same identical behavior. #2
    and #3 don't use #defines though, which in my opinion is better.
    Option 4 will work only if you use C99 and it's the "standard way" to do it. Choose this if possible.
    If you are undecided, go with #3!
7. string

