// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805350803292160
#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, s;
    cin >> m >> n >> s;
    if (s > m) {
        printf("Keep going...\n");
        return 0;
    }
    vector<string> name(m);
    for (int i = 0; i < m; i++) cin >> name[i];
    map<string, int> vis;
    for (int i = s - 1; i < m; i += n) {
        while (vis[name[i]] == 1) i++;
        cout << name[i] << endl;
        vis[name[i]] = 1;
    }
    return 0;
}