## Dynamic Allocation of Arrays 

### The problems of fixed arrays

Declaring an array with a fixed size like
```c++
int a[100000];
```
has two typical problems:

* __Exceeding maximum__. Choosing a real maximum is often impossible because the programmer has no control over the size of the data sets the user is interested in. Erroneous assumptions that a maximum will never be exceeded are the source of many programming bugs. Declaring very large arrays can be extremely wasteful of memory, and if there are many such arrays, may prevent the program from running in some systems.
* __No expansion__. Using a small size may be more efficient for the typical data set, but prevents the program from running with larger data sets. If array limits are not checked, large data sets will run over the end of an array with disastrous consequences. Fixed size arrays can not expand as needed.

These problems can be avoided by dynamically allocating an array of the right size, or reallocating an array when it needs to expand.
Both of these are done by declaring an array as a pointer and using the `new` operator to allocate memory, and `delete` to free memory that is no longer needed.

This is exactly what is `vector` does, but let's see how it's done with an array.

### Declare arrays with a pointer and allocation memories with `new`

To create a variable that will point to a dynamically allocated array, declare it as a pointer to the element type. For example,
```c++
int* a = NULL;  // pointer to an int, intiallly to nothing.
```
A dynamically allocated array is declared as a pointer, and must not use the fixed array size declaration. 
The above declaration creates a pointer, but doesn't yet allocate any memory to it.

When the desired size of an array is known, allocate memory for it with the new operator and save the address of that memory in the pointer.
Remember: Pointers may be subscripted just as arrays are. The example below reads in a number and allocates that size array.

```c++
int* a = NULL;   // Pointer to int, initialize to nothing.
int n;           // Size needed for array
cin >> n;        // Read in the size
a = new int[n];  // Allocate n ints and save ptr in a.
for (int i=0; i<n; i++) {
    a[i] = 0;    // Initialize all elements to zero.
}
. . .  // Use a as a normal array
delete [] a;  // When done, free memory pointed to by a.
a = NULL;     // Clear a to prevent using invalid memory reference.
```

### Reference:

* http://www.fredosaurus.com/notes-cpp/newdelete/50dynamalloc.html
