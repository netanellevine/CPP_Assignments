//
// Created by Netanel Levine on 04/04/2022.
//

#include "doctest.h"
#include "sources/Matrix.hpp"

using namespace std;
using namespace zich;
bool dummy;

TEST_CASE("Constructors"){
    vector<double> vec1 = {}; // 0x0
    vector<double> vec2 = {1}; // 1x1
    vector<double> vec3 = {1, 1}; // 1x2
    vector<double> vec4 = {1, 1, 1, 1}; // 2x2
    vector<double> vec5 = {1, 1, 1, 1, 1, 1}; // 2x3
    vector<double> vec6 = {1, 1, 1, 1, 1, 1}; // 3x2
    vector<double> vec7 = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 3x3
    vector<double> big1;
    big1.assign(10000, 9999999); // 10000x10000 -> 10Kx10K
//    vector<double> big2;
//    big2.assign(1000000, 9999999); // 1000000x1000000 -> 1Mx1M
//    vector<double> big3;
//    big3.assign(100000000, 9999999); // 100000000x100000000 -> 100Mx100M


    // invalid row/col parameters
    CHECK_THROWS(Matrix(vec1, 0, 0));
    CHECK_THROWS(Matrix(vec1, 1, 0));
    CHECK_THROWS(Matrix(vec1, 0, 1));

    // vector is smaller than (rows X columns)
    CHECK_THROWS(Matrix(vec1, 3, 3));
    CHECK_THROWS(Matrix(vec2, 3, 3));

    // valid parameters
    CHECK_NOTHROW(Matrix(vec2, 1, 1));
    CHECK_NOTHROW(Matrix(vec3, 1, 2));
    CHECK_NOTHROW(Matrix(vec4, 2, 2));
    CHECK_NOTHROW(Matrix(vec5, 2, 3));
    CHECK_NOTHROW(Matrix(vec6, 3, 2));
    CHECK_NOTHROW(Matrix(vec7, 3, 3));
    CHECK_NOTHROW(Matrix(big1, 100, 100));
    CHECK_NOTHROW(Matrix(big1, 5000, 2));
//    CHECK_NOTHROW(Matrix(big2, 1000, 1000));
//    CHECK_NOTHROW(Matrix(big3, 10000, 10000));

    cout << "-(1\\9) End of the constructors tests -> good job!" << endl;
}

