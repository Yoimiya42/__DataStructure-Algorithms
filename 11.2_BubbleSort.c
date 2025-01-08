# include <stdio.h>
# include <stdlib.h>

/*
Bubble Sort:

Outer Loop:  n - 1 rounds
Inner Loop:
Unsorted nums: n -> n - 1 -> n - 2 -> ... -> 2 -> 1
Comparisons:   n - 1 -> n - 2 -> n - 3 -> ... -> 1 -> 0 times

T(n) = ((n - 1) + 1) * (n - 1) / 2 = n(n - 1) / 2

Time Complexity:  O(n^2)     adaptive sort
Space Complexity: O(1)       in-place sort

Efficiency Optimization:
If the inner loop does not perform any swaps, the array is already in order.
We can use a flag to monitor this and break the loop early.
*/


// Swap function
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ------------------  Bubble Sort - Ascending ----------------------

void bubbleAscending(int arr[], int size)
{
    for(int surface = size - 1; surface > 0; surface--)
    {   
        int swapped = 0;  // flag for optimizing efficiency
        for(int water = 0; water < surface; water++)
        {   
            // left > right    => exchange
            if(arr[water] > arr[water + 1])
            {
                swap(&arr[water], &arr[water + 1]);
                swapped = 1;
            }
        }

        if(swapped == 0) // never perform the swap in this loop
            break;       // the array has been inorder, quit loop
    }
}


// ------------------  Bubble Sort - Descending ----------------------
void bubbleDescending(int* arr, int size)
{
    for(int i = size - 1; i > 0; i--)
    {   
        int swapped = 0;

        for(int j = 0; j < i; j++)
        {   
            // left < right  => exchange 
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}


// --------------------------- Test -------------------------
int main()
{   
    int arr[] = {42,37,77,99,67,14,9,32,64};
    int size = sizeof(arr) / sizeof(arr[0]);
    

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}