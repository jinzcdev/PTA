// https://pintia.cn/problem-sets/434/exam/problems/5869
#include <bits/stdc++.h>
using namespace std;
bool is_left(string s) { return s == "(" || s == "[" || s == "{" || s == "/*"; }
bool is_right(string s) { return s == ")" || s == "]" || s == "}" || s == "*/"; }
int main() {
    map<string, string> m{{"(", ")"}, {"[", "]"}, {"{", "}"}, {"/*", "*/"},
                          {")", "("}, {"]", "["}, {"}", "{"}, {"*/", "/*"}};
    string line;
    stack<string> s;
    vector<string> v;
    while (getline(cin, line)) {
        if (line == ".") break;
        v.push_back(line);
    }
    for (auto it : v) {
        string a = move(it);
        for (int i = 0; i < a.length(); i++) {
            string str;
            str += a[i];
            if (a[i] == '/' && (i != a.length() - 1 && a[i + 1] == '*')) {
                str += '*';
                i++;
            } else if (a[i] == '*' &&
                       (i != a.length() - 1 && a[i + 1] == '/')) {
                str += '/';
                i++;
            }
            if (is_left(str)) {
                s.push(str);
            } else if (is_right(str)) {
                if (!s.empty() && m[str] == s.top()) s.pop();
                else {
                    if (s.empty()) printf("NO\n?-%s", str.c_str());
                    else printf("NO\n%s-?", s.top().c_str());
                    return 0;
                }
            }
        }
    }
    if (s.empty()) printf("YES\n");
    else printf("NO\n%s-?", s.top().c_str());
    return 0;
}