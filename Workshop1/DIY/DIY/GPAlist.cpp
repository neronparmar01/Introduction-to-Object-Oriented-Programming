// Workshop 1 p2: tester program
//
// File  GPAlist.cpp
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
#include "GPAlist.h"
#include "UI.h"
#include "File.h"
using namespace std;
using namespace sdds;

namespace sdds
{
    bool gpaQuery(const char* filename)
    {
        bool done = fileopen(filename);
        fileclose();
        if (done)
        {
            funcMain();
        }
        return done ? true : false;
    }
}
