// https://pintia.cn/problem-sets/994805342720868352/problems/994805357933608960
#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    string s;
    cin >> k >> s;
    int cnt = 0;
    char pre = s[0];
    bool checked[256] = {false}, stucked[256] = {false};
    vector<char> ans;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == pre) {
            cnt++;
        } else {
            if (!checked[pre] || stucked[pre] == true) {  // 已检测过且不是坏键
                if (cnt % k == 0) {
                    stucked[pre] = true;
                } else {
                    stucked[pre] = false;
                }
            }
            checked[pre] = true;
            pre = s[i];
            cnt = 1;
        }
    }
    if (pre == s[s.length() - 1] && (!checked[pre] || stucked[pre] == true)) {
        if (cnt % k == 0) {
            stucked[pre] = true;
        } else {
            stucked[pre] = false;
        }
    }
    bool vis[128] = {false};
    for (int i = 0; i < s.length(); i++) {
        if (stucked[s[i]] && !vis[s[i]]) {
            ans.push_back(s[i]);
            vis[s[i]] = true;
        }
    }

    for (auto it : ans) printf("%c", it);
    printf("\n");
    int i = 0;
    while (i < s.length()) {
        printf("%c", s[i]);
        if (stucked[s[i]]) {
            i += k;
        } else {
            i++;
        }
    }
    return 0;
}