// https://pintia.cn/problem-sets/994805342720868352/problems/994805409175420928
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, a, b;
    scanf("%d", &n);
    vector<unordered_set<int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &a);
            v[i].insert(a);
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &b);
        int nc = 0, nt = v[b].size();
        for (auto it : v[a]) {
            if (v[b].find(it) == v[b].end()) nt++;
            else nc++;
        }
        printf("%.1f%%\n", nc * 1.0 / nt * 100);
    }
    return 0;
}