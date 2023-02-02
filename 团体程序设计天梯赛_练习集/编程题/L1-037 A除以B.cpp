// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805094485180416
#include <cstdio>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b > 0) printf("%d/%d=%.2f", a, b, a * 1.0 / b);
    else if (b < 0) printf("%d/(%d)=%.2f", a, b, a * 1.0 / b);
    else printf("%d/%d=Error", a, b);
    return 0;
}