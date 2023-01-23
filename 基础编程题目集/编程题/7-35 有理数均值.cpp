// https://pintia.cn/problem-sets/14/problems/815
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void simplify(int &a, int &b) {
    if (a == 0) {
        b = 1;
        return;
    }
    bool isneg = false;
    if (a < 0) {
        a = -a;
        isneg = true;
    }
    int k = gcd(a, b);
    a /= k;
    b /= k;
    if (isneg) a = -a;
}
int main() {
    int n, a = 0, b = 1, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d/%d", &x, &y);
        a = a * y + b * x;
        b = b * y;
        simplify(a, b);
    }
    b *= n;
    simplify(a, b);
    if (a < 0) {
        printf("-");
        a = -a;
    }
    if (a % b == 0) printf("%d", a / b);
    else printf("%d/%d", a, b);
    return 0;
}