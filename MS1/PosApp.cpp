// Final Project Milestone 1
// Student POS App Mockup tester
// Version 1.0
// Date	2023-02-28
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the PosApp class
// for submission.
//
// Name : Neron Parmar       Student ID : 171690217
// 
// File : PosApp.cpp
/////////////////////////////////////////////////////////////////


#include "PosApp.h"

using namespace std;

namespace sdds {
    void PosApp::menu() {
        cout << "The Sene-Store\n";
        cout << "1- List items\n";
        cout << "2- Add item\n";
        cout << "3- Remove item\n";
        cout << "4- Stock item\n";
        cout << "5- Point of Sale\n";
        cout << "0- exit program\n";
    }

    void PosApp::addItem() {
        cout << ">>>> Adding Item to the store................................................\n";
        cout << "Running addItem()\n";
    }

    void PosApp::removeItem() {
        cout << ">>>> Remove Item.............................................................\n";
        cout << "Running removeItem()\n";
    }

    void PosApp::stockItem() {
        cout << ">>>> Select an item to stock.................................................\n";
        cout << "Running stockItem()\n";
    }

    void PosApp::listItems() {
        cout << ">>>> Listing Items...........................................................\n";
        cout << "Running listItems()\n";
    }

    void PosApp::POS() {
        cout << ">>>> Starting Point of Sale..................................................\n";
        cout << "Running POS()\n";
    }

    void PosApp::saveRecs() {
        cout << ">>>> Saving Data.............................................................\n";
        cout << "Saving data in " << m_fileName << endl;
    }

    void PosApp::loadRecs() {
        cout << ">>>> Loading Items...........................................................\n";
        cout << "Loading data from " << m_fileName << endl;
    }

    PosApp::PosApp(const char* fileName) {
        strcpy(this->m_fileName, fileName);
    }

    void PosApp::run() {
        loadRecs();

        int choice = 1;
        while (choice) {
            menu();
            cout << "> ";
            cin >> choice;

            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid Integer, try again: ";
                cin >> choice;
            }

            while (choice < 0 || choice > 5) {
                cout << "[0<=value<=5], retry: > ";
                cin >> choice;
            }

            switch (choice) {
            case 1:
                listItems();
                break;
            case 2:
                addItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                stockItem();
                break;
            case 5:
                POS();
                break;
            default:
                saveRecs();
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }
}