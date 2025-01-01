// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1478633948431106048
#include <bits/stdc++.h>
using namespace std;
bool cmp(string &a, string &b) { return a.substr(6, 8) < b.substr(6, 8); }
int main() {
    int n, cnt = 0;
    string s;
    unordered_map<string, bool> vis;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        vis[s] = true;
    }
    scanf("%d", &n);
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (vis[v[i]]) cnt++;
    }
    sort(v.begin(), v.end(), cmp);
    if (cnt == 0) printf("%d\n%s", cnt, v[0].c_str());
    else {
        for (int i = 0; i < v.size(); i++) {
            if (vis[v[i]]) {
                printf("%d\n%s", cnt, v[i].c_str());
                break;
            }
        }
    }
    return 0;
}