#ifndef MENU_FUNCTIONS_H
#define MENU_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief    Add an element to a set: Prompts the user to add elements from an ordered set, stopping on a negative input, with the updated set being printed once amended.
 *
 * @param	 index  This is the index for the set which the element that is to be added is from.
 * @return   N/a (this is a void function)
 */

void addElementMenu(int index);

/**
 * @brief    Remove an element from a set: Prompts the user to remove elements from an ordered set, stopping on a negative input, with the updated set being printed once amended.
 *
 * @param	 index  This is the index for the set which the element that is to be removed is from.
 * @return   N/a (this is a void function)
 */

void removeElementMenu(int index);

/**
 * @brief    Find the intersection of two sets: Computes the intersection of two sets, stores the result in a third set, and prints out the resulting set.
 *
 * @param	 i_1  This is the index for the first set.
 * @param	 i_2  This is the index for the second set.
 * @param	 i_3  This is the index for the third set.
 * @return   N/a (this is a void function)
 */

void setIntersectionMenu(int i_1, int i_2, int i_3);

/**
 * @brief    Find the union of two sets: Computes the union of two sets, stores the result in a third set, and prints out the resulting set.
 *
 * @param	 i_1  This is the index for the first set.
 * @param	 i_2  This is the index for the second set.
 * @param	 i_3  This is the index for the third set.
 * @return   N/a (this is a void function)
 */

void setUnionMenu(int i_1, int i_2, int i_3);

/**
 * @brief    Find the difference between two sets: Computes the difference of two sets, stores the result in a third set, and prints out the resulting set.
 *
 * @param	 i_1  This is the index for the first set.
 * @param	 i_2  This is the index for the second set.
 * @param	 i_3  This is the index for the third set.
 * @return   N/a (this is a void function)
 */

void setDifferenceMenu(int i_1, int i_2, int i_3);

#endif // MENU_FUNCTIONS_H
