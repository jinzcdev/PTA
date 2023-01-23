// https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<int> e[N];
int n, m, l, k, a;
int bfs(int root) {
    int inq[N] = {0}, depth[N] = {0}, cnt = 0;
    queue<int> q;
    q.push(root);
    inq[root] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (depth[now] >= l) continue;
        for (auto it : e[now]) {
            if (!inq[it]) {
                q.push(it);
                inq[it] = 1;
                depth[it] = depth[now] + 1;
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &a);
            e[a].push_back(i);
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &a);
        printf("%d\n", bfs(a));
    }
    return 0;
}