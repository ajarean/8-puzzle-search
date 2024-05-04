#include "search.hpp"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> testData = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    std::vector<std::vector<int>> testData2 = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};

    Problem testProblem(testData2, testData);
    Search testSearch(testProblem);
    // State s = testProblem.getStartState();
    // std::vector<State> v = testProblem.expand(s);
    // for (State state : v) {
    //     std::cout << testProblem.goalTest(state) << '\n';
    // }

    // std::vector<State> v2 = testProblem.expand(v[0]);
    // for (State state : v2) {
    //     std::cout << testProblem.goalTest(state) << '\n';
    // }

    std::optional<State> found = testSearch.doSearch();
    if (found) {
        State finalState = found.value();
        std::cout << "Yay!" << '\n';
        return 0;
    }
    std::cout << "Nay" << '\n';



    return 0;
} 