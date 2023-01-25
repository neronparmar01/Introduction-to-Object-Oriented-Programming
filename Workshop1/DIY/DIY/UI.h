// Workshop 1 p2: tester program
//
// File  UI.h
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar         Date  1/24/23          Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UI_H
#define SDDS_UI_H

namespace sdds
{
    void funcMain(void);
    void inpt(const struct GPA* STUD);
    int outp(const char character, const double score, const struct GPA* STUD);
}

#endif