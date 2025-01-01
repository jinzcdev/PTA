// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805528788582400
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, cnt = 0;
    cin >> a >> b;
    a += b;
    if (a < 0) cout << "-";
    string s = to_string(abs(a));
    int k = s.size() % 3;
    for (int i = 0; i < k; i++) cout << s[i];
    if (k != 0 && s.size() >= 3) cout << ",";
    for (int i = k; i < (int)s.size(); i += 3) {
        if (cnt++ > 0) cout << ",";
        cout << s.substr(i, 3);
    }
    return 0;
}