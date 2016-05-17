// Copyright 2016 Kursakov Evgeny

#include "include/fraction.h"
#include "include/fraction_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <sstream>

int parseInt(const char *arg);

char parseOperation(const char *arg);
FractionCalculator::FractionCalculator() : message_("") { }

void FractionCalculator::help(const char *appName, const char *message) {
    message_ =
        std::string(message) +
            "This is a fraction calculator application.\n\n" +
            "Please provide arguments in the following format:\n\n" +

            "  $ " + appName + " <z1_num> <z1_denom> " +
            "<z2_num> <z2_denom> <operation>\n\n" +

            "Where all arguments are integer numbers, " +
            "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool FractionCalculator::validateNumberOfArguments(int argc,
                                                   const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}


std::string FractionCalculator::operator()(int argc, const char **argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.z1_num = parseInt(argv[1]);
        args.z1_denom = parseInt(argv[2]);
        args.z2_num = parseInt(argv[3]);
        args.z2_denom = parseInt(argv[4]);
        args.operation = parseOperation(argv[5]);
    }
    catch (std::string str) {
        return str;
    }

    Fraction z1;
    Fraction z2;

    z1.setNum(args.z1_num);
    z1.setDenom(args.z1_denom);
    z2.setNum(args.z2_num);
    z2.setDenom(args.z2_denom);

    Fraction z;
    std::ostringstream stream;
    switch (args.operation) {
        case '+':
            z = z1 + z2;
            stream << "Num = " << z.getNum() << " "
                << "Denom = " << z.getDenom();
            break;
        case '-':
            z = z1 - z2;
            stream << "Num = " << z.getNum() << " "
                << "Denom = " << z.getDenom();
            break;
        case '*':
            z = z1 * z2;
            stream << "Num = " << z.getNum() << " "
                << "Denom = " << z.getDenom();
            break;
        case '/':
            try {
                z = z1 / z2;
                stream << "Num = " << z.getNum() << " "
                    << "Denom = " << z.getDenom();
                break;
            }
            catch (std::string str) {
                return str;
            }
    }

    message_ = stream.str();

    return message_;
}

int parseInt(const char *arg) {
    char *end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char *arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}
