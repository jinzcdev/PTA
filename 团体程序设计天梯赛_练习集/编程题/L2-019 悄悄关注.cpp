// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805059731177472
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
struct node {
    string name;
    int cnt;
};
int main() {
    int n, m, a, sumLike = 0;
    double avg = 0;
    string s;
    unordered_map<string, int> mp, cntLike;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s] = 1;
    }
    scanf("%d", &m);
    vector<node> v;
    for (int i = 0; i < m; i++) {
        cin >> s >> a;
        v.push_back({s, a});
        sumLike += a;
    }
    avg = sumLike * 1.0 / m;
    vector<string> ans;
    for (int i = 0; i < m; i++) {
        if (mp[v[i].name]) continue;
        if (v[i].cnt > avg) ans.push_back(v[i].name);
    }
    if (ans.size() == 0) printf("Bing Mei You\n");
    else {
        sort(ans.begin(), ans.end());
        for (auto it : ans) cout << it << endl;
    }
    return 0;
}