// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805260780945408
#include <cstdio>
#include <cmath>
int main() {
    int a[10010], d[10010] = {0}, n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) d[abs(a[i] - i)]++;
    for (int i = 10000; i >= 0; i--)
        if (d[i] > 1) printf("%d %d\n", i, d[i]);
    return 0;
}