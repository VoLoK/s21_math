#include "s21_math.h"

long double s21_cos(double x) {
    return s21_sqrt(1 - s21_pow(s21_sin(x),2));
}
