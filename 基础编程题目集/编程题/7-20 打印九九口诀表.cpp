// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=800
#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%-4d", j, i, i * j);
        }
        printf("\n");
    }
    return 0;
}