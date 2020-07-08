#include "fraction.h"

Fraction::Fraction(long long numerator, long long denominator) {
  assert(denominator != 0);
  if (denominator < 0) {
    numerator *= -1;
    denominator *= -1;
  }
  _numerator = numerator;
  _denominator = denominator;
  reduce(); /*!< Для упрощения дроби. */
}

Fraction::Fraction(const Fraction &frac)
    : _numerator(frac._numerator), _denominator(frac._denominator) {}

std::ostream &operator<<(std::ostream &out, const Fraction &frac) {
  out << frac._numerator;
  if (frac._denominator != 1)
    out << "/" << frac._denominator;
  return out;
}

std::istream &operator>>(std::istream &in, Fraction &frac) {
  in >> frac._numerator;
  in >> frac._denominator;
  return in;
}

int Fraction::nod(long long a, long long b) {
  return b == 0 ? a : nod(b, a % b);
}

void Fraction::reduce() {
  int nod = Fraction::nod(_numerator, _denominator);
  _numerator /= nod;
  _denominator /= nod;
}

Fraction operator+(const Fraction &f1, const Fraction &f2) {
  return Fraction(f1._numerator * f2._denominator +
                      f2._numerator * f1._denominator,
                  f1._denominator * f2._denominator);
}

Fraction operator+(const Fraction &f1, int value) {
  return Fraction(f1._numerator + value * f1._denominator, f1._denominator);
}

Fraction operator+(int value, const Fraction &f1) {
  return Fraction(f1._numerator * value * f1._denominator, f1._denominator);
}

Fraction operator-(const Fraction &f1, const Fraction &f2) {
  return Fraction(f1._numerator * f2._denominator -
                      f2._numerator * f1._denominator,
                  f1._denominator * f2._denominator);
}

Fraction operator-(const Fraction &f1, int value) {
  return Fraction(f1._numerator - value * f1._denominator, f1._denominator);
}

Fraction operator-(int value, const Fraction &f1) {
  return Fraction(f1._numerator - value * f1._denominator, f1._denominator);
}

Fraction operator*(const Fraction &f1, const Fraction &f2) {
  return Fraction(f1._numerator * f2._numerator,
                  f1._denominator * f2._denominator);
}

Fraction operator*(const Fraction &f1, int value) {
  return Fraction(f1._numerator * value, f1._denominator);
}

Fraction operator*(int value, const Fraction &f1) {
  return Fraction(f1._numerator * value, f1._denominator);
}

Fraction operator/(const Fraction &f1, const Fraction &f2) {
  return Fraction(f1._numerator * f2._denominator,
                  f1._denominator * f2._numerator);
}

Fraction operator/(const Fraction &f1, int value) {
  return Fraction(f1._numerator, f1._denominator * value);
}

Fraction operator/(int value, const Fraction &f1) {
  return Fraction(value * f1._denominator, f1._numerator);
}

bool operator==(const Fraction &f1, const Fraction &f2) {
  return (f1._numerator == f2._numerator && f1._denominator == f2._denominator);
}

bool operator!=(const Fraction &f1, const Fraction &f2) { return !(f1 == f2); }

bool operator>(const Fraction &f1, const Fraction &f2) {
  return f1._numerator * f2._denominator > f1._denominator * f2._numerator;
}

bool operator>=(const Fraction &f1, const Fraction &f2) {
  return f1._numerator * f2._denominator >= f1._denominator * f2._numerator;
}

bool operator<(const Fraction &f1, const Fraction &f2) {
  return f1._numerator * f2._denominator < f1._denominator * f2._numerator;
}

bool operator<=(const Fraction &f1, const Fraction &f2) {
  return f1._numerator * f2._denominator <= f1._denominator * f2._numerator;
}

Fraction &Fraction::operator=(const Fraction &frac) {
  if (this == &frac)
    return *this;
  _numerator = frac._numerator;
  _denominator = frac._denominator;
  return *this;
}

Fraction &Fraction::operator=(int value) {
  _numerator = value;
  _denominator = 1;
  return *this;
}

Fraction::operator float() { return float(_numerator) / float(_denominator); }

Fraction::operator double() {
  return double(_numerator) / double(_denominator);
}
