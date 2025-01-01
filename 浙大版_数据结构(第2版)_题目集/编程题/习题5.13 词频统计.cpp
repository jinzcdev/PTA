// https://pintia.cn/problem-sets/434/exam/problems/type/7?problemSetProblemId=6259
/*
This is a test.

The word "this" is the word with the highest frequency.

Longlonglonglongword should be cut off, so is considered as the same as
longlonglonglonee.  But this_8 is different than this, and this, and this...#
this line should be ignored.
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> psi;
bool isvalid(char ch) { return isalpha(ch) || isdigit(ch) || ch == '_'; }
int main() {
    string s, it = "";
    unordered_map<string, int> cnt;
    while (getline(cin, s)) {
        if (s.size() == 0) continue;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (isvalid(s[i])) it += s[i];
            if ((!isvalid(s[i]) || i == s.length() - 1) && it != "") {
                if (it.length() > 15) it = it.substr(0, 15);
                for (int j = 0; j < it.length(); j++) it[j] = tolower(it[j]);
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
    for (const auto &it : cnt) {
        ans.push_back({it.first, it.second});
    }
    sort(ans.begin(), ans.end(), [](psi &a, psi &b) {
        return a.second != b.second ? a.second > b.second : a.first <
        b.first;
    });
    for (int i = 0; i < (int)(cnt.size() * 0.1); i++) {
        printf("%d:%s\n", ans[i].second, ans[i].first.c_str());
    }
    return 0;
}