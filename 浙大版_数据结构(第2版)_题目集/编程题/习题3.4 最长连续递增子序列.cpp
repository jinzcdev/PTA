// https://pintia.cn/problem-sets/434/problems/5860
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, begin, MAX = 1;
    cin >> n;
    vector<int> a(n), dp(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = a[i] > a[i - 1] ? dp[i - 1] + 1 : 1;
        if (dp[i] > MAX) {
            MAX = dp[i];
            begin = i - MAX + 1;
        }
    }
    for (int i = 0; i < MAX; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[begin + i]);
    }
    return 0;
}