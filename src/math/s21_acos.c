#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0;
  if (x < -1 || x > 1) {
    res = s21_NAN;
  } else if (x == 1) {
    res = 0;
  } else if (x == -1) {
    res = s21_PI;
  } else if (x < 1 && x >= 0) {
    res = s21_atan(s21_sqrt(1.0 - s21_pow(x, 2)) / x);
  } else if (x < 0 && x > -1) {
    res = s21_PI + s21_atan(s21_sqrt(1.0 - s21_pow(x, 2)) / x);
  }
  return res;
}
