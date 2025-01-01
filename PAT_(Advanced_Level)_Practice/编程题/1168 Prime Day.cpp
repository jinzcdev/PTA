// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1621700026718310400
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        int d = stoi(s.substr(i));
        if (isprime(d)) {
            cout << s.substr(i) << " " << "Yes" << endl;
        } else {
            cout << s.substr(i) << " " << "No" << endl;
            flag = false;
        }
    }
    if (flag) cout << "All Prime!";
    return 0;
}