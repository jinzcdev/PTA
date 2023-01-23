// https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int prime[50000], len = 0;
    for (int i = 2; i <= 50000; i++)
        if (isprime(i)) prime[len++] = i;
    int n;
    scanf("%d", &n);
    printf("%d=", n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    int sqr = (int)sqrt(n * 1.0), flag = 0;
    for (int i = 0; i < len && prime[i] <= sqr; i++) {
        if (n == 1) break;
        if (n % prime[i] == 0) {
            int k = 0;
            while (n % prime[i] == 0) {
                k++;
                n /= prime[i];
            }
            if (flag) printf("*");
            flag = 1;
            printf("%d", prime[i]);
            if (k > 1) printf("^%d", k);
        }
    }
    if (n != 1) printf("%s%d", flag ? "*" : "", n);
    return 0;
}