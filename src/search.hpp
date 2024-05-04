#ifndef STATE_H
#define STATE_H
#include "problem.hpp"

class Search {
    private:
        virtual int heuristic(const State&) = 0;
        Problem problem;
    public:
        Search(const Problem&);
        State doSearch();
};

#endif