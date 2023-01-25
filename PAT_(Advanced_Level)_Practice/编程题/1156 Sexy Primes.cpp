// https://pintia.cn/problem-sets/994805342720868352/problems/1478634912848322560
#include <cstdio>
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    if (isprime(n) && isprime(n - 6)) printf("Yes\n%d", n - 6);
    else if (isprime(n) && isprime(n + 6)) printf("Yes\n%d", n + 6);
    else {
        while (true) {
            n++;
            if (isprime(n) && (isprime(n - 6) || isprime(n + 6))) break;
        }
        printf("No\n%d", n);
    }
    return 0;
}