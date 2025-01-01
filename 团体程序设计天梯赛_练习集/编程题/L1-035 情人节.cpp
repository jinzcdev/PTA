// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805097018540032
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> v;
    string s;
    while (cin >> s, s != ".") {
        v.push_back(s);
    }
    if (v.size() < 2) printf("Momo... No one is for you ...");
    else if (v.size() < 14) printf("%s is the only one for you...", v[1].c_str());
    else printf("%s and %s are inviting you to dinner...", v[1].c_str(), v[13].c_str());
    return 0;
}