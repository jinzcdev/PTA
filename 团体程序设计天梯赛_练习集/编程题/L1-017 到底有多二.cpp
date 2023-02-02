// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805121500692480
#include <bits/stdc++.h>
using namespace std;
bool ispos(string s, int a) {
    int rmd = 0;
    for (int i = 0; i < s.length(); i++) {
        int tmp = rmd * 10 + (s[i] - '0');
        rmd = tmp % a;
    }
    return rmd == 0;
}
int main() {
    string s;
    int cnt = 0;
    double ans = 1.0;
    cin >> s;
    if (s[0] == '-') {
        s.erase(s.begin());
        ans *= 1.5;
    }
    if (ispos(s, 2)) ans *= 2;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '2') cnt++;
    printf("%.2f%%", cnt * 1.0 / s.length() * ans * 100);
    return 0;
}