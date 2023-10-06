
/*!
\file
\brief Source file with discription of methods in project Matrix

This file included a description of the methods that are used in the
project Matrix and implement the logic of the work
*/

#include "matrix_oop.h"

namespace matrix {
/*!
A basic constructor that initialises a matrix of some predefined dimension
*/
Matrix::Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}
/*!
Parametrized constructor with number of rows and columns
\param[in] rows Variable that contains the number of rows of the matrix
\param[in] cols Variable that contains the number of columns of the matrix
*/
Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  CreateMatrix(rows_, cols_);
}
/*!
Copy constructor
\param[in] other Variable that contains a parameter of the same class by
reference
*/
Matrix::Matrix(const Matrix& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
  CreateMatrix(rows_, cols_);
  AssignmentCycle(other);
}
/*!
Move constructor
\param[in] other Variable that contains a parameter representing an rvalue
reference to an object of the current type
*/
Matrix::Matrix(Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}
/*!
Assignment operator
\param[in] other Variable that contains a parameter of the same class by
reference \return Reference to the current class object
*/
Matrix& Matrix::operator=(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  RemoveMatrix();
  CreateMatrix(other.rows_, other.cols_);
  AssignmentCycle(other);
  return *this;
}
/*!
Assignment operator
\param[in] other Variable that contains a parameter representing an rvalue
reference to an object of the current type \return Reference to the current
class object
*/
Matrix& Matrix::operator=(Matrix&& other) {
  CheckThrowExistTwoMatrix(other);
  RemoveMatrix();
  CreateMatrix(other.rows_, other.cols_);
  AssignmentCycle(other);
  return *this;
}
/*!
Destructor
*/
Matrix::~Matrix() { RemoveMatrix(); };

/*!
Overload of the + operator, in which addition of two matrices
\param[in] other Variable that contains a parameter of the same class by
reference \return The current class object
*/
Matrix Matrix::operator+(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckThrowDimensions(other);
  Matrix helper(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      helper.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
  return helper;
}
/*!
Overload of the - operator, in which subtraction of one matrix from another
\param[in] other Variable that contains a parameter of the same class by
reference \return The current class object
*/
Matrix Matrix::operator-(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckThrowDimensions(other);
  Matrix helper(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      helper.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
  return helper;
}
/*!
Overload of the * operator, in which matrix multiplication
\param[in] other Variable that contains a parameter of the same class by
reference \return The current class object
*/
Matrix Matrix::operator*(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckNumberOfColumnsOfRows(other);
  double middle_value = 0.0;
  Matrix helper(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      middle_value = 0.0;
      for (int n = 0; n < other.rows_; ++n) {
        middle_value = middle_value + matrix_[i][n] * other.matrix_[n][j];
      }
      helper.matrix_[i][j] = middle_value;
    }
  }
  return helper;
}
/*!
Overload of the * operator, in which matrix multiplication by a number
\param[in] other Variable that contains a parameter of the same class by
reference \return The current class object
*/
Matrix Matrix::operator*(const double number) {
  CheckThrowExistOneMatrix();
  Matrix helper(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      helper.matrix_[i][j] = number * matrix_[i][j];
    }
  }
  return helper;
}
/*!
Overload of the == operator, in which checks for matrices equality
\param[in] other Variable that contains a parameter of the same class by
reference \return The result of comparing two matrices is SUCCESS or FAILURE
*/
bool Matrix::operator==(const Matrix& other) {
  bool result = SUCCESS;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    EqualityCheckCycle(other, &result);
  } else
    result = FAILURE;
  return result;
}
/*!
Overload of the += operator, in which the sum is assigned
\param[in] other Variable that contains a parameter of the same class by
reference \return Reference to the current class object
*/
Matrix& Matrix::operator+=(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckThrowDimensions(other);
  AdditionCycle(other);
  return *this;
}
/*!
Overload of the -= operator, in which the difference is assigned
\param[in] other Variable that contains a parameter of the same class by
reference \return Reference to the current class object
*/
Matrix& Matrix::operator-=(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckThrowDimensions(other);
  SubtractionCycle(other);
  return *this;
}
/*!
Overload of the *= operator, in which the multiplication is assigned
\param[in] other Variable that contains a parameter of the same class by
reference \return Reference to the current class object
*/
Matrix& Matrix::operator*=(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckNumberOfColumnsOfRows(other);
  MultiplicationCycle(other);
  return *this;
}
/*!
Overload of the () operator, in which access to matrix elements by index
\param[in] i Variable that contains the index of rows
\param[in] j Variable that contains the index of columns
\return The element of matrix that is stored under the indexes
*/
double& Matrix::operator()(int i, int j) {
  CheckThrowIndex(i, j);
  return matrix_[i][j];
}

