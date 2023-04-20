

#include <iomanip>
#include "NonPerishable.h"

namespace sdds {

    std::ostream& NonPerishable::write(std::ostream& os) const {
        Item::write(os);
        if (*this) {
            if (m_displayType == POS_LIST) {
                os << "     N / A   |";
            }
            else {
                os << "=============^" << std::endl;
            }
        }

        return os;
    }

}