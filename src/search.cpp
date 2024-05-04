#include "search.hpp"
#include <queue>
#include <set>
#include <iostream>





int MisplacedTileInformedSearch::heuristic(const State& currentState) {
    int totalHeuristic = 0;
    std::vector<std::vector<int>> goalState = problem->getGoalState().getData();
    for(int y = 0; y<goalState.size(); y++) {
        for(int x = 0; x<goalState[0].size(); x++) {
            int value = goalState[y][x];
            std::pair coordsFinal = indexInFinal(value);
            totalHeuristic += calculateManhattan(coordsFinal, std::make_pair(y, x));
        }
    }
    return totalHeuristic;
}

std::pair<int, int> Search::indexInFinal(int num) {
    for(int y = 0; y<problem->getGoalState().getData().size(); y++) {
        for(int x = 0; x<problem->getGoalState().getData()[0].size(); x++) {
            if (problem->getGoalState().getData()[y][x] == num) {
                return std::make_pair(y, x);
            }
        }
    }
}

int MisplacedTileInformedSearch::calculateManhattan(std::pair<int, int> value1, std::pair<int, int> value2) {
    return std::abs(value1.first - value2.first) + std::abs(value2.second - value2.second);
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