// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=463
int prime( int p ) {
    if (p <= 1) return 0;
    for (int i = 2; i * i <= p; i++)
        if (p % i == 0) return 0;
    return 1;
}
int PrimeSum( int m, int n ) {
    if (m == n) return prime(m) ? m : 0;
    return (prime(n) ? n : 0) + PrimeSum(m, n - 1);
}