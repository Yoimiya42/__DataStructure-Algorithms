
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

# define MAX_SIZE 10
// --------------------- D E F I N E S ---------------------

typedef struct Deque{
    int* arr;
    int front;
    int size;
    int capacity;
}Deque;

Deque* initDeque();

void pushFront(Deque* deque, int value);
void pushRear(Deque* deque, int value);

void popFront(Deque* deque);
void popRear(Deque* deque);

int peekFront(Deque* deque);
int peekRear(Deque* deque);

int* displayDeque(Deque* deque);

void clearMemory(Deque* deque);

// ----------------- I M P L E M E N T A T I O N S ----------------- 
Deque* initDeque()
{
    Deque* deque = malloc(sizeof(Deque));
    deque->front = deque->size = 0;
    deque->capacity = MAX_SIZE;
    deque->arr = malloc(sizeof(int) * deque->capacity);

    return deque;
}


// 1. push
void pushFront(Deque* deque, int value)
{
    if(deque->size == deque->capacity)
    {
        printf("Doubly queue has been full.");
        return;
    }

    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    deque->arr[deque->front] = value;
    deque->size++;
}

void pushRear(Deque* deque, int value)
{
    if(deque->size == deque->capacity)
    {
        printf("Doubly queue has been full.");
        return;
    }

    int rear = (deque->front + deque->size) % deque->capacity;
    deque->arr[rear] = value;
    deque->size++;
}


// 2. pop
void popFront(Deque* deque)
{   
    if(deque->size == 0)
    {
        printf("Empty Doubly Queue.");
        return;
    }

    deque->size--;
    deque->front = (++deque->front) % deque->capacity;
}

void popRear(Deque* deque)
{   
    if(deque->size == 0)
    {
        printf("Empty Doubly Queue.");
        return;
    }

    deque->size--;
}


// 3. peek

int peekFront(Deque* deque)
{
    if(deque->size == 0)
    {
        printf("Empty Doubly Queue.");
        return -1;
    }

    return deque->arr[deque->front];
}

int peekRear(Deque* deque)
{
    if(deque->size == 0)
    {
        printf("Empty Doubly Queue.");
        return -1;
    }

    int rear = (deque->front + deque->size - 1) % deque->capacity;
    return deque->arr[rear];
}
// 4. display
int* displayDeque(Deque* deque)
{
    int* newArr = malloc(sizeof(int) * deque->size);

    for(int i = 0; i < deque->size; i++)
    {
        newArr[i] = deque->arr[(deque->front + i) % deque->capacity];
    }

    return newArr;
}

// 5. clearMemory

void clearMemory(Deque* deque)
{
    free(deque->arr);
    free(deque);
}

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
                pushFront(deque, pushValue);
                break;
            }
            case 2:
            {
                int pushValue;
                scanf("%d", &pushValue);
                pushRear(deque, pushValue);
                break;
            }
            case 3:
            {
                popFront(deque);
                break;
            }
            case 4:
            {
                popRear(deque);
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
                int* arr = displayDeque(deque);
                for(int i = 0; i < deque->size; i++)
                {
                    printf("Deque%d= %2d\n", i, arr[i]);
                }
                free(arr);
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
// ------------------------- T  E  S  T  ---------------------------


int main()
{
    Deque* deque = initDeque();
    testDeque(deque);
    return 0;
}
