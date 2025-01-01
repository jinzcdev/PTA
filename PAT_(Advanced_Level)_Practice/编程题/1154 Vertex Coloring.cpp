// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1071785301894295552
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    vector<pair<int, int> > e;
    while (m--) {
        scanf("%d%d", &a, &b);
        e.push_back({a, b});
    }
    scanf("%d", &m);
    while (m--) {
        vector<int> color(n);
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            s.insert(color[i]);
        }
        bool flag = true;
        for (auto it : e) {
            if (color[it.first] == color[it.second]) {
                flag = false;
                break;
            }
        }
        if (flag) printf("%d-coloring\n", s.size());
        else printf("No\n");
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
vector<int> e[N], color(N);
bool vis[N] = {false}, flag;
void dfs(int u) {
    if (!flag) return;
    vis[u] = true;
    for (auto v : e[u]) {
        if (color[u] == color[v]) flag = false;
        if (!vis[v]) dfs(v);
    }
}
int main() {
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    scanf("%d", &k);
    while (k--) {
        unordered_set<int> s;
        fill(vis, vis + N, false);
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            s.insert(color[i]);
        }
        flag = true;
        dfs(0);
        if (!flag) printf("No\n");
        else printf("%d-coloring\n", s.size());
    }
    return 0;
}
*/