# include <stdio.h>
# include <stdlib.h>

int calculateMid(int start, int end)
{
    return start + (end - start) / 2;
}

/* Case 1: no duplicates
Two possibilities:
1. target value has not existed.
2. target value has existed.
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
        else // arr[mid] >= value   // [start, mid - 1] ← || [mid]
        {
            end = mid - 1;
        }
    }
    return start;
}

void insertNum(int* arr, int size, int value)
{
    int index = insertNoDup(arr, size, value);
    for(int i = size - 1 ; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
}