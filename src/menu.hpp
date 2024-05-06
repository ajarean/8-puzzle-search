#ifndef MENU_H
#define MENU_H
#include "problem.hpp"
#include "state.hpp"
#include "search.hpp"

class Menu {
    private:
        Problem* problem;
        int problemWidth;
        std::vector<std::vector<int>> makeGoal();
        void printTrace(State&);
    public:
        Menu();
        void start();
        void handleDefaultPuzzle();
        void handleCustomPuzzle();
};

#endif