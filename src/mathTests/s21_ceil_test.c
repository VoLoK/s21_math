#include "s21_tests.h"

START_TEST(test_1) {
  double num = 2.0293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_2) {
  double num = -2.0293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_3) {
  double num = 0.8293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_4) {
  double num = s21_INF_POS;
  ck_assert_double_eq(s21_ceil(num), ceil(num));
}
END_TEST

START_TEST(test_5) {
  double num = s21_INF_NEG;
  ck_assert_double_eq(s21_ceil(num), ceil(num));
}
END_TEST

START_TEST(test_6) {
  double num = s21_NAN;
  ck_assert_double_nan(s21_ceil(num));
}
END_TEST

START_TEST(test_7) {
  float num = s21_NAN;
  ck_assert_double_nan(s21_ceil(num));
}
END_TEST

START_TEST(test_8) {
  long double num = s21_NAN;
  ck_assert_double_nan(s21_ceil(num));
}
END_TEST

START_TEST(test_9) {
  double num = -0.8293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_10) {
  double num = -INT_MAX;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_11) {
  double num = INT_MAX;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_12) {
  double num = LONG_MAX;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_13) {
  double num = -LONG_MAX;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_14) {
  double num = 5.000000000000001;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

Suite* suite_ceil() {
  Suite* suite = suite_create("ceil_suite");
  TCase* tcase_core = tcase_create("ceil_tc");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  tcase_add_test(tcase_core, test_9);
  tcase_add_test(tcase_core, test_10);
  tcase_add_test(tcase_core, test_11);
  tcase_add_test(tcase_core, test_12);
  tcase_add_test(tcase_core, test_13);
  tcase_add_test(tcase_core, test_14);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
