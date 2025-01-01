// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=791
#include <cstdio>
int main() {
    int x;
    scanf("%d", &x);
    if (x <= 15) printf("%.2f", 4.0 * x / 3);
    else printf("%.2f", x * 2.5 - 17.5);
    return 0;
}