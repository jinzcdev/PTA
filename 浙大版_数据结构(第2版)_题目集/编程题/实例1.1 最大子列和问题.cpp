// https://pintia.cn/problem-sets/434/problems/5404
#include <cstdio>
const int N = 100010;
int main() {
    int n, dp[N] = {0}, a[N], MAX = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    MAX = dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] >= 0) dp[i] = dp[i - 1] + a[i];
        else dp[i] = a[i];
        if (dp[i] > MAX) MAX = dp[i];
    }
    printf("%d", MAX);
    return 0;
}