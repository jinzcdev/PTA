// https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int pre[N], in[N];
unordered_map<int, int> pos;
void lca(int prel, int prer, int inl, int inr, int u, int v) {
    if (prel > prer) return;
    int posR = pos[pre[prel]], posu = pos[u], posv = pos[v];
    if (posR > posu && posR > posv) lca(prel + 1, prel + posR - inl, inl, posR - 1, u, v);
    else if (posR < posu && posR < posv) lca(prel + posR - inl + 1, prer, posR + 1, inr, u, v);
    else if (posR == posu || posR == posv)
        printf("%d is an ancestor of %d.\n", pre[prel], posR == posu ? v : u);
    else if ((posR > posu && posR < posv) || (posR > posv && posR < posu))
        printf("LCA of %d and %d is %d.\n", u, v, pre[prel]);
}
int main() {
    int n, m, u, v;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
    while (m--) {
        scanf("%d%d", &u, &v);
        if (pos[u] == 0 && pos[v] == 0) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (pos[u] == 0 || pos[v] == 0) printf("ERROR: %d is not found.\n", pos[u] == 0 ? u : v);
        else lca(1, n, 1, n, u, v);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in;
unordered_map<int, int> pos;
void lca(int prel, int inl, int inr, int u, int v) {
    if (inl > inr) return;
    int posRoot = pos[pre[prel]], posu = pos[u], posv = pos[v];
    if (posu < posRoot && posv < posRoot) lca(prel + 1, inl, posRoot - 1 - 1, u, v);
    else if (posu > posRoot && posv > posRoot) lca(prel + posRoot - inl, posRoot, inr, u, v);
    else if (posu == posRoot || posv == posRoot)
        printf("%d is an ancestor of %d.\n", pre[prel], posu == posRoot ? v : u);
    else
        printf("LCA of %d and %d is %d.\n", u, v, pre[prel]);
}
int main() {
    int m, n, u, v;
    scanf("%d%d", &m, &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (pos[u] == 0 && pos[v] == 0) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (pos[u] == 0 || pos[v] == 0) printf("ERROR: %d is not found.\n", pos[u] == 0 ? u : v);
        else lca(0, 0, n - 1, u, v);
    }
    return 0;
}
*/