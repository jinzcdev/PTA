// https://pintia.cn/problem-sets/994805046380707840/problems/1518582000729911296
#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<int, int> mp;
    int n, k, s, a, b;
    scanf("%d%d%d", &n, &k, &s);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        if (a < 175) continue;
        if (b >= s) ans++;
        else mp[a]++;
    }
    for (auto &[i, j] : mp) ans += min(j, k);
    printf("%d", ans);
    return 0;
}