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

#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include <iostream>

using namespace std;

namespace sdds {

    const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
    FILE* sfptr = nullptr;

    bool openFileForRead() {
        sfptr = fopen(SHOPPING_DATA_FILE, "r");
        return sfptr != NULL;
    }

    bool openFileForOverwrite() {
        sfptr = fopen(SHOPPING_DATA_FILE, "w");
        return sfptr != NULL;
    }

    void closeFile() {
        if (sfptr) fclose(sfptr);
    }

    bool freadShoppingRec(ShoppingRec* rec) {
        int flag = 0;
        bool success = fscanf(sfptr, "%[^,],%d,%d\n",
            rec->m_title, &rec->m_quantity, &flag) == 3;
        rec->m_bought = !!flag;
        return success;
    }

    void fwriteShoppintRec(const ShoppingRec* rec) {
        fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
    }

}