/*!
Checks matrices for equality with each other
\param[in] other Variable that contains a parameter of the same class by
reference \return The result of comparing two matrices is SUCCESS or FAILURE
*/
bool Matrix::EqMatrix(const Matrix& other) noexcept {
  bool result = SUCCESS;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    EqualityCheckCycle(other, &result);
  } else
    result = FAILURE;
  return result;
}
/*!
Adds the second matrix to the current one
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::SumMatrix(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckThrowDimensions(other);
  AdditionCycle(other);
}
/*!
Subtracts another matrix from the current one
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::SubMatrix(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckThrowDimensions(other);
  SubtractionCycle(other);
}
/*!
Multiplies the current matrix by a number
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::MulNumber(const double num) {
  CheckThrowExistOneMatrix();
  MultiplicationCycleNumber(num);
}
/*!
Multiplies the current matrix by the second matrix
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::MulMatrix(const Matrix& other) {
  CheckThrowExistTwoMatrix(other);
  CheckNumberOfColumnsOfRows(other);
  MultiplicationCycle(other);
}
/*!
Creates a new transposed matrix from the current one and returns it
*/
Matrix Matrix::Transpose() {
  CheckThrowExistOneMatrix();
  Matrix helper(cols_, rows_);
  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      helper.matrix_[i][j] = matrix_[j][i];
    }
  }
  return helper;
}
/*!
Calculates the algebraic addition matrix of the current one and returns it
*/
Matrix Matrix::CalcComplements() {
  CheckThrowExistOneMatrix();
  CheckSquareMatrix();
  Matrix helper(rows_, cols_);
  if (rows_ == 1) {
    helper.matrix_[0][0] = 1;
  } else {
    double result_value = 0.0;
    for (int column = 0; column < cols_; ++column) {
      for (int row = 0; row < rows_; ++row) {
        Matrix minor(rows_ - 1, cols_ - 1);
        Minor(column, row, minor);
        result_value = minor.Determinant();
        helper.matrix_[column][row] =
            pow(-1, ((column + 1) + (row + 1))) * (result_value);
      }
    }
  }
  return helper;
}
/*!
Calculates and returns the determinant of the current matrix
*/
double Matrix::Determinant() {
  double result = 0.0;
  CheckThrowExistOneMatrix();
  CheckSquareMatrix();
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else if (rows_ == 3) {
    result = (matrix_[0][0] * matrix_[1][1] * matrix_[2][2] +
              matrix_[0][1] * matrix_[1][2] * matrix_[2][0] +
              matrix_[0][2] * matrix_[1][0] * matrix_[2][1]) -
             matrix_[2][0] * matrix_[1][1] * matrix_[0][2] -
             matrix_[2][1] * matrix_[1][2] * matrix_[0][0] -
             matrix_[2][2] * matrix_[1][0] * matrix_[0][1];
  } else {
    int row = 0;
    double middle_result = 0.0;
    for (int column = 0; column < cols_; ++column) {
      Matrix minor(rows_ - 1, cols_ - 1);
      Minor(row, column, minor);
      middle_result = minor.Determinant();
      result += pow(-1, ((column + 1) + (row + 1))) * matrix_[row][column] *
                (middle_result);
    }
  }
  return result;
}
/*!
Calculates and returns the inverse matrix
*/
Matrix Matrix::InverseMatrix() {
  CheckThrowExistOneMatrix();
  CheckSquareMatrix();
  if (rows_ == 1) {
    Matrix helper(rows_, cols_);
    helper.matrix_[0][0] = 0;
    helper.matrix_[0][0] = 1 / (matrix_[0][0]);
    return helper;
  } else {
    double result_value = 0.0;
    result_value = Determinant();
    if (result_value == 0) {
      throw "Matrix determinant is 0";
    }
    Matrix calc_complements_matrix(rows_, cols_);
    Matrix transpose_matrix(rows_, cols_);
    calc_complements_matrix = CalcComplements();
    transpose_matrix = calc_complements_matrix.Transpose();
    transpose_matrix.MulNumber(1 / result_value);
    return transpose_matrix;
  }
  return *this;
}

