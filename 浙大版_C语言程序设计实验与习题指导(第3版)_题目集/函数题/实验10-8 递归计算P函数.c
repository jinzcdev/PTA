// https://pintia.cn/problem-sets/13/problems/582
double P(int n, double x) {
    if (n == 0) return 1;
    if (n == 1) return x;
    return ((2 * n - 1) * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
}
