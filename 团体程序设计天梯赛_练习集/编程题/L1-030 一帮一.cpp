// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805103557459968
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    vector<string> v(n);
    unordered_map<string, bool> gender, vis;
    for (int i = 0; i < n; i++) {
        cin >> a >> v[i];
        gender[v[i]] = a;
    }
    for (int i = 0; i < n / 2; i++) {
        cout << v[i] << " ";
        for (int j = n - 1; j >= n / 2; j--) {
            if (!vis[v[j]] && gender[v[j]] != gender[v[i]]) {
                cout << v[j];
                vis[v[j]] = true;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}