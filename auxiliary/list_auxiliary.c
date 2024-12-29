# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <assert.h>

# include "3.3_List.h"


// Essential functions
void clearBuffer()
{
    while(getchar() != '\n' && getchar() != EOF);
}

int getIntInput(const char* prompt, int lowerlimit, int upperlimit)
{   
    int num;
    printf("%s", prompt);
    while(scanf("%d", &num) != 1 || num < lowerlimit || num > upperlimit)
    {
        printf("Invalid input. Please retype.");
        clearBuffer();
    }
    clearBuffer();

    return num;
}

// 8. User-interface
void UI()
{
    printf("\nPlease select your operation:\n");
    printf("1. getSize\n");
    printf("2. getCapacity\n");
    printf("3. getElem\n");
    printf("4. setElem\n\n");

    printf("5. appendElem\n");
    printf("6. popElem\n");
    printf("7. insert\n");
    printf("8. showList\n\n");

    printf("9. Exit\n");
}

void run()
{   
    List* myList = initList();
    showList(myList);
    
    UI();

    int choice;
    do{
        choice = getIntInput("\nYour choice=", 1, 9);
        switch(choice)
        {
            case 1:
                printf("Size= %d\n", getSize(myList));
                break;
            case 2:
                printf("Capacity = %d\n", getCapacity(myList));
                break;
            case 3: 
                {
                    int index = getIntInput("Please enter the index of the element you want to get=", 0, getSize(myList) - 1);
                    printf("Element= %d\n", getElem(myList, index));
                    break;
                }
            case 4:
                {
                    int index = getIntInput("Please enter the index of the element you want to set=", 0, getSize(myList) - 1);
                    int newVal = getIntInput("New Value = ", INT_MIN, INT_MAX);
                    setElem(myList, index, newVal);
                    break;
                }
            case 5:
                {
                    int value = getIntInput("Please enter the value you want to append=", INT_MIN, INT_MAX);
                    appendElem(myList, value);
                    break;
                }
            case 6:
                {
                    int index = getIntInput("Please enter the index of the element you want to pop=", 0, getSize(myList) - 1);
                    printf("Popped Element= %d\n", popElem(myList, index));
                    break;
                }
            case 7:
                {
                    int index = getIntInput("Please enter the index you want to insert=", 0, getSize(myList) - 1);
                    int value = getIntInput("Please enter the value you want to insert=", INT_MIN, INT_MAX);
                    insert(myList, index, value);
                    break;
                }  
            case 8:
                showList(myList);
                break;
            case 9:
                freeMemory(myList);
                printf("Memory Freed. Exit.");
                break;
        }
    } while(choice != 9);
}