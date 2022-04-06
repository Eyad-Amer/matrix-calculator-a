/**
 * Unit tests.
 *
 * AUTHORS: Eyad Amer
 * Date:  2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

// Good inputs and results
TEST_CASE("Good input")
{
    vector<double> mat1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> mat2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};

    Matrix m1(mat1, 3, 3);
    Matrix m2(mat2, 3, 3);

    // check if the Rows are correct
    CHECK(m1.getMatrixRows() == 3);

    // check if the columns are correct
    CHECK(m1.getMatrixcols() == 3);

    // check if the columns are correct
    //CHECK(m1.getMatrix() == mat1);

    // check if the inputs in the matrix are correct
    CHECK(m1.getMatrix().at(0).at(0) == 1);
    CHECK(m1.getMatrix().at(0).at(1) == 0);
    CHECK(m1.getMatrix().at(0).at(2) == 0);
    CHECK(m1.getMatrix().at(1).at(0) == 0);
    CHECK(m1.getMatrix().at(1).at(1) == 1);
    CHECK(m1.getMatrix().at(1).at(2) == 0);
    CHECK(m1.getMatrix().at(2).at(0) == 0);
    CHECK(m1.getMatrix().at(2).at(1) == 0);
    CHECK(m1.getMatrix().at(2).at(2) == 1);

    // plus
    //Matrix plusMatrix = (m1.operator+(m2));

    // Sum of matrices
    Matrix sumMatrix = m1 + m2;
    CHECK(sumMatrix.getMatrix().at(0).at(0) == 4);
    CHECK(sumMatrix.getMatrix().at(0).at(1) == 0);
    CHECK(sumMatrix.getMatrix().at(0).at(2) == 0);
    CHECK(sumMatrix.getMatrix().at(1).at(0) == 0);
    CHECK(sumMatrix.getMatrix().at(1).at(1) == 4);
    CHECK(sumMatrix.getMatrix().at(1).at(2) == 0);
    CHECK(sumMatrix.getMatrix().at(2).at(0) == 0);
    CHECK(sumMatrix.getMatrix().at(2).at(1) == 0);
    CHECK(sumMatrix.getMatrix().at(2).at(2) == 4);

    // Subtraction of matrices
    Matrix subMatrix = m2 - m1;
    CHECK(subMatrix.getMatrix().at(0).at(0) == 2);
    CHECK(subMatrix.getMatrix().at(0).at(1) == 0);
    CHECK(subMatrix.getMatrix().at(0).at(2) == 0);
    CHECK(subMatrix.getMatrix().at(1).at(0) == 0);
    CHECK(subMatrix.getMatrix().at(1).at(1) == 2);
    CHECK(subMatrix.getMatrix().at(1).at(2) == 0);
    CHECK(subMatrix.getMatrix().at(2).at(0) == 0);
    CHECK(subMatrix.getMatrix().at(2).at(1) == 0);
    CHECK(subMatrix.getMatrix().at(2).at(2) == 2);

    // Multiply matrices
    Matrix multMatrix = m1 * m2;
    CHECK(multMatrix.getMatrix().at(0).at(0) == 3);
    CHECK(multMatrix.getMatrix().at(0).at(1) == 0);
    CHECK(multMatrix.getMatrix().at(0).at(2) == 0);
    CHECK(multMatrix.getMatrix().at(1).at(0) == 0);
    CHECK(multMatrix.getMatrix().at(1).at(1) == 3);
    CHECK(multMatrix.getMatrix().at(1).at(2) == 0);
    CHECK(multMatrix.getMatrix().at(2).at(0) == 0);
    CHECK(multMatrix.getMatrix().at(2).at(1) == 0);
    CHECK(multMatrix.getMatrix().at(2).at(2) == 3);

    // Increase the matrix by 1
    Matrix increaseMatrix = m1.operator++();
    CHECK(increaseMatrix.getMatrix().at(0).at(0) == 2);
    CHECK(increaseMatrix.getMatrix().at(0).at(1) == 1);
    CHECK(increaseMatrix.getMatrix().at(0).at(2) == 1);
    CHECK(increaseMatrix.getMatrix().at(1).at(0) == 1);
    CHECK(increaseMatrix.getMatrix().at(1).at(1) == 2);
    CHECK(increaseMatrix.getMatrix().at(1).at(2) == 1);
    CHECK(increaseMatrix.getMatrix().at(2).at(0) == 1);
    CHECK(increaseMatrix.getMatrix().at(2).at(1) == 1);
    CHECK(increaseMatrix.getMatrix().at(2).at(2) == 2);

    // decrease the matrix by 1
    Matrix decreaseMatrix = m1.operator--();
    CHECK(decreaseMatrix.getMatrix().at(0).at(0) == 0);
    CHECK(decreaseMatrix.getMatrix().at(0).at(1) == -1);
    CHECK(decreaseMatrix.getMatrix().at(0).at(2) == -1);
    CHECK(decreaseMatrix.getMatrix().at(1).at(0) == -1);
    CHECK(decreaseMatrix.getMatrix().at(1).at(1) == 0);
    CHECK(decreaseMatrix.getMatrix().at(1).at(2) == -1);
    CHECK(decreaseMatrix.getMatrix().at(2).at(0) == -1);
    CHECK(decreaseMatrix.getMatrix().at(2).at(1) == -1);
    CHECK(decreaseMatrix.getMatrix().at(2).at(2) == 0);

    // Increase the matrix by a number
    Matrix increaseByMatrix = m1.operator++(2);
    CHECK(increaseByMatrix.getMatrix().at(0).at(0) == 3);
    CHECK(increaseByMatrix.getMatrix().at(0).at(1) == 2);
    CHECK(increaseByMatrix.getMatrix().at(0).at(2) == 2);
    CHECK(increaseByMatrix.getMatrix().at(1).at(0) == 2);
    CHECK(increaseByMatrix.getMatrix().at(1).at(1) == 3);
    CHECK(increaseByMatrix.getMatrix().at(1).at(2) == 2);
    CHECK(increaseByMatrix.getMatrix().at(2).at(0) == 2);
    CHECK(increaseByMatrix.getMatrix().at(2).at(1) == 2);
    CHECK(increaseByMatrix.getMatrix().at(2).at(2) == 3);

    // decrease the matrix by a number
    Matrix decreaseByMatrix = m1.operator--(2);
    CHECK(decreaseByMatrix.getMatrix().at(0).at(0) == -1);
    CHECK(decreaseByMatrix.getMatrix().at(0).at(1) == -2);
    CHECK(decreaseByMatrix.getMatrix().at(0).at(2) == -2);
    CHECK(decreaseByMatrix.getMatrix().at(1).at(0) == -2);
    CHECK(decreaseByMatrix.getMatrix().at(1).at(1) == -1);
    CHECK(decreaseByMatrix.getMatrix().at(1).at(2) == -2);
    CHECK(decreaseByMatrix.getMatrix().at(2).at(0) == -2);
    CHECK(decreaseByMatrix.getMatrix().at(2).at(1) == -2);
    CHECK(decreaseByMatrix.getMatrix().at(2).at(2) == -1);

    // Multiply the matrix by the scalr
    Matrix multSclarMatrix = m1.operator*(2);
    CHECK(multSclarMatrix.getMatrix().at(0).at(0) == 2);
    CHECK(multSclarMatrix.getMatrix().at(0).at(1) == 0);
    CHECK(multSclarMatrix.getMatrix().at(0).at(2) == 0);
    CHECK(multSclarMatrix.getMatrix().at(1).at(0) == 0);
    CHECK(multSclarMatrix.getMatrix().at(1).at(1) == 2);
    CHECK(multSclarMatrix.getMatrix().at(1).at(2) == 0);
    CHECK(multSclarMatrix.getMatrix().at(2).at(0) == 0);
    CHECK(multSclarMatrix.getMatrix().at(2).at(1) == 0);
    CHECK(multSclarMatrix.getMatrix().at(2).at(2) == 2);

    // check if small then
    CHECK(operator<(m1,increaseByMatrix) == true);
    CHECK(operator<=(m1,increaseByMatrix) == true);
    CHECK(operator>(increaseByMatrix, m1) == true);
    CHECK(operator>=(increaseByMatrix, m1) == true);
    CHECK(operator==(m1,m1) == true);
    CHECK(operator!=(m1,m2) == true);

}


TEST_CASE("Bad input - wrong results")
{
    vector<double> mat1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> mat2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};

    Matrix m1(mat1, 3, 3);
    Matrix m2(mat2, 3, 3);

    // Accounting operators
    CHECK_THROWS(m1 + m2);
    CHECK_THROWS(m1.operator+(m2));
    CHECK_THROWS(m1 += m2);
    CHECK_THROWS(m1.operator+=(m2));
    CHECK_THROWS(m1.operator+());
    CHECK_THROWS(m1 - m2);
    CHECK_THROWS(m1.operator-(m2));
    CHECK_THROWS(m1 -= m2);
    CHECK_THROWS(m1.operator-=(m2));
    CHECK_THROWS(m1.operator-());
    

    // Matrix multiplication in the matrix
    CHECK_THROWS(m1 * m2);
    CHECK_THROWS(m1 *= m2);
    CHECK_THROWS(operator*(5,m2));
    CHECK_THROWS(operator*(m1,3));
    CHECK_THROWS(m2.operator*(m1));
    CHECK_THROWS(m2.operator*=(m1));

    // Matrix doubling in scalar
    CHECK_THROWS(m1.operator*(5));
    CHECK_THROWS(m1.operator*=(5));

    // Increase or decrease by 1
    CHECK_THROWS(m1.operator++());
    CHECK_THROWS(m1.operator--());

    // Comparison operators
    CHECK_THROWS(CHECK_EQ((m1 > m2), true));
    CHECK_THROWS(CHECK_EQ((m1 >= m2), true));
    CHECK_THROWS(CHECK_EQ((m1 < m2), true));
    CHECK_THROWS(CHECK_EQ((m1 <= m2), true));
    CHECK_THROWS(CHECK_EQ((m1 == m2), true));
    CHECK_THROWS(CHECK_EQ((m1 != m2), true));
    
}