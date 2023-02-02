// https://pintia.cn/problem-sets/12/exam/problems/356
int f( int n ) {
    if (n <= 1) return n;
    return f(n - 2) + f(n - 1);
}