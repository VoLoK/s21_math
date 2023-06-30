#ifndef SRC_S21_TESTS_H_
#define SRC_S21_TESTS_H_

#include <check.h>
#include <math.h>

#include "s21_math.h"

Suite *suite_abs(void);
Suite *suite_acos(void);
//Suite *suite_memcmp(void);
//Suite *suite_memcpy(void);
//Suite *suite_strchr(void);
//Suite *suite_strerror(void);
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