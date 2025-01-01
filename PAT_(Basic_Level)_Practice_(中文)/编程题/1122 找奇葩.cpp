// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1729419194675666945
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n;
    unordered_map<int, int> mp;
    while (n--) {
        cin >> x;
        if (x % 2 == 1) {
            mp[x]++;
        }
    }
    for (const auto &[k, v] : mp) {
        if (v % 2 == 1) {
            cout << k;
            return 0;
        }
    }
    return 0;
}