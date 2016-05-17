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

class FractionCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    FractionCalculator app_;
    string output_;
};

TEST_F(FractionCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a fraction calculator application\\..*");
}

TEST_F(FractionCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "pi", "2", "4", "+"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "1", "1", "1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(FractionCalculatorTest, Can_Add_Fractions) {
    vector<string> args = {"2", "3", "1", "6", "+"};

    Act(args);

    Assert("Numerator = 5 Denominator = 6");
}

TEST_F(FractionCalculatorTest, Can_Diff_Fractions) {
    vector<string> args = {"13", "7", "10", "14", "-"};

    Act(args);

    Assert("Numerator = 8 Denominator = 7");
}

TEST_F(FractionCalculatorTest, Can_Mult_Fractions) {
    vector<string> args = {"10", "11", "3", "8", "*"};

    Act(args);

    Assert("Numerator = 15 Denominator = 44");
}

TEST_F(FractionCalculatorTest, Can_Divide_Fractions) {
    vector<string> args = {"1", "30", "1", "20", "/"};

    Act(args);

    Assert("Numerator = 2 Denominator = 3");
}

TEST_F(FractionCalculatorTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = {"27", "30", "0", "1", "/"};

    Act(args);

    Assert("Can't divide by zero");
}
