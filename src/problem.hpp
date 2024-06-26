#ifndef PROBLEM_H
#define PROBLEM_H
#include "state.hpp"

class Problem {
    private:
        State* startState;
        State* goalState;
        std::optional<State> moveBlankUp(State& s) const;
        std::optional<State> moveBlankDown(State& s) const;
        std::optional<State> moveBlankLeft(State& s) const;
        std::optional<State> moveBlankRight(State& s) const;
    public:
        Problem();
        Problem(const std::vector<std::vector<int>>& start, const std::vector<std::vector<int>>& goal);
        Problem(const Problem&);
        ~Problem();
        Problem& operator=(const Problem&);
        State getStartState() const;
        State getGoalState() const;
        void setStartState(State&);
        void setGoalState(State&);
        std::vector<State> expand(State&) const;
        bool isGoal(const State&) const;

};

#endif