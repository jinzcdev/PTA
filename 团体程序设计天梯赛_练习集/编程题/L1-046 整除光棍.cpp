// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805084284633088
#include <bits/stdc++.h>
using namespace std;
string divide(string a, int num) {
    int rmd = 0;
    string ans = "";
    for (int i = 0; i < a.length(); i++) {
        int tmp = rmd * 10 + (a[i] - '0');
        ans += tmp / num + '0';
        rmd = tmp % num;
    }
    while (ans[0] == '0') ans.erase(ans.begin());
    if (rmd == 0) return ans;
    return "";
}
int main() {
    int n;
    string a = "";
    cin >> n;
    for (int i = 1; ; i++) {
        a += "1";
        string ans = divide(a, n);
        if (ans != "") {
            cout << ans << " " << i;
            break;
        }
    }
    return 0;
}