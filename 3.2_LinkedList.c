# include <stdio.h>
# include <stdlib.h>
# define __ printf("\n");
//----------------------------------------------- D E F I N E ------------------------------------------
ListNode* initNode(int val);

void appendAtHead(ListNode** head, ListNode** tail, int value);
void appendAtTail(ListNode** head, ListNode** tail, int value);
void createLinkedList(ListNode** head, ListNode** tail, int num_nodes);

void insertNode(ListNode* head, int targetIndex, int value);

void deleteAtHead(ListNode** head, ListNode** tail);
void deleteAtTail(ListNode** head, ListNode** tail);
void deleteNode(ListNode** head, ListNode** tail, int targetValue);

void traverseLinkedList(ListNode* head);

int findNode(ListNode* head, int target);

/* 1. Initialization --------------------------------------------------------------------------------
Values of a node + a pointer pointing to another node
*/

typedef struct ListNode
{
    int val;
    struct ListNode* next;  // Pointer to another ListNode(struct)
}ListNode;


// Constructor
ListNode* initNode(int val)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    if (!node)  
    {
        printf("Memory allocate failed.\n");
        exit(1);
    }

    node->val = val;
    node->next = NULL;

    return node;
}


/* 2. Append nodes -----------------------------------------------------------------------------------
To modify the value a pointer points to, the parameter passed should be this pointer.
If we want to change which value is pointed by a pointer, we should pass function [a pointer to this pointer].

If we have both head and tail pointers, new-node is appended at the head or tail:
Time complexity:  O(1)
Space complexity: O(1)

If we only have head pointer, new-node is appended at the tail:
Time complexity:  O(n) (the worst case which need to traverse the whole linked list)
Space complexity: O(1)

If we insert new-node at a specific position(the middle of the linked list):
Time complexity:  O(n) (traverse to the specific position)
Space complexity: O(1)
*/
void appendAtHead(ListNode** head, ListNode** tail, int value)
{
    ListNode* newNode = initNode(value);
    newNode->next = *head;
    *head = newNode;

    if(*tail == NULL)   // If the linked list was empty before.
    {
        *tail = newNode;
    }
}

void appendAtTail(ListNode** head, ListNode** tail, int value)
{
    ListNode* newNode = initNode(value);

    if (*head == NULL) // If the linked list was empty before.
    {
        *head = newNode;
        *tail = newNode;
        return;
    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}


void createLinkedList(ListNode** head, ListNode** tail, int num_nodes)
{
    for (int i = 0; i < num_nodes; i++)
    {
        appendAtTail(head, tail, i + 1);
    }
}

void insertNode(ListNode* head, int targetIndex, int value)
{
    ListNode* current = head;
    int index = 0;
    while(current)
    {
       if (index == targetIndex)
       {
        ListNode* newNode = initNode(value);
        newNode->next = current->next;
        current->next = newNode;

        return;
       }

       index++;
       current = current->next;
    }
}

/* 3. Delete nodes ---------------------------------------------------------------------------------


*/

void deleteAtHead(ListNode** head, ListNode** tail)
{
    if (*head == NULL) // If the linked list is empty.
        return;

    ListNode* current = *head;
    *head = current->next;

    if (*head == NULL) // If the linked list only has one node before.
    {
        *tail = NULL;
    }

    free(current);  // Clear the memory the pointer pointing to avoid memory leak.
    current = NULL; // Avoid dangling pointer
}

void deleteAtTail(ListNode** head, ListNode** tail)
{
    if(*head == NULL)  // If the linked list is empty.
        return;

    if(*head == *tail) // If the linked list only has one node before.
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    } 
    
    ListNode* current = *head;
    // Traverse to the second last node
    while(current->next != *tail)
    {
        current = current->next;
    }
    free(*tail);
    current->next = NULL;
    *tail = current;
}

void deleteNode(ListNode** head, ListNode** tail, int targetValue)
{   
    if(*head == NULL)  // If the linked list is empty.
        return;

    ListNode* current = *head;
    if (current->val == targetValue)  // If the target node is the head node.
    {
        deleteAtHead(head, tail);
        return;
    }
    
    while(current->next)
    {
        if(current->next->val == targetValue)
        {   
            ListNode* toDelete = current->next;
            current->next = toDelete->next;
            free(toDelete);
            if(current->next == NULL)
            {
                *tail = current;
            }
            return;
        }
        current = current->next;
    }
}           

/* 4. Access nodes(print or modify) ---------------------------------------------------------------------------

Time complexity: O(n) (traverse the whole linked list from head)
Space complexity: O(1)
*/
void traverseLinkedList(ListNode* head)
{   
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }

    ListNode* current = head;
    int index = 0;
    while(current)
    {
        current->val *=2;
        printf("Node%d= %2d, Address = %p.\n", index, current->val, current);
        index++;

        current = current->next;
    }
}

/* 5. Search nodes ---------------------------------------------------------------------------------

Time complexity: O(n) (traverse the whole linked list from head)
Space complexity: O(1)
*/

int findNode(ListNode* head, int target)
{
    ListNode* current = head;
    int index = 0;

    while(current)
    {
        if (current->val == target)
            return index;
        
        index++;
        current = current->next;
    }

    return -1;
}

//----------------------------------------------- M A I N ------------------------------------------
int main()
{    
    // Create 3 pointers to indicate the node in linked list
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* temp = NULL;
    
    // Create a linked list with several nodes
    // createLinkedList(&head, &tail, 5);

    // insertNode(head, 2, 34);
    // traverseLinkedList(head);
    // printf("Search result: %d.\n", findNode(head,6));

    createLinkedList(&head, &tail, 1);
    traverseLinkedList(head);
    printf("\n");
    deleteNode(&head, &tail, 2);
    traverseLinkedList(head);

    return 0;
}