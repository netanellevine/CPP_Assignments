//
// Created by Netanel Levine on 05/04/2022.
//
#include "Matrix.hpp"

using namespace std;

namespace zich{

    // Constructors:

    // The default constructor will initiate the identity 5x5 matrix.
    Matrix::Matrix(vector<double> numbers, int rows, int columns) {
        if (rows <= 0 || columns <= 0){
            throw invalid_argument("Rows and columns must be positive numbers only!");
        }
        if (int (numbers.size()) != (rows * columns)){
            throw invalid_argument("The vector size does not match the rows and columns parameters!");
        }
        this->rows = rows;
        this->columns = columns;
        this->matrix = numbers;
    }

    // This constructor will create a matrix with the shape of [rows X columns] and its values will be 0.
    Matrix::Matrix(int rows, int columns) {
        if (rows <= 0 || columns <= 0) {
            throw invalid_argument("rows and columns must be positive numbers only!");
        }
        this->rows = rows;
        this->columns = columns;
        this->matrix.assign(unsigned (rows * columns), 0);
    }


    // Destructor
    Matrix::~Matrix() {
        this->matrix.clear();
    }

    /**
     * This method sum up the two matrices given and compares whether @mat1 is grater then @mat2.
     * @param mat1
     * @param mat2
     * @return true -> mat1 is greater, false -> mat1 is not greater.
     */
    bool isGreater(const Matrix &mat1, const Matrix &mat2) {
        int size1 = mat1.get_rows() * mat1.get_columns();
        int size2 = mat2.get_rows() * mat2.get_columns();
        int minSize = size1 < size2 ? size1 : size2;
        long sum1 = 0;
        long sum2 = 0;
        for (unsigned int i = 0; i < unsigned(minSize); ++i) {
            sum1 += (long)mat1.get_Matrix().at(i);
            sum2 += (long)mat2.get_Matrix().at(i);
        }
        return sum1 > sum2;
    }
    // Because of all the changes it's still unclear what to do.
//        if(sum1 < sum2){
//            if(size1 == minSize){
//                return false; // @mat2 is greater
//            }
//            // @sum1 is smaller but @minSize is not the size of @mat1, so we'll continue to sum @mat1.
//            for (unsigned int i = unsigned (minSize); i < size1; ++i) {
//                sum1 += mat1.get_Matrix().at(i);
//            }
//            if(sum1 < sum2){
//                return false; // @mat2 is greater
//            }
//            return true; // finished to sum @mat1, and it is greater than @mat2
//        }
//        else if(sum1 > sum2){
//            if(size2 == minSize){
//                return true; // @mat1 is greater
//            }
//            // @sum1 is not smaller but @minSize is not the size of @mat2, so we'll continue to sum @mat2.
//            for (unsigned int i = unsigned (minSize); i < size2; ++i) {
//                sum2 += mat2.get_Matrix().at(i);
//            }
//            if(sum1 < sum2){
//                return false; // @mat2 is greater
//            }
//            return true; // finished to sum @mat2, and it is greater than @mat1
//        }
//        else{
//            return false;
//        }
//    }


    // Arithmetic single Matrix operators:

    // mat + num
    Matrix operator +(const Matrix &mat, const double num_to_add){
        Matrix new_mat (mat.rows, mat.columns);
        for (unsigned int i = 0; i < mat.matrix.size(); ++i) {
            new_mat.matrix.at(i) = mat.matrix.at(i) + num_to_add;
        }
        return new_mat;
    }

    // num + mat
    Matrix operator +(const double num_to_add, const Matrix &mat){
        Matrix new_mat = mat + num_to_add;
        return new_mat;
    }

    // mat += num
    Matrix& Matrix::operator +=(const double num_to_add){
        *this = *this + num_to_add;
        return *this;
    }

    // +mat (unary)
    Matrix operator +(const Matrix &mat){
        Matrix new_mat (mat.rows, mat.columns);
        for (unsigned int i = 0; i < mat.matrix.size(); ++i) {
            new_mat.matrix.at(i) = std::abs(mat.matrix.at(i));
        }
        return new_mat;
    }

