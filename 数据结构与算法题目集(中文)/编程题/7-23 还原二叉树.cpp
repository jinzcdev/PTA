// https://pintia.cn/problem-sets/15/problems/838
#include <bits/stdc++.h>
using namespace std;
char pre[55], in[55];
int solve(int prel, int prer, int inl, int inr) {
    if (prel > prer) return 0;
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numleft = k - inl;
    int leftH = solve(prel + 1, prel + numleft, inl, k - 1);
    int rightH = solve(prel + numleft + 1, prer, k + 1, inr);
    return max(leftH, rightH) + 1;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    cout << solve(0, n - 1, 0, n - 1);
    return 0;
}