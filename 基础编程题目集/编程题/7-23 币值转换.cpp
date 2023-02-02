// https://pintia.cn/problem-sets/14/exam/problems/803
#include <bits/stdc++.h>
using namespace std;
char decimals[] = {'Q', 'B', 'S'}, units[] = {'Y', 'W'};
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "a";
        return 0;
    }
    int a[] = {n / 100000000, (n / 10000) % 10000, n % 10000};
    for (int i = 0; i < 3; i++) {
        string s = to_string(a[i]);
        if (i != 0 && a[i - 1] != 0 && a[i] != 0 && (a[i - 1] % 10 == 0 || s.length() < 4)) cout << "a";
        bool preZero = false;
        for (int i = 0; i < s.length(); i++) {
            int j = 4 - s.length() + i;
            if (s[i] == '0') preZero = true;
            else {
                if (preZero) cout << "a";
                printf("%c", s[i] - '0' + 'a');
                if (j < 3) cout << decimals[j];
                preZero = false;
            }
        }
        if (i < 2 && a[i] != 0) cout << units[i];
    }
    return 0;
}