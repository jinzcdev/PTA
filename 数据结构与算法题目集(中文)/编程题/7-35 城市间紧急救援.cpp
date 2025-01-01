// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=862
#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = INT_MAX;
int n, m, st, dest, maxW = -1, cntPath = 0, d[N], w[N], e[N][N];
bool vis[N] = {false};
vector<int> pre[N], tmpPath, path;
void dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && e[u][v] != 0) {
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
void dfs(int u) {
    tmpPath.push_back(u);
    if (pre[u].size() == 0) {
        cntPath++;
        int sum = 0;
        for (auto it : tmpPath) sum += w[it];
        if (maxW < sum) {
            maxW = sum;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    for (auto it : pre[u]) dfs(it);
    tmpPath.pop_back();
}
int main() {
    int a, b, d;
    scanf("%d%d%d%d", &n, &m, &st, &dest);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    while (m--) {
        scanf("%d%d%d", &a, &b, &d);
        e[a][b] = e[b][a] = d;
    }
    dijkstra(st);
    dfs(dest);
    printf("%d %d\n", cntPath, maxW);
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", path[path.size() - i - 1]);
    }
    return 0;
}