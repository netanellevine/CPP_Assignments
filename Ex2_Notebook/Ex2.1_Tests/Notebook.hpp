#ifndef EX2_1_CPP_NOTEBOOK_HPP
#define EX2_1_CPP_NOTEBOOK_HPP

#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

namespace ariel {
    class Notebook {

    public:
        void write(int page, int row, int column, Direction dir, string str);

        string read(int page, int row, int column, Direction dir, int length);

        void erase(int page, int row, int column, Direction dir, int length);

        void show(int page);
    };
}

#endif //EX2_1_CPP_NOTEBOOK_HPP
