#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

#include <string>
using namespace std;

TEST_CASE("Bad input"){
    Notebook notebook;
    int page = -1;
    int row = 0;
    int column = 1;
    for (int i = 1; i < 4; ++i) {
        CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, "%"));
        CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, 5));
        CHECK_THROWS(notebook.erase(page, row, column, Direction::Horizontal, 5));
        column += row;
        row += (2 * page);
        page += i;
    }
    std::string s = "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT";
    CHECK_THROWS(notebook.write(10, 10, 10, Direction::Horizontal, s));
    CHECK_THROWS(notebook.read(10, 10, 10, Direction::Horizontal, 120));
    CHECK_THROWS(notebook.erase(10, 10, 10, Direction::Horizontal, 120));
    CHECK_THROWS(notebook.show(-5));
}

TEST_CASE("Write and Read TEST -> GOOD_INPUT") {
    Notebook notebook;
    notebook.write(0, 0, 0, Direction::Horizontal, "notebook write function test");
            CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 28) == "notebook write function test");
    notebook.write(10, 10, 10, Direction::Horizontal, "this is fun");
            CHECK(notebook.read(10, 10, 10, Direction::Horizontal, 11) == "this is fun");
    notebook.write(500, 500, 20, Direction::Horizontal, "now let's check in the middle");
            CHECK(notebook.read(500, 500, 20, Direction::Horizontal, 13) == "in the middle");
    string out;
    for (int i = 65; i < 123; i++) {
        char changing_ch = i;
        string tmp_string(1, changing_ch);
        notebook.write(1, 0, i - 65, Direction::Horizontal, tmp_string);
        out += i;
                CHECK(notebook.read(1, 0, 0, Direction::Horizontal, i - 64) == out);

    }
}

TEST_CASE("Good input -> some tricks") {
    Notebook notebook;
    notebook.write(0, 0, 0, ariel::Direction::Horizontal, "Hey there!!");
            CHECK(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 11) == "Hey there!!");
    notebook.write(0, 0, 0, ariel::Direction::Horizontal, "How r u?");
            CHECK(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 8) == "How r u?");
    notebook.write(5, 100, 20, ariel::Direction::Horizontal, "I am fine thank you");
            CHECK(notebook.read(5, 100, 20, ariel::Direction::Horizontal, 4) == "I am");
            CHECK(notebook.read(5, 100, 20, ariel::Direction::Horizontal, 19) == "I am fine thank you");
    notebook.erase(5, 100, 25, ariel::Direction::Horizontal, 5);
            CHECK(notebook.read(5, 100, 20, ariel::Direction::Horizontal, 19) == "I am ~~~~~thank you");
            CHECK(notebook.read(2, 0, 0, ariel::Direction::Horizontal, 5) == "_____");
            CHECK(notebook.read(2, 0, 0, ariel::Direction::Vertical, 5) == "_\n"
                                                                    "_\n"
                                                                    "_\n"
                                                                    "_\n"
                                                                    "_\n");
}