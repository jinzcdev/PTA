// https://pintia.cn/problem-sets/15/problems/891
#include <bits/stdc++.h>
using namespace std;
void parse(string str, set<string> &s) {
    string it = "";
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
        if (isalpha(str[i])) it += str[i];
        if (!isalpha(str[i]) || i == str.length() - 1) {
            if (it != "" && it.length() >= 3) {
                it = it.substr(0, 10);
                s.insert(it);
            }
            it = "";
        }
    }
}
float get_similarity(set<string> &a, set<string> &b) {
    int cnt = 0;
    for (auto it : a)
        if (b.find(it) != b.end()) cnt++;
    return cnt * 100.0 / (a.size() + b.size() - cnt);
}
int main() {
    int n, m, a, b;
    scanf("%d", &n);
    vector<set<string> > v(n);
    getchar();
    for (int i = 0; i < n; i++) {
        string str;
        while (true) {
            getline(cin, str);
            if (str == "#") break;
            parse(str, v[i]);
        }
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        printf("%.1f%%\n", get_similarity(v[a - 1], v[b - 1]));
    }
    return 0;
}