#include "menu.hpp"
#include <iostream>

Menu::Menu() { this->problem = nullptr, problemWidth = 0; };

void Menu::start() {
    printWelcomeMessage();
    int choice = 0;
    while (choice != 1 && choice != 2){
        printOptions();
        std::cin >> choice;
        switch(choice) {
            case 1:
                handleDefaultPuzzle();
                break;
            case 2:
                handleCustomPuzzle();
                break;
            default:
                std::cout << "Invalid choice.\n\n";
                break;
        }
    }
}

void Menu::printWelcomeMessage() const {
    std::cout << "Welcome to Komay and friends' 8-puzzle solver!\nFeaturing:\n- Komay Sugiyama (ksugi014)\n- Adithya Iyer (aiyer026)\n- Andy Jarean (ajare002)\n- Tingxuan Wu (twu148)\n\n";
}

void Menu::printOptions() const {
    std::cout << "Please type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
}

void Menu::handleDefaultPuzzle() {
    // Handle default puzzle logic here
}

void Menu::handleCustomPuzzle() {
    while (this->problemWidth <= 0) {
        std::cout << "Please enter the width of the square (must be greater than 0): ";
        std::cin >> this->problemWidth;
        if (this->problemWidth <= 0)
            std::cout << "Invalid input. Try again!\n";
    }
    std::vector<std::vector<int>> start;
    std::cout << "Enter the puzzle, use a zero to represent the blank\n";
    for (int i = 0; i < problemWidth; ++i) {
        std::vector<int> row;
        std::cout << "Enter row " << i + 1 << ", use spaces or tabs between numbers: ";
        for (int j = 0; j < problemWidth; ++j) {
            int num;
            std::cin >> num;
            row.push_back(num);
        }
        start.push_back(row);
    }
}

