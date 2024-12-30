# include <stdio.h>
# include <stdlib.h>

# define MAX_SIZE 10

// -------------------- D  E  F  I  N  E ------------------------
typedef struct Queue{
    int* arr;
    int front;
    int size;
    int capacity;
}Queue;

Queue* initQueue();

void enqueue(Queue* queue, int value);
void dequeue(Queue* queue);

int peekFront(Queue* queue);
int peekRear(Queue* queue);

void traverseQueue(Queue* queue);

void clearMemory(Queue* queue);

// ------------------ I  M P  L  E  M  E  N  T  A  T  I  O  N  ------------------------
Queue* initQueue()
{
    Queue* queue = malloc(sizeof(Queue));
    if(!queue)
    {
        printf("Memory allocation failed.");
        exit(1);
    }

    queue->capacity = MAX_SIZE;
    queue->front = 0;
    queue->size = 0;

    queue->arr = malloc(sizeof(int) * queue->capacity);

    return queue;
}

/*
Delete the first element of an array can be inefficient, with a time complexity of O(n).

We use a variable 'front' to indicate the index of the front element, 
and maintain a variable 'size' to record the queue's length.
For the rear element, we define 'rear = front + size' to points to the position immediately following the tail element.

- Enqueue:
    size++;
- Dequeue:
    we only 'front++' to stop tracking the first element, 
    and 'size--' to update the queue's valid length.

To prevent 'front' from approaching the end index while the left side of array is still empty due to dequeue operations,
we can treat the array as a circular array where connecting the end of the array back to its beginning.
*/

// 1. Enqueue -------------------------------------------------------------------
void enqueue(Queue* queue, int value)
{   
    if (queue->size == queue->capacity)
    {
        printf("Queue has been full.");
        return;
    }

    int rear = (queue->front + queue->size) % queue->capacity;
    queue->arr[rear] = value;
    queue->size++;
}
// 2. Dequeue  -------------------------------------------------------------------

void dequeue(Queue* queue)
{
    if (queue->size == 0)
    {
        printf("Empty Queue");
        return;
    }
    
    queue->front= (++queue->front) % queue->capacity;
    queue->size--;
}

// 3. Peek ----------------------------------------------------------------
int peekFront(Queue* queue)
{
    if (queue->size == 0)
    {
        printf("Empty Queue");
        return -1;
    }

    return *((queue->arr) + (queue->front));
}

int peekRear(Queue* queue)
{
    if (queue->size == 0)
    {
        printf("Empty Queue");
        return -1;
    }
    int rear = (queue->front + queue->size -1) % queue->capacity;
    return queue->arr[rear];
}

// 4. traverse/print queue -----------------------------------------------------
void traverseQueue(Queue* queue)
{   
    if (queue->size == 0)
    {
        printf("Empty Queue");
        return;
    }

    for(int i = 0; i < queue->size; i++)
    {   
        int current = (queue->front + i) % queue->capacity;
        printf("Queue%d(addr%d) = %d\n", i, current, queue->arr[current]);
    }
}

// 5. clearMemory
void clearMemory(Queue* queue)
{
    free(queue->arr);
    free(queue);
}

// ------------------ T  E  S  T ------------------------
void testQueue(Queue* queue)
{
    printf("Choose your operations: \n");
    printf(" 1 ->enqueue\n");
    printf(" 2 ->dequeue\n");

    printf(" 3 ->peekFront\n");
    printf(" 4 ->peekRear\n");

    printf(" 5 ->check the whole queue\n");
    printf(" 6 ->clear the queue and cease\n");

    int choice;
    do{
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int enqueueValue;
                scanf("%d", &enqueueValue);
                enqueue(queue, enqueueValue);
                break;
            }
            case 2:
            {
                dequeue(queue);
                break;
            }
            case 3:
            {
                int frontValue = peekFront(queue);
                printf("The front value is: %d\n", frontValue);
                break;
            }
            case 4:
            {
                int rearValue = peekRear(queue);
                printf("The rear value is: %d\n", rearValue);
                break;
            }
            case 5:
            {
                traverseQueue(queue);
                break;
            }
            case 6:
            {
                clearMemory(queue);
                break;
            }
        }
    }while(choice != 6);
}

int main()
{
    Queue* queue = initQueue();
    testQueue(queue);
    return 0;
}