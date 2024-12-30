
/*
Stack implemented based on array.

Pros:
    1. Good cache locality due to pre-allocated continuous memory.
    2. More efficient due to easy operations.
    
Cons: fixed size
    1. Predefined size may lead to memory waste
    2. Inefficient in expanding capacity.
*/

// ---------------- D    E    F    I    N    E ------------------------
Stack* initStack();

void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);

void traverseStack(Stack* stack);
void clearStack(Stack* stack);
// --------------------------------------------------------------------

# include <stdio.h>
# include <stdlib.h>
# define MAX_SIZE 64

typedef struct Stack{
    int* arr;
    int top;

}Stack;

Stack* initStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack)
    {
        printf("Empty stack");
        exit(1);
    }
    
    stack->arr = malloc(sizeof(int) * MAX_SIZE);
    stack->top = -1;
    
    return stack;
}

// 1. Onto the stack ----------------------------------------------------------------
void push(Stack* stack, int value)
{   
    if (stack->top == MAX_SIZE -1)
    {
        printf("Stack has been empty.");
        return;
    }

    stack->arr[++stack->top] = value;
}

// 2. Pop from stack ----------------------------------------------------------------
int pop(Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Empty Stack.");
        return -1;
    }
    
    int pop_num = stack->arr[stack->top--];
    return pop_num;
}

// 3. Peek the top value ------------------------------------------------------------
int peek(Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Empty Stack.");
        return -1;
    }

    return stack->arr[stack->top];
}

// 4. Browse through the whole stack
void traverseStack(Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Empty Stack.");
        return;
    }

    for(int i = stack->top; i >= 0; i--)
    {
        printf("Layer%d= %2d\n", i, stack->arr[i]);
    }
}

// 5. Clear the stack and cease
void clearStack(Stack* stack)
{
    free(stack->arr);
    free(stack);
}

void testStack(Stack* stack)
{
    printf("Choose your operations: \n");
    printf(" 1 ->push\n");
    printf(" 2 ->pop\n");

    printf(" 3 ->peek\n");
    printf(" 4 ->check the whole stack\n");

    printf(" 5 ->clear the stack and cease\n");

    int choice;
    do{
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int pushValue;
                scanf("%d", &pushValue);
                push(stack, pushValue);
                break;
            }
            case 2:
            {
                pop(stack);
                break;
            }
            case 3:
            {
                int topValue = peek(stack);
                printf("The top value is: %d\n", topValue);
                break;
            }
            case 4:
            {
                traverseStack(stack);
                break;
            }
            case 5:
            {
                clearStack(stack);
                break;
            }

        }
    }while(choice != 5);
}


int main()
{
    Stack* stack = initStack();
    testStack(stack);

    return 0;
}