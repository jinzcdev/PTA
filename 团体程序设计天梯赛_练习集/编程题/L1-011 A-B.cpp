// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805130426171392
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool exist[130] = {false};
    for (int i = 0; i < b.size(); i++) exist[b[i]] = true;
    for (int i = 0; i < a.size(); i++)
        if (!exist[a[i]]) cout << a[i];
    return 0;
}