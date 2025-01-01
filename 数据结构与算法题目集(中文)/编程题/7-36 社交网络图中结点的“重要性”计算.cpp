// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=863
#include <bits/stdc++.h>
using namespace std;
const int N = 10010, INF = INT_MAX;
int n, d[N], e[N][N];
bool vis[N] = {false};
void dijkstra(int s) {
    fill(d, d + N, INF);
    fill(vis, vis + N, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && e[u][v] != 0 && d[u] + e[u][v] < d[v]) {
                d[v] = d[u] + e[u][v];
            }
        }
    }
}
void dfs(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; v++)
        if (e[u][v] != 0 && !vis[v]) dfs(v);
}
int main() {
    int m, a, b, k, cnt = 0;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) {
            dfs(u);
            cnt++;
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &a);
        if (cnt > 1) printf("Cc(%d)=0.00\n", a);
        else {
            float sum = 0;
            dijkstra(a);
            for (int i = 1; i <= n; i++) sum += d[i];
            printf("Cc(%d)=%.2f\n", a, (n - 1) / sum);
        }
    }
    return 0;
}