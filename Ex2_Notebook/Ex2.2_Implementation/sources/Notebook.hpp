#ifndef EX2_1_CPP_NOTEBOOK_HPP
#define EX2_1_CPP_NOTEBOOK_HPP

#include "Direction.hpp"
#include "Page.hpp"
#include <iostream>
#include <stdexcept>

#define true 1
#define false 0

using namespace std;
using namespace ariel;

namespace ariel {
    class Notebook {
    private:
        unordered_map<unsigned int, Page> notebook;
    public:
        void check_before_write(int page_num, int row_num, int col_num, Direction dir, const string & str);

        void writeHorizontal(unsigned int page_num, unsigned int row_num, unsigned int col_num, const string & str);

        void writeVertical(unsigned int page_num, unsigned int row_num, unsigned int col_num, const string & str);

        void write(int page, int row, int column, Direction dir, const string & str);

        string readHorizontal(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length);

        string readVertical(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length);

        string read(int page, int row, int column, Direction dir, int length);

        void eraseHorizontal(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length);

        void eraseVertical(unsigned int page_num, unsigned int row_num, unsigned int col_num, int length);

        void erase(int page, int row, int column, Direction dir, int length);

        void show(int page);
    };
}

#endif //EX2_1_CPP_NOTEBOOK_HPP
