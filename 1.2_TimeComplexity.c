/* Building...
4. Linear_logarithmic

*/


#include <stdio.h>
#include <math.h>
/*
Time Complexity : Time Growth Trend vs. Input Size
Given a function that represents the number of operations of an algorithm as a function
of the input size n, donated as T(n); 
The time complexity is determined by the highest order term in T(n):
T(n) = 7n + 2                  => O(n)
T(n) = 3(n^4) + 2(n^2) +n      => O(n^4)
T(n) = 2^n + 3n^2 + 4          => O(2^n)

Common Time Complexities in Ascending Order:

O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n) < O(n!)

Constant            O(1)
Logarithmic         O(log n)
Linear              O(n)
Linear-logarithmic  O(n log n)
Quadratic           O(n^2)
Exponential         O(2^n)
Factorial           O(n!)
*/

// 1. Constant O(1):
// The number of operations is constant, regardless of the input size n.
void constant(int n)
{   
    int size = 10000;
    for (int i = 1; i <= size; i++)
    {
        printf("i = %d\n", i);
    }
}
//  input size n does not affect the number of operations.

// 2. Logarithmic O(log n):
// The number of operations grows logarithmically with input size n.
// *Binary search*
int logarithmic(int total)
{   
    int op_nums = 0;

    while (total > 1)
    {
        total /= 2;
        op_nums++;
    }
    
    return op_nums;
}


// 3. Linear O(n):
// The number of operations grows linearly with input size n.
// Single-loop structure like *Traverse an array & linked list*
void linear(char* str)
{
    for (char* p = str; *p; p++)
    {
        printf("%c\n", *p);
    }
}

// 4. Linear_logarithmic  O(n log n):
// *Merge sort*, *Quick sort*
int LinearLogarithmic(int n)
{
    if (n <= 1)
        return 1;
    int count = LinearLogarithmic(n / 2) + LinearLogarithmic(n / 2);

    for (int i = 0; i < n; i++) 
    {
        count++;
    }

    return count;
}

// 5.Quadratic O(n^2):
// The number of operations grows quadratically with inout size n.
// Nested-loop structure like *Traverse a 2D array*, *bubble sort*
void quadratic(int* arr, int r, int c)
{
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
            printf("arr[%d][%d] = %d\n", row, col, *(arr + row * c + col));
    }
}

void bubbleSort(int *num, int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(*(num+j) > *(num + j + 1))
            {
                int tmp = *(num + j);
                *(num + j) = *(num + j + 1);
                *(num + j + 1) = tmp;
            }
        }
    }
}

// 6. Exponential O(2^n):
// The number of operations grows exponentially with input size n.
// *Cell division*

int exponential(int n)
{
    int cell_nums = 0;
    int bis = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bis; j++)
        {
            cell_nums++;
        }
        bis*= 2;
    }

    return cell_nums;
}

int exponential_rec(int n)
{
    int cell_init = 1;
    if (n == 0)
        return cell_init;

    return pow(2, n) + exponential_rec(n - 1);
}

// 7. Factorial O(n!):
// *full permutation*

int fullPermutation(int n)
{// n! = n * (n-1) * (n-2) * ... * 1
    int op_nums = 1;
    if (n == 1)
        return op_nums;

    return n * fullPermutation(n - 1);
}




int main()
{
    printf("Cell nums= %d\n", exponential_rec(3));
    printf("Operation times = %d\n", logarithmic(100));
    printf("The factorial of 5 is %d\n", fullPermutation(5));
    return 0;
}