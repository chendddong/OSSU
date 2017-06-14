# Notes in Week 4

###  [notes](http://docs.cs50.net/2016/fall/notes/4/week4.html), [slides](http://cdn.cs50.net/2016/fall/lectures/4/week4.pdf)

### Hexadecimal 

* Often use it as the memory address

| Decimal   |      Binary      |  Hexadecimal |
|:---------:|:----------------:|:------------:|
| 0  |  0000 | 0x0 |
| 1  |  0001 | 0x1 |
| 2  |  0010 | 0x2 |
| 3  |  0011 | 0x3 |
| 4  |  0100 | 0x4 |
| 5  |  0101 | 0x5 |
| 6  |  0110 | 0x6 |
| 7  |  0111 | 0x7 |
| 8  |  1000 | 0x8 |
| 9  |  1001 | 0x9 |
| 10 |  1010 | 0xA |
| 11 |  1011 | 0xB |
| 12 |  1100 | 0xC |
| 13 |  1101 | 0xD |
| 14 |  1110 | 0xE |
| 15 |  1111 | 0xF |


### C -- Basic Data type
| Data type   |      Size(bytes)     |
|:---------:|:----------------:|
|   int   |  4  | 
|   char   |  1  | 
|   float   |  4  | 
|   double   |  8  | 
|   long long   |  8  | 
|   char*, int* ...   |  4(32 bits) or 8(64 bits)  | 

### Pointer

\*: goes to  the pointer

\&: extract the pointer 


### Dynamic Memory Allocation

[An example of how to use DMA](https://www.youtube.com/watch?v=ywqB3ZTf8OE&feature=youtu.be)

1.  every block of memory that you malloc() must subsequently be free()d.
2.  Only memory that you malloc() should be free()d
3.  Do not free() a block of memory more than once

### Structures

Creation:

```C

struct car {
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};

```

Access:

```C
// declaration
struct car mycar;

// field accessing
mycar.year = 2011;
strcpy(mycar.plate, "CS50");
mycar.odometer = 50505;

// another way
struct car *mycar = malloc(sizeof(struct car)); 

(*mycar).year = 2011;
strcpy((*mycar).plate, "CS50");
(*mycar).odometer = 50505;

// another way
struct car *mycar = malloc(sizeof(struct car)); 

mycar->year = 2011;
strcpy(mycar->plate, "CS50");
mycar->odometer = 50505;
```

Defining Custom Data Types:

```C
typedef struct car 
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
}
car_t;
```

### File Pointers

*   fopen()
    *   Opens a file and returns a file pointer to it
    *   Always check the return value to make sure you don't get back NULL.
    ```C
    // read
    FILE* ptr1 = fopen("file1.txt","r");
    // write
    FILE* ptr2 = fopen("file2.txt","w");
    // append
    FILE* ptr3 = fopen("file3.txt","a");

    ```
*   fclose()
    *   Close the file pointed to by the given file pointer
    ```C
    fclose(ptr1);
    ```
*   fgetc()
    *   Reads and returns the next character from the file pointed to.
    *   Note: The operation of the file pointer passed in as a parameter must
    be "r" for read, or you will suffer from an error.
    ```C
    char ch = fgetc(ptr1);
    ```
    *   The 'cat' command:
    ```C
    char ch;
    // end of file
    while ((ch = fgetc(ptr)) != EOF)
        printf("%c", ch);
    ```
*   fputc()
    *   Writes or appends the specified character to the pointed-to file.
    *   Note: The operation of the file pointer passed in as a parameter must
    be "w" for write or "a" for append, or you will suffer an error.
    ```C
    fputc('A', ptr2);
    ```
    *   The 'cp' command:
    ```C
    char ch;
    // end of file
    while ((ch = fgetc(ptr)) != EOF)
        fputc(ch, ptr2);
    ```
*   fread()
    *   Reads <qty> unites of size <size> form the file pointed to and stores
    them in memory in a buffer(usually an array) pointed to by <buffer>.
    *   Note: The operation of the file pointer passed in as a parameter must
    be "r" for read, or you will suffer from an error.
    ```C
    // prototype
    fread(<buffer>, <size>, <qty>, <file pointer>);

    // Example 0:
    int arr[10];
    fread(arr, sizeof(int), 10, ptr);

    // Example 1:
    double* arr2 = malloc*(sizeof(double) * 80);
    fread(arr2, sizeof(double), 80, ptr);

    // Example 2:
    char c;
    fread(&c, sizeof(char), 1, ptr);
    ```    
*   fwrite()
    *   Writes <qty> unites of size <size> form the file pointed to by
    reading them from a buffer(usually an array) pointed to by <buffer>.
    *   Note: The operation of the file pointer passed in as a parameter must
    be "w" for write or "a" for append, or you will suffer from an error.
    ```C
    // prototype
    fwrite(<buffer>, <size>, <qty>, <file pointer>);

    // Example 0:
    int arr[10];
    fwrite(arr, sizeof(int), 10, ptr);

    // Example 1:
    double* arr2 = malloc*(sizeof(double) * 80);
    fwrite(arr2, sizeof(double), 80, ptr);

    // Example 2:
    char c;
    fwrite(&c, sizeof(char), 1, ptr);

##### Other useful functions

| Function  |  Description    |
|:---------:|---------------|
|   fgets()   |  Reads a full string from a file  | 
|   fputs()   |  Writes a full string from a file  | 
|   fprintf()   |  Writes a formatted string to a file  | 
|   fseek()  |  Allows you rewind or fast-forward within a file  | 
|   ftell()   |  Tells you at what (byte) position you are at within a file  | 
|   feof()   |  Tells you whether you've read to the end of a file | 
|   ferror() | Indicates whether an error has occurred in working with a file|
