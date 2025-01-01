// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=794
#include <cstdio>
int main() {
    int a, b, sum = 0, cnt = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        printf("%5d", i);
        sum += i;
        if (++cnt % 5 == 0) printf("\n");
    }
    if ((b - a + 1) % 5 != 0) printf("\n");
    printf("Sum = %d", sum);
    return 0;
}