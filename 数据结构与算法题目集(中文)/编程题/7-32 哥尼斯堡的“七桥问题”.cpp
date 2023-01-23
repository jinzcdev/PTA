// https://pintia.cn/problem-sets/15/problems/859
#include <bits/stdc++.h>
using namespace std;
bool vis[1010] = {false};
vector<int> e[1010];
void dfs(int u) {
    vis[u] = true;
    for (auto it : e[u])
        if (!vis[it]) dfs(it);
}
int main() {
    int n, m, a, b, cnt = 0;
    scanf("%d%d", &n, &m);
    vector<int> d(n + 1);
    while (m--) {
        scanf("%d%d", &a, &b);
        d[a]++;
        d[b]++;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    bool flag = (cnt == 1);
    for (int i = 1; i <= n; i++) {
        if (d[i] % 2 == 1) {
            flag = false;
            break;
        }
    }
    printf("%d", flag ? 1 : 0);
    return 0;
}