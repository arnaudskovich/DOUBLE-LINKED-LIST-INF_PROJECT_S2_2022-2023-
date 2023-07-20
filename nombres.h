typedef struct ListItem LI;

struct ListItem {
    double value; //The number contained in the item
    LI *next; //point to the following item in the list ; null if current is last
    LI *prev; //point to the previous item in the list ; null if current is first
};

typedef struct ChainedList CL;

struct ChainedList {
    LI *first, *last; // point respectively to the first and last item in the list; null if there is no element
    int count; //the number of items in the list
};

CL *createList();
void initializeList(CL *list, double firstItemValue);
void printList(const CL *list);
void unshiftItem(CL *list, double number);
void pushItem(CL *list, double number);
void insertItem(CL *list, double number, unsigned int position);
void shiftItem(CL *list);
void popItem(CL *list);
void deleteItem(CL *list, unsigned int position);
void deleteItemCount(CL *list, unsigned int position, unsigned int count);
