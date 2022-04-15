#include <iostream>
#include <unordered_map>
#include "Row.hpp"
using namespace std;

namespace ariel {
    class Page {
    public:
        unordered_map<unsigned int, Row> page;
    };
}