// https://pintia.cn/problem-sets/13/exam/problems/576
double calc_pow(double x, int n) {
    if (n == 0) return 1;
    return x * calc_pow(x, n - 1);
}