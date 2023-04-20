// Final Project Milestone 1
// Student POS App Mockup tester
// Version 1.0
// Date	2023-02-28
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the PosApp class
// for submission.
//
// Name : Neron Parmar       Student ID : 171690217
// 
// File : PosApp.h
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cstring>

namespace sdds {
    const int MAX_FILENAME = 255;
    class PosApp {
        char m_fileName[MAX_FILENAME]{};
    public:
        void menu();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void POS();
        void saveRecs();
        void loadRecs();

        PosApp(const char* fileName);
        void run();
    };
}

#endif