#ifndef PROBLEM_H
#define PROBLEM_H
#include "state.hpp"
#include <optional>

class Problem {
    private:
        State* startState;
        State* goalState;
        std::optional<State> moveBlankUp(State& s) const;
        std::optional<State> moveBlankDown(State& s) const;
        std::optional<State> moveBlankLeft(State& s) const;
        std::optional<State> moveBlankRight(State& s) const;
    public:
        Problem(const std::vector<std::vector<int>>& start, const std::vector<std::vector<int>>& goal);
        ~Problem();
        std::vector<State> expand(State& s) const;
        bool goalTest(const State& s) const;

};

#endif