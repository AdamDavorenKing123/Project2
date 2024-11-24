/**
* @file main.c
* @brief This file contains the main function for which our user will be provided with 8 options to carry out, encompassing a variety of set operations.
*
* Such operations include set creation, deletion, adding/removing elements from a set, and set theory operations (intersection, union, and difference).
*
* @authors Adam Davoren King, Andrew Reel, Charlie Brady, Ciaran Knowles, Joey Clancy, Ruairi Seery
* @version 1.0
*/

#include "dataTypeOrderedIntSet.h"
#include "doubleLinkedList.h"
#include "menuFunctions.h"


/**
 * @brief    Get a valid index: Prompts the user to enter an index and checks if it is valid.
 *
 * @param	 N/a
 * @return   Returns a valid int index.
 */

//Simplified code by creating a function that takes in user input and checks if it is valid, which can be reused throughout the main() function.
int static getValidIndex() {
	int index;
	do {
		scanf_s("%d", &index);
		if (index < 0 || index >= 10) {
			printf("Invalid index - please enter only values 0 - 9\n");
			printf("Try again\n\n");
		}
	} while (index < 0 || index >= 10);
	return index;
}

int main() {
	int choice;
	int index = 0; ///< Initalising the variable for the index to be zero.
	int i_1 = 0; ///< Initalising the variable for the index 1 to be zero.
	int i_2 = 0; ///< Initalising the variable for the index 2 to be zero.
	int i_3 = 0; ///< Initalising the variable for the index 3 to be zero.

	orderedIntSet* SetsArray[10] = { NULL }; ///< Declaring an array to hold 10 ordered sets.

	while (1) {
		printf("\nChoose from the following:\n");
		printf("1) Create empty ordered set\n");
		printf("2) Delete ordered set\n");
		printf("3) Add element to ordered set\n");
		printf("4) Remove element from ordered set\n");
		printf("5) Set intersection\n");
		printf("6) Set union\n");
		printf("7) Set difference\n");
		printf("8) Terminate program\n");

		printf("Your choice: ");
		
		//Safeguard to ensure only valid input is recieved.
		while (scanf_s("%d", &choice) !=1) {
			printf("Error: Invalid input\n");
			printf("Please enter a valid integer\n");}
			while(getchar() != '\n'); ///< Clears the input buffer if invalid input is recieved.

		switch (choice) {
		case 1:
			printf("Please enter index (0 - 9) for set to be created:  \n\n ");
			index = getValidIndex();
			SetsArray[index] = createOrderedSet(); ///< Calls the function to create a set
			printf("Set at index %d created \n\n", index);
			break;

		case 2:
			printf("Please enter index (0 - 9) for set to be deleted:  \n\n");
			index = getValidIndex();
			deleteOrderedSet(index); ///< Calls the function to delete a set.
			printf("Set at index %d deleted \n\n", index);
			break;

		case 3:
			printf("Please enter index (0 - 9) for set to add elements to:  \n\n");
			index = getValidIndex();
			addElementMenu(index); ///< Calls the relevant menu function to add an element to a set.
			break;

		case 4:
			printf("Please enter index (0 - 9) for set to remove elements from: \n\n");
			index = getValidIndex();
			removeElementMenu(index); ///< Calls the relevant menu function to remove an element from a set.
			break;

		case 5:
			printf("Please enter three indices: two for sets to form intersection of and one for the target set: \n\n");
			i_1 = getValidIndex();
			i_2 = getValidIndex();
			i_3 = getValidIndex();
			setIntersectionMenu(i_1, i_2, i_3); ///< Calls the relevant menu function to find the intersection of three sets based of the inputted 3 indices.
			break;

		case 6:
			printf("Please enter three indices: two for sets to form union of and one for the target set: \n\n");
			i_1 = getValidIndex();
			i_2 = getValidIndex();
			i_3 = getValidIndex();
			setUnionMenu(i_1, i_2, i_3); ///< Calls the relevant menu function to find the union of three sets based of the inputted 3 indices.
			break;

		case 7:
			printf("Please enter three indices: two for sets to form difference of and one for the target set: \n\n");
			i_1 = getValidIndex();
			i_2 = getValidIndex();
			i_3 = getValidIndex();
			setDifferenceMenu(i_1, i_2, i_3); ///< Calls the relevant menu function to find the difference of three sets based of the inputted 3 indices.
			break;

		case 8:
			printf("Program terminated.\n");

			return 0;

		//If invalid integer input is recieved, return error message and get user to try again.
		default:
			printf("Illegal Input - please enter only values 1 - 8\n");
			printf("Try again\n\n");
		}
	}

	return 0;
}



