// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=354
double fn( double x, int n ) {
    if (n == 1) return x;
    return fn(x, n - 1) + (n % 2 != 0 ? pow(x, n) : -pow(x, n));
}