// https://pintia.cn/problem-sets/13/problems/575
double fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}
double factsum(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fact(n) + factsum(n - 1);
}