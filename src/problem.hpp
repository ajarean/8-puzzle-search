#ifndef PROBLEM_H
#define PROBLEM_H
#include "state.hpp"

class Problem {
    private:
        State* startState;
        State* goalState;
        State* moveBlankUp(State* s);
        State* moveBlankDown(State* s);
        State* moveBlankLeft(State* s);
        State* moveBlankRight(State* s);
    public:
        Problem(const std::vector<std::vector<int>>& start, const std::vector<std::vector<int>>& goal);
        ~Problem();
        std::vector<State*> expand(State* s);
        bool goalTest(State* s);

};

#endif