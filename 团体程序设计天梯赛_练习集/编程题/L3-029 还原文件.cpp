// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1386335159927652365
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, k;
vector<vector<int> > frag(m);
vector<int> v(n), tmp, ans;
bool vis[N] = {false}, solved = false;
void dfs(int start) {
    if (solved) return;
    if (tmp.size() == m) {
        solved = true;
        ans = tmp;
        return;
    }
    for (int i = 0; i < m; i++) {
        if (vis[i]) continue;
        bool flag = true;
        for (int j = 0; j < frag[i].size(); j++) {
            if (frag[i][j] != v[start + j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            vis[i] = true;
            tmp.push_back(i);
            dfs(start + frag[i].size() - 1);
            vis[i] = false;
            tmp.pop_back();
        }
    }
}
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> m;
    frag.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> k;
        frag[i].resize(k);
        for (int j = 0; j < k; j++) cin >> frag[i][j];
    }
    dfs(0);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    return 0;
}