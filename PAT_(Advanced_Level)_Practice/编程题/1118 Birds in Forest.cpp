// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805354108403712
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int father[N];
void init() {
    for (int i = 1; i <= N; i++) {
        father[i] = i;
    }
}
int findFather(int x) {
    if (x == father[x]) return x;
    int f = findFather(father[x]);
    father[x] = f;
    return f;
}
void Union(int a, int b) {
    int faa = findFather(a);
    int fab = findFather(b);
    if (faa != fab) father[faa] = fab;
}
int main() {
    init();
    int n, m, k, a, b, cntBird = 0, cntTree = 0;
    bool vis[N] = {false};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int pre, temp;
        scanf("%d%d", &m, &pre);
        cntBird = max(pre, cntBird);
        for (int j = 0; j < m - 1; j++) {
            scanf("%d", &temp);
            Union(pre, temp);
            cntBird = max(temp, cntBird);
        }
    }
    for (int i = 1; i <= cntBird; i++) {
        int fa = findFather(i);
        if (!vis[fa]) {
            cntTree++;
            vis[fa] = true;
        }
    }
    printf("%d %d\n", cntTree, cntBird);
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &b);
        printf("%s\n", findFather(a) == findFather(b) ? "Yes" : "No");
    }
    return 0;
}
