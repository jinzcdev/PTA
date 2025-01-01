// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805363914686464
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    double number[100010], ans = 0.0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &number[i]);
    for (int i = 1; i <= n; i++) {
        ans += number[i] * i * (n - i + 1);
    }
    printf("%.2f", ans);
    return 0;
}