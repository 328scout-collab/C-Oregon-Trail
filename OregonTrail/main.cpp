//
// Created by reinholzj on 11/6/2026.
//

#include <iostream>
#include "StoreInventory.h"

int main() {
    // Start the player with $300.00
    StoreInventory playerInventory(300.00);
    int choice = 0;

    std::cout << "Welcome to Independence, Missouri! Before heading out on the Oregon Trail, you need supplies.\n";

    while (true) {
        playerInventory.displayStore();
        std::cout << "Enter your choice (1-5): ";

        // Input validation for menu selection
        if (!(std::cin >> choice)) {
            std::cout << "\n[!] Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        // Option 5 finishes shopping (4 items + 1 finish option = 5)
        if (choice == 5) {
            std::cout << "\nYou leave the store and head out onto the trail...\n";
            break;
        }

        std::string selectedItem = "";
        if (choice == 1) selectedItem = "Oxen";
        else if (choice == 2) selectedItem = "Food (lbs)";
        else if (choice == 3) selectedItem = "Clothing";
        else if (choice == 4) selectedItem = "Ammunition (box)";
        else {
            std::cout << "\n[!] Invalid choice. Please choose a number between 1 and 5.\n";
            continue;
        }

        int quantity = 0;
        std::cout << "How many " << selectedItem << " would you like to buy? ";

        // Input validation for quantity
        if (!(std::cin >> quantity) || quantity <= 0) {
            std::cout << "\n[!] Please enter a valid positive quantity.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        playerInventory.buyItem(selectedItem, quantity);
    }

    // Show what the player is taking onto the trail
    playerInventory.displaySummary();

    return 0;
}