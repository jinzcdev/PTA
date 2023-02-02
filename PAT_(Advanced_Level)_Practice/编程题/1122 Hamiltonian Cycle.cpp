// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805351814119424
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, nv, a, b, e[205][205];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &nv);
        vector<int> v(nv);
        bool vis[205] = {false};
        for (int j = 0; j < nv; j++) scanf("%d", &v[j]);
        if (nv != n + 1 || v[0] != v[nv - 1]) {
            printf("NO\n");
            continue;
        }
        bool flag = true;
        for (int j = 0; j < nv - 1; j++) {
            if (vis[v[j]] == true || e[v[j]][v[j + 1]] != 1) {
                flag = false;
                break;
            }
            vis[v[j]] = true;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}