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


#ifndef NAMESPACE_SHOPPINGLIST_H 
#define NAMESPACE_SHOPPINGLIST_H
namespace sdds {



	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}
#endif
