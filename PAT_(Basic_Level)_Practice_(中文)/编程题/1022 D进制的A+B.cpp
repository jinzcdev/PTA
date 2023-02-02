// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805299301433344
/*
#include <cstdio>
int main() {
    int a, b, d, sum;
    scanf("%d%d%d", &a, &b, &d);
    sum = a + b;
    int ans[31], num = 0;
    do {
        ans[num++] = sum % d;
        sum /= d;
    } while (sum != 0);
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}
*/
#include <cstdio>
void solve(int n, int d) {
    if (n == 0) return;
    solve(n / d, d);
    printf("%d", n % d);
}
int main() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    if (a + b == 0) printf("0");
    else solve(a + b, d);
    return 0;
}