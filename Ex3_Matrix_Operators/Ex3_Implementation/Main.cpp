#include <iostream>
#include "sources/Matrix.hpp"

using namespace std;
using namespace zich;


int main() {
    cout << endl << endl << endl;
    Matrix a; // default constructor.
    cout << "matrix a: identity 5x5\n" << a << endl << endl;

    Matrix b (3, 3); // generate 4x4 matrix of zeros.
    cout << "matrix b: zeros 3x3\n" << b << endl << endl;

    vector<double> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix c (vec1, 3, 3);
    cout << "matrix c:  3x3\n" << c << endl << endl;

    cout << "matrix c * b:\n" << c * b << endl << endl; // zero matrix

    cout << "matrix c * (++b):\n" << c * (++b) << endl << endl; // won't be zero because b was incremented by 1 (prefix).

    cout << "matrix c * (-(++b) * 7):\n" << c * (-(++b) * 7) << endl << endl;

    cout << "matrix c * (-(-(++b) + 36) * -c):\n" << c * (-(-(++b) + 36) * -c) << endl << endl;

    cout << "matrix a + a:\n" << a + a << endl << endl;

    cout << "matrix ( -(a + a + a) * -(a + 15)):\n" << ( -(a + a + a) * -(a + 15)) << endl << endl;

    cout << "(c == b):\n" << (c == b) << endl << endl;

    cout << "(c < b):\n" << (c < b) << endl << endl;

    cout << "(c >=b):\n" << (c >= b) << endl << endl;

    vector<double>  vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<double>  vec4 = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Matrix d (vec3, 4, 3);
    Matrix e (vec4, 4, 3);

    cout << "(d == e): " << (d == e) << endl;
    cout << "(d < e): " << (d < e) << endl;
    cout << "(d > e): " << (d > e) << endl;
    cout << "(d >= e): " << (d >= e) << endl;
    cout << "(d <= e): " << (d <= e) << endl;
    cout << "(d != e): " << (d != e) << endl;

    cout << endl << "End of Main!" << endl;



    return 0;
}
