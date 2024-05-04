#ifndef STATE_H
#define STATE_H
#include "problem.hpp"

class Search {
    private:
        virtual int heuristic(const State&);
        Problem* problem;
    public:
        Search(Problem&);
        std::optional<State> doSearch();
};

#endif