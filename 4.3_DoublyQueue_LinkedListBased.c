
# include <stdio.h>
# include <stdlib.h>
// ------------------ D  E  F  I  N  E ------------------------
typedef struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct Deque{
    Node* front;
    Node* rear;
}Deque;

Node* createNode(int value);
Deque* initDeque();

void push(Deque* deque, int value, int isFront);
void pushFront(Deque* deque, int value, int isFront);
void pushRear(Deque* deque, int value, int isFront);

void pop(Deque* deque, int isFront);
void popFront(Deque* deque, int isFront);
void popRear(Deque* deque, int isFront);

int peekFront(Deque* deque);
int peekRear(Deque* deque);

void traverseDeque(Deque* deque);

void clearMemory(Deque* deque);

// ------------------ I  M P  L  E  M  E  N  T  A  T  I  O  N  ------------------------
Node* createNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed.");
        exit(1);
    }

    newNode->val = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Deque* initDeque()
{
    Deque* deque = malloc(sizeof(Deque));
    if(!deque)
    {
        printf("Memory allocation failed.");
        exit(1);
    }

    deque->front = NULL;
    deque->rear = NULL;

    return deque;
}

// 1. Push at the front/rear ----------------------------------------------------- 
void push(Deque* deque, int value, int isFront)
{   
    Node* newNode = createNode(value);
    if (deque->front == NULL) // If the deque is empty.
    {
        deque->front = deque->rear = newNode; 
        return;
    }

    if(isFront)  // push at the front
    {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    else{        // push at the rear
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

void pushFront(Deque* deque, int value, int isFront)
{
    push(deque, value, 1);
}

void pushRear(Deque* deque, int value, int isFront)
{
    push(deque, value, 0);
}

// 2. Pop from the front/rear -----------------------------------------------------
void pop(Deque* deque, int isFront)
{
    if (deque->front == NULL) // If the deque is empty.
    {
        printf("Empty Doubly Queue.");
    }

    if (deque->front->next == NULL) // If the deque only has one node.
    {
        free(deque->front);
        deque->front = deque->rear = NULL;
        return;
    }

    if (isFront) // pop from the front
    {
        Node* temp = deque->front;
        deque->front = temp->next;
        deque->front->prev = NULL;
        free(temp); 
    }else{     // pop from the rear
        Node* temp = deque->rear;
        deque->rear = temp->prev;
        deque->rear->next = NULL;
        free(temp);
    }
}

void popFront(Deque* deque, int isFront)
{
    pop(deque, 1);
}

void popRear(Deque* deque, int isFront)
{
    pop(deque, 0);
}

// 3. Peek the front/rear -----------------------------------------------------
int peekFront(Deque* deque)
{
    if (deque->front == NULL)
    {
        printf("Empty Doubly Queue.");
        return -1;
    }

    return deque->front->val;
}

int peekRear(Deque* deque)
{
    if (deque->front == NULL)
    {
    printf("Empty Doubly Queue.");
    }

    return deque->rear->val;
}


// 4. traverse/print deque -----------------------------------------------------
void traverseDeque(Deque* deque)
{
    if (deque->front == NULL)
    {
        printf("Empty Doubly Queue.");
        return;
    }
    
    Node* current = deque->front;
    int index = 0;
    while(current)
    {
        printf("Queue%d= %2d\n", index, current->val);
        index++;
        current = current->next;
    }
}

// 5. clearMemory --------------------------------------------------------------
void clearMemory(Deque* deque)
{
    while(deque->front)
    {
        Node* temp = deque->front;
        deque->front = temp->next;
        free(temp);
    }
    free(deque);
}


// ------------------ T  E  S  T  ------------------------
void testDeque(Deque* deque)
{
    printf("Choose your operations: \n");
    printf(" 1 ->pushFront\n");
    printf(" 2 ->pushRear\n");

    printf(" 3 ->popFront\n");
    printf(" 4 ->popRear\n");

    printf(" 5 ->peekFront\n");
    printf(" 6 ->peekRear\n");

    printf(" 7 ->check the whole deque\n");
    printf(" 8 ->clear the deque and cease\n");

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
                pushFront(deque, pushValue, 1);
                break;
            }
            case 2:
            {
                int pushValue;
                scanf("%d", &pushValue);
                pushRear(deque, pushValue, 0);
                break;
            }
            case 3:
            {
                popFront(deque, 1);
                break;
            }
            case 4:
            {
                popRear(deque, 0);
                break;
            }
            case 5:
            {
                int frontValue = peekFront(deque);
                printf("The front value is: %d\n", frontValue);
                break;
            }
            case 6:
            {
                int rearValue = peekRear(deque);
                printf("The rear value is: %d\n", rearValue);
                break;
            }
            case 7:
            {
                traverseDeque(deque);
                break;
            }
            case 8:
            {
                clearMemory(deque);
                break;
            }
        }
    }while(choice != 8);
}


int main()
{
    Deque* deque = initDeque();
    testDeque(deque);
}