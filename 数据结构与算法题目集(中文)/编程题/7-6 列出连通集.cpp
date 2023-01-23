// https://pintia.cn/problem-sets/15/problems/714
#include <bits/stdc++.h>
using namespace std;
int e[10][10], n, m;
bool vis[10];
void dfs(int u) {
    vis[u] = true;
    printf(" %d", u);
    for (int v = 0; v < n; v++)
        if (e[u][v] != 0 && !vis[v]) dfs(v);
}
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf(" %d", now);
        for (int v = 0; v < n; v++) {
            if (e[now][v] != 0 && !vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    for (int i = 0; i < 2; i++) {
        fill(vis, vis + n, false);
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                printf("{");
                if (i == 0) dfs(u);
                else bfs(u);
                printf(" }\n");
            }
        }
    }
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
const int N = 15;
set<int> e[N];
bool vis[N] = {false}, inq[N] = {false};
void dfs(int u) {
    vis[u] = true;
    printf(" %d", u);
    for (const auto &it : e[u])
        if (!vis[it]) dfs(it);
}
void bfs(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    printf("{");
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf(" %d", now);
        for (const auto &it : e[now]) {
            if (!inq[it]) {
                q.push(it);
                inq[it] = true;
            }
        }
    }
    printf(" }\n");
}
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].insert(b);
        e[b].insert(a);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            printf("{");
            dfs(i);
            printf(" }\n");
        }
    }
    for (int i = 0; i < n; i++) {
        if (!inq[i]) bfs(i);
    }
    return 0;
}
*/