/*!
Implement the access to private field rows_ via accessor
\return Private field rows_ value
*/
inline int Matrix::GetRows() noexcept { return rows_; }
/*!
Implement the access to private field cols_ via accessor
\return Private field cols_ value
*/
inline int Matrix::GetCols() noexcept { return cols_; }
/*!
Implement the access to private field matrix_ via accessor
\param[in] i Variable that contains the index of rows
\param[in] j Variable that contains the index of columns
\return The element of matrix that is stored under the indexes
*/
double Matrix::GetMatrix(int i, int j) {
  CheckThrowIndex(i, j);
  return matrix_[i][j];
}
/*!
Implement the access to private field rows_ via mutator
\param[in] row A variable that contains the number of rows to change
*/
void Matrix::SetRows(int rows) {
  if (rows_ != rows) {
    Matrix helper(rows, cols_);
    if (rows_ > rows) {
      HelperSetMore(helper);
    } else {
      HelperSetLess(helper);
      for (int i = rows_; i < helper.rows_; ++i) {
        for (int j = 0; j < helper.cols_; ++j) {
          helper.matrix_[i][j] = 0;
        }
      }
    }
    *this = helper;
  }
}
/*!
Implement the access to private field cols_ via mutator
\param[in] row A variable that contains the number of cols to change
*/
void Matrix::SetCols(int cols) {
  if (cols_ != cols) {
    Matrix helper(rows_, cols);
    if (cols_ > cols) {
      HelperSetMore(helper);
    } else {
      HelperSetLess(helper);
      for (int i = 0; i < helper.rows_; ++i) {
        for (int j = cols_; j < helper.cols_; ++j) {
          helper.matrix_[i][j] = 0;
        }
      }
    }
    *this = helper;
  }
}
/*!
Implement the access to private field matrix_ via mutator
\param[in] i Variable that contains the index of rows
\param[in] j Variable that contains the index of columns
\param[in] value Variable that contains the value
\return The result of placing an element in the matrix
*/
bool Matrix::SetMatrix(int i, int j, double value) noexcept {
  bool result = SUCCESS;
  if (GetCols() > j && GetRows() > i) {
    matrix_[i][j] = value;
  } else {
    result = FAILURE;
  }
  return result;
}

/*!
Method with matrix creation
\param[in] rows Variable that contains the number of rows in matrix
\param[in] columns Variable that contains the number of columns in matrix
\return The result of creating matrix
*/
bool Matrix::CreateMatrix(int rows, int columns) {
  bool res = SUCCESS;
  if (CheckSize(rows, columns) == SUCCESS) {
    rows_ = rows;
    cols_ = columns;
    try {
      matrix_ = new double*[rows_];
      for (int i = 0; i < rows_; ++i) {
        matrix_[i] = new double[cols_]();
      }
    } catch (const std::bad_alloc& e) {
      std::cout << "Error: " << e.what() << '\n';
    }
  } else
    return res = FAILURE;
  return res;
}
/*!
Method with the removal of the matrix
*/
void Matrix::RemoveMatrix() {
  if (MatrixExist(*this) == SUCCESS) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    if (matrix_ != nullptr) {
      delete[] matrix_;
    }
  }
}

