/*
Queue implemented based on Linked List.
*/

// ---------- D    E    F    I    N    E ------------------------

# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node* next;
}Node;

typedef struct Queue{
    struct Node* front;
    struct Node* rear;
}Queue;

void enqueue(Queue* queue, int value);
void dequeue(Queue* queue);

int peekFront(Queue* queue);
int peekRear(Queue* queue);

void traverseQueue(Queue* queue);

void clearMemory(Queue* queue);

// ------------------ I  M P  L  E  M  E  N  T  A  T  I  O  N  ------------------------
Node* createNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocate failed.");
        exit(1);
    }

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

Queue* initQueue()
{
    Queue* queue = malloc(sizeof(Queue));
    if(!queue)
    {
        printf("Memory allocate failed.");
        exit(1);
    }

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

// 1. enqueue(push) ------------------------------------------------------------
void enqueue(Queue* queue, int value)
{
    Node* newNode = createNode(value);

    if(queue->front == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// 2. dequeue(pop) -------------------------------------------------------------
void dequeue(Queue* queue)
{ 
    if (queue->front == NULL)      // If the queue is empty.
    {
        printf("Empty Queue.");
        return;
    }

    if (queue->front->next == NULL)  //If the queue only has one node
    {
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    }

    Node* temp = queue->front;
    queue->front = temp->next;
    free(temp);
    temp = NULL;
}

// 3. peek  ---------------------------------------------------------------------
int peekFront(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Empty Queue");
        return -1;
    }

    return queue->front->val;
}

int peekRear(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Empty Queue");
        return -1;
    }

    return queue->rear->val;
}

// 4. traverse/print queue -----------------------------------------------------

void traverseQueue(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Empty Queue");
        return;
    }

    Node* current = queue->front;
    int index = 0;
    while(current)
    {   
        printf("Queue%d= %2d\n", index, current->val);
        current = current->next;
        index++;
    }
}

// 5. clearMemory --------------------------------------------------------------

void clearMemory(Queue* queue)
{
    while(queue->front)
    {
        Node* temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }

    free(queue);
}

// ------------------ T  E  S  T  ------------------------
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