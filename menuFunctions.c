/**
* @file menuFunctions.c
* @brief This file contains all the menu functions for our menu-driven interface for our program to work.
*
* @authors Adam Davoren King, Andrew Reel, Charlie Brady, Ciaran Knowles, Joey Clancy, Ruairi Seery
* @version 1.0
*/

#include "dataTypeOrderedIntSet.h"
#include "menuFunctions.h"

/**
 * @brief    Add an element to a set: Prompts the user to add elements from an ordered set, stopping on a negative input, with the updated set being printed once amended.
 *
 * @param	 index  This is the index for the set which the element that is to be added is from.
 * @return   N/a (this is a void function)
 */
void addElementMenu(orderedIntSet* s) {
	int ElemToBeAdded;
	printf("Please enter element (enter value <0 to stop):");
	scanf_s("%d", &ElemToBeAdded);
	while (ElemToBeAdded > 0) {
		addElement(s, ElemToBeAdded);
		scanf_s("%d", &ElemToBeAdded);
	}
	return;
}

/**
 * @brief    Remove an element from a set: Prompts the user to remove elements from an ordered set, stopping on a negative input, with the updated set being printed once amended.
 *
 * @param	 index  This is the index for the set which the element that is to be removed is from.
 * @return   N/a (this is a void function)
 */

void removeElementMenu(int index) {

}

/**
 * @brief    Find the intersection of two sets: Computes the intersection of two sets, stores the result in a third set, and prints out the resulting set.
 *
 * @param	 i_1  This is the index for the first set.
 * @param	 i_2  This is the index for the second set.
 * @param	 i_3  This is the index for the third set.
 * @return   N/a (this is a void function)
 */

void setIntersectionMenu(int i_1, int i_2, int i_3) {

}

/**
 * @brief    Find the union of two sets: Computes the union of two sets, stores the result in a third set, and prints out the resulting set.
 *
 * @param	 i_1  This is the index for the first set.
 * @param	 i_2  This is the index for the second set.
 * @param	 i_3  This is the index for the third set.
 * @return   N/a (this is a void function)
 */

void setUnionMenu(int i_1, int i_2, int i_3) {


}

/**
 * @brief    Find the difference between two sets: Computes the difference of two sets, stores the result in a third set, and prints out the resulting set.
 *
 * @param	 i_1  This is the index for the first set.
 * @param	 i_2  This is the index for the second set.
 * @param	 i_3  This is the index for the third set.
 * @return   N/a (this is a void function)
 */

void setDifferenceMenu(int i_1, int i_2, int i_3) {

}