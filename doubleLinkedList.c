/**
* @file doubleLinkedList.c
* @brief This file contains the implementation of a double linked list, with its related functions
*
* Such operations include managing a doubly linked list by creating, deleting, and traversing nodes, and inserting or deleting nodes at specific positions relative to the current node.
* 
* @authors Adam Davoren King, Andrew Reel, Charlie Brady, Ciaran Knowles, Joey Clancy, Ruairi Seery
* @version 1.0
*/


#include "doubleLinkedList.h"
#include "dataTypeOrderedIntSet.h"
#include "menuFunctions.h"

static void createDoubleLinkedList(DoubleLinkedList** list) {
    // allocate memory using malloc
    *list = malloc(sizeof(DoubleLinkedList));
    if (*list == NULL) {
        // Handle memory allocation failure
        printf("Error: Memory allocation failed\n");
        return;
    }

    // allocate memory for head and tail using malloc
    (*list)->head = malloc(sizeof(Node));
    if ((*list)->head == NULL) {
        // Handle memory allocation failure
        printf("Error: Memory allocation failed.\n");
        free(*list); // Don't forget to free the previously allocated memory
        return;
    }

    (*list)->tail = malloc(sizeof(Node));
    if ((*list)->tail == NULL) {
        // Handle memory allocation failure
        printf("Error: Memory allocation failed.\n");
        free((*list)->head); // Don't forget to free the previously allocated memory
        free(*list); // Don't forget to free the previously allocated memory
        return;
    }
}
//IMPLEMENTATION IN MAIN
//int main() {
//    DoubleLinkedList* list;
//    createDoubleLinkedList(&list);
//    // list is now an empty double linked list
//    return 0;
//}

void deleteDoubleLinkedList(DoubleLinkedList** list) {
    // check if list is NULL
    // if true print error message
    if (*list == NULL) {
        printf("Error: List is already deleted or does not exist.\n");
        return;
    }
    // delete all nodes in list
    // itereate through list
    // store next pointer in temporary variable next
	// free current node, free
	// move to next node
    Node* current = (*list)->head;
    while (current != (*list)->tail) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    // free tail
    // free list
    free((*list)->tail);
    free(*list);
    // set list ptr to NULL
    *list = NULL;
}
//IMPLEMENTATION IN MAIN
//int main() {
//    DoubleLinkedList* list;
//    createDoubleLinkedList(&list);
//    // ... add nodes to the list ...
//    deleteDoubleLinkedList(&list);
//    return 0;
//}

int getData(DoubleLinkedList* list) {
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        return -1; // Return an error value
    }
    return list->current->data;
}

void gotoNextNode(DoubleLinkedList* list) {
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        return;
    }
    if (list->current != list->tail) {
        list->current = list->current->next;
    }
}

void gotoPreviousNode(DoubleLinkedList* list) {
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        return;
    }
    if (list->current != list->head) {
        list->current = list->current->prev;
    }
}

void gotoHead(DoubleLinkedList* list) {
    if (list == NULL) {
        printf("Error: List does not exist.\n");
        return;
    }
    list->current = list->head;
}

void gotoTail(DoubleLinkedList* list) {
    if (list == NULL) {
        printf("Error: List does not exist.\n");
        return;
    }
    list->current = list->tail;
}

void insertAfter(DoubleLinkedList* list, int newdata) {
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        return;
    }
    if (list->current == list->tail) {
        printf("Error: Cannot insert after tail node.\n");
        return;
    }

    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    new_node->data = newdata;
    new_node->prev = list->current;
    new_node->next = list->current->next;
    list->current->next->prev = new_node;
    list->current->next = new_node;
}

void insertBefore(DoubleLinkedList* list, int newdata) {
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        return;
    }
    if (list->current == list->head) {
        printf("Error: Cannot insert before head node.\n");
        return;
    }

    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    new_node->data = newdata;
    new_node->prev = list->current->prev;
    new_node->next = list->current;
    list->current->prev->next = new_node;
    list->current->prev = new_node;
}

void deleteCurrent(DoubleLinkedList* list) {
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        return;
    }
    if (list->current == list->head || list->current == list->tail) {
        printf("Error: Cannot delete head or tail node.\n");
        return;
    }

    Node* temp = list->current;
    list->current->prev->next = list->current->next;
    list->current->next->prev = list->current->prev;
    list->current = list->current->next;
    free(temp);
}
