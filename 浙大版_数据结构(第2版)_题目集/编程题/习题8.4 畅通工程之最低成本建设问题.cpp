// https://pintia.cn/problem-sets/434/exam/problems/type/7?problemSetProblemId=6544
#include <bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x7fffffff;
bool vis[N] = {false};
int e[N][N], d[N], n, m;
void dfs(int u) {
    vis[u] = true;
    for (int i = 1; i <= n; i++)
        if (e[u][i] != INF && !vis[i]) dfs(i);
}
int prime(int s) {
    fill(d, d + N, INF);
    fill(vis, vis + N, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return -1;
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && e[u][v] != INF && e[u][v] < d[v]) {
                d[v] = e[u][v];
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += d[i];
    return sum;
}
int main() {
    scanf("%d%d", &n, &m);
    fill(e[0], e[0] + N * N, INF);
    int a, b, d, cnt = 0;
    while (m--) {
        scanf("%d%d%d", &a, &b, &d);
        e[a][b] = e[b][a] = d;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    if (cnt > 1) printf("Impossible");
    else printf("%d", prime(1));
    return 0;
}
