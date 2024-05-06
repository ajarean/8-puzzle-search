#include "problem.hpp"

Problem::Problem() {
    this->startState = nullptr;
    this->goalState = nullptr;
}

Problem::Problem(const std::vector<std::vector<int>>& start, const std::vector<std::vector<int>>& goal) {
    this->startState = new State(start);
    this->goalState = new State(goal);
}

Problem::Problem(const Problem& p) {
    this->startState = new State(*p.startState);
    this->goalState = new State(*p.goalState);
}

Problem::~Problem() {
    delete startState;
    delete goalState;
}

Problem& Problem::operator=(const Problem& rhs) {
    if (this != &rhs) {
        this->startState = new State(*rhs.startState);
        this->goalState = new State(*rhs.goalState);
    }
    return *this;
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
    //Checks if it is possible to move the blank up
    if (blank.first == 0) return std::nullopt;
    //Swaps the blank with the number above it
    std::swap(newData[blank.first][blank.second], newData[blank.first-1][blank.second]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

std::optional<State> Problem::moveBlankDown(State& s) const {
    std::pair<int, int> blank = s.findBlank();
    std::vector<std::vector<int>> newData = s.getData();
    //Checks if it is possible to move the blank down
    if (blank.first == newData.size()-1) return std::nullopt;
    //Swaps the blank with the number below it
    std::swap(newData[blank.first][blank.second], newData[blank.first+1][blank.second]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

std::optional<State> Problem::moveBlankLeft(State& s) const {
    std::pair<int, int> blank = s.findBlank();
    std::vector<std::vector<int>> newData = s.getData();
    //Checks if it is possible to move the blank to the left
    if (blank.second == 0) return std::nullopt;
    //Swaps the blank with the number to its left
    std::swap(newData[blank.first][blank.second], newData[blank.first][blank.second-1]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

//Attempts to move the blank right on a given state.
std::optional<State> Problem::moveBlankRight(State& s) const {
    std::pair<int, int> blank = s.findBlank();
    std::vector<std::vector<int>> newData = s.getData();
    //Checks if it is possible to move the blank to the right
    if (blank.second == newData[0].size()-1) return std::nullopt;
    //Swaps the blank with the number to its right
    std::swap(newData[blank.first][blank.second], newData[blank.first][blank.second+1]);
    State* parent = new State(s);
    return State(newData, parent, parent->getDepth()+1);
}

//Applies all four operators to a given state. Returns all possible states formed by applying operators to a given state.
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

bool Problem::isGoal(const State& s) const {
    return *this->goalState == s;
}