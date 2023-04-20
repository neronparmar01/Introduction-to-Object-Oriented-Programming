// Final Project
// Milestone 4
// Perishable and NonPerishable Tester
// Version 1.0
// Date	2023-03-29
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of Milestone 4
// for submission.
//
// 
// Name : Neron Parmar      StudentID : 171690217
// File : Date.h
/////////////////////////////////////////////////////////////////

#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
#include "Error.h"

namespace sdds {
    class Date {
    public:
        Date();
        Date(int year, int month, int day);
        Date(int year, int month, int day, int hour, int minute = 0);
        Date& dateOnly(bool val);
        const Error& error() const {
            return m_error;
        }
        void display(std::ostream& out) const;
        void read(std::istream& in);

        operator bool() const;

        bool operator<(const Date& d) const;
        bool operator>(const Date& d) const;
        bool operator<=(const Date& d) const;
        bool operator>=(const Date& d) const;

        bool operator==(const Date& d) const;
        bool operator!=(const Date& d) const;

    private:
        bool validate();

        int m_year;
        int m_month;
        int m_day;
        int m_hour;
        int m_minute;
        bool m_onlyDate;
        Error m_error;
    };

    std::ostream& operator<<(std::ostream& out, const Date& date);
    std::istream& operator>>(std::istream& in, Date& date);
}
#endif //!SDDS_DATE_H_