#include <stdlib.h>
#include <stdio.h>
#include "nombres.h"

CL *createList() {
    CL *list = (CL *) malloc(sizeof(CL));
    if (list == NULL) {
        printf("COULD NOT CREATE LIST\nMEMORY ALLOCATION WAS NOT SUCCESSFUL");
        exit(1);
    }
    list->count = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void initializeList(CL *list, const double firstItemValue) {
    LI *item = (LI *) malloc(sizeof(LI));
    if (item == NULL) {
        printf("COULD NOT CREATE ITEM\nMEMORY ALLOCATION WAS NOT SUCCESSFUL");
        exit(1);
    }
    item->value = firstItemValue;
    item->prev = NULL;
    item->next = NULL;
    list->first = item;
    list->last = item;
    list->count = 1;
}

void printList(const CL *list) {
    if (list->count == 0) {
        printf(">>> LIST IS EMPTY <<<");
        return;
    }
    LI *temp = list->first;
    unsigned int i = 0;
    printf(">>> FORMAT [POSITION] : VALUE <<<\n");
    while (temp) {
        printf("[%i]: %lf; ", i, temp->value);
        temp = temp->next;
        i++;
    }
    printf("\n");
}

void unshiftItem(CL *list, double number) {
    LI *item = (LI *) malloc(sizeof(LI));
    if (item == NULL) {
        printf("COULD NOT CREATE ITEM\nMEMORY ALLOCATION WAS NOT SUCCESSFUL");
        exit(1);
    }
    if (list->count == 0) return initializeList(list, number);
    item->value = number;
    item->next = list->first;
    item->prev = NULL;
    list->first->prev = item;
    list->first = item;
    list->count++;
}

void pushItem(CL *list, double number) {
    LI *item = (LI *) malloc(sizeof(LI));
    if (item == NULL) {
        printf("COULD NOT CREATE ITEM\nMEMORY ALLOCATION WAS NOT SUCCESSFUL");
        exit(1);
    }
    if (list->count == 0) return initializeList(list, number);
    item->value = number;
    if (list->count == 1) {
        list->first->next = item;
        item->prev = list->first;
    } else {
        item->prev = list->last;
        list->last->next = item;
    }
    item->next = NULL;
    list->last = item;
    list->count++;
}

void insertItem(CL *list, double number, unsigned int position) {
    if (list->count == 0) return initializeList(list, number);
    if (position >= list->count) {
        return pushItem(list, number);
    }
    if (position == 0) {
        return unshiftItem(list, number);
    }
    LI *item = (LI *) malloc(sizeof(LI));
    if (item == NULL) {
        printf("COULD NOT CREATE ITEM\nMEMORY ALLOCATION WAS NOT SUCCESSFUL");
        exit(1);
    }
    item->value = number;
    LI *itemRight = list->first;
    for (int i = 0; i < position; i++) {
        itemRight = itemRight->next;
    }
    LI *itemLeft = itemRight->prev;
    item->prev = itemLeft;
    item->next = itemRight;
    itemLeft->next = item;
    itemRight->prev = item;
    list->count++;
}

void shiftItem(CL *list) {
    if (list->count == 0) return;
    if (list->count == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        list->count = 0;
        return;
    }
    if (list->count == 2) {
        LI *itemToShift = list->first;
        list->first = list->last;
        free(itemToShift);
        list->count = 1;
        return;
    }
    LI *itemToShift = list->first;
    list->first = list->first->next;
    list->first->prev = NULL;
    free(itemToShift);
    list->count--;
}

void popItem(CL *list) {
    if (list->count == 0) return;
    if (list->count == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        list->count = 0;
        return;
    }
    if (list->count == 2) {
        LI *itemToPop = list->last;
        list->first->next = NULL;
        list->last = list->first;
        free(itemToPop);
        list->count = 1;
        return;
    }
    LI *itemToPop = list->last;
    list->last = list->last->prev;
    list->last->next = NULL;
    free(itemToPop);
    list->count--;
}

void deleteItem(CL *list, unsigned int position) {
    if (position >= list->count) return;
    if (position == 0) return shiftItem(list);
    if (position == list->count - 1) return popItem(list);
    LI *itemToDelete = list->first;
    for (int i = 0; i < position; ++i) {
        itemToDelete = itemToDelete->next;
    }
    itemToDelete->prev->next = itemToDelete->next;
    itemToDelete->next->prev = itemToDelete->prev;
    list->count--;
    free(itemToDelete);
}

void deleteItemCount(CL *list, unsigned int position, unsigned int count) {
    while (position < list->count && count > 0) {
        deleteItem(list, position);
        count--;
    }
}