/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Matrix.hpp"
using namespace zich;

int main() {
  
  std::vector<double> identity = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<double> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix a{identity, 3, 3};  // constructor taking a vector and a matrix size
//  cout << a + a << endl << endl;
  /* prints [1 0 0]
            [0 1 0]
            [0 0 1]*/

//  cout << (-a) << endl << endl;
  /* prints [-1 0 0]
            [0 -1 0]
            [0 0 -1]*/
//  cout << (3*a) << endl << endl;
  /* prints [3 0 0]
            [0 3 0]
            [0 0 3]*/

  Matrix b{arr, 3, 3};
//  a += b;
string c = (a >= b) ? "b is greater": "b is not greater";
//  cout << (a+b) << endl << endl;  // prints the 0 matrix
  cout << c << endl << endl;
//  cout << ++a << endl << endl;
//a++;
//  cout << a << endl << endl;
  /* prints [6 0 0]
            [0 6 0]
            [0 0 6]*/

  cout << "End of demo!" << endl;
  return 0;
}
