// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1478633729396088832
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n, m = 1, k, x, ans[N] = {0};
    scanf("%d%d%d", &n, &k, &x);
    vector<int> v(n);
    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        if (z % 2 == 0) {
            m = m % k == 0 ? k : m % k;
            for (int j = n - 1; j >= m; j--) v[j] = v[j - m];
            for (int j = 0; j < m; j++) v[j] = x;
            m++;
        }
        for (int j = 0; j < n; j++) ans[j] += v[j];
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}