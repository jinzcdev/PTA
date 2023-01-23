// https://pintia.cn/problem-sets/994805260223102976/problems/994805291311284224
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 1;
    long long p;
    scanf("%d%ld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n && n - i > ans; i++) {
        for (int j = i + ans; j < n; j++) {
            if (v[i] * p < v[j]) break;
            ans = max(ans, j - i + 1);
        }
    }
    printf("%d", ans);
    return 0;
}