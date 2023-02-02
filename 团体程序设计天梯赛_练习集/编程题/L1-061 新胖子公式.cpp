// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1111914599412858882
#include <cstdio>
int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    double ans = a / (b * b);
    if (ans > 25.0) printf("%.1f\nPANG", ans);
    else printf("%.1f\nHai Xing", ans);
    return 0;
}