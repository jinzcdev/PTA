// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805055679479808
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int> e[N], cnt[N];
int n, a, root, maxDepth = -1;
void dfs(int u, int depth) {
    maxDepth = max(maxDepth, depth);
    cnt[depth].push_back(u);
    for (auto &it : e[u]) dfs(it, depth + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a == -1) root = i;
        else e[a].push_back(i);
    }
    dfs(root, 0);
    printf("%d\n", maxDepth + 1);
    for (int i = 0; i < cnt[maxDepth].size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", cnt[maxDepth][i]);
    }
    return 0;
}