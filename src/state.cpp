#include "state.hpp"

State::State() {
    this->data = {};
    this->parent = nullptr;
    this->depth = 0;
    this->cost = 0;
}

State::State(const State& state) {
    this->data = state.data;
    this->parent = state.parent == nullptr ? nullptr : new State(*state.parent);
    this->depth = state.depth;
    this->cost = state.cost;
}

State& State::operator=(const State& rhs) {
    if (this != &rhs) {
        this->data = rhs.data;
        if (this->parent != nullptr) delete this->parent;
        this->parent = rhs.parent == nullptr ? nullptr : new State(*rhs.parent);
        this->depth = rhs.depth;
        this->cost = rhs.cost;
    }
    return *this;
}

State::~State() {
    delete parent;
}

std::vector<std::vector<int>> State::getData() const {
    return this->data;
}

State* State::getParent() const {
    return this->parent;
}

int State::getDepth() const {
    return this->depth;
}

int State::getCost() const {
    return this->cost;
}

void State::setData(std::vector<std::vector<int>>& data) {
    this->data = data;
}

void State::setParent(State* parent) {
    this->parent = parent;
}

void State::setDepth(int depth) {
    this->depth = depth;
}

void State::setCost(int cost) {
    this->cost = cost;
}

std::pair<int, int> State::findBlank() const {
    std::pair<int, int> blankLocation;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            if (data[i][j] == 0) {
                blankLocation.first = i;
                blankLocation.second = j;
            }
        }
    }
    return blankLocation;
}

bool State::operator<(const State& rhs) const {
    return cost < rhs.cost;
}

bool State::operator>(const State& rhs) const {
    return cost > rhs.cost;
}

bool State::operator<=(const State& rhs) const {
    return cost <= rhs.cost;
}

bool State::operator>=(const State& rhs) const {
    return cost >= rhs.cost;
}

bool State::operator==(const State& rhs) const {
    return data == rhs.data;
}