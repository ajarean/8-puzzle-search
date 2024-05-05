#include "search.hpp"
#include "menu.hpp"

/**
 * 
 *  LINK TO THE GITHUB REPO: https://github.com/ajarean/8-puzzle-search
 * 
 *  TEAM MEMBERS:
 *  Komay Sugiyama (ksugi014)
 *  Adithya Iyer (aiyer026)
 *  Andy Jarean (ajare002)
 *  Tingxuan Wu (twu148)
 * 
 * 
*/

int main(int argc, char* argv[]) {
    int choice = 1;
    while (choice==1) {
        Menu menu;
        menu.start();
        std::cout << "\nWould you like to try another search?\nIf so, press 1. Else, input a different number: \n" << std::endl;
        choice = 0;
        std::cin >> choice;
    }
    std::cout << "Thank you! :)" << std::endl;
    
    return 0;
} 