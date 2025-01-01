// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805489282433024
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 510;
const int INF = 0x7FFFFFFF;
int G[N][N], weight[N];
int d[N], vis[N] = {false};
int c, n, sp, m;
int st = 0, ed;
vector<int> pre[N];
vector<int> path, tempPath;

void dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int minNeed = INF, minRemain = INF;
void dfs(int v) {
    if (v == st) {
        tempPath.push_back(v);
        int remain = 0, need = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if (weight[id] > 0) {
                remain += weight[id];
            } else {
                if (remain > abs(weight[id])) remain -= abs(weight[id]);
                else {
                    need += abs(weight[id]) -remain;
                    remain = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if (need == minNeed && remain < minRemain) {
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &c, &n, &sp, &m);
    fill(G[0], G[0] + N * N, INF);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= c / 2;
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    dijkstra(st);
    dfs(sp);
    printf("%d ", minNeed);
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != path.size() - 1) printf("->");
        printf("%d", path[i]);
    }
    printf(" %d", minRemain);
    return 0;
}