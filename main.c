#include <stdio.h>
#include <stdlib.h>
#include "nombres.h"

#ifdef _WIN32

void clearConsole() {
    system("cls");
}

#elif defined(__unix__) || defined(__APPLE__)
void clearConsole() {
        printf("\033[2J\033[H");
        fflush(stdout);
}
#else
    void clearConsole() {}
#endif

void showMenu();

void showAddSubmenu();

void showDeleteSubmenu();

void askSelection();

CL *initializer();

void printer(CL *list);

void sizePrinter(CL *list);

void addLogic(CL *list);

void deleteLogic(CL *list);

void exit_f() {
    exit(0);
}

int main() {
    char mainChoice;
    CL *list;
    do {
        showMenu();
        askSelection();
        scanf(" %c", &mainChoice);
        clearConsole();
        switch (mainChoice) {
            case '1':
                if(list != NULL){
                    printf("!!! THIS WILL RESET THE CURRENT LIST !!!\nDO YOU WANT TO CONTINUE ?");
                    char c;
                    do {
                        printf("\nINPUT Y FOR YES AND N FOR NO: ");
                        scanf(" %c", &c);
                    }while(c!='Y' && c!='y' && c!='n' && c!='N');
                    clearConsole();
                    if(c=='N' || c=='n') break;
                }
                clearConsole();
                list = initializer();
                break;
            case '2':
                if (list != NULL) printer(list);
                else printf("!!! FIRST CREATE THE LIST !!!");
                break;
            case '3':
                if (list != NULL)sizePrinter(list);
                else printf("!!! FIRST CREATE THE LIST !!!");
                break;
            case '4':
                if (list != NULL) addLogic(list);
                else printf("!!! FIRST CREATE THE LIST !!!");
                break;
            case '5':
                if (list != NULL)deleteLogic(list);
                else printf("!!! FIRST CREATE THE LIST !!!");
                break;
            case '6':
                exit_f();
                break;
            default:
                printf("!!! CHOOSE A NUMBER BETWEEN 1-6 !!!");
        }

    } while (mainChoice != '6');
    return 0;
}

void showMenu() {
    printf("\n==== LINKED LIST MANAGER FOR NUMBERS ====\n");
    printf("Choose a number to realize its action\n");
    printf("1- Create the list\n");
    printf("2- Show list content\n");
    printf("3- Get list length\n");
    printf("4- Add a number in the list\n");
    printf("5- Delete a number from the list\n");
    printf("6- Quit");
}

void showAddSubmenu() {
    printf("==== NUMBER ADDING ====\n");
    printf("0- Print list content\n");
    printf("1- At list start\n");
    printf("2- At list end\n");
    printf("3- Somewhere in the list\n");
    printf("4- Back\n");
    printf("5- Quit\n");
}

void showDeleteSubmenu() {
    printf("==== NUMBER DELETING ====\n");
    printf("0- Print list content\n");
    printf("1- At list start\n");
    printf("2- At list end\n");
    printf("3- Somewhere in the list\n");
    printf("4- Back\n");
    printf("5- Quit\n");
}

void askSelection() {
    printf("\nEnter your selection: ");
}

CL *initializer() {
    printf(">>> LIST INITIALIZED <<<");
    return createList();
}

void printer(CL *list) {
    printList(list);
}

void sizePrinter(CL *list) {
    printf(">>> THE LIST CONTAINS %d NUMBERS <<<", list->count);
}

void addLogic(CL *list) {
    char choice;
    double numberToAdd;
    unsigned int position;
    do {
        showAddSubmenu();
        askSelection();
        scanf(" %c", &choice);
        clearConsole();

        switch (choice) {
            case '0':
                printer(list);
                printf("\n");
                break;
            case '1':
                printf("=== ADDING NUMBER TO LIST START ===\nInput the number to add: ");
                scanf(" %lf", &numberToAdd);
                clearConsole();
                unshiftItem(list, numberToAdd);
                printf(">>> NUMBER ADDED AT LIST STARTING <<<\n");
                break;
            case '2':
                printf("=== ADDING NUMBER TO LIST END ===\nInput the number to add: ");
                scanf(" %lf", &numberToAdd);
                clearConsole();
                pushItem(list, numberToAdd);
                printf(">>> NUMBER ADDED AT LIST END <<<\n");
                break;
            case '3':
                printf("=== ADDING NUMBER TO A SPECIFIC POSITION ===\n"
                       "Input the number to add: ");
                scanf(" %lf", &numberToAdd);
                printf("\n::: Position for the insertion :::\n"
                       "[must be a positive integer less than %d]\n"
                       "[if greater, the number will be added at the list end]: ", list->count);
                scanf(" %u", &position);
                clearConsole();
                insertItem(list, numberToAdd, position);
                printf(">>> NUMBER ADDED AT POSITION %d <<<\n",
                       (position < list->count) ? position : list->count - 1);
                break;
            case '4':
                return;
            case '5':
                exit_f();
                break;
            default:
                printf("!!! CHOOSE A NUMBER BETWEEN 0-5 !!!\n");
        }

    } while (choice != '4');
}

void deleteLogic(CL *list) {
    if (list->count == 0) {
        printf("\n>>> LIST IS EMPTY NO DELETION ACTION IS POSSIBLE <<<\n");
        return;
    }
    char choice;
    unsigned int position;
    do {
        showDeleteSubmenu();
        askSelection();
        scanf(" %c", &choice);
        clearConsole();

        switch (choice) {
            case '0':
                printer(list);
                printf("\n");
                break;
            case '1':
                printf(">>> NUMBER %lf DELETED AT LIST STARTING <<<\n", list->first->value);
                shiftItem(list);
                break;
            case '2':
                printf("\n>>> NUMBER %lf DELETED AT LIST END <<<\n", list->last->value);
                popItem(list);
                break;
            case '3':
                printf("=== DELETING NUMBER AT A SPECIFIC POSITION ===\n"
                       "::: Input the position of the number to delete :::\n"
                       "[must be a positive integer less than %d]\n"
                       "[if greater, nothing will be done]: ", list->count);
                scanf(" %u", &position);
                clearConsole();
                deleteItem(list, position);
                (position < list->count) ? printf(">>> NUMBER AT POSITION %d DELETED <<<\n", position) : printf(
                        "!!! POSITION SPECIFIED DOES NOT EXIST !!!\n");
                break;
            case '4':
                return;
            case '5':
                exit_f();
                break;
            default:
                printf("!!! CHOOSE A NUMBER BETWEEN 0-5 !!!\n");
        }

    } while (choice != '4');
}

