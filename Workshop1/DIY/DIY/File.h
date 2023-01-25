// Workshop 1 p2: tester program
//
// File  File.h
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar         Date  1/24/23          Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
    int fileopen(const char* fname);
    void fileclose();
    int stu_nam(char name[]);
    int stu_num(int* num);
    int stu_GPA(double* gpa);

}

#endif
