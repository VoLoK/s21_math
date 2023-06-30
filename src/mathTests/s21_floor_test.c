#include "s21_tests.h"

START_TEST(simple_test) {
    double x = 100.0;

    ck_assert_double_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(big_num) {
    double x = 8.00000008;

    ck_assert_double_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(negative_num) {
    double x = -5.02;

    ck_assert_double_eq(s21_floor(x), floor(x));
}
END_TEST


Suite* suite_floor() {
  Suite* suite = suite_create("floor_suite");
  TCase* tcase_core = tcase_create("floor_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, negative_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}


