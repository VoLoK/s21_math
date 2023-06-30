#include "s21_math.h"

long double s21_sqrt(double x) {
    if (s21_IS_NAN(x) || x == s21_INF_NEG || x < 0) return s21_NAN;
        if (x == s21_INF_POS || x == 0) return (long double)x;
        return s21_pow(x, 0.5);
}
