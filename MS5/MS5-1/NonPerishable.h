// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : NonPerishable.h
// Name : Neron Parmar     Student ID : 171690217     Date : 4/16/23
/////////////////////////////////////////////////////////////////

#ifndef SDDS_NONPERISHABLE_H_
#define SDDS_NONPERISHABLE_H_
#include <iostream>
#include "Item.h"

namespace sdds {
    class NonPerishable : public Item {
        char itemType() const override {
            return 'N';
        }

        std::ostream& write(std::ostream& os) const override;
    };
}

#endif //!SDDS_NONPERISHABLE_H_