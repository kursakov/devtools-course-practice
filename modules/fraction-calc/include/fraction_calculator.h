// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_FRACTION_CALC_INCLUDE_FRACTION_CALCULATOR_H_
#define MODULES_FRACTION_CALC_INCLUDE_FRACTION_CALCULATOR_H_

#include <string>

class FractionCalculator {
 public:
    FractionCalculator();
    std::string operator()(int argc, const char **argv);

 private:
    void help(const char *appName, const char *message = "");
    bool validateNumberOfArguments(int argc, const char **argv);

    std::string message_;
};

#endif  // MODULES_FRACTION_CALC_INCLUDE_FRACTION_CALCULATOR_H_
