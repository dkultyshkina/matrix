#include <gtest/gtest.h>

#include "../src/matrix_oop.h"

TEST(TestEqMatrix, EqMatrixTrue) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  matrix_2.SetMatrix(0, 1, 2);
  matrix_2.SetMatrix(1, 0, 3);
  matrix_2.SetMatrix(1, 1, 4);
  bool result = matrix.EqMatrix(matrix_2);
  ASSERT_EQ(result, SUCCESS);
}

TEST(TestEqMatrix, EqMatrixFalse) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  matrix_2.SetMatrix(0, 1, 2);
  matrix_2.SetMatrix(1, 0, 3);
  matrix_2.SetMatrix(1, 1, 4.0001);
  bool result = matrix.EqMatrix(matrix_2);
  ASSERT_EQ(result, FAILURE);
}

TEST(TestEqMatrix, EqMatrixFalseTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  matrix_2.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(1, 0, 2);
  matrix_2.SetMatrix(1, 1, 4);
  bool result = matrix.EqMatrix(matrix_2);
  ASSERT_EQ(result, FAILURE);
}

TEST(TestEqMatrix, EqMatrixTrueTwo) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);

  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 3);
  matrix_2.SetMatrix(0, 2, -3);
  matrix_2.SetMatrix(0, 3, 4);
  matrix_2.SetMatrix(1, 0, 2);
  matrix_2.SetMatrix(1, 1, 1);
  matrix_2.SetMatrix(1, 2, -1);
  matrix_2.SetMatrix(1, 3, 2);
  matrix_2.SetMatrix(2, 0, 6);
  matrix_2.SetMatrix(2, 1, 2);
  matrix_2.SetMatrix(2, 2, 1);
  matrix_2.SetMatrix(2, 3, 0);
  matrix_2.SetMatrix(3, 0, 2);
  matrix_2.SetMatrix(3, 1, 3);
  matrix_2.SetMatrix(3, 2, 0);
  matrix_2.SetMatrix(3, 3, -5);

  bool result = matrix.EqMatrix(matrix_2);
  ASSERT_EQ(result, SUCCESS);
}

TEST(TestEqMatrix, EqMatrixFalseThree) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);

  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 3);
  matrix_2.SetMatrix(0, 2, -3);
  matrix_2.SetMatrix(0, 3, 4);
  matrix_2.SetMatrix(1, 0, 2);
  matrix_2.SetMatrix(1, 1, 1);
  matrix_2.SetMatrix(1, 2, -1);
  matrix_2.SetMatrix(1, 3, 2);
  matrix_2.SetMatrix(2, 0, 6);
  matrix_2.SetMatrix(2, 1, 2);
  matrix_2.SetMatrix(2, 2, 3);
  matrix_2.SetMatrix(2, 3, 0);
  matrix_2.SetMatrix(3, 0, 2);
  matrix_2.SetMatrix(3, 1, 3);
  matrix_2.SetMatrix(3, 2, 0);
  matrix_2.SetMatrix(3, 3, -5);

  bool result = matrix.EqMatrix(matrix_2);
  ASSERT_EQ(result, FAILURE);
}

TEST(TestEqMatrix, EqMatrixFour) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  bool result = matrix.EqMatrix(matrix_2);
  ASSERT_EQ(result, FAILURE);
}

TEST(TestSumMatrix, SumMatrixOne) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);

  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 3);
  matrix_2.SetMatrix(0, 2, -3);
  matrix_2.SetMatrix(0, 3, 4);
  matrix_2.SetMatrix(1, 0, 10);
  matrix_2.SetMatrix(1, 1, 1);
  matrix_2.SetMatrix(1, 2, -1);
  matrix_2.SetMatrix(1, 3, 2);
  matrix_2.SetMatrix(2, 0, 6);
  matrix_2.SetMatrix(2, 1, 2);
  matrix_2.SetMatrix(2, 2, 31);
  matrix_2.SetMatrix(2, 3, 0);
  matrix_2.SetMatrix(3, 0, 2);
  matrix_2.SetMatrix(3, 1, 16);
  matrix_2.SetMatrix(3, 2, -2);
  matrix_2.SetMatrix(3, 3, -5);

  matrix.SumMatrix(matrix_2);
  ASSERT_EQ(matrix(0, 0), 4);
  ASSERT_EQ(matrix(0, 1), 6);
  ASSERT_EQ(matrix(0, 2), -6);
  ASSERT_EQ(matrix(0, 3), 8);
  ASSERT_EQ(matrix(1, 0), 12);
  ASSERT_EQ(matrix(1, 1), 2);
  ASSERT_EQ(matrix(1, 2), -2);
  ASSERT_EQ(matrix(1, 3), 4);
  ASSERT_EQ(matrix(2, 0), 12);
  ASSERT_EQ(matrix(2, 1), 4);
  ASSERT_EQ(matrix(2, 2), 32);
  ASSERT_EQ(matrix(2, 3), 0);
  ASSERT_EQ(matrix(3, 0), 4);
  ASSERT_EQ(matrix(3, 1), 19);
  ASSERT_EQ(matrix(3, 2), -2);
  ASSERT_EQ(matrix(3, 3), -10);
}

TEST(TestSumMatrix, SumMatrixTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 2.1);
  matrix.SetMatrix(0, 1, 3.57);
  matrix.SetMatrix(1, 0, 2.776);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, -34.5);
  matrix_2.SetMatrix(0, 1, 445.32);
  matrix_2.SetMatrix(1, 0, 98.268);
  matrix_2.SetMatrix(1, 1, -1.0034);
  matrix.SumMatrix(matrix_2);
  ASSERT_EQ(matrix(0, 0), -32.4);
  ASSERT_EQ(matrix(0, 1), 448.89);
  ASSERT_EQ(matrix(1, 0), 101.044);
  ASSERT_EQ(matrix(1, 1), -1.0034);
}

TEST(TestSumMatrix, SumMatrixExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix.SumMatrix(matrix_2););
}

TEST(TestSubMatrix, SubMatrixOne) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 2.1);
  matrix.SetMatrix(0, 1, 3.57);
  matrix.SetMatrix(1, 0, 2.776);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, -34.5);
  matrix_2.SetMatrix(0, 1, 445.32);
  matrix_2.SetMatrix(1, 0, 98.268);
  matrix_2.SetMatrix(1, 1, -1.0034);
  matrix.SubMatrix(matrix_2);
  ASSERT_EQ(matrix(0, 0), 36.6);
  ASSERT_EQ(matrix(0, 1), -441.75);
  ASSERT_EQ(matrix(1, 0), -95.492);
  ASSERT_EQ(matrix(1, 1), 1.0034);
}

TEST(TestSubMatrix, SubMatrixTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix_2.SetMatrix(0, 0, 123);
  matrix.SetMatrix(0, 1, 100);
  matrix_2.SetMatrix(0, 1, -123);
  matrix.SetMatrix(1, 0, 383);
  matrix_2.SetMatrix(1, 0, 382);
  matrix.SetMatrix(1, 1, 404);
  matrix_2.SetMatrix(1, 1, 4);
  matrix.SubMatrix(matrix_2);
  ASSERT_EQ(matrix(0, 0), -23);
  ASSERT_EQ(matrix(0, 1), 223);
  ASSERT_EQ(matrix(1, 0), 1);
  ASSERT_EQ(matrix(1, 1), 400);
}

