// https://pintia.cn/problem-sets/994805260223102976/problems/1038429065476579328
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a * b);
    reverse(s.begin(), s.end());
    cout << stoi(s);
    return 0;
}

// python:
// a, b = map(int, input().split())
// print(int(''.join(list(str(a * b))[::-1])))
