// https://pintia.cn/problem-sets/994805260223102976/problems/1478634235812786176
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int digitsum(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
bool cmp(pii &a, pii &b) {
    return a.first != b.first ? a.first < b.first : a.second < b.second;
}
int main() {
    int n, k, m;
    cin >> n;
    for (int z = 1; z <= n; z++) {
        vector<pii> v;
        printf("Case %d\n", z);
        cin >> k >> m;
        int left = (int)pow(10, k - 1 - 2), right = (int)pow(10, k - 2) - 1;
        for (int x = left; x <= right; x++) {
            int d = x * 100 + 99;
            int sum = digitsum(d);
            if (sum == m) {
                int n = digitsum(d + 1), tmp = gcd(m, n);
                if (tmp > 2 && isprime(tmp)) {
                    v.push_back({n, d});
                }
            }
        }
        if (v.size() == 0) {
            printf("No Solution\n");
            continue;
        }
        sort(v.begin(), v.end(), cmp);
        for (auto it : v) printf("%d %d\n", it.first, it.second);
    }
    return 0;
}