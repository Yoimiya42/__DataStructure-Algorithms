# include <stdio.h>
# include <stdlib.h>

/*
Selection Sort:

Outer Loop:  n - 1 rounds
Inner Loop:  
Unsorted nums: n -> n - 1 -> n - 2 -> ... -> 2 -> 1     
Comparisons:   n - 1 -> n - 2 -> n - 3 -> ... -> 1 -> 0 times

T(n) = ((n - 1) + 1) * (n - 1) / 2 = n(n - 1) / 2

Time Complexity:  O(n^2)     non-adaptive sort
Space Complexity: O(1)       in-place sort

Ascending:  Find the *minimum* number in the unsorted interval
*/
// ----------- Selection Sort - Ascending ----------------------
void selectionAscending(int arr[], int size)
{
    for(int outer = 0; outer < size - 1; outer++)
    {   
        int minIndex = outer;

        for(int inner = outer + 1; inner < size; inner++)
        {  // Find the minimum value in the unsorted interval
            if (arr[inner] < arr[minIndex])
            {
                minIndex = inner;
            }
        }
        // swich the min with the first element of the unsorted interval
        int temp = arr[outer];
        arr[outer] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// ----------- Selection Sort - Descending ----------------------
void selectionDescending(int arr[], int size)
{
    for(int outer = 0; outer < size - 1; outer++)
    {
        int maxIndex = outer;

        for(int inner = outer + 1; inner < size; inner++)
        {
            if (arr[inner] > arr[maxIndex])
            {
                maxIndex = inner;
            }
        }
        
        int temp = arr[outer];
        arr[outer] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}


// ---------------------- Test ----------------------
int main ()
{   
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    selectionDescending(arr, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}