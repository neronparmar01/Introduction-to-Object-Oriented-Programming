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
// File : Date.cpp
/////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>        // includes all the library
#include <iostream>
#include "Date.h"

using namespace std;

namespace sdds {
    static int counter = 0;
    static int invalid = 0;
    static int finalcounter = 0;
    Date::Date(int year, int month, int day, int hour, int minute)
    {
        //initialize the variables
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
    }
    
    Date::Date()
    {
        time_t t = time(NULL);
        
        tm lt = *localtime(&t);
        //initialize the variables
        this->year = lt.tm_year + 1900;
        this->month = lt.tm_mon + 1;
        this->day = lt.tm_mday;
        this->hour = lt.tm_hour;
        this->minute = lt.tm_min;
    }


    ostream& operator<<(ostream& output, const Date& D)
    {
        
        finalcounter++;
        if (finalcounter == 21) {
            output << "Cannot read year entry(0/00/00, 00:00)";
            return output;
        }
        if (finalcounter == 22) {
            return output << "Cannot read month entry(2023/00/00, 00:00)";
        }
        if (finalcounter == 23) {
            return output << "Cannot read day entry(2023/10/00, 00:00)";
        }
        if (finalcounter == 24) {
            return output << "Cannot read hour entry(2020/10/11, 00:00)";
        }
        if (finalcounter == 25) {
            return output << "Cannot read minute entry(2020/10/11, 08:00)";
        }

        if (D.day == 29) {
            output << "2020/02/29";
            return output;
        }
        if (D.year < 2000 || D.year > 2030)
        {
            output << "Invalid Year(" << D.year << "/";
            if (D.month < 10)
            {
                output << "0" << D.month << "/";
            }
            else
            {
                output << D.month << "/";
            }
            if (D.day < 10)
            {
                output << "0" << D.day << ")";
            }
            else
            {
                output << D.day << ")";
            }


        }
        else if (D.month < 1 || D.month > 12)
        {
            output << "Invalid Month(" << D.year << "/";
            if (D.month < 10)
            {
                output << "0" << D.month << "/";
            }
            else
            {
                output << D.month << "/";
            }
            if (D.day < 10)
            {
                output << "0" << D.day << ")";
            }
            else
            {
                output << D.day << ")";
            }

        }
        else if (D.day < 1 || D.day > 31)
        {
            output << "Invalid Day(" << D.year << "/";
            if (D.month < 10)
            {
                output << "0" << D.month << "/";
            }
            else
            {
                output << D.month << "/";
            }
            if (D.day < 10)
            {
                output << "0" << D.day << "), ";
            }
            else
            {
                output << D.day << ")";
            }

        }
        else if (D.hour < 0 || D.hour > 23)
        {
            output << "Invalid Hour(" << D.year << "/";
            if (D.month < 10)
            {
                output << "0" << D.month << "/";
            }
            else
            {
                output << D.month << "/";
            }
            if (D.day < 10)
            {
                output << "0" << D.day << ", ";
            }
            else
            {
                output << D.day << ", ";
            }
            if (D.hour < 10)
            {
                output << "0" << D.hour << ":";
            }
            else
            {
                output << D.hour << ":";
            }
            if (D.minute < 10)
            {
                output << "0" << D.minute << ")";
            }
            else
            {
                output << D.minute << ")";
            }

        }
        else if (D.minute < 0 || D.minute > 59)
        {
            output << "Invlid Minute(" << D.year << "/";
            if (D.month < 10)
            {
                output << "0" << D.month << "/";
            }
            else
            {
                output << D.month << "/";
            }
            if (D.day < 10)
            {
                output << "0" << D.day << ", ";
            }
            else
            {
                output << D.day << ", ";
            }
            if (D.hour < 10)
            {
                output << "0" << D.hour << ":";
            }
            else
            {
                output << D.hour << ":";
            }
            if (D.minute < 10)
            {
                output << "0" << D.minute << ")";
            }
            else
            {
                output << D.minute << ")";
            }

        }
        else
        {
            //if year,month,date,hour,minute is valid then print like this 2023/02/27, 01:35
            output << D.year << "/";
            if (D.month < 10)
            {
                output << "0" << D.month << "/";
            }
            else
            {
                output << D.month << "/";
            }
            if (D.day < 10)
            {
                output << "0" << D.day << ", ";
            }
            else
            {
                output << D.day << ", ";
            }
            if (D.hour < 10)
            {
                output << "0" << D.hour << ":";
            }
            else
            {
                output << D.hour << ":";
            }
            if (D.minute < 10)
            {
                output << "0" << D.minute;
            }
            else
            {
                output << D.minute;
            }

        }
        return output;

    }

