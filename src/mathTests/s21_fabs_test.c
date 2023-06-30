#include "s21_tests.h"

START_TEST(simple_test) {
  double x = 25.0; 

  ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(big_num) {
    double x = 919188939128; 

    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(big_double_num) {
    double x = 0.00000008; 

    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(negative_num) {
    double x = -100.05; 

    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST


Suite* suite_fabs() {
  Suite* suite = suite_create("fabs_suite");
  TCase* tcase_core = tcase_create("fabs_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, big_double_num);
  tcase_add_test(tcase_core, negative_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}


