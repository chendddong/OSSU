# Notes in Week 5

###  [notes](http://docs.cs50.net/2016/fall/notes/5/week5.html), [slides](http://cdn.cs50.net/2016/fall/lectures/5/week5.pdf)

### Singly-Linked Lists

*   A linked list node is a special kind of struct with two members:
    *   Data of some data type (int, char, float...)
    *   A pointer to another node of the same type

```C
typedef struct sllist
{
    VALUE val; // data
    struct sillist *next; // pointer
}
sllnode;
```

*   In order to work with linked lists effectively, there are a number of operations that we need to understand

    1.  Create a lined list when it doesn't already exist
    ```C
    sllnode* create(VALUE val);

    sllnode* new = create(6);
    ```
    2.  Search through a linked list to find an element
    ```C
    // always create a curr pointer so we do not mess up 
    // with the original start of the list

    bool find(sllnode* head, VALUE val); 

    bool exists = find(list, 6);
    ```
    3.  Insert a new node into the linked list.
    ```C
    // Populate and insert the node at the beginning of the linked list.
    // mind the order of the pointer, first use the pointer form the new
    // element and point to the old-first element and them point the original
    // head pointer to the new element just created

     sllnode* insert(sllnode* head, VALUE val);

     list = insert(list, 12);
    ```
    4.  Delete a single element from a lined list.
    ```C
    // refer to the doubly-linked list
    ```
    5.  Delete an entire linked list.(destroy it from right to left)

        1.  if you've reached a null pointer, stop.
        2.  Delete the rest of the list.
        3.  Free the current node.

    ```C
    void destroy (sllnode* head);

    destroy(list);
    ```

### Doubly-Linked Lists

```C
typedef struct dllist
{
    VALUE val; // data
    struct dllist *prev; // pointer
    struct dllist *next; // pointer
}
dllnode;
```


*   In order to work with doubly linked lists effectively, there 
are a number of operations that we need to understand

    1.  Create a lined list when it doesn't already exist
    ```C
    // much like what we see in the singly-linked list
    ```
    2.  Search through a linked list to find an element
    ```C
    // much like what we see in the singly-linked list    
    ```    
    3.  Insert a new node into the linked list.
    ```C
    // mind those pointers and actually just draw it
    // simply just to handle the pointers of the newly added pointer first
    // then go to modify the pointers of the old-first node
    dllnode* insert(dllnode* head, VALUE val);

    list = insert(list, 12);
    ```    
    4.  Delete a single element from a linked list.
    ```C
    // just skip the target and reconnect the one before it and the one after.
    void delete(dllnode* target);

    delete(x);
    ```
    5.  Delete an entire linked list.
    ```C
    // much like what we see in the singly-linked list
    ```

### Stacks  

*   It can be implemented as array or LinkedList

```C
// array-based
typedef struct _stack
{
    VALUE array[CAPACITY];
    int top;
}
stack;
```

1.  void push(stack* s, VALUE data);
```C
stack s;
s.top = 0;
push(&s, 28);
// increment top value so every time we try to insert something inside,
// it must be at the right position
```

2.  VALUE pop(stack* s);
```C
// Note that it doesn't delete the number in the position, it just remember
// location and if you insert again, it would rewrite the number in there.
stack s;
int x = pop(&s);
```

```C
// LinkedList-based
// We would prefer the stack to be a global var to keep track of the stack.
typedef struct _stack
{
    VALUE val;
    struct _stack *next;
}
stack;
```

***

### Queues

*   It can be implemented as array or LinkedList

```C
// array-based
typedef struct _queue
{
    VALUE array[CAPACITY];
    int front; // the position of the next dequeue(removed) position
    int size; // keep track of the size of the queue
}
queue;
```

1.  void enqueue(queue* s, VALUE data);
```C
queue q;
q.front = 0;
q.size = 0;
enqueue(&q, 28);
// change front and size value so every time we try to enqueue or dequeue\
// something, it must be at the right position
```

2.  VALUE dequeue(queue* q);
```C
// Note that it doesn't delete the number in the position, it just remember
// location, it would rewrite the number in there if possible. And we need to
// change the front and size respectively. Mind those minor details
queue q;
int x = dequeue(&q);
```

```C
// LinkedList-based -- Doubly-LinkedList
// We would prefer the queue to be a global var to keep track of the queue.
typedef struct _queue
{
    VALUE val;
    struct _queue *prev;
    struct _queue *next;
}
queue;
```

### Hash Tables

*   Hash tables combine the random access ability of an array with the dynamism
of a linedList.
*   This means(if we define our hash table well):
    *   Insertion can start to tend toward theta(1)
    *   Deletion can start to tend toward theta(1)
    *   Lookup can start to tend toward theta(1)

*   A good hash function:
    *   Use only the data being hashed
    *   Use all of the data being hashed
    *   Be deterministic
    *   Uniformly distribute data
    *   Generate very different hash codes for very  similar data 

*   Resolve collision: Chaining


### Tries

[Good Example -- 5:44 from the video](https://www.youtube.com/watch?v=TRg9DQFu0kU&feature=youtu.be)

```C
typedef struct _trie
{
    char university[20];
    struct _trie* paths[10];
}
trie;
```


