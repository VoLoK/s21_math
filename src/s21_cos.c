#include "s21_math.h"

long double s21_cos(double x) {
    return sqrt(1 - pow(s21_sin(x),2));
}
