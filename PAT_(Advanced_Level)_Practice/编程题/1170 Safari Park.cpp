// https://pintia.cn/problem-sets/994805342720868352/exam/problems/1621700071370862592
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int main() {
    int n, r, k, m, a, b;
    vector<pair<int, int>> e;
    scanf("%d%d%d", &n, &r, &k);
    while (r--) {
        scanf("%d%d", &a, &b);
        e.push_back({a, b});
    }
    scanf("%d", &m);
    while (m--) {
        vector<int> v(n + 1);
        unordered_set<int> s;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if (s.size() > k) printf("Error: Too many species.\n");
        else if (s.size() < k) printf("Error: Too few species.\n");
        else {
            bool flag = true;
            for (auto it : e) {
                if (v[it.first] == v[it.second]) {
                    flag = false;
                    break;
                }
            }
            printf("%s\n", flag ? "Yes" : "No");
        }
    }
    return 0;
}