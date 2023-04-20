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
// File : NonPerishable.h
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