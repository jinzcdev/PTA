// https://pintia.cn/problem-sets/14/exam/problems/3006
#include <cstdio>
const int maxn = 100010;
int main() {
    int a, n, len = 0, carry = 0, ans[maxn];
    scanf("%d%d", &a, &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        int temp = i * a + carry;
        ans[len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) ans[len++] = carry;
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}