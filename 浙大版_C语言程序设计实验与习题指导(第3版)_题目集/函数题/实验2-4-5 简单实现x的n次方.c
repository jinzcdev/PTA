// https://pintia.cn/problem-sets/13/exam/problems/412
double mypow( double x, int n ) {
    if (n == 0) return 1;
    return x * mypow(x, n - 1);
}