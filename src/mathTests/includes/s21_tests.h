#ifndef SRC_S21_MATH_TESTS_H_
#define SRC_S21_MATH_TESTS_H_

#include <check.h>
#include <math.h>
#include <time.h>

#include "s21_math.h"

Suite *suite_abs(void);
Suite *suite_acos(void);
Suite *suite_asin(void);
Suite *suite_exp(void);
Suite *suite_sqrt(void);
Suite *suite_fabs(void);
Suite *suite_floor(void);
Suite *suite_log(void);
Suite *suite_pow(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif
