// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1697150941050929156
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            if ((sum += v[j]) <= m) {
                ans++;
            } else {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}