/***********************************************************************
// OOP244 Workshop 10:
// File	validate.h
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    4/8/23        Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H


template <typename T>
bool validate(const T& min, const T* testValue, const int n, bool* result) {
    bool valid = true;


    for (int i = 0; i < n; i++) {


        result[i] = testValue[i] >= min;
        valid = valid && result[i];
    }
    return valid;
}


#endif