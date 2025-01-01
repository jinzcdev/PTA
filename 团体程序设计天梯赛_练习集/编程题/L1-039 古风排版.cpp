// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805091888906240
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    scanf("%d", &n);
    getchar();
    getline(cin, s);
    int m = s.length() % n == 0 ? s.length() / n : s.length() / n + 1;
    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = i; j < s.length(); j += n) {
            tmp += s[j];
        }
        int num = m - tmp.length();
        for (int j = 0; j < num; j++) {
            tmp += " ";
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << endl;
    }
    return 0;
}