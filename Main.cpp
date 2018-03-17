//Fin(real)
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

bool validInput = true;//FIXME, REMOVE WHEN A BETTER SOLUTION IS OBTAINED
                        //To test if numerical input is valid.

// PROTOTYPES for functions used by this test program:
    // These have already been written for you.

    char get_user_command( );
    // Postcondition: The user has been prompted to enter a one character command.
    // The next character has been read (skipping blanks and newline characters), 
    // and this character has been returned.

    int get_number( );  //changed to an int, (see comments in definition).
    // Postcondition: The user has been prompted to enter a real number. The
    // number has been read, echoed to the screen, and returned by the function.

    void print_menu();

int main( )
{
	
    BST myTree = BST();
    char choice;   // A command character entered by the user
    int entry;
    int maxVal;
    
    cout << "I have initialized an empty sequence of real numbers." << endl;    //?

    print_menu( );  //put outside of do-while loop because it was annoying to see it each time. DR
    do
    {
        choice = toupper(get_user_command( ));
        switch (choice)
        {
			case 'S': // Get size of BST
                cout << endl << "The tree size is: " << myTree.size() << endl;
                break;

            case 'I': // Insert a node into your BST declared above
                entry = get_number();
                if(validInput == true)
                {
                    myTree.Insert(entry);
                    cout << endl << "Node added." << endl << endl;
                }
			    break;
            
            case 'D': // Delete a node from your BST declared above
                entry = get_number();
                if(validInput == true)
                {
                    myTree.Erase(entry);
                    cout << endl << "Node Erased." << endl;
                }
                break;

            case 'P': //Print your BST declared above
                myTree.Print();
			    break;
            
            case 'R': // Pre-order
                myTree.Pre_order();
                break;

            case 'O': // In-order
                myTree.In_order();
			    break;
            
            case 'T': // Post-order
                myTree.Post_order();
                break;

            case 'M': // Display max
                cout << "The maximum value in the tree is: " << myTree.getMax() << "." << endl;
			    break;
            
            case 'E': // Delete max
                maxVal = myTree.removeMax();
                cout << "The maximum value in the tree (" << maxVal << "), was removed." << endl;
                break;

            case 'L': // Reprint list
                print_menu();
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
    //Current letters used.  S,I,D,P,R,O,T,M,E,R
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << "Get the size of the tree:---------------------[S]" << endl;
    cout << "Insert a node into the tree:------------------[I]" << endl;
    cout << "Delete a node from the tree:------------------[D]" << endl;
    cout << "Print the tree:-------------------------------[P]" << endl;
    cout << "Print while traverseing the tree(Pre-Order):--[R]" << endl;
    cout << "Print while traverseing the tree(In-Order):---[O]" << endl;
    cout << "Print while traverseing the tree(Post-Order):-[T]" << endl;
    cout << "Display max value of the tree:----------------[M]" << endl;
    cout << "Delete the maximum value from the tree:-------[E]" << endl;
    cout << "Reprint choice list:--------------------------[L]" << endl;
    //cout << "insert multiple nodes into the tree: [M]" << endl;
	
    //
	// More Choices
	//

    cout << " Q   Quit this test program" << endl << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command = ' ';

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character
    cout << command << " has been read." << endl;   //I thought this line belonged here, DR

    return command;
}

int get_number( )   //I changed to an int (from a double) because the instructions said
                    //Insert() and Delete() took int values.   DR
// Library facilities used: iostream
{
    int result;
    
    cout << "Please enter a real number for the sequence: ";
    if(cin  >> result)
    {
        cout << result << " has been read." << endl;
        validInput = true;   //FIXME: Throw exception in stead if I have the time to implement it.
        return result;
    } else
    {
        cout << endl << "Invalid input, input an integer." << endl;
        validInput = false;   //FIXME: Throw exception in stead if I have the time to implement it.
        cin.clear();
        return 0;
    }
}