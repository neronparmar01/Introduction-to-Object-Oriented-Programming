// Workshop 1:
// Version: 1.0
// Author: Fardad Soleimanloo
// Description:
// w1p1.cpp
//
// Name : Neron Parmar      Student ID: 171690217
// Date : 5/18/23
// 
///////////////////////////////////////////////////

#ifndef NAMESPACE_SHOPPINGREC_H 
#define NAMESPACE_SHOPPINGREC_H

namespace sdds {
    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;

    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);

}
#endif
