// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805366343188480
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n), dpMax(n), dpMin(n), ans;
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    dpMax[0] = v[0];
    dpMin[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++) {
        dpMax[i] = max(dpMax[i - 1], v[i]);
        dpMin[n - i - 1] = min(dpMin[n - i], v[n - i - 1]);
    }
    for (int i = 0; i < v.size(); i++)
        if (dpMax[i] == v[i] && dpMin[i] == v[i]) ans.push_back(v[i]);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    if (ans.size() == 0) printf("\n");
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}