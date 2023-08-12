/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : File.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar       Date    5/25/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring> 
#include "File.h"
#include "Employee.h" 

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    bool read(Employee& emp) {
        int res = fscanf(fptr, "%d,%lf,", &emp.m_empNo, &emp.m_salary);
        if (res == 2) {
            char name[128];
            fgets(name, 128, fptr);
            int len = strlen(name);
            emp.m_name = new char[len + 1];
            strcpy(emp.m_name, name);
            emp.m_name[len - 1] = '\0';
            return true;
        }
        return false;
    }
}
