// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1111914599408664577
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int cnt = 0, i = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '6') cnt++;
        if (s[i] != '6' || i == s.length() - 1) {
            if (cnt > 0) {
                if (cnt <= 3) for (int j = 0; j < cnt; j++) printf("6");
                else if (cnt <= 9) printf("9");
                else printf("27");
            }
            cnt = 0;
        }
        if (s[i] != '6') printf("%c", s[i]);
    }
    return 0;
}