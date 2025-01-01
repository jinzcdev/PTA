// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805398257647616
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    map<string, int> mcnt;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) s[i] += 32;
        if (!isalnum(s[i]) && isalnum(s[i - 1])) {
            string ss = s.substr(start, i - start);
            // cout << ss << endl;
            while (!isalnum(ss[ss.length() - 1])) ss.erase(ss.end() - 1);
            bool isvalid = true;
            for (int j = 0; j < ss.length(); j++) {
                if (!isalnum(ss[j])) {
                    isvalid = false;
                    break;
                }
            }
            if (isvalid) mcnt[ss]++;
            start = i + 1;
        }
        if (!isalnum(s[start])) start++;
    }
    if (start < s.length() && isalnum(s[start])) {
        string laststr = s.substr(start);
        while (!isalnum(laststr[laststr.length() - 1]))
            laststr.erase(laststr.end() - 1);
        mcnt[laststr]++;
    }
    string maxstr = "zzzzzz", ans;
    int maxCnt = -1;
    for (auto it : mcnt) {
        if (it.second > maxCnt) {
            maxCnt = it.second;
            ans = it.first;
        } else if (it.second == maxCnt && it.first < ans) {
            ans = it.first;
        }
    }
    printf("%s %d", ans.c_str(), maxCnt);
    return 0;
}