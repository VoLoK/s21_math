#include "s21_tests.h"

START_TEST(simple_test) {
  int num = 1;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(simple_test2) {
  int num = 3;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(zero_num) {
  int num = 0;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

Suite* suite_fact() {
  Suite* suite = suite_create("fact_suite");
  TCase* tcase_core = tcase_create("fact_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, simple_test2);
  tcase_add_test(tcase_core, zero_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
