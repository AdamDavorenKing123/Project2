#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

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
    Node* current;
} DoubleLinkedList;

// Function to create a double linked list
static void createDoubleLinkedList(DoubleLinkedList** list);

// Function to delete a double linked list
void deleteDoubleLinkedList(DoubleLinkedList** list);

// Function to get the data from the current node
int getData(DoubleLinkedList* list);

// Function to move to the next node in the list
void gotoNextNode(DoubleLinkedList* list);

// Function to move to the previous node in the list
void gotoPreviousNode(DoubleLinkedList* list);

// Function to move to the head node
void gotoHead(DoubleLinkedList* list);

// Function to move to the tail node
void gotoTail(DoubleLinkedList* list);

// Function to insert a new node after the current node
void insertAfter(DoubleLinkedList* list, int newdata);

// Function to insert a new node before the current node
void insertBefore(DoubleLinkedList* list, int newdata);

// Function to delete the current node
void deleteCurrent(DoubleLinkedList* list);

#endif // DOUBLE_LINKED_LIST_H
