// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343043829760
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
int main() {
    int n, m, u, v, k;
    scanf("%d%d", &n, &m);
    g.resize(n + 1);
    vector<int> in(n + 1, 0), ans;
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        in[v]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        vector<int> temp(in);
        bool flag = true;
        for (int j = 0; j < n; j++) {
            scanf("%d", &u);
            if (temp[u] != 0) {
                if (flag) {
                    ans.push_back(i);
                    flag = false;
                }
            }
            for (auto it : g[u]) temp[it]--;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}