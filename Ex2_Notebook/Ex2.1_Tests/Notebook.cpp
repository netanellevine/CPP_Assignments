#include "Notebook.hpp"

using namespace ariel;

void Notebook::write(int page, int row, int column, Direction dir, string str){
    if (page < 0 || row < 0 || column < 0){
        throw invalid_argument {"Page/Row/Column must be a non-negative Integer number!"};
    }
    if (str.length() > 100 && dir == Direction::Horizontal){
        throw invalid_argument {"Writing Horizontally is possible only when the String length is less then 100 characters!"};
    }
}
string Notebook::read(int page, int row, int column, Direction dir, int length){
    if (page < 0 || row < 0 || column < 0 || length < 0){
        throw invalid_argument {"Page/Row/Column/Length must be a non-negative Integer number!"};
    }
    return "";
}
void Notebook::erase(int page, int row, int column, Direction dir, int length){
    if (page < 0 || row < 0 || column < 0 || length < 0){
        throw invalid_argument {"Page/Row/Column/Length must be a non-negative Integer number!"};
    }
}
void Notebook::show(int page){
    if (page < 0){
        throw invalid_argument {"Page must be a non-negative Integer number!"};
    }
}

