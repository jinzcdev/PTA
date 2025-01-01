// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1697150941050929154
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp = {{"ling", 0}, {"yi", 1}, {"er", 2}, {"san", 3}, {"si", 4}, {"wu", 5}, {"liu", 6}, {"qi", 7}, {"ba", 8}, {"jiu", 9}};
int parse(string s) {
    if (mp.count(s)) return mp[s];
    if (s.find("sqrt") != string::npos) {
        return (int)sqrt(stoi(s.substr(4)));
    }
    int idx = 0;
    while (idx < s.size() && isdigit(s[idx])) idx++;
    if (idx == s.size()) return stoi(s);
    int a = stoi(s.substr(0, idx)), b = stoi(s.substr(idx + 1));
    char op = s[idx];
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return (int)pow(a, b);
    }
    return 0;
}
int main() {
    string s, ans;
    while (cin >> s) cout << parse(s);
    return 0;
}