TEST(TestSubMatrix, SubMatrixExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix.SubMatrix(matrix_2));
}

TEST(TestMulNumber, MulNumberOne) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 23.4);
  matrix.SetMatrix(0, 1, -18);
  matrix.SetMatrix(1, 0, 239);
  matrix.SetMatrix(1, 1, 3904.9);
  matrix.MulNumber(2);
  ASSERT_EQ(matrix(0, 0), 46.8);
  ASSERT_EQ(matrix(0, 1), -36);
  ASSERT_EQ(matrix(1, 0), 478);
  ASSERT_EQ(matrix(1, 1), 7809.8);
}

TEST(TestMulNumber, MulNumberTwo) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 23);
  matrix.SetMatrix(0, 1, -18);
  matrix.SetMatrix(1, 0, 239);
  matrix.SetMatrix(1, 1, 3904.9);
  matrix.MulNumber(-6);
  ASSERT_EQ(matrix(0, 0), -138);
  ASSERT_EQ(matrix(0, 1), 108);
  ASSERT_EQ(matrix(1, 0), -1434);
  ASSERT_EQ(matrix(1, 1), -23429.4);
}

TEST(TestMulMatrix, MulMatrixOne) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 4);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 9);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, 3);
  matrix_2.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(1, 0, -3);
  matrix_2.SetMatrix(1, 1, 4);
  matrix.MulMatrix(matrix_2);
  ASSERT_EQ(matrix(0, 0), 6);
  ASSERT_EQ(matrix(0, 1), 12);
  ASSERT_EQ(matrix(1, 0), 27);
  ASSERT_EQ(matrix(1, 1), 9);
}

TEST(TestMulMatrix, MulMatrixTwo) {
  matrix::Matrix matrix(3, 2);
  matrix::Matrix matrix_2(2, 3);
  matrix.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 0, 5);
  matrix.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(0, 1, -1);
  matrix.SetMatrix(1, 0, -3);
  matrix_2.SetMatrix(1, 0, -3);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(1, 1, 0);
  matrix.SetMatrix(2, 0, 4);
  matrix.SetMatrix(2, 1, -1);
  matrix_2.SetMatrix(0, 2, 6);
  matrix_2.SetMatrix(1, 2, 7);
  matrix.MulMatrix(matrix_2);
  ASSERT_EQ(matrix(0, 0), 7);
  ASSERT_EQ(matrix(0, 1), -2);
  ASSERT_EQ(matrix(0, 2), 19);
  ASSERT_EQ(matrix(1, 0), -15);
  ASSERT_EQ(matrix(1, 1), 3);
  ASSERT_EQ(matrix(1, 2), -18);
  ASSERT_EQ(matrix(2, 0), 23);
  ASSERT_EQ(matrix(2, 1), -4);
  ASSERT_EQ(matrix(2, 2), 17);
}

TEST(TestMulMatrix, MulMatrixExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix.MulMatrix(matrix_2));
}

TEST(TestTranspose, TransposeOne) {
  matrix::Matrix matrix(3, 3);
  matrix.SetMatrix(0, 0, 494.24);
  matrix.SetMatrix(0, 1, 245.244);
  matrix.SetMatrix(0, 2, -249.3);
  matrix.SetMatrix(1, 0, 2.455);
  matrix.SetMatrix(1, 1, 2355.3);
  matrix.SetMatrix(1, 2, 4748);
  matrix.SetMatrix(2, 0, 8896);
  matrix.SetMatrix(2, 1, -3567);
  matrix.SetMatrix(2, 2, 678);
  matrix::Matrix matrix_2(3, 3);
  matrix_2 = matrix.Transpose();
  ASSERT_EQ(matrix_2(0, 0), 494.24);
  ASSERT_EQ(matrix_2(0, 1), 2.455);
  ASSERT_EQ(matrix_2(0, 2), 8896);
  ASSERT_EQ(matrix_2(1, 0), 245.244);
  ASSERT_EQ(matrix_2(1, 1), 2355.3);
  ASSERT_EQ(matrix_2(1, 2), -3567);
  ASSERT_EQ(matrix_2(2, 0), -249.3);
  ASSERT_EQ(matrix_2(2, 1), 4748);
  ASSERT_EQ(matrix_2(2, 2), 678);
}

TEST(TestTranspose, TransposeTwo) {
  matrix::Matrix matrix(3, 2);
  matrix.SetMatrix(0, 0, 494.24);
  matrix.SetMatrix(0, 1, 245.244);
  matrix.SetMatrix(1, 0, 2.455);
  matrix.SetMatrix(1, 1, 2355.3);
  matrix.SetMatrix(2, 0, 8896);
  matrix.SetMatrix(2, 1, -3567);
  matrix::Matrix matrix_2(2, 3);
  matrix_2 = matrix.Transpose();
  ASSERT_EQ(matrix(0, 0), 494.24);
  ASSERT_EQ(matrix_2(0, 1), 2.455);
  ASSERT_EQ(matrix_2(0, 2), 8896);
  ASSERT_EQ(matrix_2(1, 0), 245.244);
  ASSERT_EQ(matrix_2(1, 1), 2355.3);
  ASSERT_EQ(matrix_2(1, 2), -3567);
}

TEST(TestCalcComplements, CalcComplementsOne) {
  matrix::Matrix matrix(3, 3);
  matrix.SetMatrix(0, 0, 7);
  matrix.SetMatrix(0, 1, -4);
  matrix.SetMatrix(0, 2, 6);
  matrix.SetMatrix(1, 0, -5);
  matrix.SetMatrix(1, 1, 3);
  matrix.SetMatrix(1, 2, 2);
  matrix.SetMatrix(2, 0, -1);
  matrix.SetMatrix(2, 1, 8);
  matrix.SetMatrix(2, 2, -4);
  matrix::Matrix matrix_2(3, 3);
  matrix_2 = matrix.CalcComplements();
  ASSERT_EQ(matrix_2(0, 0), -28);
  ASSERT_EQ(matrix_2(0, 1), -22);
  ASSERT_EQ(matrix_2(0, 2), -37);
  ASSERT_EQ(matrix_2(1, 0), 32);
  ASSERT_EQ(matrix_2(1, 1), -22);
  ASSERT_EQ(matrix_2(1, 2), -52);
  ASSERT_EQ(matrix_2(2, 0), -26);
  ASSERT_EQ(matrix_2(2, 1), -44);
  ASSERT_EQ(matrix_2(2, 2), 1);
}

TEST(TestCalcComplements, CalcComplementsTwo) {
  matrix::Matrix matrix(4, 4);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 0);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 9);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, -7);
  matrix.SetMatrix(1, 2, 11);
  matrix.SetMatrix(1, 3, 5);
  matrix.SetMatrix(2, 0, -9);
  matrix.SetMatrix(2, 1, 4);
  matrix.SetMatrix(2, 2, 25);
  matrix.SetMatrix(2, 3, 84);
  matrix.SetMatrix(3, 0, 3);
  matrix.SetMatrix(3, 1, 12);
  matrix.SetMatrix(3, 2, -5);
  matrix.SetMatrix(3, 3, 58);
  matrix::Matrix matrix_2(4, 4);
  matrix_2 = matrix.CalcComplements();
  ASSERT_EQ(matrix_2(0, 0), -6154);
  ASSERT_EQ(matrix_2(0, 1), -12104);
  ASSERT_EQ(matrix_2(0, 2), -7570);
  ASSERT_EQ(matrix_2(0, 3), 2170);
  ASSERT_EQ(matrix_2(1, 0), 5208);
  ASSERT_EQ(matrix_2(1, 1), -722);
  ASSERT_EQ(matrix_2(1, 2), 1856);
  ASSERT_EQ(matrix_2(1, 3), 40);
  ASSERT_EQ(matrix_2(2, 0), -2271);
  ASSERT_EQ(matrix_2(2, 1), -579);
  ASSERT_EQ(matrix_2(2, 2), -61);
  ASSERT_EQ(matrix_2(2, 3), 232);
  ASSERT_EQ(matrix_2(3, 0), 3795);
  ASSERT_EQ(matrix_2(3, 1), 2779);
  ASSERT_EQ(matrix_2(3, 2), 1103);
  ASSERT_EQ(matrix_2(3, 3), -54);
}

TEST(TestCalcComplements, CalcComplementsThree) {
  matrix::Matrix matrix(1, 1);
  matrix.SetMatrix(0, 0, 7);
  matrix::Matrix matrix_2(1, 1);
  matrix_2 = matrix.CalcComplements();
  ASSERT_EQ(matrix_2(0, 0), 1);
}

TEST(TestCalcComplements, CalcComplementsExpectThrow) {
  matrix::Matrix matrix(3, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix.SetMatrix(2, 0, 3);
  matrix.SetMatrix(2, 1, 4);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(TestDeterminant, DeterminantOne) {
  matrix::Matrix matrix(3, 3);
  matrix.SetMatrix(0, 0, 35);
  matrix.SetMatrix(0, 1, -33);
  matrix.SetMatrix(0, 2, 16);
  matrix.SetMatrix(1, 0, 86);
  matrix.SetMatrix(1, 1, 33);
  matrix.SetMatrix(1, 2, -54);
  matrix.SetMatrix(2, 0, 17);
  matrix.SetMatrix(2, 1, 59);
  matrix.SetMatrix(2, 2, 72);
  double result = 0.0;
  result = matrix.Determinant();
  ASSERT_EQ(result, 501508);
}

TEST(TestDeterminant, DeterminantTwo) {
  matrix::Matrix matrix(4, 4);
  matrix.SetMatrix(0, 0, 35);
  matrix.SetMatrix(0, 1, -33);
  matrix.SetMatrix(0, 2, 16);
  matrix.SetMatrix(0, 3, 20);
  matrix.SetMatrix(1, 0, 86);
  matrix.SetMatrix(1, 1, 33);
  matrix.SetMatrix(1, 2, -54);
  matrix.SetMatrix(1, 3, 44);
  matrix.SetMatrix(2, 0, 17);
  matrix.SetMatrix(2, 1, 59);
  matrix.SetMatrix(2, 2, 72);
  matrix.SetMatrix(2, 3, 93);
  matrix.SetMatrix(3, 0, -10);
  matrix.SetMatrix(3, 1, 12);
  matrix.SetMatrix(3, 2, 57);
  matrix.SetMatrix(3, 3, 38);
  double result = 0.0;
  result = matrix.Determinant();
  ASSERT_EQ(result, -54381);
}

TEST(TestDeterminant, DeterminantThree) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 35);
  matrix.SetMatrix(0, 1, -33);
  matrix.SetMatrix(1, 0, 86);
  matrix.SetMatrix(1, 1, 33);
  double result = 0.0;
  result = matrix.Determinant();
  ASSERT_EQ(result, 3993);
}

TEST(TestDeterminant, DeterminantFour) {
  matrix::Matrix matrix(1, 1);
  matrix.SetMatrix(0, 0, 5);
  double result = 0.0;
  result = matrix.Determinant();
  ASSERT_EQ(result, 5);
}

TEST(TestDeterminant, DeterminantExpectThrow) {
  matrix::Matrix matrix(3, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix.SetMatrix(2, 0, 3);
  matrix.SetMatrix(2, 1, 4);
  EXPECT_ANY_THROW(matrix.Determinant(););
}

TEST(TestInverseMatrix, InverseMatrixOne) {
  matrix::Matrix matrix(3, 3);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 5);
  matrix.SetMatrix(0, 2, 7);
  matrix.SetMatrix(1, 0, 6);
  matrix.SetMatrix(1, 1, 3);
  matrix.SetMatrix(1, 2, 4);
  matrix.SetMatrix(2, 0, 5);
  matrix.SetMatrix(2, 1, -2);
  matrix.SetMatrix(2, 2, -3);
  matrix::Matrix matrix_2(3, 3);
  matrix_2 = matrix.InverseMatrix();
  ASSERT_EQ(matrix_2(0, 0), 1);
  ASSERT_EQ(matrix_2(0, 1), -1);
  ASSERT_EQ(matrix_2(0, 2), 1);
  ASSERT_EQ(matrix_2(1, 0), -38);
  ASSERT_EQ(matrix_2(1, 1), 41);
  ASSERT_EQ(matrix_2(1, 2), -34);
  ASSERT_EQ(matrix_2(2, 0), 27);
  ASSERT_EQ(matrix_2(2, 1), -29);
  ASSERT_EQ(matrix_2(2, 2), 24);
}

TEST(TestInverseMatrix, InverseMatrixTwo) {
  matrix::Matrix matrix(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 1);
  matrix.SetMatrix(0, 2, 0);
  matrix.SetMatrix(0, 3, 0);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 2);
  matrix.SetMatrix(1, 2, 0);
  matrix.SetMatrix(1, 3, 0);
  matrix.SetMatrix(2, 0, 1);
  matrix.SetMatrix(2, 1, 1);
  matrix.SetMatrix(2, 2, 3);
  matrix.SetMatrix(2, 3, 4);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, -1);
  matrix.SetMatrix(3, 2, 2);
  matrix.SetMatrix(3, 3, 3);
  matrix::Matrix matrix_2(4, 4);
  matrix_2 = matrix.InverseMatrix();
  ASSERT_EQ(matrix_2(0, 0), 2);
  ASSERT_EQ(matrix_2(0, 1), -1);
  ASSERT_EQ(matrix_2(0, 2), 0);
  ASSERT_EQ(matrix_2(0, 3), 0);
  ASSERT_EQ(matrix_2(1, 0), -3);
  ASSERT_EQ(matrix_2(1, 1), 2);
  ASSERT_EQ(matrix_2(1, 2), 0);
  ASSERT_EQ(matrix_2(1, 3), 0);
  ASSERT_EQ(matrix_2(2, 0), 31);
  ASSERT_EQ(matrix_2(2, 1), -19);
  ASSERT_EQ(matrix_2(2, 2), 3);
  ASSERT_EQ(matrix_2(2, 3), -4);
  ASSERT_EQ(matrix_2(3, 0), -23);
  ASSERT_EQ(matrix_2(3, 1), 14);
  ASSERT_EQ(matrix_2(3, 2), -2);
  ASSERT_EQ(matrix_2(3, 3), 3);
}

