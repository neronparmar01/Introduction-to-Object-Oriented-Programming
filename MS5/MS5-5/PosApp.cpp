


#include <iostream>
#include <iomanip>
#include <cstring>
#include "Utils.h"
#include "PosApp.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "Bill.h"

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

        int choice = makeFoolproofChoice(0, 5, "> ");
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

        if (m_nptr >= MAX_NO_ITEMS) {
            std::cout << "Inventory Full!" << std::endl;
            return;
        }
        else {
            Item* newItem = NULL;
            std::cout << "Is the Item perishable? (Y)es/(N)o: ";
            char opt;
            std::cin >> opt;
            if (opt == 'Y' || opt == 'y') {
                newItem = new Perishable();
            }
            else if (opt == 'N' || opt == 'n') {
                newItem = new NonPerishable();
            }
            else {
                std::cout << "Invalid option entered" << std::endl;
                return;
            }

            std::cin >> *newItem;
            while (!*newItem) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << *newItem << ", try again...\n";
            }

            m_Iptr[m_nptr++] = newItem;
        }

        printActionTitle("DONE!");
    }

    void PosApp::listItems(bool displayTotal) {
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

        if (displayTotal) {
            std::cout << std::right << std::setw(46) << "Total Asset: $ " << " | ";
            std::cout << std::setw(13);
            std::cout << std::setprecision(2) << total << "|" << std::endl;
            std::cout << "-----------------------------------------------^--------------^" << std::endl;
            std::cout << std::endl;
        }
    }

    int PosApp::selectItem() {
        printActionTitle("Item Selection by row number");
        std::cout << "Press <ENTER> to start....";

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cin.get();

        listItems(false);

        return makeFoolproofChoice(1, m_nptr, "Enter the row number: ");
    }

    void PosApp::removeItem() {
        printActionTitle("Remove Item");

        int choice = selectItem();
        std::cout << "Removing...." << std::endl;

        std::cout << m_Iptr[choice - 1]->displayType(POS_FORM);

        Item* item = m_Iptr[choice - 1];
        delete item;

        for (int i = choice - 1; i < m_nptr; i++) {
            m_Iptr[i] = m_Iptr[i + 1];
        }

        m_nptr--;

        printActionTitle("DONE!");
    }

    void PosApp::stockItem() {
        printActionTitle("Select an item to stock");

        int choice = selectItem();
        std::cout << "Selected Item:" << std::endl;

        Item* item = m_Iptr[choice - 1];

        std::cout << item->displayType(POS_FORM);
        int max = MAX_STOCK_NUMBER - item->quantity();
        int toAdd = makeFoolproofChoice(1, max, "Enter quantity to add: ");

        *item += toAdd;

        printActionTitle("DONE!");
    }

    static Item* search(Item** items, int n, const char* SKU) {
        for (int i = 0; i < n; i++) {
            if (*items[i] == SKU) {
                return items[i];
            }
        }
        return NULL;
    }

    void PosApp::POS() {
        printActionTitle("Starting Point of Sale");

        char SKU[100];
        Bill bill;

        bill.clear();

        int input = 0;

        std::cin.ignore(10000, '\n');

        while (true) {
            memset(SKU, 0, 100);
            std::cout << "Enter SKU or <ENTER> only to end sale...";
            std::cout << std::endl << "> ";
            input = 0;

            while (input < 100) {
                SKU[input] = std::cin.get();
                if (SKU[input] == '\n') {
                    SKU[input--] = 0;
                    break;
                }
                input++;
            }

            if (strlen(SKU) > MAX_SKU_LEN) {
                std::cout << "SKU too long." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            if (SKU[0] != 0 && !std::cin.fail()) {
                Item* item = search(m_Iptr, m_nptr, SKU);
                if (item != NULL) {
                    *item -= 1;
                    std::cout << item->displayType(POS_FORM);
                    if (*item) {
                        bill.add(item);
                        std::cout << std::endl;
                        std::cout << ">>>>> Added to bill" << std::endl;
                        std::cout << std::fixed << std::setprecision(2);
                        std::cout << ">>>>> Total: " << bill.total() << std::endl;
                    }
                    else {
                        std::cout << std::endl;
                        item->clear();
                    }
                }
                else {
                    std::cout << "!!!!! Item Not Found !!!!!" << std::endl;
                }
            }
            else {
                break;
            }
        }

        bill.print(std::cout);;

       // std::cout << "Running " << "POS()" << std::endl;
    }

    void PosApp::printActionTitle(const char* str) const {
        std::cout << ">>>> ";
        std::cout << std::setw(72) << std::left << std::setfill('.') << str;
        std::cout << std::endl;
        std::cout << std::setfill(' ');
    }

}