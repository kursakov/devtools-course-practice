// Copyright 2016 Kursakov Evgeny

#include "include/fraction.h"
#include "include/fraction_calculator.h"

#include <string>
#include <sstream>

Fraction parseFraction(std::string arg);
int parseInt(std::string arg);
char parseOperation(const char *arg);

FractionCalculator::FractionCalculator() : message_("") { }

std::string FractionCalculator::operator()(int argc, const char **argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    Fraction fraction1;
    Fraction fraction2;
    char operation;

    try {
        fraction1 = parseFraction(argv[1]);
        operation = parseOperation(argv[2]);
        fraction2 = parseFraction(argv[3]);
    } catch (std::string str) {
        return str;
    }

    Fraction result;
    try {
        switch (operation) {
            case '+':
                result = fraction1 + fraction2;
                break;
            case '-':
                result = fraction1 - fraction2;
                break;
            case '*':
                result = fraction1 * fraction2;
                break;
            case '/':
                result = fraction1 / fraction2;
                break;
        }
    } catch (std::string str) {
        return str;
    }

    std::ostringstream stream;
    stream << result.getNum() << "/" << result.getDenom();

    message_ = stream.str();

    return message_;
}

bool FractionCalculator::validateNumberOfArguments(int argc,
                                                   const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

void FractionCalculator::help(const char *appName, const char *message) {
    message_ =
        std::string(message) +
            "This is a fraction calculator application.\n\n" +
            "Arguments should be provided in the following format:\n" +

            " $ " + appName + " <frac1>" +
            " <operation> <frac2> \n" +

            "Where <operation> is one of '+', '-', '*', '/' " +
            "and where <frac*> is integer or pair of integer separated by '/'.";
}

Fraction parseFraction(std::string arg) {
    size_t separatorPos = arg.find('/');

    if (separatorPos == std::string::npos) {
        return Fraction(parseInt(arg), 1);
    }

    return Fraction(parseInt(arg.substr(0, separatorPos)),
                    parseInt(arg.substr(separatorPos + 1)));
}

int parseInt(std::string arg) {
    char *end;
    int value = static_cast<int>(strtol(arg.c_str(), &end, 10));

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
