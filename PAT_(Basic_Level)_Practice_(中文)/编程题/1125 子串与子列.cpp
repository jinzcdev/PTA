// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1729419194675666948
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    int min_len = INT_MAX, start = -1;
    for (int i = 0; i <= n - m; ++i) {
        if (s[i] != t[0]) {
            continue;
        }
        int k = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == t[k]) {
                if (m == ++k) {
                    if (j - i + 1 < min_len) {
                        min_len = j - i + 1;
                        start = i;
                    }
                    break;
                }
            }
        }
    }
    return start == -1 ? "" : s.substr(start, min_len);
}
int main() {
    string s, p;
    cin >> s >> p;
    cout << minWindow(s, p) << endl;
    return 0;
}