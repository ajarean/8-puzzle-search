#include "search.hpp"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> testData = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    std::vector<std::vector<int>> testData2 = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};
    std::vector<std::vector<int>> testData3 = {{1, 8, 2}, {0, 4, 3}, {7, 6, 5}}; // Solvable
    std::vector<std::vector<int>> testData4 = {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};

    Problem* testProblem = new Problem(testData3, testData);
    UniformCostSearch testSearch(testProblem);

    EuclideanDistanceSearch testSearch3(testProblem);
    
    MisplacedTileInformedSearch testSearch2(testProblem);
    
    // State s = testProblem.getStartState();
    // std::vector<State> v = testProblem.expand(s);
    // for (State state : v) {
    //     std::cout << testProblem.isGoal(state) << '\n';
    // }

    // std::vector<State> v2 = testProblem.expand(v[0]);
    // for (State state : v2) {
    //     std::cout << testProblem.isGoal(state) << '\n';
    // }

    std::optional<State> solutionState = testSearch.doSearch();
    if (solutionState) {
        std::cout << "The algorithm expanded " << testSearch.getTotalNodes() << " nodes\n";
        std::cout << "The max queue size was " << testSearch.getMaxQueue() << "\n";
        std::cout << "The depth of the goal node was " << testSearch.getSolutionDepth() << "\n";
    }
    else std::cout << "Failed to find goal state bruh" << '\n';

    std::cout << std::endl;

    std::optional<State> solutionState2 = testSearch2.doSearch();
    if (solutionState2) {
        std::cout << "The algorithm expanded " << testSearch2.getTotalNodes() << " nodes\n";
        std::cout << "The max queue size was " << testSearch2.getMaxQueue() << "\n";
        std::cout << "The depth of the goal node was " << testSearch2.getSolutionDepth() << "\n";
    }
    else std::cout << "Failed to find goal state bruh" << '\n';

    delete testProblem;

    return 0;
} 