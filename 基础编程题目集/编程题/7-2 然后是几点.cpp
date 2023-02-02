// https://pintia.cn/problem-sets/14/exam/problems/782
#include <cstdio>
int main() {
    int a, b, m;
    scanf("%d%d", &a, &b);
    m = a / 100 * 60 + a % 100 + b;
    printf("%d%02d", m / 60, m % 60);
    return 0;
}
