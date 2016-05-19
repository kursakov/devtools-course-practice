// Copyright 2016 Muminov Ruslan, Kursakov Evgeny

#include <gtest/gtest.h>

#include <string>
#include <stdexcept>

#include "include/fraction.h"

TEST(FractionTest, Can_Create_Default) {
    // Arrange
    int n = 0;

    // Act
    Fraction z;

    // Assert
    EXPECT_EQ(n, z.getNum());
    EXPECT_TRUE(n != z.getDenom());
}

TEST(FractionTest, Do_Throw_When_Denominator_Is_Zero) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Fraction z1(1, 0));
}

TEST(FractionTest, Do_Throw_When_Denominator_Set_Zero) {
    // Arrange
    Fraction z;

    // Act & Assert
    ASSERT_ANY_THROW(z.setDenom(0));
}

TEST(FractionTest, Can_Create_Nonzero_Element) {
    // Arrange
    int n = 5;
    int d = 6;

    // Act
    Fraction z(5, 6);

    // Assert
    EXPECT_EQ(n, z.getNum());
    EXPECT_EQ(d, z.getDenom());
}

TEST(FractionTest, Can_Create_Via_Copying) {
    // Arrange
    Fraction z(21, 20);

    // Act
    Fraction expected_z = z;

    // Assert
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Create_With_Negative_Numerator) {
    // Arrange & Act
    Fraction z(-10, 6);

    // Assert
    EXPECT_EQ(z.getNum(), -5);
    EXPECT_EQ(z.getDenom(), 3);
}

TEST(FractionTest, Can_Create_With_Negative_Denominator) {
    // Arrange & Act
    Fraction z(10, -6);

    // Assert
    EXPECT_EQ(z.getNum(), -5);
    EXPECT_EQ(z.getDenom(), 3);
}

TEST(FractionTest, Can_Create_With_Zero_Numerator) {
    // Arrange & Act
    Fraction z(0, 1);

    // Assert
    EXPECT_EQ(z.getNum(), 0);
    EXPECT_EQ(z.getDenom(), 1);
}

TEST(FractionTest, Can_Create_With_Negative_Numerator_And_Denominator) {
    // Arrange & Act
    Fraction z(-5, -6);

    // Assert
    EXPECT_EQ(z.getNum(), 5);
    EXPECT_EQ(z.getDenom(), 6);
}

TEST(FractionTest, Can_Set_Numerator) {
    // Arrange
    Fraction z;
    int n = 20;

    // Act
    z.setNum(n);

    // Assert
    EXPECT_EQ(n, z.getNum());
}

TEST(FractionTest, Can_Set_Denominator) {
    // Arrange
    Fraction z;
    int d = 26;

    // Act
    z.setDenom(d);

    // Assert
    EXPECT_EQ(d, z.getDenom());
}

TEST(FractionTest, Can_Add_Fraction) {
    // Arrange
    Fraction z1(0, 14);
    Fraction z2(1, 7);

    // Arrange
    Fraction z = z1 + z2;

    // Assert
    Fraction expected_z(1, 7);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Add_Negative_Fractions) {
    // Arrange
    Fraction z1(-3, 5);
    Fraction z2(-1, 3);

    // Arrange
    Fraction z = z1 + z2;

    // Assert
    Fraction expected_z(-14, 15);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Difference_Fraction) {
    // Arrange
    Fraction z1(3, 14);
    Fraction z2(1, 7);
    Fraction z;

    // Act
    z = z1 - z2;

    // Assert
    Fraction expected_z(1, 14);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Multiplication_Fraction) {
    // Arrange
    Fraction z1(5, 3);
    Fraction z2(4, 6);

    // Act
    Fraction z = z1 * z2;

    // Assert
    Fraction expected_z(20, 18);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Can_Division_Fraction) {
     // Arrange
    Fraction z1(5, 2);
    Fraction z2(7, 3);

    // Act
    Fraction z = z2 / z1;

    // Assert
    Fraction expected_z(14, 15);
    EXPECT_EQ(expected_z, z);
}

TEST(FractionTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    Fraction z1;
    Fraction z2(26, 14);

    // Act & Assert
    EXPECT_THROW(z2 / z1, std::invalid_argument);
}

TEST(FractionTest, Number_Is_Equal_To_Itself) {
    // Arrange
    Fraction z(26, 14);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(FractionTest, Equal_Numbers_Are_Equal) {
    // Arrange
    Fraction z1(2, 14);
    Fraction z2(1, 7);

    // Act & Assert
    EXPECT_EQ(z1, z2);
}

TEST(FractionTest, Different_Numbers_Not_Equal) {
    // Arrange
    Fraction z1(2, 14);
    Fraction z2(1, 8);

    // Act & Assert
    EXPECT_NE(z1, z2);
}
