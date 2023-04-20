// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : PosApp.h
// Name : Neron Parmar     Student ID : 171690217     Date : 4/16/23
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include "Item.h"

namespace sdds {
    class PosApp {
    public:
        PosApp(const char* fileName);
        ~PosApp();
        void run();

    private:
        PosApp(const PosApp&); // privatize copy constructor to prevent copy construction
        PosApp& operator=(const PosApp&); // privatize assignement operator to prevent assignement
        int menu() const;
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void POS();
        void saveRecs() const;
        void loadRecs();
        void printActionTitle(const char* str) const;
        char m_FileName[128 + 1]; // MAX LENGTH + 1 for NULL
        Item* m_Iptr[MAX_NO_ITEMS];
        int m_nptr;
    };
}
#endif // !SDDS_POSAPP_H_