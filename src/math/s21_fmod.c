#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int is_value = 1;
  long double res = 0;
  float res_not_value;
  double final_quotient = 0;

  if (s21_isinf(x)) {
    is_value = 0;
    res_not_value = s21_NAN;
  }

  if (s21_isnan(x)) {
    is_value = 0;
    res_not_value = s21_NAN;
  }

  if (y < 0) {
    y = fabs(y);
  }

  double quotient = x / y;

  final_quotient = x < 0.0 ? s21_ceil(quotient) : s21_floor(quotient);

  res = (long double)x - (final_quotient * (long double)y);

  if (y == s21_INF_POS || y == s21_INF_NEG) {
    res = x;
  }

  if (res == 0.0 && x < 0.0) {
    res = -0.0;
  }

  return (is_value) ? res : res_not_value;
}