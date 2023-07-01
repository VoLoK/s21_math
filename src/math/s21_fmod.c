#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int is_value = 0;
  long double res = 0;
  float res_not_value = s21_NAN;
  double final_quotient = 0;

  if (x == s21_INF_POS || x == s21_INF_NEG) {
    is_value = 0;
    res_not_value = s21_NAN;
  } else {
    if (y < 0) {
      y = s21_fabs(y);
    }
    is_value = 1;
    res_not_value = 0.0;
    double quotient = x / y;
    final_quotient = x < 0.0 ? s21_ceil(quotient) : s21_floor(quotient);
    res = (long double)x - (final_quotient * (long double)y);
    if (y == s21_INF_POS || y == s21_INF_NEG) {
      res = x;
    }
    if (res == 0.0 && x < 0.0) {
      res = -0.0;
    }
  }
  return (is_value) ? res : res_not_value;
}