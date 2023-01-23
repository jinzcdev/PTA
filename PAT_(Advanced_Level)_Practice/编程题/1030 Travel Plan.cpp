// https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x7FFFFFFF;

int n, m, start, dest;
int G[maxn][maxn], cost[maxn][maxn], pre[maxn];
int d[maxn], c[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s){
    fill(d, d + maxn, INF);
    fill(c, c + maxn, INF);
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < n; i++)
        pre[i] = i;
    for (int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++){
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++){
            if (!vis[v] && G[u][v] < INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if (d[u] + G[u][v] == d[v]) {
                    if (c[u] + cost[u][v] < c[v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }   
    }
}

void DFS(int s, int v) {
    if (s == v) {
        printf("%d ",v);
        return;
    }
    DFS(s, pre[v]);
    printf("%d ", v);
}

int main(){
    scanf("%d%d%d%d", &n, &m, &start, &dest);
    fill(G[0], G[0] + maxn * maxn, INF);
    int u, v;
    for (int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(start);
    DFS(start, dest);
    printf("%d %d", d[dest], c[dest]);
    return 0;
}