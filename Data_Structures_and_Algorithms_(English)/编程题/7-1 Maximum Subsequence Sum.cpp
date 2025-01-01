// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=663
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans, left = 0, right = 0;
    scanf("%d", &n);
    vector<int> v(n), dp(n, 0), idx(n, 0);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    ans = dp[0] = v[0];
    idx[0] = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > dp[i - 1] + v[i]) {
            idx[i] = i;
        } else {
            idx[i] = idx[i - 1];
        }
        dp[i] = max(v[i], dp[i - 1] + v[i]);
        if (dp[i] > ans) {
            ans = dp[i];
            left = idx[i];
            right = i;
        }
    }
    if (ans < 0) printf("0 %d %d\n", v[0], v[n - 1]);
    else printf("%d %d %d\n", ans, v[left], v[right]);
    return 0;
}