// Copyright 2016 Muminov_Ruslan

#ifndef MODULES_FRACTION_CALC_INCLUDE_FRACTION_H_
#define MODULES_FRACTION_CALC_INCLUDE_FRACTION_H_

class Fraction {
 public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(const Fraction& z);

    Fraction& operator=(const Fraction& z);

    int getNum() const;
    int getDenom() const;
    void setNum(int numerator);
    void setDenom(int denominator);

    Fraction operator + (const Fraction& z) const;
    Fraction operator - (const Fraction& z) const;
    Fraction operator * (const Fraction& z) const;
    Fraction operator / (const Fraction& z) const;

    bool operator == (const Fraction& z) const;
    bool operator != (const Fraction& z) const;

 private:
    bool equalsZero(const Fraction& z) const;
    int NOD() const;
    void reduction();
    int numerator_;
    int denominator_;
};

#endif  // MODULES_FRACTION_CALC_INCLUDE_FRACTION_H_
