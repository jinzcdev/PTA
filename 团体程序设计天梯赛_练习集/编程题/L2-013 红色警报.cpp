// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805063963230208
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
bool vis[N] = {false}, occupied[N] = {false};
vector<int> e[N];
int n, m, k, a, b;
void dfs(int u) {
    vis[u] = true;
    for (auto it : e[u])
        if (!vis[it] && !occupied[it]) dfs(it);
}
int count_cc() {
    int cnt = 0;
    fill(vis, vis + N, false);
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            if (!occupied[u]) dfs(u);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int pre = count_cc();
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        occupied[a] = true;
        int tmp = count_cc();
        if (tmp > pre + 1) printf("Red Alert: City %d is lost!\n", a);
        else printf("City %d is lost.\n", a);
        pre = tmp;
        if (i == n - 1) printf("Game Over.");
    }
    return 0;
}