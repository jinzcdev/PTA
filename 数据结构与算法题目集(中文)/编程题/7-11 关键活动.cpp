// https://pintia.cn/problem-sets/15/problems/719
#include <bits/stdc++.h>
using namespace std;
const int N = 110, INF = INT_MAX;
typedef pair<int, int> pii;
int n, m, e[N][N], ind[N] = {0}, ve[N] = {0}, vl[N] = {0}, max_cost = -1;
vector<pii> ans;
stack<int> topOrder;
bool cmp(pii &a, pii &b) {
    return a.first != b.first ? a.first < b.first : a.second > b.second;
}
bool topSort() {
    int cnt = 0;
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (ind[u] == 0) {
            q.push(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topOrder.push(u);
        cnt++;
        for (int v = 1; v <= n; v++) {
            if (e[u][v] != INF) {
                ve[v] = max(ve[v], ve[u] + e[u][v]);
                if (--ind[v] == 0) q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) max_cost = max(max_cost, ve[i]);
    fill(vl, vl + N, max_cost);
    while (!topOrder.empty()) {
        int u = topOrder.top();
        topOrder.pop();
        for (int v = 1; v <= n; v++) {
            if (e[u][v] != INF) vl[u] = min(vl[u], vl[v] - e[u][v]);
        }
    }
    return n == cnt;
}
int main() {
    fill(e[0], e[0] + N * N, INF);
    int a, b, cost;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &cost);
        e[a][b] = cost;
        ind[b]++;
    }
    if (!topSort()) {
        printf("0");
        return 0;
    }
    printf("%d\n", max_cost);
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (e[u][v] != INF && ve[u] == vl[v] - e[u][v])
                ans.push_back({u, v});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (auto it : ans) printf("%d->%d\n", it.first, it.second);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 110, INF = INT_MAX;
typedef pair<int, int> pii;
int n, m, e[N][N], ind[N] = {0}, ve[N] = {0}, vl[N] = {0}, max_cost = -1;
bool vis[N] = {false};
vector<pii> ans;
stack<int> topOrder;
bool cmp(pii &a, pii &b) {
    return a.first != b.first ? a.first < b.first : a.second > b.second;
}
bool topSort() {
    int cnt = 0;
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (ind[u] == 0) {
            q.push(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topOrder.push(u);
        cnt++;
        for (int v = 1; v <= n; v++) {
            if (e[u][v] != INF) {
                ve[v] = max(ve[v], ve[u] + e[u][v]);
                if (--ind[v] == 0) q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) max_cost = max(max_cost, ve[i]);
    fill(vl, vl + N, max_cost);
    while (!topOrder.empty()) {
        int u = topOrder.top();
        topOrder.pop();
        for (int v = 1; v <= n; v++) {
            if (e[u][v] != INF) vl[u] = min(vl[u], vl[v] - e[u][v]);
        }
    }
    return n == cnt;
}
void dfs(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
        if (e[u][v] != INF) {
            if (vl[v] - e[u][v] == ve[u]) ans.push_back({u, v});
            if (!vis[v]) dfs(v);
        }
    }
}
int main() {
    fill(e[0], e[0] + N * N, INF);
    int a, b, cost;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &cost);
        e[a][b] = cost;
        ind[b]++;
    }
    if (!topSort()) {
        printf("0");
        return 0;
    }
    printf("%d\n", max_cost);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);
    sort(ans.begin(), ans.end(), cmp);
    for (auto it : ans) printf("%d->%d\n", it.first, it.second);
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    int u, v;
    bool operator<(const node& a) const { return a.u != u ? u < a.u : v > a.v; }
};
vector<int> e[N], tmpPath;
vector<vector<int> > path;
int n, m, ind[N] = {0}, w[N][N] = {0}, MAX = -1;
bool vis[N] = {false};
bool isCyclic() {
    int cnt = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        for (auto it : e[now])
            if (--ind[it] == 0) q.push(it);
    }
    return cnt != n + 2;
}
void dfs(int u, int v) {
    vis[u] = true;
    tmpPath.push_back(u);
    if (u == v) {
        int sum_cost = 0;
        for (int i = 0; i < tmpPath.size() - 1; i++)
            sum_cost += w[tmpPath[i]][tmpPath[i + 1]];
        if (sum_cost == MAX) path.push_back(tmpPath);
        else if (sum_cost >= MAX) {
            MAX = sum_cost;
            path.clear();
            path.push_back(tmpPath);
        }
        vis[u] = false;
        tmpPath.pop_back();
        return;
    }
    for (auto it : e[u])
        if (!vis[it]) dfs(it, v);
    vis[u] = false;
    tmpPath.pop_back();
}
int main() {
    int a, b, cost;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &cost);
        e[a].push_back(b);
        ind[b]++;
        w[a][b] = cost;
        vis[a] = true;
    }
    int st = 0, dest = n + 1;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            e[st].push_back(i);
            ind[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            e[i].push_back(dest);
            ind[dest]++;
        }
    }
    if (isCyclic()) {
        printf("0");
        return 0;
    }
    fill(vis, vis + N, false);
    dfs(st, dest);
    printf("%d\n", MAX);
    set<node> s;
    for (auto v : path)
        for (int i = 1; i < v.size() - 2; i++) s.insert({v[i], v[i + 1]});
    vector<node> ans;
    for (auto it : s) ans.push_back(it);
    for (auto it : ans) printf("%d->%d\n", it.u, it.v);
    return 0;
}
*/
