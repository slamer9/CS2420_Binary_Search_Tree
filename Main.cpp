// An interactive test program template

//
// Disclamer
//

#include <iostream>
//
// Your #includes
//

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


int main( )
{
	// *****
    // *****   Declare Binary Search Tree here  ***** 
	// *****
    char choice;   // A command character entered by the user
    
    cout << "I have initialized an empty sequence of real numbers." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case 'I': // Insert a node into your BST declared above
					  break;
					  
			//
			//  More choices necessary to test all of your functions
			//
			
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
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << "Insert a node into the tree: " << endl;
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