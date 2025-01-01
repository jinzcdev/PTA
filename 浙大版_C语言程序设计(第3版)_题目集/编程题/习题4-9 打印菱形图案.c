// https://pintia.cn/problem-sets/12/exam/problems/type/7?problemSetProblemId=295
#include <stdio.h>
int main() {
    int n, row, num = -1;
    scanf("%d", &n);
    row = (n + 1) / 2;
    for (int i = 1; i <= row; i++) {
        num += 2;
        for (int j = 0; j < row - i; j++) printf("  ");
        for (int j = 0; j < num; j++) printf("* ");
        printf("\n");
    }
    for (int i = 1; i <= row - 1; i++) {
        num -= 2;
        for (int j = 0; j < i; j++) printf("  ");
        for (int j = 0; j < num; j++) printf("* ");
        printf("\n");
    }
    return 0;
}