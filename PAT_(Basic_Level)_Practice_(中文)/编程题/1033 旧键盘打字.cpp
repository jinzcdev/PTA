// https://pintia.cn/problem-sets/994805260223102976/problems/994805288530460672
#include <bits/stdc++.h>
using namespace std;
int main() {
    bool isbroken[128] = {false};
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++) isbroken[a[i]] = true;
    for (int i = 0; i < b.length(); i++) {
        if (isbroken[toupper(b[i])] || (isbroken['+'] && isupper(b[i]))) continue;
        cout << b[i];
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++) {
        if (s1.find(toupper(s2[i])) != string::npos) continue;
        if (isupper(s2[i]) && s1.find('+') != string::npos) continue;
        cout << s2[i];
    }
    return 0;
}
*/