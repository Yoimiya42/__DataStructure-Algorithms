



typedef struct Node{
    int val;
    struct Node* 
}

Node* createNode(int value)
{
    Node* node = malloc(sizeof(Node));
    node->val = value;
    node->next = NULL;
}

// 1. push
void push(Node** top, int value)
{
    Node* node = createNode(value);
    node->next = *top;
    *top = node;
}

// 2. pop
void pop(Node** top)
{
    if(*top == NULL)
    {
        printf("Empty Stack.");
        return;
    }

    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}
// 3. peek
int peek(Node* top)
{
    if(top == NULL)
    {
        printf("Empty Stack.");
        return -1;
    }

    return top->val;
}

// 4. check the whole stack
void traverseStack(Node* top)
{
    Node* current = top;
    int index = 0;
    while(current)
    {  
        printf("Layer%d: %d\n", index, current->val);
        current = current->next;
        index++;
    }

}

int main()
{   
    Node* top = NULL;
    return 0;
}