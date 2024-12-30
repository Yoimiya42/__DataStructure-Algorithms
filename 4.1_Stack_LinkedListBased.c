
/*
Stack implemented based on linked list.

Pros:
    1. Flexible size, no need to specify the size in advance.
Cons:
    1. Inefficient in memory allocation for new nodes and changing the pointers.
    2. More space occupied duo to extra space for linked list nodes pointers.
    
*/

// ---------- D    E    F    I    N    E ------------------------

# include <stdlib.h>
# include <stdio.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

void push(Stack* stack, int value);
void pop(Stack* stack);
int peek(Stack* stack);

void traverseStack(Stack* stack);
void clearStack(Stack* stack);

// ------------------ I  M P  L  E  M  E  N  T  A  T  I  O  N  ------------------------
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocate failed.");
        exit(1);
    }
    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

Stack* initStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack)
    {
        printf("Memory allocate failed.");
        exit(1);
    }

    stack->top = NULL;

    return stack;
}


// 1.Onto the stack ----------------------------------------------------------------
void push(Stack* stack, int value)   
{
    Node* node = createNode(value);
    
    if(stack->top == NULL)
    {
        stack->top = node;
        return;
    }

    node->next = stack->top;
    stack->top = node;
}

// 2.Pop from stack ----------------------------------------------------------------
void pop(Stack* stack)
{
    if(stack->top == NULL)
    {
        printf("Empty Stack.");
        return;
    }
    
    Node* current = stack->top;
    stack->top = current->next;

    free(current);
}

// 3.Peek the top -------------------------------------------------------------------
int peek(Stack* stack)
{
    if(stack->top == NULL)
    {
        printf("Empty Stack.");
        return -1;
    }

    return stack->top->val;
}

// 4. Browse through the stack -----------------------------------------------------
void traverseStack(Stack* stack)
{
    if(stack->top == NULL)
    {
        printf("Empty Stack.");
        return;
    }

    Node* current = stack->top;
    int index = 0;
    while(current)
    {
        printf("Layer %d: %d\n", index, current->val);
        current = current->next;
        index++;
    }
    printf("\n");
}

// 5. Clear the stack ----------------------------------------------------------------
void clearStack(Stack* stack)
{
    while(stack->top)
    {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
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