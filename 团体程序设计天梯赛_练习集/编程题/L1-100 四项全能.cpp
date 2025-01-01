// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388419
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, x, sum = 0;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> x;
        sum += x;
    }
    int tmp = sum - n * (m - 1);
    cout << (tmp > 0 ? tmp : 0);
    return 0;
}