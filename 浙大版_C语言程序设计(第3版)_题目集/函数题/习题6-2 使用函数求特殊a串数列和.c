// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=309
int fn( int a, int n ) {
    int sum = 0, i = 0;
    while (i++ < n) sum = sum * 10 + a;
    return sum;
}
int SumA( int a, int n ) {
    if (n == 1) return a;
    return fn(a, n) + SumA(a, n - 1);
}