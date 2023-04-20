


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