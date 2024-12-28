/*
Building...
2. Logarithmic O(log n)
5. Exponential O(2^n)
*/



# include <stdio.h>
# include <stdlib.h>

/*
Input space  =>   Temporary space   =>  Output space
              |    temporary data   |
              |   stack frame space |
              |   instruction space |


Temporary data:     used to save [constants], [variables], [objects]
Stack frame space： used to save [the context data of called function]
Instruction space:  used to store [complied program instructions] (negligible)
*/
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

int func()
{   
 // Perform certain operations...
    return 0;
}

int space_algorithms(int input)    // Input data
{
const int a = 0;      // Temporary data(constants)
int b = 7;            // Temporary data(variables)
int c = func();       // Stack frame space(call function)

return a + b + c;     // Output data
}


/* We usually focus on [worst-case] space complexity*/
/* 
   NOTE: memory occupied by initializing variables or calling functions in a loop,
         which is released upon entering the next cycle, does not accumulate over space, 
         thus the space complexity is O(1).
*/

/*
Common Time Complexities in Ascending Order:

O(1) < O(log n) < O(n) < O(n^2) < O(2^n)

Constant            O(1)
Logarithmic         O(log n)
Linear              O(n)
Quadratic           O(n^2)
Exponential         O(2^n)
*/

/*
1. Constant O(1):
The space complexity is constant, regardless of the input size n.
NOTE: memory occupied by initializing variables or calling functions in a loop,
      which is released upon entering the next cycle, does not accumulate over space, 
      thus the space complexity is O(1).
*/

void constant(int n)
{   
    const int a = 7;                 // Constant 
    int b = 9;                       // Variable
    int nums [648];                  // Array with fixed size

    for (int i = 0; i < n; i++)
    {
        int c = 100;
        func();
    }
}

// 2. Logarithmic O(log n)

// 3. Linear O(n)
void linear(int n)
{   /* An array of length n occupies O(n) space */
    int* nums =  malloc(sizeof(int) * n);  
    free(nums);
    
    /* A linked list of length n occupies O(n) space */
    ListNode **nodes = malloc(sizeof(ListNode *) * n);
    // Initialize n nodes
    for(int i = 0; i < n; i++)
    {
        nodes[i] = malloc(sizeof(ListNode));
    }
    // Free memory
    for(int i = 0; i < n; i++)
    {
        free(nodes[i]);
    }
    free(nodes);

}

// Recursive depth is n, meaning there are n instances of unreturned functions, 
// using O(n) size of stack frame space.
void linearRecur(int n)
{
    if (n == 0)
        return;
    linearRecur(n - 1);
}

// 4. Quadratic O(n^2)

void quadratic(int n)
{   // A 2D array occupies O(n^2) space
    int **matrix = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        int *tmp = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            *(tmp + j) = j;
        }
        *(matrix + i) = tmp;
    }
    
    // Free memory
    for (int i = 0; i < n; i++)
    {
        free(*(matrix + i));
    }
    free(matrix); 
}

int quadratic_recur(int n)
{
    if (n <= 0)
        return 0;

    int *nums = malloc(sizeof(int) * n);
    printf("Recursion length = %d, length of 'nums' = %d \r\n", n, n );
    int res = quadratic_recur(n - 1);
    free(nums);

    return res;
}

// 5. Exponential O(2^n)






int main()
{
    quadratic_recur(7);
    return 0;
}