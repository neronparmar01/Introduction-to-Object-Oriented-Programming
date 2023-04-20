// Final Project Milestone 2
// Student Logical operator Tester program
// Version 1.0
// Date	2023-02-27
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
// Name : Neron Parmar               Student ID : 171690217
// File : Date.h
/////////////////////////////////////////////////////////////////

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__

#include <bits/stdc++.h>    // includes all the library

using namespace std;

namespace sdds
{
    class Date
    {
    public:
        int year;
        int month;
        int day;
        int hour;
        int minute;

        Date(int year, int month, int day, int hour, int minute);
        Date();
        int getYear();
        int getMonth();
        int getDay();
        int getHour();


        int getMinute();
        void setYear(int year);

        void setMonth(int month);

        void setDay(int day);

        void setHour(int hour);
        void setMinute(int minute);
        void printDate();
        friend ostream& operator<<(ostream& output, const Date& D);
        Date(int year, int month, int day);
        friend istream& operator>>(istream& input, Date& D);
        void dateOnly(bool value);
        Date(int year, int month, int day, int hour);
        bool operator==(const Date& D);
        bool operator>=(const Date& D);
        bool operator<=(const Date& D);
        bool operator!=(const Date& D);

        bool operator<(const Date& D);

        bool operator>(const Date& D);
        bool operator!();
        const char* error() const;
    };
}

#endif