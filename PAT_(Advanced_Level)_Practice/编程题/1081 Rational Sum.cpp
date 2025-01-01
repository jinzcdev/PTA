// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805386161274880
#include <cstdio>
#define ll long long
const int maxn = 110;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b , a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void yuefen(ll &a, ll &b) {
    ll c = gcd(a, b);
    a /= c;
    b /= c;
}

void printAns(ll num, ll den){
    yuefen(num, den);
    ll m = num / den;
    if (m != 0) printf("%lld %lld/%lld\n", m, num % den, den);
    else printf("%lld/%lld\n", num % den, den);
}

int main() {
    int n;
    ll num[maxn], den[maxn];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", num + i, den + i);
    }
    ll ansDen = den[0];
    for (int i = 1; i < n; i++) {
        ansDen = lcm(ansDen, den[i]);
    }
    ll ansNum = 0;
    for (int i = 0; i < n; i++) {
        ansNum += num[i] * (ansDen / den[i]);
    }
    if (ansNum == 0) printf("0\n");
    else if (ansNum % ansDen == 0) printf("%lld\n", ansNum / ansDen);
    else printAns(ansNum, ansDen);
    return 0;
}