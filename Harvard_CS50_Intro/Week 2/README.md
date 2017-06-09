# Notes in Week 2

* ###  [notes](http://docs.cs50.net/2016/fall/notes/2/week2.html)
* ###  [slides](http://cdn.cs50.net/2016/fall/lectures/2/week2.pdf)

### Debugging
1.  Always focus on the first bug and try to solve it one by one
2.  Use extra print to see the alteration of variables
3.  Rubber duck...
4.  Some standard regarding the code
    1.  scope: You know what
    2.  correctness: AC
    3.  design: efficiency
    4.  style: Add some useful but concise comments

5.  complete ASCII chart
![Complete ASCII chart](https://github.com/chendddong/OSSU/blob/master/Harvard_CS50_Intro/Week%202/ASCII.png)
6.  the 'man' [link](https://reference.cs50.net/)
7.  the '\0' ends a string
8.  command-line argument of the main
9.  Exit code 0; Use the command below to check the exit code.
    >$ echo $?
10. We cannot assign an array to another array
    ```C
    #include <stdio.h>

    void set_array(int array[4]);
    void set_int(int x);

    int main(void) {
        int a = 10;
        int b[4] = {0, 1, 2, 3};
        set_int(a);
        set_array(b);
        /* Should be 10 22*/
        printf("%d %d\n", a , b[0]);
    }

    void set_array(int array[4]) {
        array[0] = 22;
    }

    void set_int(int x) {
        x = 22;
    }
    ```
11. Macro:
    ```C
    #define NAME REPLACEMENT
    #define PI 3.14159265
    #define COURSE "CS50"
    ```

