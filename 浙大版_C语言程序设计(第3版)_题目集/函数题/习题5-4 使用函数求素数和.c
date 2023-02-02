// https://pintia.cn/problem-sets/12/exam/problems/304
int prime( int p ) {
    if (p <= 1) return 0;
    for (int i = 2; i * i <= p; i++)
        if (p % i == 0) return 0;
    return 1;
}
int PrimeSum( int m, int n ) {
    if (m == n) return prime(m) ? m : 0;
    return prime(m) ? m + PrimeSum(m + 1, n) : PrimeSum(m + 1, n);
}