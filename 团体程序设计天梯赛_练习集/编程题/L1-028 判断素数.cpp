// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805106325700608
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n, k;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        printf("%s\n", isPrime(k) ? "Yes" : "No");
    }
    return 0;
}