// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1386335159927652361
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> e[N], ans, path;
void dfs(int u) {
    path.push_back(u);
    if (e[u].size() == 0) {
        if (path.size() > ans.size()) ans = path;
        path.pop_back();
        return;
    }
    for (auto it : e[u]) dfs(it);
    path.pop_back();
}
int main() {
    int n, k, a, root = 0;
    scanf("%d", &n);
    bool vis[N] = {false};
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &a);
            e[i].push_back(a);
            vis[a] = true;
        }
        sort(e[i].begin(), e[i].end());
    }
    while (vis[root]) root++;
    dfs(root);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}