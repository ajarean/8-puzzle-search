#include "search.hpp"
#include "menu.hpp"

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