// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1697151678120173568
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1), left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n && v[j] >= v[j + 1]; j++) {
            if (v[j] > v[j + 1]) ++right[i];
        }
    }
    for (int i = n; i > 1; i--) {
        for (int j = i; j > 1 && v[j] >= v[j - 1]; j--) {
            if (v[j] > v[j - 1]) ++left[i];
        }
    }
    for (int i = 1; i <= n; i++) ans += max(left[i], right[i]) * 100 + 200;
    cout << ans;
    return 0;
}