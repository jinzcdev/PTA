// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1518581803354341376
#include <bits/stdc++.h>
using namespace std;
int main() {
    string str[2];
    string a;
    for (int j = 0; j < 2; j++) {
        cin >> a;
        for (int i = 1; i < a.length(); i++) {
            if (a[i] % 2 == a[i - 1] % 2) {
                str[j] += max(a[i], a[i - 1]);
            }
        }
    }
    if (str[0] == str[1]) cout << str[0];
    else cout << str[0] << endl << str[1];
    return 0;
}