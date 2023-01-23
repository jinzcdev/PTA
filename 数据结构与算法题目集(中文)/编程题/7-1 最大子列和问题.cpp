// https://pintia.cn/problem-sets/15/problems/709
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans;
    cin >> n;
    vector<int> v(n), dp(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    ans = dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}