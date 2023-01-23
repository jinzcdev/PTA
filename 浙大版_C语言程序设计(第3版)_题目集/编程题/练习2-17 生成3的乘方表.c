// https://pintia.cn/problem-sets/12/problems/249
#include <stdio.h>
int main() {
    int n, sum = 1;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        printf("pow(3,%d) = %d\n", i, sum);
        sum *= 3;
    }
    return 0;
}