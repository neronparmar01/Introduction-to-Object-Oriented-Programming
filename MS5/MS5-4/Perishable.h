


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