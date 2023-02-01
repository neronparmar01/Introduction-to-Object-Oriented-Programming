/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Customer.cpp
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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include <cstring>
#include "Tools.h"

namespace sdds
{

	// complete
	Customers* g_rec = new Customers[5];

	void read(char* str, int len)
	{ // Fully provided
		if (cin.peek() == '\n')
		{
			cin.ignore();
		}
		cin.getline(str, len);
	}

	// Code Start

	bool read(Customers& rec)
	{

		cout << " Enter User name: ";
		cin.getline(rec.user_name, 25);
		if (strlen(rec.user_name) == 0)
		{
			return false;
		}

		cout << " Enter likes_count: ";
		cin >> rec.likes_count;
		cout << " Enter retweets_count: ";
		cin >> rec.retweets_count;
		cout << " Enter replies_count: ";
		cin >> rec.replies_count;
		cout << " Enter share videos (y/n): ";
		cin >> rec.share_videos;
		cin.clear();
		cin.ignore(1000, '\n');
		return true;
	}

	void EmptyRecord(Customers& c_rec)
	{
		c_rec = {};
	}

	void EmptyRecord(CustomersRecord& t_rec)
	{
		t_rec.noOfRecords = 0;
	}

	void addCustomer(CustomersRecord& t_rec, Customers& c_rec)
	{

		t_rec.ptr_rec = g_rec;
		t_rec.ptr_rec[t_rec.noOfRecords] = c_rec;
		t_rec.noOfRecords++;
	}

	void display(const CustomersRecord& t_rec)
	{
		for (int i = 0; i < t_rec.noOfRecords; i++)
		{
			cout << i + 1 << ". " << t_rec.ptr_rec[i].user_name << ", " << t_rec.ptr_rec[i].likes_count << ", " << t_rec.ptr_rec[i].retweets_count << ", " << t_rec.ptr_rec[i].replies_count << ", " << t_rec.ptr_rec[i].share_videos << endl << endl;
		}
	}

	// complete

}