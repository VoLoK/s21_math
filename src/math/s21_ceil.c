#include "s21_math.h"

long double s21_ceil(double x) {
    long double res = s21_NAN;
    if (x == s21_INF_POS) {
        res = s21_INF_POS;
    } else if (x == s21_INF_NEG) {
        res = s21_INF_NEG;
    } else if (x < 0) {
        res = (unsigned long int)-x;
        res = -res;
    } else if (x >= 0) {
        res = (unsigned long int)x;
        res = res == x ? x : res + 1;
    }
    return res;
}
