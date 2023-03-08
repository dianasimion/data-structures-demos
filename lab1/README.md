# Lab 1 - Recap

## Pointers

-   All variables have:
    -   a start address
    -   a size (depends on the architecture)
    -   a content / value
-   Pointers are **variables** that contain the **start address** of _another_ variable (this variable can be a pointer as well).

## Pass by value vs reference

### Pass by value

```c
int a = 3;
int b = 100;
swap(a, b);

void swap(int a, int b);
```

-   When the swap function is executed, it makes a **copy** of each received argument. These copies of a and b will be located at _other_ memory addresses than the original ones (and will contain our values).

-   When the swap function returns from its call, all the copied arguments and local variables declared in the function will be **destroyed**.

-   In the main code, a and b will still have their original values, since we **didn't perform any changes on them**. We actually performed all the changes on their copies (which now don't exist anymore).

### Pass by reference

```c
int a = 3;
int b = 100;
swap(&a, &b);

void swap(int *a, int *b);
```

-   Passing the addresses of a and b will offer control on their content too (by dereferencing the pointers that contain their addresses). This way, when performing the changes in the swap function, we will work with the values at the addresses contained by the *a and *b received parameters.

## Dynamic memory allocation

### Static vs dynamic

Static memory allocation:

-   variables go on the stack
-   happens at compile time

Dynamic memory allocation:

-   allocated memory goes on the heap
-   happens at run time

What goes on here?

```c
int* a = malloc(5 * sizeof(int))
```

The pointer `a` will contain the _starting address_ of the dynamically allocated memory.

-   The pointer `a` will go on the **stack** &rarr; `sizeof(int*)` bytes. (size of a pointer)

-   The dynamically allocated memory will go on the **heap** &rarr; `5 * sizeof(int)` bytes.

### To cast or not to cast

```c
int* a = (int*) malloc(3 * sizeof(int));

// vs

int* a = malloc(3 * sizeof(int));
```

The return type of malloc is `void*`.
In **C**, the compiler knows how to perform the cast from `void*` to the type of the pointer.

\* However, in C++ the cast is mandatory. So if you want your app to be compatible with C++ as well you should cast every dynamic memory allocation function call.

More about the advatantages and disadvantages of both versions, in this [post](https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc).

### Sizeof

The typical way we learn to allocate an array of elements looks like this:

```c
RandomDataStructure* ds_array = malloc(n * sizeof(RandomDataStructure));
```

This works fine, but if we decide to change the type of the elements contained by the array, we'd have to update it in 2 places.

In order for our code to be **more generic** we could update the code to something like this:

```c
RandomDataStructure* ds_array = malloc(n * sizeof(*ds_array));
```

This says: "I want the size of an element in my array to be the size of _the value at the start address contained by the pointer ds_array_". This size is the same with the previous one.

Now, if we decide to change the data structure type, we'll have to only do it in one place.

### Free the memory

-   Tips:

    -   Always free the memory in the reverse order of allocating it. Start to free the "inner" variables first, and the "outer" ones last.
    -   Always check if the result of malloc/calloc/realloc call failed. (Use the `DIE` macro)
    -   Don't free pointers that don't reference dynamic allocated memory.
    -   Don't double free the memory.

-   How to know where the memory leaks come from?
    -   compile with `gcc -g -Wall -Wextra ...`
    -   run `valgrind --leak-check=full --show-leak-kinds=all ./executable`
