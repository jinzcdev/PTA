// https://pintia.cn/problem-sets/994805046380707840/problems/1336215880692482059
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int main() {
    int e[N][N] = {0}, n, m, k, a, b, dist, minCost = 0x7fffffff, ans = -1,
        cnt = 0;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &a, &b, &dist);
        e[a][b] = e[b][a] = dist;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &k);
        vector<int> v(k);
        unordered_set<int> s;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            s.insert(v[j]);
        }
        if (k != n || s.size() != n || e[0][v[0]] == 0 || e[0][v[k - 1]] == 0) continue;
        int sum = e[0][v[0]] + e[0][v[k - 1]], flag = 1;
        for (int j = 0; j < k - 1; j++) {
            if (e[v[j]][v[j + 1]] == 0) {
                flag = 0;
                break;
            }
            sum += e[v[j]][v[j + 1]];
        }
        if (!flag) continue;
        cnt++;
        if (sum < minCost) {
            minCost = sum;
            ans = i;
        }
    }
    printf("%d\n%d %d", cnt, ans, minCost);
    return 0;
}