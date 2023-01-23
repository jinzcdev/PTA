// https://pintia.cn/problem-sets/12/problems/350
int sum( int n ) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return n + sum(n - 1);
}