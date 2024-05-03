#include "state.hpp"

State::State(const State& state) {
    this->data = state.data;
    this->parent = state.parent == nullptr ? nullptr : new State(state.parent->data, state.parent->parent, state.parent->depth);
    this->depth = state.depth;
}

State& State::operator=(const State& rhs) {
    if (this != &rhs) {
        this->data = rhs.data;
        this->parent = rhs.parent == nullptr ? nullptr : new State(rhs.parent->data, rhs.parent->parent, rhs.parent->depth);
        this->depth = rhs.depth;
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

void State::setData(std::vector<std::vector<int>>& data) {
    this->data = data;
}

void State::setParent(State* parent) {
    this->parent = parent;
}

void State::setDepth(int depth) {
    this->depth = depth;
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