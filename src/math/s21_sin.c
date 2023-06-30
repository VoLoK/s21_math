#include "s21_math.h"
#include <math.h>

long double s21_sin(double x) {
    long double res = 0;
    x = fmod(x, 2 * s21_PI);
    for (int i = 0; i < 6; i++) {
        res += (s21_pow(-1, i) * s21_pow(x, 2 * i + 1)) / (s21_fact(2 * i + 1));
    }
    return res;
}
