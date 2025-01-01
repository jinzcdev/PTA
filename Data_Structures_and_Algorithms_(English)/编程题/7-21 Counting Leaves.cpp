// https://pintia.cn/problem-sets/16/exam/problems/type/7?problemSetProblemId=683
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int maxDepth, leaf[N];
vector<int> e[N];
void dfs(int root, int depth) {
    if (root == -1) return;
    maxDepth = max(maxDepth, depth);
    if (e[root].size() == 0) leaf[depth]++;
    for (auto it : e[root]) dfs(it, depth + 1);
}
int main() {
    int n, m, k, a, b;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < N; i++) e[i].clear();
        fill(leaf, leaf + N, 0);
        maxDepth = -1;
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d", &a, &k);
            while (k--) {
                scanf("%d", &b);
                e[a].push_back(b);
            }
        }
        dfs(1, 0);
        for (int i = 0; i <= maxDepth; i++) {
            if (i != 0) printf(" ");
            printf("%d", leaf[i]);
        }
        printf("\n");
    }
    return 0;
}