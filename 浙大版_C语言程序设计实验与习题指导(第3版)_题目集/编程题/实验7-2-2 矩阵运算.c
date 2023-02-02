// https://pintia.cn/problem-sets/13/exam/problems/513
#include <stdio.h>
int main() {
    int n, a, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            if (i != n - 1 && j != n - 1 && i + j + 1 != n) {
                ans += a;
            }
        }
    }
    printf("%d", ans);
    return 0;
}