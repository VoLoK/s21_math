#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 0.0;
  if (x == s21_PI) {
    res = -1;
  } else if (x == 0) {
    res = 1;
  } else if (x == s21_INF_POS || x == s21_INF_NEG) {
    res = s21_NAN;
  } else {
    res = s21_sqrt(1 - s21_pow(s21_sin(x), 2));
  }
  return res;
}
