// https://pintia.cn/problem-sets/12/problems/345
#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    a += c;
    b += d;
    if (fabs(a) < 0.05) a = fabs(a);
    if (fabs(b) < 0.05) b = fabs(b);
    printf("(%.1f, %.1f)", a, b);
    return 0;
}