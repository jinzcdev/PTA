// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1386335159927652365
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, k;
vector<vector<int> > frag(m);
vector<int> v(n), tmp, ans;
bool vis[N] = {false};
bool dfs(int start, bool memo[]) {
    if (tmp.size() == m) {
        ans = tmp;
        return true;
    }
    if (memo[start]) return false;
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
            bool found = dfs(start + frag[i].size() - 1, memo);
            vis[i] = false;
            tmp.pop_back();
            if (found) {
                return true;
            }
        }
    }
    memo[start] = true;
    return false;
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
    bool memo[n] = {false};
    dfs(0, memo);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    return 0;
}

/*
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
*/

/* @pintia note=start
与 Leetcode 的这道题有类似之处 [139. 单词拆分 - 力扣（LeetCode）](https://leetcode.cn/problems/word-break/)
@pintia note=end */