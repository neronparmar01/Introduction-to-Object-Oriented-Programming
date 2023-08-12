/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : Employee.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar       Date    5/25/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

	int noOfEmployees;
	Employee* employees;


	void sort()
	{
		int i, j;
		Employee temp;
		for (i = 0; i < noOfEmployees - 1; i++) {
			for (j = i + 1; j < noOfEmployees; j++) {
				if (employees[i].m_empNo > employees[j].m_empNo) {
					temp = employees[i];
					employees[i] = employees[j];
					employees[j] = temp;
				}
			}
		}
	}



	bool load()
	{
		bool ok = false;
		int i = 0;
		if (openFile(DATAFILE)) {
			noOfEmployees = noOfRecords();
			employees = new Employee[noOfEmployees];
			while (i < noOfEmployees && read(employees[i])) {
				i++;
			}
			if (i == noOfEmployees) {
				ok = true;
				sort(); // Call the sort function after loading the data
			}
			else {
				cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
			}
			closeFile();
		}
		else {
			cout << "Could not open data file: " << DATAFILE << endl;
		}
		return ok;
	}



	void display()
	{
		cout << "Employee Salary report, sorted by employee number" << endl;
		cout << "no- Empno, Name, Salary" << endl;
		cout << "------------------------------------------------" << endl;
		for (int i = 0; i < noOfEmployees; i++) {
			cout << i + 1 << "- " << employees[i].m_empNo << ": " << employees[i].m_name << ", " << employees[i].m_salary << endl;
		}
	}
	void deallocateMemory()
	{
		for (int i = 0; i < noOfEmployees; i++) {
			delete[] employees[i].m_name;
		}
		delete[] employees;
	}
}