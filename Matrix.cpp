/**
 * Implementation of the functions
 *
 * Author: Eyad Amer
 * Since : 2022-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

namespace zich
{
    Matrix::Matrix(const vector<double> &mat, unsigned int r, unsigned int c)
    {
        if (r <= 0 || c <= 0)
        {
            throw invalid_argument("illegal inputs - the number of the row or columns are Negetave number!");
        }

        this->rows = r;
        this->cols = c;
    }

    Matrix::Matrix(const Matrix &other)
    {
        if (other.rows <= 0 || other.cols <= 0)
        {
            throw invalid_argument("illegal inputs - the number of the row or columns are Negetave number!");
        }

        this->rows = other.rows;
        this->cols = other.cols;
    }

    // check if the Matrices are the same size
    bool checkSize(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    }

    // Accounting operators: +, +=, +(onry), -, -=, -(onry)

    // plus
    Matrix Matrix::operator+(const Matrix &other)
    {
        return *this;
    }

    // add
    Matrix Matrix::operator+=(const Matrix &other)
    {
        return *this;
    }

    // plus onry
    Matrix Matrix::operator+()
    {
        return *this;
    }

    // minus
    Matrix Matrix::operator-(const Matrix &other)
    {
        return *this;
    }

    // reduction
    Matrix Matrix::operator-=(const Matrix &other)
    {
        return *this;
    }

    // minus onry
    Matrix Matrix::operator-()
    {
        return *this;
    }

    // Comparison operators: <, <=, >, >=, =, !=
    bool operator<(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    }

    bool operator<=(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    }

    bool operator>(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    }

    bool operator>=(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    }

    bool operator==(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    }

    bool operator!=(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    }

    // Increase or decrease by 1 all the members of the matrix befor the number
    Matrix Matrix::operator++()
    {
        return *this;
    }

    Matrix Matrix::operator--()
    {
        return *this;
    }

    // Increase or decrease by 1 all the members of the matrix after the number
    Matrix Matrix::operator++(int num)
    {
        return *this;
    }

    Matrix Matrix::operator--(int num)
    {
        return *this;
    }

    // Matrix doubling in scalar
    Matrix Matrix::operator*(double num)
    {
        return *this;
    }

    Matrix Matrix::operator*=(double num)
    {
        return *this;
    }

    // Matrix multiplication in the matrix
    Matrix operator*(double num, const Matrix &other)
    {
        return other;
    }

    // Matrix multiplication in the matrix
    Matrix operator*(const Matrix &other, double num)
    {
        return other;
    }

    Matrix Matrix::operator*(const Matrix &other)
    {
        return *this;
    }

    Matrix Matrix::operator*=(const Matrix &other)
    {
        return *this;
    }

    // input and output operator
    std::istream &operator>>(std::istream &input, Matrix &other)
    {
        return input;
    }

    std::ostream &operator<<(std::ostream &output, const Matrix &other)
    {
        return output;
    }

}