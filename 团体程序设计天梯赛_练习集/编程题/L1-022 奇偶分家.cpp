// https://pintia.cn/problem-sets/994805046380707840/problems/994805114445873152
#include <cstdio>
int main() {
    int n, a, cntOdd = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2 != 0) cntOdd++;
    }
    printf("%d %d", cntOdd, n - cntOdd);
    return 0;
}