// https://pintia.cn/problem-sets/15/problems/865
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    m = min(n, m);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for (int i = 1; i <= m; i++) {
        if (i != 1) printf(" ");
        printf("%d", v[n - i]);
    }
    return 0;
}