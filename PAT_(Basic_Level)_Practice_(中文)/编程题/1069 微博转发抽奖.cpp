// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805265159798784
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<string> v(m), ans;
    map<string, int> mp;
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    if (m < s) {
        printf("Keep going...\n");
        return 0;
    }
    ans.push_back(v[s - 1]);
    mp[v[s - 1]] = 1;
    int cnt = 0;
    for (int i = s; i < m; i++) {
        if (++cnt % n == 0) {
            if (mp[v[i]] != 0) cnt--;
            else {
                ans.push_back(v[i]);
                mp[v[i]] = 1;
            }
        }
    }
    for (auto it : ans) {
        cout << it << endl;
    }
    return 0;
}