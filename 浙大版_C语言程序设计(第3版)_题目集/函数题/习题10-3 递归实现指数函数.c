// https://pintia.cn/problem-sets/12/problems/353
double calc_pow( double x, int n ) {
    if (n == 0) return 1;
    return x * calc_pow(x, n - 1);
}