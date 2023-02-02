// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805063166312448
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, cnt = 0;
    vector<int> v;
    cin >> n;
    while (n--) {
        cin >> a;
        int pos = upper_bound(v.begin(), v.end(), a) - v.begin();
        if (pos == v.size()) v.push_back(a);
        else v[pos] = a;
    }
    cout << v.size();
    return 0;
}