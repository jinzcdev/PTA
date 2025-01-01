// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805142086336512
#include <cstdio>
int main() {
    double a;
    scanf("%lf", &a);
    printf("Celsius = %d", (int)(5 * (a - 32) / 9));
    return 0;
}
