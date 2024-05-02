#include <problem.hpp>

State* Problem::moveBlankUp(State* s) {
    std::pair<int, int> blank = s->findBlank();
    std::vector<std::vector<int>> newData = s->getData();
    if (blank.first == 0) return nullptr;
    std::swap(newData[blank.first][blank.second], newData[blank.first-1][blank.second]);
    return new State(newData, s, s->getDepth()+1);
}

State* Problem::moveBlankDown(State* s) {
    std::pair<int, int> blank = s->findBlank();
    std::vector<std::vector<int>> newData = s->getData();
    if (blank.first == newData.size()-1) return nullptr;
    std::swap(newData[blank.first][blank.second], newData[blank.first+1][blank.second]);
    return new State(newData, s, s->getDepth()+1);
}

State* Problem::moveBlankLeft(State* s) {
    std::pair<int, int> blank = s->findBlank();
    std::vector<std::vector<int>> newData = s->getData();
    if (blank.second == 0) return nullptr;
    std::swap(newData[blank.first][blank.second], newData[blank.first][blank.second-1]);
    return new State(newData, s, s->getDepth()+1);
}

State* Problem::moveBlankRight(State* s) {
    std::pair<int, int> blank = s->findBlank();
    std::vector<std::vector<int>> newData = s->getData();
    if (blank.second == newData[0].size()-1) return nullptr;
    std::swap(newData[blank.first][blank.second], newData[blank.first][blank.second+1]);
    return new State(newData, s, s->getDepth()+1);
}