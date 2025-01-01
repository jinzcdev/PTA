// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=807
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << v[i];
    }
    return 0;
}