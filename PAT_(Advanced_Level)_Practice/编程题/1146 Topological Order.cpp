// https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, a, b, cnt = 0;
    scanf("%d%d", &n, &m);
    vector<int> e[n + 1], in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        in[b]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        vector<int> v(n), tin = in;
        for (int j = 0; j < n; j++) scanf("%d", &v[j]);
        for (int j = 0; j < n; j++) {
            if (tin[v[j]] > 0) {
                if (cnt++ > 0) printf(" ");
                printf("%d", i);
                break;
            }
            for (auto it : e[v[j]]) tin[it]--;
        }
    }
    return 0;
}