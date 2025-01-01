// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173569
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        sum += v[r];
        while (l <= r && sum > m) {
            sum -= v[l++];
        }
        if (l <= r) {
            ans += r - l + 1;
        }
    }
    cout << ans;
    return 0;
}
