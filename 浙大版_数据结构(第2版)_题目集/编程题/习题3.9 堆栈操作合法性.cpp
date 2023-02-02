// https://pintia.cn/problem-sets/434/exam/problems/5891
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    string s;
    scanf("%d%d", &n, &m);
    while (n--) {
        int size = 0, flag = 1;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == 'S' && ++size > m) || (s[i] == 'X' && --size < 0)) {
                flag = 0;
                break;
            }
        }
        printf("%s\n", (flag && size == 0) ? "YES" : "NO");
    }
    return 0;
}