// https://pintia.cn/problem-sets/994805046380707840/problems/1336215880692482054
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int left = 1, right = (int)pow(2, n);
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'y') {
                right = (left + right) / 2;
            } else if (s[i] == 'n') {
                left = (left + right) / 2 + 1;
            }
        }
        cout << left << endl;
    }
    return 0;
}