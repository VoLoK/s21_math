#include "s21_math.h"

long double s21_ceil(double x) {
    long double res = 0;
    if (x == s21_NAN) {
        res = s21_NAN;
    } else if (x < 0) {
        res = (int)-x;
        res = -res;
    } else {
        res = (int)x;
        res += 1;
    }
    return res;
}
