// https://pintia.cn/problem-sets/434/problems/5654
#include <cstdio>
const int N = 100010;
int main() {
    int a, n, ans[N] = {0}, carry = 0, len = 0;
    scanf("%d%d", &a, &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        int tmp = carry + a * i;
        ans[len++] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry != 0) {
        ans[len++] = carry % 10;
        carry /= 10;
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}