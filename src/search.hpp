#ifndef STATE_H
#define STATE_H
#include "problem.hpp"
#include <cstdlib>

class Search {
    private:
        virtual int heuristic(const State&) = 0;

    protected:
        Problem problem;
        
    public:
        
        Search(const Problem&);
        State doSearch(const Problem&);
        friend std::pair<int, int> indexInFinal(int , Problem& );
};

class MisplacedTileInformedSearch: public Search {
    private:
        int heuristic(const State&);
    
    public:
};

#endif