TEST(TestInverseMatrix, InverseMatrixThree) {
  matrix::Matrix matrix(1, 1);
  matrix.SetMatrix(0, 0, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix_2 = matrix.InverseMatrix();
  ASSERT_EQ(matrix_2(0, 0), 0.5);
}

TEST(TestInverseMatrix, InverseMatrixFour) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 3);
  matrix.SetMatrix(0, 1, 4);
  matrix.SetMatrix(1, 0, 5);
  matrix.SetMatrix(1, 1, 7);
  matrix::Matrix matrix_2(2, 2);
  matrix_2 = matrix.InverseMatrix();
  ASSERT_EQ(matrix_2(0, 0), 7);
  ASSERT_EQ(matrix_2(0, 1), -4);
  ASSERT_EQ(matrix_2(1, 0), -5);
  ASSERT_EQ(matrix_2(1, 1), 3);
}

TEST(TestInverseMatrix, InverseMatrixExpectThrow) {
  matrix::Matrix matrix(3, 3);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, 2);
  matrix.SetMatrix(1, 0, 1);
  matrix.SetMatrix(1, 1, 3);
  matrix.SetMatrix(1, 2, 2);
  matrix.SetMatrix(2, 0, 5);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 8);
  EXPECT_ANY_THROW(matrix.InverseMatrix(););
}

TEST(TestInverseMatrix, InverseMatrixExpectThrowTwo) {
  matrix::Matrix matrix(3, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(1, 0, 1);
  matrix.SetMatrix(1, 1, 3);
  matrix.SetMatrix(2, 0, 5);
  matrix.SetMatrix(2, 1, 2);
  EXPECT_ANY_THROW(matrix.InverseMatrix(););
}

TEST(TestPlusOperator, PlusOperatorOne) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix::Matrix matrix_3(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);

  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 3);
  matrix_2.SetMatrix(0, 2, -3);
  matrix_2.SetMatrix(0, 3, 4);
  matrix_2.SetMatrix(1, 0, 10);
  matrix_2.SetMatrix(1, 1, 1);
  matrix_2.SetMatrix(1, 2, -1);
  matrix_2.SetMatrix(1, 3, 2);
  matrix_2.SetMatrix(2, 0, 6);
  matrix_2.SetMatrix(2, 1, 2);
  matrix_2.SetMatrix(2, 2, 31);
  matrix_2.SetMatrix(2, 3, 0);
  matrix_2.SetMatrix(3, 0, 2);
  matrix_2.SetMatrix(3, 1, 16);
  matrix_2.SetMatrix(3, 2, -2);
  matrix_2.SetMatrix(3, 3, -5);
  matrix_3 = matrix + matrix_2;
  ASSERT_EQ(matrix_3(0, 0), 4);
  ASSERT_EQ(matrix_3(0, 1), 6);
  ASSERT_EQ(matrix_3(0, 2), -6);
  ASSERT_EQ(matrix_3(0, 3), 8);
  ASSERT_EQ(matrix_3(1, 0), 12);
  ASSERT_EQ(matrix_3(1, 1), 2);
  ASSERT_EQ(matrix_3(1, 2), -2);
  ASSERT_EQ(matrix_3(1, 3), 4);
  ASSERT_EQ(matrix_3(2, 0), 12);
  ASSERT_EQ(matrix_3(2, 1), 4);
  ASSERT_EQ(matrix_3(2, 2), 32);
  ASSERT_EQ(matrix_3(2, 3), 0);
  ASSERT_EQ(matrix_3(3, 0), 4);
  ASSERT_EQ(matrix_3(3, 1), 19);
  ASSERT_EQ(matrix_3(3, 2), -2);
  ASSERT_EQ(matrix_3(3, 3), -10);
}

TEST(TestPlusOperator, PlusOperatorTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 2.1);
  matrix.SetMatrix(0, 1, 3.57);
  matrix.SetMatrix(1, 0, 2.776);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, -34.5);
  matrix_2.SetMatrix(0, 1, 445.32);
  matrix_2.SetMatrix(1, 0, 98.268);
  matrix_2.SetMatrix(1, 1, -1.0034);
  matrix_3 = matrix + matrix_2;
  ASSERT_EQ(matrix_3(0, 0), -32.4);
  ASSERT_EQ(matrix_3(0, 1), 448.89);
  ASSERT_EQ(matrix_3(1, 0), 101.044);
  ASSERT_EQ(matrix_3(1, 1), -1.0034);
}

TEST(TestPlusOperator, PlusOperatorExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix + matrix_2);
}

TEST(TestSubOperator, SubOperatorOne) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 2.1);
  matrix.SetMatrix(0, 1, 3.57);
  matrix.SetMatrix(1, 0, 2.776);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, -34.5);
  matrix_2.SetMatrix(0, 1, 445.32);
  matrix_2.SetMatrix(1, 0, 98.268);
  matrix_2.SetMatrix(1, 1, -1.0034);
  matrix_3 = matrix - matrix_2;
  ASSERT_EQ(matrix_3(0, 0), 36.6);
  ASSERT_EQ(matrix_3(0, 1), -441.75);
  ASSERT_EQ(matrix_3(1, 0), -95.492);
  ASSERT_EQ(matrix_3(1, 1), 1.0034);
}

TEST(TestSubOperator, SubOperatorTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix_2.SetMatrix(0, 0, 123);
  matrix.SetMatrix(0, 1, 100);
  matrix_2.SetMatrix(0, 1, -123);
  matrix.SetMatrix(1, 0, 383);
  matrix_2.SetMatrix(1, 0, 382);
  matrix.SetMatrix(1, 1, 404);
  matrix_2.SetMatrix(1, 1, 4);
  matrix_3 = matrix - matrix_2;
  ASSERT_EQ(matrix_3(0, 0), -23);
  ASSERT_EQ(matrix_3(0, 1), 223);
  ASSERT_EQ(matrix_3(1, 0), 1);
  ASSERT_EQ(matrix_3(1, 1), 400);
}

TEST(TestSubOperator, SubOperatorExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix - matrix_2);
}

TEST(TestMulNumberOperator, MulNumberOperatorOne) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 23.4);
  matrix.SetMatrix(0, 1, -18);
  matrix.SetMatrix(1, 0, 239);
  matrix.SetMatrix(1, 1, 3904.9);
  matrix_3 = matrix * 2;
  ASSERT_EQ(matrix_3(0, 0), 46.8);
  ASSERT_EQ(matrix_3(0, 1), -36);
  ASSERT_EQ(matrix_3(1, 0), 478);
  ASSERT_EQ(matrix_3(1, 1), 7809.8);
}

