// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1478634527046828032
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, a = "String";
    unordered_map<char, int> cnt;
    int len = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (a.find(s[i]) != string::npos) {
            cnt[s[i]]++;
            len++;
        }
    }
    while (len != 0) {
        for (int i = 0; i < 6; i++) {
            if (cnt[a[i]] > 0) {
                cout << a[i];
                cnt[a[i]]--;
                len--;
            }
        }
    }
    return 0;
}