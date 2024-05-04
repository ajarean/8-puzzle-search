#include "search.hpp"


Search::Search(const Problem& p) {
    this->problem = p;
}

int MisplacedTileInformedSearch::heuristic(const State& currentState) {
    int totalHeuristic = 0;
    std::vector<std::vector<int>> goalState = problem.getGoalState().getData();
    for(int y = 0; y<goalState.size(); y++) {
        for(int x = 0; x<goalState[0].size(); x++) {
            int value = goalState[y][x];
            totalHeuristic += calculateManhattan(indexInFinal(value, problem), std::make_pair(y, x));
        }
    }
    return totalHeuristic;
}

int calculateManhattan(std::pair<int, int> value1, std::pair<int, int> value2) {
    return std::abs(value1.first - value2.first) + std::abs(value2.second - value2.second);
}

std::pair<int, int> indexInFinal(int num, Problem problem) {
    for(int y = 0; y<problem.getGoalState().getData().size(); y++) {
        for(int x = 0; x<problem.getGoalState().getData()[0].size(); x++) {
            if (problem.getGoalState().getData()[y][x] == num) {
                return std::make_pair(y, x);
            }
        }
}
}