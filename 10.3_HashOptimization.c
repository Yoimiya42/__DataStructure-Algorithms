# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
Given an array of integers nums and an integer target, return indices 
of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

Example:
[7,16,24,35]  target = 42    => return [0, 3] 
*/

/* Self-Solution 1: Linear Search -- Brute force enumeration
Time Complexity:  O(n^2)
Space Complexity: O(1)
*/
int* twoSumLinearSearch(int* nums, int numsSize, int target, int* returnSize) 
{   
    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = i + 1;j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                int* res = malloc(sizeof(int) * 2);
                res[0] = i;
                res[1] = j;
                *returnSize = 2;

                return res;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}


/********************************************************
 * Self-Solution 2： Hash Search
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 * 
 * 1. Look for whether target - nums[i] exists in the hash table
 *    if yes, directly return the indices
 *    if not, -> 2. insert (key: i, value: nums[i]) into the hash table
 ********************************************************/
// Separate Chaining
typedef struct Node{
    int key;     // nums in array
    int value;   // index of a number
    struct Node* next;
}Node;

typedef struct HashTable{
    double loadFactor;
    int capacity;
    Node** buckets;
}HashTable;

Node* createNode(int key, int value)
{
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;

    return node;
}

HashTable* initHashTable(int size)
{
    HashTable* hmap = malloc(sizeof(HashTable));
    hmap->loadFactor = 3.0 / 4.0;
    hmap->capacity = (int)(size / hmap->loadFactor) + 1;
    hmap->buckets = calloc(hmap->capacity, sizeof(Node*));

    return hmap;
}

int hashFunc(HashTable* hmap, int key)
{   
    if(abs(key) >= hmap->capacity)
    {
        return hashFunc(hmap, abs(key) % hmap->capacity);
    }
    return abs(key);
}

int find(HashTable* hmap, int key)
{
    int hashIndex = hashFunc(hmap, key);
    Node* cur = hmap->buckets[hashIndex];
    while(cur)
    {   
        if(cur->key == key)
        {
            return cur->value;
        }
        cur = cur->next;
    }

    return -1;
}

void add(HashTable* hmap, int key, int value)
{
    Node* newNode = createNode(key, value);
    int i = hashFunc(hmap, key);

    newNode->next = hmap->buckets[i];
    hmap->buckets[i] = newNode;
}

int* twoSumHashSearch(int* nums, int numsSize, int target, int* returnSize)
{
    HashTable* hmap = initHashTable(numsSize);
    for(int i = 0; i < numsSize; i++)
    {
        int index = find(hmap, target - nums[i]);
        if(index != -1)
        {
            int* res = malloc(sizeof(int) * 2);
            res[0] = index;
            res[1] = i;

            *returnSize = 2;

            return res;
        }else{
            add(hmap, nums[i], i);
        }
    }

    *returnSize = 0;
    return NULL;
}

/********************************************************************
 * Official Solution: 

*/









// ---------------------- Test ----------------------
int main()
{
    int arr[] = {-7,-14,-3,-4,-5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = -8;
    
    int returnSize = 0;
    int* res = twoSumHashSearch(arr, size, target, &returnSize);
    if(returnSize)
    {
        printf("The indices are: [%d, %d]\n", res[0], res[1]);
    }else{
        printf("No matched indices.\n");
    }

    return 0;
}