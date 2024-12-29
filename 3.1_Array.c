/* Outline
1. Initialize an Array
2. Access Array Elements
3. Insertion
4. Deletion
5. Traversing an Array
6. Find a element
7. Expanding Array
8. Pros and Cons of Array
*/

/*
Cons of Array:
- Fixed size (inefficient or hard to expand)
- Inefficient in insertion and deletion
- Space wastage

Pros of Array:
- Random access
- Cache locality
- Continuous memory space
*/



#include <stdio.h>
#include <stdlib.h>
#define PRINTARRAY(arr, size) for (int *p = arr; p < arr + size; p++){printf("%d, address= %p\n", *p, p);}
#define __ printf("\n");
/*
Array: Store a batch of data of the same type in a CONTINUOUS memory space.
*/


// 1. Initialize an Array
void initializeArray()
{
    int arrNotInit[7];   // Declare but not initialize， filled with rubbish value

    int arrOnStack[5] = {1, 2, 3, 4, 5}; 
    // Declare and initialize
    // Statically allocate memory on stack, which is automatically released after function end.

    // int FaultInit = {1, 2, 3, 4, 5}; Error: wrong initialization


    int *arrOnHeap = calloc(5, sizeof(int));
    // Dynamically allocate memory on heap, and initialize with 0.
    // Memory must be manually released using free() to avoid memory leak.
}

/* 2. Access Array Elements:

 Element address = Array address + sizeof(element type) * index
                (= First element address + offset)

Time complexity: O(1)
Space complexity: O(1)

*/
int randomAccess(int *num, int size)
{
    int randomIndex = rand() % size;
    return *(num + randomIndex);
}

/* 3. Insertion:  
Shift all subsequent elements back by one position.
Due to the fixed size of array, the last element will be lost.

Time complexity: O(n)
Space complexity: O(1)  

e.g.  insert 7 at index 1 of {1,2,3,4,5}
                          => {1,7,2,3,4}
*/
void insertElement(int *arr, int size, int insertElem, int insertIndex)
{
    for(int i = size - 1; i > insertIndex; i--)
    {
        *(arr + i) = *(arr + i -1);
    }
    *(arr + insertIndex) = insertElem;
}

/* 4. Deletion:
Shift all subsequent elements forward by one position.

Time complexity: O(n)
Space complexity: O(1)

e.g. delete element at index 1 of {1,7,2,3,4}
                               => {1,2,3,4,0}
*/
void deleteElement(int *arr, int size, int deleteElem, int deleteIndex)
{
    for(int i = deleteIndex; i < size - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
}

/* 5. Traversing an Array:
    - Linearly access each element in the array.
    - Time complexity:  O(n)
    - Space complexity: O(1)
*/

/* 6. Find a element:
Time complexity: O(n)
Space complexity: O(1)
*/
int findElement(int *arr, int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(*(arr) + i == target)
            return i;
    }

    return -1;
}

/*
7. Expanding Array:
In most programming languages, the size of array is immutable.
To enlarge an array, a new array with larger size must be created, and the original array copied to the new array.(Inefficient)

Time complexity: O(n)
Space complexity: O(n)
*/
int* expandArray(int *oldArr, int oldSize, int enlargerSize)
{
    int *newArr = calloc(enlargerSize, sizeof(int));
    for(int i = 0; i < oldSize; i++)
    {
        *(newArr + i) = *(oldArr + i);
    }

    return newArr;
}

int main()
{
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        *(arr + i) = i + 1;
        printf("arr[%d] = %d, address = %p\n", i, *(arr + i), arr + i);
    }
    

    printf("Random accessed element = %d\n", randomAccess(arr, 5));
    __;

    insertElement(arr, 5, 7, 1);
    PRINTARRAY(arr, 5);
    __;

    deleteElement(arr, 5, 7, 1);
    PRINTARRAY(arr, 5);
    __;
    
    printf("Result: %d\n", findElement(arr, 5, 3));
    __;
    
    int *newArr = expandArray(arr, 5, 10);
    PRINTARRAY(newArr, 10);


    free(arr);
}