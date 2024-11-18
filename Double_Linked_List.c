///////////////////Double Linked Lists////////////////////////
//createDoubleLinkedList() : Creates a new empty double linked list, consisting
//only of head and tail
//Pre : None
//Post : Empty double linked list is created.
//deleteDoubleLinkedList() : Deletes a list(including all its elements).
//Pre : valid double linked list exists.
//Post : The entire list is deleted.
//getData() : Returns the data associated with current node.
//Pre : valid double linked list exists.
//Post : data of current node is returned
//gotoNextNode() : Sets current node to the successor of current.
//Pre : valid double linked lists exists.
//Post : if current node is other than tail, current node is set to successor of
//current node.Otherwise, list remains unchanged.
//Page 1 of 6
//CE4703 Assignment 2
//gotoPreviousNode() : Sets current node to the predeccessor of current.
//Pre : valid double linked lists exists.
//Post : if current node is other than head, current node is set set to predeccessor of current node.Otherwise, list remains unchanged.
//gotoHead() : Sets current node to head.
//Pre : valid double linked lists exists.
//Post : current node is set to head
//gotoTail() : Sets current node to tail.
//Pre : valid double linked lists exists
//Post : current node is set to tail
//insertAfter(newdata) : Creates a new node, associates newdata with it and
//inserts it after the current node.
//Pre : valid double linked lists exists and newdata is valid data.
//Post : If current node is not tail, new node is inserted after current node.
//Otherwise list remains unchanged and an error is returned.
//insertBefore(newdata) : Creates a new node, associates newdata with it and
//inserts it before the current node.
//Pre : valid double linked lists exists and newdata is valid data.
//Post : If current node is not head, new node is inserted before current node.
//Otherwise list remains unchanged and an error is returned ⇒
//deleteCurrent() : Deletes the current node from list.
//Pre : valid double linked list exists.
//Post : If current node is other than head or tail, the current node is removed
//from list.Otherwise, an error is returned.
//Define suitable data type(s) for a double linked list and implement the outlined
//operations.
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoubleLinkedList;

void createDoubleLinkedList(DoubleLinkedList** list) {
    // allocate memory using malloc
    *list = malloc(sizeof(DoubleLinkedList));
    // allocate memory for head and tail using malloc
    (*list)->head = malloc(sizeof(Node));
    (*list)->tail = malloc(sizeof(Node));

    // initialize head -> prev to NULL & next to tail
    (*list)->head->prev = NULL;
    (*list)->head->next = (*list)->tail;
    // set data field to dummy value
    (*list)->head->data = 0; 

    // initialize tail -> prev to head & next to NULL
    (*list)->tail->prev = (*list)->head;
    (*list)->tail->next = NULL;
    // set data field to dummy value
    (*list)->tail->data = 0; 
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


