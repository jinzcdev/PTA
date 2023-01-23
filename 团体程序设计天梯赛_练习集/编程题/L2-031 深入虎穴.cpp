// https://pintia.cn/problem-sets/994805046380707840/problems/1111914599412858888
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int> e[N];
int maxDepth = -1, ans;
bool vis[N] = {false};
void dfs(int u, int depth) {
    vis[u] = true;
    if (depth > maxDepth) {
        maxDepth = depth;
        ans = u;
    }
    for (auto it : e[u])
        if (!vis[it]) dfs(it, depth + 1);
}
int main() {
    int n, m, a, hash[N] = {0}, u = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &a);
            e[i].push_back(a);
            hash[a] = 1;
        }
    }
    while (hash[u]) u++;
    dfs(u, 1);
    printf("%d", ans);
    return 0;
}