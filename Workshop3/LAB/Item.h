/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1
// Version 1.0
// Description
// tester program
//
// File : Item.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar    Date    6/1/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Item {

        // private variables and functions

        char m_itemName[21];
        double m_price;
        bool m_taxed;
        void setName(const char* name);

        // public functions

    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display()const;
        bool isValid()const;
        double price()const;
        double tax()const;
    };
}

#endif // !SDDS_SUBJECT_H