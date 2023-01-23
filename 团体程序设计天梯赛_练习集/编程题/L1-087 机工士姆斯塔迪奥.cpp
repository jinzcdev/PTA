// https://pintia.cn/problem-sets/994805046380707840/problems/1518581903422062592
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, t, a, cnt = 0;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int> > v(n + 1, vector<int>(m + 1, 0));
    while (k--) {
        scanf("%d%d", &t, &a);
        if (t == 0) for (int i = 1; i <= m; i++) v[a][i] = 1;
        else for (int i = 1; i <= n; i++) v[i][a] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cnt += v[i][j];

    cout << n * m - cnt;
    return 0;
}