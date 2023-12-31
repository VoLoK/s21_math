#include "s21_tests.h"

START_TEST(test_1) {
  double num = 0.82;
  ck_assert_double_eq_tol(s21_cos(num), cos(num), 0.000001);
}
END_TEST

START_TEST(test_2) {
  double num = s21_PI;
  ck_assert_double_eq_tol(s21_cos(num), cos(num), 0.000001);
}
END_TEST

START_TEST(test_3) {
  double num = -1;
  ck_assert_double_eq_tol(s21_cos(num), cos(num), 0.000001);
}
END_TEST

START_TEST(test_4) {
  double num = 1;
  ck_assert_double_eq_tol(s21_cos(num), cos(num), 0.000001);
}
END_TEST

START_TEST(test_5) {
  double num = 0;
  ck_assert_double_eq_tol(s21_cos(num), cos(num), 0.000001);
}
END_TEST

START_TEST(test_6) {
  double num = 12;
  ck_assert_double_eq_tol(s21_cos(num), cos(num), 0.000001);
}
END_TEST

START_TEST(test_7) {
  double num = -12;
  ck_assert_double_eq_tol(s21_cos(num), cos(num), 0.000001);
}
END_TEST

START_TEST(test_8) {
  float num = s21_INF_POS;
  ck_assert_double_nan(s21_cos(num));
}
END_TEST

START_TEST(test_9) {
  float num = s21_INF_NEG;
  ck_assert_double_nan(s21_cos(num));
}
END_TEST

START_TEST(test_10) {
  float num = s21_NAN;
  ck_assert_double_nan(s21_cos(num));
}
END_TEST

Suite* suite_cos() {
  Suite* suite = suite_create("cos_suite");
  TCase* tcase_core = tcase_create("cos_tc");

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

  suite_add_tcase(suite, tcase_core);
  return suite;
}