TEST(TestMulNumberOperator, MulNumberOperatorTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 23);
  matrix.SetMatrix(0, 1, -18);
  matrix.SetMatrix(1, 0, 239);
  matrix.SetMatrix(1, 1, 3904.9);
  matrix_3 = matrix * -6;
  ASSERT_EQ(matrix_3(0, 0), -138);
  ASSERT_EQ(matrix_3(0, 1), 108);
  ASSERT_EQ(matrix_3(1, 0), -1434);
  ASSERT_EQ(matrix_3(1, 1), -23429.4);
}

TEST(TestMulNumberOperator, MulNumberOperatorFriends) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 23);
  matrix.SetMatrix(0, 1, -18);
  matrix.SetMatrix(1, 0, 239);
  matrix.SetMatrix(1, 1, 3904.9);
  matrix_3 = -6 * matrix;
  ASSERT_EQ(matrix_3(0, 0), -138);
  ASSERT_EQ(matrix_3(0, 1), 108);
  ASSERT_EQ(matrix_3(1, 0), -1434);
  ASSERT_EQ(matrix_3(1, 1), -23429.4);
}

TEST(TestMulOperator, MulOperatorOne) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 4);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 9);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, 3);
  matrix_2.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(1, 0, -3);
  matrix_2.SetMatrix(1, 1, 4);
  matrix_3 = matrix * matrix_2;
  ASSERT_EQ(matrix_3(0, 0), 6);
  ASSERT_EQ(matrix_3(0, 1), 12);
  ASSERT_EQ(matrix_3(1, 0), 27);
  ASSERT_EQ(matrix_3(1, 1), 9);
}

TEST(TestMulOperator, MulOperatorTwo) {
  matrix::Matrix matrix(3, 2);
  matrix::Matrix matrix_2(2, 3);
  matrix::Matrix matrix_3(2, 2);
  matrix.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 0, 5);
  matrix.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(0, 1, -1);
  matrix.SetMatrix(1, 0, -3);
  matrix_2.SetMatrix(1, 0, -3);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(1, 1, 0);
  matrix.SetMatrix(2, 0, 4);
  matrix.SetMatrix(2, 1, -1);
  matrix_2.SetMatrix(0, 2, 6);
  matrix_2.SetMatrix(1, 2, 7);
  matrix_3 = matrix * matrix_2;
  ASSERT_EQ(matrix_3(0, 0), 7);
  ASSERT_EQ(matrix_3(0, 1), -2);
  ASSERT_EQ(matrix_3(0, 2), 19);
  ASSERT_EQ(matrix_3(1, 0), -15);
  ASSERT_EQ(matrix_3(1, 1), 3);
  ASSERT_EQ(matrix_3(1, 2), -18);
  ASSERT_EQ(matrix_3(2, 0), 23);
  ASSERT_EQ(matrix_3(2, 1), -4);
  ASSERT_EQ(matrix_3(2, 2), 17);
}

TEST(TestMulOperator, MulOperatorExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix * matrix_2);
}

TEST(TestEqOperator, EqOperatorTrue) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  matrix_2.SetMatrix(0, 1, 2);
  matrix_2.SetMatrix(1, 0, 3);
  matrix_2.SetMatrix(1, 1, 4);
  bool result = matrix == matrix_2;
  ASSERT_EQ(result, SUCCESS);
}

TEST(TestEqOperator, EqOperatorFalse) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  matrix_2.SetMatrix(0, 1, 2);
  matrix_2.SetMatrix(1, 0, 3);
  matrix_2.SetMatrix(1, 1, 4.0001);
  bool result = matrix == matrix_2;
  ASSERT_EQ(result, FAILURE);
}

TEST(TestEqOperator, EqOperatorFalseTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  matrix_2.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(1, 0, 2);
  matrix_2.SetMatrix(1, 1, 4);
  bool result = matrix == matrix_2;
  ASSERT_EQ(result, FAILURE);
}

TEST(TestEqOperator, EqOperatorTrueTwo) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);

  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 3);
  matrix_2.SetMatrix(0, 2, -3);
  matrix_2.SetMatrix(0, 3, 4);
  matrix_2.SetMatrix(1, 0, 2);
  matrix_2.SetMatrix(1, 1, 1);
  matrix_2.SetMatrix(1, 2, -1);
  matrix_2.SetMatrix(1, 3, 2);
  matrix_2.SetMatrix(2, 0, 6);
  matrix_2.SetMatrix(2, 1, 2);
  matrix_2.SetMatrix(2, 2, 1);
  matrix_2.SetMatrix(2, 3, 0);
  matrix_2.SetMatrix(3, 0, 2);
  matrix_2.SetMatrix(3, 1, 3);
  matrix_2.SetMatrix(3, 2, 0);
  matrix_2.SetMatrix(3, 3, -5);

  bool result = matrix == matrix_2;
  ASSERT_EQ(result, SUCCESS);
}

TEST(TestEqOperator, EqOperatorFour) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  bool result = matrix == matrix_2;
  ASSERT_EQ(result, FAILURE);
}

TEST(TestEqOperator, EqOperatorFalseThree) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);

  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 3);
  matrix_2.SetMatrix(0, 2, -3);
  matrix_2.SetMatrix(0, 3, 4);
  matrix_2.SetMatrix(1, 0, 2);
  matrix_2.SetMatrix(1, 1, 1);
  matrix_2.SetMatrix(1, 2, -1);
  matrix_2.SetMatrix(1, 3, 2);
  matrix_2.SetMatrix(2, 0, 6);
  matrix_2.SetMatrix(2, 1, 2);
  matrix_2.SetMatrix(2, 2, 3);
  matrix_2.SetMatrix(2, 3, 0);
  matrix_2.SetMatrix(3, 0, 2);
  matrix_2.SetMatrix(3, 1, 3);
  matrix_2.SetMatrix(3, 2, 0);
  matrix_2.SetMatrix(3, 3, -5);

  bool result = matrix == matrix_2;
  ASSERT_EQ(result, FAILURE);
}

TEST(TestAssignOperator, AssignOperatorFalseThree) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);
  matrix_2 = matrix;

  ASSERT_EQ(matrix_2(0, 0), 2);
  ASSERT_EQ(matrix_2(0, 1), 3);
  ASSERT_EQ(matrix_2(0, 2), -3);
  ASSERT_EQ(matrix_2(0, 3), 4);
  ASSERT_EQ(matrix_2(1, 0), 2);
  ASSERT_EQ(matrix_2(1, 1), 1);
  ASSERT_EQ(matrix_2(1, 2), -1);
  ASSERT_EQ(matrix_2(1, 3), 2);
  ASSERT_EQ(matrix_2(2, 0), 6);
  ASSERT_EQ(matrix_2(2, 1), 2);
  ASSERT_EQ(matrix_2(2, 2), 1);
  ASSERT_EQ(matrix_2(2, 3), 0);
  ASSERT_EQ(matrix_2(3, 0), 2);
  ASSERT_EQ(matrix_2(3, 1), 3);
  ASSERT_EQ(matrix_2(3, 2), 0);
  ASSERT_EQ(matrix_2(3, 3), -5);
}

