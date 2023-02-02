// https://pintia.cn/problem-sets/15/exam/problems/716
#include <bits/stdc++.h>
using namespace std;
const int N = 110, INF = INT_MAX;
int e[N][N], d[N], n, m;
void dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    bool vis[N] = {false};
    while (true) {
        int u = -1, MIN = INF;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && d[i] < MIN) {
                u = i;
                MIN = d[i];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && e[u][v] != INF && d[u] + e[u][v] < d[v])
                d[v] = d[u] + e[u][v];
        }
    }
}
int main() {
    fill(e[0], e[0] + N * N, INF);
    scanf("%d%d", &n, &m);
    int a, b, w;
    while (m--) {
        scanf("%d%d%d", &a, &b, &w);
        e[a][b] = e[b][a] = w;
    }
    int ans = -1, minlen = INF;
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        int maxlen = -1;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            if (d[j] > maxlen) maxlen = d[j];
        }
        if (maxlen < minlen) {
            minlen = maxlen;
            ans = i;
        }
    }
    if (ans == -1) printf("0");
    else printf("%d %d\n", ans, minlen);
    return 0;
}