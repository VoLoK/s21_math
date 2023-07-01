#include <math.h>

#include "s21_math.h"

long double s21_sin(double x) {
  long double res = s21_NAN;
  if (x == 0.0) {
    res = 0.0;
  } else if (x == s21_INF_POS || x == s21_INF_NEG) {
    res = s21_NAN;
  } else {
    res = 0.0;
    while (x > s21_PI) {
      x -= 2 * s21_PI;
    }
    while (x < -s21_PI) {
      x += 2 * s21_PI;
    }
    long double x_copy = x;
    for (int n = 1; n <= 16; ++n) {
      res += x_copy;
      x_copy *= (-1) * s21_pow(x, 2) / ((2 * n) * (2 * n + 1));
    }
  }
  return res;
}
