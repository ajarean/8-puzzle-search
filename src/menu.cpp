#include "menu.hpp"

Menu::Menu() { this->problem = nullptr, problemWidth = 0, nodesExpanded = 0, maxNodesQueued = 0, goalNodeDepth = 0; };

void Menu::start() {
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<
    "\nWelcome to Komay and friends' 8-puzzle solver!\nFeaturing:\n- Komay Sugiyama (ksugi014)\n- Adithya Iyer (aiyer026)\n- Andy Jarean (ajare002)\n- Tingxuan Wu (twu148)\n"
     "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
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

    std::cout << std::endl << "Your starting state is: " << std::endl;
    this->problem->getStartState().displayState();
    std::cout << std::endl << "Your goal state is: " << std::endl;
    this->problem->getGoalState().displayState();
    std::cout << std::endl;

    std::string searchType;
    choice = 0;
    Search* search = nullptr;
    while (choice != 1 && choice != 2 && choice != 3){
        std::cout << "Enter your choice of algorithm (1-3):\n1. Uniform Cost Search\n2. A* with the Misplaced Tile heuristic\n3. A* with the Euclidean distance heuristic" << std::endl;
        std::cin >> choice;
        switch(choice) {
            case 1: {
                search = new UniformCostSearch(problem);
                searchType = "UNIFORM COST SEARCH";
                break;
            }
            case 2: {
                search = new MisplacedTileInformedSearch(problem);
                searchType = "MISPLACED TILE INFORMED SEARCH";
                break;
            }
            case 3: {
                search = new EuclideanDistanceSearch(problem);
                searchType = "EUCLIDEAN DISTANCE SEARCH";
                break;
            }
            // case 4: {
            //     search = new ManhattanSearch(problem);
            //     break;
            // }
            default:
                std::cout << "Invalid choice.\n\n";
                break;
        }
    }

    std::optional<State> solutionState = search->doSearch();
    if (solutionState) {
        State finalState = solutionState.value();
        std::cout << "\n!!!!!!! GOAL !!!!!!!";
    }
    else std::cout << "Failed to find goal state bruh" << '\n';

    std::cout << std::endl << searchType << " RESULTS: \n";
    std::cout << "Expanded a total of: " << search->getTotalNodes() << " nodes." << std::endl;
    std::cout << "Max number of nodes in the queue at any one time: " << search->getMaxQueue() << "." << std::endl;
    std::cout << "Depth of the goal node: " << search->getSolutionDepth() << "." << std::endl;

    delete problem;
    delete search;
}

void Menu::handleDefaultPuzzle() {
    int choice = 0;
    this->problemWidth = 3;
    std::vector<std::vector<int>> start, goal;
    while (choice < 1 || choice > 7){
        std::cout << "Please choose a default puzzle type:\n1. Trivial\n2. Easy\n3. Oh Boy\n4. Very Easy\n5. doable\n6. IMPOSSIBLE\n7. 5-width example" << std::endl;
        std::cin >> choice;
        switch(choice) {
            case 1: start = {{1,2,3},{4,5,6},{7,8,0}};
                break;
            case 2: start = {{1,2,0},{4,5,3},{7,8,6}};
                break;
            case 3: start = {{8,7,1},{6,0,2},{5,4,3}};
                break;
            case 4: start = {{1,2,3},{4,5,6},{7,0,8}};
                break;
            case 5: start = {{0,1,2},{4,5,3},{7,8,6}};
                break;
            case 6: start = {{1,2,3},{4,5,6},{8,7,0}};
                break;
            case 7: start = {{1,2,3,4,5},{6,7,8,0,9},{11,19,14,13,10},{16,22,12,15,18},{21,20,17,23,24}};
                this->problemWidth = 5;
                break;
            default:
                std::cout << "Invalid choice.\n\n";
                break;
        }
        goal = makeGoal();
        problem = new Problem(start, goal);
    }
}

void Menu::handleCustomPuzzle() {
    while (this->problemWidth <= 0) {
        std::cout << "Please enter the width of the square (must be greater than 0): ";
        std::cin >> this->problemWidth;
        if (this->problemWidth <= 0)
            std::cout << "Invalid input. Try again!\n\n";
    }
    std::vector<std::vector<int>> start, goal;
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
    goal = makeGoal();
    this->problem = new Problem(start, goal);
}

std::vector<std::vector<int>> Menu::makeGoal() {
    std::vector<std::vector<int>> goal(problemWidth, std::vector<int>(problemWidth));

    int num = 1;
    for (int i = 0; i < problemWidth; ++i) {
        for (int j = 0; j < problemWidth; ++j) {
            goal[i][j] = num;
            num++;
        }
    }
    goal[problemWidth - 1][problemWidth - 1] = 0;

    return goal;
}

