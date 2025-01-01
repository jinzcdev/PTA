// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805070971912192
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int pre[N], n, isMirror = 0;
vector<int> ans;
void solve(int prel, int prer) {
    if (prel > prer) return;
    int i = prel + 1, j = prer;
    if (!isMirror) {
        while (i <= prer && pre[i] < pre[prel]) i++;
        while (j > prel && pre[j] >= pre[prel]) j--;
    } else {
        while (i <= prer && pre[i] >= pre[prel]) i++;
        while (j > prel && pre[j] < pre[prel]) j--;
    }
    if (i - j != 1) return;
    solve(prel + 1, i - 1);
    solve(i, prer);
    ans.push_back(pre[prel]);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    solve(0, n - 1);

    if (ans.size() != n) {
        isMirror = 1;
        ans.clear();
        solve(0, n - 1);
    }
    if (ans.size() != n) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", ans[i]);
        }
    }
    return 0;
}