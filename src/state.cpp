#include <state.hpp>

std::pair<int, int> State::findBlank() {
    std::pair<int, int> blankLocation;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            if (data[i][j] == 0) {
                blankLocation.first = i;
                blankLocation.second = j;
            }
        }
    }
    return blankLocation;
}