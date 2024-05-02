#include <state.hpp>

std::vector<std::vector<int>> State::getData() {
    return this->data;
}

State* State::getParent() {
    return this->parent;
}

int State::getDepth() {
    return this->depth;
}

void State::setData(const std::vector<std::vector<int>>& data) {
    this->data = data;
}

void State::setParent(State* parent) {
    this->parent = parent;
}

void State::setDepth(int depth) {
    this->depth = depth;
}

std::pair<int, int> State::findBlank() {
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