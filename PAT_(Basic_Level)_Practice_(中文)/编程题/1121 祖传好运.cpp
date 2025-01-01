// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1729419194675666944
#include <bits/stdc++.h>
using namespace std;
bool solve(const string& num) {
    int n = num.length();
    for (int i = 1; i <= n; ++i) {
        int tmp = stoi(num.substr(0, i));
        if (tmp % i != 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int k;
    cin >> k;
    while (k--) {
        string x;
        cin >> x;
        cout << (solve(x) ? "Yes" : "No") << endl;
    }
    return 0;
}