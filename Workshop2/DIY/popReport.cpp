/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : popReport.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar      Date    5/27/23     Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Population.h"
using namespace sdds;
int main() {
   if (load("PCpopulations.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}