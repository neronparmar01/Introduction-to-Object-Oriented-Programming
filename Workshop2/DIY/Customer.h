/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Customer.h
// Version 1.1
// Date   Fall 2022
// Author Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                  Date          Reason
// Parmar Neron Nelson   1/31/23       reordered user's tweets report
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_
#include<cstring>

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };

    void read(char* str, int len);

    //Code Start

    void EmptyRecord(Customers& c_rec);
    void EmptyRecord(CustomersRecord& t_rec);

    bool read(Customers& rec);
    void addCustomer(CustomersRecord& t_rec, Customers& c_rec);
    void display(const CustomersRecord& t_rec);

    //Code Ended
}

#endif 
