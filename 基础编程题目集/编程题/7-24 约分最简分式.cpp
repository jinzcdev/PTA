// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=804
#include <cstdio>
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    int a, b;
    scanf("%d/%d", &a, &b);
    printf("%d/%d", a / gcd(a, b), b / gcd(a, b));
    return 0;
}