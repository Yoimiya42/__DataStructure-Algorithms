
/*
Linked List implemented using C with head pointer only.
*/


// ----------------------------------------------- D E F I N E ------------------------------------------
ListNode* initNode(int value);
void appendAtHead(ListNode* newNode);
void appendAtTail(ListNode* newNode);
void deleteAtHead();
void deleteAtTail();
void traverseLinkedList();
void createLinkedList();
void clearMemory();

// -----------------------------------------------------------------------------------------------------
# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* head = NULL;


// Initialization
ListNode* initNode(int value)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode*));
    
    if(!newNode)
    {
        printf("Memory allocate failed.");
        exit(1);
    }

    newNode->val = value;
    newNode->next = NULL;
    
    return newNode;
}

// Append
void appendAtHead(ListNode* newNode)
{   
    newNode->next = head;
    head = newNode;
}

void appendAtTail(ListNode* newNode)
{
    if(head == NULL)
    {
        appendAtHead(newNode);
        return;
    }

    ListNode* current = head;
    while(current->next)
    {
        current = current->next;
    }

    current->next = newNode;
}

// Delete
void deleteAtHead()
{
    if(head == NULL)
        return;
    
    ListNode* current = head;
    head = current->next;

    free(current);
    current = NULL;
}

void deleteAtTail()
{
    if(head == NULL)

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    ListNode* current = head;
    while(current->next->next)
    {   
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Traverse
void traverseLinkedList()
{
    if (head == NULL)
    {
        printf("Empty Linked List.");
        return;
    }
    
    ListNode* current = head;
    int index = 0;
    while(current)
    {
        printf("Node%d= %2d\n", index, current->val);
        index++;

        current = current->next;
    }
}

// Create
void createLinkedList()
{
    int num_nodes;
    int validation;
    do{  
        printf("Please enter the number of nodes to create(0<= Integer <=100):");
        validation = scanf("%d", &num_nodes);
    }while(validation!=1 || num_nodes < 0 || num_nodes > 100);

    for (int i =0; i < num_nodes; i++)
    {
        int value;
        do{ 
            printf("Please enter the value of node%d:", i);
            validation = scanf("%d:", &value);
        }while(validation != 1);

        ListNode* newNode = initNode(value);
        appendAtTail(newNode);
    }

    printf("Created Successfully. Your Linked List is:\n");
}

void clearMemory()
{
    ListNode* current = head;
    while(current)
    {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main()
{   
    createLinkedList();
    traverseLinkedList();

    deleteAtHead();
    deleteAtTail();

    printf("\n\n");
    traverseLinkedList();

    return 0;
}