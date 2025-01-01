// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805056195379200
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> e[N];
int main() {
    int n, m, k, np, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &np);
        vector<vector<bool> > vis;
        vis.resize(n + 1, vector<bool>(n + 1, false));
        // bool vis[N][N] = {false};
        int cnt = 0;
        while (np--) {
            scanf("%d", &a);
            for (int i = 0; i < e[a].size(); i++) {
                if (!vis[a][e[a][i]]) {
                    vis[a][e[a][i]] = vis[e[a][i]][a] = true;
                    if (++cnt == m) break;
                }
            }
        }
        printf("%s\n", cnt == m ? "YES" : "NO");
    }
    return 0;
}