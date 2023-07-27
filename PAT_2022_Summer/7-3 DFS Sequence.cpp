// 该代码测试点 2 未通过
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> e(n + 1, vector<int>(n + 1));
    int a, b;
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a][b] = 1;
    }
    while (k--) {
        unordered_set<int> sset;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
            sset.insert(v[i]);
        }
        if (sset.size() != n) {
            printf("no\n");
            continue;
        }
        vector<bool> vis(n + 1);
        vis[v[1]] = true;
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (e[v[i]][v[i + 1]] == 1) {
                vis[v[i + 1]] = true;
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (e[v[i]][j] == 1 && !vis[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            vis[v[i + 1]] = true;
        }
        printf("%s\n", flag ? "yes" : "no");
    }
    return 0;
}