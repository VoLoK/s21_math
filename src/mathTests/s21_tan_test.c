#include "s21_tests.h"

START_TEST(test_1) {
  double num = 0.82;
  ck_assert_double_eq_tol(s21_tan(num), tan(num), 0.000001);
}
END_TEST

START_TEST(test_2) {
  double num = -0.23;
  ck_assert_double_eq_tol(s21_tan(num), tan(num), 0.000001);
}
END_TEST

START_TEST(test_4) {
  double num = s21_PI;
  ck_assert_double_eq_tol(s21_tan(num), tan(num), 0.000001);
}
END_TEST

START_TEST(test_5) {
  double num = 0;
  ck_assert_double_eq_tol(s21_tan(num), tan(num), 0.000001);
}
END_TEST

START_TEST(test_6) {
  double num = 12.287;
  ck_assert_double_eq_tol(s21_tan(num), tan(num), 0.000001);
}
END_TEST

START_TEST(test_7) {
  double num = -12.976;
  ck_assert_double_eq_tol(s21_tan(num), tan(num), 0.000001);
}
END_TEST

START_TEST(test_8) {
  float num = INFINITY;
  ck_assert_double_nan(s21_tan(num));
}
END_TEST

START_TEST(test_9) {
  float num = -INFINITY;
  ck_assert_double_nan(s21_tan(num));
}
END_TEST

Suite* suite_tan() {
  Suite* suite = suite_create("tan_suite");
  TCase* tcase_core = tcase_create("tan_tc");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  tcase_add_test(tcase_core, test_9);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
