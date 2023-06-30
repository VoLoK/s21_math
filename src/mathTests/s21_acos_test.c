#include "s21_tests.h"

START_TEST(test_1) {
  int num = 0.82;
  ck_assert_double_eq_tol(s21_acos(num), acos(num), 0.000001);
}
END_TEST

//START_TEST(test_2) {
//    int num = -0.23;
//    ck_assert_double_eq_tol(s21_acos(num), acos(num), 0.000001);
//}
//END_TEST
//
//START_TEST(test_3) {
//    int num = -1;
//    ck_assert_double_eq_tol(s21_acos(num), acos(num), 0.000001);
//}
//END_TEST
//
//START_TEST(test_4) {
//    int num = 1;
//    ck_assert_double_eq_tol(s21_acos(num), acos(num), 0.000001);
//}
//END_TEST
//
//START_TEST(test_5) {
//    int num = 0;
//    ck_assert_double_eq_tol(s21_acos(num), acos(num), 0.000001);
//}
//END_TEST
//
//START_TEST(test_6) {
//    int num = 12;
//    ck_assert_double_nan(s21_acos(num));
//}
//END_TEST
//
//START_TEST(test_7) {
//    int num = -12;
//    ck_assert_double_nan(s21_acos(num));
//}
//END_TEST
//
//START_TEST(test_8) {
//    float num = INFINITY;
//    ck_assert_double_nan(s21_acos(num));
//}
//END_TEST
//
//START_TEST(test_9) {
//    float num = -INFINITY;
//    ck_assert_double_nan(s21_acos(num));
//}
END_TEST



Suite* suite_acos() {
  Suite* suite = suite_create("acos_suite");
  TCase* tcase_core = tcase_create("acos_tc");

  tcase_add_test(tcase_core, test_1);
//  tcase_add_test(tcase_core, test_2);
//  tcase_add_test(tcase_core, test_3);
//  tcase_add_test(tcase_core, test_4);
//  tcase_add_test(tcase_core, test_5);
//  tcase_add_test(tcase_core, test_6);
//  tcase_add_test(tcase_core, test_7);
//  tcase_add_test(tcase_core, test_8);
//  tcase_add_test(tcase_core, test_9);

  suite_add_tcase(suite, tcase_core);
  return suite;
}


