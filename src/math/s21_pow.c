#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1, temp = base;
  if (exp == 0)
    result = 1;
  else if (s21_IS_NAN(base) && exp != 0)
    result = s21_NAN;
  else if (base == 1)
    result = 1;
  else if ((long int)exp == exp) {
    if (exp > 0)
      for (; exp >= 1; exp--) result *= base;
    else
      for (; exp <= -1; exp++) result /= base;
  } else {
    if (temp < 0) {
      temp = -temp;
      result = s21_exp(exp * s21_log(temp));
      if (s21_fmod(exp, 2) != 0) result = -result;
    } else
      result = s21_exp(exp * s21_log(base));
  }
  return result;
}
