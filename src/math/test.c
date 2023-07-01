#include "includes/s21_math.h"
#include <stdio.h>
#include <math.h>

long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double s21_log(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
int s21_fact(int n);

int main () {

    //    //double x = 1000000.0003;         //sqrt
//    double x = -234423.3242;
//     printf("%Lf\n", s21_sqrt(x));
// 	printf("%f", sqrt(x));

//    //double x = 1000000.0003;         //sqrt
//    double x = -234423.3242;
//     printf("%Lf\n", s21_sqrt(x));
// 	printf("%f", sqrt(x));
   
    double base = -55.0;              //pow
    double exp = -2.0;
    printf("%Lf \n", s21_pow(base, exp));
	printf("%f", pow(base, exp));

	// double x = 919188939128;        //fabs
    // printf("%Lf\n", s21_fabs(x));
	// printf("%f", fabs(x));

    // double x = 0.5;        //exp
    // printf("%Lf\n", s21_exp(x));
	// printf("%f", exp(x));

    // double x = 5.00000008;        //log
    // printf("%Lf\n", s21_log(x));
	// printf("%f", log(x));

    // double x = 1000.0;        //floor
    // printf("%Lf\n", s21_floor(x));
	// printf("%f", floor(x));

    // double x = 1000000.0003;         //fmod
    // double y = -234423.3242;
    // printf("%Lf\n", s21_fmod(x, y));
	// printf("%f", fmod(x, y));
}

long double s21_floor(double x) {
    return (x == (long int)x) ? x :
    (x > 0) ? (long double)(((long int)x)) :
    (x < 0) ? (long double)((long int)x) - 1 : 0;
}

long double s21_fabs(double x) {
//   double res;
//   if (x > 0) {
//     res = x;
//   } else {
//     res = x * -1.0;
//   }
//   return res;

  return (x > 0) ? x : -x;
}

long double s21_exp(double x) {
    long double rez = 1, y = 1;
    long double i = 1;
    int flag = 0;
    if (x < 0) {
        x *= -1;
        flag = 1;
    }
    while (s21_fabs(rez) > s21_EPS) {
    rez *= x / i;
        i++;
        y += rez;
        if (y > s21_MAX_double) {
            y = s21_INF_POS;
            break;
        }
    }
    y = flag == 1 ? y > s21_MAX_double ? 0 : 1. / y : y;
    return y = y > s21_MAX_double ? s21_INF_POS : y;
}

long double s21_log(double x) {
    long double sign = 1, pow = 0, count = 2, result, temp;
    if (x < 0) {
        x = x * -1;
        sign = sign * -1;
    } else {
        x = x * 1;
        sign = sign * 1;
    }
    while ((x >= 10) || (x < 1 && x > 0)) {
        if (x < 1 && x > 0) {
            x = x * 10;
            pow = pow - 1;
        } else {
            x = x * 0.1;
            pow = pow + 1;
        }
    }
    x = sign * x / 10;
    if (x < 0) {
        result = -s21_NAN;
    } else if (x == 0) {
        result = -s21_INF_POS;
    } else {
        x--;
        result = x;
        temp = x;
        while (s21_fabs(result) > s21_EPS) {
            result = result * -x * (count - 1) / count;
            count = count + 1;
            temp = temp + result;
        }
        result = temp + (pow + 1) * S21_LN10;
    }
    return (x == 1) ? 0 : result;
}

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

long double s21_sqrt(double x) {
    if (s21_IS_NAN(x) || x == s21_INF_NEG || x < 0) return s21_NAN;
    if (x == s21_INF_POS || x == 0) return (long double)x;
    return s21_pow(x, 0.5);

}

long double s21_fmod(double x, double y) {
  int is_value = 1;
  long double res = 0;
  float res_not_value;
  double final_quotient = 0;

  if (s21_sin(x)) {
    is_value = 0;
    res_not_value = s21_NAN;
  }

  if (s21_tan(x)) {
    is_value = 0;
    res_not_value = s21_NAN;
  }

  if (y < 0) {
    y = fabs(y);
  }

  double quotient = x / y;

  final_quotient = x < 0.0 ? s21_ceil(quotient) : s21_floor(quotient);

  res = (long double)x - (final_quotient * (long double)y);

  if (y == s21_INF_POS || y == s21_INF_NEG) {
    res = x;
  }

  if (res == 0.0 && x < 0.0) {
    res = -0.0;
  }

  return (is_value) ? res : res_not_value;
}

long double s21_sin(double x) {
    long double res = 0;
    x = fmod(x, 2 * s21_PI);
    for (int i = 0; i < 6; i++) {
        res += (s21_pow(-1, i) * s21_pow(x, 2 * i + 1)) / (s21_fact(2 * i + 1));
    }
    return res;
}

long double s21_tan(double x) {
    return s21_sin(x) / s21_cos(x);
}

long double s21_ceil(double x) {
    long double res = 0;
    if (x < 0) {
        res = (int)-x;
        res = -res;
    } else {
        res = (int)x;
        res += 1;
    }
    return res;
}

long double s21_cos(double x) {
    return s21_sqrt(1 - s21_pow(s21_sin(x),2));
}

int s21_fact(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return s21_fact(n - 1) * n;
    }
}
