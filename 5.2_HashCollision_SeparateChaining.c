# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
Hash Collision: multiple inputs(keys) correspond to the same output(value)

The larger the capacity of hashTable, 
the lower the probability that multiple keys being assigned to the same bucket, resulting in fewer collisions
Hence, we can reduce the hashTable collision by extending capacity of hashTable.

Load Factor = ( n(pairs) / Total buckets ) 
It used to measure the severity of hash collision and often serves as a trigger for resizing the hashTable.

e.g. In Java, the default load factor is 0.75, 
which means that once exist pairs reach 75% of the total buckets,
the system will resize the hashTable to twice its original size.

Unfortunately, the resizing operation is also time-consuming, and 
a hash function's input space is typically far greater than its output space.
    - Separate Chaining
    - Open Addressing
these two methods are used to improve the structure of hash table.
*/

// ------------------- D  E  F  I  N  E ------------------------
# define CAPACITY 10
# define EXTENDRATIO 2

typedef struct Pair{
    int key;
    char* val;
}Pair;

typedef struct Node{
    Pair* pair;
    struct Node* next;
}Node;

typedef struct Hmap{
    int size;    // Number of existing pairs
    int capacity;
    double loadFactor; // Condition for extending
    int extendRatio;   // The ratio of extending
    Node** buckets;    // 
}Hmap;

Hmap* initHmap();
void deconstructor(Hmap* hmap);
int hashFunc(int key, Hmap* hmap);
double loadFactor(Hmap* hmap);

Pair* createPair(int key, char* val);
Node* createNode(Pair* pair);

char* get(Hmap* hmap, int input);
void put(Hmap* hmap, int key, char* val);
void extendHmap(Hmap* hmap);
void delete(Hmap* hmap, int key);
void printHmap(Hmap* hmap);

// ------------------- I  M  P  L  E  M  E  N  T  A  T  I  O  N  S ------------------------

// 0. Constructor
Hmap* initHmap()
{
    Hmap* hmap = malloc(sizeof(Hmap));
    hmap->size = 0;
    hmap->capacity = CAPACITY;
    hmap->loadFactor = 3.0 / 4.0;
    hmap->extendRatio = 2;

    hmap->buckets = (Node**)malloc(sizeof(Node*) * hmap->capacity);
    for(int i = 0; i < hmap->capacity; i++)
    {
        hmap->buckets[i] = NULL;
    }

    return hmap;
}

// 0. Deconstructor
void deconstructor(Hmap* hmap)
{
    for(int i = 0; i < hmap->capacity; i++)
    {
        Node* current = hmap->buckets[i];
        while(current)
        {
            Node* temp = current;
            current = current->next;

            free(temp->pair->val);
            free(temp->pair);
            free(temp->next);
            free(temp);
        }
    }

    free(hmap->buckets);
    free(hmap);
}

// HashFunction
int hashFunc(int key, Hmap* hmap)
{
    return key % hmap->capacity;
}

// Calculate the current load factor
double loadFactor(Hmap* hmap)
{
    return (double)hmap->size / (double)hmap->capacity;
}

// Create Pair
Pair* createPair(int key, char* val)
{
    Pair* pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->val = strdup(val);

    return pair;
}

// Create Node
Node* createNode(Pair* pair)
{
    Node* node = malloc(sizeof(Node));
    node->pair = pair;
    node->next = NULL;

    return node;
}

// 1. Enquiry the value by key
char* get(Hmap* hmap, int key)
{
    int index = hashFunc(key, hmap);

    Node* target = hmap->buckets[index];
    while(target)
    {   
        if(target->pair->key == key)
        {
            return target->pair->val;
        }
        target = target->next;
    }

    return "Nothing fetched.";
}

// 2. Add Pair
void put(Hmap* hmap, int key, char* val)
{   
    if(loadFactor(hmap) >= hmap->loadFactor)
    {
        extendHmap(hmap);
    }

    int index = hashFunc(key, hmap);

// Scenario 1: The key has existed, update the value
    Node* target = hmap->buckets[index];
    while(target)
    {
        if(target->pair->key == key)
        {
            free(target->pair->val);
            target->pair->val = strdup(val);

            return;
        }
        target = target->next;
    }

// Scenario 2: The key does not exist
    Pair* pair = createPair(key, val);
    Node* node = createNode(pair);

    node->next = hmap->buckets[index];
    hmap->buckets[index] = node;

    hmap->size++;
}

// 3. Extend
void extendHmap(Hmap* hmap)
{   
    // Reserve the previous buckets
    int oldCapacity = hmap->capacity;
    Node** oldBuckets = hmap->buckets;

    // Initialize a new buckets
    hmap->size = 0;
    hmap->capacity *= hmap->extendRatio;
    hmap->buckets = (Node**)malloc(sizeof(Node*) * hmap->capacity);
    for(int i = 0; i < hmap->capacity; i++)
    {
        hmap->buckets[i] = NULL;
    }

    // Copy the old buckets to the new buckets
    for(int i = 0; i < oldCapacity; i++)
    {
        Node* current = oldBuckets[i];
        while(current)
        {
            put(hmap, current->pair->key, current->pair->val);
            
            Node* temp = current;
            current = current->next;

            free(temp->pair->val);
            free(temp->pair);
            free(temp);
        }
    }

    free(oldBuckets);
}

// 4. Remove
void delete(Hmap* hmap, int key)
{
    int index = hashFunc(key, hmap);

    Node* current = hmap->buckets[index];
    Node* prev = NULL;
    while(current)
    {
        if(current->pair->key == key)
        {   
            if(prev)
            {
                prev->next = current->next;
            }else{
                hmap->buckets[index] = current->next;
            }
            free(current->pair->val);
            free(current->pair);
            free(current);

            hmap->size--;
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("No matched key.\n");
}

// 5. print
void printHmap(Hmap* hmap)
{   
    if(hmap->size == 0)
    {
        printf("Empty HashMap.\n");
        return;
    }

    for(int i = 0; i < hmap->capacity; i++)
    {
        if(hmap->buckets[i])
        {   
            Node* current = hmap->buckets[i];
            printf("Buckets[%2d]: ", i);

            while(current)
            {
                printf("Key= %d, Val= %s-> ",current->pair->key, current->pair->val);

                current = current->next;
            }

            printf("\n");
        }
    }
}

// ------------------- T  E  S  T -------------------
void testHmap(Hmap* hmap)
{   
    printf("Choose your operations: \n\n");

    printf(" 1 ->put\n");
    printf(" 2 ->get\n");
    printf(" 3 ->print the whole HashMap\n");
    printf(" 4 ->delete\n\n");

    printf(" 5 ->clear the HashMap and cease\n");

    int choice;
    do{
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int key;
                char val[256];
                scanf("%d %s", &key, val);
                put(hmap, key, val);
                break;
            }
            case 2:
            {
                int key;
                scanf("%d", &key);
                printf("The value is: %s\n", get(hmap, key));
                break;
            }
            case 3:
            {
                printHmap(hmap);
                break;
            }
            case 4:
            {
                int key;
                scanf("%d", &key);
                delete(hmap, key);
                break;
            }
            case 5:
            {   
                deconstructor(hmap);
                printf("Exit\n");
                break;
            }
        }
    } while (choice != 5);
}


int main()
{   
    Hmap* hmap = initHmap();
    testHmap(hmap);

    return 0;
}