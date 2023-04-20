


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
        void listItems(bool displayTotal = true);
        int selectItem();
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