// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805349851185152
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m, u, v;
vector<int> g[N];
bool vis[N] = {false};
void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if (!vis[g[u][i]]) {
            dfs(g[u][i]);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int even = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", g[i].size());
        if (g[i].size() % 2 == 0) even++;
    }
    if (even == n && cnt == 1) printf("\nEulerian");
    else if (even == n - 2 && cnt == 1) printf("\nSemi-Eulerian");
    else printf("\nNon-Eulerian");
    return 0;
}