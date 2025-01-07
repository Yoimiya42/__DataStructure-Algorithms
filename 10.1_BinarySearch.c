
# include <stdio.h>
# include <stdlib.h>
/*
Binary Search:

Pros:
1. Time-efficient
2. Space-efficient

Cons:
Must be [1.sorted] [2.no duplicates] [3. array]

*/

/*
Double Closed Interval: 

start       = 0
end         = n-1
mid-point   = start + (end - start) / 2

[i, mid - 1] [mid] [mid + 1, j]
Iteration：condition: i <= j
Terminal condition: i > j
*/

int calculateMid(int start, int end)
{
    return start + (end - start) / 2;
}

// -------------------- Double Closed Interval  ----------------------
/*Interation:
Time Complexity:  O(log n)
Space Complexity: O(1)    Pointers i and j occupies constant size of space
*/
int binarySearchIter(int* arr, int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = 0;

    while(start <= end)
    {
        mid = calculateMid(start, end);
        if(arr[mid] > target)          // =>  [start, mid - 1] ← || [mid]
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)    // =>  [mid] || → [mid + 1, end]
        {
            start = mid + 1;
        }
        else // arr[mid] == target                           
        {
            return mid;
        }
    }

    return -1;                        // Not found
}

/*
Recursion:
Time Complexity：  O(log n)
Space Complexity:  O(log n)   Generate (log n) stack frames
*/

int BinarySearchRecur(int* arr, int start, int end, int target)
{
    if(start > end)           // Terminal Condition
    {
        return -1;
    }

    int mid = calculateMid(start, end);

    if (arr[mid] < target)    // [mid] || → [mid + 1, end]
    {   
        return BinarySearchRecur(arr, mid + 1, end, target);
    }
    else if (arr[mid] > target)    // [start, mid - 1] ← || [mid]
    {
        return BinarySearchRecur(arr, start, mid -1, target);
    }
    else  // arr[mid] == target
    {
        return mid;
    }
}


// ---------------- Left-Closed Right-Open Interval -------------------

// int binarySearchIter2(int* arr, int size, int target)
// {
//     int start = 0;
//     int end = size;
//     int mid = 0;

//     while(start < end)
// }