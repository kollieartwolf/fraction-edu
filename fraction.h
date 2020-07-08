#ifndef FRACTION_H
#define FRACTION_H

#include <cassert>
#include <fstream>

class Fraction {
public:
  Fraction(long long numerator = 0, long long denominator = 1);
  Fraction(const Fraction &frac);
  friend std::ostream &operator<<(std::ostream &out, const Fraction &frac);
  friend std::istream &operator>>(std::istream &in, Fraction &frac);
  friend Fraction operator+(const Fraction &f1, const Fraction &f2);
  friend Fraction operator+(const Fraction &f1, int value);
  friend Fraction operator+(int value, const Fraction &f1);
  friend Fraction operator-(const Fraction &f1, const Fraction &f2);
  friend Fraction operator-(const Fraction &f1, int value);
  friend Fraction operator-(int value, const Fraction &f1);
  friend Fraction operator*(const Fraction &f1, const Fraction &f2);
  friend Fraction operator*(const Fraction &f1, int value);
  friend Fraction operator*(int value, const Fraction &f1);
  friend Fraction operator/(const Fraction &f1, const Fraction &f2);
  friend Fraction operator/(const Fraction &f1, int value);
  friend Fraction operator/(int value, const Fraction &f1);
  friend bool operator==(const Fraction &f1, const Fraction &f2);
  friend bool operator!=(const Fraction &f1, const Fraction &f2);
  friend bool operator>(const Fraction &f1, const Fraction &f2);
  friend bool operator<=(const Fraction &f1, const Fraction &f2);
  friend bool operator<(const Fraction &f1, const Fraction &f2);
  friend bool operator>=(const Fraction &f1, const Fraction &f2);
  Fraction &operator=(const Fraction &frac);
  Fraction &operator=(int value);
  operator float();
  operator double();

private:
  long long _numerator = 0;
  long long _denominator = 1;
  static int nod(long long a, long long b);
  void reduce();
};

#endif // FRACTION_H
