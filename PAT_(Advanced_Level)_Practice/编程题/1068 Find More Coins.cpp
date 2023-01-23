// https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010, maxv = 110;
bool cmp(int a, int b) { return a > b; }
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> coin(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &coin[i]);
    sort(coin.begin() + 1, coin.end(), cmp);
    int dp[maxn] = {0};
    bool choice[maxn][maxv] = {false};
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= coin[i]; j--) {
            if (dp[j - coin[i]] + coin[i] >= dp[j]) {
                dp[j] = dp[j - coin[i]] + coin[i];
                choice[i][j] = true;
            }
        }
    }
    if (dp[m] != m) printf("No Solution\n");
    else {
        vector<int> ans;
        int v = m, pos = n;
        while (v > 0) {
            if (choice[pos][v]) {
                v -= coin[pos];
                ans.push_back(coin[pos]);
            }
            pos--;
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", ans[i]);
        }
    }
    return 0;
}