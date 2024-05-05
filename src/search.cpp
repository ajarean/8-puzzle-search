#include "search.hpp"
#include <queue>
#include <set>
#include <iostream>
#include <math.h>

// Base Class

std::pair<int, int> Search::indexInFinal(int num) {
    std::pair<int, int> f = {-1, -1};
    for(int y = 0; y<problem->getGoalState().getData().size(); y++) {
        for(int x = 0; x<problem->getGoalState().getData()[0].size(); x++) {
            if (problem->getGoalState().getData()[y][x] == num) {
                f.first = y;
                f.second = x;
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

// Euclidean

int EuclideanDistanceSearch::heuristic(const State& currentState) {
    int totalHeuristic = 0;
    std::vector<std::vector<int>> goalState = problem->getGoalState().getData();
    for(int y = 0; y < goalState.size(); y++){
        for(int x = 0; x< goalState[y].size(); x++){
            int value = currentState.getData()[y][x];
            std::pair coordsFinal = indexInFinal(value);
            std::pair coordsInitial = std::make_pair(y,x);
            totalHeuristic += calculateEuclidean(coordsFinal, coordsInitial);
            std::cout << "total heuristic is for (" << coordsInitial.first << ","<< coordsInitial.second <<") and (" << 
            coordsFinal.first << ","<< coordsFinal.second << ") is " << totalHeuristic << std::endl;
        }
    }
    return totalHeuristic;
}

int EuclideanDistanceSearch::calculateEuclidean(std::pair<int,int> pos1, std::pair<int,int> pos2){
    return sqrt(pow((pos2.first-pos1.first),2) + pow((pos2.second-pos1.second),2));
    //sqrt((x2-x1)^2+(y2-y1)^2)
}

// Misplaced Tile

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



int MisplacedTileInformedSearch::calculateManhattan(std::pair<int, int> value1, std::pair<int, int> value2) {
    return std::abs(value1.first - value2.first) + std::abs(value2.second - value2.second);
}







