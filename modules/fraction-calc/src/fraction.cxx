// Copyright 2016 Muminov Ruslan, Kursakov Evgeny

#include "include/fraction.h"

#include <cstdlib>
#include <string>
#include <stdexcept>

Fraction::Fraction() : numerator_(0), denominator_(1) { }

Fraction::Fraction(const int numerator, const int denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Can't divide by zero");
    numerator_ = numerator;
    denominator_ = denominator;
    this->reduction();
}

Fraction::Fraction(const Fraction &z)
    : numerator_(z.getNum()), denominator_(z.getDenom()) { }

Fraction &Fraction::operator=(const Fraction &z) {
    numerator_ = z.getNum();
    denominator_ = z.getDenom();
    return *this;
}

int Fraction::getNum() const {
    return numerator_;
}

int Fraction::getDenom() const {
    return denominator_;
}

void Fraction::setNum(const int numerator) {
    numerator_ = numerator;
}

void Fraction::setDenom(const int denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Can't divide by zero");
    denominator_ = denominator;
}

Fraction Fraction::operator+(const Fraction &z) const {
    Fraction sum;

    sum.setNum(this->getNum() * z.getDenom() + z.getNum() * this->getDenom());
    sum.setDenom(this->getDenom() * z.getDenom());
    sum.reduction();

    return sum;
}

Fraction Fraction::operator-(const Fraction &z) const {
    Fraction difference;

    difference.setNum(this->getNum() * z.getDenom()
                          - z.getNum() * this->getDenom());
    difference.setDenom(this->getDenom() * z.getDenom());
    difference.reduction();

    return difference;
}

Fraction Fraction::operator*(const Fraction &z) const {
    Fraction multiplication;

    multiplication.setNum(this->getNum() * z.getNum());
    multiplication.setDenom(this->getDenom() * z.getDenom());
    multiplication.reduction();

    return multiplication;
}

Fraction Fraction::operator/(const Fraction &z) const {
    Fraction division;

    if (equalsZero(z))
        throw std::invalid_argument("Can't divide by zero");
    division.setNum(this->getNum() * z.getDenom());
    division.setDenom(this->getDenom() * z.getNum());
    division.reduction();

    return division;
}

bool Fraction::operator==(const Fraction &z) const {
    return equalsZero(*this - z);
}

bool Fraction::operator!=(const Fraction &z) const {
    return !(*this == z);
}

bool Fraction::equalsZero(const Fraction &z) const {
    return z.getNum() == 0;
}

int Fraction::NOD() const {
    int num = std::abs(this->getNum());
    if (num == 0)
        return 1;
    int denom = this->getDenom();
    while (num != denom)
        if (num > denom) {
            num -= denom;
        } else {
            denom -= num;
        }
    return num;
}

void Fraction::reduction() {
    if (getDenom() < 0) {
        this->setNum(-this->getNum());
        this->setDenom(-this->getDenom());
    }

    int nod = this->NOD();
    this->setNum(this->getNum() / nod);
    this->setDenom(this->getDenom() / nod);
}
