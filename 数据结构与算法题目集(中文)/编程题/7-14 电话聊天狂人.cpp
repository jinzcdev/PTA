// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=722
#include <bits/stdc++.h>
using namespace std;
int n, maxCnt = 0, cntName = 1;
string a, b, ans = "99999999999";
unordered_map<string, int> hashCnt;
void solve(string s, int cnt) {
    if (cnt > maxCnt) {
        ans = s;
        maxCnt = cnt;
        cntName = 1;
    } else if (cnt == maxCnt) {
        cntName++;
        if (s < ans) ans = s;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        hashCnt[a]++;
        hashCnt[b]++;
        solve(a, hashCnt[a]);
        solve(b, hashCnt[b]);
    }
    printf("%s %d", ans.c_str(), maxCnt);
    if (cntName > 1) printf(" %d", cntName);
    return 0;
}

/* @pintia note=start
我的笔记
@pintia note=end */