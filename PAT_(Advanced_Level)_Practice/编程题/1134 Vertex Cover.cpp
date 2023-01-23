// https://pintia.cn/problem-sets/994805342720868352/problems/994805346428633088
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int edge[N][N] = {0};
int main() {
    int n, m, k, t, v, v1, v2, id = 1;
    scanf("%d%d", &n, &m);
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        edge[v1][v2] = edge[v2][v1] = id++;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &t);
        // fill(vis, vis + N, false);
        bool vis[N] = {false};
        int cnt = 0;
        for (int i = 0; i < t; i++) {
            scanf("%d", &v);
            for (int j = 0; j < g[v].size(); j++) {
                if (!vis[edge[v][g[v][j]]]) {
                    cnt++;
                    vis[edge[v][g[v][j]]] = true;
                }
            }
        }
        if (cnt == m)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}