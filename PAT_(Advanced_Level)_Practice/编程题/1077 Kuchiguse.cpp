// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805390896644096
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, len = 99999;
    scanf("%d", &n);
    getchar();
    string s;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        len = min(len, (int)s.length());
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
    int pos = 0;
    for (; pos < len; pos++) {
        char ch = v[0][pos];
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (v[j][pos] != ch) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    if (pos == 0) printf("nai\n");
    else for (int i = pos - 1; i >= 0; i--) printf("%c", v[0][i]);
    return 0;
}