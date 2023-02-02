// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805364711604224
#include <bits/stdc++.h>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> temp, ans, fac;
void dfs(int x, int sum, int facSum, int cntK) {
    if (x < 1 || sum > n || cntK > k) return;
    if (sum == n && cntK == k) {
        if (facSum > maxFacSum) {
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    temp.push_back(x);
    dfs(x, sum + fac[x], facSum + x, cntK + 1);
    temp.pop_back();
    dfs(x - 1, sum, facSum, cntK);
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i <= sqrt(n * 1.0); i++) fac.push_back(pow(i, p));
    dfs(fac.size() - 1, 0, 0, 0);
    if (ans.size() == 0) printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }
    return 0;
}