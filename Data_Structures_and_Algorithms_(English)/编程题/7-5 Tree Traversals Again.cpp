// https://pintia.cn/problem-sets/16/exam/problems/667
#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
vector<int> pre, in;
void solve(int prel, int prer, int inl, int inr) {
    if (prel > prer) return;
    int k = inl;
    while (in[k] != pre[prel]) k++;
    int numleft = k - inl;
    solve(prel + 1, prel + numleft, inl, k - 1);
    solve(prel + numleft + 1, prer, k + 1, inr);
    printf("%d", pre[prel]);
    if (++cnt < n) printf(" ");
}
int main() {
    scanf("%d", &n);
    char op[5], val[5];
    stack<int> s;
    for (int i = 0; i < n * 2; i++) {
        scanf("%s", op);
        if (op[1] == 'u') {
            scanf("%s", val);
            pre.push_back(stoi(val));
            s.push(stoi(val));
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    solve(0, n - 1, 0, n - 1);
    return 0;
}