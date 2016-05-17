// Copyright 2016 Kursakov Evgeny

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/fraction_calculator.h"

int main(int argc, const char** argv) {
    FractionCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
