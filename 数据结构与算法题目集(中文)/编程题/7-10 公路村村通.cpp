// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=718
#include <bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
struct edge {
    int u, v, cost;
} e[N * 3];
int n, m, father[N];
bool cmp(edge a, edge b) { return a.cost < b.cost; }
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
int kruskal() {
    for (int i = 1; i <= n; i++) father[i] = i;
    sort(e, e + m, cmp);
    int ans = 0, cntEdge = 0;
    for (int i = 0; i < m; i++) {
        int faA = findFather(e[i].u), faB = findFather(e[i].v);
        if (faA != faB) {
            father[faA] = faB;
            ans += e[i].cost;
            if (++cntEdge == n - 1) break;
        }
    }
    return cntEdge != n - 1 ? -1 : ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].cost);
    printf("%d\n", kruskal());
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
int e[N][N], d[N], n, m;
int prime() {
    bool vis[N] = {false};
    fill(d, d + N, INF);
    d[1] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && e[u][v] != INF && e[u][v] < d[v]) {
                d[v] = e[u][v];
            }
        }
    }
    return ans;
}
int main() {
    int a, b, w;
    scanf("%d%d", &n, &m);
    fill(e[0], e[0] + N * N, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        e[a][b] = e[b][a] = w;
    }
    printf("%d\n", prime());
    return 0;
}
*/