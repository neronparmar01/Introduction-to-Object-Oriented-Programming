/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Toys.h
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


#define MAX_TNAME 31    // maximum length of a toy name
namespace sdds
{
    // Toys class and the variables 
    class Toys
    {
        char m_tname[MAX_TNAME];  // name of the toys
        int m_sku;
        double m_price;
        int m_age;
        bool m_onSale = false;
    public:
        void calSale();
        void display() const;
        int getSku() const;
        void addToys(const char* tname, int sku, double price, int age);
        void isSale(bool sale);

    };

}