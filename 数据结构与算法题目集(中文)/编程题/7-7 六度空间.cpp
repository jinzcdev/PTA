// https://pintia.cn/problem-sets/15/exam/problems/715
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> e[N];
int bfs(int u) {
    queue<int> q;
    q.push(u);
    int cnt = 1, depth[N] = {0};
    bool vis[N] = {false};
    vis[u] = true;
    depth[u] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (depth[now] > 6) break;
        for (auto it : e[now]) {
            if (!vis[it]) {
                q.push(it);
                depth[it] = depth[now] + 1;
                vis[it] = true;
                cnt += 1;
            }
        }
    }
    return cnt;
}
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) printf("%d: %.2f%%\n", i, bfs(i) * 100.0 / n);
    return 0;
}