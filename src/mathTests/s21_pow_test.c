#include "s21_tests.h"

START_TEST(simple_test) {
  double base = 0.5;
  double exp = 2.0;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(big_num) {
  double base = 0.00000008;
  double exp = 5.00000008;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(negative_exp) {
  double base = 0.234;
  double exp = -7.5;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(negative_base) {
  double base = -2.0;
  double exp = 10.0;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

START_TEST(zero) {
  double base = 0;
  double exp = 2.5;

  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 0.000001);
}
END_TEST

Suite* suite_pow() {
  Suite* suite = suite_create("pow_suite");
  TCase* tcase_core = tcase_create("pow_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, negative_exp);
  tcase_add_test(tcase_core, negative_base);
  tcase_add_test(tcase_core, zero);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
