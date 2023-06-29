#include "s21_math.h"

long double s21_pow(double base, double exp) {
    long double result = 0;
        if (exp == 0) result = 1.0L;
            else if (exp > 0) result = s21_exp(exp * s21_log(base));
            else
            result = 1 / (s21_exp(-exp * s21_log(base)));
    
    return result;
}