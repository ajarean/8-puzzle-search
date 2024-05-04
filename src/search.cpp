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
        pqueue.pop();
        if (problem->isGoal(currState)) return currState;
        std::vector<State> expanded = problem->expand(currState);
        for (State nextState : expanded) {
            if (!seen.contains(nextState)) {
                nextState.setCost(nextState.getDepth() + heuristic(nextState));
                pqueue.push(nextState);
            }
        }
        seen.insert(currState);
    }
    return std::nullopt;
}