#ifndef STATE_H
#define STATE_H
#include "problem.hpp"
#include <cstdlib>

class Search {
    protected:
        virtual int heuristic(const State&);
        Problem* problem;
        std::pair<int, int> indexInFinal(int);
        int totalNodes;
        int maxQueue;
        int solutionDepth;

    public:
        int getTotalNodes() const;
        int getMaxQueue() const;
        int getSolutionDepth() const;
        Search(Problem* p) : problem(p), totalNodes(0), maxQueue(0), solutionDepth(0) {};
        std::optional<State> doSearch();
        
};

class UniformCostSearch: public Search {
    private:
        int heuristic(const State&) override;

    public:
        UniformCostSearch(Problem* p) : Search(p) {}
};

class EuclideanDistanceSearch: public Search {
    private:
        int heuristic(const State&);
        int calculateEuclidean(std::pair<int,int>, std::pair<int,int>);
    public:
        EuclideanDistanceSearch(Problem* p) : Search(p) {};
};

class MisplacedTileInformedSearch: public Search {
    private:
        int heuristic(const State&) override;
        int calculateManhattan(std::pair<int, int> , std::pair<int, int> );
    
    public:
        MisplacedTileInformedSearch(Problem* p) : Search(p) {};

};

#endif