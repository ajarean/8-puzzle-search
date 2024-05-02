#ifndef NODE_H
#define NODE_H

#include <vector>

class State {
    private:
        std::vector<std::vector<int>> data;
        State* parent;
        int depth;
    public:
        State(const std::vector<std::vector<int>>& data) : data(data) {};
        State(const std::vector<std::vector<int>>& data, State* parent, int depth) : data(data), parent(parent), depth(depth) {};
        ~State();
};

#endif