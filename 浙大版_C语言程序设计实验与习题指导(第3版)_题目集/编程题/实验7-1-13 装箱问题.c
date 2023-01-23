// https://pintia.cn/problem-sets/13/problems/509
#include <stdio.h>
const int N = 1010;
int main() {
    int n, a[N], tmp;
    for (int i = 0; i < N; i++) {
        a[i] = 0;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        int j = 1;
        for (; j <= 1000; j++) {
            if (a[j] + tmp <= 100) {
                a[j] += tmp;
                break;
            }
        }
        printf("%d %d\n", tmp, j);
    }
    int i = 1;
    while (i <= 1000 && a[i] != 0) i++;
    printf("%d", i - 1);
    return 0;
}