//
// Created by reinholzj on 11/5/2026.
//

#include "StoreInventory.h"
#include <iostream>
#include <iomanip>

// Constructor implementation
StoreInventory::StoreInventory(double startingMoney) : money(startingMoney) {
    prices["Oxen"] = 40.00;
    prices["Food (lbs)"] = 0.20;
    prices["Clothing"] = 10.00;
    prices["Ammunition (box)"] = 2.00;

    for (const auto& pair : prices) {
        items[pair.first] = 0;
    }
}

// Display store items and prices
void StoreInventory::displayStore() const {
    std::cout << "\n=== THE OREGON TRAIL GENERAL STORE ===\n";
    std::cout << "Your Money: $" << std::fixed << std::setprecision(2) << money << "\n";
    std::cout << "----------------------------------------\n";

    int index = 1;
    for (const auto& pair : prices) {
        std::cout << index << ". " << pair.first << " - $" << std::fixed << std::setprecision(2) << pair.second << " each\n";
        index++;
    }
    std::cout << index << ". Finish shopping and start journey\n";
    std::cout << "----------------------------------------\n";
}

// Handle purchasing logic
bool StoreInventory::buyItem(const std::string& itemName, int quantity) {
    if (prices.find(itemName) == prices.end()) return false;

    double totalCost = prices[itemName] * quantity;
    if (totalCost > money) {
        std::cout << "\n[!] You don't have enough money for that many " << itemName << "!\n";
        return false;
    }

    money -= totalCost;
    items[itemName] += quantity;
    std::cout << "\n[+] Successfully bought " << quantity << " " << itemName << "!\n";
    return true;
}

// Display final summary before leaving the store
void StoreInventory::displaySummary() const {
    std::cout << "\n=== FINAL INVENTORY & BUDGET ===\n";
    std::cout << "Remaining Money: $" << std::fixed << std::setprecision(2) << money << "\n";
    std::cout << "Purchased Items:\n";
    for (const auto& pair : items) {
        std::cout << " - " << pair.first << ": " << pair.second << "\n";
    }
    std::cout << "================================\n";
}