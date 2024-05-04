#include "search.hpp"
#include <queue>
#include <set>
#include <iostream>

// Base Class

std::pair<int, int> Search::indexInFinal(int num) {
    std::pair<int, int> f = {-1, -1};
    std::vector<std::vector<int>> goalState = problem->getGoalState().getData();
    for(int y = 0; y<goalState.size(); y++) {
        for(int x = 0; x<goalState[0].size(); x++) {
            if (goalState[x][y] == num) {
                f.first = x;
                f.second = y;
                return f;
            }
        }
    } return f;
}

std::optional<State> Search::doSearch() {
    State start = problem->getStartState();
    std::priority_queue<State, std::vector<State>, std::greater<State>> pqueue;
    pqueue.push(problem->getStartState());
    while (!pqueue.empty()) {
        State currState = pqueue.top();
        pqueue.pop();
        if (problem->isGoal(currState)) return currState;
        std::vector<State> expanded = problem->expand(currState);
        for (State nextState : expanded) {
            nextState.setCost(nextState.getDepth() + heuristic(nextState));
            pqueue.push(nextState);
        }
    }
    return std::nullopt;
}



// Uniform

int UniformCostSearch::heuristic(const State& currentState) {
    return 0;
}

// Euclidean

// Misplaced Tile

int MisplacedTileInformedSearch::heuristic(const State& c) {
    int totalHeuristic = 0;
    std::vector<std::vector<int>> goalState = problem->getGoalState().getData();
    std::vector<std::vector<int>> currentState = c.getData();
    for(int y = 0; y<currentState.size(); y++) {
        for(int x = 0; x<currentState[0].size(); x++) {
            // Run distance test on every tile
            int value = currentState[x][y];
            std::pair coordsFinal = indexInFinal(value);
            // std::cout << "  Calculating tile " << value << std::endl;
            totalHeuristic += calculateManhattan(std::make_pair(x, y), coordsFinal);
            
        }
    }
    // std::cout << "      state heuristic of " << totalHeuristic << std::endl;
    return totalHeuristic;
}



int MisplacedTileInformedSearch::calculateManhattan(std::pair<int, int> value1, std::pair<int, int> value2) {
    // value1 --> current tile placement
    // value2 --> goal tile placement
    // std::cout << "       Finding distance between " << "(" << value1.second <<" , " << value1.first << ") and "  << "(" << value2.second << ", " << value2.first << ")" << std::endl;
    int dx = std::abs(value1.first - value2.first);
    int dy = std::abs(value1.second - value2.second);
    // std::cout << "       dx: " << dx << std::endl;
    // std::cout << "       dy: " << dy << std::endl;
    // std::cout << "       tile heuristic " << x << std::endl;
    return dx+dy;
}







