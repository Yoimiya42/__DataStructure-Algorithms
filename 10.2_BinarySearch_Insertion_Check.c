# include <stdio.h>
# include <stdlib.h>

typedef int (*InsertFunc)(int*, int, int);
typedef int (*checkFunc)(int*, int, int);


int calculateMid(int start, int end);

int insertNoDup(int* arr, int size, int value);
int insertWithDup(int* arr, int size, int value);

int insertNum(int* arr, int size, int value, InsertFunc insertFunc);

int checkLeft(int* arr, int size, int target);
int checkRight(int* arr, int size, int target);





// ------------------  Binary Search Insertion -----------------------
int calculateMid(int start, int end)
{
    return start + (end - start) / 2;
}

/* ------------------------------------------------------------------
Case 1: insert a value into an array with no duplicate values
Ultimately, the 'start' points to the first element exceeding the target
While the 'end' points to the first falling below the target

{1, 3, 5,  7, 9, 11, 13} insert 6
        |   |
        end start

*/
int insertNoDup(int* arr, int size, int value)
{
    int start = 0;
    int end = size - 1;
    int mid  = 0;

    while(start <= end)
    {   
        mid = calculateMid(start, end);

        if (arr[mid] < value)      // [mid] || → [mid + 1, end]
        {
            start = mid + 1;
        }
        else if (arr[mid] > value)  // [start, mid - 1] ← || [mid]
        {
            end = mid - 1;
        }
    }
    return start;
}

/* -------------------------------------------------------------------
Case 2: insert a value into an array with duplicate values
Ultimately, the 'start' points the first element exceeding/equal to the target
While the 'end' points to the first dalling below the target

{2, 4,  7, 7, 7, 9, 12, 16} insert 7
    |   |
   end start      
*/
int insertWithDup(int* arr, int size, int value)
{
    int start = 0;
    int end = size - 1;
    int mid = 0;

    while(start <= end)
    {
        mid = calculateMid(start, end);

        if(arr[mid] < value)          // [mid] || → [mid + 1, end]
        {
            start = mid + 1;
        }
        else    // arr [mid] >= value    [start, mid] ← || [mid + 1, end]
        {  
            end = mid - 1;
        }
    }

    return start;
}

// ----------------------  Insertion  ---------------------------------
int insertNum(int* arr, int size, int value, InsertFunc insertFunc)
{
    int index = insertFunc(arr, size, value);
    for(int i = size - 1 ; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    printf("Insertion index = %d", index);

    return index;
}

/* -------------------------------------------------------------------
Case 3: find the left boundary 
Given a sorted array nums of length n, which may contain duplicate elements,
return the index of the leftmost occurrence of the target value. If not present, return -1.

{1, 4, 5,  9, 9, 9, 12, 16, 24, 36, 42}    target = 9   => return 3
       |   |
      end start
    
*/
int checkLeft(int* arr, int size, int target)
{
    int start = 0;
    int end = size -1;
    int mid = 0;

    while(start <= end)
    {
        mid = calculateMid(start, end);
        if (arr[mid] < target)     // [mid] || → [mid + 1, end]
        {
            start = mid + 1;
        }
        else  // arr[mid] >= target    [start, mid] ← || [mid + 1, end]
        {
            end = mid - 1;
        }
    }

    if (start == size || arr[start] != target)
    {   // index out of boundary || target not exist  
        return -1;
    }else{
        return start;
    }
}

/* -------------------------------------------------------------------
Case 4: fine the right boundary
{1, 5, 7, 8, 8, 8, 8, 8, 8, 8,  10, 16}   target = 8  => return 9
                            |    |
                           end start
*/

int checkRight(int* arr, int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = 0;

    while(start <= end)
    {
        mid = calculateMid(start, end);
        if (arr[mid] <= target)
        {
            start = mid + 1;
        }
        else   // arr[mid] > value
        {
            end = mid - 1;
        }
    }

    if (end == -1 || arr[end] != target)
    {
        return -1;
    }else{
        return end;
    }
}


// ------------------------- T E S T ----------------------------
void test_InsertNoDup()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 6;

    int index = insertNum(arr, size, value, insertNoDup);  
    // expected : 3   => {1, 3, 5, 6, 7, 9, 11}
}

void test_InsertWithDup()
{
    int arr[] = {2, 4, 7, 7, 7, 9, 12, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 7;

    int index = insertNum(arr, size, value, insertWithDup);
    // expected : 2   => {2, 4, 7, 7, 7, 7, 9, 12}
}

void test_checkLeft1()
{
    int arr[] = {1, 4, 5, 9, 9, 9, 12, 16, 24, 36, 42};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int index = checkLeft(arr, size, target);
    // expected : 3
}

void test_checkLeft2()
{
    int arr[] = {1, 4, 5, 9, 9, 9, 12, 16, 24, 36, 42};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 45;

    int index = checkLeft(arr, size, target);
    // expected : -1
}

void test_checkRight1()
{
    int arr[] = {1, 5, 7, 8, 8, 8, 8, 8, 8, 8, 10, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int index = checkRight(arr, size, target);
    // expected : 9
}

void test_checkRight2()
{
    int arr[] = {1, 5, 7, 8, 8, 8, 8, 8, 8, 8, 10, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    int index = checkRight(arr, size, target);
    // expected : -1
}

int main()
{
    test_InsertNoDup();

    test_InsertWithDup();

    test_checkLeft1();
    test_checkLeft2();
    
    test_checkRight1();
    test_checkRight2();

    return 0;
}