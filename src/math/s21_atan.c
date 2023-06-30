#include "s21_math.h"

long double s21_atan(double x) {
    int is_valid = (x > -1 && x < 1);
    long double res = 0;
    if (x == s21_INF_POS) {
        res = s21_PI / 2;
    } else if (x == s21_INF_NEG) {
        res = -s21_PI / 2.0;
    } else if (x == 1) {
        res = s21_PI / 4.0;
    } else if (x == -1) {
        res = -s21_PI / 4.0;
    }
    res = is_valid ? x : 1.0 / x;
    for (int i = 1; i < 7000; i++) {
        double chisl = s21_pow(-1, i) * s21_pow(x, (1 + 2 * i) * (is_valid ? 1 : -1));
        double znam = 1 + 2 * i;
        res += chisl / znam;
    }
    if (!is_valid) res = (s21_PI * s21_fabs(x) / (2 * x)) - res;
    return res;
}
