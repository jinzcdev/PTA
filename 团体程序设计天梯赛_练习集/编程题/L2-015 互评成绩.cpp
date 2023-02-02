// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805062432309248
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, m;
    vector<double> ans;
    scanf("%d%d%d", &n, &k, &m);
    while (n--) {
        int a, sum = 0, Min = 999, Max = -1;
        for (int i = 0; i < k; i++) {
            scanf("%d", &a);
            sum += a;
            if (a < Min) Min = a;
            if (a > Max) Max = a;
        }
        ans.push_back((sum - Min - Max) * 1.0 / (k - 2));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < m; i++) {
        if (i != 0) printf(" ");
        printf("%.3f", ans[ans.size() - (m - i)]);
    }
    return 0;
}