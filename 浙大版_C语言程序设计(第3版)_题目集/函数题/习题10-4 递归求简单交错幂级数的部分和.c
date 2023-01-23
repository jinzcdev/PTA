// https://pintia.cn/problem-sets/12/problems/354
double fn( double x, int n ) {
    if (n == 1) return x;
    return fn(x, n - 1) + (n % 2 != 0 ? pow(x, n) : -pow(x, n));
}