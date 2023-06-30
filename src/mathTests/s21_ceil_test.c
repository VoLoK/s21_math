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
  double num = -2.0293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_5) {
  double num = -2.0293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_6) {
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(test_7) {
  ck_assert_double_nan(s21_ceil(s21_NAN));
  ck_assert_double_nan(ceil(s21_NAN));
}
END_TEST

//START_TEST(s21_ceil_test5) {
//  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
//}
//END_TEST
//
//START_TEST(s21_ceil_test6) {
//  ck_assert_double_eq_tol(s21_ceil(50), ceil(50), 0.000001);
//}
//END_TEST

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

  suite_add_tcase(suite, tcase_core);
  return suite;
}
