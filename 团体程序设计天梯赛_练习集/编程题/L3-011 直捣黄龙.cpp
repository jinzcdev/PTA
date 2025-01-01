// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805049455132672
#include <bits/stdc++.h>
using namespace std;
const int N = 210, INF = INT_MAX;
int n, k, d[N], e[N][N], w[N];
int start = 0, dest, cntPath = 0, maxRelease = -1, maxSum = -1;
vector<int> pre[N], tmpPath, path;
unordered_map<string, int> name2id;
unordered_map<int, string> id2name;
void dijkstra(int s) {
    fill(d, d + N, INF);
    d[s] = 0;
    bool vis[N] = {false};
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
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
void dfs(int u) {
    tmpPath.push_back(u);
    if (u == start) {
        int sum = 0;
        for (int i = 0; i < tmpPath.size() - 1; i++) {
            sum += w[tmpPath[i]];
        }
        if ((int)tmpPath.size() > maxRelease) {
            maxRelease = tmpPath.size();
            path = tmpPath;
            maxSum = sum;
        } else if ((int)tmpPath.size() == maxRelease && sum > maxSum) {
            maxSum = sum;
            path = tmpPath;
        }
        tmpPath.pop_back();
        cntPath++;
        return;
    }
    for (auto v : pre[u]) {
        dfs(v);
    }
    tmpPath.pop_back();
}
int main() {
    fill(e[0], e[0] + N * N, INF);
    scanf("%d%d", &n, &k);
    string u, v, s;
    cin >> u >> v;

    int pos = 0;
    id2name[0] = u;
    name2id[u] = pos++;
    for (int i = 0; i < n - 1; i++) {
        cin >> s;
        name2id[s] = pos;
        id2name[pos] = s;
        if (s == v) {
            dest = pos;
        }
        cin >> w[pos++];
    }
    int t;
    while (k--) {
        cin >> u >> v >> t;
        int id_u = name2id[u], id_v = name2id[v];
        e[id_u][id_v] = e[id_v][id_u] = t;
    }
    dijkstra(0);
    dfs(dest);
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << id2name[path[i]];
        if (i != 0) {
            cout << "->";
        }
    }
    printf("\n%d %d %d", cntPath, d[dest], maxSum);
    return 0;
}