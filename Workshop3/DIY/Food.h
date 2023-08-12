/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
// professor's tester program
//
//	File : Food.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   6/4/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds {
    class Food {
        char m_name[31];
        int m_calories;
        int m_time;

        // member function
        void setEmpty();

    public:
        void setCalories(const char* name, int calories, int when);
        bool isValid() const;
        void display() const;
        int getCalories() const;
    };
}

#endif // !SDDS_FOOD_H
