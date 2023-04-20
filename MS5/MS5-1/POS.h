// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : POS.h
// Name : Neron Parmar     Student ID : 171690217     Date : 4/16/23
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POS_H_
#define SDDS_POS_H_

namespace sdds {
    const double TAX = 0.13;
    const int MAX_SKU_LEN = 7;
    const int MIN_YEAR = 2000;
    const int MAX_YEAR = 2030;
    const int MAX_STOCK_NUMBER = 99;
    const int MAX_NO_ITEMS = 200;
    const int MAX_NAME_LEN = 40;

    const int POS_LIST = 1;
    const int POS_FORM = 2;

    const char ERROR_POS_SKU[] = "SKU too long";
    const char ERROR_POS_NAME[] = "Item name too long";
    const char ERROR_POS_PRICE[] = "Invalid price value";
    const char ERROR_POS_TAX[] = "Invalid tax status";
    const char ERROR_POS_QTY[] = "Invalid quantity value";
    const char ERROR_POS_STOCK[] = "Item out of stock";
    const char ERROR_POS_EMPTY[] = "Invalid Empty Item";
}
#endif //!SDDS_POS_H_