#include "s21_tests.h"

START_TEST(simple_test) {
  int num = 2;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(negative_num) {
    int num = -2;
    ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST


Suite* suite_abs() {
  Suite* suite = suite_create("abs_suite");
  TCase* tcase_core = tcase_create("abs_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, negative_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

