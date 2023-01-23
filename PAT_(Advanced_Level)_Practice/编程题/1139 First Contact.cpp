// https://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first != b.first ? a.first < b.first : a.second < b.second;
}
int main() {
    int n, m, k;
    unordered_map<int, bool> isfriend;
    vector<int> f[10000];
    string a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int ia = abs(stoi(a)), ib = abs(stoi(b));
        if (a.length() == b.length()) {
            f[ia].push_back(ib);
            f[ib].push_back(ia);
        }
        isfriend[ia * 10000 + ib] = isfriend[ib * 10000 + ia] = true;
    }
    scanf("%d", &k);
    while (k--) {
        cin >> a >> b;
        int ia = abs(stoi(a)), ib = abs(stoi(b));
        vector<pair<int, int> > ans;
        for (auto ta : f[ia]) {
            if (ta == ib) continue;
            for (auto tb : f[ib]) {
                if (tb != ia && isfriend[ta * 10000 + tb]) {
                    ans.push_back({ta, tb});
                }
            }
        }
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end(), cmp);
        for (auto it : ans) printf("%04d %04d\n", it.first, it.second);
    }
    return 0;
}