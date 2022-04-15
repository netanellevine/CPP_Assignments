//
// Created by Netanel Levine on 04/04/2022.
//

#ifndef EX3_1_CPP_MATRIX_HPP
#define EX3_1_CPP_MATRIX_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using std::istream;
using std::ostream;
using std::vector;

namespace zich
{
    class Matrix {
        private:
            int rows;
            int columns;
            std::vector<double> matrix;

        public:

        // Constructors:

        // The default constructor will initiate the identity 5x5 matrix.
        Matrix() {rows = columns = 5;
            vector<double> vec;
            vec.assign(25,0);
            vec.at(0) = vec.at(6) = vec.at(12) = vec.at(18) = vec.at(24) = 1;
            matrix = vec;}

        Matrix(int rows, int columns); // only by shape

        Matrix(const vector<double> &numbers, int rows, int columns); // regular constructor

        Matrix(const Matrix & mat){ // deep copy constructor
                rows = mat.rows;
                columns = mat.columns;
                matrix.assign(mat.matrix.begin(), mat.matrix.end());
            };

        //Destructor
        ~Matrix();

        // Getters & Setters:
        [[nodiscard]] vector<double> get_Matrix() const{
            return this->matrix;
        }

        [[nodiscard]] int get_rows() const{
            return this->rows;
        }

        [[nodiscard]] int get_columns() const{
            return this->columns;
        }

        [[nodiscard]] double get_value(const int row,const int column) const{
            return this->matrix.at(unsigned (row * this->columns + column));
        }


//        [[nodiscard("You ignored the returned value, maybe you wanted set_new_mat() method instead?")]] vector<double> get_Matrix() const{
//            return this->matrix;
//        }
//
//        [[nodiscard("You ignored the returned value, maybe you wanted set_rows() method instead?")]] int get_rows() const{
//            return this->rows;
//        }
//
//        [[nodiscard("You ignored the returned value, maybe you wanted set_columns() method instead?")]] int get_columns() const{
//            return this->columns;
//        }
//
//        [[nodiscard("You ignored the returned value, maybe you wanted set_value() method instead?")]] double get_value(const int row,const int column) const{
//            return this->matrix.at(unsigned (row * this->columns + column));
//        }

        void set_value(const int row,const int column, const int value){
            this->matrix.at(unsigned (row * this->columns + column)) = value;
        }

        void set_rows(const int row){
            this->rows = row;
        }

        void set_columns(const int column){
            this->columns = column;
        }

        void set_new_mat(const vector<double> &vec){
            this->matrix.assign(vec.begin(), vec.end());
        }


        // Operators:

        // Arithmetic single Matrix operators:
        friend Matrix operator +(const Matrix &mat, double num_to_add);
        friend Matrix operator +(double num_to_add, const Matrix &mat);
        friend Matrix operator +(const Matrix &mat);

        friend Matrix operator -(const Matrix &mat, double num_to_subtract);
        friend Matrix operator -(double num_to_subtract, const Matrix &mat);
        friend Matrix operator -(const Matrix &mat);

        friend Matrix operator *(const Matrix &mat, double num_to_multiply);
        friend Matrix operator *(double num_to_multiply, const Matrix &mat);

        Matrix& operator +=(double num_to_add);
        Matrix& operator -=(double num_to_subtract);
        Matrix& operator *=(double num_to_multiply);

        // prefix:
         Matrix& operator ++();
         Matrix& operator --();

        // postfix:
         Matrix operator ++(int dummy);
         Matrix operator --(int dummy);

        // Arithmetic double Matrix operators:
        Matrix operator +(const Matrix &mat);
        Matrix operator -(const Matrix &mat);
        Matrix operator *(const Matrix &mat)const;

        Matrix& operator +=(const Matrix &mat);
        Matrix& operator -=(const Matrix &mat);
        Matrix& operator *=(const Matrix &mat);

        // Comparison operators:
        friend bool operator >(const Matrix &mat1, const Matrix &mat2);
        friend bool operator <(const Matrix &mat2, const Matrix &mat1);

        friend bool operator >=(const Matrix &mat1, const Matrix &mat2);
        friend bool operator <=(const Matrix &mat1, const Matrix &mat2);

        friend bool operator ==(const Matrix &mat1, const Matrix &mat2);
        friend bool operator !=(const Matrix &mat1, const Matrix &mat2);

        // input/output operators:
        friend istream &operator >>(istream &input, Matrix &mat);
        friend ostream &operator <<(ostream &out, const Matrix &mat);

    };
}

#endif //EX3_1_CPP_MATRIX_HPP