    // -mat (unary)
    Matrix operator -(const Matrix &mat){
        Matrix new_mat = +mat;
        for (unsigned int i = 0; i < mat.matrix.size(); ++i) {
            new_mat.matrix.at(i) = (new_mat.matrix.at(i) != 0) ? (-new_mat.matrix.at(i)) : 0;
        }
        return new_mat;
    }

    // mat - num
    Matrix operator -(const Matrix &mat, const double num_to_subtract){
        Matrix new_mat = mat + (-num_to_subtract);
        return new_mat;
    }

    // num - mat
    Matrix operator -(const double num_to_subtract, const Matrix &mat){
        Matrix new_mat = -mat + num_to_subtract;
        return new_mat;
    }

    // mat -= num
    Matrix& Matrix::operator -=(const double num_to_subtract){
        *this = *this - num_to_subtract;
        return *this;
    }

    // ++mat (prefix)
    Matrix &Matrix::operator ++(){
        for (unsigned int i = 0; i < this->matrix.size(); ++i) {
            this->matrix.at(i) = this->matrix.at(i) + 1;
        }
         return *this;
    }

    // mat++ (postfix)
   Matrix Matrix ::operator ++(int dummy){
        Matrix new_mat = *this;
        *this += 1;
        return new_mat;
    }

    // --mat (prefix)
    Matrix &Matrix::operator --(){
        for (unsigned int i = 0; i < this->matrix.size(); ++i) {
            this->matrix.at(i) = this->matrix.at(i) - 1;
        }
        return *this;
    }

    // mat-- (postfix)
    Matrix Matrix ::operator --(int dummy){
        Matrix new_mat = *this;
        *this -= 1;
        return new_mat;
    }

    // mat * num
    Matrix operator *(const Matrix &mat, const double num_to_multiply){
        Matrix new_mat (mat.rows, mat.columns);
        for (unsigned int i = 0; i < mat.matrix.size(); ++i) {
            new_mat.matrix.at(i) = mat.matrix.at(i) * num_to_multiply;
        }
        return new_mat;
    }

    // num * mat
    Matrix operator *(const double num_to_multiply, const Matrix &mat){
        Matrix new_mat (mat.rows, mat.columns);
        new_mat = mat * num_to_multiply;
        return new_mat;
    }

    // mat *= num
    Matrix& Matrix::operator *=(const double num_to_multiply){
        *this = *this * num_to_multiply;
        return *this;
    }


    // Arithmetic double Matrix operators:

    // mat1 + mat2
    Matrix Matrix::operator +(const Matrix &mat){
        if(this->rows != mat.rows || this->columns != mat.columns){
            throw invalid_argument ("You cant add two matrices with different shape!");
        }
        Matrix new_mat (mat.rows, mat.columns);
        for (unsigned int i = 0; i < mat.matrix.size(); ++i) {
            new_mat.matrix.at(i) = this->matrix.at(i) + mat.matrix.at(i);
        }
        return new_mat;
    }

    // mat1 - mat2
    Matrix Matrix::operator -(const Matrix &mat){
        if(this->rows != mat.rows || this->columns != mat.columns){
            throw invalid_argument ("You cant subtract two matrices with different shape!");
        }
        Matrix new_mat (mat.rows, mat.columns);
        for (unsigned int i = 0; i < mat.matrix.size(); ++i) {
            new_mat.matrix.at(i) = this->matrix.at(i) - mat.matrix.at(i);
        }
        return new_mat;
    }

    // mat1 * mat2
    Matrix Matrix::operator *(const Matrix &mat){
        if(this->columns != mat.rows){
            throw invalid_argument ("You can't multiply two matrices with invalid shape!");
        }
        Matrix new_mat (this->rows, mat.columns);
        for (int i = 0; i < mat.columns; ++i) {
            for (int j = 0; j < this->rows; ++j) {
                int sum = 0;
                for (int k = 0; k < this->columns; ++k) {
                    sum += (int)(this->get_value(j, k) * mat.get_value(k, i));
                }
                new_mat.set_value(j, i, sum);
            }
        }
        return new_mat;
    }

    // mat1 += mat2
    Matrix& Matrix::operator +=(const Matrix &mat){
        *this = *this + mat;
        return *this;
    }

    // mat1 -= mat2
    Matrix& Matrix::operator -=(const Matrix &mat){
        *this = *this - mat;
        return *this;
    }

