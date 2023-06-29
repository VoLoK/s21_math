#include "s21_math.h"

long double s21_floor(double x) {
    return (x == (long int)x) ? x :
    (x > 0) ? (long double)(((long int)x)) :
    (x < 0) ? (long double)((long int)x) - 1 : 0;
}