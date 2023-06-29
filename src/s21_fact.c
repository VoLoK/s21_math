int s21_fact(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return s21_fact(n - 1) * n;
    }
}