TEST(TestAssignOperator, AssignOperatorOne) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);
  matrix_2 = matrix;

  ASSERT_EQ(matrix_2(0, 0), 2);
  ASSERT_EQ(matrix_2(0, 1), 3);
  ASSERT_EQ(matrix_2(0, 2), -3);
  ASSERT_EQ(matrix_2(0, 3), 4);
  ASSERT_EQ(matrix_2(1, 0), 2);
  ASSERT_EQ(matrix_2(1, 1), 1);
  ASSERT_EQ(matrix_2(1, 2), -1);
  ASSERT_EQ(matrix_2(1, 3), 2);
  ASSERT_EQ(matrix_2(2, 0), 6);
  ASSERT_EQ(matrix_2(2, 1), 2);
  ASSERT_EQ(matrix_2(2, 2), 1);
  ASSERT_EQ(matrix_2(2, 3), 0);
  ASSERT_EQ(matrix_2(3, 0), 2);
  ASSERT_EQ(matrix_2(3, 1), 3);
  ASSERT_EQ(matrix_2(3, 2), 0);
  ASSERT_EQ(matrix_2(3, 3), -5);
}

TEST(TestAssignOperator, AssignOperatorTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 2.1);
  matrix.SetMatrix(0, 1, 3.57);
  matrix.SetMatrix(1, 0, 2.776);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, -34.5);
  matrix_2.SetMatrix(0, 1, 445.32);
  matrix_2.SetMatrix(1, 0, 98.268);
  matrix_2.SetMatrix(1, 1, -1.0034);
  matrix = matrix_2;
  ASSERT_EQ(matrix(0, 0), -34.5);
  ASSERT_EQ(matrix(0, 1), 445.32);
  ASSERT_EQ(matrix(1, 0), 98.268);
  ASSERT_EQ(matrix(1, 1), -1.0034);
}
TEST(TestPlusEqOperator, PlusEqOperatorOne) {
  matrix::Matrix matrix(4, 4);
  matrix::Matrix matrix_2(4, 4);
  matrix::Matrix matrix_3(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);

  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 3);
  matrix_2.SetMatrix(0, 2, -3);
  matrix_2.SetMatrix(0, 3, 4);
  matrix_2.SetMatrix(1, 0, 10);
  matrix_2.SetMatrix(1, 1, 1);
  matrix_2.SetMatrix(1, 2, -1);
  matrix_2.SetMatrix(1, 3, 2);
  matrix_2.SetMatrix(2, 0, 6);
  matrix_2.SetMatrix(2, 1, 2);
  matrix_2.SetMatrix(2, 2, 31);
  matrix_2.SetMatrix(2, 3, 0);
  matrix_2.SetMatrix(3, 0, 2);
  matrix_2.SetMatrix(3, 1, 16);
  matrix_2.SetMatrix(3, 2, -2);
  matrix_2.SetMatrix(3, 3, -5);
  matrix += matrix_2;
  ASSERT_EQ(matrix(0, 0), 4);
  ASSERT_EQ(matrix(0, 1), 6);
  ASSERT_EQ(matrix(0, 2), -6);
  ASSERT_EQ(matrix(0, 3), 8);
  ASSERT_EQ(matrix(1, 0), 12);
  ASSERT_EQ(matrix(1, 1), 2);
  ASSERT_EQ(matrix(1, 2), -2);
  ASSERT_EQ(matrix(1, 3), 4);
  ASSERT_EQ(matrix(2, 0), 12);
  ASSERT_EQ(matrix(2, 1), 4);
  ASSERT_EQ(matrix(2, 2), 32);
  ASSERT_EQ(matrix(2, 3), 0);
  ASSERT_EQ(matrix(3, 0), 4);
  ASSERT_EQ(matrix(3, 1), 19);
  ASSERT_EQ(matrix(3, 2), -2);
  ASSERT_EQ(matrix(3, 3), -10);
}

TEST(TestPlusEqOperator, PlusEqOperatorTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 2.1);
  matrix.SetMatrix(0, 1, 3.57);
  matrix.SetMatrix(1, 0, 2.776);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, -34.5);
  matrix_2.SetMatrix(0, 1, 445.32);
  matrix_2.SetMatrix(1, 0, 98.268);
  matrix_2.SetMatrix(1, 1, -1.0034);
  matrix += matrix_2;
  ASSERT_EQ(matrix(0, 0), -32.4);
  ASSERT_EQ(matrix(0, 1), 448.89);
  ASSERT_EQ(matrix(1, 0), 101.044);
  ASSERT_EQ(matrix(1, 1), -1.0034);
}

TEST(TestPlusEqOperator, PlusEqOperatorExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix += matrix_2);
}

TEST(TestSubEqOperator, SubEqOperatorOne) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 2.1);
  matrix.SetMatrix(0, 1, 3.57);
  matrix.SetMatrix(1, 0, 2.776);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, -34.5);
  matrix_2.SetMatrix(0, 1, 445.32);
  matrix_2.SetMatrix(1, 0, 98.268);
  matrix_2.SetMatrix(1, 1, -1.0034);
  matrix -= matrix_2;
  ASSERT_EQ(matrix(0, 0), 36.6);
  ASSERT_EQ(matrix(0, 1), -441.75);
  ASSERT_EQ(matrix(1, 0), -95.492);
  ASSERT_EQ(matrix(1, 1), 1.0034);
}

TEST(TestSubEqOperator, SubEqOperatorTwo) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix_2.SetMatrix(0, 0, 123);
  matrix.SetMatrix(0, 1, 100);
  matrix_2.SetMatrix(0, 1, -123);
  matrix.SetMatrix(1, 0, 383);
  matrix_2.SetMatrix(1, 0, 382);
  matrix.SetMatrix(1, 1, 404);
  matrix_2.SetMatrix(1, 1, 4);
  matrix -= matrix_2;
  ASSERT_EQ(matrix(0, 0), -23);
  ASSERT_EQ(matrix(0, 1), 223);
  ASSERT_EQ(matrix(1, 0), 1);
  ASSERT_EQ(matrix(1, 1), 400);
}

TEST(TestSubEqOperator, SubEqOperatorExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix -= matrix_2);
}

TEST(TestMulEqOperator, MulEqOperatorOne) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix.SetMatrix(0, 0, 4);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 9);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(0, 0, 3);
  matrix_2.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(1, 0, -3);
  matrix_2.SetMatrix(1, 1, 4);
  matrix *= matrix_2;
  ASSERT_EQ(matrix(0, 0), 6);
  ASSERT_EQ(matrix(0, 1), 12);
  ASSERT_EQ(matrix(1, 0), 27);
  ASSERT_EQ(matrix(1, 1), 9);
}

