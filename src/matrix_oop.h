/*!
\file
\brief Header file with discription of methods in project Matrix

This file included a description of the methods that are used in the
project Matrix and implement the logic of the work
*/

#ifndef _MATRIX_OOP_H_
#define _MATRIX_OOP_H_

#include <cmath>
#include <iostream>

#define SUCCESS 1
#define FAILURE 0

namespace matrix {

/*!
Class Matrix with public and private methods and values
*/

class Matrix {
 public:
  Matrix();  ///< A basic constructor that initialises a matrix of some
             ///< predefined dimension
  explicit Matrix(
      int rows,
      int cols);  ///< Parametrized constructor with number of rows and columns
  Matrix(const Matrix& other);             ///< Copy constructor
  Matrix(Matrix&& other) noexcept;         ///< Move constructor
  Matrix& operator=(const Matrix& other);  ///< Assignment operator
  Matrix& operator=(Matrix&& other);       ///< Assignment operator

  ~Matrix();  ///< Destructor

  //Перегрузка операторов
  Matrix operator+(const Matrix& other);  ///< Addition of two matrices
  Matrix operator-(
      const Matrix& other);  ///< Subtraction of one matrix from another
  Matrix operator*(const Matrix& other);  ///< Matrix multiplication
  Matrix operator*(const double number);  ///< Matrix multiplication by a number
  bool operator==(const Matrix& other);   ///< Checks for matrices equality
  Matrix& operator+=(const Matrix& other);  ///< Addition assignment
  Matrix& operator-=(const Matrix& other);  ///< Difference assignment
  Matrix& operator*=(const Matrix& other);  ///< Multiplication assignment
  double& operator()(int i, int j);  ///< Access to matrix elements by index

  friend Matrix operator*(double number, Matrix& other) {  ///< Friend functions
    return (other * number);
  }

  bool EqMatrix(const Matrix& other) noexcept;  ///< Checks matrices for
                                                ///< equality with each other
  void SumMatrix(
      const Matrix& other);  ///< Adds the second matrix to the current one
  void SubMatrix(
      const Matrix& other);  ///< Subtracts another matrix from the current one
  void MulNumber(
      const double number);  ///< Multiplies the current matrix by a number
  void MulMatrix(const Matrix& other);  ///< Multiplies the current matrix by
                                        ///< the second matrix
  Matrix Transpose();  ///< Creates a new transposed matrix from the current one
                       ///< and returns it
  Matrix CalcComplements();  ///< Calculates the algebraic addition matrix of
                             ///< the current one and returns it
  double Determinant();      ///< Calculates and returns the determinant of the
                             ///< current matrix
  Matrix InverseMatrix();    ///< Calculates and returns the inverse matrix

  int GetRows() noexcept;  ///< Implement the access to private field rows_ via
                           ///< accessor
  int GetCols() noexcept;  ///< Implement the access to private field cols_ via
                           ///< accessor
  double GetMatrix(
      int i,
      int j);  /// < Implement the access to private field matrix_ via accessor
  void SetRows(
      int rows);  ///< Implement the access to private field rows_ via mutator
  void SetCols(
      int cols);  ///< Implement the access to private field cols_ via mutator
  bool SetMatrix(int i, int j,
                 double value) noexcept;  /// < Implement the access to private
                                          /// field matrix_ via mutator

 private:
  int rows_, cols_;  ///< private field
  double** matrix_;  ///< private field

  bool CreateMatrix(int rows, int columns);  ///< Method with matrix creation
  void RemoveMatrix();  ///< Method with the removal of the matrix

  bool CheckSize(int rows, int columns)
      const noexcept;  ///< Method with checking size of matrix
  bool MatrixExist(const Matrix& matrix)
      const noexcept;  ///< Method with checking an existing matrix
  void Minor(int row, int column, const Matrix& minor)
      const noexcept;  ///< Method with minor calculation
  void AdditionCycle(
      const Matrix& other) noexcept;  ///< Method with the cycle of summation of
                                      ///< matrix elements
  void SubtractionCycle(
      const Matrix& other) noexcept;  ///< Method with the cycle of subtraction
                                      ///< of matrix elements
  void MultiplicationCycleNumber(
      double number) noexcept;  ///< Method with the cycle of multiplying matrix
                                ///< elements by a number
  void MultiplicationCycle(
      const Matrix& other) noexcept;  ///< Method with the cycle of multiplying
                                      ///< matrix elements
  void AssignmentCycle(
      const Matrix& other) noexcept;  ///< Method with matrix element assignment
                                      ///< multiplication cycle
  void EqualityCheckCycle(
      const Matrix& other,
      bool* result) noexcept;  ///< Method with the cycle of checking matrix
                               ///< elements for equality
  void HelperSetMore(Matrix& other);  ///< Helper method for SetRows and SetCols
  void HelperSetLess(Matrix& other);  ///< Helper method for SetRows and SetCols
  void CheckThrowExistTwoMatrix(
      const Matrix& other);  ///< A method with checks for the existence of two
                             ///< matrixes on exceptional
  void CheckThrowExistOneMatrix();  ///< A method with checks for the existence
                                    ///< of one matrixes on exceptional
  void CheckThrowDimensions(
      const Matrix& other);  ///< A method with checks for different matrix
                             ///< dimensions of matrixes on exceptional
  void CheckNumberOfColumnsOfRows(
      const Matrix& other);  ///< A method with checks for the number of columns
                             ///< of the first matrix does not equal the number
                             ///< of rows of the second matrix on exceptional
  void CheckSquareMatrix();  ///< A method with checks for the matrix is not
                             ///< square on exceptional
  void CheckThrowIndex(int i, int j);  ///< A method with checks for index is
                                       ///< outside the matrix on exceptional
};
}  // namespace matrix
#endif  //_MATRIX_OOP_H_
