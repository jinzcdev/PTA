// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1518581337161646080
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x) {
    if (x <= 1) return x;
    return x * f(x - 1);
}
int main() {
    ll a, b;
    cin >> a >> b;
    cout << f(a + b);
    return 0;
}