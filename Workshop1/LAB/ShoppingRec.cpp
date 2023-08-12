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


#include <iostream>
#include "ShoppingRec.h"
#include "File.h"
#include "Utils.h"
#include "ShoppingList.h"

using namespace std;


namespace sdds {


    ShoppingRec getShoppingRec() {
        ShoppingRec R = {};
        cout << "Item name: ";
        readCstr(R.m_title, MAX_TITLE_LENGTH);
        cout << "Quantity: ";
        R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
        return R;
    }
    void displayShoppingRec(const ShoppingRec* shp) {
        cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
            " qty:(" << shp->m_quantity << ")" << endl;
    }
    void toggleBoughtFlag(ShoppingRec* rec) {
        rec->m_bought = !rec->m_bought;

    }
    bool isShoppingRecEmpty(const ShoppingRec* shp) {
        return shp->m_title[0] == 0;
    }



}