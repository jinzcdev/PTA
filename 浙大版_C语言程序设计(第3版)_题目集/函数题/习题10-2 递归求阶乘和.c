// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=352
double fact( int n ) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}
double factsum( int n ) {
    if (n <= 1) return n == 0 ? 0 : 1;
    return fact(n) + factsum(n - 1);
}