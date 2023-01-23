// https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> e[N];
bool vis[N] = {false};
void dfs(int u) {
    vis[u] = true;
    for (auto it : e[u])
        if (!vis[it]) dfs(it);
}
int main() {
    int n, m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    while (k--) {
        fill(vis, vis + N, false);
        scanf("%d", &a);
        vis[a] = true;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}