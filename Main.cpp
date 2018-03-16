/// An interactive test program template

// File/Project Prolog
// Name: Duncan Reeves
// CS 2420 Section 601
// Project: Binary Search Tree
// Date: 3/15/2018
//
// I declare that the following code was written by me or provided 
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
//
// I Duncan have not used any code other than my own (or that in the textbook) for this project. I also
// have not used any function or data-structure from the Standard-Template Library. I understand that any
// violation of this disclaimer will result in a 0 for the project.

#include <iostream>
#include "BST.h"

using namespace std;

// PROTOTYPES for functions used by this test program:
    // These have already been written for you.

    char get_user_command( );
    // Postcondition: The user has been prompted to enter a one character command.
    // The next character has been read (skipping blanks and newline characters), 
    // and this character has been returned.

    double get_number( );
    // Postcondition: The user has been prompted to enter a real number. The
    // number has been read, echoed to the screen, and returned by the function.

    void print_menu();

int main( )
{
	
    BST myTree = BST();
    char choice;   // A command character entered by the user
    int entry;
    
    cout << "I have initialized an empty sequence of real numbers." << endl;    //?

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
			case 'S': // Get size of BST
                cout << endl << "The tree size is: " << myTree.size() << endl;
                break;

            case 'I': // Insert a node into your BST declared above
                get_number();
			    break;
            
            case 'D': // Delete a node from your BST declared above
                break;

            case 'P': //Print your BST declared above
			    break;
            
            case 'R': // pre-order
                break;

            case 'O': // in-order
			    break;
            
            case 'T': // post-order
                break;
			
			case 'Q': cout << "Ridicule is the best test of truth." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    //Current letters used.  S,I,D,P,R,O,T
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << "Get the size of the tree: [S]" << endl;
    cout << "Insert a node into the tree: [I]" << endl;
    cout << "Delete a node from the tree: [D]" << endl;
    cout << "Print the tree: [P]" << endl;
    cout << "Print while traverseing the tree(Pre-Order): [R]" << endl;
    cout << "Print while traverseing the tree(In-Order): [O]" << endl;
    cout << "Print while traverseing the tree(Post-Order): [T]" << endl;
    //cout << "insert multiple nodes into the tree: [M]" << endl;
	
    //
	// More Choices
	//

    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character
    cout << command << " has been read." << endl;   //I thought this line belonged here, DR

    return command;
}

double get_number( )
// Library facilities used: iostream
{
    double result;
    
    cout << "Please enter a real number for the sequence: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}