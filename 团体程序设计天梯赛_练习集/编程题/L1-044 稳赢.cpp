// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805086365007872
#include <bits/stdc++.h>
using namespace std;
string win(string s) {
    if (s == "ChuiZi") return "Bu";
    else if (s == "Bu") return "JianDao";
    return "ChuiZi";
}
int main() {
    int n, cnt = 0;
    string s;
    scanf("%d", &n);
    while (cin >> s, s != "End") {
        if (++cnt <= n) cout << win(s) << endl;
        else {
            cout << s << endl;
            cnt = 0;
        }   
    }
    return 0;
}