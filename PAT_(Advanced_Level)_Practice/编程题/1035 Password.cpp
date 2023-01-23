// https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520
#include <bits/stdc++.h>
using namespace std;
string convert(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') s[i] = '@';
        else if (s[i] == '0') s[i] = '%';
        else if (s[i] == 'l') s[i] = 'L';
        else if (s[i] == 'O') s[i] = 'o';
    }
    return s;
}
int main() {
    int n;
    string a, b;
    vector<pair<string, string> > ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        string s = convert(b);
        if (s != b) ans.push_back({a, s});
    }
    if (ans.size() != 0) {
        printf("%d\n", ans.size());
        for (auto it : ans) 
            cout << it.first << " " << it.second << endl;
    } else if (n == 1) printf("There is 1 account and no account is modified\n");
    else printf("There are %d accounts and no account is modified\n", n);
    return 0;
}