#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fundamental Program Control Structures: Interation and Recursion
// 1. Interation

int for_loop(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
         sum += i;
    }

    return sum;
}

int while_loop(int n)
{
    int sum = 0;
    int acc = 1;
    while(acc <= n)
    {
        sum += acc;
        acc ++; 
    }

    return sum;
}

int do_while_loop(int n)
{
    int sum = 0;
    int acc = 1;
    do{
        sum += acc;
        acc++;
    }while(acc <= n);
    
    return sum;
}

char* nested_loop(int n)
{
    int size = n * n * 26 + 1;
    char *res = malloc(size * sizeof(char));
    //*res = '\0';  // initialize the memory block with null character
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {   
            char tmp[26];
            snprintf(tmp, sizeof(tmp),"(%d, %d), ", i, j);
            //snprintf(): write formatted output to sized buffer
            strncat(res, tmp, size - strlen(res) - 1);
            //strncat():  append 'tmp' to 'res',  and limit the the size of string concatenated.
        }
    }

    return res;
}

/*
 2. Recursion
 Involves two phases: calling and returning.
 Calling:   When a function is called, system allocates a *stack frame*  to store the function's local variables,
            parameters, and return address.
 Returning: When a function completes its execution and returns, the corresponding stack frame is removed from the 'call stack'.
            The environment is restored to previous state.
*/
int regular_recursion(int n)
{// The summation occurs in the returning phase.
    if (n == 1)
        return n;
    int res = regular_recursion(n - 1);

    return n + res;
}

int tail_recursion(int n, int res)
{// The summation occurs in the calling phase.
    if (n == 0)
        return res;
        
    return tail_recursion(n - 1, res + n );
}

int tree_recursion(int n)
{
    if (n == 1 | n == 2)
        return n - 1; 

    int res = tree_recursion(n - 1) + tree_recursion(n - 2);

    return res;
}

/*
3.Complexity for Interation and Recursion(For Summation):
               Interation      |     Recursion
TimeComplx:     O(n)           |        O(n)
SpaceComplx:    O(1)           |        O(n)

Interation is more efficient.
Recursion is more readable and concise.
*/

int main()
{   
    printf("ForLoop: %d\n", for_loop(10));
    printf("WhileLoop: %d\n", while_loop(10));
    printf("DoWhileLoop: %d\n", do_while_loop(10)); 
    printf("NestedLoop: %s\n", nested_loop(10));

    return 0;
}