#include "search.hpp"
#include "menu.hpp"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    int choice = 1;
    while (choice==1) {
        Menu menu;
        menu.start();
        std::cout << "\nWould you like to try another search?\nIf so, press 1. Else, input a different number." << std::endl;
        choice = 0;
        std::cin >> choice;
    }
    std::cout << "Thank you! :)" << std::endl;

    // std::vector<std::vector<int>> testData = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    // std::vector<std::vector<int>> testData2 = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};
    // std::vector<std::vector<int>> testData3 = {{1, 8, 2}, {0, 4, 3}, {7, 6, 5}}; // Solvable
    // std::vector<std::vector<int>> testData4 = {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};

    // Problem* testProblem = new Problem(testData4, testData);
    // UniformCostSearch testSearch(testProblem);
    // MisplacedTileInformedSearch testSearch2(testProblem);
    
    // // State s = testProblem.getStartState();
    // // std::vector<State> v = testProblem.expand(s);
    // // for (State state : v) {
    // //     std::cout << testProblem.isGoal(state) << '\n';
    // // }

    // // std::vector<State> v2 = testProblem.expand(v[0]);
    // // for (State state : v2) {
    // //     std::cout << testProblem.isGoal(state) << '\n';
    // // }

    // std::optional<State> solutionState = testSearch.doSearch();
    // if (solutionState) {
    //     State finalState = solutionState.value();
    //     std::cout << "Found goal state in " << finalState.getDepth() << " move(s)\n";
    // }
    // else std::cout << "Failed to find goal state bruh" << '\n';

    // std::optional<State> solutionState2 = testSearch2.doSearch();
    // if (solutionState2) {
    //     State finalState2 = solutionState2.value();
    //     std::cout << "Found goal state in " << finalState2.getDepth() << " move(s)\n";
    // }
    // else std::cout << "Failed to find goal state bruh" << '\n';

    // std::cout << "UNIFORM COST SEARCH:" << std::endl;
    // std::optional<State> solutionState = testSearch.doSearch();
    // if (solutionState) {
    //     std::cout << "The algorithm expanded " << testSearch.getTotalNodes() << " nodes\n";
    //     std::cout << "The max queue size was " << testSearch.getMaxQueue() << "\n";
    //     std::cout << "The depth of the goal node was " << testSearch.getSolutionDepth() << "\n";
    // }
    // else std::cout << "Failed to find goal state bruh" << '\n';

    // std::cout << std::endl;

    // std::cout << "A* SEARCH WITH MISPLACED TILE HEURISTIC:" << std::endl;
    // std::optional<State> solutionState2 = testSearch2.doSearch();
    // if (solutionState2) {
    //     std::cout << "The algorithm expanded " << testSearch2.getTotalNodes() << " nodes\n";
    //     std::cout << "The max queue size was " << testSearch2.getMaxQueue() << "\n";
    //     std::cout << "The depth of the goal node was " << testSearch2.getSolutionDepth() << "\n";
    // }
    // else std::cout << "Failed to find goal state bruh" << '\n';

    // std::cout << std::endl;

    // std::cout << "A* SEARCH WITH EUCLIDEAN DISTANCE HEURISTIC:" << std::endl;
    // std::optional<State> solutionState3 = testSearch3.doSearch();
    // if (solutionState3) {
    //     std::cout << "The algorithm expanded " << testSearch3.getTotalNodes() << " nodes\n";
    //     std::cout << "The max queue size was " << testSearch3.getMaxQueue() << "\n";
    //     std::cout << "The depth of the goal node was " << testSearch3.getSolutionDepth() << "\n";
    // }
    // else std::cout << "Failed to find goal state bruh" << '\n';

    // delete testProblem;

    return 0;
} 