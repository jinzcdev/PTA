// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805059118809088
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int> e[N];
int n, k, power[N] = {0};
double z, r, ans = 0;
void dfs(int u, int depth) {
    if (power[u] != 0) {
        ans += z * pow(1 - (r / 100.0), depth) * power[u];
    }
    for (auto &it : e[u]) {
        dfs(it, depth + 1);
    }
}
int main() {
    int a;
    scanf("%d%lf%lf", &n, &z, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k == 0) {
            scanf("%d", &power[i]);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &a);
            e[i].push_back(a);
        }
    }
    dfs(0, 0);
    printf("%d", (int)ans);
    return 0;
}