TEST_CASE("Arithmetic operators"){
    vector<double>  vec_i4 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    vector<double>  vec_i44 = {2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2};
    vector<double>  vec_i3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double>  vec1 = {1, 2, 3, 4, 5, 6};
    vector<double>  vec2 = {6, 5, 4, 3, 2, 1};
    vector<double>  vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double>  vec4 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<double>  vec5 = {7, 7, 7, 7, 7, 7};
    vector<double>  vec6 = {10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<double>  vec7 = {7, 7, 7, 7, 6, 7};
    vector<double>  vec8 = {7, 7, 7, 8, 6, 7};
    vector<double>  vec9 = {22, 28, 49, 64};
    vector<double>  vec10 = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    vector<double>  vec11 = {30, 24, 18, 84, 69, 54, 138, 114, 90};
    vector<double>  vec12 = {90, 114, 138, 54, 69, 84, 18, 24, 30};
    Matrix mat1(vec_i4, 4, 4);
    Matrix mat2(vec_i3, 3, 3);
    Matrix mat3(vec1, 2, 3);
    Matrix mat4(vec1, 3, 2);
    Matrix mat5(vec2, 2, 3);
    Matrix mat6(vec2, 3, 2);
    Matrix mat7(vec3, 3, 3);
    Matrix mat8(vec4, 3, 3);
    Matrix mat1p1(vec_i44, 4, 4);
    Matrix mul_3_4(vec9, 2, 2);
    Matrix mul_7_7(vec10, 3, 3);
    Matrix mul_7_8(vec11, 3, 3);
    Matrix mul_8_7(vec12, 3, 3);

    SUBCASE("+ - operators") {

        SUBCASE("single matrix"){
            Matrix a = mat1 + 1;
            Matrix a_r = 1 + mat1;
            Matrix b = a - 1;
            Matrix c = -(1 - a);
            CHECK(a == mat1p1);
            CHECK(a_r == mat1p1);
            CHECK(b == mat1);
            CHECK(c == -mat1);
            b = 0 - mat3;
            CHECK(b == (-(mat3)));
            CHECK(-b != mat3);
            CHECK(mat3 == (+(-mat3)));

            Matrix d = (+(+(mat1 - 1) - 1));
            CHECK(d == mat1);
            d = +(-(+(+(mat1 - 1) - 1)) - 1);
            CHECK(d == mat1p1);

            vector<double> vec = {2, -1, 1, 1, 1, 2, 1, -1, 1, 1, 2, 1, -1, 1, 1, 2};
            Matrix mat (vec, 4, 4);
            CHECK (+mat == mat1p1);
            CHECK (-mat == -mat1p1);
        }

        SUBCASE("double matrix"){
            CHECK_THROWS(mat1 + mat2); // 4x4 + 3x3
            CHECK_THROWS(mat2 + mat1); // 3x3 + 4x4
            CHECK_THROWS(mat3 + mat4); // 2x3 + 3x2
            CHECK_THROWS(mat4 + mat3); // 3x2 + 2x3

            CHECK_NOTHROW(mat1p1 + mat1); // 4x4 + 4x4
            CHECK_NOTHROW(mat1 + mat1p1); // 4x4 + 4x4
            CHECK_NOTHROW(mat3 + mat5); // 2x3 + 2x3
            CHECK_NOTHROW(mat5 + mat3); // 2x3 + 2x3

            Matrix a = mat3 + mat5;
            Matrix b (vec5, 2, 3);
            CHECK(b == a);
            CHECK_EQ(a, b);

            Matrix c (vec7, 2, 3);
            CHECK_NE(a, c);
            CHECK(c != a);

            Matrix d (vec8, 2, 3);
            CHECK_NE(a, d);
            CHECK(d != a);

            a = mat7 + mat8;
            Matrix e (vec6, 3, 3);
            CHECK(e == a);
            CHECK_EQ(e, a);

            cout << "-(2\\9) End of + - operators -> good job!" << endl;
        }
    }

    SUBCASE("* operator"){

        SUBCASE("single matrix"){
            Matrix a = mat1 * 2;
            CHECK_EQ((mat1 + mat1), a);
            CHECK((mat1 + mat1) == a);
            a = 2 * mat1;
            CHECK_EQ((mat1 + mat1), a);
            CHECK((mat1 + mat1) == a);

            a = mat4 + mat4 + mat4 + mat4 + mat4;
            CHECK_EQ((mat4 * 5), a);
            CHECK((mat4 * 5) == a);
            CHECK_EQ((5 * mat4), a);
            CHECK((5 * mat4) == a);

            CHECK_EQ((mat4 * 1), mat4);
            CHECK((mat4 * 1) == mat4);
            CHECK_EQ((1 * mat4), mat4);
            CHECK((1 * mat4) == mat4);
        }

        SUBCASE("double matrix"){
            CHECK ((mat3 * mat4) == mul_3_4);
            CHECK_EQ ((mat3 * mat4), mul_3_4);
            CHECK_THROWS (dummy = (mat4 * mat3) != mul_3_4);

            CHECK((mat7 * mat7) == mul_7_7);
            CHECK_EQ((mat7 * mat7), mul_7_7);

            CHECK((mat7 * mat8) == mul_7_8);
            CHECK_EQ((mat7 * mat8), mul_7_8);
            CHECK((mat8 * mat7) != mul_7_8);
            CHECK_NE((mat8 * mat7), mul_7_8);

            CHECK((mat8 * mat7) == mul_8_7);
            CHECK_EQ((mat8 * mat7), mul_8_7);
            CHECK((mat7 * mat8) != mul_8_7);
            CHECK_NE((mat7 * mat8), mul_8_7);

            CHECK_THROWS(mat1 * mat2); // 4x4 * 3x3
            CHECK_THROWS(mat2 * mat1); // 3x3 * 4x4
            CHECK_THROWS(mat3 * mat5); // 2x3 * 2x3
            CHECK_THROWS(mat5 * mat3); // 2x3 * 2x3

            CHECK_NOTHROW(mat1p1 * mat1); // 4x4 * 4x4
            CHECK_NOTHROW(mat1 * mat1p1); // 4x4 * 4x4
            CHECK_NOTHROW(mat3 * mat4); // 2x3 * 3x2
            CHECK_NOTHROW(mat4 * mat3); // 3x2 * 2x3

            Matrix i3 = mat2;
            Matrix i4 = mat1;
            for (int i = 1; i < 200; ++i) {
                i3 *= i3;
                i4 *= i4;
                CHECK(i3 == mat2);
                CHECK_EQ(i3, mat2);
                CHECK(i4 == mat1);
                CHECK_EQ(i4, mat1);
                CHECK_THROWS(i3 * i4);
                CHECK_NOTHROW(i4 * i4);
                CHECK_THROWS(i4 * i3);
                CHECK_NOTHROW(i3 * i3);
            }

            cout << "-(3\\9) End of * operator -> good job!" << endl;
        }
    }

    SUBCASE("++ -- operators"){
        ++mat1;
        CHECK(mat1p1 == mat1);
        CHECK_EQ(mat1p1, mat1);

        Matrix mat1_copy = mat1++;
        CHECK(mat1p1 == mat1_copy);
        CHECK_EQ(mat1p1, mat1_copy);

        CHECK(mat1 != mat1_copy);
        CHECK_NE(mat1, mat1_copy);

        --mat1;
        CHECK(mat1p1 == mat1);
        CHECK_EQ(mat1p1, mat1);

        mat1_copy = mat1--;
        CHECK(mat1p1 == mat1_copy);
        CHECK_EQ(mat1p1, mat1_copy);

        CHECK(mat1_copy != mat1);
        CHECK_NE(mat1_copy, mat1);

        vector<double>  vec_t1;
        vector<double>  vec_t2;
        vec_t1.assign(625, 0);
        vector<double>  vec_plus_500;
        vec_plus_500.assign(625, 10000);

        Matrix a (vec_t1, 25, 25);
        Matrix c(vec_plus_500, 25, 25);
        for (int i = 0; i < 10000; ++i){
            ++a;
            vec_t2.assign(625, i + 1);
            Matrix b (vec_t2, 25, 25);
            CHECK(a == b);
            CHECK(b == a);
            CHECK_EQ(a, b);

            if(i != 9999){
                CHECK(a != c);
                CHECK(c != a);
                CHECK_NE(a, c);
            }
            else{
                CHECK(a == c);
                CHECK(c == a);
                CHECK_EQ(a, c);
            }
        }

        for (int i = 0; i < 10000 ; ++i) {
            vec_t2.assign(625, (10000 - i));
            Matrix b (vec_t2, 25, 25);
            CHECK(a == b);
            CHECK(b == a);
            CHECK_EQ(a, b);
            --a;
        }

        cout << "-(4\\9) End of ++ -- operators -> good job!" << endl;
    }

    SUBCASE("+= -= *= operators"){

        SUBCASE("single matrix"){
            vector<double>  vec_t1;
            vector<double>  vec_t2;
            vec_t1.assign(25, 0);
            vector<double>  vec_plus_500;
            vec_plus_500.assign(25, 10000);

            Matrix a (vec_t1, 5, 5);
            Matrix b (vec_plus_500, 5, 5);

            for (int i = 0; i < 10000; ++i){
                a += 1;
                vec_t2.assign(25, i + 1);
                Matrix c (vec_t2, 5, 5);
                CHECK(a == c);
                CHECK(c == a);
                CHECK_EQ(a, c);
                if(i != 9999){
                    CHECK(a != b);
                    CHECK(c != b);
                    CHECK_NE(a, b);
                }
                else{
                    CHECK(a == b);
                    CHECK(b == a);
                    CHECK_EQ(a, b);
                }
            }

            for (int i = 0; i < 10000 ; ++i) {
                vec_t2.assign(25, (10000 - i));
                Matrix c (vec_t2, 5, 5);
                CHECK(a == c);
                CHECK(c == a);
                CHECK_EQ(a, c);
                a -= 1;
            }

            vec_t1.assign(25, 1);
            Matrix d (vec_t1, 5, 5);
            int factorial = 1;
            for (int i = 1; i < 14 ; ++i) {
                vec_t2.assign(25, factorial);
                Matrix c (vec_t2, 5, 5);
                CHECK(d == c);
                CHECK(c == d);
                CHECK_EQ(d, c);
                d *= i;
                factorial *= i;
            }
        }

        SUBCASE("double matrix"){
            Matrix mat3_copy (mat3);
            Matrix mat4_copy (mat4);
            mat3 *= mat4;
            CHECK(mat3 == mul_3_4);
            CHECK_EQ(mat3, mul_3_4);

            mat3 = mat3_copy;
            mat4 *= mat3;
            CHECK_THROWS (dummy = mat4 != mul_3_4);

            Matrix mat7_copy(mat7);
            mat7 *= mat7;
            CHECK(mat7 == mul_7_7);
            CHECK_EQ(mat7, mul_7_7);

            mat7 = mat7_copy;
            mat7 *= mat8;
            CHECK(mat7 == mul_7_8);
            CHECK(mat7 != mul_8_7);
            CHECK_EQ(mat7, mul_7_8);

            mat7 = mat7_copy;
            mat8 *= mat7;
            CHECK(mat8 != mul_7_8);
            CHECK_NE(mat8, mul_7_8);
            CHECK(mat8 == mul_8_7);
            CHECK_EQ(mat8, mul_8_7);
            CHECK_NE(mat7, mul_8_7);

            mat3 = mat3_copy;
            CHECK_THROWS(mat1 *= mat2); // 4x4 * 3x3
            CHECK_THROWS(mat2 *= mat1); // 3x3 * 4x4
            CHECK_THROWS(mat3 *= mat5); // 2x3 * 2x3
            CHECK_THROWS(mat5 *= mat3); // 2x3 * 2x3

            CHECK_NOTHROW(mat1p1 *= mat1); // 4x4 * 4x4
            CHECK_NOTHROW(mat1 *= mat1p1); // 4x4 * 4x4
            CHECK_NOTHROW(mat3 *= mat4); // 2x3 * 3x2
            mat3 = mat3_copy;
            mat4 = mat4_copy;
            CHECK_NOTHROW(mat4 *= mat3); // 3x2 * 2x3

            cout << "-(5\\9) End of += -= *= operators -> good job!" << endl;
        }
    }
}

TEST_CASE("Comparison operators"){
    vector<double>  vec_i4 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    vector<double>  vec_i3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double>  vec1 = {1, 2, 3, 4, 5, 6};
    vector<double>  vec2 = {6, 5, 4, 3, 2, 1};
    vector<double>  vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double>  vec4 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<double>  vec5 = {7, 7, 7, 7, 7, 7};
    vector<double>  vec6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<double>  vec7 = {7, 7, 7, 7, 6, 7};
    vector<double>  vec8 = {7, 7, 7, 8, 6, 7};

    Matrix i3 (vec_i3, 3, 3);
    Matrix i4 (vec_i4, 4, 4);
    Matrix a (vec1, 2, 3);
    Matrix b (vec2, 2, 3);
    Matrix c (vec3, 3, 3);
    Matrix d (vec4, 3, 3);
    Matrix e (vec1, 3, 2);
    Matrix f (vec3, 9, 1);
    Matrix g (vec3, 1, 9);
    Matrix h (vec6, 4, 4);


    SUBCASE("== znd !="){
        Matrix copy_a (a);
        CHECK (a == copy_a);
        CHECK (copy_a == a);
        CHECK_EQ (a, copy_a);

        CHECK_NOTHROW (dummy = (a != b));
        CHECK (a != b);
        CHECK (b != a);
        CHECK_FALSE (a == b);
        CHECK_FALSE (b == a);
        CHECK_NE (a, b);

        CHECK_NOTHROW (dummy = (c != d));
        CHECK (c != d);
        CHECK (d != c);
        CHECK_FALSE (c == d);
        CHECK_FALSE (d == c);
        CHECK_NE (c, d);

        CHECK_THROWS (dummy = a == e);
        CHECK_THROWS (dummy = a != e);
        CHECK_THROWS (dummy = f == g);
        CHECK_THROWS (dummy = f != g);
        CHECK_THROWS (dummy = i3 == i4);
        CHECK_THROWS (dummy = i3 != i4);

        Matrix t1 (vec8, 2, 3);
        Matrix t2 (vec5, 2, 3);
        CHECK (t1 != t2);
        CHECK (t2 != t1);
        CHECK_FALSE (t1 == t2);
        CHECK_FALSE (t2 == t1);
        CHECK_NE (t1, t2);

        cout << "-(6\\9) End of == != operators -> good job!" << endl;
    }

    SUBCASE ("< and >"){

        CHECK_NOTHROW (dummy = (a > b));
        CHECK_NOTHROW (dummy = (a < b));
        CHECK_FALSE (a > b);
        CHECK_FALSE (b > a);
        CHECK_FALSE (a < b);
        CHECK_FALSE (b < a);
        CHECK_NE (a, b);

        CHECK_NOTHROW (dummy = (c > d));
        CHECK_NOTHROW (dummy = (c < d));
        CHECK_FALSE (c > d);
        CHECK_FALSE (d > c);
        CHECK_FALSE (c < d);
        CHECK_FALSE (d < c);
        CHECK_NE (c, d);

        CHECK_THROWS (dummy = a > e);
        CHECK_THROWS (dummy = a < e);
        CHECK_THROWS (dummy = f > g);
        CHECK_THROWS (dummy = f < g);
        CHECK_THROWS (dummy = i3 > i4);
        CHECK_THROWS (dummy = i3 < i4);

        Matrix t1 (vec8, 2, 3);
        Matrix t2 (vec5, 2, 3);
        CHECK_FALSE (t1 > t2);
        CHECK_FALSE (t2 < t1);
        CHECK_FALSE (t1 < t2);
        CHECK_FALSE (t2 > t1);
        CHECK_NE (t1, t2);

        CHECK_FALSE (i3 > d);
        CHECK_FALSE (h < i4);
        CHECK_FALSE (d < i3);
        CHECK_FALSE (i4 > h);
        CHECK (d > i3);
        CHECK (i4 < h);

        cout << "-(7\\9) End of < > operators -> good job!" << endl;
    }

    SUBCASE ("<= and >="){

        CHECK_NOTHROW (dummy = (a >= b));
        CHECK_NOTHROW (dummy = (a <= b));
        CHECK_FALSE (a >= b);
        CHECK_FALSE (b >= a);
        CHECK_FALSE (a <= b);
        CHECK_FALSE (b <= a);
        CHECK_NE (a, b);

        CHECK_NOTHROW (dummy = (c >= d));
        CHECK_NOTHROW (dummy = (c <= d));
        CHECK_FALSE (c >= d);
        CHECK_FALSE (d >= c);
        CHECK_FALSE (c <= d);
        CHECK_FALSE (d <= c);
        CHECK_NE (c, d);

        CHECK_THROWS (dummy = a >= e);
        CHECK_THROWS (dummy = a <= e);
        CHECK_THROWS (dummy = f >= g);
        CHECK_THROWS (dummy = f <= g);
        CHECK_THROWS (dummy = i3 >= i4);
        CHECK_THROWS (dummy = i3 <= i4);

        Matrix t1 (vec8, 2, 3);
        Matrix t2 (vec5, 2, 3);
        CHECK_FALSE (t1 >= t2);
        CHECK_FALSE (t2 <= t1);
        CHECK_FALSE (t1 <= t2);
        CHECK_FALSE (t2 >= t1);
        CHECK_NE (t1, t2);

        CHECK_FALSE (i3 >= d);
        CHECK_FALSE (h <= i4);
        CHECK_FALSE (d <= i3);
        CHECK_FALSE (i4 >= h);
        CHECK (d >= i3);
        CHECK (i4 <= h);

        Matrix copy_a (a);
        CHECK (a >= copy_a);
        CHECK (copy_a >= a);

        cout << "-(8\\9) End of >= <= operators -> good job!" << endl;
    }
}

TEST_CASE("Output operator"){
    vector<double> vec_i4 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    vector<double> vec2 = {6, 5, 4, 3, 2, 1};
    vector<double> vec3 = {1,0,1,0};
    vector<double> vec4 = {2,1,1,2};
    stringstream stream;

    // out

    stream << Matrix(vec3,2,2);
            CHECK(stream.str() == "[1 0]\n[1 0]");
    stream.str(std::string());
    stream << Matrix(vec3,1,4);
            CHECK(stream.str() == "[1 0 1 0]");
    stream.str(std::string());
    stream << Matrix(vec3,4,1);
            CHECK(stream.str() == "[1]\n[0]\n[1]\n[0]");
    stream.str(std::string());

    stream << Matrix(vec4,2,2);
            CHECK(stream.str() == "[2 1]\n[1 2]");
    stream.str(std::string());
    stream << Matrix(vec4,1,4);
            CHECK(stream.str() == "[2 1 1 2]");
    stream.str(std::string());
    stream << Matrix(vec4,4,1);
            CHECK(stream.str() == "[2]\n[1]\n[1]\n[2]");
    stream.str(std::string());

    stream << Matrix(vec_i4,4,4);
            CHECK(stream.str() == "[1 0 0 0]\n[0 1 0 0]\n[0 0 1 0]\n[0 0 0 1]");
    stream.str(std::string());
    stream << Matrix(vec_i4,2,8);
            CHECK(stream.str() == "[1 0 0 0 0 1 0 0]\n[0 0 1 0 0 0 0 1]");
    stream.str(std::string());
    stream << Matrix(vec_i4,16,1);
            CHECK(stream.str() == "[1]\n[0]\n[0]\n[0]\n[0]\n[1]\n[0]\n[0]\n[0]\n[0]\n[1]\n[0]\n[0]\n[0]\n[0]\n[1]");
    stream.str(std::string());

    stream << Matrix(vec2,2,3);
            CHECK(stream.str() == "[6 5 4]\n[3 2 1]");
    stream.str(std::string());
    stream << Matrix(vec2,3,2);
            CHECK(stream.str() == "[6 5]\n[4 3]\n[2 1]");
    stream.str(std::string());
    stream << Matrix(vec2,6,1);
            CHECK(stream.str() == "[6]\n[5]\n[4]\n[3]\n[2]\n[1]");
    stream.str(std::string());

    cout << "-(9\\9) End of << operator -> good job!" << endl;
}