// https://pintia.cn/problem-sets/434/problems/6259
#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> psi;
bool isvalid(char ch) { return isalpha(ch) || isdigit(ch) || ch == '_'; }
int main() {
    string s, it = "";
    unordered_map<string, int> cnt;
    while (getline(cin, s)) {
        if (s.length() == 0) continue;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (isvalid(s[i])) it += tolower(s[i]);
            if ((!isvalid(s[i]) || i == s.length() - 1) && it != "") {
                if (it.length() > 15) it = it.substr(0, 15);
                cnt[it]++;
                it = "";
            }
            if (s[i] == '#') {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    printf("%d\n", cnt.size());
    vector<psi> ans;
    for (const auto &it : cnt) ans.push_back({it.first, it.second});
    sort(ans.begin(), ans.end(), [](psi &a, psi &b) {
        return a.second != b.second ? a.second > b.second : a.first <
        b.first;
    });
    for (int i = 0; i < (int)(cnt.size() * 0.1); i++)
        printf("%d:%s\n", ans[i].second, ans[i].first.c_str());
    return 0;
}