/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : Employee.h
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar       Date    5/25/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    void sort();
    bool load();
    void display();
    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_