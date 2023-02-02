// https://pintia.cn/problem-sets/14/exam/problems/810
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
    for (int i = 0; i < n; i++) cout << v[i] << endl;
    return 0;
}