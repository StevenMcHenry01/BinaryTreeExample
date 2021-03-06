// Chapter21Program.cpp : Defines the entry point for the console application.
/*
*
* Steven McHenry
*
* Chapter 22 programming assignment
*
* May 20, 2018
*
*/

#include "stdafx.h"
#include <iostream> // for cout and cin
#include <iomanip> // for output formatting
#include "IntBinaryTree.h"
using namespace std;

//Function Prototypes
void displayMenu();
void readInput(int*);
int validateInt();

int main()
{
	// Constants for menu choices
	const int INSERT_CHOICE = 1,
		DISPLAY_TREE_CHOICE = 2,
		DISPLAY_LEAF_CHOICE = 3,
		DISPLAY_HEIGHT_CHOICE = 4,
		DISPLAY_WIDTH_CHOICE = 5,
		EXIT_CHOICE = 6;

	//Create new Binary tree object
	IntBinaryTree tree;

	// user input
	int userInput = -1;
	// input pointer
	int* inputPointer = &userInput;

	// hold new int
	int newInt = NULL;

	while (userInput != 6)
	{
		displayMenu();
		// read user input
		readInput(inputPointer);
		// handle input with switch
		switch (userInput)
		{
		case INSERT_CHOICE:
			cout << " Please enter an integer to add to the tree: ";
			// HIGH LEVEL validity check
			newInt = validateInt();
			// insert number into tree
			tree.insertNode(newInt);
			break;
		case DISPLAY_TREE_CHOICE:
			// display entire tree (In order)
			tree.displayInOrder();
			break;
		case DISPLAY_LEAF_CHOICE:
			// display leaf count
			cout << endl << " There are " << tree.getLeafCount() << 
				" leaves in this tree. " << endl;
			break;
		case DISPLAY_HEIGHT_CHOICE:
			// display tree height
			cout << endl << " This tree is " << tree.getTreeHeight() << 
				" levels high." << endl;
			break;
		case DISPLAY_WIDTH_CHOICE:
			// display tree width
			cout << endl << " This tree is " << tree.getTreeWidth() << 
				" nodes wide." << endl;
			break;
		case EXIT_CHOICE:
			cout << endl << " Goodbye, and thank you!" << endl << endl << endl;
			break;
		default: //check for incorrect menu choice
			cout << endl << " ERROR - Number must be within (1-6)";
		}
	} // end While

    return 0;
}

//*******************************************************************
// name: displayMenu
// Called By: main
// passed: none
// returns: none
// calls: none
// Description: displays the menu of choices
//*******************************************************************
void displayMenu()
{
	// Display the menu.
	cout << endl << " *************************" << endl;
	cout << " Binary Tree Menu!" << endl;
	cout << " *************************" << endl << endl;
	cout << " 1. Insert Number" << endl;
	cout << " 2. Display Tree" << endl;
	cout << " 3. Display Leaf Count" << endl;
	cout << " 4. Display Tree Height" << endl;
	cout << " 5. Display Tree Width" << endl;
	cout << " 6. Exit Program" << endl << endl;
}

//*******************************************************************
// name: readInput
// Called By: main
// passed: int*
// returns: none
// calls: none
// Description: reads user menu choice input and validates that it is
// an integer and between 1-6
//*******************************************************************
void readInput(int* point)
{
	do {
		cout << " Please enter your choice" << endl;
		cout << " (1, 2, 3, 4, 5, or to exit enter 6): ";
		// read input
		cin >> *point;
		// if fails
		if (cin.fail())
		{
			cin.clear(); // clears error flags
			cin.ignore(999, '\n'); // the first parameter is just some 
								   //arbitrarily large value, the second param 
								   //being the character to ignore till
			cout << endl << " ERROR - Please enter an integer" << endl;
		}
		else if (*point <= 0 || *point > 6)
		{
			cout << endl << " ERROR - Please enter an integer between 1-6" << endl;
		}
	} while (*point <= 0 || *point > 6);
}

//*******************************************************************
// name: validateInt
// Called By: main
// passed: none
// returns: int
// calls: none
// Description: Checks for valid int to add to tree
//*******************************************************************
int validateInt()
{
	int newInt;
	cin >> newInt;
	while (!cin)
	{
		cout << endl << " ERROR - Please enter a valid Integer: ";
		cin.clear();
		cin.ignore();
		cin >> newInt;
	}

	return newInt;
}