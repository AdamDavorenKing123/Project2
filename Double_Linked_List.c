///////////////////Double Linked Lists////////////////////////

#include <stdlib.h>
#include <stdio.h>
typedef enum {
    ok,
    illegalNode,
    noMemory
}Dllerror;

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    Node* current;
} DoubleLinkedList;

Dllerror  createDoubleLinkedList(DoubleLinkedList* list) {
    // allocate memory using malloc
    Dllerror result = ok; 
    list = malloc(sizeof(DoubleLinkedList));
    if (list == NULL) {
        // Handle memory allocation failure
        printf("Error: Memory allocation failed.\n");
        result=noMemory;
    }
    else {
        // allocate memory for head and tail using malloc
        list->head = malloc(sizeof(Node));
        if (list->head == NULL) {
            // Handle memory allocation failure
            printf("Error: Memory allocation failed.\n");
            free(list); // Don't forget to free the previously allocated memory
            result= noMemory;
        }
        else {
            list->tail = malloc(sizeof(Node));
            if (list->tail == NULL) {
                // Handle memory allocation failure
                printf("Error: Memory allocation failed.\n");
                free(list->head); // Don't forget to free the previously allocated memory
                free(list); // Don't forget to free the previously allocated memory
                result= noMemory;
            }
            else {
                list->head->next = list->tail;// enure list head points next to list tail
                list->tail->prev = list->head;// ensure list tail points prev to head
                list->head->prev = NULL;// ensure list head prev points to null 
                list->tail->next = NULL;// ensure list tail next points to null
                list->current = list->head;// make the head the current node 
            }
        }
    }
    return result;
}
//IMPLEMENTATION IN MAIN
//int main() {
//    DoubleLinkedList* list;
//    createDoubleLinkedList(&list);
//    // list is now an empty double linked list
//    return 0;
//}

Dllerror deleteDoubleLinkedList(DoubleLinkedList* list) {
    // check if list is NULL
    // if true print error message
    Dllerror result = ok;
    if (list == NULL) {
        printf("Error: List is already deleted or does not exist.\n");
        result = noMemory;
    }
    else {
        // delete all nodes in list
        // itereate through list
        // store next pointer in temporary variable next
        // free current node, free
        // move to next node
        gotoHead(list);
        gotoNextNode(list);
        while (deleteCurrent(list) == ok) {
            deleteCurrent(list);
        }
        // free tail
        // free list
        free(list->tail);
        free(list->head);
        free(list);
        
        // set list ptr to NULL
        list = NULL;
    }
    return result;
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
    else {
        return list->current->data;
    }
}

Dllerror gotoNextNode(DoubleLinkedList* list) {
    Dllerror result = ok;
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        result= noMemory;
    }
    else {
        if (list->current != list->tail) {
            list->current = list->current->next;
        }
    }
    return result;
}

Dllerror gotoPreviousNode(DoubleLinkedList* list) {
    Dllerror result = ok;
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        result = noMemory;
    }
    else {
        if (list->current == list->head) {
            result = illegalNode;
        }
        else {
            list->current = list->head;
        }
    }
    return result;
}

Dllerror gotoHead(DoubleLinkedList* list) {
    Dllerror result = ok;
    if (list == NULL) {
        printf("Error: List does not exist.\n");
        result = noMemory;
    }
    else {
        list->current = list->head;
    }
    return result;
}

Dllerror gotoTail(DoubleLinkedList* list) {
    Dllerror result = ok;
    if (list == NULL) {
        printf("Error: List does not exist.\n");
        result = noMemory;
    }
    else {
        list->current = list->tail;
    }
    return result;
}

Dllerror insertAfter(DoubleLinkedList* list, int newdata) {
    Dllerror result = ok;
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        result = noMemory;
    }
    else {
        if (list->current == list->tail) {
            printf("Error: Cannot insert after tail node.\n");
            result = illegalNode;
        }
        else {

            Node* new_node = malloc(sizeof(Node));
            if (new_node == NULL) {
                printf("Error: Memory allocation failed.\n");
                result = illegalNode;
            }
            else {

                new_node->data = newdata;
                new_node->prev = list->current;
                new_node->next = list->current->next;
                list->current->next->prev = new_node;
                list->current->next = new_node;
            }
        }
    }
    return result;
}

Dllerror insertBefore(DoubleLinkedList* list, int newdata) {
    Dllerror result = ok;
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        result = noMemory;
    }
    else {
        if (list->current == list->head) {
            printf("Error: Cannot insert before head node.\n");
            result = noMemory;
        }
        else {

            Node* new_node = malloc(sizeof(Node));
            if (new_node == NULL) {
                printf("Error: Memory allocation failed.\n");
                result = noMemory;
            }
            else {
                new_node->data = newdata;
                new_node->prev = list->current->prev;
                new_node->next = list->current;
                list->current->prev->next = new_node;
                list->current->prev = new_node;
            }
        }
    }
    return result; 
}

Dllerror deleteCurrent(DoubleLinkedList* list) {
    Dllerror result = ok; 
    if (list == NULL || list->current == NULL) {
        printf("Error: List is empty or does not exist.\n");
        result= noMemory;
    }
    else {
        if (list->current == list->head || list->current == list->tail) {
            printf("Error: Cannot delete head or tail node.\n");
            result = illegalNode;
        }
        else {
            Node* temp = list->current;
            list->current->prev->next = list->current->next;
            list->current->next->prev = list->current->prev;
            list->current = list->current->next;
            free(temp);
        }
    }
    return result;
}

