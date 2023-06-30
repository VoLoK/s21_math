#include "s21_tests.h"

START_TEST(test_1) {
  int num = 0.321;
  ck_assert_double_eq_tol(s21_atan(num), atan(num), 0.000001);
}
END_TEST

START_TEST(test_2) {
    int num = -0.93;
    ck_assert_double_eq_tol(s21_atan(num), atan(num), 0.000001);
}
END_TEST

START_TEST(test_3) {
    int num = -1;
    ck_assert_double_eq_tol(s21_atan(num), atan(num), 0.000001);
}
END_TEST

START_TEST(test_4) {
    int num = 1;
    ck_assert_double_eq_tol(s21_atan(num), atan(num), 0.000001);
}
END_TEST

START_TEST(test_5) {
    int num = 0;
    ck_assert_double_eq_tol(s21_atan(num), atan(num), 0.000001);
}
END_TEST

START_TEST(test_6) {
    int num = 16.13;
    ck_assert_double_eq_tol(s21_atan(num), atan(num), 0.000001);
}
END_TEST

START_TEST(test_7) {
    int num = 16.13;
    ck_assert_double_eq_tol(s21_atan(num), atan(num), 0.000001);
}
END_TEST

START_TEST(test_8) {
    float num = INFINITY;
    ck_assert_double_eq(s21_atan(num), atan(num));
}
END_TEST

START_TEST(test_9) {
    float num = -INFINITY;
    ck_assert_double_eq(s21_atan(num), atan(num));
}
END_TEST

START_TEST(test_10) {
    ck_assert_double_nan(s21_atan(NAN));
}
END_TEST



Suite* suite_atan() {
  Suite* suite = suite_create("atan_suite");
  TCase* tcase_core = tcase_create("atan_tc");

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



