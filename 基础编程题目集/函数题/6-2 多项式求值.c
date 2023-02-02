// https://pintia.cn/problem-sets/14/exam/problems/734
/*
double f( int n, double a[], double x ) {
    double ans = 0;
    int i = 0;
    for ( ; i <= n; i++) {
        double temp = 1.0;
        int j = 0;
        for ( ; j < i; j++) {
            temp *= x;
        }
        ans += a[i] * temp;
    }
    return ans;
}*/
double f( int n, double a[], double x ) {
    double ans = a[n];
    for (int i = n - 1; i >= 0; i--) {
        ans = ans * x + a[i];
    }
    return ans;
}
// double f( int n, double a[], double x ) {
//     if (n == 0) return a[0];
//     return f(n - 1, a, x*x) + a[n];
// }