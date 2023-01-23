// https://pintia.cn/problem-sets/994805046380707840/problems/994805127389495296
#include <cstdio>
int main() {
    int n, sum = 0, tmp = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        tmp *= i;
        sum += tmp;
    }
    printf("%d", sum);
    return 0;
}