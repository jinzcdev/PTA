// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805122985476096
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cnt = 0, w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        int sum = 0;
        bool flag = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (!isdigit(s[i])) {
                flag = false;
                break;
            }
            sum += w[i] * (s[i] - '0');
        }
        if (!flag || m[sum % 11] != s[s.length() - 1]) {
            cout << s << endl;
            cnt++;
        }
    }
    if (cnt == 0) cout << "All passed";
    return 0;
}