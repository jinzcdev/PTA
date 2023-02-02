// https://pintia.cn/problem-sets/15/exam/problems/894
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, a;
    scanf("%d%d", &n, &m);
    vector<vector<string> > v(m + 1);
    string s;
    while (n--) {
        cin >> s >> k;
        while (k--) {
            scanf("%d", &a);
            v[a].push_back(s);
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d %d\n", i, v[i].size());
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j < v[i].size(); j++) {
            printf("%s\n", v[i][j].c_str());
        }
    }
    return 0;
}