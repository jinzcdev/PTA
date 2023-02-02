// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805343463260160
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, ans = 1;
    unordered_map<int, bool> vis;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        vis[x] = true;
    }
    while (vis[ans]) ans++;
    printf("%d", ans);
    return 0;
}