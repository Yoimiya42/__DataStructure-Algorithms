typedef struct List{
    int* arr;
    int capacity;
    int size;
    int enlargeRatio;
}List;

# define DEFAULT_CAPACITY 10
# define DEFAULT_ENLARGE 2

List* initList();
int getSize(List* list);
int getCapacity(List* list);
void showList(List* list);
void enlarge(List* list);
void appendElem(List* list, int value);
int getElem(List* list, int index);
void setElem(List* list, int index, int newVal);
int popElem(List* list, int index);
void insert(List* list, int index, int value);
void freeMemory(List* list);