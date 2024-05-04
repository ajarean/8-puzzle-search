#include "menu.hpp"

Menu::Menu() { this->problem = nullptr, problemWidth = 0, nodesExpanded = 0, maxNodesQueued = 0, goalNodeDepth = 0; };

void Menu::start() {
    std::cout << "Welcome to Komay and friends' 8-puzzle solver!\nFeaturing:\n- Komay Sugiyama (ksugi014)\n- Adithya Iyer (aiyer026)\n- Andy Jarean (ajare002)\n- Tingxuan Wu (twu148)\n\n";
    int choice = 0;
    while (choice != 1 && choice != 2){
        std::cout << "Please type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
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
    choice = 0;
    while (choice != 1 && choice != 2){
        std::cout << "Enter your choice of algorithm (1-3):\n1. Uniform Cost Search\n2. A* with the Misplaced Tile heuristic\n3. A* with the Euclidean distance heuristic" << std::endl;
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

void Menu::handleDefaultPuzzle() {
    // Handle default puzzle logic here
}

void Menu::handleCustomPuzzle() {
    while (this->problemWidth <= 0) {
        std::cout << "Please enter the width of the square (must be greater than 0): ";
        std::cin >> this->problemWidth;
        if (this->problemWidth <= 0)
            std::cout << "Invalid input. Try again!\n\n";
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
    std::vector<std::vector<int>> stateData
    {
        {1,2,3},
        {4,5,6},
        {7,8,0}
    };
    State s(stateData);
    std::cout << std::endl << "Your starting state is: " << std::endl;
    displayState(s);
    std::cout << std::endl;
}

void Menu::displayState(State& s) const {
    // temporary state
    
    std::vector<std::vector<int>> stateData = s.getData();
    for (int i = 0; i < problemWidth; ++i) {
        for (int j = 0; j < problemWidth; ++j) {
            std::cout << stateData[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