TEST(TestMulEqOperator, MulEqOperatorTwo) {
  matrix::Matrix matrix(3, 2);
  matrix::Matrix matrix_2(2, 3);
  matrix.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 0, 5);
  matrix.SetMatrix(0, 1, 1);
  matrix_2.SetMatrix(0, 1, -1);
  matrix.SetMatrix(1, 0, -3);
  matrix_2.SetMatrix(1, 0, -3);
  matrix.SetMatrix(1, 1, 0);
  matrix_2.SetMatrix(1, 1, 0);
  matrix.SetMatrix(2, 0, 4);
  matrix.SetMatrix(2, 1, -1);
  matrix_2.SetMatrix(0, 2, 6);
  matrix_2.SetMatrix(1, 2, 7);
  matrix *= matrix_2;
  ASSERT_EQ(matrix(0, 0), 7);
  ASSERT_EQ(matrix(0, 1), -2);
  ASSERT_EQ(matrix(0, 2), 19);
  ASSERT_EQ(matrix(1, 0), -15);
  ASSERT_EQ(matrix(1, 1), 3);
  ASSERT_EQ(matrix(1, 2), -18);
  ASSERT_EQ(matrix(2, 0), 23);
  ASSERT_EQ(matrix(2, 1), -4);
  ASSERT_EQ(matrix(2, 2), 17);
}

TEST(TestMulEqOperator, MulEqOperatorExpectThrow) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(1, 1);
  matrix.SetMatrix(0, 0, 1);
  matrix.SetMatrix(0, 1, 2);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 4);
  matrix_2.SetMatrix(0, 0, 1);
  EXPECT_ANY_THROW(matrix *= matrix_2);
}

TEST(TestGetRows, GetRowsOne) {
  matrix::Matrix matrix(3, 2);
  int rows = matrix.GetRows();
  ASSERT_EQ(rows, 3);
}

TEST(TestGetRows, GetRowsTwo) {
  matrix::Matrix matrix(10, 6);
  int rows = matrix.GetRows();
  ASSERT_EQ(rows, 10);
}

TEST(TestGetCols, GetColsOne) {
  matrix::Matrix matrix(3, 2);
  int cols = matrix.GetCols();
  ASSERT_EQ(cols, 2);
}

TEST(TestGetCols, GetColsTwo) {
  matrix::Matrix matrix(10, 6);
  int cols = matrix.GetCols();
  ASSERT_EQ(cols, 6);
}

TEST(TestSetCols, SetColsOne) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix.SetMatrix(0, 1, 100);
  matrix.SetMatrix(1, 0, 383);
  matrix.SetMatrix(1, 1, 404);
  matrix.SetCols(5);
  ASSERT_EQ(matrix.GetMatrix(0, 0), 100);
  ASSERT_EQ(matrix.GetMatrix(0, 1), 100);
  ASSERT_EQ(matrix.GetMatrix(0, 2), 0);
  ASSERT_EQ(matrix.GetMatrix(0, 3), 0);
  ASSERT_EQ(matrix.GetMatrix(0, 4), 0);
  ASSERT_EQ(matrix.GetMatrix(1, 0), 383);
  ASSERT_EQ(matrix.GetMatrix(1, 1), 404);
  ASSERT_EQ(matrix.GetMatrix(1, 2), 0);
  ASSERT_EQ(matrix.GetMatrix(1, 3), 0);
  ASSERT_EQ(matrix.GetMatrix(1, 4), 0);
}

TEST(TestSetRows, SetRowsOne) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix.SetMatrix(0, 1, 100);
  matrix.SetMatrix(1, 0, 383);
  matrix.SetMatrix(1, 1, 404);
  matrix.SetRows(5);
  ASSERT_EQ(matrix.GetMatrix(0, 0), 100);
  ASSERT_EQ(matrix.GetMatrix(0, 1), 100);
  ASSERT_EQ(matrix.GetMatrix(1, 0), 383);
  ASSERT_EQ(matrix.GetMatrix(1, 1), 404);
  ASSERT_EQ(matrix.GetMatrix(2, 0), 0);
  ASSERT_EQ(matrix.GetMatrix(2, 1), 0);
  ASSERT_EQ(matrix.GetMatrix(3, 0), 0);
  ASSERT_EQ(matrix.GetMatrix(3, 1), 0);
  ASSERT_EQ(matrix.GetMatrix(4, 0), 0);
  ASSERT_EQ(matrix.GetMatrix(4, 1), 0);
}

TEST(TestSetCols, SetColsTwo) {
  matrix::Matrix matrix(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);
  matrix.SetCols(2);
  ASSERT_EQ(matrix.GetMatrix(0, 0), 2);
  ASSERT_EQ(matrix.GetMatrix(0, 1), 3);
  ASSERT_EQ(matrix.GetMatrix(1, 0), 2);
  ASSERT_EQ(matrix.GetMatrix(1, 1), 1);
  ASSERT_EQ(matrix.GetMatrix(2, 0), 6);
  ASSERT_EQ(matrix.GetMatrix(2, 1), 2);
  ASSERT_EQ(matrix.GetMatrix(3, 0), 2);
  ASSERT_EQ(matrix.GetMatrix(3, 1), 3);
}

TEST(TestSetRows, SetRowsTwo) {
  matrix::Matrix matrix(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);
  matrix.SetRows(2);
  ASSERT_EQ(matrix.GetMatrix(0, 0), 2);
  ASSERT_EQ(matrix.GetMatrix(0, 1), 3);
  ASSERT_EQ(matrix.GetMatrix(0, 2), -3);
  ASSERT_EQ(matrix.GetMatrix(0, 3), 4);
  ASSERT_EQ(matrix.GetMatrix(1, 0), 2);
  ASSERT_EQ(matrix.GetMatrix(1, 1), 1);
  ASSERT_EQ(matrix.GetMatrix(1, 2), -1);
  ASSERT_EQ(matrix.GetMatrix(1, 3), 2);
}

TEST(TestOperatorBrace, OperatorBraceOne) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix.SetMatrix(0, 1, 100);
  matrix.SetMatrix(1, 0, 383);
  matrix.SetMatrix(1, 1, 404);
  EXPECT_ANY_THROW(matrix(2, 0));
}

TEST(TestSetMatrix, SetMatrixOne) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix.SetMatrix(0, 1, 100);
  matrix.SetMatrix(1, 0, 383);
  matrix.SetMatrix(1, 1, 404);
  EXPECT_ANY_THROW(matrix(2, 0));
}

