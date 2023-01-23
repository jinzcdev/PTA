// https://pintia.cn/problem-sets/434/problems/6476
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> e[N];
int bfs(int u) {
    queue<int> q;
    q.push(u);
    bool inq[N] = {false};
    inq[u] = true;
    int depth[N] = {0}, cnt = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (depth[now] + 1 > 6) break;
        for (auto it : e[now]) {
            if (!inq[it]) {
                depth[it] = depth[now] + 1;
                inq[it] = true;
                q.push(it);
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d: %.2f%%\n", i, bfs(i) * 100.0 / n);
    }
    return 0;
}