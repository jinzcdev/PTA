// https://pintia.cn/problem-sets/994805342720868352/problems/1478635415925800960
#include <bits/stdc++.h>
using namespace std;
struct node {
    int n, v;
};
int n, k, m;
vector<node> ans;
bool cmp(node a, node b) { return a.n != b.n ? a.n < b.n : a.v < b.v; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int getDigitSum(int x) {
    int sumD = 0;
    while (x != 0) {
        sumD += x % 10;
        x /= 10;
    }
    return sumD;
}
void dfs(int number, int numDigit, int sumD) {
    if (sumD > m) return;
    if (sumD + 9 * (k - numDigit) < m) return;
    if (numDigit == k) {
        if (sumD != m) return;
        int n = getDigitSum(number + 1);
        int x = gcd(m, n);
        if (x > 2 && isPrime(x)) ans.push_back({n, number});
        return;
    }
    for (int i = 0; i <= 9; i++)
        dfs(number * 10 + i, numDigit + 1, sumD + i);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Case %d\n", i);
        scanf("%d%d", &k, &m);
        ans.clear();
        for (int j = 1; j <= 9; j++) dfs(j, 1, j);
        if (ans.size() == 0) printf("No Solution\n");
        else {
            sort(ans.begin(), ans.end(), cmp);
            for (auto it : ans)
                printf("%d %d\n", it.n, it.v);
        }
    }
    return 0;
}
