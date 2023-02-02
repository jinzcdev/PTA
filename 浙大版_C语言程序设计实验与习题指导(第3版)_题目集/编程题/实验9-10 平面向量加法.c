// https://pintia.cn/problem-sets/13/exam/problems/565
#include <stdio.h>
int main() {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    a += c;
    b += d;
    if (a > -0.05 && a < 0) a = 0;
    if (b > -0.05 && b < 0) b = 0;
    printf("(%.1f, %.1f)", a, b);
    return 0;
}