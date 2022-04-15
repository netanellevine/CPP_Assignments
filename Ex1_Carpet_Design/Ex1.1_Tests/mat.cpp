#include <iostream>
#include <stdexcept>

namespace ariel{
    std::string mat(int row, int col, char c1, char c2){
        if (row % 2 == 0 || col % 2 == 0){
            throw std::invalid_argument{"The Matrix should hold only odd parameters."};
        }
        if (row <= 0 || col <= 0){
            throw std::invalid_argument{"The Matrix should hold only positive parameters."};
        }
    return "My beautiful carpet";
}
}