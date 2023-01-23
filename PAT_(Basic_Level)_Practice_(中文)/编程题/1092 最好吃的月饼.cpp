// https://pintia.cn/problem-sets/994805260223102976/problems/1071785779399028736
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, cnt = 0, MAX = -1, sum[1010] = {0};
    scanf("%d%d", &n, &m);
    while (m--) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            sum[i] += a;
            MAX = max(MAX, sum[i]);
        }
    }
    printf("%d\n", MAX);
    for (int i = 1; i <= n; i++)
        if (sum[i] == MAX) printf("%s%d", cnt++ > 0 ? " " : "", i);
    return 0;
}