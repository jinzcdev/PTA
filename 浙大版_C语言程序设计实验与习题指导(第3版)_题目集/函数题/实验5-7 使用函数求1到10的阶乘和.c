// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=465
double fact( int n ) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}