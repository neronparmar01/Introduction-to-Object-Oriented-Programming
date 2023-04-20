// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : PosApp.cpp
// Name : Neron Parmar     Student ID : 171690217     Date : 4/16/23
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>
#include "PosApp.h"
#include "Perishable.h"
#include "NonPerishable.h"

namespace sdds {

    PosApp::PosApp(const char* filename) {
        if (filename) {
            strcpy(m_FileName, filename);
        }
    }

    PosApp::~PosApp() {
        for (int i = 0; i < m_nptr; i++) {
            delete m_Iptr[i];
        }
    }

    int PosApp::menu() const {
        std::cout << "The Sene-Store" << std::endl;
        std::cout << "1- List items" << std::endl;
        std::cout << "2- Add item" << std::endl;
        std::cout << "3- Remove item" << std::endl;
        std::cout << "4- Stock item" << std::endl;
        std::cout << "5- POS" << std::endl;
        std::cout << "0- exit program" << std::endl;
        std::cout << "> ";
        int choice = -1;

        do {
            if (std::cin >> choice) {
                if (choice < 0 || choice > 5) {
                    std::cout << "[0<=value<=5], retry: > ";
                }
            }
            else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid Integer, try again: ";
                choice = -1;
            }
        } while (choice < 0 || choice > 5);

        return choice;
    }

    void PosApp::run() {
        loadRecs();
        int choice = -1;
        do {
            choice = menu();
            switch (choice) {
            case 0:
                break;
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
            }
        } while (choice != 0);
        saveRecs();
        std::cout << "Goodbye!" << std::endl;
    }

    void PosApp::loadRecs() {
        printActionTitle("Loading Items");

        std::ifstream input(m_FileName);

        if (!input) {
            std::ofstream ofs(m_FileName);
            ofs.close();
            input.open(m_FileName);
        }

        m_nptr = 0;

        while (input) {
            char c;
            input >> c;
            if (c == 'P') {
                m_Iptr[m_nptr] = new Perishable();

                // ignore the next comma
                char tmp;
                input >> tmp;
            }
            else if (c == 'N') {
                m_Iptr[m_nptr] = new NonPerishable();

                // ignore the next comma
                char tmp;
                input >> tmp;
            }
            else
                std::cout << "Invalid itemType found: " << c;

            input >> *m_Iptr[m_nptr++];
            if (input.fail()) {
                delete m_Iptr[--m_nptr];
            }
        }
    }

    void PosApp::saveRecs() const {
        printActionTitle("Saving Data");
        std::ofstream of(m_FileName);

        for (int i = 0; i < m_nptr; i++) {
            of << *m_Iptr[i] << std::endl;
        }
    }

    void PosApp::addItem() {
        printActionTitle("Adding Item to the store");
        std::cout << "Running " << "addItem()" << std::endl;
    }

    void PosApp::listItems() {
        printActionTitle("Listing Items");

        // Bubble sort
        for (int i = m_nptr - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (strcmp(m_Iptr[j]->getName(), m_Iptr[j + 1]->getName()) > 0) {
                    Item* tmp = m_Iptr[j];
                    m_Iptr[j] = m_Iptr[j + 1];
                    m_Iptr[j + 1] = tmp;
                }
            }
        }

        std::cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << std::endl;
        std::cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << std::endl;

        double total = 0;
        for (int i = 0; i < m_nptr; i++) {
            m_Iptr[i]->displayType(POS_LIST);
            std::cout << std::right << std::setw(4) << (i + 1) << " | ";
            std::cout << *m_Iptr[i] << std::endl;
            total += (m_Iptr[i]->cost() * m_Iptr[i]->quantity());
        }


        std::cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << std::endl;
        std::cout << std::right << std::setw(46) << "Total Asset: $ " << " | ";
        std::cout << std::setw(13);
        std::cout << std::setprecision(2) << total << "|" << std::endl;
        std::cout << "-----------------------------------------------^--------------^" << std::endl;
        std::cout << std::endl;
    }

    void PosApp::removeItem() {
        printActionTitle("Remove Item");
        std::cout << "Running " << "removeItem()" << std::endl;
    }

    void PosApp::stockItem() {
        printActionTitle("Select an item to stock");
        std::cout << "Running " << "stockItem()" << std::endl;
    }

    void PosApp::POS() {
        printActionTitle("Starting Point of Sale");
        std::cout << "Running " << "POS()" << std::endl;
    }

    void PosApp::printActionTitle(const char* str) const {
        std::cout << ">>>> ";
        std::cout << std::setw(72) << std::left << std::setfill('.') << str;
        std::cout << std::endl;
        std::cout << std::setfill(' ');
    }

}