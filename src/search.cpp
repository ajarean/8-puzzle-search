#include "search.hpp"
#include <queue>
#include <set>
#include <iostream>
int Search::heuristic(const State& state) {
    return 0;
}

Search::Search(Problem& p) {
    this->problem = &p;
}

std::optional<State> Search::doSearch() {
    State start = problem->getStartState();
    std::priority_queue<State> pqueue;
    std::set<State> seen;
    pqueue.push(problem->getStartState());
    while (!pqueue.empty()) {
        State currState = pqueue.top();
        std::cout << "Depth: " << currState.getDepth() << ", ";
        std::cout << pqueue.size() << " states in frontier" << std::endl << std::endl;
        pqueue.pop();
        if (problem->isGoal(currState)) return currState;
        std::vector<State> expanded = problem->expand(currState);
        std::cout << "f(n) of all frontier states: ";
        for (State nextState : expanded) {
            if (!seen.contains(nextState)) {
                std::cout << "   " << nextState.getDepth() << " + " << heuristic(nextState) << std::endl;
                nextState.setCost(nextState.getDepth() + heuristic(nextState));
                pqueue.push(nextState);
            }
        }
        std::cout << "\n\n";
        seen.insert(currState);
    }
    return std::nullopt;
}