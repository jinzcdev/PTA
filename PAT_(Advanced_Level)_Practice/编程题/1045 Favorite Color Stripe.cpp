// https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, l, temp, dp[10010], number[210];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &temp);
        number[temp] = i;
    }
    scanf("%d", &l);
    vector<int> a;
    for (int i = 0; i < l; i++) {
        scanf("%d", &temp);
        if (number[temp] != 0) a.push_back(temp);
    }
    int ans = -1;
    for (int i = 0; i < a.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (number[a[i]] >= number[a[j]] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}