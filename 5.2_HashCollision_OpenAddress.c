
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// ------------------- D  E  F  I  N  E ------------------------

# define CAPACITY 10
# define EXTENDRATIO 2

typedef struct Pair{
    int key;
    char* val;
}Pair;

typedef struct Hmap{
    int size;
    int capacity;
    double loadFactor;
    int extendRatio;
    
    Pair** buckets;
    Pair* tombstone;
}Hmap;

Hmap* initHmap();
void deconstructor(Hmap* hmap);
Pair* createPair(int key, char* val);

int hashFunc(Hmap* hmap, int key);
double loadFactor(Hmap* hmap);

void extendHmap(Hmap* hmap);

void put(Hmap* hmap, int key, char* val);
char* get(Hmap* hmap, int key);
void delete(Hmap* hmap, int key);
void print(Hmap* hmap);


// ------------------- I  M  P  L  E  M  E  N  T  A  T  I  O  N  S ------------------------ 
Hmap* initHmap()
{
    Hmap* hmap = malloc(sizeof(Hmap));

    hmap->size = 0;
    hmap->capacity = CAPACITY;
    hmap->loadFactor = 2.0 / 3.0;
    hmap->extendRatio = EXTENDRATIO;
    
    hmap->tombstone = malloc(sizeof(Pair));
    hmap->tombstone->key = -1;
    hmap->tombstone->val = "-1";

    hmap->buckets = (Pair**)malloc(sizeof(Pair*) * hmap->capacity);
    for(int i = 0; i < hmap->capacity; i++)
    {
        hmap->buckets[i] = NULL;
    }

    return hmap;
}

Pair* createPair(int key, char* val)
{
    Pair* pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->val = strdup(val);

    return pair;
}

// Hash Function
int hashFunc(Hmap* hmap, int key)
{
    return key % hmap->capacity;
}

// loadFactor
double loadFactor(Hmap* hmap)
{
    return (double) hmap->size / (double) hmap->capacity;
}

// Deconstructor
void deconstructor(Hmap* hmap)
{
    for(int i = 0; i < hmap->capacity; i++)
    {
        if(hmap->buckets[i] && hmap->buckets[i] != hmap->tombstone)
        {
            free(hmap->buckets[i]->val);
            free(hmap->buckets[i]);
        }
    }

    free(hmap->buckets);
    free(hmap->tombstone);
    free(hmap);
}
// Optimize index
// int optimizedIndex(Hmap* hmap, int key)
// {
//     int index = hashFunc(hmap, key);
//     int TombStone = -1;
//     while(hmap->buckets[index])
//     {   
//         if(hmap->buckets[index]->key == key)
//         {   
//             // If the a tombstone is occurred in the previous bucket, 
//             // we exchange the 
//             if(TombStone != -1) 
//             {
//                 hash->buckets[TombStone] = hash->buckets[index];
//                 hash->buckets[index] = hmap->tombstone;
//                 return TombStone;
//             }
//             return index;
//         }
//     }
// }


// 1. Extend
void extendHmap(Hmap* hmap)
{
    // Reserve the previous buckets
    Pair** oldBuckets = hmap->buckets;
    int oldCapacity = hmap->capacity;

    // Initialize a new buckets
    hmap->size = 0;
    hmap->capacity *= hmap->extendRatio;

    hmap->buckets = (Pair**)malloc(sizeof(Pair*) * hmap->capacity);
    for(int i = 0; i < hmap->capacity; i++)
    {
        hmap->buckets[i] = NULL;
    }

    // Copy the old buckets to the new buckets
    for(int i = 0; i < oldCapacity; i++)
    {
        if(oldBuckets[i] && oldBuckets[i] != hmap->tombstone)
        {
            put(hmap, oldBuckets[i]->key, oldBuckets[i]->val);
            free(oldBuckets[i]->val);
            free(oldBuckets[i]);
        }
    }
    free(oldBuckets);
}

// 2. Put
void put(Hmap* hmap, int key, char* val)
{   
    // If the load factor is greater than the threshold, extend the HashMap.
    if(loadFactor(hmap) >= hmap->loadFactor)
    {
        extendHmap(hmap);
    }

    int index = hashFunc(hmap, key);

    while(hmap->buckets[index] && hmap->buckets[index] != hmap->tombstone)
    {   
        // Scenario 1: The key has existed, update the value
        if(hmap->buckets[index]->key == key)
        {
            free(hmap->buckets[index]->val);
            hmap->buckets[index]->val = strdup(val);

            return;
        }
        // If this bucket is occupied with another key-value, move linearly step to the next empty exist.
        index = (index + 1) % hmap->capacity;
    }

    // Scenario 2: The key does not exist
    Pair* pair = createPair(key, val);
    hmap->buckets[index] = pair;
    hmap->size++;
}

// 3. Get value via key
char* get(Hmap* hmap, int key)
{
    int index = hashFunc(hmap, key);
    while(hmap->buckets[index] && hmap->buckets[index] != hmap->tombstone)
    {
        if(hmap->buckets[index]->key == key)
        {
            return hmap->buckets[index]->val;
        }
        index = (index + 1) % hmap->capacity;
    }

    return "Nothing fetched.";
}

// 4. Delete
void delete(Hmap* hmap, int key)
{
    int index = hashFunc(hmap, key);

    while(hmap->buckets[index] && hmap->buckets[index] != hmap->tombstone)
    {
        if(hmap->buckets[index]->key == key)
        {   
            free(hmap->buckets[index]->val);
            free(hmap->buckets[index]);

            hmap->buckets[index] = hmap->tombstone;
            hmap->size--;
            return;
        }
        index = (index + 1) % hmap->capacity;
    }
    
    printf("No matched key.");
}

// 5. print
void print(Hmap* hmap)
{
    for(int i = 0; i < hmap->capacity; i++)
    {   
        Pair* cur = hmap->buckets[i];
        if(cur)
        {
            if(cur != hmap->tombstone)
            {
                printf("Bucket[%2d]: Key(%d)= %s\n", i, cur->key, cur->val);
            }else{
                printf("Bucket[%2d]: TOMBSTONE.\n", i);
            }
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
    printf(" 5 ->clear the HashMap and cease.\n");

    int key;
    char val[100];

    while(1)
    {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                scanf("%d", &key);
                scanf("%s", val);
                put(hmap, key, val);
                break;
            case 2:
                scanf("%d", &key);
                printf("The value is: %s\n", get(hmap, key));
                break;
            case 3:
                print(hmap);
                break;
            case 4:
                scanf("%d", &key);
                delete(hmap, key);
                break;
            case 5:
                deconstructor(hmap);
                printf("Memory released. Cease.\n");
                return;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

int main()
{
    Hmap* hmap = initHmap();
    testHmap(hmap);
    return 0;
}