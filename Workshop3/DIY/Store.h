/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Store.h
// Version 1.0
// Date	2022/10/28
// Author Nargis Khan
// Description
// Tests Store module
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Nelson Parmar   Date   2/6/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define MAX_NUM_TOYS 10   // number of the toys that can be added
#define MAX_SNAME 31      // maximum name lenght of the store
#include "Toys.h"

namespace sdds
{
    class Store
    {
        char m_sName[MAX_SNAME] = "\0";
        int m_noOfToys = 0;
        int m_addToys = 0;
        Toys m_toy[MAX_NUM_TOYS];

    public:
        void display() const;
        void find(int sku);
        void setEmpty();    // for the empty state
        void setStore(const char* sName, int no);
        void setToys(const char* tname, int sku, double price, int age);

    };

}
