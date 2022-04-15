#include <iostream>
#include <unordered_map>

using namespace std;

namespace ariel {
    class Row {
    public:
        unordered_map<unsigned int, char> row;
    };
}