    // mat1 *= mat2
    Matrix& Matrix::operator *=(const Matrix &mat){
        *this = *this * mat;
        return *this;
    }

    // Comparison operators:

    // mat1 > mat2 -> true or false
    bool operator >(const Matrix &mat1, const Matrix &mat2){
        if(mat1.rows != mat2.rows || mat1.columns != mat2.columns){
            throw invalid_argument ("You can't compare between matrices with different shapes!");
        }
        if(mat1 == mat2){
            return false;
        }
        return isGreater(mat1, mat2);
    }

    // mat1 < mat2 -> true or false
    bool operator <(const Matrix &mat2, const Matrix &mat1){
        if(mat1.rows != mat2.rows || mat1.columns != mat2.columns){
            throw invalid_argument ("You can't compare between matrices with different shapes!");
        }
        if(mat1 == mat2){
            return false;
        }
        return isGreater(mat1, mat2);
    }

    // mat1 >= mat2 -> true or false
    bool operator >=(const Matrix &mat1, const Matrix &mat2){
        if(mat1.rows != mat2.rows || mat1.columns != mat2.columns){
            throw invalid_argument ("You can't compare between matrices with different shapes!");
        }
        if(mat1 == mat2){
            return true;
        }
        return (mat1 > mat2);
    }

    // mat1 <= mat2 -> true or false
    bool operator <=(const Matrix &mat1, const Matrix &mat2){
        if(mat1.rows != mat2.rows || mat1.columns != mat2.columns){
            throw invalid_argument ("You can't compare between matrices with different shapes!");
        }
        if(mat1 == mat2){
            return true;
        }
        return (mat1 < mat2);
    }

    // mat1 == mat2 -> true or false
    bool operator ==(const Matrix &mat1, const Matrix &mat2){
        if(mat1.rows != mat2.rows || mat1.columns != mat2.columns){
            throw invalid_argument ("You can't compare between matrices with different shapes!");
        }
        for (int i = 0; i < mat1.rows ; ++i) {
            for (int j = 0; j < mat1.columns; ++j) {
                if(mat1.get_value(i, j) != mat2.get_value(i, j)){
                    return false;
                }
            }
        }
        return true;
    }

    // mat1 != mat2 -> true or false
    bool operator !=(const Matrix &mat1, const Matrix &mat2){
        if(mat1.rows != mat2.rows || mat1.columns != mat2.columns){
            throw invalid_argument ("You can't compare between matrices with different shapes!");
        }
        return !(mat1 == mat2);
    }


    // input/output operators:

    /** input -> the valid syntax is: [1 2 3], [4 5 6], [7 8 9]
     * each [] represent a row and the amount of numbers within each [] is the columns.
    */
    istream &operator >>(istream &input, Matrix &mat){
        string string_mat;
        char curr_ch = '~';
        while (curr_ch != '\n'){
            curr_ch = (char)input.get();
            if (curr_ch != '~'){
                string_mat += curr_ch;
            }
        }
        std::vector<double> vec;
        int count_r = 0;
        int count_c = 0;
        for (unsigned int i = 0; i < string_mat.length(); ++i) {
            if (string_mat.at(i) >= '0' && string_mat.at(i) <= '9'){
                vec.push_back(string_mat.at(i) - '0');
                count_c++;
            }
            else if (string_mat.at(i) == '['){
                count_r++;
            }
            else if (string_mat.at(i) == ']'){
                count_c = 0;
            }
            if (count_c > mat.get_columns() || count_r > mat.get_rows()){
                throw invalid_argument ("The shape of the input given is not valid!");
            }
        }
        if (vec.size() != mat.get_Matrix().size()){
            throw invalid_argument ("The amount of values given do not correspond to the original matrix!");
        }
        mat.set_new_mat(vec);
        return input;
    }

    /** output -> the output will look like that:   [1 2 3]
     *                                              [4 5 6]
     *                                              [7 8 9]
     */
    ostream &operator <<(ostream &out, const Matrix &mat){
        for (int i = 0; i < mat.rows; ++i) {
            out << '[';
            for (int j = 0; j < mat.columns; ++j) {
                out << mat.get_value(i, j);
               if (j == mat.columns - 1) { out << ']';}
               else{out << ' ';}
            }
            if (i != mat.rows - 1){
                out << std::endl;
            }
        }
        return out;
    }

}