TEST(TestSetMatrix, SetMatrixTwo) {
  matrix::Matrix matrix(1, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix.SetMatrix(0, 1, 100);
  bool result = matrix.SetMatrix(1, 0, 383);
  ASSERT_EQ(result, FAILURE);
}

TEST(TestConstructor, ConstructorCopy) {
  matrix::Matrix matrix(2, 2);
  matrix.SetMatrix(0, 0, 100);
  matrix.SetMatrix(0, 1, 100);
  matrix.SetMatrix(1, 0, 383);
  matrix.SetMatrix(1, 1, 404);
  matrix::Matrix matrix_2(matrix);
  ASSERT_EQ(matrix_2.GetMatrix(0, 0), 100);
  ASSERT_EQ(matrix.GetMatrix(0, 1), 100);
  ASSERT_EQ(matrix.GetMatrix(1, 0), 383);
  ASSERT_EQ(matrix.GetMatrix(1, 1), 404);
}

TEST(TestConstructor, ConstructorCopyTwo) {
  matrix::Matrix matrix(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);
  matrix::Matrix matrix_2(matrix);
  ASSERT_EQ(matrix_2.GetMatrix(0, 0), 2);
  ASSERT_EQ(matrix_2.GetMatrix(0, 1), 3);
  ASSERT_EQ(matrix_2.GetMatrix(0, 2), -3);
  ASSERT_EQ(matrix_2.GetMatrix(0, 3), 4);
  ASSERT_EQ(matrix_2.GetMatrix(1, 0), 2);
  ASSERT_EQ(matrix_2.GetMatrix(1, 1), 1);
  ASSERT_EQ(matrix_2.GetMatrix(1, 2), -1);
  ASSERT_EQ(matrix_2.GetMatrix(1, 3), 2);
  ASSERT_EQ(matrix_2.GetMatrix(2, 0), 6);
  ASSERT_EQ(matrix_2.GetMatrix(2, 1), 2);
  ASSERT_EQ(matrix_2.GetMatrix(2, 2), 1);
  ASSERT_EQ(matrix_2.GetMatrix(2, 3), 0);
  ASSERT_EQ(matrix_2.GetMatrix(3, 0), 2);
  ASSERT_EQ(matrix_2.GetMatrix(3, 1), 3);
  ASSERT_EQ(matrix_2.GetMatrix(3, 2), 0);
  ASSERT_EQ(matrix_2.GetMatrix(3, 3), -5);
}

TEST(TestConstructor, ConstructorCopyThree) {
  matrix::Matrix matrix(4, 4);
  matrix.SetMatrix(0, 0, 2);
  matrix.SetMatrix(0, 1, 3);
  matrix.SetMatrix(0, 2, -3);
  matrix.SetMatrix(0, 3, 4);
  matrix.SetMatrix(1, 0, 2);
  matrix.SetMatrix(1, 1, 1);
  matrix.SetMatrix(1, 2, -1);
  matrix.SetMatrix(1, 3, 2);
  matrix.SetMatrix(2, 0, 6);
  matrix.SetMatrix(2, 1, 2);
  matrix.SetMatrix(2, 2, 1);
  matrix.SetMatrix(2, 3, 0);
  matrix.SetMatrix(3, 0, 2);
  matrix.SetMatrix(3, 1, 3);
  matrix.SetMatrix(3, 2, 0);
  matrix.SetMatrix(3, 3, -5);
  matrix::Matrix matrix_2(matrix);
  matrix_2.SubMatrix(matrix);
  ASSERT_EQ(matrix_2.GetMatrix(0, 0), 0);
  ASSERT_EQ(matrix_2.GetMatrix(0, 1), 0);
  ASSERT_EQ(matrix_2.GetMatrix(0, 2), 0);
  ASSERT_EQ(matrix_2.GetMatrix(0, 3), 0);
  ASSERT_EQ(matrix_2.GetMatrix(1, 0), 0);
  ASSERT_EQ(matrix_2.GetMatrix(1, 1), 0);
  ASSERT_EQ(matrix_2.GetMatrix(1, 2), 0);
  ASSERT_EQ(matrix_2.GetMatrix(1, 3), 0);
  ASSERT_EQ(matrix_2.GetMatrix(2, 0), 0);
  ASSERT_EQ(matrix_2.GetMatrix(2, 1), 0);
  ASSERT_EQ(matrix_2.GetMatrix(2, 2), 0);
  ASSERT_EQ(matrix_2.GetMatrix(2, 3), 0);
  ASSERT_EQ(matrix_2.GetMatrix(3, 0), 0);
  ASSERT_EQ(matrix_2.GetMatrix(3, 1), 0);
  ASSERT_EQ(matrix_2.GetMatrix(3, 2), 0);
  ASSERT_EQ(matrix_2.GetMatrix(3, 3), 0);
}

TEST(TestConstructor, ConstructorThrowOne) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix.SumMatrix(matrix_2););
}

TEST(TestConstructor, ConstructorThrowTwo) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix.SubMatrix(matrix_2););
}

TEST(TestConstructor, ConstructorThrowThree) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix.MulMatrix(matrix_2););
}

TEST(TestConstructor, ConstructorThrowFour) {
  matrix::Matrix matrix;
  EXPECT_ANY_THROW(matrix.Transpose(););
}

TEST(TestConstructor, ConstructorThrowFive) {
  matrix::Matrix matrix;
  EXPECT_ANY_THROW(matrix.MulNumber(-6););
}

TEST(TestConstructor, ConstructorThrowSix) {
  matrix::Matrix matrix;
  EXPECT_ANY_THROW(matrix.CalcComplements(););
}

TEST(TestConstructor, ConstructorThrowSeven) {
  matrix::Matrix matrix;
  EXPECT_ANY_THROW(matrix.Determinant(););
}

TEST(TestConstructor, ConstructorThrowEight) {
  matrix::Matrix matrix;
  EXPECT_ANY_THROW(matrix.InverseMatrix(););
}

TEST(TestConstructor, ConstructorOperationThrowOne) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix + matrix_2);
}

TEST(TestConstructor, ConstructorOperationThrowTwo) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix - matrix_2);
}

TEST(TestConstructor, ConstructorOperationThrowThree) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix * matrix_2);
}

TEST(TestConstructor, ConstructorOperationThrowFour) {
  matrix::Matrix matrix;
  EXPECT_ANY_THROW(matrix * 6);
}

TEST(TestConstructor, ConstructorOperationThrowFive) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix = matrix_2);
}

TEST(TestConstructor, ConstructorOperationThrowSix) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix += matrix_2);
}

TEST(TestConstructor, ConstructorOperationThrowSeven) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix -= matrix_2);
}

TEST(TestConstructor, ConstructorOperationThrowEight) {
  matrix::Matrix matrix;
  matrix::Matrix matrix_2;
  EXPECT_ANY_THROW(matrix *= matrix_2);
}

TEST(TestConstructor, ConstructorMove) {
  matrix::Matrix matrix(2, 2);
  matrix::Matrix matrix_2(2, 2);
  matrix_2.SetMatrix(0, 0, 3);
  matrix_2.SetMatrix(0, 1, 4);
  matrix_2.SetMatrix(1, 0, 5);
  matrix_2.SetMatrix(1, 1, 7);
  matrix.SetMatrix(0, 0, -2);
  matrix.SetMatrix(0, 1, 1);
  matrix.SetMatrix(1, 0, 3);
  matrix.SetMatrix(1, 1, 1);
  matrix = matrix::Matrix(std::move(matrix_2));
  ASSERT_EQ(matrix(0, 0), 3);
  ASSERT_EQ(matrix(0, 1), 4);
  ASSERT_EQ(matrix(1, 0), 5);
  ASSERT_EQ(matrix(1, 1), 7);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
