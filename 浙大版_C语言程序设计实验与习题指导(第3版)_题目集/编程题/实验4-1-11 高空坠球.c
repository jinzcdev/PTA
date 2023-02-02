// https://pintia.cn/problem-sets/13/exam/problems/445
#include <math.h>
#include <stdio.h>
int main() {
    double h, ans = 0.0;
    int n;
    scanf("%lf%d", &h, &n);
    if (n == 0) {
        printf("0.0 0.0");
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        ans += (h / pow(2, i - 2));
    }
    ans += h;
    printf("%.1f %.1f", ans, h / pow(2, n));
    return 0;
}