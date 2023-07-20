# INF_PROJECT_S2_2022-2023
# Double Linked List (Numbers)

This repository contains a simple implementation of a double linked list for numbers in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Manager](#manager)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)

## Introduction

A double linked list is a data structure that consists of a sequence of elements, called nodes, where each node contains both a value and references to the previous and next nodes in the sequence. This allows for efficient insertion and deletion at both ends of the list.

This implementation provides basic operations to create, modify, and print a double linked list of numbers in C.

## Features

- Create an empty double linked list.
- Initialize the list with a single number.
- Print the contents of the list.
- Add a number to the front of the list (unshift).
- Add a number to the end of the list (push).
- Insert a number at a specific position in the list.
- Remove the first number from the list (shift).
- Remove the last number from the list (pop).
- Delete a number at a specific position from the list.

## Functions

The following functions are available for interacting with the double linked list:
```c

CL *createList() //Creates an empty double linked list and return a pointer to it.

void initializeList(CL *list, double firstItemValue) //Initializes the list with a single number.

void printList(const CL *list) //Prints the content of the list.

void unshiftItem(CL *list, double number) //Adds a number to the front of the list (unshift).

void pushItem(CL *list, double number) //Adds a number to the end of the list (push).

void insertItem(CL *list, double number, unsigned int position) //Inserts a number at a specific position in the list.

void shiftItem(CL *list) //Remove the first number from the list (shift).

void popItem(CL *list) //Remove the last number from the list (pop).

void deleteItem(CL *list, unsigned int position) //Delete a number at a specific position from the list.
```
## Usage

To use the double linked list in your C project, follow these steps:

1. Clone the repository to your local machine:
```bash
git clone https://github.com/arnaudskovich/DOUBLE-LINKED-LIST-INF_PROJECT_S2_2022-2023-.git
```
2. Include the `numbers.h` header file in your C code:

```c
#include "numbers.h"
```
3. Compile your code along with the numbers.c source file:
```bash
gcc your_code.c numbers.c -o your_executable
```
4. Start using the functions available in the numbers.h header file to interact with the double linked list. For example:
```c
#include <stdio.h>
#include "numbers.h"

int main() {
    // Create a new double linked list
    CL *myList = createList();

    // Initialize the list with a single number
    // You can pass this step because number adding fuctions (unshiftItem, pushItem, insertItem) can handle this
    initializeList(myList, 42.0);

    // Add numbers to the front and end of the list
    unshiftItem(myList, 10.0);
    pushItem(myList, 100.0);

    // Insert a number at a specific position in the list
    insertItem(myList, 50.0, 2);

    // Print the contents of the list
    printList(myList);

    // Remove the first and last numbers from the list
    shiftItem(myList);
    popItem(myList);

    // Delete a number at a specific position from the list
    deleteItem(myList, 1);

    // Print the updated list
    printList(myList);

    // Free the memory used by the list
    // Note: Don't forget to free the memory when you're done with the list!
    free(myList);

    return 0;
}

```
The above code gives the following output:
```css
>>> FORMAT [POSITION] : VALUE <<<
[0]: 10.000000; [1]: 42.000000; [2]: 50.000000; [3]: 100.000000;
>>> FORMAT [POSITION] : VALUE <<<
[0]: 42.000000; [1]: 100.000000;
```

## MANAGER
!!! You can also use the pre-written manager in the main.c file to see how things works. !!!<br>
The realease is using the manager in main.c

## Contributing
Contributions to this project are welcome! If you find any issues or have ideas for improvements, feel free to open an issue or submit a pull request.

## License
This project is licensed under the GNU General Public License v3.0 License. Feel free to use and modify the code as per the terms of the license.
