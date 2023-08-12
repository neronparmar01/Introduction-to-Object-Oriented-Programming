/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : File.h
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar       Date    5/25/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "Employee.h"
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(Employee& emp);

}
#endif // !SDDS_FILE_H_