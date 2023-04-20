// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : Perishable.h
// Name : Neron Parmar    Student ID : 171690217    Date: 4/16/23
/////////////////////////////////////////////////////////////////

#ifndef SDDS_NPERISHABLE_H_
#define SDDS_PERISHABLE_H_
#include <iostream>
#include "Item.h"
#include "Date.h"

namespace sdds {
    class Perishable : public Item {
        Date m_date;
        char itemType() const override {
            return 'P';
        }

        std::ostream& write(std::ostream& os) const override;
        std::istream& read(std::istream& is) override;
        std::ofstream& save(std::ofstream& of) const override;
        std::ifstream& load(std::ifstream& ifs) override;
    };
}

#endif //!SDDS_PERISHABLE_H_