#include "s21_tests.h"

START_TEST(simple_test) {
  double x = 55.0;
  double y = 2.0;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(big_num) {
  double x = 55.00000006;
  double y = 256.00789;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(negative_num) {
  double x = 55.0;
  double y = -2.0;

  ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

Suite* suite_fmod() {
  Suite* suite = suite_create("fmod_suite");
  TCase* tcase_core = tcase_create("fmod_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, negative_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
