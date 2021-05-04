#ifndef MAIN_HEADER_H_
#define MAIN_HEADER_H_

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


/*****************************************************************************
 *
 * FUNCTION PrintHeader
 *
 ____________________________________________________________________________
 * This function passes in parameters for cout, the name of the programmer,
 * their student id, the class name, the assignment number, and the assignment
 * name from the main function and outputs the class heading to either the
 * output file or the console depending on what is called by using ostream.
 *___________________________________________________________________________
 * PRE-CONDITIONS:
 *	cout:	Allows output to the console
 * CONSTANTS:
 *	PROGRAMMER: Previously defined
 *	STUDENT_ID: Previously defined
 *	CLASS:		Previously defined
 *	SECTION:	Previously defined
 *	LAB_NUM:	Previously defined
 *	LAB_NAME:	Previously defined
 ******************************************************************************/
void PrintHeader()
{
	// CLASS HEADER CONSTANTS
	const char PROGRAMMER[50] = "Alan Vuong, Caleb Yun, Ethan Bockler";
	const char CLASS[5] = "CS1D";
	const int ASSIGN_NUMBER = 14;
	const char ASSIGN_NAME[30] = "Dijkstra and MST";

	cout << left;
	cout << "*******************************************************";
	cout << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n*  " << setw(14) << left << "CLASS" << ": " << CLASS;
	cout << "\n*  ASSIGN #" << left << setw(6) << ASSIGN_NUMBER << ": " << ASSIGN_NAME;
	cout << "\n*******************************************************\n\n";
	cout << right;
}

#endif