#include "s21_tests.h"

START_TEST(simple_test) {
    double base = 0.5;              
    double exp = 2.0; 

    ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(big_num) {
    double base = 0.00000008;              
    double exp = 5.00000008; 

    ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(negative_num) {
    double base = 0.234;              
    double exp = -7.5; 

    ck_assert_double_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST


Suite* suite_pow() {
  Suite* suite = suite_create("pow_suite");
  TCase* tcase_core = tcase_create("pow_tc");

  tcase_add_test(tcase_core, simple_test);
  tcase_add_test(tcase_core, big_num);
  tcase_add_test(tcase_core, negative_num);

  suite_add_tcase(suite, tcase_core);
  return suite;
}