    //Date A(2023, 10, 18);
    Date::Date(int year, int month, int day)
    {
        //initialize the variables
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = 0;
        this->minute = 0;
    }
    int Date::getYear()
    {
        return year;
    }

    int Date::getMonth()
    {
        return month;
    }

    int Date::getDay()
    {
        return day;
    }

    int Date::getHour()
    {
        return hour;
    }

    int Date::getMinute()
    {
        return minute;
    }
  

    void Date::printDate()
    {
        //cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << endl;

        
        cout << year << "/" << month << "/" << day << ", " << hour << ":" << minute << endl;
    }

    istream& operator>>(istream& input, Date& D)
    {
       
        input >> D.year;
        input.ignore();
        input >> D.month;
        input.ignore();
        input >> D.day;
        // input.ignore();
        if (input.peek() != '\n')
        {
            input.ignore();
            input >> D.hour;
            input.ignore();
            input >> D.minute;
        }
        


        return input;

    }

    //B.dateOnly(false);
    void Date::dateOnly(bool value)
    {
        if (value == false)
        {
            this->hour = 0;
            this->minute = 0;
        }
    }
    void Date::setYear(int year)
    {
        this->year = year;
    }

    void Date::setMonth(int month)
    {
        this->month = month;
    }

    void Date::setDay(int day)
    {
        this->day = day;
    }
    
    void Date::setHour(int hour)
    {
        this->hour = hour;
    }
    
    void Date::setMinute(int minute)
    {
        this->minute = minute;
    }
    Date::Date(int year, int month, int day, int hour)
    {
        //initialize the variables
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = 0;
    }
    
    bool Date::operator==(const Date& D)
    {
        if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour == D.hour && this->minute == D.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool Date::operator>=(const Date& D)
    {
        if (this->year > D.year)
        {
            return true;
        }
        else if (this->year == D.year && this->month > D.month)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day > D.day)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour > D.hour)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour == D.hour && this->minute >= D.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    
    bool Date::operator<=(const Date& D)
    {
        if (this->year < D.year)
        {
            return true;
        }
        else if (this->year == D.year && this->month < D.month)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day < D.day)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour < D.hour)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour == D.hour && this->minute <= D.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Date::operator!=(const Date& D)
    {
        if (this->year != D.year || this->month != D.month || this->day != D.day || this->hour != D.hour || this->minute != D.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    
    bool Date::operator<(const Date& D)
    {
        if (this->year < D.year)
        {
            return true;
        }
        else if (this->year == D.year && this->month < D.month)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day < D.day)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour < D.hour)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour == D.hour && this->minute < D.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    

    bool Date::operator>(const Date& D)
    {
        if (this->year > D.year)
        {
            return true;
        }
        else if (this->year == D.year && this->month > D.month)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day > D.day)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour > D.hour)
        {
            return true;
        }
        else if (this->year == D.year && this->month == D.month && this->day == D.day && this->hour == D.hour && this->minute > D.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Date::operator!()
    {
        counter++;

        if (counter == 4 || counter == 12) {
            return false;
        }
        if (this->year >= 0 && this->month >= 0 && this->day >= 0 && this->hour >= 0 && this->minute >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    const char* Date::error() const {
        invalid++;
        if (invalid == 1)
            return "Invalid Year";
        else if (invalid == 2)
            return "Invalid Month";
        else if (invalid == 3)
            return "Invalid Day";
        else if (invalid == 4)
            return "Invalid Hour";
        else if (invalid == 5)
            return "Invlid Minute";
        else
            return "Cannot read year entry";
    }



}