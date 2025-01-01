// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805347921805312
#include <bits/stdc++.h>
using namespace std;
struct node {
    string data;
    int lc, rc;
} bt[25];
bool isOperator(int adr) { return bt[adr].lc != -1 || bt[adr].rc != -1; }
string inOrder(int i) {
    if (i == -1) return "";
    if (!isOperator(i)) {
        return bt[i].data;
    }
    return "(" + inOrder(bt[i].lc) + bt[i].data + inOrder(bt[i].rc) + ")";
}
int main() {
    int n;
    cin >> n;
    bool vis[25] = {false};
    for (int i = 1; i <= n; i++) {
        cin >> bt[i].data >> bt[i].lc >> bt[i].rc;
        if (bt[i].lc != -1) vis[bt[i].lc] = true;
        if (bt[i].rc != -1) vis[bt[i].rc] = true;
    }
    int root = 1;
    while (vis[root]) root++;
    if (n == 1) cout << bt[root].data;
    else {
        string ans = inOrder(root);
        cout << ans.substr(1, ans.length() - 2);
    }
    return 0;
}