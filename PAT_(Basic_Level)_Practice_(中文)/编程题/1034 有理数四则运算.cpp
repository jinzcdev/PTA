// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805287624491008
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

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
void printNum(ll a, ll b) {
    bool isneg = false;
    if (a < 0) {
        printf("(-");
        a = -a;
        isneg = true;
    }
    if (a == 0) printf("0");
    else {
        ll tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
        if (a < b) printf("%d/%d", a, b);
        else if (a % b == 0) printf("%d", a / b);
        else printf("%d %d/%d", a / b, a % b, b);
    }
    if (isneg) printf(")");
}
int main() {
    ll a, b, c, d;
    scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
    char op[] = "+-*\\/";
    for (int i = 0; i < 4; i++) {
        printNum(a, b);
        printf(" %c ", op[i]);
        printNum(c, d);
        printf(" = ");
        switch (i) {
            case 0: printNum(a * d + b * c, b * d); break;
            case 1: printNum(a * d - b * c, b * d); break;
            case 2: printNum(a * c, b * d); break;
            case 3:
                if (c == 0) printf("Inf");
                else {
                    if (c < 0) {
                        d = -d;
                        c = -c;
                    }
                    printNum(a * d, b * c);
                }
                break;
        }
        printf("\n");
    }
    return 0;
}
*/