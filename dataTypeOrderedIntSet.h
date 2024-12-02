#ifndef DATA_TYPE_ORDERED_INT_SET_H
#define DATA_TYPE_ORDERED_INT_SET_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	CREATED_SET,///< Set is created
	DELETED_SET,///< Deleted set 
	NUMBER_ADDED, ///< Element added to the set
	NUMBER_ALREADY_IN_SET, ///< Element already exists in the set
	NUMBER_REMOVED, ///< Element removed from the set
	NUMBER_NOT_IN_SET, ///< Element not found in the set
	ALLOCATION_ERROR ///< Memory allocation error
} setReturnValue;

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct orderedIntSet {
	Node* head;
	Node* tail;
	Node* current;
	int count;
} orderedIntSet; 
typedef enum {
	ok,
	illegalNode,
	noMemory
}Dllerror;



typedef struct {
	Node* head;
	Node* tail;
	Node* current;
} DoubleLinkedList;

// Function to create a double linked list
Dllerror createDoubleLinkedList(DoubleLinkedList* list);

// Function to delete a double linked list
Dllerror deleteDoubleLinkedList(DoubleLinkedList* list);

// Function to get the data from the current node
int getData(DoubleLinkedList* list);

// Function to move to the next node in the list
Dllerror gotoNextNode(DoubleLinkedList* list);

// Function to move to the previous node in the list
Dllerror gotoPreviousNode(DoubleLinkedList* list);

// Function to move to the head node
Dllerror gotoHead(DoubleLinkedList* list);

// Function to move to the tail node
Dllerror gotoTail(DoubleLinkedList* list);

// Function to insert a new node after the current node
Dllerror insertAfter(DoubleLinkedList* list, int newdata);

// Function to insert a new node before the current node
Dllerror insertBefore(DoubleLinkedList* list, int newdata);

// Function to delete the current node
Dllerror deleteCurrent(DoubleLinkedList* list);


/**
 * @brief    Create a Set: Prompts the user to create a new ordered set and stores it in SetsArray.
 *
 * @param	 N/a
 *
 * @return   Returns a new empty ordered set
 */

setReturnValue createOrderedSet(orderedIntSet* s);

/**
 * @brief     Delete a set: Deletes an ordered set specified by the user from SetsArray.
 *
 * @param     s  This is the set which is to be deleted.
 *
 * @return    N/a (this is a void function)
 */

setReturnValue deleteOrderedSet(orderedIntSet* s);

/**
 * @brief     Add an element to a set: Prompts the user to add elements to an ordered set, stopping on a negative input.
 *
 * @param     s  This is the set which the element is to be added to.
 * @param     elem  This is the element to be added to the set.
 *
 * @return    N/a (this is a void function)
 */

setReturnValue addElement(orderedIntSet* s, int elem);

/**
 * @brief     Remove an element from a set: Prompts the user to remove elements from an ordered set, stopping on a negative input.
 *
 * @param     s  This is the set which the element is to be removed from.
 * @param     elem  This is the element to be removed from the set.
 *
 * @return    Returns the value NUMBER ADDED if elem has been added to the set or NUMBER ALREADY IN SET if elem is already present in the set.
 */

setReturnValue removeElement(orderedIntSet* s, int elem);

/**
 * @brief     Find the intersection of two sets: Computes the intersection of two sets and stores the result in a third set.
 *
 * @param     s1  This is the first set
 * @param     s2  This is the second set
 *
 * @return    Returns the value NUMBER REMOVED if elem has been in the set or NUMBER NOT IN SET if elem has not been in the set.

 */

orderedIntSet* setIntersection(const orderedIntSet* s1, const orderedIntSet* s2);

/**
 * @brief     Find the union of two sets: Computes the union of two sets and stores the result in a third set.
 *
 * @param     s1  This is the first set
 * @param     s2  This is the second set
 *
 * @return    Returns a new intSet that contains the result of the union of s1 and s2.
 */

orderedIntSet* setUnion(const orderedIntSet* s1, const orderedIntSet* s2);

/**
 * @brief     Find the difference between two sets: Computes the difference of two sets and stores the result in a third set.
 *
 * @param     s1  This is the first set
 * @param     s2  This is the second set
 *
 * @return    Returns a new object of class intSet that contains the result of the difference of s1 and s2.
 */

orderedIntSet* setDifference(const orderedIntSet* s1, const orderedIntSet* s2);

/**
 * @brief     Print the set: Prints the set in format {Num_1, Num_2, Num_3, . . ., Num_n}
 *
 * @param     s  This is the set to be printed.
 *
 * @return    Returns the value ALLOCATION ERROR in all methods if an error from the dynamic data structure prevents inserting new elements.
 */

setReturnValue printToStdout(const orderedIntSet* s);

#endif // DATA_TYPE_ORDERED_INT_SET_H
