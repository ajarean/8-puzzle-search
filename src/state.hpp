#ifndef NODE_H
#define NODE_H

#include <vector>

class State {
    private:
        std::vector<std::vector<int>> data;
        State* parent;
        int depth;
        int cost;
    public:
        State();
        State(const std::vector<std::vector<int>>& data) : data(data), parent(nullptr), depth(0), cost(0) {};
        State(const std::vector<std::vector<int>>& data, State* parent, int depth) : data(data), parent(parent), depth(depth), cost(0) {};
        State(const State& state);
        State& operator=(const State& rhs);
        ~State();
        std::vector<std::vector<int>> getData() const;
        State* getParent() const;
        int getDepth() const;
        int getCost() const;
        void setData(std::vector<std::vector<int>>& data);
        void setParent(State* parent);
        void setDepth(int depth);
        void setCost(int cost);
        std::pair<int, int> findBlank() const;
        bool operator<(const State& rhs) const;
        bool operator<=(const State& rhs) const;
        bool operator>(const State& rhs) const;
        bool operator>=(const State& rhs) const;
        bool operator==(const State& rhs) const;
};

#endif