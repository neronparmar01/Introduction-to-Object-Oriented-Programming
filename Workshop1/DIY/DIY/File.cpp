// Workshop 1 p2: tester program
//
// File  File.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar         Date  1/24/23          Reason
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
using namespace std;
using namespace sdds;

namespace sdds
{

    FILE* file = NULL;

    int fileopen(const char* fname)
    {
        file = fopen(fname, "r");
        return file != NULL;
    }

    void fileclose()
    {
        if (file)
        {
            fclose(file);
        }
    }
    int stu_nam(char name[])
    {

        return fscanf(file, "%[^,],", name) == 1;
    }
    int stu_num(int* num)
    {

        return fscanf(file, "%d,", num) == 1;
    }
    int stu_GPA(double* gpa)
    {

        return fscanf(file, "%lf\n", gpa) == 1;
    }

}