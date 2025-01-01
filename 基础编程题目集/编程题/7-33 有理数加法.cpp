// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=813
#include <cstdio>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int a, b, c, d;
    scanf("%d/%d %d/%d", &a, &b, &c, &d);
    a = a * d + b * c;
    b = b * d;
    if (a % b == 0) printf("%d", a / b);
    else {
        int tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
        printf("%d/%d", a, b);
    }
    return 0;
}