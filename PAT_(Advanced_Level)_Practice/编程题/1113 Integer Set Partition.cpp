// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805357258326016
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < n / 2; i++) ans += v[n - i - 1] - v[i];
    if (n % 2 == 1) ans += v[n / 2];
    printf("%d %d\n", n % 2 == 0 ? 0 : 1, ans);
    return 0;
}