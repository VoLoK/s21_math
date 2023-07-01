#include "s21_tests.h"

START_TEST(simple_test) {
  double x = 5.0;

  ck_assert_double_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(big_num) {
  double x = 5.00000008;

  ck_assert_double_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(negative_num) {
  double x = -5.0;

  ck_assert_double_nan(s21_log(x));
}
END_TEST

Suite* suite_log() {
  Suite* suite = suite_create("log_suite");
  TCase* tcase_core = tcase_create("log_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, negative_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
