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
Suite *suite_atan(void);
Suite *suite_ceil(void);
//Suite *suite_strlen(void);
//Suite *suite_strncat(void);
//Suite *suite_strncmp(void);
//Suite *suite_strncpy(void);
//Suite *suite_strpbrk(void);
//Suite *suite_strrchr(void);
//Suite *suite_strstr(void);
//Suite *suite_strtok(void);
//Suite *suite_insert(void);
//Suite *suite_trim(void);
//Suite *suite_to_upper(void);
//Suite *suite_to_lower(void);
//Suite *suite_sprintf(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif
