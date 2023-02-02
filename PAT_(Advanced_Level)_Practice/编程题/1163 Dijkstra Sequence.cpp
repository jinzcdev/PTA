// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1478635670373253120
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
const int INF = 0x7FFFFFFF;
int G[maxn][maxn], d[maxn], number[maxn];
bool vis[maxn];
int n, m, k;

bool Dijkstra(int s) {
    fill(vis, vis + maxn, false);
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1 || d[u] != d[number[i]]) return false;
        u = number[i];
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + maxn * maxn, INF);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    scanf("%d", &k);
    while (k--) {
        for (int i = 1; i <= n; i++) {
            cin >> number[i];
        }
        if (Dijkstra(number[1])) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
