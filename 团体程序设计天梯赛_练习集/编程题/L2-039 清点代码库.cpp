// https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652362
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, vector<int> > piv;
bool cmp(piv &a, piv &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++) {
        vector<int> v(m);
        for (int j = 0; j < m; j++)
            scanf("%d", &v[j]);
        mp[v]++;
    }
    vector<piv> ans;
    for (auto it : mp)
        ans.push_back({it.second, it.first});
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i].first);
        vector<int> a = move(ans[i].second);
        for (int j = 0; j < a.size(); j++) printf(" %d", a[j]);
        printf("\n");
    }
    return 0;
}