#include "fraction.h"
#include <iostream>

int main() {
  Fraction f1(15, 6), f2(15, 3), f3(15, 15);
  std::cout << "f1: " << f1 << ", f2: " << f2 << ", f3: " << f3 << std::endl;
  std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
  std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
  std::cout << "f1 / f2 = " << f1 / f2 << std::endl;
  std::cout << "f2 / f1 = " << f2 / f1 << std::endl;
  std::cout << "f1 * 2 == f2 ? " << bool((f1 * 2) == f2) << std::endl;
  Fraction f4 = f2 * f3;
  std::cout << "f4 = f2 * f3 = " << f4 << std::endl;
  Fraction f5;
  int d = 1, m = 1;
  for (int i = 0; i < 20; i++) {
    f5 = f5 + Fraction(m, d);
    std::cout << "\tIteration " << i + 1 << ": " << f5 << " with " << m << "/"
              << d << std::endl;
    m *= -1;
    d += 2;
  }
  f5 = f5 * 4;
  std::cout << "Pi number (20 iterations): " << float(f5) << ", " << double(f5)
            << std::endl;
  std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
  std::cout << "f1 += f2 += 5: ";
  f1 += f2 += 5;
  std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
  std::cout << "f1 < 1 ? " << bool(f1 < 1) << std::endl;
  return 0;
}
