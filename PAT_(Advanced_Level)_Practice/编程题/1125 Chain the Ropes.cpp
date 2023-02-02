// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805350316752896
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.begin() + n);
    double ans = v[0];
    for (int i = 1; i < n; i++) {
        ans = (ans + v[i]) / 2;
    }
    cout << (int)ans;
    return 0;
}
