// Copyright 2016 Muminov Ruslan

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/fraction_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;


class FractionCalculatorTest: public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(IsMatch(output_, expected));
    }

 private:
    FractionCalculator app_;
    string output_;

    ::testing::AssertionResult IsMatch(std::string output,
                                       std::string expected) {
        if (RE::FullMatch(output, RE(expected)))
            return ::testing::AssertionSuccess();
        else
            return ::testing::AssertionFailure()
                << "\nOutput:\n" << output
                << "\n\nRegex:\n" << expected << "\n";
    }
};

TEST_F(FractionCalculatorTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a fraction calculator application\\..*");
}

TEST_F(FractionCalculatorTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = {"10/2", "+"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(FractionCalculatorTest, Can_Add_Fractions) {
    // Arrange
    vector<string> args = {"1/4", "+",  "3/8"};

    // Act
    Act(args);

    // Assert
    Assert("5/8");
}

TEST_F(FractionCalculatorTest, Can_Multiply_Fractions) {
    // Arrange
    vector<string> args = {"11/3", "*",  "3/2"};

    // Act
    Act(args);

    // Assert
    Assert("11/2");
}

TEST_F(FractionCalculatorTest, Can_Divide_Fractions) {
    // Arrange
    vector<string> args = {"8/3", "/",  "2/5"};

    // Act
    Act(args);

    // Assert
    Assert("20/3");
}

TEST_F(FractionCalculatorTest, Can_Pass_Fraction_As_Integer) {
    // Arrange
    vector<string> args = {"1", "+",  "3/2"};

    // Act
    Act(args);

    // Assert
    Assert("5/2");
}
