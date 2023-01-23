// https://pintia.cn/problem-sets/13/problems/441
#include <stdio.h>
int main() {
    int a, n, temp = 0;
    scanf("%d%d", &a, &n);
    for (int i = 1; i <= n; i++) {
        temp = temp * 10 + i;
    }
    printf("s = %d", a * temp);
    return 0;
}