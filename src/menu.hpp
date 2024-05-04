#ifndef MENU_H
#define MENU_H
#include "problem.hpp"
#include "state.hpp"

class Menu {
    private:
        Problem* problem;
        int problemWidth;
    public:
        Menu();
        void start();
        void printWelcomeMessage() const;
        void printOptions() const;
        void handleDefaultPuzzle();
        void handleCustomPuzzle();
        // void displayState(State& s) const;

};

#endif