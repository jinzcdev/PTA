// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805133597065216
#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void yuefen(long long &a, long long &b) {
    int g = gcd(a, b);
    a /= g;
    b /= g;
}
int main() {
    int n;
    long long a, b, fenzi = 0, fenmu = 1;
    cin >> n;
    while (n--) {
        scanf("%ld/%ld", &a, &b);
        long long gcm = fenmu * b / gcd(fenmu, b);
        fenzi = gcm / b * a + gcm / fenmu * fenzi;
        fenmu = gcm;
        yuefen(fenzi, fenmu);
    }
    // if (fenmu < 0) fenzi = -fenzi;
    if (fenzi < 0 || fenmu < 0) {
        cout << "-";
        fenzi = abs(fenzi);
        fenmu = abs(fenmu);
    }
    if (fenzi != 0 && fenzi < fenmu) printf("%ld/%ld", fenzi, fenmu);
    else if (fenzi % fenmu == 0) cout << fenzi / fenmu;
    else printf("%ld %ld/%ld", fenzi / fenmu, fenzi % fenmu, fenmu);
    return 0;
}