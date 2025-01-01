// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805124398956544
#include <cstdio>
int main() {
    int n, numRow = 0;
    char ch;
    scanf("%d %c", &n, &ch);
    numRow = (n + 1) / 2;
    for (int i = 0; i < numRow; i++) {
        for (int j = 0; j < n; j++) printf("%c", ch);
        printf("\n");
    }
    return 0;
}
