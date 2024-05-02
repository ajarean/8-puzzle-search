#ifndef PROBLEM_H
#define PROBLEM_H
#include <state.cpp>

class Problem {
    private:
        State* startState;
        State* goalState;
        State* moveBlankUp(State* s);
        State* moveBlankDown(State* s);
        State* moveBlankLeft(State* s);
        State* moveBlankRight(State* s);
    public:
        Problem(State* startState);
        ~Problem();
        std::vector<State*> expand(State* s);
        bool goalTest(State* s);

};

#endif