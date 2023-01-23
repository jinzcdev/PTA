// https://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int main() {
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);
    vector<int> v[N];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while (m--) {
        scanf("%d", &k);
        bool flag = true, hash[N] = {false};
        for (int i = 0; i < k; i++) {
            scanf("%d", &a);
            if (hash[a]) flag = false;
            for (auto it : v[a]) hash[it] = true;
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}