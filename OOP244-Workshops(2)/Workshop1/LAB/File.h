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

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "ShoppingRec.h"


namespace sdds {

	
	
	// functions
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif // !SDDS_FILE_H
