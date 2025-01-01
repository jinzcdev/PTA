// https://pintia.cn/problem-sets/17/exam/problems/type/7?problemSetProblemId=261
#include <cstdio>
bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    int i = 1, ans = 0;
    while (i <= n - 2) {
        if (isPrime(i) && isPrime(i + 2)) ans++;
        i++;
    }
    printf("%d\n", ans);
    return 0;
}