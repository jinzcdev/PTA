// https://pintia.cn/problem-sets/12/problems/311
int dp[10010] = {0};
int fib(int n) {
    if (dp[n] != 0) return dp[n];
    if (n == 1 || n == 2) return 1;
    dp[n - 1] = fib(n - 1);
    dp[n - 2] = fib(n - 2);
    return dp[n - 1] + dp[n - 2];
}
void PrintFN(int m, int n) {
    int temp, cnt = 0;
    for (int i = 1; i <= 20; i++) {
        int temp = fib(i);
        if (temp >= m && temp <= n) {
            if (cnt++ != 0) printf(" ");
            printf("%d", temp);
        }
    }
    if (!cnt) printf("No Fibonacci number\n");
}