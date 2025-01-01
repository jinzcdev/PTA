// https://pintia.cn/problem-sets/12/exam/problems/type/7?problemSetProblemId=287
#include <stdio.h>
int main() {
    int a, sum = 0;
    while (scanf("%d", &a), a > 0) sum += a % 2 != 0 ? a : 0;
    printf("%d", sum);
    return 0;
}