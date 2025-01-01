// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1336215880692482053
#include <bits/stdc++.h>
using namespace std;
int main() {
    int i = 0, n = 0, cnt = 0, ans = 0;
    bool flag = true;
    string s;
    while (getline(cin, s), s != ".") {
        n++;
        if (s.find("chi1 huo3 guo1") != string::npos) {
            cnt++;
            if (flag) {
                flag = false;
                ans = n;
            }
        }
    }
    cout << n << endl;
    if (flag) cout << "-_-#";
    else cout << ans << " " << cnt;
    return 0; 
}