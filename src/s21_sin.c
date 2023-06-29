//long double s21_sin(double x) {
//    if (x > 1 || x < -1) {
//        x = x * s21_PI / 180;
//    }
//    int base = 16;
//    long double res = 0;
//    long double chisl;
//    long double znam;
//    for (int n = 0; n < base; n++) {
//        chisl = pow(-1, n-1) * pow(x, 2 * n - 1);
//        znam = s21_fact(2 * n - 1);
//        res += chisl / znam;
//    }
//    return res;
//}

long double s21_sin(double x) {
    long double res = 0;
    x = s21_fmod(x, 2 * s21_PI);
    for (int i = 0; i < 6; i++) {
        res += (pow(-1, i) * pow(x, 2 * i + 1)) / (s21_fact(2 * i + 1));
    }
    return res;
}
