/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
// tester program
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
// and the comments stated in the main function
//
// File : Employee.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/7/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "ReadWrite.h"
namespace sdds {
    class Employee : public ReadWrite {
        int m_empno;
        int m_office;
        char m_name[41];
        double m_salary;
    public:
        Employee();
        Employee(int stno, const char* name, double salary, int office);
        void set(int stno, const char* name, double salary, int office);
        std::ostream& display(std::ostream& os)const;
        std::istream& read(std::istream& is);
        bool operator==(int office)const;
    };


}
#endif // !SDDS_EMPLOYEE_H_