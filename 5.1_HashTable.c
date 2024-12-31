/*
HashTable or HashMap  establishes a mapping between a key and a value,enabling efficient element retrieval.
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// ------------------- D  E  F  I  N  E  S -------------------
# define CAPACITY 100

typedef struct Pair{
    int key;
    char* val;
}Pair;

typedef struct HashMap{
    Pair* buckets[CAPACITY];// Fixed size, no need to dynamically allocate memory.
}HashMap;

// -------------------I M P L E M E N T A T I O N S -------------------

// Hash Function
int hashFunc(int rawData)
{
    return rawData % CAPACITY;
}

// 0. Constructor
HashMap* initHashMap()
{
    HashMap* hmap = malloc(sizeof(HashMap));
    for(int i = 0; i < CAPACITY; i++)
    {
        hmap->buckets[i] = NULL;
    }

    return hmap;
}

// 1. put:    Time Complexity: O(1)
void put(HashMap* hmap, const int key, const char* val)
{
    Pair* pair = malloc(sizeof(Pair));

    pair->key = key;
    pair->val = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(pair->val, val);

    int index = hashFunc(key);
    hmap->buckets[index] = pair;
}

// 2. delete:  Time Complexity: O(1)
void delete(HashMap* hmap, const int key)
{
    int index = hashFunc(key);

    if(hmap->buckets[index] == NULL)  // Avoid processing NULL pointer.
    {
        printf("Key not found.");
        return;
    }

    free(hmap->buckets[index]->val);
    free(hmap->buckets[index]);

    hmap->buckets[index] = NULL;
}
// 3. print

void printHmap(HashMap* hmap)
{   int index = 0;
    for(int i = 0; i < CAPACITY; i++)
    {
        if(hmap->buckets[i])
        {
            printf("hmap[%d]: %d -> %s\n", index, hmap->buckets[i]->key, hmap->buckets[i]->val);
        }
        index++;
    }
}

// 4. deconstructor
void deconstructor(HashMap* hmap)
{
    for(int i = 0; i < CAPACITY; i++)
    {
        if(hmap->buckets[i])
        {
            free(hmap->buckets[i]->val);
            free(hmap->buckets[i]);
        }
    }

    free(hmap);
}

// ------------------- T  E  S  T -------------------
void testHashMap(HashMap* hmap)
{
    printf("Choose your operations: \n");
    printf(" 1 ->put\n");
    printf(" 2 ->delete\n");

    printf(" 3 ->print the whole HashMap\n");
    printf(" 4 ->clear the HashMap and cease\n");

    int choice;
    do{
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int key;
                char* val = malloc(sizeof(char) * 100);
                scanf("%d %s", &key, val);
                put(hmap, key, val);
                break;
            }
            case 2:
            {
                int key;
                scanf("%d", &key);
                delete(hmap, key);
                break;
            }
            case 3:
            {
                printHmap(hmap);
                break;
            }
            case 4:
            {
                deconstructor(hmap);
                break;
            }
        }
    }while(choice != 4);
}

int main()
{   
    HashMap* hmap = initHashMap();
    testHashMap(hmap);

    return 0;
}