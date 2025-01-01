// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=582
double P(int n, double x) {
    if (n == 0) return 1;
    if (n == 1) return x;
    return ((2 * n - 1) * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
}
