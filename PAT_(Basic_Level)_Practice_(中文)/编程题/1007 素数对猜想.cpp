// https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744
#include <cstdio>
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    int pre = 2, cnt = 0;
    for (int x = 3; x <= n; x++) {
        if (isPrime(x)) {
            cnt += x - pre == 2;
            pre = x;
        }
    }
    printf("%d", cnt);
    return 0;
}