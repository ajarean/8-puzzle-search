#include "menu.hpp"

Menu::Menu() { 
    this->problem = nullptr; 
    problemWidth = 0;
}

void Menu::start() {
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<
    "\nWelcome to Komay and friends' 8-puzzle solver!\nFeaturing:\n- Komay Sugiyama (ksugi014)\n- Adithya Iyer (aiyer026)\n- Andy Jarean (ajare002)\n- Tingxuan Wu (twu148)\n"
     "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    //Prompt to use default or custom puzzle
    int choice = 0;
    while (choice != 1 && choice != 2){
        std::cout << "\nPlease type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
        std::cin >> choice;
        switch(choice) {
            case 1:
                handleDefaultPuzzle();
                break;
            case 2:
                handleCustomPuzzle();
                break;
            default:
                std::cout << "Invalid choice.\n";
                exit(1);
                break;
        }
    }

    //Display start and final states
    std::cout << std::endl << "Your starting state is: " << std::endl;
    this->problem->getStartState().displayState();
    std::cout << std::endl << "Your goal state is: " << std::endl;
    this->problem->getGoalState().displayState();
    std::cout << std::endl;

    //Prompt to choose search algorithm
    std::string searchType;
    choice = 0;
    Search* search = nullptr;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4){
        std::cout << "Enter your choice of algorithm (1-4):\n1. Uniform Cost Search\n2. A* with the Misplaced Tile heuristic\n3. A* with the Euclidean distance heuristic\n4. A* with the Manhattan distance heuristic" << std::endl;
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
            case 4: {
                search = new ManhattanInformedSearch(problem);
                searchType = "MANHATTAN INFORMED SEARCH";
                break;
            }
            default:
                std::cout << "Invalid choice.\n\n";
                break;
        }
    }

    //Run search
    std::optional<State> solutionState = search->doSearch();
    if (solutionState) {
        State finalState = solutionState.value();
        std::cout << "\n!!!!!!! GOAL !!!!!!!";
    }
    else std::cout << "\nCould not find goal state. Puzzle is unsolvable.\n";

    //Print search results
    std::cout << std::endl << searchType << " RESULTS: \n";
    std::cout << "Expanded a total of: " << search->getTotalNodes() << " nodes\n";
    std::cout << "Max number of nodes in the queue at any one time: " << search->getMaxQueue() << "\n";
    std::cout << "Depth of the goal node: " << search->getSolutionDepth() << "\n";

    //Prompt to print solution trace
    if (solutionState) {
        int trace = 0;
        std::cout << "Would you like to print the trace?\nIf so, press 1. Else, input a different number: ";
        std::cin >> trace;
        if (trace == 1) {
            std::cout << "Printing trace: \n\n";
            printTrace(solutionState.value());
        }
    }

    delete search;
}

void Menu::handleDefaultPuzzle() {
    int choice = -1;
    this->problemWidth = 3;
    std::vector<std::vector<int>> start, goal;
    while (choice < 0 || choice > 8){
        std::cout << "\nPlease choose a default puzzle type:\n0. Objective\n1. Trivial\n2. Easy\n3. Oh Boy\n4. Very Easy\n5. doable\n6. IMPOSSIBLE\n7. Trivial 4-width\n8. Solvable 4-width" << std::endl;
        std::cin >> choice;
        switch(choice) {
            case 0: start = {{1,0,3},{4,2,6},{7,5,8}};
                break;
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
            case 7: start = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
                this->problemWidth = 4;
                break;
            case 8: start = {{1,2,3,4},{5,6,7,8},{9,12,10,0},{13,14,15,11}};
                this->problemWidth = 4;
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

//Function to procedurally gernerate goal state based on puzzle size
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

void Menu::printTrace(State& s) {
    State* currState = &s;
    std::stack<State*> stack;
    stack.push(currState);
    //Follow state->parent path all the way to start state
    while(currState->getParent() != nullptr) {
        currState = currState->getParent();
        stack.push(currState);
    }
    //Display nodes on stack, effectively printing the solution trace
    while(!stack.empty()) {
        State* newState = stack.top();
        stack.pop();
        newState->displayState();
        std::cout << '\n';
    }
}