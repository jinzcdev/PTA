// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1697150941050929152
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2 != 0) {
        printf("Error: %d digit(s)", n);
        return 0;
    }
    string a = s.substr(0, n / 2);
    string b = s.substr(n / 2);
    int carry = 2;
    string origin = a;
    for (int i = n / 2 - 1; i >= 0; i--) {
        int t = a[i] - '0' + carry;
        a[i] = (t % 10) + '0';
        carry = t / 10;
    }
    if (carry != 0 || a != b) {
        printf("No: %s - %s != 2", b.c_str(), origin.c_str());
    } else {
        printf("Yes: %s - %s = 2", b.c_str(), origin.c_str());
    }
    return 0;
}