#ifndef STATE_H
#define STATE_H
#include "problem.hpp"
#include <cstdlib>

class Search {
    private:
        virtual int heuristic(const State&) = 0;

    protected:
        Problem* problem;
        std::pair<int, int> indexInFinal(int);
        
    public:
        
        Search(Problem* p) : problem(p) {}
        std::optional<State> doSearch();
        
};

class UniformCostSearch: public Search {
    private:
        int heuristic(const State&) {return 0;}

    public:
        UniformCostSearch(Problem* p) : Search(p) {}
};

class EuclideanDistanceSearch: public Search {
    private:
        int heuristic(const State&);
        int calculateEuclidean(std::pair<int,int>, std::pair<int,int>);
    public:
        EuclideanDistanceSearch(Problem* p) : Search(p) {};
        // int calculateEuclidean(std::pair<int,int>, std::pair<int,int>);
};

class MisplacedTileInformedSearch: public Search {
    private:
        int heuristic(const State&);
        int calculateManhattan(std::pair<int, int> , std::pair<int, int> );
    
    public:
        MisplacedTileInformedSearch(Problem* p) : Search(p) {};

};

#endif