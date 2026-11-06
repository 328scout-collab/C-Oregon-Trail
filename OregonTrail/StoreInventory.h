//
// Created by reinholzj on 11/5/2026.
//

#ifndef STORE_INVENTORY_H
#define STORE_INVENTORY_H

#include <string>
#include <map>


class StoreInventory {
private:
    double money;
    std::map<std::string, int> items;
    std::map<std::string, double> prices;

public:
    // Constructor
    StoreInventory(double startingMoney);

    // Member functions
    void displayStore() const;
    bool buyItem(const std::string& itemName, int quantity);
    void displaySummary() const;
};

#endif // STORE_INVENTORY_H