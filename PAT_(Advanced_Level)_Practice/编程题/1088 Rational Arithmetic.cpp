// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805378443755520
#include <iostream>
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {
    return a % b == 0 ? b : gcd(b, a % b);
}
void simplify(ll a, ll b) {
    bool isNeg = a < 0;
    if (isNeg) printf("(-");
    a = abs(a);
    if (a % b == 0) printf("%lld", a / b);
    else {
        ll gcdNum = gcd(a, b);
        a /= gcdNum;
        b /= gcdNum;
        if (a > b) printf("%lld %lld/%lld", a / b, a % b, b);
        else printf("%lld/%lld", a, b);
    }
    if (isNeg) printf(")");
}

int main() {
    ll a, b, c, d, m, n;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    const string op = "+-*/";
    for (int i = 0; i < op.length(); i++) {
        simplify(a, b);
        printf(" %c ", op[i]);
        simplify(c, d);
        printf(" = ");
        switch (op[i]) {
            case '+': m = a * d + b * c; n = b * d; break;
            case '-': m = a * d - b * c; n = b * d; break;
            case '*': m = a * c; n = b * d; break;
            case '/': 
                m = a * d;
                n = b * c;
                if (n < 0) {
                    m = -m;
                    n = -n;
                }
                break;
        }
        if (n == 0) {
            printf("Inf\n");
            continue;
        }
        simplify(m, n);
        printf("\n");
    }
    return 0;
}