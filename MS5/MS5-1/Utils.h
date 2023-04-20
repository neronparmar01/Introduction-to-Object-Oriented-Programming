// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : Utils.h
// Name : Neron Parmar     Student ID : 171690217     Date : 4/16/23
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
namespace sdds {
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int min);
    int daysOfMonth(int year, int month);
}
#endif //!SDDS_UTILS_H_