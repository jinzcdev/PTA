// https://pintia.cn/problem-sets/13/exam/problems/437
#include <stdio.h>
int main() {
    int n, ans, a;
    scanf("%d%d", &n, &ans);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a);
        if (a < ans) ans = a;
    }
    printf("min = %d", ans);
    return 0;
}