// https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652360
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n, m, s_max, k;
    string str;
    scanf("%d%d%d", &n, &m, &s_max);
    vector<queue<char> > q(n + 1);
    stack<char> s;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (auto it : str) {
            q[i].push(it);
        }
    }
    vector<char> ans;
    while (scanf("%d", &k), k != -1) {
        if (k == 0 && !s.empty()) {
            ans.push_back(s.top());
            s.pop();
        } else if (!q[k].empty()) {
            if (s.size() == s_max) {
                ans.push_back(s.top());
                s.pop();
            }
            s.push(q[k].front());
            q[k].pop();
        }
    }
    for (auto it : ans) printf("%c", it);
    return 0;
}