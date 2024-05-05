#ifndef MENU_H
#define MENU_H
#include "problem.hpp"
#include "state.hpp"
#include "search.hpp"
#include <iostream>
#include <vector>

class Menu {
    private:
        Problem* problem;
        int problemWidth;
        int nodesExpanded;
        int maxNodesQueued;
        int goalNodeDepth;
        std::vector<std::vector<int>> makeGoal();
    public:
        Menu();
        void start();
        void handleDefaultPuzzle();
        void handleCustomPuzzle();
};

#endif