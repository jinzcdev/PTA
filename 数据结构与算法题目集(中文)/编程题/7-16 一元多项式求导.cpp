// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=820
#include <cstdio>
int main() {
    int n, a, b, flag = 0;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (b > 0) {
            if (flag++ > 0) printf(" ");
            printf("%d %d", a * b, b - 1);
        }
    }
    if (!flag) printf("0 0");
    return 0;
}