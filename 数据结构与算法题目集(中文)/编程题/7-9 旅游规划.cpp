// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=717
#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int e[N][N], weight[N][N], d[N], cost[N], n, m, st, dest;
void dijkstra(int s) {
    fill(d, d + n, INF);
    fill(cost, cost + n, INF);
    d[s] = cost[s] = 0;
    bool vis[N] = {false};
    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && d[i] < MIN) {
                u = i;
                MIN = d[i];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && e[u][v] != INF) {
                if (d[u] + e[u][v] < d[v]) {
                    d[v] = d[u] + e[u][v];
                    cost[v] = cost[u] + weight[u][v];
                } else if (d[u] + e[u][v] == d[v] && cost[u] + weight[u][v] < cost[v]) {
                    cost[v] = cost[u] + weight[u][v];
                }
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &st, &dest);
    fill(e[0], e[0] + N * N, INF);
    int a, b, td, tc;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &td, &tc);
        e[a][b] = e[b][a] = td;
        weight[a][b] = weight[b][a] = tc;
    }
    dijkstra(st);
    printf("%d %d\n", d[dest], cost[dest]);
    return 0;
}
