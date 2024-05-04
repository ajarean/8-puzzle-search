#ifndef STATE_H
#define STATE_H
#include "problem.hpp"

class Search {
    private:
        virtual int heuristic(const State&) = 0;
    public:
        Search();
        State& doSearch(const Problem&);
};

#endif