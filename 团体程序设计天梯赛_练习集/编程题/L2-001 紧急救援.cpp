// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805073643683840
#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m, st, dest, e[N][N], weight[N], d[N], cntPath = 0, maxNum = -1;
vector<int> pre[N], tempPath, path;
void dfs(int u) {
    tempPath.push_back(u);
    if (pre[u].size() == 0) {
        cntPath++;
        int tempNum = 0;
        for (auto it : tempPath) tempNum += weight[it];
        if (tempNum > maxNum) {
            maxNum = tempNum;
            path = tempPath;
        }
    }
    for (auto it : pre[u]) dfs(it);
    tempPath.pop_back();
}
void dijkstra(int s) {
    bool vis[N] = {false};
    fill(d, d + N, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && e[u][v] != INF) {
                if (d[u] + e[u][v] < d[v]) {
                    d[v] = d[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + e[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int main() {
    fill(e[0], e[0] + N * N, INF);
    int a, b, dist;
    scanf("%d%d%d%d", &n, &m, &st, &dest);
    for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &dist);
        e[a][b] = e[b][a] = dist;
    }
    dijkstra(st);
    dfs(dest);
    printf("%d %d\n", cntPath, maxNum);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i != 0) printf(" ");
    }
    return 0;
}