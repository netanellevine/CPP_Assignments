
#include <iostream>
#include "mat.cpp"
using namespace ariel;

int main() {
    std::string ans;
    ans = ariel::mat(9, 7, '@', '-');
    std::cout << ans << std::endl;

    ans = ariel::mat(19, 19, 'A', '*');
    std::cout << ans << std::endl;

    ans = ariel::mat(7, 21, '~', 'T');
    std::cout << ans << std::endl;

    ans = ariel::mat(15, 15, '<', '>');
    std::cout << ans << std::endl;

    ans = ariel::mat(31, 21, 'X', 'O');
    std::cout << ans << std::endl;
    return 0;
}
