// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805386161274880
#include <bits/stdc++.h>
using namespace std;
long int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void simplify(long int &a, long int &b) {
    int temp = gcd(abs(a), abs(b));
    a /= temp;
    b /= temp;
}
int main() {
    int n;
    long int a, b, num = 0, den = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%ld/%ld", &a, &b);
        if (num == 0) {
            num = a;
            den = b;
            simplify(num, den);
        } else {
            long int temp = b * den;
            num = b * num + a * den;
            den = temp;
            if (num != 0) simplify(num, den);
        }
    }
    if (num < 0) {
        printf("-");
        num = -num;
    }
    if (num % den == 0) printf("%d", num / den);
    else if (num > den) printf("%d %d/%d", num / den, num % den, den);
    else printf("%d/%d", num, den);
    return 0;
}
/*
#include <cstdio>
#define ll long long
ll ansNum = 0, ansDen = 1;
ll gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void simplify(ll &a, ll &b) {
    ll c = gcd(a, b);
    a /= c;
    b /= c;
}
void add(ll a, ll b) {
    ll lcm = b * ansDen / gcd(b, ansDen);
    ansNum = lcm / ansDen * ansNum + lcm / b * a;
    ansDen = lcm;
    simplify(ansNum, ansDen);
}
int main() {
    int n;
    ll num, den;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &num, &den);
        add(num, den);
    }
    if (ansNum % ansDen == 0) printf("%lld\n", ansNum / ansDen);
    else if (ansNum < ansDen) printf("%lld/%lld\n", ansNum, ansDen);
    else printf("%lld %lld/%lld\n", ansNum / ansDen, ansNum % ansDen, ansDen);
    return 0;
}
*/