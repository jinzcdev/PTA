// https://pintia.cn/problem-sets/12/exam/problems/298
int sum( int m, int n ) {
    if (m == n) return m;
    return m + sum(m + 1, n);
}