/*!
Method with checking size of matrix
\param[in] rows Variable that contains the number of rows in matrix
\param[in] columns Variable that contains the number of columns in matrix
\return The result of checking size of matrix - SUCCESS or FAILURE
*/
bool Matrix::CheckSize(int rows, int columns) const noexcept {
  if (rows >= 1 && columns >= 1) {
    return SUCCESS;
  } else
    return FAILURE;
}
/*!
Method with checking an existing matrix
\param[in] matrix Variable that contains a parameter of the same class by
reference \return The result of checking size of matrix - SUCCESS or FAILURE
*/
bool Matrix::MatrixExist(const Matrix& matrix) const noexcept {
  if (matrix.rows_ >= 1 && matrix.cols_ >= 1 && matrix.matrix_ != NULL) {
    return SUCCESS;
  } else
    return FAILURE;
}
/*!
Method with minor calculation
\param[in] rows Variable that contains the number of rows in matrix
\param[in] columns Variable that contains the number of columns in matrix
\param[in] minor Variable that contains a parameter of the same class by
reference
*/
void Matrix::Minor(int row, int column, const Matrix& minor) const noexcept {
  int row_minor = 0, column_minor = 0;
  for (int row_new = 0; row_new < rows_; ++row_new) {
    column_minor = 0;
    for (int column_new = 0; column_new < cols_; ++column_new) {
      if (row_new != row && column_new != column) {
        minor.matrix_[row_minor][column_minor] = matrix_[row_new][column_new];
        ++column_minor;
      }
    }
    if (row_new != row) {
      ++row_minor;
    }
  }
}
/*!
Method with the cycle of summation of matrix elements
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::AdditionCycle(const Matrix& other) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}
/*!
Method with the cycle of subtraction of matrix elements
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::SubtractionCycle(const Matrix& other) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}
/*!
Method with the cycle of multiplying matrix elements by a number
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::MultiplicationCycleNumber(double number) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      SetMatrix(i, j, number * matrix_[i][j]);
    }
  }
}
/*!
Method with the cycle of multiplying matrix elements
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::MultiplicationCycle(const Matrix& other) noexcept {
  double middle_value = 0.0;
  Matrix helper(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      middle_value = 0.0;
      for (int n = 0; n < other.rows_; n++) {
        middle_value = middle_value + matrix_[i][n] * other.matrix_[n][j];
      }
      helper.matrix_[i][j] = middle_value;
    }
  }
  *this = helper;
}
/*!
Method with matrix element assignment multiplication cycle
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::AssignmentCycle(const Matrix& other) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
/*!
Method with the cycle of checking matrix elements for equality
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::EqualityCheckCycle(const Matrix& other, bool* result) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > 0.0000001) {
        *result = FAILURE;
        break;
      }
    }
  }
}
/*!
Helper method for SetRows and SetCols
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::HelperSetMore(Matrix& other) {
  for (int i = 0; i < other.rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      other.matrix_[i][j] = matrix_[i][j];
    }
  }
}
/*!
Helper method for SetRows and SetCols
\param[in] other Variable that contains a parameter of the same class by
reference
*/
void Matrix::HelperSetLess(Matrix& other) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      other.matrix_[i][j] = matrix_[i][j];
    }
  }
}
/*!
A method with checks for the existence of two matrixes on exceptional
\param[in] other Variable that contains a parameter of the same class by
reference \throw "The matrix does not exist!"
*/
void Matrix::CheckThrowExistTwoMatrix(const Matrix& other) {
  if (!(MatrixExist(*this) == SUCCESS && MatrixExist(other) == SUCCESS)) {
    throw "The matrix does not exist!";
  }
}
/*!
A method with checks for the existence of one matrixes on exceptional
\throw "The matrix does not exist!"
*/
void Matrix::CheckThrowExistOneMatrix() {
  if (MatrixExist(*this) == FAILURE) {
    throw "The matrix does not exist!";
  }
}
/*!
A method with checks for different matrix dimensions of matrixes on exceptional
\param[in] other Variable that contains a parameter of the same class by
reference \throw "Different matrix dimensions"
*/
void Matrix::CheckThrowDimensions(const Matrix& other) {
  if (!(rows_ == other.rows_ && cols_ == other.cols_)) {
    throw "Different matrix dimensions";
  }
}
/*!
A method with checks for the number of columns of the first matrix does not
equal the number of rows of the second matrix on exceptional \param[in] other
Variable that contains a parameter of the same class by reference \throw "The
number of columns of the first matrix is not equal to the number of rows of the
second matrix"
*/
void Matrix::CheckNumberOfColumnsOfRows(const Matrix& other) {
  if (cols_ != other.rows_) {
    throw "The number of columns of the first matrix is not equal to the number of rows of the second matrix";
  }
}
/*!
A method with checks for the matrix is not square on exceptional
\throw "The matrix is not square"
*/
void Matrix::CheckSquareMatrix() {
  if (rows_ != cols_) {
    throw "The matrix is not square";
  }
}
/*!
A method with checks for index is outside the matrix on exceptional
\param[in] i Variable that contains the index of rows
\param[in] j Variable that contains the index of columns
\throw "Index is outside the matrix"
*/
void Matrix::CheckThrowIndex(int i, int j) {
  if (!(i < rows_ && i >= 0 && j < cols_ && j >= 0)) {
    throw "Index is outside the matrix";
  }
}
}  // namespace matrix
