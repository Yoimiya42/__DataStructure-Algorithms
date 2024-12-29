/*A Python-like list implemented using C arrays.*/
//--------------------------- D  E  F  I  N  E  ---------------------------
List* initList();

int getSize(List* list);                           //-- len()
int getCapacity(List* list); 
void showList(List* list);                         //-- print(list)
int getElem(List* list, int index);                //-- list[index]
void setElem(List* list, int index, int newVal);   //-- list[index] = newVal

void enlarge(List* list); 

void appendElem(List* list, int value);            //-- list.append(value)
int popElem(List* list, int index);                //-- list.pop(index)
void insert(List* list, int index, int value);     //-- list.insert(index, value)

void freeMemory(List* list); 
//------------------------------------------------------------------------

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <assert.h>

# include "auxiliary/list_auxiliary.h"

# define DEFAULT_CAPACITY 10
# define DEFAULT_ENLARGE 2

typedef struct List{
    int* arr;
    int capacity;
    int size;
    int enlargeRatio;
}List;

// 1. Initialization

List* initList()
{   
    List* myList = malloc(sizeof(List));
    if (!myList)
    {
        printf("Memory allocate failed.");
        exit(1);
    }

    // Default capacity
    myList-> capacity = DEFAULT_CAPACITY;
    
    // Initial Length

    myList->size= getIntInput("Desired list length(0<=Integer<=10)=", 0, myList->capacity);

    // Initial Content of List
    myList->arr = malloc(sizeof(int) * myList->capacity);
    for(int i = 0; i < myList->size; i++)
    {   
        char prompt[16];
        snprintf(prompt, sizeof(prompt), "List[%d]= ", i);
 
        *((myList->arr) + i) = getIntInput(prompt, INT_MIN, INT_MAX);
    }


    // Default enlargeRatio
    myList->enlargeRatio = DEFAULT_ENLARGE;

    return myList;
}

// 2. Fundamental Functions:

int getSize(List* list)
{
    return list->size;
}

int getCapacity(List* list)
{
    return list->capacity;
}

void showList(List* list)
{   
    printf("\nList:\n");
    for(int i = 0; i < list->size; i++)
    {
        printf("List[%d]= %2d\n", i, *((list->arr)+i));
    }
}

int getElem(List* list, int index)
{   
    assert(index >= 0 && index < list->size);
    return *((list->arr) + index);
}

void setElem(List* list, int index, int newVal)
{    
    assert(index >= 0 && index < list->size);
    *((list->arr) + index) = newVal;
}


// 3. Enlarge List Capacity
void enlarge(List* list)
{
    list->capacity = getCapacity(list) * list->enlargeRatio;
    int* newArr = malloc(sizeof(int) * list->capacity);

    for(int i = 0; i < getSize(list); i++)
    {
        *(newArr + i) = *((list->arr) + i);
    }
    free(list->arr);
    list->arr = newArr;
}

// 4. Append
void appendElem(List* list, int value)
{
    if(list->size == list->capacity)
        enlarge(list);
    
    *((list->arr) + getSize(list)) = value;
    list->size++;
}

// 5. Pop
int popElem(List* list, int index)
{
    assert(0<= index && index < list->size);
    int num = *((list->arr) + index);
    for(int i = index; i < getSize(list) - 1; i++)
    {
        *((list->arr) + i) = *((list->arr) + i + 1);
    }
    list->size--;
    return num;
}

// 6. Insert
void insert(List* list, int index, int value)
{   
    assert(0<= index && index < list->size);
    if(list->size == list->capacity)
        enlarge(list);

    for(int i = getSize(list); i > index; i--)
    {
        *((list->arr) + i) = *((list->arr) + i - 1);
    }

    *((list->arr) + index) = value;
    list->size++;
}

// 7. FreeMemory
void freeMemory(List* list)
{
    free(list->arr);
    free(list);
}


int main()
{
    run();
    return 0;
}
