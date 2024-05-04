#include "problem.hpp"
#include <iostream>

Problem::Problem() {
    this->startState = nullptr;
    this->goalState = nullptr;
}

Problem::Problem(const std::vector<std::vector<int>>& start, const std::vector<std::vector<int>>& goal) {
    this->startState = new State(start);
    this->goalState = new State(goal);
}

Problem::~Problem() {
    delete startState;
    delete goalState;
}

State Problem::getStartState() const {
    return *this->startState;
}

State Problem::getGoalState() const {
    return *this->goalState;
}

void Problem::setStartState(State& s) {
    this->startState = &s;
}

void Problem::setGoalState(State& s) {
    this->goalState = &s;
}

std::optional<State> Problem::moveBlankUp(State& s) const {
    std::pair<int, int> blank = s.findBlank();
    std::vector<std::vector<int>> newData = s.getData();
    if (blank.first == 0) return std::nullopt;
    std::swap(newData[blank.first][blank.second], newData[blank.first-1][blank.second]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

std::optional<State> Problem::moveBlankDown(State& s) const {
    std::pair<int, int> blank = s.findBlank();
    std::vector<std::vector<int>> newData = s.getData();
    if (blank.first == newData.size()-1) return std::nullopt;
    std::swap(newData[blank.first][blank.second], newData[blank.first+1][blank.second]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

std::optional<State> Problem::moveBlankLeft(State& s) const {
    std::pair<int, int> blank = s.findBlank();
    std::vector<std::vector<int>> newData = s.getData();
    if (blank.second == 0) return std::nullopt;
    std::swap(newData[blank.first][blank.second], newData[blank.first][blank.second-1]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

std::optional<State> Problem::moveBlankRight(State& s) const {
    std::pair<int, int> blank = s.findBlank();
    std::vector<std::vector<int>> newData = s.getData();
    if (blank.second == newData[0].size()-1) return std::nullopt;
    std::swap(newData[blank.first][blank.second], newData[blank.first][blank.second+1]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

std::vector<State> Problem::expand(State& s) const {
    std::vector<State> expansions;
    std::optional<State> upState = moveBlankUp(s);
    std::optional<State> downState = moveBlankDown(s);
    std::optional<State> leftState = moveBlankLeft(s);
    std::optional<State> rightState = moveBlankRight(s);
    if (upState) expansions.push_back(upState.value());
    if (downState) expansions.push_back(downState.value());
    if (leftState) expansions.push_back(leftState.value());
    if (rightState) expansions.push_back(rightState.value());
    return expansions;
}

bool Problem::goalTest(const State& s) const {
    return goalState->getData() == s.getData();
}