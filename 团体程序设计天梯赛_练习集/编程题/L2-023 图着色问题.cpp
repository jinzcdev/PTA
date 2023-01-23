// https://pintia.cn/problem-sets/994805046380707840/problems/994805057298481152
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int main() {
    int n, m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    vector<pair<int, int> > v;
    while (m--) {
        scanf("%d%d", &a, &b);
        v.push_back({a, b});
    }
    scanf("%d", &m);
    while (m--) {
        unordered_set<int> s;
        int color[N] = {0};
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            s.insert(a);
            color[i] = a;
        }
        if (s.size() != k) printf("No\n");
        else {
            bool flag = true;
            for (auto it : v) {
                if (color[it.first] == color[it.second]) {
                    flag = false;
                    break;
                }
            }
            printf("%s\n", flag ? "Yes" : "No");
        }
    }
    return 0;
}